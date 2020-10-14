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
 *  @(#) $Id: wifiuart.c,v 1.1 2020/04/18 20:06:33 roi Exp $
 */
/*
 *  STM32F7XX用 WIFIUARTドライバ
 */
#include "kernel_impl.h"
#include <t_syslog.h>
#include <t_stdlib.h>
#include <string.h>
#include <sil.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include <target_syssvc.h>
#include "wifiuart.h"

#define sil_orw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) | (b))
#define sil_andw_mem(a, b)		sil_wrw_mem((a), sil_rew_mem(a) & ~(b))
#define sil_modw_mem(a, b, c)	sil_wrw_mem((a), (sil_rew_mem(a) & (~b)) | (c))

/*
 *  UARTポートIDから管理ブロックを取り出すためのマクロ
 */
#define INDEX_UART(uartid)      ((uint_t)((uartid) - 1))

/*
 * USARTレジスタ定義
 */
#define USART_SR(x)		(x)
#define USART_DR(x)		(x + 0x04)
#define USART_BRR(x)	(x + 0x08)
#define USART_CR1(x)	(x + 0x0C)
#define USART_CR2(x)	(x + 0x10)
#define USART_CR3(x)	(x + 0x14)
#define USART_GTPR(x)	(x + 0x18)

#define UART_TIMEOUT_VALUE  0x1FFFFFF

#ifndef QUEUE_BUFSIZE
#define QUEUE_BUFSIZE  1024
#endif

#define LIMIT1_SIZE    ((QUEUE_BUFSIZE*7)/8)
#define LIMIT2_SIZE    ((QUEUE_BUFSIZE*6)/8)

static queue_t txque[NUM_WIFIUARTPORT];
static queue_t rxque[NUM_WIFIUARTPORT];
static uint8_t txbuffer[NUM_WIFIUARTPORT][QUEUE_BUFSIZE];
static uint8_t rxbuffer[NUM_WIFIUARTPORT][QUEUE_BUFSIZE];

static WIFIUART_Handle_t Huart[NUM_WIFIUARTPORT];

/*
 *  送信割込み許可
 */
static void
wifiuart_enable_send(WIFIUART_Handle_t *huart)
{
	sil_orw_mem((uint32_t *)USART_CR1(huart->base), USART_CR1_TXEIE);
}

/*
 *  送信割込み禁止
 */
static void
wifiuart_disable_send(WIFIUART_Handle_t *huart)
{
	sil_andw_mem((uint32_t *)USART_CR1(huart->base), USART_CR1_TXEIE);
}

/*
 *  RTS受信許可
 */
static void
wifiuart_enable_rts(WIFIUART_Handle_t *huart)
{
	//digitalWrite(huart->Init.rtspin, 0);
	HAL_GPIO_WritePin(WIFI_USARTx_PORT, WIFI_USARTx_RTS_PIN, GPIO_PIN_RESET);
}

/*
 *  RTS受信不可
 */
static void
wifiuart_disable_rts(WIFIUART_Handle_t *huart)
{
	//digitalWrite(huart->Init.rtspin, 1);
	HAL_GPIO_WritePin(WIFI_USARTx_PORT, WIFI_USARTx_RTS_PIN, GPIO_PIN_SET);
}

/*
 *  CTSチェック
 */
static bool_t
wifiuart_sens_cts(WIFIUART_Handle_t *huart)
{
	//return (bool_t)(digitalRead(huart->Init.ctspin) == 0);
	return (bool_t)HAL_GPIO_ReadPin(WIFI_USARTx_PORT, WIFI_USARTx_CTS_PIN);
}

/*
 *  受信バッファに文字があるか？
 */
static bool_t
wifiuart_getready(WIFIUART_Handle_t *huart)
{
	return (sil_rew_mem((void*)USART_SR(huart->base)) & USART_SR_RXNE) != 0;
}

/*
 *  送信バッファに空きがあるか？
 */
static bool_t
wifiuart_putready(WIFIUART_Handle_t *huart)
{
	return (sil_rew_mem((void*)USART_SR(huart->base)) & USART_SR_TXE) != 0;
}

/*
 *  WIFI-UART割込みハンドラ
 */
void
wifiuart_isr(intptr_t exinf)
{
	WIFIUART_Handle_t *huart = &Huart[INDEX_UART(exinf)];
	uint32_t base = huart->base;

	uint32_t tmp;
	queue_t  *que;
	int      bsize;

	BSP_LED_Toggle(LED1);

	if(wifiuart_getready(huart)){
		que = huart->rque;
		bsize = que->top - que->tail;
		if(bsize < 0)
			bsize += que->size;
		if(bsize < (que->size-1)){
			tmp = sil_rew_mem((uint32_t *)(USART_DR(base))) & 0xFF;
			que->buffer[que->top++] = (uint8_t)tmp;
			if(que->top >= que->size)
				que->top = 0;
			if(huart->rxcallback != NULL)
				huart->rxcallback(huart);
		}
		if(bsize >= LIMIT1_SIZE)
			wifiuart_disable_rts(huart);
	}
	if(wifiuart_putready(huart)){
		que = huart->tque;
		if(wifiuart_sens_cts(huart) && que->top != que->tail){
			sil_wrw_mem((uint32_t *)(USART_DR(base)), (uint32_t)que->buffer[que->tail++]);
			if(que->tail >= que->size)
				que->tail -= que->size;
			if(que->top == que->tail)
				wifiuart_disable_send(huart);
		}
		else
			wifiuart_disable_send(huart);
	}
}

/*
 *  拡張UART初期化
 */
WIFIUART_Handle_t *
wifiuart_init(ID portid, WIFIUART_Init_t *ini)
{
	WIFIUART_Handle_t *huart;
	uint32_t no = INDEX_UART(portid);
	uint32_t base=WIFIUART1_BASE;

	uint32_t tmp, usartdiv, fraction;
	uint32_t src_clock;

	if(portid < 0 || portid > NUM_WIFIUARTPORT || ini == NULL)
		return NULL;

	txque[no].size = QUEUE_BUFSIZE;
	txque[no].top  = 0;
	txque[no].tail = 0;
	txque[no].buffer = txbuffer[no];
	rxque[no].size = QUEUE_BUFSIZE;
	rxque[no].top  = 0;
	rxque[no].tail = 0;
	rxque[no].buffer = rxbuffer[no];

	huart  = &Huart[no];
	memcpy((void *)&huart->Init, ini, sizeof(WIFIUART_Init_t));
	huart->base = base;
	huart->no   = no;
	huart->tque = &txque[no];
	huart->rque = &rxque[no];

	/* USARTの無効化 */
	sil_andw((void*)USART_CR1(base), ~USART_CR1_UE);

	/* 1STOP BIT */
	sil_wrw_mem((void*)USART_CR2(base), 0);

	/* 1START BIT, 8DATA bits, Parityなし */
	sil_wrw_mem((void*)USART_CR1(base), 0);

	/* CR3初期化 */
	sil_wrw_mem((void*)USART_CR3(base), 0);

	/* 通信速度設定 */
	if (base == USART1_BASE) {
		/* USART1のみPCLK2を使用する */
		src_clock = HAL_RCC_GetPCLK2Freq();
	} else {
		src_clock = HAL_RCC_GetPCLK1Freq();
	}

	tmp = (1000 * (src_clock / 100)) / ((huart->Init.bps / 100) * 16);
	usartdiv = (tmp / 1000) << 4;
	fraction = tmp - ((usartdiv >> 4) * 1000);
	fraction = ((16 * fraction) + 500) / 1000;
	usartdiv |= (fraction & 0x0F);
	sil_wrw_mem((void*)USART_BRR(base), usartdiv);

	/* 送受信の有効化、エラー割込みの有効化 */
	sil_orw((void*)USART_CR1(base), USART_CR1_RE | USART_CR1_TE);
	sil_orw((void*)USART_CR3(base), USART_CR3_EIE);

	/* USARTの有効化 */
	sil_orw((void*)USART_CR1(base), USART_CR1_UE);

	/*
	 *  受信通知コールバックを許可する．
	 */
	sil_orw((void*)USART_CR1(base), USART_CR1_RXNEIE);

	//wifiuart_enable_send(huart);

	/*
	 *  シリアルI/O割込みのマスクを解除する．
	 */
	ena_int(INTNO_WIFIUART1);
	wifiuart_enable_rts(huart);
	return huart;
}

/*
 *  WIFI-UART無効化
 */
ER
wifiuart_deinit(WIFIUART_Handle_t *huart)
{
	uint32_t base, tmp;

	if(huart == NULL)
		return E_PAR;
	/*
	 *  ハードウェアのリセット
	 */
	base = huart->base;

	/*
	 *  USARTをディスエーブル
	 */
	sil_andw((void*)USART_CR1(base), ~USART_CR1_UE);

	return E_OK;
}

/*
 *  WIFI-UART受信
 */
int
wifiuart_recev(WIFIUART_Handle_t *huart, unsigned char *buf, int len)
{
	queue_t  *que;
	int      bsize, rlen = 0;
	uint32_t i;

	if(huart == NULL)
		return 0;
	que = huart->rque;
	while(len > rlen){
		bsize = que->top - que->tail;
		if(bsize == 0)
			break;
		else if(bsize < 0)
			bsize = que->size - que->tail;
		if(bsize > (len - rlen))
			bsize = len - rlen;
		for(i = 0 ; i < bsize ; i++)
			*buf++ = que->buffer[que->tail++];
		if(que->tail >= que->size)
			que->tail -= que->size;
		rlen += bsize;
	}
	return rlen;
}

/*
 *  WIFI-UART受信サイズ取得
 */
int
wifiuart_recsize(WIFIUART_Handle_t *huart)
{
	queue_t  *que;
	int      bsize;

	if(huart == NULL)
		return 0;
	que = huart->rque;
	bsize = que->top - que->tail;
	if(bsize < 0)
		bsize += que->size;
	if(bsize < LIMIT2_SIZE)
		wifiuart_enable_rts(huart);
	return bsize;
}

/*
 *  WIFI-UART送信
 */
int
wifiuart_send(WIFIUART_Handle_t *huart, unsigned char *buf, int len)
{
	queue_t  *que;
	int      bsize, i;

	if(huart == NULL)
		return 0;
	que = (queue_t *)huart->tque;
	for(i = 0 ; i < len ; i++){
		bsize = que->top - que->tail;
		if(bsize < 0)
			bsize += que->size;
		if(bsize < (que->size-1)){
			que->buffer[que->top++] = *buf++;
			if(que->top >= que->size)
				que->top -= que->size;
		}
		else{
			if(wifiuart_sens_cts(huart))
				wifiuart_enable_send(huart);
			dly_tsk(20000);
		}
	}
	if(i != 0 && wifiuart_sens_cts(huart))
		wifiuart_enable_send(huart);
	return i;
}

/*
 *  CTSセンスチェック
 */
bool_t
wifiuart_cts_sens(WIFIUART_Handle_t *huart)
{
	queue_t  *que;

	if(huart == NULL)
		return false;
	que = huart->tque;
	if(que->top == que->tail || !wifiuart_sens_cts(huart))
		return false;
	wifiuart_enable_send(huart);
	return true;
}

/*
 *  GPIO設定関数
 */

void WIFI_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;

    /* 串口外设时钟使能 */
    WIFI_USARTx_GPIO_ClK_ENABLE();
    WIFI_USARTx_GPIO_RTS_CTS_ClK_ENABLE();
    WIFI_USARTx_GPIO_RST_CLK_ENABLE();
    WIFI_USARTx_GPIO_BPS_CLK_ENABLE();

    /* 串口外设功能GPIO配置 */
    GPIO_InitStruct.Pin = WIFI_USARTx_Tx_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    GPIO_InitStruct.Alternate = WIFI_USARTx_TX_AF;
    HAL_GPIO_Init(WIFI_USARTx_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = WIFI_USARTx_Rx_PIN;
    //GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    //GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Alternate = WIFI_USARTx_RX_AF;
    HAL_GPIO_Init(WIFI_USARTx_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = WIFI_USARTx_RTS_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    //GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    HAL_GPIO_Init(WIFI_USARTx_RTS_CTS_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = WIFI_USARTx_CTS_PIN;
    //GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(WIFI_USARTx_RTS_CTS_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = WIFI_USARTx_RST_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    HAL_GPIO_Init(WIFI_USARTx_RST_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = WIFI_USARTx_BPS_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    //GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    HAL_GPIO_Init(WIFI_USARTx_BPS_PORT, &GPIO_InitStruct);
}

UART_HandleTypeDef husartx_wifi;

void WIFI_USARTx_Init(void)
{
  /* 通信功能引脚GPIO初始化 */
  WIFI_GPIO_Init();
  WIFI_USARTx_RCC_CLK_ENABLE();
  husartx_wifi.Instance = WIFIUART1_NAME;
  husartx_wifi.Init.BaudRate = WIFIUART1_BPS;
  husartx_wifi.Init.WordLength = UART_WORDLENGTH_8B;
  husartx_wifi.Init.StopBits = UART_STOPBITS_1;
  husartx_wifi.Init.Parity = UART_PARITY_NONE;
  husartx_wifi.Init.Mode = UART_MODE_TX_RX;
  husartx_wifi.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  husartx_wifi.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&husartx_wifi);

  //HAL_NVIC_SetPriority(USART6_IRQn, 0, 1);
  //HAL_NVIC_EnableIRQ(USART6_IRQn);
}
