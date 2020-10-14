/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2020 by TOPPERS PROJECT Educational Working Group.
 * 
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: wifiuart.h,v 1.0 2020/04/13 21:31:56 roi Exp $
 */
/*
 *  STM32F7XX用 WIFI-UARTドライバインクルードファイル
 */

#ifndef _WIFIUART_H_
#define _WIFIUART_H_

//#include "pinmode.h"
//#include "target_serial.h"
#include "stm32f4xx_hal.h"

#ifdef __cplusplus
 extern "C" {
#endif

/*
 *  WIFIUARTポート定義
 */
#define WIFIUART1_PORTID        1
#define NUM_WIFIUARTPORT        1

#define WIFIUART1_NAME  USART2
#define WIFIUART1_BASE USART2_BASE
//#define WIFIUART1_NAME  UART4
//#define WIFIUART1_BASE UART4_BASE

#define WIFIUART1_BPS (115200)

#define INTNO_WIFIUART1  (USART2_IRQn + 16)	/* 割込み番号 */
//#define INTNO_WIFIUART1  (UART4_IRQn + 16)	/* 割込み番号 */
#define INTPRI_WIFIUART1 -2	/* 割込み優先度 */
#define INTATR_WIFIUART1 TA_NULL	/* 割込み属性 */


#ifndef TOPPERS_MACRO_ONLY

/*
 *  WIFIUART 設定初期設定構造体
 */
typedef struct
{
	uint32_t              bps;
	int32_t               rtspin;			/* UART RTS pin# */
	int32_t               ctspin;			/* UART CTS pin# */
	uint32_t              pull;
	uint32_t              otype;
}WIFIUART_Init_t;

/*
 *  QUEUEバッファ定義
 */
typedef struct _queue_s {
	uint16_t    size;
	uint16_t    top;
	uint16_t    tail;
	uint16_t    limit;
	uint8_t     *buffer;
} queue_t;

/*
 *  拡張UARTハンドラ定義
 */
typedef struct wifiuart_struct WIFIUART_Handle_t;
struct wifiuart_struct {
	uintptr_t   base;
	const WIFIUART_Init_t Init;
	uint32_t    no;
	queue_t     *rque;
	queue_t     *tque;
	void        (*rxcallback)(WIFIUART_Handle_t * huart);	/* 受信終了コールバック関数 */
};

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  拡張UART関数のプロトタイプ宣言
 */
#ifndef TOPPERS_MACRO_ONLY

extern WIFIUART_Handle_t *wifiuart_init(ID portid, WIFIUART_Init_t *ini);
extern ER   wifiuart_deinit(WIFIUART_Handle_t *uart);
extern int  wifiuart_recev(WIFIUART_Handle_t *uart, unsigned char *buf, int len);
extern int  wifiuart_send(WIFIUART_Handle_t *uart, unsigned char *buf, int len);
extern int  wifiuart_recsize(WIFIUART_Handle_t *uart);
extern bool_t wifiuart_cts_sens(WIFIUART_Handle_t *huart);
extern void wifiuart_isr(intptr_t exinf);

/*
 * STM32F407(YS-F4Pro) <--> ESP32(Devkitc_v4)
 * PD5(TXD, CN4) --> IO5(RXD)
 * PD6(RXD, CN4) <-- IO4(TXD)
 * PH2(RTS, CN3) --> IO18(CTS)
 * PH7(CTS, CN3) <-X- IO19(RTS) NOTE: should be DISCONNECTED to work,
 * otherwise, when STM32 send ssid & password to ESP32, ESP32 will NOT act.
 * PI8(RST, CN3) <--> EN
 * PD15(BPS, CN3) <--> IO21
 */

/*
#define WIFI_USARTx_RCC_CLK_ENABLE()                 __HAL_RCC_USART6_CLK_ENABLE()
#define WIFI_USARTx_RCC_CLK_DISABLE()                __HAL_RCC_USART6_CLK_DISABLE()

#define WIFI_USARTx_GPIO_ClK_ENABLE()               __HAL_RCC_GPIOC_CLK_ENABLE()
#define WIFI_USARTx_PORT                            GPIOC
#define WIFI_USARTx_Tx_PIN                          GPIO_PIN_6
#define WIFI_USARTx_Rx_PIN                          GPIO_PIN_7

#define WIFI_USARTx_TX_AF	GPIO_AF8_USART6
#define WIFI_USARTx_RX_AF	GPIO_AF8_USART6
*/

#define WIFI_USARTx_RCC_CLK_ENABLE()                 __HAL_RCC_USART2_CLK_ENABLE()
#define WIFI_USARTx_RCC_CLK_DISABLE()                __HAL_RCC_USART2_CLK_DISABLE()

#define WIFI_USARTx_GPIO_ClK_ENABLE()               __HAL_RCC_GPIOD_CLK_ENABLE()
#define WIFI_USARTx_PORT                            GPIOD
#define WIFI_USARTx_Tx_PIN                          GPIO_PIN_5
#define WIFI_USARTx_Rx_PIN                          GPIO_PIN_6

#define WIFI_USARTx_TX_AF	GPIO_AF7_USART2
#define WIFI_USARTx_RX_AF	GPIO_AF7_USART2

#define WIFI_USARTx_GPIO_RTS_CTS_ClK_ENABLE()       __HAL_RCC_GPIOH_CLK_ENABLE()
#define WIFI_USARTx_RTS_CTS_PORT                    GPIOH
#define WIFI_USARTx_RTS_PIN                         GPIO_PIN_2
#define WIFI_USARTx_CTS_PIN                         GPIO_PIN_3

#define WIFI_USARTx_RST_PORT                    GPIOI
#define WIFI_USARTx_RST_PIN                     GPIO_PIN_8
#define WIFI_USARTx_GPIO_RST_CLK_ENABLE()       __HAL_RCC_GPIOI_CLK_ENABLE()

#define WIFI_USARTx_BPS_PORT                    GPIOD
#define WIFI_USARTx_BPS_PIN                     GPIO_PIN_15
#define WIFI_USARTx_GPIO_BPS_CLK_ENABLE()       __HAL_RCC_GPIOD_CLK_ENABLE()

void WIFI_USARTx_Init(void);

#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif

#endif	/* _WIFIUART_H_ */

