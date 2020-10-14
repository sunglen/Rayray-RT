#ifndef tGasPressureSensorBody__INLINE_H
#define tGasPressureSensorBody__INLINE_H

/*
 * This file was automatically generated by tecsgen.
 * Move and rename like below before editing,
 *   gen/tGasPressureSensorBody_inline_template.h => src/tGasPressureSensorBody_inline.h
 * to avoid to be overwritten by tecsgen.
 */
/* #[<PREAMBLE>]#
 * Don't edit the comments between #[<...>]# and #[</...>]#
 * These comment are used by tecsmerege when merging.
 *
 * call port function #_TCPF_#
 * call port: cSensorPort signature: sSensorPort context:task
 *   void           cSensorPort_clearSCL( );
 *   void           cSensorPort_clearSDA( );
 *   void           cSensorPort_setSCL( );
 *   void           cSensorPort_setSDA( );
 *   void           cSensorPort_inputPower( uint8_t powerType );
 *   uint16_t       cSensorPort_getValue( );
 * call port: cI2C signature: sI2C context:task
 *   void           cI2C_enable( );
 *   void           cI2C_disable( );
 *   bool_t         cI2C_isBusy( );
 *   bool_t         cI2C_startTransaction( uint32_t address, int32_t internalAddress, int32_t internalAddressBytes, uint8_t* data, uint32_t dataSize, int32_t direction );
 *   void           cI2C_initialize( );
 *   void           cI2C_interruptBody( uint32_t inputs );
 *
 * #[</PREAMBLE>]# */

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eSensor
 * entry port: eSensor
 * signature:  sSensorArray
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSensor_getValue
 * name:         eSensor_getValue
 * global_name:  tGasPressureSensorBody_eSensor_getValue
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eSensor_getValue(CELLIDX idx, int16_t* buf, int8_t bufferSize)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_PORT>]# eSensorCaribrate
 * entry port: eSensorCaribrate
 * signature:  sSensorCaribrate
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eSensorCaribrate_calibrate
 * name:         eSensorCaribrate_calibrate
 * global_name:  tGasPressureSensorBody_eSensorCaribrate_calibrate
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline bool_t
eSensorCaribrate_calibrate(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_PORT>]# eiSensorDriver
 * entry port: eiSensorDriver
 * signature:  siSensorDriver
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiSensorDriver_initialize
 * name:         eiSensorDriver_initialize
 * global_name:  tGasPressureSensorBody_eiSensorDriver_initialize
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eiSensorDriver_initialize(CELLIDX idx)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<ENTRY_FUNC>]# eiSensorDriver_i2cInterruptBody
 * name:         eiSensorDriver_i2cInterruptBody
 * global_name:  tGasPressureSensorBody_eiSensorDriver_i2cInterruptBody
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
Inline void
eiSensorDriver_i2cInterruptBody(CELLIDX idx, uint32_t inputs)
{
	CELLCB	*p_cellcb;
	if (VALID_IDX(idx)) {
		p_cellcb = GET_CELLCB(idx);
	}
	else {
		/* Write error processing code here */
	} /* end if VALID_IDX(idx) */

	/* Put statements here #_TEFB_# */

}

/* #[<POSTAMBLE>]#
 *   Put non-entry functions below.
 * #[</POSTAMBLE>]#*/

#endif /* tGasPressureSensorBody_INLINEH */
