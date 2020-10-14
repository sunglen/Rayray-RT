/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tMain01_template.c => src/tMain01.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * 呼び口関数 #_TCPF_#
 * require port : signature: sKernel context: task
 *   ER             sleep( );
 *   ER             sleepTimeout( TMO timeout );
 *   ER             delay( RELTIM delayTime );
 *   ER             exitTask( );
 *   ER             getTaskId( ID* p_taskId );
 *   ER             rotateReadyQueue( PRI taskPriority );
 *   ER             getTime( SYSTIM* p_systemTime );
 *   ER             getMicroTime( SYSUTM* p_systemMicroTime );
 *   ER             lockCpu( );
 *   ER             unlockCpu( );
 *   ER             disableDispatch( );
 *   ER             enableDispatch( );
 *   ER             disableTaskException( );
 *   ER             enableTaskException( );
 *   ER             changeInterruptPriorityMask( PRI interruptPriority );
 *   ER             getInterruptPriorityMask( PRI* p_interruptPriority );
 *   ER             exitKernel( );
 *   bool_t         senseContext( );
 *   bool_t         senseLock( );
 *   bool_t         senseDispatch( );
 *   bool_t         senseDispatchPendingState( );
 *   bool_t         senseKernel( );
 * call port : cLED  signature: sLED context: task
 *   void           cLED_output( uint16_t ledData, uint8_t set );
 *   uint16_t       cLED_sense( );
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます */
#include "tMain01_tecsgen.h"

#include "stm32f4xx_nucleo.h"

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

void
busy_wait(void)
{
	uint32_t temp;
	//SysTick->CTRL |= (1<<2);
	SysTick->CTRL &= ~(1<<2);
	SysTick->LOAD=3000000L;
	//24-bit
	SysTick->VAL=0;
	SysTick->CTRL=0x01;

	do{
		temp=SysTick->CTRL;
	}while((temp&0x01) && ((temp&(1<<16))==0));

	SysTick->CTRL=0x00;
	SysTick->VAL=0;
}

#define LED1_INTERVAL_MS 1000

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tMain01_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main()
{
    uint16_t ledData;

    cLED_output(USER_LED, LED_ON);

    while(1)
    {
        ledData = cLED_sense();

        switch(ledData)
        {
        case 0:
            cLED_output(USER_LED, LED_ON);
            break;
        default:
            cLED_output(USER_LED, LED_OFF);
            break;
        }
        busy_wait();
        //dly_tsk(LED1_INTERVAL_MS);
    }
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
