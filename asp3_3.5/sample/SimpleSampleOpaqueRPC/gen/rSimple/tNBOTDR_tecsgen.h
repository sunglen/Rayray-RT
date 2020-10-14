/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
#ifndef tNBOTDR_TECSGEN_H
#define tNBOTDR_TECSGEN_H

/*
 * celltype          :  tNBOTDR
 * global name       :  tNBOTDR
 * idx_is_id(actual) :  no(no)
 * singleton         :  no
 * has_CB            :  true
 * has_INIB          :  false
 * rom               :  yes
 * CB initializer    :  yes
 */

/* グローバルヘッダ #_IGH_# */
#include "global_tecsgen.h"

/* シグニチャヘッダ #_ISH_# */
#include "sChannel_tecsgen.h"
#include "sTDR_tecsgen.h"
#include "sSysLog_tecsgen.h"

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* セル CB 型宣言 #_CCTPA_# */
typedef struct tag_tNBOTDR_CB {
    /* call port #_TCP_# */
    /* call port #_NEP_# */ 
    /* var #_VA_# */ 
    TMO            tmo;
}  tNBOTDR_CB;
extern tNBOTDR_CB  tNBOTDR_CB_tab[];

/* セルタイプのIDX型 #_CTIX_# */
typedef struct tag_tNBOTDR_CB *tNBOTDR_IDX;

/* 受け口関数プロトタイプ宣言 #_EPP_# */
/* sTDR */
Inline ER           tNBOTDR_eTDR_reset(tNBOTDR_IDX idx);
Inline ER           tNBOTDR_eTDR_sendSOP(tNBOTDR_IDX idx, bool_t b_client);
Inline ER           tNBOTDR_eTDR_receiveSOP(tNBOTDR_IDX idx, bool_t b_client);
Inline ER           tNBOTDR_eTDR_sendEOP(tNBOTDR_IDX idx, bool_t b_continue);
Inline ER           tNBOTDR_eTDR_receiveEOP(tNBOTDR_IDX idx, bool_t b_continue);
Inline ER           tNBOTDR_eTDR_putInt8(tNBOTDR_IDX idx, int8_t in);
Inline ER           tNBOTDR_eTDR_putInt16(tNBOTDR_IDX idx, int16_t in);
Inline ER           tNBOTDR_eTDR_putInt32(tNBOTDR_IDX idx, int32_t in);
Inline ER           tNBOTDR_eTDR_putInt64(tNBOTDR_IDX idx, int64_t in);
Inline ER           tNBOTDR_eTDR_putInt128(tNBOTDR_IDX idx, int128_t in);
Inline ER           tNBOTDR_eTDR_getInt8(tNBOTDR_IDX idx, int8_t* out);
Inline ER           tNBOTDR_eTDR_getInt16(tNBOTDR_IDX idx, int16_t* out);
Inline ER           tNBOTDR_eTDR_getInt32(tNBOTDR_IDX idx, int32_t* out);
Inline ER           tNBOTDR_eTDR_getInt64(tNBOTDR_IDX idx, int64_t* out);
Inline ER           tNBOTDR_eTDR_getInt128(tNBOTDR_IDX idx, int128_t* out);
Inline ER           tNBOTDR_eTDR_putUInt8(tNBOTDR_IDX idx, uint8_t in);
Inline ER           tNBOTDR_eTDR_putUInt16(tNBOTDR_IDX idx, uint16_t in);
Inline ER           tNBOTDR_eTDR_putUInt32(tNBOTDR_IDX idx, uint32_t in);
Inline ER           tNBOTDR_eTDR_putUInt64(tNBOTDR_IDX idx, uint64_t in);
Inline ER           tNBOTDR_eTDR_putUInt128(tNBOTDR_IDX idx, uint128_t in);
Inline ER           tNBOTDR_eTDR_getUInt8(tNBOTDR_IDX idx, uint8_t* out);
Inline ER           tNBOTDR_eTDR_getUInt16(tNBOTDR_IDX idx, uint16_t* out);
Inline ER           tNBOTDR_eTDR_getUInt32(tNBOTDR_IDX idx, uint32_t* out);
Inline ER           tNBOTDR_eTDR_getUInt64(tNBOTDR_IDX idx, uint64_t* out);
Inline ER           tNBOTDR_eTDR_getUInt128(tNBOTDR_IDX idx, uint128_t* out);
Inline ER           tNBOTDR_eTDR_putChar(tNBOTDR_IDX idx, char_t in);
Inline ER           tNBOTDR_eTDR_getChar(tNBOTDR_IDX idx, char_t* out);
Inline ER           tNBOTDR_eTDR_putBool(tNBOTDR_IDX idx, bool_t in);
Inline ER           tNBOTDR_eTDR_getBool(tNBOTDR_IDX idx, bool_t* out);
Inline ER           tNBOTDR_eTDR_putFloat32(tNBOTDR_IDX idx, float32_t in);
Inline ER           tNBOTDR_eTDR_putDouble64(tNBOTDR_IDX idx, double64_t in);
Inline ER           tNBOTDR_eTDR_getFloat32(tNBOTDR_IDX idx, float32_t* out);
Inline ER           tNBOTDR_eTDR_getDouble64(tNBOTDR_IDX idx, double64_t* out);
Inline ER           tNBOTDR_eTDR_putSChar(tNBOTDR_IDX idx, schar_t in);
Inline ER           tNBOTDR_eTDR_putShort(tNBOTDR_IDX idx, short_t in);
Inline ER           tNBOTDR_eTDR_putInt(tNBOTDR_IDX idx, int_t in);
Inline ER           tNBOTDR_eTDR_putLong(tNBOTDR_IDX idx, long_t in);
Inline ER           tNBOTDR_eTDR_getSChar(tNBOTDR_IDX idx, schar_t* out);
Inline ER           tNBOTDR_eTDR_getShort(tNBOTDR_IDX idx, short_t* out);
Inline ER           tNBOTDR_eTDR_getInt(tNBOTDR_IDX idx, int_t* out);
Inline ER           tNBOTDR_eTDR_getLong(tNBOTDR_IDX idx, long_t* out);
Inline ER           tNBOTDR_eTDR_putUChar(tNBOTDR_IDX idx, uchar_t in);
Inline ER           tNBOTDR_eTDR_putUShort(tNBOTDR_IDX idx, ushort_t in);
Inline ER           tNBOTDR_eTDR_putUInt(tNBOTDR_IDX idx, uint_t in);
Inline ER           tNBOTDR_eTDR_putULong(tNBOTDR_IDX idx, ulong_t in);
Inline ER           tNBOTDR_eTDR_getUChar(tNBOTDR_IDX idx, unsigned char* out);
Inline ER           tNBOTDR_eTDR_getUShort(tNBOTDR_IDX idx, ushort_t* out);
Inline ER           tNBOTDR_eTDR_getUInt(tNBOTDR_IDX idx, uint_t* out);
Inline ER           tNBOTDR_eTDR_getULong(tNBOTDR_IDX idx, ulong_t* out);
Inline ER           tNBOTDR_eTDR_putIntptr(tNBOTDR_IDX idx, const intptr_t ptr);
Inline ER           tNBOTDR_eTDR_getIntptr(tNBOTDR_IDX idx, intptr_t* ptr);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* 最適化のため参照するセルタイプの CB 型の定義を取込む #_ICT_# */
#ifndef  TOPPERS_CB_TYPE_ONLY
#define  tNBOTDR_CB_TYPE_ONLY
#define TOPPERS_CB_TYPE_ONLY
#endif  /* TOPPERS_CB_TYPE_ONLY */
#include "tSocketClient_tecsgen.h"
#include "tSysLog_tecsgen.h"
#ifdef  tNBOTDR_CB_TYPE_ONLY
#undef TOPPERS_CB_TYPE_ONLY
#endif /* tNBOTDR_CB_TYPE_ONLY */
#define tNBOTDR_ID_BASE             (1)  /* ID のベース  #_NIDB_# */
#define tNBOTDR_N_CELL              (1)  /* セルの個数  #_NCEL_# */

/* IDXの正当性チェックマクロ #_CVI_# */
#define tNBOTDR_VALID_IDX(IDX) (1)


/* セルCBを得るマクロ #_GCB_# */
#define tNBOTDR_GET_CELLCB(idx) (idx)



/* var アクセスマクロ #_VAM_# */
#define tNBOTDR_VAR_tmo(p_that)	((p_that)->tmo)

#define tNBOTDR_GET_tmo(p_that)	((p_that)->tmo)
#define tNBOTDR_SET_tmo(p_that,val)	((p_that)->tmo=(val))

 /* 呼び口関数マクロ #_CPM_# */
#define tNBOTDR_cChannel_send( p_that, buf, size, tmo ) \
	  tSocketClient_eC0_send( \
	   &tSocketClient_CB_tab[0], (buf), (size), (tmo) )
#define tNBOTDR_cChannel_flush( p_that, tmo ) \
	  tSocketClient_eC0_flush( \
	   &tSocketClient_CB_tab[0], (tmo) )
#define tNBOTDR_cChannel_receive( p_that, buf, size, tmo ) \
	  tSocketClient_eC0_receive( \
	   &tSocketClient_CB_tab[0], (buf), (size), (tmo) )
#define tNBOTDR_cChannel_end_receive( p_that ) \
	  tSocketClient_eC0_end_receive( \
	   &tSocketClient_CB_tab[0] )
#define tNBOTDR_cChannel_reset( p_that ) \
	  tSocketClient_eC0_reset( \
	   &tSocketClient_CB_tab[0] )
#define tNBOTDR__require_call_port_tSysLog_eSysLog_write( p_that, prio, p_syslog ) \
	  tSysLog_eSysLog_write( \
	    (prio), (p_syslog) )
#define tNBOTDR__require_call_port_tSysLog_eSysLog_read( p_that, p_syslog ) \
	  tSysLog_eSysLog_read( \
	    (p_syslog) )
#define tNBOTDR__require_call_port_tSysLog_eSysLog_mask( p_that, logmask, lowmask ) \
	  tSysLog_eSysLog_mask( \
	    (logmask), (lowmask) )
#define tNBOTDR__require_call_port_tSysLog_eSysLog_refer( p_that, pk_rlog ) \
	  tSysLog_eSysLog_refer( \
	    (pk_rlog) )

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* 受け口スケルトン関数プロトタイプ宣言（VMT不要最適化により参照するもの） #_EPSP_# */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* TOPPERS_MACRO_ONLY */

/* IDXの正当性チェックマクロ（短縮形） #_CVIA_# */
#define VALID_IDX(IDX)  tNBOTDR_VALID_IDX(IDX)


/* セルCBを得るマクロ(短縮形) #_GCBA_# */
#define GET_CELLCB(idx)  tNBOTDR_GET_CELLCB(idx)

/* CELLCB 型(短縮形) #_CCT_# */
#define CELLCB	tNBOTDR_CB

/* セルタイプのIDX型(短縮形) #_CTIXA_# */
#define CELLIDX	tNBOTDR_IDX



/* var アクセスマクロ(短縮形) #_VAMA_# */
#define VAR_tmo              tNBOTDR_VAR_tmo( p_cellcb )

/* 呼び口関数マクロ（短縮形）#_CPMA_# */
#define cChannel_send( buf, size, tmo ) \
          ((void)p_cellcb, tNBOTDR_cChannel_send( p_cellcb, buf, size, tmo ))
#define cChannel_flush( tmo ) \
          ((void)p_cellcb, tNBOTDR_cChannel_flush( p_cellcb, tmo ))
#define cChannel_receive( buf, size, tmo ) \
          ((void)p_cellcb, tNBOTDR_cChannel_receive( p_cellcb, buf, size, tmo ))
#define cChannel_end_receive( ) \
          ((void)p_cellcb, tNBOTDR_cChannel_end_receive( p_cellcb ))
#define cChannel_reset( ) \
          ((void)p_cellcb, tNBOTDR_cChannel_reset( p_cellcb ))
#define write( prio, p_syslog ) \
          ((void)p_cellcb, tNBOTDR__require_call_port_tSysLog_eSysLog_write( p_cellcb, prio, p_syslog ))
#define read( p_syslog ) \
          ((void)p_cellcb, tNBOTDR__require_call_port_tSysLog_eSysLog_read( p_cellcb, p_syslog ))
#define mask( logmask, lowmask ) \
          ((void)p_cellcb, tNBOTDR__require_call_port_tSysLog_eSysLog_mask( p_cellcb, logmask, lowmask ))
#define refer( pk_rlog ) \
          ((void)p_cellcb, tNBOTDR__require_call_port_tSysLog_eSysLog_refer( p_cellcb, pk_rlog ))




/* 受け口関数マクロ（短縮形） #_EPM_# */
#define eTDR_reset       tNBOTDR_eTDR_reset
#define eTDR_sendSOP     tNBOTDR_eTDR_sendSOP
#define eTDR_receiveSOP  tNBOTDR_eTDR_receiveSOP
#define eTDR_sendEOP     tNBOTDR_eTDR_sendEOP
#define eTDR_receiveEOP  tNBOTDR_eTDR_receiveEOP
#define eTDR_putInt8     tNBOTDR_eTDR_putInt8
#define eTDR_putInt16    tNBOTDR_eTDR_putInt16
#define eTDR_putInt32    tNBOTDR_eTDR_putInt32
#define eTDR_putInt64    tNBOTDR_eTDR_putInt64
#define eTDR_putInt128   tNBOTDR_eTDR_putInt128
#define eTDR_getInt8     tNBOTDR_eTDR_getInt8
#define eTDR_getInt16    tNBOTDR_eTDR_getInt16
#define eTDR_getInt32    tNBOTDR_eTDR_getInt32
#define eTDR_getInt64    tNBOTDR_eTDR_getInt64
#define eTDR_getInt128   tNBOTDR_eTDR_getInt128
#define eTDR_putUInt8    tNBOTDR_eTDR_putUInt8
#define eTDR_putUInt16   tNBOTDR_eTDR_putUInt16
#define eTDR_putUInt32   tNBOTDR_eTDR_putUInt32
#define eTDR_putUInt64   tNBOTDR_eTDR_putUInt64
#define eTDR_putUInt128  tNBOTDR_eTDR_putUInt128
#define eTDR_getUInt8    tNBOTDR_eTDR_getUInt8
#define eTDR_getUInt16   tNBOTDR_eTDR_getUInt16
#define eTDR_getUInt32   tNBOTDR_eTDR_getUInt32
#define eTDR_getUInt64   tNBOTDR_eTDR_getUInt64
#define eTDR_getUInt128  tNBOTDR_eTDR_getUInt128
#define eTDR_putChar     tNBOTDR_eTDR_putChar
#define eTDR_getChar     tNBOTDR_eTDR_getChar
#define eTDR_putBool     tNBOTDR_eTDR_putBool
#define eTDR_getBool     tNBOTDR_eTDR_getBool
#define eTDR_putFloat32  tNBOTDR_eTDR_putFloat32
#define eTDR_putDouble64 tNBOTDR_eTDR_putDouble64
#define eTDR_getFloat32  tNBOTDR_eTDR_getFloat32
#define eTDR_getDouble64 tNBOTDR_eTDR_getDouble64
#define eTDR_putSChar    tNBOTDR_eTDR_putSChar
#define eTDR_putShort    tNBOTDR_eTDR_putShort
#define eTDR_putInt      tNBOTDR_eTDR_putInt
#define eTDR_putLong     tNBOTDR_eTDR_putLong
#define eTDR_getSChar    tNBOTDR_eTDR_getSChar
#define eTDR_getShort    tNBOTDR_eTDR_getShort
#define eTDR_getInt      tNBOTDR_eTDR_getInt
#define eTDR_getLong     tNBOTDR_eTDR_getLong
#define eTDR_putUChar    tNBOTDR_eTDR_putUChar
#define eTDR_putUShort   tNBOTDR_eTDR_putUShort
#define eTDR_putUInt     tNBOTDR_eTDR_putUInt
#define eTDR_putULong    tNBOTDR_eTDR_putULong
#define eTDR_getUChar    tNBOTDR_eTDR_getUChar
#define eTDR_getUShort   tNBOTDR_eTDR_getUShort
#define eTDR_getUInt     tNBOTDR_eTDR_getUInt
#define eTDR_getULong    tNBOTDR_eTDR_getULong
#define eTDR_putIntptr   tNBOTDR_eTDR_putIntptr
#define eTDR_getIntptr   tNBOTDR_eTDR_getIntptr

/* イテレータコード (FOREACH_CELL)の生成 #_FEC_# */
#define FOREACH_CELL(i,p_cb)   \
    for( (i) = 0; (i) < tNBOTDR_N_CELL; (i)++ ){ \
       (p_cb) = &tNBOTDR_CB_tab[i];

#define END_FOREACH_CELL   }

/* CB 初期化マクロ #_CIM_# */
#define INITIALIZE_CB(p_that)\
	(p_that)->tmo = TMO_FEVR;
#define SET_CB_INIB_POINTER(i,p_that)\
	/* empty */
#ifndef TOPPERS_MACRO_ONLY

/* inline ヘッダの include #_INL_# */
#include "tNBOTDR_inline.h"

#endif /* TOPPERS_MACRO_ONLY */

#ifdef TOPPERS_CB_TYPE_ONLY

/* inline のための undef #_UDF_# */
#undef VALID_IDX
#undef GET_CELLCB
#undef CELLCB
#undef CELLIDX
#undef tNBOTDR_IDX
#undef FOREACH_CELL
#undef END_FOREACH_CELL
#undef INITIALIZE_CB
#undef SET_CB_INIB_POINTER
#undef VAR_tmo
#undef VAR_tmo
#undef tNBOTDR_VAR_tmo
#undef tNBOTDR_GET_tmo
#undef tNBOTDR_SET_tmo
#undef tNBOTDR_cChannel_send
#undef cChannel_send
#undef tNBOTDR_cChannel_flush
#undef cChannel_flush
#undef tNBOTDR_cChannel_receive
#undef cChannel_receive
#undef tNBOTDR_cChannel_end_receive
#undef cChannel_end_receive
#undef tNBOTDR_cChannel_reset
#undef cChannel_reset
#undef tNBOTDR__require_call_port_tSysLog_eSysLog_write
#undef write
#undef tNBOTDR__require_call_port_tSysLog_eSysLog_read
#undef read
#undef tNBOTDR__require_call_port_tSysLog_eSysLog_mask
#undef mask
#undef tNBOTDR__require_call_port_tSysLog_eSysLog_refer
#undef refer
#undef eTDR_reset
#undef eTDR_sendSOP
#undef eTDR_receiveSOP
#undef eTDR_sendEOP
#undef eTDR_receiveEOP
#undef eTDR_putInt8
#undef eTDR_putInt16
#undef eTDR_putInt32
#undef eTDR_putInt64
#undef eTDR_putInt128
#undef eTDR_getInt8
#undef eTDR_getInt16
#undef eTDR_getInt32
#undef eTDR_getInt64
#undef eTDR_getInt128
#undef eTDR_putUInt8
#undef eTDR_putUInt16
#undef eTDR_putUInt32
#undef eTDR_putUInt64
#undef eTDR_putUInt128
#undef eTDR_getUInt8
#undef eTDR_getUInt16
#undef eTDR_getUInt32
#undef eTDR_getUInt64
#undef eTDR_getUInt128
#undef eTDR_putChar
#undef eTDR_getChar
#undef eTDR_putBool
#undef eTDR_getBool
#undef eTDR_putFloat32
#undef eTDR_putDouble64
#undef eTDR_getFloat32
#undef eTDR_getDouble64
#undef eTDR_putSChar
#undef eTDR_putShort
#undef eTDR_putInt
#undef eTDR_putLong
#undef eTDR_getSChar
#undef eTDR_getShort
#undef eTDR_getInt
#undef eTDR_getLong
#undef eTDR_putUChar
#undef eTDR_putUShort
#undef eTDR_putUInt
#undef eTDR_putULong
#undef eTDR_getUChar
#undef eTDR_getUShort
#undef eTDR_getUInt
#undef eTDR_getULong
#undef eTDR_putIntptr
#undef eTDR_getIntptr
#endif /* TOPPERS_CB_TYPE_ONLY */

#endif /* tNBOTDR_TECSGENH */
