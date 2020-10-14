/*
 * このファイルは tecsgen によりテンプレートとして自動生成されました
 * このファイルを編集して使用することが意図されていますが
 * tecsgen の再実行により上書きされてしまうため、通常
 *   gen/tJoystick_template.c => src/tJoystick.c
 * のように名前, フォルダを変更してから修正します
 */
/* #[<PREAMBLE>]#
 * #[<...>]# から #[</...>]# で囲まれたコメントは編集しないでください
 * tecsmerge によるマージに使用されます
 *
 * #[</PREAMBLE>]# */

#include "tJoystick_tecsgen.h"

#include "stm32f4xx_nucleo.h"

#ifndef E_OK
#define	E_OK    0     /* success */
#define	E_ID    (-18) /* illegal ID */
#endif

/* 受け口関数 #_TEPF_# */
/* #[<ENTRY_PORT>]# eInitialize
 * entry port: eInitialize
 * signature:  sInitializeRoutineBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eInitialize_main
 * name:         eInitialize_main
 * global_name:  tJoystick_eInitialize_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eInitialize_main()
{
	BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);
}

/* #[<ENTRY_PORT>]# eJoystick
 * entry port: eJoystick
 * signature:  sJoystick
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eJoystick_getState
 * name:         eJoystick_getState
 * global_name:  tJoystick_eJoystick_getState
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
uint16_t
eJoystick_getState()
{
    uint16_t direction = 0;

    direction=BSP_PB_GetState(BUTTON_USER);

    /*
    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3))
    {
        direction = JOYSTICK_UP;
    }

    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4))
    {
        direction = JOYSTICK_DOWN;
    }

    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_5))
    {
        direction = JOYSTICK_RIGHT;
    }

    if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_6))
    {
        direction = JOYSTICK_LEFT;
    }
    */
    return direction;
}

/* #[<POSTAMBLE>]#
 *   これより下に非受け口関数を書きます
 * #[</POSTAMBLE>]#*/
