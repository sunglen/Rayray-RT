/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tPPAllocator_TECSGEN_H
#define tPPAllocator_TECSGEN_H

/*
 * celltype          :  tPPAllocator
 * global name       :  tPPAllocator
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
#include "sPPAllocator_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル INIB 型宣言 #_CIP_# */
typedef const struct tag_tPPAllocator_INIB {
    /* call port #_NEP_# */ 
    /* attribute(RO) #_ATO_# */ 
    uint32_t       heapSize;
    int8_t*        buf;
}  tPPAllocator_INIB;
/* セル CB 型宣言 #_CCTPA_# */
typedef struct tag_tPPAllocator_CB {
    tPPAllocator_INIB  *_inib;
    /* call port #_NEP_# */ 
    /* var #_VA_# */ 
    uint32_t       allocatedSize;
}  tPPAllocator_CB;
extern tPPAllocator_CB  tPPAllocator_CB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef struct tag_tPPAllocator_CB *tPPAllocator_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sPPAllocator */
ER           tPPAllocator_ePPAllocator_alloc(tPPAllocator_IDX idx, uint32_t size, void** ptr);
ER           tPPAllocator_ePPAllocator_dealloc(tPPAllocator_IDX idx, const void* ptr);
ER           tPPAllocator_ePPAllocator_dealloc_all(tPPAllocator_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY

#define tPPAllocator_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define tPPAllocator_N_CELL         (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tPPAllocator_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tPPAllocator_GET_CELLCB(idx) (idx)

/* 属性アクセスマクロ #_AAM_# */
#define tPPAllocator_ATTR_heapSize( p_that )	((p_that)->_inib->heapSize)

#define tPPAllocator_GET_heapSize(p_that)	((p_that)->_inib->heapSize)


/* var アクセスマクロ #_VAM_# */
#define tPPAllocator_VAR_buf(p_that)	((p_that)->_inib->buf)
#define tPPAllocator_VAR_allocatedSize(p_that)	((p_that)->allocatedSize)

#define tPPAllocator_GET_buf(p_that)	((p_that)->buf)
#define tPPAllocator_SET_buf(p_that,val)	((p_that)->buf=(val))
#define tPPAllocator_GET_allocatedSize(p_that)	((p_that)->allocatedSize)
#define tPPAllocator_SET_allocatedSize(p_that,val)	((p_that)->allocatedSize=(val))

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
#define VALID_IDX(IDX)  tPPAllocator_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tPPAllocator_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tPPAllocator_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tPPAllocator_IDX


/* 属性アクセスマクロ(短縮形) #_AAMA_# */
#define ATTR_heapSize        tPPAllocator_ATTR_heapSize( p_cellcb )


/* var アクセスマクロ(短縮形) #_VAMA_# */
#define VAR_buf              tPPAllocator_VAR_buf( p_cellcb )
#define VAR_allocatedSize    tPPAllocator_VAR_allocatedSize( p_cellcb )




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define ePPAllocator_alloc tPPAllocator_ePPAllocator_alloc
#define ePPAllocator_dealloc tPPAllocator_ePPAllocator_dealloc
#define ePPAllocator_dealloc_all tPPAllocator_ePPAllocator_dealloc_all

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tPPAllocator_N_CELL; (i)++ ){ \
       (p_cb) = &tPPAllocator_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)	(void)(p_that);
#define SET_CB_INIB_POINTER(i,p_that)\
	(p_that)->_inib = &tPPAllocator_INIB_tab[(i)];

#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tPPAllocator_TECSGENH */
