/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tSysLog_TECSGEN_H
#define tSysLog_TECSGEN_H

/*
 * celltype          :  tSysLog
 * global name       :  tSysLog
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
#include "sSysLog_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB (ダミー)型宣言 #_CCDP_# */
typedef struct tag_tSysLog_CB {
    int  dummy;
} tSysLog_CB;
/* シングルトンセル CB プロトタイプ宣言 #_SCP_# */


/* セルタイプのIDX型 #_CTIX_# */
typedef int   tSysLog_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sSysLog */
ER           tSysLog_eSysLog_write( uint_t prio, const SYSLOG* p_syslog);
ER_UINT      tSysLog_eSysLog_read( SYSLOG* p_syslog);
ER           tSysLog_eSysLog_mask( uint_t logmask, uint_t lowmask);
ER           tSysLog_eSysLog_refer( T_SYSLOG_RLOG* pk_rlog);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

#ifndef TOPPERS_CB_TYPE_ONLY


/* セルCBを得るマクロ #_GCB_# */
#define tSysLog_GET_CELLCB(idx) ((void *)0)
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


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tSysLog_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tSysLog_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tSysLog_IDX




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eSysLog_write    tSysLog_eSysLog_write
#define eSysLog_read     tSysLog_eSysLog_read
#define eSysLog_mask     tSysLog_eSysLog_mask
#define eSysLog_refer    tSysLog_eSysLog_refer

/* CB 初期化マクロ #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tSysLog_TECSGENH */
