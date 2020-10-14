/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tOpaqueUnmarshaler_sSample_TECSGEN_H
#define tOpaqueUnmarshaler_sSample_TECSGEN_H

/*
 * celltype          :  tOpaqueUnmarshaler_sSample
 * global name       :  tOpaqueUnmarshaler_sSample
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
#include "sRPCErrorHandler_tecsgen.h"
#include "sUnmarshalerMain_tecsgen.h"
#include "sPPAllocator_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB (ダミー)型宣言 #_CCDP_# */
typedef struct tag_tOpaqueUnmarshaler_sSample_CB {
    int  dummy;
} tOpaqueUnmarshaler_sSample_CB;

/* セルタイプのIDX型 #_CTIX_# */
typedef int   tOpaqueUnmarshaler_sSample_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sUnmarshalerMain */
ER           tOpaqueUnmarshaler_sSample_eService_main(tOpaqueUnmarshaler_sSample_IDX idx);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tOpaqueUnmarshaler_sSample_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tSample_tecsgen.h"
#include "tNBOTDR_tecsgen.h"
#include "tPPAllocator_tecsgen.h"
#ifdef  tOpaqueUnmarshaler_sSample_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tOpaqueUnmarshaler_sSample_CB_TYPE_ONLY */
#ifndef TOPPERS_CB_TYPE_ONLY

#define tOpaqueUnmarshaler_sSample_ID_BASE        (1)  /* ID のベース  #_NIDB_# */
#define tOpaqueUnmarshaler_sSample_N_CELL        (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tOpaqueUnmarshaler_sSample_VALID_IDX(IDX) (1)

/* optional 呼び口をテストするマクロ #_TOCP_# */
#define tOpaqueUnmarshaler_sSample_is_cErrorHandler_joined(p_that) \
	  (0)    /* not joined */

/* セルCBを得るマクロ #_GCB_# */
#define tOpaqueUnmarshaler_sSample_GET_CELLCB(idx) ((void *)0)
 /* 呼び口関数マクロ #_CPM_# */
#define tOpaqueUnmarshaler_sSample_cServerCall_sayHello( p_that, times ) \
	  tSample_eEnt_sayHello( \
	   (tSample_IDX)0, (times) )
#define tOpaqueUnmarshaler_sSample_cServerCall_howAreYou( p_that, buf, len ) \
	  tSample_eEnt_howAreYou( \
	   (tSample_IDX)0, (buf), (len) )
#define tOpaqueUnmarshaler_sSample_cTDR_reset( p_that ) \
	  tNBOTDR_eTDR_reset( \
	   &tNBOTDR_CB_tab[0] )
#define tOpaqueUnmarshaler_sSample_cTDR_sendSOP( p_that, b_client ) \
	  tNBOTDR_eTDR_sendSOP( \
	   &tNBOTDR_CB_tab[0], (b_client) )
#define tOpaqueUnmarshaler_sSample_cTDR_receiveSOP( p_that, b_client ) \
	  tNBOTDR_eTDR_receiveSOP( \
	   &tNBOTDR_CB_tab[0], (b_client) )
#define tOpaqueUnmarshaler_sSample_cTDR_sendEOP( p_that, b_continue ) \
	  tNBOTDR_eTDR_sendEOP( \
	   &tNBOTDR_CB_tab[0], (b_continue) )
#define tOpaqueUnmarshaler_sSample_cTDR_receiveEOP( p_that, b_continue ) \
	  tNBOTDR_eTDR_receiveEOP( \
	   &tNBOTDR_CB_tab[0], (b_continue) )
#define tOpaqueUnmarshaler_sSample_cTDR_putInt8( p_that, in ) \
	  tNBOTDR_eTDR_putInt8( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putInt16( p_that, in ) \
	  tNBOTDR_eTDR_putInt16( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putInt32( p_that, in ) \
	  tNBOTDR_eTDR_putInt32( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putInt64( p_that, in ) \
	  tNBOTDR_eTDR_putInt64( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putInt128( p_that, in ) \
	  tNBOTDR_eTDR_putInt128( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_getInt8( p_that, out ) \
	  tNBOTDR_eTDR_getInt8( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getInt16( p_that, out ) \
	  tNBOTDR_eTDR_getInt16( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getInt32( p_that, out ) \
	  tNBOTDR_eTDR_getInt32( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getInt64( p_that, out ) \
	  tNBOTDR_eTDR_getInt64( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getInt128( p_that, out ) \
	  tNBOTDR_eTDR_getInt128( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_putUInt8( p_that, in ) \
	  tNBOTDR_eTDR_putUInt8( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putUInt16( p_that, in ) \
	  tNBOTDR_eTDR_putUInt16( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putUInt32( p_that, in ) \
	  tNBOTDR_eTDR_putUInt32( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putUInt64( p_that, in ) \
	  tNBOTDR_eTDR_putUInt64( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putUInt128( p_that, in ) \
	  tNBOTDR_eTDR_putUInt128( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_getUInt8( p_that, out ) \
	  tNBOTDR_eTDR_getUInt8( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getUInt16( p_that, out ) \
	  tNBOTDR_eTDR_getUInt16( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getUInt32( p_that, out ) \
	  tNBOTDR_eTDR_getUInt32( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getUInt64( p_that, out ) \
	  tNBOTDR_eTDR_getUInt64( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getUInt128( p_that, out ) \
	  tNBOTDR_eTDR_getUInt128( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_putChar( p_that, in ) \
	  tNBOTDR_eTDR_putChar( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_getChar( p_that, out ) \
	  tNBOTDR_eTDR_getChar( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_putBool( p_that, in ) \
	  tNBOTDR_eTDR_putBool( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_getBool( p_that, out ) \
	  tNBOTDR_eTDR_getBool( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_putFloat32( p_that, in ) \
	  tNBOTDR_eTDR_putFloat32( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putDouble64( p_that, in ) \
	  tNBOTDR_eTDR_putDouble64( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_getFloat32( p_that, out ) \
	  tNBOTDR_eTDR_getFloat32( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getDouble64( p_that, out ) \
	  tNBOTDR_eTDR_getDouble64( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_putSChar( p_that, in ) \
	  tNBOTDR_eTDR_putSChar( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putShort( p_that, in ) \
	  tNBOTDR_eTDR_putShort( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putInt( p_that, in ) \
	  tNBOTDR_eTDR_putInt( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putLong( p_that, in ) \
	  tNBOTDR_eTDR_putLong( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_getSChar( p_that, out ) \
	  tNBOTDR_eTDR_getSChar( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getShort( p_that, out ) \
	  tNBOTDR_eTDR_getShort( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getInt( p_that, out ) \
	  tNBOTDR_eTDR_getInt( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getLong( p_that, out ) \
	  tNBOTDR_eTDR_getLong( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_putUChar( p_that, in ) \
	  tNBOTDR_eTDR_putUChar( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putUShort( p_that, in ) \
	  tNBOTDR_eTDR_putUShort( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putUInt( p_that, in ) \
	  tNBOTDR_eTDR_putUInt( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_putULong( p_that, in ) \
	  tNBOTDR_eTDR_putULong( \
	   &tNBOTDR_CB_tab[0], (in) )
#define tOpaqueUnmarshaler_sSample_cTDR_getUChar( p_that, out ) \
	  tNBOTDR_eTDR_getUChar( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getUShort( p_that, out ) \
	  tNBOTDR_eTDR_getUShort( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getUInt( p_that, out ) \
	  tNBOTDR_eTDR_getUInt( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_getULong( p_that, out ) \
	  tNBOTDR_eTDR_getULong( \
	   &tNBOTDR_CB_tab[0], (out) )
#define tOpaqueUnmarshaler_sSample_cTDR_putIntptr( p_that, ptr ) \
	  tNBOTDR_eTDR_putIntptr( \
	   &tNBOTDR_CB_tab[0], (ptr) )
#define tOpaqueUnmarshaler_sSample_cTDR_getIntptr( p_that, ptr ) \
	  tNBOTDR_eTDR_getIntptr( \
	   &tNBOTDR_CB_tab[0], (ptr) )
#define tOpaqueUnmarshaler_sSample_cErrorHandler_errorOccured( p_that, func_id, er, state ) \
	  ((ER (*)())0)()
	  /* optional no entry port joined */
#define tOpaqueUnmarshaler_sSample_cPPAllocator_alloc( p_that, size, ptr ) \
	  tPPAllocator_ePPAllocator_alloc( \
	   &tPPAllocator_CB_tab[0], (size), (ptr) )
#define tOpaqueUnmarshaler_sSample_cPPAllocator_dealloc( p_that, ptr ) \
	  tPPAllocator_ePPAllocator_dealloc( \
	   &tPPAllocator_CB_tab[0], (ptr) )
#define tOpaqueUnmarshaler_sSample_cPPAllocator_dealloc_all( p_that ) \
	  tPPAllocator_ePPAllocator_dealloc_all( \
	   &tPPAllocator_CB_tab[0] )

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
#define VALID_IDX(IDX)  tOpaqueUnmarshaler_sSample_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tOpaqueUnmarshaler_sSample_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tOpaqueUnmarshaler_sSample_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tOpaqueUnmarshaler_sSample_IDX

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cServerCall_sayHello( times ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cServerCall_sayHello( p_cellcb, times ))
#define cServerCall_howAreYou( buf, len ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cServerCall_howAreYou( p_cellcb, buf, len ))
#define cTDR_reset( ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_reset( p_cellcb ))
#define cTDR_sendSOP( b_client ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_sendSOP( p_cellcb, b_client ))
#define cTDR_receiveSOP( b_client ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_receiveSOP( p_cellcb, b_client ))
#define cTDR_sendEOP( b_continue ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_sendEOP( p_cellcb, b_continue ))
#define cTDR_receiveEOP( b_continue ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_receiveEOP( p_cellcb, b_continue ))
#define cTDR_putInt8( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putInt8( p_cellcb, in ))
#define cTDR_putInt16( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putInt16( p_cellcb, in ))
#define cTDR_putInt32( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putInt32( p_cellcb, in ))
#define cTDR_putInt64( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putInt64( p_cellcb, in ))
#define cTDR_putInt128( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putInt128( p_cellcb, in ))
#define cTDR_getInt8( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getInt8( p_cellcb, out ))
#define cTDR_getInt16( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getInt16( p_cellcb, out ))
#define cTDR_getInt32( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getInt32( p_cellcb, out ))
#define cTDR_getInt64( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getInt64( p_cellcb, out ))
#define cTDR_getInt128( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getInt128( p_cellcb, out ))
#define cTDR_putUInt8( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putUInt8( p_cellcb, in ))
#define cTDR_putUInt16( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putUInt16( p_cellcb, in ))
#define cTDR_putUInt32( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putUInt32( p_cellcb, in ))
#define cTDR_putUInt64( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putUInt64( p_cellcb, in ))
#define cTDR_putUInt128( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putUInt128( p_cellcb, in ))
#define cTDR_getUInt8( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getUInt8( p_cellcb, out ))
#define cTDR_getUInt16( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getUInt16( p_cellcb, out ))
#define cTDR_getUInt32( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getUInt32( p_cellcb, out ))
#define cTDR_getUInt64( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getUInt64( p_cellcb, out ))
#define cTDR_getUInt128( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getUInt128( p_cellcb, out ))
#define cTDR_putChar( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putChar( p_cellcb, in ))
#define cTDR_getChar( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getChar( p_cellcb, out ))
#define cTDR_putBool( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putBool( p_cellcb, in ))
#define cTDR_getBool( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getBool( p_cellcb, out ))
#define cTDR_putFloat32( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putFloat32( p_cellcb, in ))
#define cTDR_putDouble64( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putDouble64( p_cellcb, in ))
#define cTDR_getFloat32( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getFloat32( p_cellcb, out ))
#define cTDR_getDouble64( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getDouble64( p_cellcb, out ))
#define cTDR_putSChar( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putSChar( p_cellcb, in ))
#define cTDR_putShort( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putShort( p_cellcb, in ))
#define cTDR_putInt( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putInt( p_cellcb, in ))
#define cTDR_putLong( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putLong( p_cellcb, in ))
#define cTDR_getSChar( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getSChar( p_cellcb, out ))
#define cTDR_getShort( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getShort( p_cellcb, out ))
#define cTDR_getInt( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getInt( p_cellcb, out ))
#define cTDR_getLong( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getLong( p_cellcb, out ))
#define cTDR_putUChar( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putUChar( p_cellcb, in ))
#define cTDR_putUShort( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putUShort( p_cellcb, in ))
#define cTDR_putUInt( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putUInt( p_cellcb, in ))
#define cTDR_putULong( in ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putULong( p_cellcb, in ))
#define cTDR_getUChar( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getUChar( p_cellcb, out ))
#define cTDR_getUShort( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getUShort( p_cellcb, out ))
#define cTDR_getUInt( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getUInt( p_cellcb, out ))
#define cTDR_getULong( out ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getULong( p_cellcb, out ))
#define cTDR_putIntptr( ptr ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_putIntptr( p_cellcb, ptr ))
#define cTDR_getIntptr( ptr ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cTDR_getIntptr( p_cellcb, ptr ))
#define cErrorHandler_errorOccured( func_id, er, state ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cErrorHandler_errorOccured( p_cellcb, func_id, er, state ))
#define cPPAllocator_alloc( size, ptr ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cPPAllocator_alloc( p_cellcb, size, ptr ))
#define cPPAllocator_dealloc( ptr ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cPPAllocator_dealloc( p_cellcb, ptr ))
#define cPPAllocator_dealloc_all( ) \
          ((void)p_cellcb, tOpaqueUnmarshaler_sSample_cPPAllocator_dealloc_all( p_cellcb ))



/* optional 呼び口をテストするマクロ（短縮形） #_TOCPA_# */
#define is_cErrorHandler_joined()\
		tOpaqueUnmarshaler_sSample_is_cErrorHandler_joined(p_cellcb)

/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eService_main    tOpaqueUnmarshaler_sSample_eService_main

/* イテレータコード (FOREACH_CELL)の生成(CB,INIB は存在しない) #_NFEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for((i)=0;(i)<0;(i)++){

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#endif /* TOPPERS_CB_TYPE_ONLY */

#ifndef TOPPERS_MACRO_ONLY

#endif /* TOPPERS_MACRO_ONLY */

#endif /* tOpaqueUnmarshaler_sSample_TECSGENH */
