/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2015 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: core_support.S 1339 2019-12-07 01:28:44Z ertl-komori $
 */

/*
 *  プロセッサ依存モジュール アセンブリ言語部（ARM-M用）
 */

#define TOPPERS_MACRO_ONLY
#define UINT_C(val)		(val)		/* uint_t型の定数を作るマクロ */
#define ULONG_C(val)	(val)		/* ulong_t型の定数を作るマクロ */
#define CAST(type, val)	(val)		/* 型キャストを行うマクロ */

#include "kernel_impl.h"
#include "arm_m.h"
#include "offset.h"
#include "target_asm.inc"

/*
 *  CPU例外エントリ
 *
 *  割込みエントリと処理の内容は同等だが，ログの種類が異なるため，
 *  分けている．
 */
	AALIGN(2)
	ATEXT
	ATHUMB(core_exc_entry)
	AGLOBAL(core_exc_entry)
ALABEL(core_exc_entry)
	/*
	 *  例外/割込みが発生すると，発生時にアクティブなスタックにスクラ
	 *  ッチレジスタ等が保存される．
	 *  この内容に加えて，CPU例外ハンドラへの情報として，basepri の値と，
	 *  EXC_RETURNの情報を加えて保存する．basepriの値は，CPU例外からの
	 *  リターン時に割込み優先度マスクの値を元に戻すためにも用いられる．
	 *
	 *   -----------
	 *  | EXC_RETURN|  
	 *   -----------
	 *  |  basepri  |  
	 *   -----------
	 *  |    R0     |  
	 *   -----------
	 *  |    R1     |
	 *   -----------
	 *  |    R2     |
	 *   -----------
	 *  |    R3     |
	 *   -----------
	 *  |    R12    |
	 *   -----------
	 *  |    LR     |
	 *   -----------
	 *  |    PC     |
	 *   -----------
	 *  |   xPSR    |
	 *   -----------
	 *
	 */

	/*
	 *  カーネル管理外の例外かチェック
	 *  カーネル内のクリティカルセクションの実行中，全割込みロック状態，
	 *  CPUロック状態，カーネル管理外の割込みハンドラ実行中のいずれかで
	 *  発生したCPU例外を，カーネル管理外のCPU例外と呼ぶ
	 *  全割込みロック状態はFAULTMASKが'1'の場合
	 *  CPUロック状態はbasepriがIIPM_LOCKかで判断する．
	 */
	mrs   r2, FAULTMASK           /* 全割込みロック状態ならカーネル管理外例外処理へ */
	cbnz  r2, core_nonkernel_exc_entry

	mrs   r2, basepri             /* baepriの値を取得 */
	cmp   r2, #IIPM_LOCK          /* CPUロック状態ならカーネル管理外例外処理へ */
	beq   core_nonkernel_exc_entry


	/*
	 * スタックを変更する必要があるかチェック
	 * EXC_RETURN（割込み時にLRに設定される値）をチェックして，例外発生時に
	 * アクティブなスタックを特定することで多重割込みか判定する．
	 */
	tst   lr, #EXC_RETURN_PSP    /* 割込み元がMSPなら多重割込み */
	beq   core_exc_entry_1       /* 多重割込みならcore_exc_entry_1へ */
	mrs   r0, psp                /* 一段目の割込みの場合はPSP上に */
	stmfd r0!,{r2}               /* 割込み発生時の割込み優先度マスクを積む */
	stmfd r0!,{lr}               /* EXC_RETURN を積む             */
	msr   psp, r0                /* CPU例外ハンドラへの引数となる */
	push  {lr}                   /* MSP上にもEXC_RETURN を積む    */ 
#ifdef TOPPERS_SUPPORT_OVRHDR
	push    {r0}
	bl      ovrtimer_stop
	pop     {r0}
#endif /* TOPPERS_SUPPORT_OVRHDR */
	b     core_exc_entry_2
ALABEL(core_exc_entry_1)         /* 多重割込みの場合 */
	push  {r2}                   /* 割込み発生時の割込み優先度マスクを積む */
	push  {lr}                   /* EXC_RETURN を積む             */ 
	mov   r0, sp                 /* CPU例外ハンドラへの引数となる */

	/*
	 *  共通処理
	 */
ALABEL(core_exc_entry_2)
	mrs   r3, ipsr               /* ハンドラアドレスを取得 */
ALABEL(core_exc_entry_3)
	ldr   r1, =_kernel_exc_tbl
	ldr   r2, [r1, r3, lsl #2]

#ifdef LOG_EXC_ENTER
	push  {r0,r2,r3}
	mov   r0, r3                 /* 例外番号をパラメータに  */
	bl    log_exc_enter          /* log_exc_enterを呼び出す */
	pop   {r0,r2,r3}
	push  {r3}                   /* 例外番号をスタックへ    */
#endif /* LOG_EXC_ENTER */

	/*
	 *  CPU例外ハンドラの呼び出し
	 */
	blx   r2

#ifdef LOG_EXC_ENTER
	pop   {r0}                   /* 例外番号を引数に        */
	bl    log_exc_leave          /* log_exc_leaveを呼び出す */
#endif /* LOG_EXC_ENTER */

	b     ret_exc

/*
 *  カーネル管理外のCPU例外の出入口処理
 */
ALABEL(core_nonkernel_exc_entry)
	tst   lr, #EXC_RETURN_PSP    /* 割込み元がMSPなら多重割込み */
	beq   core_nonkernel_exc_entry_1  /* 多重割込みなら */
	mrs   r0, psp                /* 一段目の割込みの場合はPSP上に */
	stmfd r0!,{r2}               /* 割込み発生時の割込み優先度マスクを積む */
	stmfd r0!,{lr}               /* EXC_RETURN を積む             */
	msr   psp, r0                /* CPU例外ハンドラへの引数となる */
	push  {lr}                   /* MSP上にもEXC_RETURN を積む    */ 
	b     core_nonkernel_exc_entry_2
ALABEL(core_nonkernel_exc_entry_1) /* 多重割込みの場合 */
	push  {r2}                   /* 割込み発生時の割込み優先度マスクを積む */
	push  {lr}                   /* EXC_RETURN を積む             */ 
	mov   r0, sp                 /* CPU例外ハンドラへの引数となる */

ALABEL(core_nonkernel_exc_entry_2)
	mrs   r3, ipsr               /* CPU例外ハンドラのアドレスを取得 */
	ldr   r1, =_kernel_exc_tbl
	ldr   r2, [r1, r3, lsl #2]

	/*
	 *  CPU例外ハンドラの呼び出し
	 */
	blx   r2

	/*
	 *  割込みロック状態とする．
	 */
	cpsid f

	/*
	 *  戻り先のコンテキストの判定
	 * 
	 *  割込みハンドラ実行にLRにセットされるEXC_RETURNをチェックして，戻り
	 *  先でMSPが使われていれば，割込み先が非タスクコンテキストと判定する．
	 */
	pop   {r3}                     /* lrをスタックから取得         */
	tst   r3, #EXC_RETURN_PSP      /* 戻り先がPSPなら              */
	bne   core_nonkernel_ret_exc_1
	pop   {r1}                     /* 元の割込み優先度マスク(basepri) */
	b     core_nonkernel_ret_exc_2 /* の値をMSPから取得 */

ALABEL(core_nonkernel_ret_exc_1)
	/*
	 *  PSP上からEXC_RETURNを削除
	 */
	mrs   r2, psp
	add   r2, r2, #4
	/*
	 *  元の割込み優先度マスク(basepri)の値をPSPから取得
	 */
	ldmfd r2!, {r1} 
	msr   psp, r2

ALABEL(core_nonkernel_ret_exc_2)
	msr   basepri, r1             /* 割込み優先度マスクを割込み前に状態へ */
	bx    r3                      /* リターン */

/*
 *  割込みエントリ
 */
	ATHUMB(core_int_entry)
	AGLOBAL(core_int_entry)
ALABEL(core_int_entry)
	/*
	 *  割込み発生時の割込み優先度マスクをスタックに保存するため取得
	 */
	mrs   r2, basepri             /* baepriの値を取得 */

	/*
	 * 多重割込みかチェック
	 * EXC_RETURN（割込み時にLRに設定される値）をチェックして，例外発生時に
	 * アクティブなスタックを特定することで多重割込みか判定する．
	 */
	tst   lr, #EXC_RETURN_PSP    /* 割込み元がMSPなら多重割込み */
	beq   core_int_entry_1       /* 多重割込みならcore_int_entry_1へ */
	mrs   r0, psp                /* 一段目の割込みの場合はPSP上に */
	stmfd r0!,{r2}               /* 割込み発生時の割込み優先度マスクを積む */
	stmfd r0!,{lr}               /* EXC_RETURN を積む             */
	msr   psp, r0                /* CPU例外ハンドラへの引数となる */
	push  {lr}                   /* MSP上にもEXC_RETURN を積む    */ 
#ifdef TOPPERS_SUPPORT_OVRHDR
	push    {r0}
	bl      ovrtimer_stop
	pop     {r0}
#endif /* TOPPERS_SUPPORT_OVRHDR */
	b     core_int_entry_2
ALABEL(core_int_entry_1)         /* 多重割込みの場合 */
	push  {r2}                   /* 割込み発生時の割込み優先度マスクを積む */
	push  {lr}                   /* EXC_RETURN を積む             */ 
	mov   r0, sp                 /* 未定義の割込みが発生した場合の情報とする */

	/*
	 *  共通処理
	 */
ALABEL(core_int_entry_2)
	mrs   r3, ipsr               /* ハンドラアドレスを取得 */
	ldr   r1, =_kernel_exc_tbl
	ldr   r2, [r1, r3, lsl #2]

#ifdef LOG_INH_ENTER
	push  {r0,r2,r3}
	mov   r0, r3                 /* 例外番号をパラメータに  */
	bl    log_inh_enter          /* log_exc_enterを呼び出す */
	pop   {r0,r2,r3}
	push  {r3}                   /* 例外番号をスタックへ    */
#endif /* LOG_EXC_ENTER */

	/*
	 *  割込みハンドラの呼び出し
	 */
	blx   r2

#ifdef LOG_INH_LEAVE
	pop   {r0}                   /* 例外番号を引数に        */
	bl    log_exc_leave          /* log_exc_leaveを呼び出す */
#endif /* LOG_INH_LEAVE */

/*
 *  割込み/例外出口
 *
 *  ret_exc/ret_intは，CPU例外/割込みハンドラから戻った直後に実行する
 *  ルーチンである．
 */
ALABEL(ret_exc)
ALABEL(ret_int)
	/*
	 *  割込みロック状態とする．この時点では，CPUロック状態にはならない
	 * （basepriとlock_flagとsaved_iipmは更新しない）．
	 *
	 *  割込みロック状態とするのは，戻り先のコンテキストのチェックと，
	 *  戻り先が非タスクコンテキストであった場合のリターンをアトミック
	 *  に行うためである．bsepriをCPUロックの値にすることでもアトミッ
	 *  クなチェックと復帰は可能であるが，割込みからリターンしても，
	 *  basepri の設定内容は元に戻らないため，使用することができない． 
	 *  一方，FAULTMASKは，割込みからのリターン処理によって，'0'にクリ
	 *  アされる．
	 */
	cpsid f

	/*
	 *  戻り先のコンテキストの判定
	 * 
	 *  割込みハンドラ実行にLRにセットされるEXC_RETURNをチェックして，戻り
	 *  先でMSPが使われていれば，割込み先が非タスクコンテキストと判定する．
	 */
	pop   {r3}                     /* lrをスタックから取得         */
	tst   r3, #EXC_RETURN_PSP      /* 戻り先がPSPなら ret_int_1 へ */
	bne   ret_int_1
	pop   {r1}                     /* 元の割込み優先度マスク(basepri)をr1へ */
	b     ret_int_2                

	/*
	 *  一段目の割込みの出口処理
	 */
ALABEL(ret_int_1)
	/*
	 *  PSP上から，EXC_RETURN(r0)と元の割込み優先度マスク(basepri)(r1)
	 *  を取得
	 */
	mrs   r2, psp
	ldmfd r2!, {r0,r1} 
	msr   psp, r2

	/*
	 *  割込みハンドラによりディスパッチ要求があった場合には，
	 *  request_dispatch_retintによって，PendSV要求が発行されている．
	 *  その場合，このまま割込みハンドラからリターンした後，
	 *  PendSVの割込みが入り，そこでディスパッチャが実行される
	 *  よって，ここではディスパッチするかどうかのチェック処理は
	 *  不要である
	 */

#ifdef TOPPERS_SUPPORT_OVRHDR
	push    {r1,r3}
	bl      ovrtimer_start
	pop     {r1,r3}
#endif /* TOPPERS_SUPPORT_OVRHDR */
ALABEL(ret_int_2)
	/*
	 *  ここには割込みロック状態（FAULTMASKがセット）された状態で来る．
	 *  Handlerモードからのリターンにより自動的に割込みロック解除状態になる．
	 *  割込み優先度マスクは割込み前に状態に戻す．
	 *  CPUロック解除状態に戻る様にlock_flagを0とする．
	 *  CPUロック解除状態で発生した例外はカーネル管理外の例外として，
	 *  core_nonkernel_ret_exc_2 からリターンするため，無条件にCPUロック解除状態とする．
	 */ 
	msr   basepri, r1             /* 割込み優先度マスクを割込み前の状態へ */
	mov   r0, #0
	ldr   r1, =lock_flag          /* CPUロック解除状態へ */
	str   r0, [r1]
	bx    r3                      /* リターン */

	ATHUMB(pendsv_handler)
	AGLOBAL(pendsv_handler)
ALABEL(pendsv_handler)
	ldr    r0, =p_runtsk
	ldr    r1, [r0]
	/* p_runtsk == NULL <=> アイドル処理から -> コンテキスト保存なし */
	cbz    r1, pendsv_handler_1
	/* コンテキストを保存 */
	mrs    r2, psp
	stmfd  r2!, {r4-r11}
#ifdef TOPPERS_FPU_CONTEXT
	tst    lr, #EXC_RETURN_FP
	bne    pendsv_handler_0
	vstmdb r2!, {s16-s31}
	/* vstmdb により，Lazy Stacking の際もスクラッチが保存される． */
ALABEL(pendsv_handler_0)
#endif /* TOPPERS_FPU_CONTEXT */
	str    r2, [r1, #TCB_sp]
	str    lr, [r1, #TCB_pc]
ALABEL(pendsv_handler_1)
	/*
	 * この時点でのレジスタ
	 * r0 : &p_runtsk
	 * r1 : p_runtsk
	 */
#ifdef LOG_DSP_ENTER
	push   {r0, r1}
	mov    r0, r1
	bl     log_dsp_enter
	pop    {r0, r1}
#endif /* LOG_DSP_ENTER */
	ldr    r2, =p_schedtsk
	ldr    r2, [r2]
	str    r2, [r0] /* p_runtsk = p_schedtsk */
	cbz    r2, return_to_idle /* p_runtsk == NULL なら idle_loop へ */
	/* 戻り先が EXC_RETURN でないなら Thread モードへ */
	ldr    r0, [r2, #TCB_pc]
	and    r3, r0, #EXC_RETURN_PREFIX
	cmp    r3, #EXC_RETURN_PREFIX
	bne    return_to_thread
#ifdef LOG_DSP_LEAVE
	push   {r0, r2}
	mov    r0, r2
	bl     log_dsp_leave
	pop    {r0, r2}
#endif /* LOG_DSP_LEAVE */
#if __TARGET_ARCH_THUMB >= 5
	ldr    r1, [r2, #TCB_stk_top]
	msr    psplim, r1
#endif /* __TARGET_ARCH_THUMB >= 5 */
	ldr    r1, [r2, #TCB_sp]
#ifdef TOPPERS_FPU_CONTEXT
	tst    r0, #EXC_RETURN_FP
	bne    pendsv_handler_2
	vldmia r1!, {s16-s31}
ALABEL(pendsv_handler_2)
#endif /* TOPPERS_FPU_CONTEXT */
	ldmfd  r1!, {r4-r11}
	msr    psp, r1
	bx     r0
ALABEL(return_to_thread)
	/*
	 * この時点でのレジスタ
	 * r0 : p_runtsk->tskctxb.pc
	 * r2 : p_runtsk
	 */
	/* CPU ロック状態へ */
	ldr    r1, =lock_flag
	mov    r3, #1
	str    r3, [r1]
	ldr    r1, =#IIPM_LOCK
	msr    basepri, r1
#ifdef LOG_DSP_LEAVE
	push   {r0, r2}
	mov    r0, r2
	bl     log_dsp_leave
	pop    {r0, r2}
#endif /* LOG_DSP_LEAVE */
	ldr    r1, [r2, #TCB_sp]
#ifdef TOPPERS_FPU_CONTEXT
	ldr    lr, =#EXC_RETURN
	ldr    r3, [r2, #TCB_fpu_flag]
	cbz    r3, return_to_thread_0
	vldmia r1!, {s16-s31}
	orr    lr, #EXC_RETURN_FP
ALABEL(return_to_thread_0)
#endif /* TOPPERS_FPU_CONTEXT */
	ldmfd  r1!, {r4-r11}
	ldr    r3, [r2, #TCB_stk_top]
	msr    psplim, r3
	/* ダミーの例外フレームを作成 */
	ldr    r3, =#EPSR_T
	stmfd  r1!, {r0, r3} /* xPSR と 戻り先番地 */
	sub    r1, #(4 * 6)
	/* start_r へ分岐する場合のため，r1 に p_runtsk を設定 */
	str    r2, [r1, #(4 * 1)]
	msr    psp, r1
#ifdef TOPPERS_FPU_CONTEXT
	bx     lr
#else
	ldr    pc, =#EXC_RETURN
#endif /* TOPPERS_FPU_CONTEXT */
ALABEL(return_to_idle)
	mrs   r0, psp
	ldr   r1, =idle_loop
	ldr   r2, =#EPSR_T
	stmfd r0!, {r1, r2}
	sub   r0, #(4 * 6)
	msr   psp, r0
	ldr   pc, =#EXC_RETURN

/*
 * Thread モードから Handler モードへの復帰
 * dispatch -> do_dispatch から呼ばれる
 * この時点でのレジスタ
 * r4 : p_runtsk
 * r5 : p_runtsk->tskctxb.pc
 */
	ATHUMB(svc_handler)
	AGLOBAL(svc_handler)
ALABEL(svc_handler)
#ifdef LOG_DSP_LEAVE
	mov    r0, r4
	bl     log_dsp_leave
#endif /* LOG_DSP_LEAVE */
	/* CPU ロック解除状態へ */
	ldr    r0, =lock_flag
	mov    r1, #0
	str    r1, [r0]
	ldr    r0, =#IIPM_ENAALL
	msr    basepri, r0
	ldr    r0, [r4, #TCB_stk_top]
	msr    psplim, r0
	ldr    r0, [r4, #TCB_sp]
#ifdef TOPPERS_FPU_CONTEXT
	tst    r5, #EXC_RETURN_FP
	bne    svc_handler_0
	vldmia r0!, {s16-s31}
ALABEL(svc_handler_0)
#endif /* TOPPERS_FPU_CONTEXT */
	mov    r1, r5
	ldmfd  r0!, {r4-r11}
	msr    psp, r0
	bx     r1

/*
 *  ディスパッチャの動作開始
 */
	ATHUMB(start_dispatch)
	AGLOBAL(start_dispatch)
ALABEL(start_dispatch)
	/*
	 *  このルーチンは，カーネル起動時に，すべての割込みを禁止した状態
	 * （割込みロック状態と同等）で呼び出される．また，割込みモード（非
	 *  タスクコンテキストと同等）で呼び出されることを想定している．
	 *
	 *  core_initializeで，lock_flagをfalseに，saved_iipmをIIPM_ENAALLに
	 *  初期化しているため，カーネル管理外の割込みを許可することで，
	 *  CPUロック状態・（モデル上の）割込み優先度マスク全解除状態になる．
	 *  また，task_initializeでdisdspをfalseに初期化しているため，ディ
	 *  スパッチ許可状態になっている．
	 */
#if __TARGET_ARCH_THUMB >= 5
	ldr   r0, =istk
	ldr   r0, [r0]
	msr   msplim, r0
#endif /* __TARGET_ARCH_THUMB >= 5 */
	ldr   r0, =istkpt             /* MSPを初期化   */
	ldr   r1, [r0]                /* start_dispatch呼び出し時に呼び出し用に */
	msr   msp, r1                 /* 使用しているため初期化する             */
	/* 
	 * スタックをIDが1のタスクのスタック領域に切り換える
	 */
	mov   r0, #CONTROL_PSP        /* PSPを有効に  */
	msr   control, r0
	isb                           /* control の操作後に必要 */
	ldr   r1, =tinib_table
	ldr   sp, [r1, #TINIB_stk_bottom]

	/* dispatcher_0 の引数を設定 */
	ldr   r1, =p_schedtsk
	ldr   r1, [r1]
	ldr   r2, =p_runtsk

	cpsie f                       /* カーネル管理外の割込みを許可 */
	b     dispatcher_0

/*
 *  現在のコンテキストを捨ててディスパッチ
 */
	ATHUMB(exit_and_dispatch)
	AGLOBAL(exit_and_dispatch)
ALABEL(exit_and_dispatch)
	/* dispatcher_0 の引数を設定 */
	ldr   r1, =p_schedtsk
	ldr   r1, [r1]
	ldr   r2, =p_runtsk
	b     dispatcher_0

/*
 * ディスパッチャ本体
 * 引数
 * r0: p_runtsk
 * r1: p_schedtsk
 * r2: &p_runtsk
 */
	ATHUMB(do_dispatch)
	AGLOBAL(do_dispatch)
ALABEL(do_dispatch)
	push  {r4-r11}
#ifdef TOPPERS_FPU_CONTEXT
	mrs   r3, control
	and   r3, #CONTROL_FPCA
	cbz   r3, dispatch_1 /* FPU の使用がなければ保存をスキップ */
	vpush {s16-s31}
	mov   r3, #CONTROL_PSP
	msr   control, r3 /* FPCA をクリア */
ALABEL(dispatch_1)
	/* fpu_flag はゼロもしくは CONTROL_PSP と同じ値（非ゼロ） */
	str   r3, [r0, #TCB_fpu_flag]
#endif /* TOPPERS_FPU_CONTEXT */
	str   lr, [r0, #TCB_pc]
	str   sp, [r0, #TCB_sp]
ALABEL(dispatcher_0)
#ifdef LOG_DSP_ENTER
	push  {r1, r2}
	bl    log_dsp_enter
	pop   {r1, r2}
#endif /* LOG_DSP_ENTER */
	str   r1, [r2] /* p_runtsk = p_schedtsk */
	cbz   r1, idle_loop /* p_runtsk == NULL ならアイドル処理へ */
	ldr   r2, [r1, #TCB_pc]
	/* 実行再開番地が EXC_RETURN なら Handler モードへ */
	and   r3, r2, #EXC_RETURN_PREFIX
	cmp   r3, #EXC_RETURN_PREFIX
	bne   dispatcher_1
	/* r1, r2 は例外ハンドラの先頭で未定義となるため退避 */
	mov   r4, r1
	mov   r5, r2
	svc   #0

/*
 * Thread モードでのコンテキスト復帰
 * この時点でのレジスタ
 * r1 : p_runtsk
 * r2 : p_runtsk->tskctxb.pc
 */
	ATHUMB(dispatcher_1)
	AGLOBAL(dispatcher_1)
ALABEL(dispatcher_1)
#ifdef LOG_DSP_LEAVE
	push  {r1, r2}
	mov   r0, r1
	bl    log_dsp_leave
	pop   {r1, r2}
#endif /* LOG_DSP_LEAVE */
#if __TARGET_ARCH_THUMB >= 5
	ldr   r0, [r1, #TCB_stk_top]
	msr   psplim, r0
#endif /* __TARGET_ARCH_THUMB >= 5 */
	ldr   sp, [r1, #TCB_sp]
#ifdef TOPPERS_FPU_CONTEXT
	ldr   r3, [r1, #TCB_fpu_flag]
	cbz   r3, dispatcher_2
	vpop  {s16-s31} /* CONTROL.FPCA もセットされる */
ALABEL(dispatcher_2)
#endif /* TOPPERS_FPU_CONTEXT */
	pop   {r4-r11}
	bx    r2

ALABEL(idle_loop)
	/* ここではすでに割込み許可状態 */
#ifdef TOPPERS_CUSTOM_IDLE
	toppers_asm_custom_idle
#else
	/* CPU ロック解除状態へ */
	ldr r0, =lock_flag
	mov r1, #0
	str r1, [r0]
	ldr r0, =#IIPM_ENAALL
	msr basepri, r0
ALABEL(_idle_loop_1)
	/*
	 *  basepriを全割込み許可に設定してからwfiが発行されるまでに
	 *  割込みが入った場合，そこでディスパッチが必要な状態になれば
	 *  割込みの出口処理で遅延ディスパッチし，ここには戻ってこない．
	 *  遅延ディスパッチしなかった場合はここに戻ってきて次の割込みを
	 *  wfiで待つため，想定どおりの動作となる
	 */
	wfi
	b     _idle_loop_1
	nop
#endif /* TOPPERS_CUSTOM_IDLE */

/*
 * タスクの起動
 * r1 にタスクの TCB が設定されている
 */
	ATHUMB(start_r)
	AGLOBAL(start_r)
ALABEL(start_r)
#ifdef TOPPERS_SUPPORT_OVRHDR
	mov r4, r1
	bl  ovrtimer_start
	mov r1, r4
#endif /* TOPPERS_SUPPORT_OVRHDR */
	/* CPU ロック解除状態へ */
	ldr r0, =lock_flag
	mov r2, #0
	str r2, [r0]
	ldr r0, =#IIPM_ENAALL
	msr basepri, r0
	ldr r2, [r1, #TCB_p_tinib]
	ldr r0, [r2, #TINIB_exinf]
	ldr lr, =ext_tsk
	ldr pc, [r2, #TINIB_task]

/*
 *  カーネルの終了処理の呼出し
 *
 *  スタックを非タスクコンテキスト用に切り替え．
 *  
 */
	ATHUMB(call_exit_kernel)
	AGLOBAL(call_exit_kernel)
ALABEL(call_exit_kernel)
	mov   r1, #CONTROL_MSP
	msr   control, r1  /* MSPを有効に  */
	isb                /* control の操作後に必要 */
	b     exit_kernel  /* カーネルの終了処理を呼ぶ */

/*
 *  微少時間待ち
 */
	AALIGN(2)
	ATEXT
	ATHUMB(sil_dly_nse)
	AGLOBAL(sil_dly_nse)
ALABEL(sil_dly_nse)
	sub   r0, r0, #SIL_DLY_TIM1
	cmp   r0, #0
	bgt   sil_dly_nse1
	bx    lr
ALABEL(sil_dly_nse1)
	sub   r0, r0, #SIL_DLY_TIM2
	cmp   r0, #0
	bgt   sil_dly_nse1
	bx    lr
