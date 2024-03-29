/*
 * This file was automatically generated by tecsgen.
 * Move and rename like below before editing,
 *   gen/tRotaryEncoderBody_templ.c => src/tRotaryEncoderBody.c
 * to avoid to be overwritten by tecsgen.
 */
/* #[<PREAMBLE>]#
 * Don't edit the comments between #[<...>]# and #[</...>]#
 * These comment are used by tecsmerege when merging.
 *
 * attr access macro #_CAAM_#
 * interruptNumber  INTNO            ATTR_interruptNumber
 * interruptCount   int32_t          VAR_interruptCount
 * initializedFlag  bool_t           VAR_initializedFlag
 *
 * call port function #_TCPF_#
 * call port: ciMotorInterrupt signature: siMotorInterrupt context:task
 *   void           ciMotorInterrupt_quadDecode( subscript, uint32_t pins );
 *   void           ciMotorInterrupt_stopMotor( subscript );
 *       subscript:  0...(NCP_ciMotorInterrupt-1)
 *
 * #[</PREAMBLE>]# */

/* Put prototype declaration and/or variale definition here #_PAC_# */
#include "tRotaryEncoderBody_tecsgen.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* entry port function #_TEPF_# */
/* #[<ENTRY_PORT>]# eInitialize
 * entry port: eInitialize
 * signature:  sRoutineBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInitialize_main
 * name:         eInitialize_main
 * global_name:  tRotaryEncoderBody_eInitialize_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eInitialize_main()
{
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_EXTI);
	syslog(LOG_NOTICE, "Encoder Init");
}

/* #[<ENTRY_PORT>]# eTerminate
 * entry port: eTerminate
 * signature:  sRoutineBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTerminate_main
 * name:         eTerminate_main
 * global_name:  tRotaryEncoderBody_eTerminate_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTerminate_main()
{
}

/* #[<ENTRY_PORT>]# eiCyclicBody
 * entry port: eiCyclicBody
 * signature:  siHandlerBody
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiCyclicBody_main
 * name:         eiCyclicBody_main
 * global_name:  tRotaryEncoderBody_eiCyclicBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eiCyclicBody_main()
{
	//syslog(LOG_NOTICE, "Rotary Encoder");
}

/* #[<ENTRY_PORT>]# eiISR
 * entry port: eiISR
 * signature:  siHandlerBody
 * context:    non-task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eiISR_main
 * name:         eiISR_main
 * global_name:  tRotaryEncoderBody_eiISR_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eiISR_main()
{
	//PUSHスイッチ割込みクリア
	__HAL_GPIO_EXTI_CLEAR_IT(KEY_BUTTON_PIN);

	ciMotorInterrupt_quadDecode(0, 0);
}

/* #[<POSTAMBLE>]#
 *   Put non-entry functions below.
 * #[</POSTAMBLE>]#*/
