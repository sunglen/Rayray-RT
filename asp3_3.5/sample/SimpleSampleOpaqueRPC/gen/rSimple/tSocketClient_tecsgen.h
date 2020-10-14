/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tSocketClient_TECSGEN_H
#define tSocketClient_TECSGEN_H

/*
 * celltype          :  tSocketClient
 * global name       :  tSocketClient
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
#include "sSocketClientOpener_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tSocketClient_INIB {
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    int16_t        portNo;
    char_t*        serverAddr;
}  tSocketClient_INIB;
/* セル CB 型宣言 #_CCTPA_# */
typedef struct tag_tSocketClient_CB {
    tSocketClient_INIB  *_inib;
    /* call port #_NEP_# */ 
    /* var #_VA_# */ 
    int_t          sd;
}  tSocketClient_CB;
extern tSocketClient_CB  tSocketClient_CB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef struct tag_tSocketClient_CB *tSocketClient_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sChannel */
ER           tSocketClient_eC0_send(tSocketClient_IDX idx, const int8_t* buf, int16_t size, TMO tmo);
ER           tSocketClient_eC0_flush(tSocketClient_IDX idx, TMO tmo);
ER_UINT      tSocketClient_eC0_receive(tSocketClient_IDX idx, int8_t* buf, int16_t size, TMO tmo);
ER           tSocketClient_eC0_end_receive(tSocketClient_IDX idx);
ER           tSocketClient_eC0_reset(tSocketClient_IDX idx);
/* sSocketClientOpener */
ER           tSocketClient_eOpener_open(tSocketClient_IDX idx, const char_t* serverAddr, uint16_t portNo, TMO tmo);
ER           tSocketClient_eOpener_simpleOpen(tSocketClient_IDX idx, TMO tmo);
ER           tSocketClient_eOpener_close(tSocketClient_IDX idx, TMO tmo);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

#define tSocketClient_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define tSocketClient_N_CELL        (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tSocketClient_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tSocketClient_GET_CELLCB(idx) (idx)

/* 属性アクセスマクロ #_AAM_# */
#define tSocketClient_ATTR_portNo( p_that )	((p_that)->_inib->portNo)
#define tSocketClient_ATTR_serverAddr( p_that )	((p_that)->_inib->serverAddr)

#define tSocketClient_GET_portNo(p_that)	((p_that)->_inib->portNo)
#define tSocketClient_GET_serverAddr(p_that)	((p_that)->_inib->serverAddr)


/* var アクセスマクロ #_VAM_# */
#define tSocketClient_VAR_sd(p_that)	((p_that)->sd)

#define tSocketClient_GET_sd(p_that)	((p_that)->sd)
#define tSocketClient_SET_sd(p_that,val)	((p_that)->sd=(val))

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
#define VALID_IDX(IDX)  tSocketClient_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tSocketClient_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tSocketClient_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tSocketClient_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_portNo          tSocketClient_ATTR_portNo( p_cellcb )
#define ATTR_serverAddr      tSocketClient_ATTR_serverAddr( p_cellcb )


/* var アクセスマクロ(短縮形) #_VAMA_# */
#define VAR_sd               tSocketClient_VAR_sd( p_cellcb )




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eC0_send         tSocketClient_eC0_send
#define eC0_flush        tSocketClient_eC0_flush
#define eC0_receive      tSocketClient_eC0_receive
#define eC0_end_receive  tSocketClient_eC0_end_receive
#define eC0_reset        tSocketClient_eC0_reset
#define eOpener_open     tSocketClient_eOpener_open
#define eOpener_simpleOpen tSocketClient_eOpener_simpleOpen
#define eOpener_close    tSocketClient_eOpener_close

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tSocketClient_N_CELL; (i)++ ){ \
       (p_cb) = &tSocketClient_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	(p_that)->_inib = &tSocketClient_INIB_tab[(i)];

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tSocketClient_TECSGENH */
