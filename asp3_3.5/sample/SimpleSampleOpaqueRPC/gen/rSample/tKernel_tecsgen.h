/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tKernel_TECSGEN_H
#define tKernel_TECSGEN_H

/*
 * celltype          :  tKernel
 * global name       :  tKernel
 * idx_is_id(actual) :  no(no)
 * singleton         :  yes
 * has_CB            :  false
 * has_INIB          :  false
 * rom               :  yes
 * CB initializer    :  no
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sKernel_tecsgen.h"
#include "siKernel_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB (ダミー)型宣言 #_CCDP_# */
typedef struct tag_tKernel_CB {
    int  dummy;
} tKernel_CB;
/* シングルトンセル CB プロトタイプ宣言 #_SCP_# */


/* セルタイプのIDX型 #_CTIX_# */
typedef int   tKernel_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sKernel */
Inline ER           tKernel_eKernel_delay( RELTIM delay_time);
Inline ER           tKernel_eKernel_exitTask();
Inline ER           tKernel_eKernel_getTime( SYSTIM* p_system_time);
Inline ER           tKernel_eKernel_getMicroTime( SYSUTM* p_system_micro_time);
Inline ER           tKernel_eKernel_exitKernel();
/* siKernel */
Inline ER           tKernel_eiKernel_getMicroTime( SYSUTM* p_system_micro_time);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */


/* セルCBを得るマクロ #_GCB_# */
#define tKernel_GET_CELLCB(idx) ((void *)0)
#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* 受け口スケルトン関数プロトタイプ宣言（VMT不要最適化により参照するもの） #_EPSP_# */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tKernel_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tKernel_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tKernel_IDX




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eKernel_delay    tKernel_eKernel_delay
#define eKernel_exitTask tKernel_eKernel_exitTask
#define eKernel_getTime  tKernel_eKernel_getTime
#define eKernel_getMicroTime tKernel_eKernel_getMicroTime
#define eKernel_exitKernel tKernel_eKernel_exitKernel
#define eiKernel_getMicroTime tKernel_eiKernel_getMicroTime

/* CB 初期化マクロ #_CIM_# */
#ifndef TOPPERS_MACRO_ONLY

/* inline ヘッダの include #_INL_# */
#include "tKernel_inline.h"

#endif /* TOPPERS_MACRO_ONLY */

#ifdef TOPPERS_CB_TYPE_ONLY

/* inline のための undef #_UDF_# */
#undef VALID_IDX
#undef GET_CELLCB
#undef CELLCB
#undef CELLIDX
#undef tKernel_IDX
#undef FOREACH_CELL
#undef END_FOREACH_CELL
#undef INITIALIZE_CB
#undef SET_CB_INIB_POINTER
#undef eKernel_delay
#undef eKernel_exitTask
#undef eKernel_getTime
#undef eKernel_getMicroTime
#undef eKernel_exitKernel
#undef eiKernel_getMicroTime
#endif /* TOPPERS_CB_TYPE_ONLY */

#endif /* tKernel_TECSGENH */
