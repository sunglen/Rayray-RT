/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tSocketServer_TECSGEN_H
#define tSocketServer_TECSGEN_H

/*
 * celltype          :  tSocketServer
 * global name       :  tSocketServer
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  true
 * has_INIB          :  true
 * rom               :  yes
 * CB initializer    :  yes
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sChannel_tecsgen.h"
#include "sServerChannelOpener_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tSocketServer_INIB {
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    int16_t        portNo;
}  tSocketServer_INIB;
/* セル CB 型宣言 #_CCTPA_# */
typedef struct tag_tSocketServer_CB {
    tSocketServer_INIB  *_inib;
    /* call port #_NEP_# */ 
    /* var #_VA_# */ 
    int_t          sd;
}  tSocketServer_CB;
extern tSocketServer_CB  tSocketServer_CB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef struct tag_tSocketServer_CB *tSocketServer_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sChannel */
ER           tSocketServer_eC1_send(tSocketServer_IDX idx, const int8_t* buf, int16_t size, TMO tmo);
ER           tSocketServer_eC1_flush(tSocketServer_IDX idx, TMO tmo);
ER_UINT      tSocketServer_eC1_receive(tSocketServer_IDX idx, int8_t* buf, int16_t size, TMO tmo);
ER           tSocketServer_eC1_end_receive(tSocketServer_IDX idx);
ER           tSocketServer_eC1_reset(tSocketServer_IDX idx);
/* sServerChannelOpener */
ER           tSocketServer_eOpener_open(tSocketServer_IDX idx);
ER           tSocketServer_eOpener_close(tSocketServer_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

#define tSocketServer_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define tSocketServer_N_CELL        (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tSocketServer_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tSocketServer_GET_CELLCB(idx) (idx)

/* 属性アクセスマクロ #_AAM_# */
#define tSocketServer_ATTR_portNo( p_that )	((p_that)->_inib->portNo)

#define tSocketServer_GET_portNo(p_that)	((p_that)->_inib->portNo)


/* var アクセスマクロ #_VAM_# */
#define tSocketServer_VAR_sd(p_that)	((p_that)->sd)

#define tSocketServer_GET_sd(p_that)	((p_that)->sd)
#define tSocketServer_SET_sd(p_that,val)	((p_that)->sd=(val))

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
#define VALID_IDX(IDX)  tSocketServer_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tSocketServer_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tSocketServer_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tSocketServer_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_portNo          tSocketServer_ATTR_portNo( p_cellcb )


/* var アクセスマクロ(短縮形) #_VAMA_# */
#define VAR_sd               tSocketServer_VAR_sd( p_cellcb )




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eC1_send         tSocketServer_eC1_send
#define eC1_flush        tSocketServer_eC1_flush
#define eC1_receive      tSocketServer_eC1_receive
#define eC1_end_receive  tSocketServer_eC1_end_receive
#define eC1_reset        tSocketServer_eC1_reset
#define eOpener_open     tSocketServer_eOpener_open
#define eOpener_close    tSocketServer_eOpener_close

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tSocketServer_N_CELL; (i)++ ){ \
       (p_cb) = &tSocketServer_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	(p_that)->_inib = &tSocketServer_INIB_tab[(i)];

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tSocketServer_TECSGENH */
