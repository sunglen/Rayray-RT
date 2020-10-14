/*
 * このファイルは tecsgen により自動生成されました
 * このファイルを編集して使用することは、意図されていません
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * call port: cTDR signature: sTDR context:task
 *   ER             cTDR_reset( );
 *   ER             cTDR_sendSOP( bool_t b_client );
 *   ER             cTDR_receiveSOP( bool_t b_client );
 *   ER             cTDR_sendEOP( bool_t b_continue );
 *   ER             cTDR_receiveEOP( bool_t b_continue );
 *   ER             cTDR_putInt8( int8_t in );
 *   ER             cTDR_putInt16( int16_t in );
 *   ER             cTDR_putInt32( int32_t in );
 *   ER             cTDR_putInt64( int64_t in );
 *   ER             cTDR_putInt128( int128_t in );
 *   ER             cTDR_getInt8( int8_t* out );
 *   ER             cTDR_getInt16( int16_t* out );
 *   ER             cTDR_getInt32( int32_t* out );
 *   ER             cTDR_getInt64( int64_t* out );
 *   ER             cTDR_getInt128( int128_t* out );
 *   ER             cTDR_putUInt8( uint8_t in );
 *   ER             cTDR_putUInt16( uint16_t in );
 *   ER             cTDR_putUInt32( uint32_t in );
 *   ER             cTDR_putUInt64( uint64_t in );
 *   ER             cTDR_putUInt128( uint128_t in );
 *   ER             cTDR_getUInt8( uint8_t* out );
 *   ER             cTDR_getUInt16( uint16_t* out );
 *   ER             cTDR_getUInt32( uint32_t* out );
 *   ER             cTDR_getUInt64( uint64_t* out );
 *   ER             cTDR_getUInt128( uint128_t* out );
 *   ER             cTDR_putChar( char_t in );
 *   ER             cTDR_getChar( char_t* out );
 *   ER             cTDR_putBool( bool_t in );
 *   ER             cTDR_getBool( bool_t* out );
 *   ER             cTDR_putFloat32( float32_t in );
 *   ER             cTDR_putDouble64( double64_t in );
 *   ER             cTDR_getFloat32( float32_t* out );
 *   ER             cTDR_getDouble64( double64_t* out );
 *   ER             cTDR_putSChar( schar_t in );
 *   ER             cTDR_putShort( short_t in );
 *   ER             cTDR_putInt( int_t in );
 *   ER             cTDR_putLong( long_t in );
 *   ER             cTDR_getSChar( schar_t* out );
 *   ER             cTDR_getShort( short_t* out );
 *   ER             cTDR_getInt( int_t* out );
 *   ER             cTDR_getLong( long_t* out );
 *   ER             cTDR_putUChar( uchar_t in );
 *   ER             cTDR_putUShort( ushort_t in );
 *   ER             cTDR_putUInt( uint_t in );
 *   ER             cTDR_putULong( ulong_t in );
 *   ER             cTDR_getUChar( unsigned char* out );
 *   ER             cTDR_getUShort( ushort_t* out );
 *   ER             cTDR_getUInt( uint_t* out );
 *   ER             cTDR_getULong( ulong_t* out );
 *   ER             cTDR_putIntptr( const intptr_t ptr );
 *   ER             cTDR_getIntptr( intptr_t* ptr );
 * call port: cLockChannel signature: sSemaphore context:task optional:true
 *   bool_t     is_cLockChannel_joined()                     check if joined
 *   ER             cLockChannel_signal( );
 *   ER             cLockChannel_wait( );
 *   ER             cLockChannel_waitPolling( );
 *   ER             cLockChannel_waitTimeout( TMO timeout );
 *   ER             cLockChannel_initialize( );
 *   ER             cLockChannel_refer( T_RSEM* pk_semaphore_status );
 * call port: cErrorHandler signature: sRPCErrorHandler context:task optional:true
 *   bool_t     is_cErrorHandler_joined()                     check if joined
 *   ER             cErrorHandler_errorOccured( int16_t func_id, ER er, int16_t state );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます #_PAC_# */
#include "tOpaqueMarshaler_sSample_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eClientEntry
 * entry port: eClientEntry
 * signature:  sSample
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eClientEntry_sayHello
 * name:         eClientEntry_sayHello
 * global_name:  tOpaqueMarshaler_sSample_eClientEntry_sayHello
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eClientEntry_sayHello(CELLIDX idx, int32_t times)
{
	ER		retval_;
	ER		ercd_;
	int16_t	state_;
	int16_t	func_id_ = FUNCID_SSAMPLE_SAYHELLO;	/* (id of 'sayHello') = 1*/
	tOpaqueMarshaler_sSample_CB *p_cellcb;

	if( VALID_IDX( idx ) ){
		p_cellcb = GET_CELLCB(idx);
	}else{
		return ERCD( E_RPC, E_ID );
	}

	/* Channel Lock */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_GET_SEM );
	if( is_cLockChannel_joined() )
		cLockChannel_wait();
	/* SOPの送出 */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_SEND_SOP );
	if( ( ercd_ = cTDR_sendSOP( true ) ) != E_OK )
		goto error_reset;
	/* 関数 id の送出 */
	if( ( ercd_ = cTDR_putInt16( func_id_ ) ) != E_OK )
		goto error_reset;
	/* 入力引数送出 */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_SEND_BODY );
	if( ( ercd_ = cTDR_putInt32( times ) ) != E_OK )	/* GenParamCopy 3 */
		goto error_reset;
	/* EOPの送出（パケットの掃きだし） */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_SEND_EOP );
	if( (ercd_=cTDR_sendEOP(true)) != E_OK )
		goto error_reset;

	/* パケットの始まりをチェック */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_RECV_SOP );
	if( (ercd_=cTDR_receiveSOP( true )) != E_OK )
		goto error_reset;
	/* 戻り値の受け取り */
	if( ( ercd_ = cTDR_getInt( &(retval_) ) ) != E_OK )	/* GenParamCopy 2 */
		goto error_reset;

	/* パケットの終わりをチェック */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_RECV_EOP );
	if( (ercd_=cTDR_receiveEOP(false)) != E_OK )
		goto error_reset;
	/* Channel Unlock */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_RELEASE_SEM );
	if( is_cLockChannel_joined() )
		cLockChannel_signal();
	return retval_;

error_reset:
	if( MERCD( ercd_ ) != E_RESET )
		(void)cTDR_reset();
	/* Channel Unlock */
	if( is_cLockChannel_joined() )
		cLockChannel_signal();

	if( ercd_ != E_OK && is_cErrorHandler_joined() )
		cErrorHandler_errorOccured( func_id_, ercd_, state_ );
	return ERCD( E_RPC, MERCD( ercd_ ) );
}

/* #[<ENTRY_FUNC>]# eClientEntry_howAreYou
 * name:         eClientEntry_howAreYou
 * global_name:  tOpaqueMarshaler_sSample_eClientEntry_howAreYou
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
ER
eClientEntry_howAreYou(CELLIDX idx, char_t* buf, int32_t len)
{
	ER		retval_;
	ER		ercd_;
	int16_t	state_;
	int16_t	func_id_ = FUNCID_SSAMPLE_HOWAREYOU;	/* (id of 'howAreYou') = 2*/
	tOpaqueMarshaler_sSample_CB *p_cellcb;

	if( VALID_IDX( idx ) ){
		p_cellcb = GET_CELLCB(idx);
	}else{
		return ERCD( E_RPC, E_ID );
	}

	/* Channel Lock */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_GET_SEM );
	if( is_cLockChannel_joined() )
		cLockChannel_wait();
	/* SOPの送出 */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_SEND_SOP );
	if( ( ercd_ = cTDR_sendSOP( true ) ) != E_OK )
		goto error_reset;
	/* 関数 id の送出 */
	if( ( ercd_ = cTDR_putInt16( func_id_ ) ) != E_OK )
		goto error_reset;
	/* 入力引数送出 */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_SEND_BODY );
	if( ( ercd_ = cTDR_putInt32( len ) ) != E_OK )	/* GenParamCopy 3 */
		goto error_reset;
	/* EOPの送出（パケットの掃きだし） */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_SEND_EOP );
	if( (ercd_=cTDR_sendEOP(true)) != E_OK )
		goto error_reset;

	/* パケットの始まりをチェック */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_RECV_SOP );
	if( (ercd_=cTDR_receiveSOP( true )) != E_OK )
		goto error_reset;
	/* 戻り値の受け取り */
	if( ( ercd_ = cTDR_getInt( &(retval_) ) ) != E_OK )	/* GenParamCopy 2 */
		goto error_reset;
	if( MERCD( retval_ ) != E_RPC ){
		/* 出力値の受け取り */
		SET_RPC_STATE( state_, RPCSTATE_CLIENT_RECV_BODY );
		{	/* GenParamCopy 4 */
			int32_t  i__2, length__2;
			if( ( ercd_ = cTDR_getInt32( &(length__2) ) ) != E_OK )	/* GenParamCopy 2 */
				goto error_reset;
			for( i__2 = 0; i__2 < length__2; i__2++ ){	/* GenParamCopy 9 */
				if( ( ercd_ = cTDR_getChar( &(buf[i__2]) ) ) != E_OK )	/* GenParamCopy 2 */
					goto error_reset;
			}
		}
	}

	/* パケットの終わりをチェック */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_RECV_EOP );
	if( (ercd_=cTDR_receiveEOP(false)) != E_OK )
		goto error_reset;
	/* Channel Unlock */
	SET_RPC_STATE( state_, RPCSTATE_CLIENT_RELEASE_SEM );
	if( is_cLockChannel_joined() )
		cLockChannel_signal();
	return retval_;

error_reset:
	if( MERCD( ercd_ ) != E_RESET )
		(void)cTDR_reset();
	/* Channel Unlock */
	if( is_cLockChannel_joined() )
		cLockChannel_signal();

	if( ercd_ != E_OK && is_cErrorHandler_joined() )
		cErrorHandler_errorOccured( func_id_, ercd_, state_ );
	return ERCD( E_RPC, MERCD( ercd_ ) );
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
