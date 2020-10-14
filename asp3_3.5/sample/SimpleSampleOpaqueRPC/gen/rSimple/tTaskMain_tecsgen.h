/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tTaskMain_TECSGEN_H
#define tTaskMain_TECSGEN_H

/*
 * celltype          :  tTaskMain
 * global name       :  tTaskMain
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  false
 * has_INIB          :  false
 * rom               :  yes
 * CB initializer    :  no
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sTaskBody_tecsgen.h"
#include "sSocketClientOpener_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB (ダミー)型宣言 #_CCDP_# */
typedef struct tag_tTaskMain_CB {
    int  dummy;
} tTaskMain_CB;

/* セルタイプのIDX型 #_CTIX_# */
typedef int   tTaskMain_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sTaskBody */
void         tTaskMain_eBody_main(tTaskMain_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tTaskMain_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tSimple_tecsgen.h"
#include "tSocketClient_tecsgen.h"
#ifdef  tTaskMain_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tTaskMain_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tTaskMain_ID_BASE           (1)  /* ID のベース  #_NIDB_# */
#define tTaskMain_N_CELL            (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tTaskMain_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tTaskMain_GET_CELLCB(idx) ((void *)0)
 /* 呼び口関数マクロ #_CPM_# */
#define tTaskMain_cBody_main( p_that ) \
	  tSimple_eBody_main( \
	    )
#define tTaskMain_cOpener_open( p_that, serverAddr, portNo, tmo ) \
	  tSocketClient_eOpener_open( \
	   &tSocketClient_CB_tab[0], (serverAddr), (portNo), (tmo) )
#define tTaskMain_cOpener_simpleOpen( p_that, tmo ) \
	  tSocketClient_eOpener_simpleOpen( \
	   &tSocketClient_CB_tab[0], (tmo) )
#define tTaskMain_cOpener_close( p_that, tmo ) \
	  tSocketClient_eOpener_close( \
	   &tSocketClient_CB_tab[0], (tmo) )

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
#define VALID_IDX(IDX)  tTaskMain_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tTaskMain_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tTaskMain_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tTaskMain_IDX

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cBody_main( ) \
          ((void)p_cellcb, tTaskMain_cBody_main( p_cellcb ))
#define cOpener_open( serverAddr, portNo, tmo ) \
          ((void)p_cellcb, tTaskMain_cOpener_open( p_cellcb, serverAddr, portNo, tmo ))
#define cOpener_simpleOpen( tmo ) \
          ((void)p_cellcb, tTaskMain_cOpener_simpleOpen( p_cellcb, tmo ))
#define cOpener_close( tmo ) \
          ((void)p_cellcb, tTaskMain_cOpener_close( p_cellcb, tmo ))




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eBody_main       tTaskMain_eBody_main

/* イテレータコード (FOREACH_CELL)の生成(CB,INIB は存在しない) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tTaskMain_TECSGENH */
