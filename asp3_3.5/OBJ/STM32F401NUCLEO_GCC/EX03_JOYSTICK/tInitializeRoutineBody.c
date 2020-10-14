/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tInitializeRoutineBody_template.c => src/tInitializeRoutineBody.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port : cInitialize  signature: sInitialize context: task
 *   ER             cInitialize_initialize( subscript );
 *
 * #[</PREAMBLE>]# */

#include "tInitializeRoutineBody_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eInitializeRoutineBody
 * entry port: eInitializeRoutineBody
 * signature:  sInitializeRoutineBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInitializeRoutineBody_main
 * name:         eInitializeRoutineBody_main
 * global_name:  tInitializeRoutineBody_eInitializeRoutineBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eInitializeRoutineBody_main(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	int32_t i;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	//呼び口配列に接続されたセルを初期化する
	for(i = 0 ;i < N_CP_cInitialize(p_cellcb); i++){
		cInitialize_main( i );
	}
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
