/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tOpaqueMarshaler_sSample_TECSGEN_H
#define tOpaqueMarshaler_sSample_TECSGEN_H

/*
 * celltype          :  tOpaqueMarshaler_sSample
 * global name       :  tOpaqueMarshaler_sSample
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
#include "sSample_tecsgen.h"
#include "sTDR_tecsgen.h"
#include "sSemaphore_tecsgen.h"
#include "sRPCErrorHandler_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB (ダミー)型宣言 #_CCDP_# */
typedef struct tag_tOpaqueMarshaler_sSample_CB {
    int  dummy;
} tOpaqueMarshaler_sSample_CB;

/* セルタイプのIDX型 #_CTIX_# */
typedef int   tOpaqueMarshaler_sSample_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sSample */
ER           tOpaqueMarshaler_sSample_eClientEntry_sayHello(tOpaqueMarshaler_sSample_IDX idx, int32_t times);
ER           tOpaqueMarshaler_sSample_eClientEntry_howAreYou(tOpaqueMarshaler_sSample_IDX idx, char_t* buf, int32_t len);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tOpaqueMarshaler_sSample_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tNBOTDR_tecsgen.h"
#include "tSemaphore_tecsgen.h"
#ifdef  tOpaqueMarshaler_sSample_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tOpaqueMarshaler_sSample_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tOpaqueMarshaler_sSample_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define tOpaqueMarshaler_sSample_N_CELL        (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tOpaqueMarshaler_sSample_VALID_IDX(IDX) (1)

/* optional 呼び口をテストするマクロ #_TOCP_# */
#define tOpaqueMarshaler_sSample_is_cLockChannel_joined(p_that) \
	  (1)
#define tOpaqueMarshaler_sSample_is_cErrorHandler_joined(p_that) \
	  (0)    /* not joined */

/* セルCBを得るマクロ #_GCB_# */
#define tOpaqueMarshaler_sSample_GET_CELLCB(idx) ((void *)0)
 /* 呼び口関数マクロ #_CPM_# */
#define tOpaqueMarshaler_sSample_cTDR_reset( p_that ) \
	  tNBOTDR_eTDR_reset( \
	   &tNBOTDR_CB_tab[0] )
#define tOpaqueMarshaler_sSample_cTDR_sendSOP( p_that, b_client ) \
	  tNBOTDR_eTDR_sendSOP( \
	   &tNBOTDR_CB_tab[0], (b_client) )
#define tOpaqueMarshaler_sSample_cTDR_receiveSOP( p_that, b_client ) \
	  tNBOTDR_eTDR_receiveSOP( \
	   &tNBOTDR_CB_tab[0], (b_client) )
#define tOpaqueMarshaler_sSample_cTDR_sendEOP( p_that, b_continue ) \
	  tNBOTDR_eTDR_sendEOP( \
	   &tNBOTDR_CB_tab[0], (b_continue) )
#define tOpaqueMarshaler_sSample_cTDR_receiveEOP( p_that, b_continue ) \
	  tNBOTDR_eTDR_receiveEOP( \
	   &tNBOTDR_CB_tab[0], (b_continue) )
#define tOpaqueMarshaler_sSample_cTDR_putInt8( p_that, in ) \
	  tNBOTDR_eTDR_putInt8( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putInt16( p_that, in ) \
	  tNBOTDR_eTDR_putInt16( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putInt32( p_that, in ) \
	  tNBOTDR_eTDR_putInt32( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putInt64( p_that, in ) \
	  tNBOTDR_eTDR_putInt64( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putInt128( p_that, in ) \
	  tNBOTDR_eTDR_putInt128( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_getInt8( p_that, out ) \
	  tNBOTDR_eTDR_getInt8( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getInt16( p_that, out ) \
	  tNBOTDR_eTDR_getInt16( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getInt32( p_that, out ) \
	  tNBOTDR_eTDR_getInt32( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getInt64( p_that, out ) \
	  tNBOTDR_eTDR_getInt64( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getInt128( p_that, out ) \
	  tNBOTDR_eTDR_getInt128( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_putUInt8( p_that, in ) \
	  tNBOTDR_eTDR_putUInt8( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putUInt16( p_that, in ) \
	  tNBOTDR_eTDR_putUInt16( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putUInt32( p_that, in ) \
	  tNBOTDR_eTDR_putUInt32( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putUInt64( p_that, in ) \
	  tNBOTDR_eTDR_putUInt64( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putUInt128( p_that, in ) \
	  tNBOTDR_eTDR_putUInt128( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_getUInt8( p_that, out ) \
	  tNBOTDR_eTDR_getUInt8( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getUInt16( p_that, out ) \
	  tNBOTDR_eTDR_getUInt16( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getUInt32( p_that, out ) \
	  tNBOTDR_eTDR_getUInt32( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getUInt64( p_that, out ) \
	  tNBOTDR_eTDR_getUInt64( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getUInt128( p_that, out ) \
	  tNBOTDR_eTDR_getUInt128( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_putChar( p_that, in ) \
	  tNBOTDR_eTDR_putChar( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_getChar( p_that, out ) \
	  tNBOTDR_eTDR_getChar( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_putBool( p_that, in ) \
	  tNBOTDR_eTDR_putBool( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_getBool( p_that, out ) \
	  tNBOTDR_eTDR_getBool( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_putFloat32( p_that, in ) \
	  tNBOTDR_eTDR_putFloat32( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putDouble64( p_that, in ) \
	  tNBOTDR_eTDR_putDouble64( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_getFloat32( p_that, out ) \
	  tNBOTDR_eTDR_getFloat32( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getDouble64( p_that, out ) \
	  tNBOTDR_eTDR_getDouble64( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_putSChar( p_that, in ) \
	  tNBOTDR_eTDR_putSChar( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putShort( p_that, in ) \
	  tNBOTDR_eTDR_putShort( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putInt( p_that, in ) \
	  tNBOTDR_eTDR_putInt( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putLong( p_that, in ) \
	  tNBOTDR_eTDR_putLong( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_getSChar( p_that, out ) \
	  tNBOTDR_eTDR_getSChar( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getShort( p_that, out ) \
	  tNBOTDR_eTDR_getShort( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getInt( p_that, out ) \
	  tNBOTDR_eTDR_getInt( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getLong( p_that, out ) \
	  tNBOTDR_eTDR_getLong( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_putUChar( p_that, in ) \
	  tNBOTDR_eTDR_putUChar( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putUShort( p_that, in ) \
	  tNBOTDR_eTDR_putUShort( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putUInt( p_that, in ) \
	  tNBOTDR_eTDR_putUInt( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_putULong( p_that, in ) \
	  tNBOTDR_eTDR_putULong( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueMarshaler_sSample_cTDR_getUChar( p_that, out ) \
	  tNBOTDR_eTDR_getUChar( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getUShort( p_that, out ) \
	  tNBOTDR_eTDR_getUShort( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getUInt( p_that, out ) \
	  tNBOTDR_eTDR_getUInt( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_getULong( p_that, out ) \
	  tNBOTDR_eTDR_getULong( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueMarshaler_sSample_cTDR_putIntptr( p_that, ptr ) \
	  tNBOTDR_eTDR_putIntptr( \
	   &tNBOTDR_CB_tab[0], (ptr) )
#define tOpaqueMarshaler_sSample_cTDR_getIntptr( p_that, ptr ) \
	  tNBOTDR_eTDR_getIntptr( \
	   &tNBOTDR_CB_tab[0], (ptr) )
#define tOpaqueMarshaler_sSample_cLockChannel_signal( p_that ) \
	  tSemaphore_eSemaphore_signal( \
	   &tSemaphore_CB_tab[0] )
#define tOpaqueMarshaler_sSample_cLockChannel_wait( p_that ) \
	  tSemaphore_eSemaphore_wait( \
	   &tSemaphore_CB_tab[0] )
#define tOpaqueMarshaler_sSample_cLockChannel_waitPolling( p_that ) \
	  tSemaphore_eSemaphore_waitPolling( \
	   &tSemaphore_CB_tab[0] )
#define tOpaqueMarshaler_sSample_cLockChannel_waitTimeout( p_that, timeout ) \
	  tSemaphore_eSemaphore_waitTimeout( \
	   &tSemaphore_CB_tab[0], (timeout) )
#define tOpaqueMarshaler_sSample_cLockChannel_initialize( p_that ) \
	  tSemaphore_eSemaphore_initialize( \
	   &tSemaphore_CB_tab[0] )
#define tOpaqueMarshaler_sSample_cLockChannel_refer( p_that, pk_semaphore_status ) \
	  tSemaphore_eSemaphore_refer( \
	   &tSemaphore_CB_tab[0], (pk_semaphore_status) )
#define tOpaqueMarshaler_sSample_cErrorHandler_errorOccured( p_that, func_id, er, state ) \
	  ((ER (*)())0)()
	  /* optional no entry port joined */

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
#define VALID_IDX(IDX)  tOpaqueMarshaler_sSample_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tOpaqueMarshaler_sSample_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tOpaqueMarshaler_sSample_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tOpaqueMarshaler_sSample_IDX

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cTDR_reset( ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_reset( p_cellcb ))
#define cTDR_sendSOP( b_client ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_sendSOP( p_cellcb, b_client ))
#define cTDR_receiveSOP( b_client ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_receiveSOP( p_cellcb, b_client ))
#define cTDR_sendEOP( b_continue ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_sendEOP( p_cellcb, b_continue ))
#define cTDR_receiveEOP( b_continue ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_receiveEOP( p_cellcb, b_continue ))
#define cTDR_putInt8( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putInt8( p_cellcb, in ))
#define cTDR_putInt16( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putInt16( p_cellcb, in ))
#define cTDR_putInt32( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putInt32( p_cellcb, in ))
#define cTDR_putInt64( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putInt64( p_cellcb, in ))
#define cTDR_putInt128( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putInt128( p_cellcb, in ))
#define cTDR_getInt8( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getInt8( p_cellcb, out ))
#define cTDR_getInt16( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getInt16( p_cellcb, out ))
#define cTDR_getInt32( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getInt32( p_cellcb, out ))
#define cTDR_getInt64( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getInt64( p_cellcb, out ))
#define cTDR_getInt128( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getInt128( p_cellcb, out ))
#define cTDR_putUInt8( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putUInt8( p_cellcb, in ))
#define cTDR_putUInt16( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putUInt16( p_cellcb, in ))
#define cTDR_putUInt32( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putUInt32( p_cellcb, in ))
#define cTDR_putUInt64( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putUInt64( p_cellcb, in ))
#define cTDR_putUInt128( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putUInt128( p_cellcb, in ))
#define cTDR_getUInt8( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getUInt8( p_cellcb, out ))
#define cTDR_getUInt16( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getUInt16( p_cellcb, out ))
#define cTDR_getUInt32( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getUInt32( p_cellcb, out ))
#define cTDR_getUInt64( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getUInt64( p_cellcb, out ))
#define cTDR_getUInt128( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getUInt128( p_cellcb, out ))
#define cTDR_putChar( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putChar( p_cellcb, in ))
#define cTDR_getChar( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getChar( p_cellcb, out ))
#define cTDR_putBool( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putBool( p_cellcb, in ))
#define cTDR_getBool( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getBool( p_cellcb, out ))
#define cTDR_putFloat32( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putFloat32( p_cellcb, in ))
#define cTDR_putDouble64( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putDouble64( p_cellcb, in ))
#define cTDR_getFloat32( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getFloat32( p_cellcb, out ))
#define cTDR_getDouble64( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getDouble64( p_cellcb, out ))
#define cTDR_putSChar( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putSChar( p_cellcb, in ))
#define cTDR_putShort( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putShort( p_cellcb, in ))
#define cTDR_putInt( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putInt( p_cellcb, in ))
#define cTDR_putLong( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putLong( p_cellcb, in ))
#define cTDR_getSChar( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getSChar( p_cellcb, out ))
#define cTDR_getShort( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getShort( p_cellcb, out ))
#define cTDR_getInt( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getInt( p_cellcb, out ))
#define cTDR_getLong( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getLong( p_cellcb, out ))
#define cTDR_putUChar( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putUChar( p_cellcb, in ))
#define cTDR_putUShort( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putUShort( p_cellcb, in ))
#define cTDR_putUInt( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putUInt( p_cellcb, in ))
#define cTDR_putULong( in ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putULong( p_cellcb, in ))
#define cTDR_getUChar( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getUChar( p_cellcb, out ))
#define cTDR_getUShort( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getUShort( p_cellcb, out ))
#define cTDR_getUInt( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getUInt( p_cellcb, out ))
#define cTDR_getULong( out ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getULong( p_cellcb, out ))
#define cTDR_putIntptr( ptr ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_putIntptr( p_cellcb, ptr ))
#define cTDR_getIntptr( ptr ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cTDR_getIntptr( p_cellcb, ptr ))
#define cLockChannel_signal( ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cLockChannel_signal( p_cellcb ))
#define cLockChannel_wait( ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cLockChannel_wait( p_cellcb ))
#define cLockChannel_waitPolling( ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cLockChannel_waitPolling( p_cellcb ))
#define cLockChannel_waitTimeout( timeout ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cLockChannel_waitTimeout( p_cellcb, timeout ))
#define cLockChannel_initialize( ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cLockChannel_initialize( p_cellcb ))
#define cLockChannel_refer( pk_semaphore_status ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cLockChannel_refer( p_cellcb, pk_semaphore_status ))
#define cErrorHandler_errorOccured( func_id, er, state ) \
          ((void)p_cellcb, tOpaqueMarshaler_sSample_cErrorHandler_errorOccured( p_cellcb, func_id, er, state ))



/* optional 呼び口をテストするマクロ（短縮形） #_TOCPA_# */
#define is_cLockChannel_joined()\
		tOpaqueMarshaler_sSample_is_cLockChannel_joined(p_cellcb)
#define is_cErrorHandler_joined()\
		tOpaqueMarshaler_sSample_is_cErrorHandler_joined(p_cellcb)

/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eClientEntry_sayHello tOpaqueMarshaler_sSample_eClientEntry_sayHello
#define eClientEntry_howAreYou tOpaqueMarshaler_sSample_eClientEntry_howAreYou

/* イテレータコード (FOREACH_CELL)の生成(CB,INIB は存在しない) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tOpaqueMarshaler_sSample_TECSGENH */
