/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tRPCDedicatedTaskMainWithOpener_TECSGEN_H
#define tRPCDedicatedTaskMainWithOpener_TECSGEN_H

/*
 * celltype          :  tRPCDedicatedTaskMainWithOpener
 * global name       :  tRPCDedicatedTaskMainWithOpener
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  false
 * has_INIB          :  true
 * rom               :  yes
 * CB initializer    :  no
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sTaskBody_tecsgen.h"
#include "sUnmarshalerMain_tecsgen.h"
#include "sServerChannelOpener_tecsgen.h"
#include "sKernel_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tRPCDedicatedTaskMainWithOpener_INIB {
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    RELTIM         initialDelay;
    RELTIM         reopenDelay;
}  tRPCDedicatedTaskMainWithOpener_INIB;

/* CB は存在しない。INIB を CB の代わりに使用するための define #_DCI_# */
#define tRPCDedicatedTaskMainWithOpener_CB_tab           tRPCDedicatedTaskMainWithOpener_INIB_tab
#define tRPCDedicatedTaskMainWithOpener_CB               tRPCDedicatedTaskMainWithOpener_INIB
#define tag_tRPCDedicatedTaskMainWithOpener_CB           tag_tRPCDedicatedTaskMainWithOpener_INIB

extern tRPCDedicatedTaskMainWithOpener_INIB  tRPCDedicatedTaskMainWithOpener_INIB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef const struct tag_tRPCDedicatedTaskMainWithOpener_INIB *tRPCDedicatedTaskMainWithOpener_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sTaskBody */
void         tRPCDedicatedTaskMainWithOpener_eMain_main(tRPCDedicatedTaskMainWithOpener_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tRPCDedicatedTaskMainWithOpener_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tOpaqueUnmarshaler_sSample_tecsgen.h"
#include "tSocketServer_tecsgen.h"
#include "tKernel_tecsgen.h"
#ifdef  tRPCDedicatedTaskMainWithOpener_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tRPCDedicatedTaskMainWithOpener_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tRPCDedicatedTaskMainWithOpener_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define tRPCDedicatedTaskMainWithOpener_N_CELL        (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tRPCDedicatedTaskMainWithOpener_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tRPCDedicatedTaskMainWithOpener_GET_CELLCB(idx) (idx)

/* 属性アクセスマクロ #_AAM_# */
#define tRPCDedicatedTaskMainWithOpener_ATTR_initialDelay( p_that )	((p_that)->initialDelay)
#define tRPCDedicatedTaskMainWithOpener_ATTR_reopenDelay( p_that )	((p_that)->reopenDelay)

#define tRPCDedicatedTaskMainWithOpener_GET_initialDelay(p_that)	((p_that)->initialDelay)
#define tRPCDedicatedTaskMainWithOpener_GET_reopenDelay(p_that)	((p_that)->reopenDelay)



 /* 呼び口関数マクロ #_CPM_# */
#define tRPCDedicatedTaskMainWithOpener_cMain_main( p_that ) \
	  tOpaqueUnmarshaler_sSample_eService_main( \
	   (tOpaqueUnmarshaler_sSample_IDX)0 )
#define tRPCDedicatedTaskMainWithOpener_cOpener_open( p_that ) \
	  tSocketServer_eOpener_open( \
	   &tSocketServer_CB_tab[0] )
#define tRPCDedicatedTaskMainWithOpener_cOpener_close( p_that ) \
	  tSocketServer_eOpener_close( \
	   &tSocketServer_CB_tab[0] )
#define tRPCDedicatedTaskMainWithOpener__require_call_port_tKernel_eKernel_delay( p_that, delay_time ) \
	  tKernel_eKernel_delay( \
	    (delay_time) )
#define tRPCDedicatedTaskMainWithOpener__require_call_port_tKernel_eKernel_exitTask( p_that ) \
	  tKernel_eKernel_exitTask( \
	    )
#define tRPCDedicatedTaskMainWithOpener__require_call_port_tKernel_eKernel_getTime( p_that, p_system_time ) \
	  tKernel_eKernel_getTime( \
	    (p_system_time) )
#define tRPCDedicatedTaskMainWithOpener__require_call_port_tKernel_eKernel_getMicroTime( p_that, p_system_micro_time ) \
	  tKernel_eKernel_getMicroTime( \
	    (p_system_micro_time) )
#define tRPCDedicatedTaskMainWithOpener__require_call_port_tKernel_eKernel_exitKernel( p_that ) \
	  tKernel_eKernel_exitKernel( \
	    )

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* 受け口スケルトン関数プロトタイプ宣言（VMT不要最適化により参照するもの） #_EPSP_# */

#ifndef TOPPERS_CB_TYPE_ONLY

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

/* IDXの正当性チェックマクロ（短縮形） #_CVIA_# */
#define VALID_IDX(IDX)  tRPCDedicatedTaskMainWithOpener_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tRPCDedicatedTaskMainWithOpener_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tRPCDedicatedTaskMainWithOpener_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tRPCDedicatedTaskMainWithOpener_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_initialDelay    tRPCDedicatedTaskMainWithOpener_ATTR_initialDelay( p_cellcb )
#define ATTR_reopenDelay     tRPCDedicatedTaskMainWithOpener_ATTR_reopenDelay( p_cellcb )


/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cMain_main( ) \
          ((void)p_cellcb, tRPCDedicatedTaskMainWithOpener_cMain_main( p_cellcb ))
#define cOpener_open( ) \
          ((void)p_cellcb, tRPCDedicatedTaskMainWithOpener_cOpener_open( p_cellcb ))
#define cOpener_close( ) \
          ((void)p_cellcb, tRPCDedicatedTaskMainWithOpener_cOpener_close( p_cellcb ))
#define delay( delay_time ) \
          ((void)p_cellcb, tRPCDedicatedTaskMainWithOpener__require_call_port_tKernel_eKernel_delay( p_cellcb, delay_time ))
#define exitTask( ) \
          ((void)p_cellcb, tRPCDedicatedTaskMainWithOpener__require_call_port_tKernel_eKernel_exitTask( p_cellcb ))
#define getTime( p_system_time ) \
          ((void)p_cellcb, tRPCDedicatedTaskMainWithOpener__require_call_port_tKernel_eKernel_getTime( p_cellcb, p_system_time ))
#define getMicroTime( p_system_micro_time ) \
          ((void)p_cellcb, tRPCDedicatedTaskMainWithOpener__require_call_port_tKernel_eKernel_getMicroTime( p_cellcb, p_system_micro_time ))
#define exitKernel( ) \
          ((void)p_cellcb, tRPCDedicatedTaskMainWithOpener__require_call_port_tKernel_eKernel_exitKernel( p_cellcb ))




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eMain_main       tRPCDedicatedTaskMainWithOpener_eMain_main

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tRPCDedicatedTaskMainWithOpener_N_CELL; (i)++ ){ \
       //(p_cb) = &tRPCDedicatedTaskMainWithOpener_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tRPCDedicatedTaskMainWithOpener_TECSGENH */
