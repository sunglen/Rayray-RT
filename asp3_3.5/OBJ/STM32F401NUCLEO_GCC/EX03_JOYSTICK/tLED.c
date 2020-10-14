/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tLED_template.c => src/tLED.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

/* プロトタイプ宣言や変数の定義をここに書きます */
#include "tLED_tecsgen.h"

#include "stm32f4xx_nucleo.h"

#define LED_PIN 5
#define LEDON() (GPIOA->BSRR |= GPIO_BSRR_BS_5)
#define LEDOFF() (GPIOA->BSRR |= GPIO_BSRR_BR_5)


#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eInitialize
 * entry port: eInitialize
 * signature:  sInitializeRoutineBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInitialize_main
 * name:         eInitialize_main
 * global_name:  tLED_eInitialize_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eInitialize_main()
{
	BSP_LED_Init(LED2);
}

/* #[<ENTRY_PORT>]# eLED
 * entry port: eLED
 * signature:  sLED
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eLED_output
 * name:         eLED_output
 * global_name:  tLED_eLED_output
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eLED_output(uint16_t ledData, uint8_t set)
{
	  if (set != 0)
	  {
		  BSP_LED_On(LED2);
	  }
	  else
	  {
		  BSP_LED_Off(LED2);
	  }
}

/* #[<ENTRY_FUNC>]# eLED_sense
 * name:         eLED_sense
 * global_name:  tLED_eLED_sense
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint16_t
eLED_sense()
{
	if((uint16_t)(GPIOA->IDR & (1<<LED_PIN)) != 0){
		return 1<<LED_PIN;
	}else{
		return 0;
	}
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
