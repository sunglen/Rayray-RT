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
 *  @(#) $Id: wifiuart.c,v 1.1 2020/04/17 13:18:33 roi Exp $
 */
/*
 * 
 *  STM32F7XX用 WIFI-ESP32(LWIP用)ドライバ関数群
 *
 */
#include "kernel_impl.h"
#include <t_syslog.h>
#include <t_stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sil.h>
#include <target_syssvc.h>
#include <string.h>
#include "device.h"
#include "wifi.h"
#include "kernel_cfg.h"

#define MIN(a, b) ((a) > (b) ? (b) : (a))

/*
 *  WIFICポートIDから管理ブロックを取り出すためのマクロ
 */
#define INDEX_WIFI(emacid)      ((uint_t)((emacid) - 1))

/*
 *  受信バッファポインタを取り出すマクロ
 */
#define get_workbuf(h, n)       ((h)->Init.databuffer + ((h)->Init.paketbufsize + sizeof(WIFI_Head_t)) * (n))

/*
 *  WIFI ハンドラ
 */
static WIFI_Handle_t WifiHandle[NUM_WIFI_PORT];


static uint8_t *
buf_length2char(uint8_t *d, int len)
{
	int     i;
	uint8_t buf[16];

	for(i = 0 ; i < 16 && len != 0 ; i++){
		buf[i] = (len % 10) + '0';
		len /= 10;
	}
	while(i > 0){
		*d++ = buf[--i];
	}
	return d;
}

/*
 *  UART受信コールバック関数
 */
static void
wifiuart_rxcallback(WIFIUART_Handle_t *huart)
{
	isig_sem(WUART1_SEM);
}

static int
wifiuart_recv(WIFIUART_Handle_t *huart, uint8_t *buf, int len)
{
	int rlen = 0;

	while(rlen < len){
		wifiuart_cts_sens(huart);
		rlen = wifiuart_recsize(huart);
		if(rlen < len)
			twai_sem(WUART1_SEM, 100000);
	}
	return wifiuart_recev(huart, buf, len);
}

/*
 *  DESCRIPTER領域の初期化
 *  parameter1 hmac  EMACハンドラへのポインタ
 */
static void
wifi_bd_reset(WIFI_Handle_t *hwifi)
{
	WIFI_Head_t *h;
	uint8_t     *p = hwifi->Init.databuffer;
	uint_t      i;

	for(i = 0 ; i < hwifi->Init.wbufcount ; i++){
		h = (WIFI_Head_t *)p;
		h->status = 0;
		h->length = 0;
		p += (hwifi->Init.paketbufsize + sizeof(WIFI_Head_t));
	}
	hwifi->rx_top   = 0;
	hwifi->rx_tail  = 0;
	hwifi->rx_count = 0;
}

/*
 *  EMACデバイスの初期化
 *  parameter1 portid EMACのポートID
 *  parameter2 ini    初期化構造体へのポインタ
 *  return            ハンドラへのポインタ
 */
WIFI_Handle_t *
wifi_init(ID portid, WIFI_Init_t *ini)
{
	WIFIUART_Init_t Init;
	WIFI_Handle_t *hwifi;
	uint32_t no;

	if(portid == 0 || portid > NUM_WIFI_PORT)
		return NULL;

	no = INDEX_WIFI(portid);
	hwifi = &WifiHandle[no];

	memset(hwifi, 0, sizeof(WIFI_Handle_t));
	memcpy(&hwifi->Init, ini, sizeof(WIFI_Init_t));

	WIFI_USARTx_Init();

	if(ini->bps_pin >= 0){
		HAL_GPIO_WritePin(WIFI_USARTx_BPS_PORT, WIFI_USARTx_BPS_PIN, ini->bps_select);
	}
	if(ini->rst_pin >= 0){
		HAL_GPIO_WritePin(WIFI_USARTx_RST_PORT, WIFI_USARTx_RST_PIN, GPIO_PIN_RESET);
	}

	if(ini->bps_select != WIFIUART_460800BPS)
		Init.bps = 115200;
	else
		Init.bps = 460800;
	Init.rtspin = ini->rts_pin;
	Init.ctspin = ini->cts_pin;
	Init.pull   = ini->pull;
	Init.otype  = ini->otype;
	hwifi->huart = wifiuart_init(WIFIUART1_PORTID, &Init);
	if(hwifi->huart == NULL){
		syslog_0(LOG_ERROR, "## WIFI UART INIT ERROR ##");
		return NULL;
	}

	/*
	 *  ワークバッファリセット
	 */
	wifi_bd_reset(hwifi);

	hwifi->macid = portid;
	return hwifi;
}

/*
 *  WIFI終了処理
 *  parameter1 hmac  EMACハンドラへのポインタ
 *  return     E_OKで正常終了
 */
ER
wifi_deinit(WIFI_Handle_t *hwifi)
{
	if(hwifi == NULL || hwifi->macid == 0 || hwifi->macid > NUM_WIFI_PORT)
		return E_OBJ;
	wifiuart_deinit(hwifi->huart);
	hwifi->macid = 0;
	return E_OK;
}

/*
 *  WIFI送信処理
 *  parameter1 hmac  EMACハンドラへのポインタ
 *  parameter2 pktp  送信パケット構造体(LWIP型)
 *  return     E_OKで正常終了
 */
ER
wifi_send(WIFI_Handle_t *hwifi, struct wifi_pkt *pktp)
{
	uint8_t  head[16], *buf;
	ER       ercd = E_OK;

	if(hwifi == NULL || pktp == NULL)
		return E_PAR;

	head[0] = 'W';
	head[1] = 'D';
	buf = buf_length2char(&head[2], pktp->tot_len);
	*buf++ = ':';
	wifiuart_send(hwifi->huart, head, (buf-head));

	while(pktp != NULL){
		if(pktp->len == 0)
			break;

		/*
		 *  送信データをバッファに書き込む
		 */
		wifiuart_send(hwifi->huart, pktp->payload, pktp->len);
		pktp = pktp->next;
	}
	return ercd;
}

/*
 *  受信データ長の取り出し
 *  parameter1 hwifi  WIFIハンドラへのポインタ
 *  return     0でなければ、受信パケット長
 */
int
wifi_recv_length(WIFI_Handle_t *hwifi)
{
	WIFI_Head_t *h;
	int      num, i;
	uint8_t  *p;

	if(hwifi->rx_count == 0)
		return 0;
	for(i = hwifi->rx_tail, num = hwifi->rx_count ; num > 0 ; num--){
		p = get_workbuf(hwifi, i);
		h = (WIFI_Head_t *)p;
		if((h->status & DESC_RX_ACTIVE) != 0)
			return h->length;
		if(++i >= hwifi->Init.wbufcount)
			i = 0;
	}
	return 0;
}

/*
 *  受信パケットの取得
 *  parameter1 hwifi  WIFIハンドラへのポインタ
 *  parameter2 pktp  受信データ格納パケット構造体(LWIP型)
 *  return     E_OKならば、受信パケット長
 */
ER
wifi_recv(WIFI_Handle_t *hwifi, struct wifi_pkt *pktp)
{
	WIFI_Head_t *h;
	int      actlen, i;
	volatile uint8_t  *b, *pdata, *p;
	uint32_t len, tlen, num;

	if(pktp != NULL){
		b = pktp->payload;
		len = pktp->len;
	}
	else{
		b = NULL;
		len = 0;
	}

	/*
	 *  受信パケットの確認し、ない場合はエラー終了
	 */
	if(hwifi->rx_count == 0)
		return E_NOMEM;

	while(hwifi->rx_count > 0){
		p = get_workbuf(hwifi, hwifi->rx_tail);
		h = (WIFI_Head_t *)p;
		num = hwifi->rx_tail;
		if(++hwifi->rx_tail >= hwifi->Init.wbufcount)
			hwifi->rx_tail = 0;
		hwifi->rx_count--;
		if((h->status & DESC_RX_ACTIVE) != 0){
			h->status &= ~DESC_RX_ACTIVE;
			/*
			 *  パケット格納領域がある場合は受信パケットを取得する
			 */
			if(b != NULL){
				/* 受信データを取得する */
				pdata = p + sizeof(WIFI_Head_t);
				actlen = h->length;
				syslog_4(LOG_DEBUG, "WIFI:wifi_recv num(%d) b[%08x] pdata[%08x] actlen[%08x] !", num, b, pdata, actlen);
				syslog_4(LOG_DEBUG, "  12[%02x] 13[%02x] 14[%02x] 15[%02x]", pdata[12], pdata[13], pdata[14], pdata[15]);
				while(actlen > 0){
					tlen = MIN(len, actlen);
					for(i = 0 ; i < tlen ; i++)
						*b++ = *pdata++;
					actlen -= tlen;
					len    -= tlen;
					if(len == 0 /*&& actlen > 0*/){
						if((pktp = pktp->next) == NULL){
							b = NULL;
							break;
						}
						b = pktp->payload;
						if((len = pktp->len) == 0){
							b = NULL;
							break;
						}
					}
				}
			}
			return E_OK;
		}
	}
	return E_NOMEM;
}

/*
 *  LINK状態を取得する
 *  parameter1 hmac  EMACハンドラへのポインタ
 *  return     LINK状態(0で未接続)
 */
uint32_t
wifi_link_detect(WIFI_Handle_t *hwifi)
{
	return hwifi->linkvalue & LINK_CONNECT;
}

/*
 *  WIFIをリセットする
 *  parameter1 hmac   EMACハンドラへのポインタ
 *  return     E_OKで正常終了
 */
ER
wifi_reset(WIFI_Handle_t *hwifi)
{
	int len;
	uint8_t buf[8];

	hwifi->linkvalue &= ~LINK_READY;

	/*
	 *  WIFIモジュールリセット
	 */
	GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = WIFI_USARTx_RST_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    //GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
    HAL_GPIO_Init(WIFI_USARTx_RST_PORT, &GPIO_InitStruct);
	HAL_GPIO_WritePin(WIFI_USARTx_RST_PORT, WIFI_USARTx_RST_PIN, GPIO_PIN_RESET);
	dly_tsk(100000);
	//HAL_GPIO_WritePin(WIFI_USARTx_RST_PORT, WIFI_USARTx_RST_PIN, GPIO_PIN_SET);
	GPIO_InitStruct.Pin = WIFI_USARTx_RST_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(WIFI_USARTx_RST_PORT, &GPIO_InitStruct);
	dly_tsk(500000);

	/*
	 *  受信バッファをフラッシュ
	 */
	while((len = wifiuart_recsize(hwifi->huart)) > 0){
		len = MIN(len, 8);
		wifiuart_recev(hwifi->huart, buf, len);
	}

	/*
	 *  ワークバッファリセット
	 */
	wifi_bd_reset(hwifi);
	return E_OK;
}

WIFI_Handle_t *
wifi_gethandler(ID portid)
{
	if(portid == 0 || portid > NUM_WIFI_PORT)
		return NULL;
	return &WifiHandle[INDEX_WIFI(portid)];
}

/*
 *  ESP32 BLE SPP送信
 */
ER
wifi_ble_send(WIFI_Handle_t *hwifi, uint8_t *pdata, uint32_t length)
{
	uint8_t *buf, head[16];

	if(hwifi == NULL || pdata == NULL || length == 0)
		return E_PAR;
	if((hwifi->linkvalue & LINK_BLE_CONNECT) == 0)
		return E_OBJ;
	head[0] = 'B';
	head[1] = 'D';
	buf = buf_length2char(&head[2], length);
	*buf++ = ':';
	wifiuart_send(hwifi->huart, head, (buf-head));

	/*
	 *  送信データをバッファに書き込む
	 */
	wifiuart_send(hwifi->huart, pdata, length);
	return E_OK;
}

void
wifi_dispatch(WIFI_Handle_t *hwifi)
{
	WIFIUART_Handle_t *huart = hwifi->huart;
	WIFI_Head_t *h;
	uint_t i;
	uint32_t event = 0;
	int len, len2, clen;
	uint8_t *p, buf[32];

	huart->rxcallback  = wifiuart_rxcallback;

	while(1){
		while(wifiuart_recsize(huart) == 0){
			wifiuart_cts_sens(huart);
			twai_sem(WUART1_SEM, 100000);
		}
		wifiuart_recv(huart, buf, 1);
		if(buf[0] != 'W' && buf[0] != 'M' && buf[0] != 'B')
			continue;
		len = wifiuart_recv(huart, &buf[1], 1);
		clen = 0;
		event = 0;
		while(len > 0){
			len = wifiuart_recv(huart, &buf[2], 1);
			if(buf[2] >= '0' && buf[2] <= '9')
				clen = clen * 10 + (buf[2] - '0');
			else
				break;
		}
		if(buf[0] == 'W'){
			switch(buf[1]){
			case 'S':
				hwifi->linkvalue |= LINK_START;
				if(clen > 0)
					wifiuart_recv(huart, hwifi->hwaddr, clen);
				clen = 0;
				syslog_3(LOG_NOTICE, "mac[%02x][%02x][%02x]", hwifi->hwaddr[0], hwifi->hwaddr[1], hwifi->hwaddr[2]);
				syslog_3(LOG_NOTICE, "mac[%02x][%02x][%02x]", hwifi->hwaddr[3], hwifi->hwaddr[4], hwifi->hwaddr[5]);
				if(hwifi->uartevent != NULL)
					hwifi->uartevent(hwifi, WIFI_START);
				event = START_EVENT_DETECT;
				break;
			case 'C':
				hwifi->linkvalue |= LINK_CONNECT;
				if(hwifi->uartevent != NULL)
					hwifi->uartevent(hwifi, WIFI_CONNECT);
				event = PHY_EVENT_DETECT;
				break;
			case 'N':
				hwifi->linkvalue &= ~LINK_CONNECT;
				if(hwifi->uartevent != NULL)
					hwifi->uartevent(hwifi, WIFI_DISCONNECT);
				event = PHY_EVENT_DETECT;
				break;
			case 'E':
				hwifi->linkvalue &= ~LINK_START;
				if(hwifi->uartevent != NULL)
					hwifi->uartevent(hwifi, WIFI_STOP);
				break;
			case 'D':
				if(hwifi->rx_count < hwifi->Init.wbufcount){
					p = get_workbuf(hwifi, hwifi->rx_top);
					h = (WIFI_Head_t *)p;
					wifiuart_recv(huart, &p[sizeof(WIFI_Head_t)], clen);
					h->length  = clen;
					h->status |= DESC_RX_ACTIVE;
					hwifi->rx_count++;
					syslog_2(LOG_DEBUG, "WD count(%d) top(%d)", hwifi->rx_count, hwifi->rx_top);
					if(++hwifi->rx_top >= hwifi->Init.wbufcount)
						hwifi->rx_top = 0;
					clen = 0;
					event = RECV_EVENT_DETECT;
				}
				else
					syslog_1(LOG_ERROR, "wifi:lost packet(%d) !", clen);
				break;
			default:
				break;
			}
			if(hwifi->wifievent != NULL && event != 0)
				hwifi->wifievent(hwifi, event);
			for(i = 0 ; i < clen ; i++)
				wifiuart_recv(huart, &buf[0], 1);
		}
		if(buf[0] == 'B'){
			switch(buf[1]){
			case 'C':
				hwifi->linkvalue |= LINK_BLE_CONNECT;
				if(hwifi->uartevent != NULL)
					hwifi->uartevent(hwifi, BLE_CONNECT);
				break;
			case 'N':
				hwifi->linkvalue &= ~LINK_BLE_CONNECT;
				if(hwifi->uartevent != NULL)
					hwifi->uartevent(hwifi, BLE_DISCONNECT);
				break;
			case 'D':
				hwifi->blecount = clen;
				if(hwifi->Init.blebuffer != NULL){
					wifiuart_recv(huart, hwifi->Init.blebuffer, clen);
					clen = 0;
				}
				if(hwifi->uartevent != NULL)
					hwifi->uartevent(hwifi, BLE_RECV);
				break;
			default:
				break;
			}
			for(i = 0 ; i < clen ; i++)
				wifiuart_recv(huart, &buf[0], 1);
		}
		if(buf[0] == 'M'){
			switch(buf[1]){
			case 'R':
				if(clen >= 2){
					wifiuart_recv(huart, hwifi->version, 2);
					clen -= 2;
				}
				if(hwifi->Init.bledevice != NULL){
					hwifi->linkvalue |= LINK_BLE_START;
					buf[0] = 'B';
					buf[1] = 'S';
					len = strlen(hwifi->Init.bledevice);
					p = buf_length2char(&buf[2], len);
					*p++ = ':';
					wifiuart_send(huart, buf, (p-buf));
					wifiuart_send(huart, (uint8_t *)hwifi->Init.bledevice, len);
				}
				if(hwifi->Init.ssid != NULL){
					syslog_4(LOG_NOTICE, "wifi_dispatch: %c%c (clen=%d). connecting to %s.", buf[0], buf[1], clen, hwifi->Init.ssid);
					hwifi->linkvalue |= LINK_READY;
					buf[0] = 'W';
					buf[1] = 'S';
					len = strlen(hwifi->Init.ssid);
					if(hwifi->Init.password == NULL)
						len2 = 0;
					else
						len2 = strlen(hwifi->Init.password);
					p = buf_length2char(&buf[2], len+len2+1);
					*p++ = ':';
					wifiuart_send(huart, buf, (p-buf));
					wifiuart_send(huart, (uint8_t *)hwifi->Init.ssid, len);
					wifiuart_send(huart, (uint8_t *)",", 1);
					if(len2 > 0)
						wifiuart_send(huart, (uint8_t *)hwifi->Init.password, len2);
					if(hwifi->uartevent != NULL)
						hwifi->uartevent(hwifi, MODULE_READY);
				}
				break;
			default:
				break;
			}
			for(i = 0 ; i < clen ; i++)
				wifiuart_recv(huart, &buf[0], 1);
		}
	}
}

