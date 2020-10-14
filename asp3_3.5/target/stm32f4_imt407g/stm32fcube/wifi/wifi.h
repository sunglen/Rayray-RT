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
 *  @(#) $Id: wifiuart.h,v 1.0 2020/04/18 10:26:29 roi Exp $
 */
/*
 *  STM32F7XX用 WIFIデバイスドライバインクルードファイル
 */

#ifndef _WIFI_H_
#define _WIFI_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "wifiuart.h"

/*
 *  MACポート定義
 */
#define WIFI1_PORTID            1
#define WIFIDEF_PORTID          WIFI1_PORTID
#define NUM_WIFI_PORT           1

/*
 *  ボーレート設定
 */
#define WIFIUART_115200BPS      1
#define WIFIUART_460800BPS      0

/*
 *  MAC EVENT定義
 */
#define PHY_EVENT_DETECT        (1<<0)
#define SEND_EVENT_DETECT       (1<<1)
#define RECV_EVENT_DETECT       (1<<2)
#define START_EVENT_DETECT      (1<<6)
#define RESET_EVENT_DETECT      (1<<7)

/*
 *  ETHERNETアドレス長
 */
#define	ADLEN_ETHER	6
#define ETHER_HDR_SIZE	((ADLEN_ETHER*2)+2)

/*
 *  LINK設定定義
 */
#define LINK_SPEED_OF_YOUR_NETIF_IN_BPS  100000000

#define MODULE_READY            0
#define WIFI_START              1
#define WIFI_CONNECT            2
#define WIFI_DISCONNECT         3
#define WIFI_STOP               4

#define BLE_START               8
#define BLE_CONNECT             9
#define BLE_DISCONNECT          10
#define BLE_RECV                11

#define LINK_READY              (1<<15)
#define LINK_BLE_START          (1<<9)
#define LINK_BLE_CONNECT        (1<<8)
#define LINK_START              (1<<1)
#define LINK_CONNECT            (1<<0)

#define DESC_RX_ACTIVE          (1<<15)

#define EMAC_DATA_ATTRIBUTE     (section(".ethDataSection"))

typedef struct
{
	uint16_t              status;
	uint16_t              length;
}WIFI_Head_t;

/*
 *  EMACコンフュギュレーション構造体定義
 */
typedef struct
{
	uint32_t              paketbufsize;		/* WIFI パケットバッファサイズ */
	uint32_t              wbufcount;		/* WIFI ワークバッファ数 */
	void                  *databuffer;		/* WIFI データ領域先頭アドレス */
	const char            *ssid;			/* WIFI SSID */
	const char            *password;		/* WIFI PASSWORD */
	const char            *bledevice;		/* BLE DEVICE NAME */
    uint8_t               *blebuffer;		/* BLE ワークバッファ */
	uint32_t              bps_select;		/* ボーレート選択 */
	int_t                 rst_pin;			/* リセットピン番号 */
	int_t                 bps_pin;			/* ボーレートピン番号 */
	int_t                 rts_pin;			/* RTSピン番号 */
	int_t                 cts_pin;			/* CTSピン番号 */
	uint32_t              pull;				/* GPIO pull mode */
	uint32_t              otype;			/* GPIO output type */
}WIFI_Init_t;

/*
 *  EMACハンドラ定義
 */
typedef struct WIFI_Handle WIFI_Handle_t;
struct WIFI_Handle {
	WIFIUART_Handle_t *huart;
	WIFI_Init_t  Init;
	uint8_t      tx_wait;
	uint8_t      rx_top;
	uint8_t      rx_tail;
	uint8_t      rx_count;
	uint8_t      hwaddr[8];
	uint32_t     linkvalue;
	uint8_t      version[2];
	uint16_t     blecount;
	ID           macid;
	void         (*wifievent)(WIFI_Handle_t *hwifi, uint32_t);
	void         (*uartevent)(WIFI_Handle_t *hwifi, int);

	uint32_t     ifShortPkts;
	uint32_t     wifi_tx_count;
	uint32_t     wifi_rx_count;
	uint32_t     wifi_connect_count;
};

/*
 *  LWIP用パケットバッファ構造体
 */
struct wifi_pkt {
	struct wifi_pkt *next;					/* next pbuf chain */
	void         *payload;					/* pointer to the data buffer */
	uint16_t     tot_len;					/* total length of this buffer and all next buffers in chain */
	uint16_t     len;						/* length of this buffer */
};


extern WIFI_Handle_t *wifi_init(ID portid, WIFI_Init_t *ini);
extern ER   wifi_deinit(WIFI_Handle_t *hwifi);
extern ER   wifi_send(WIFI_Handle_t *hwifi, struct wifi_pkt *pktp);
extern int  wifi_recv_length(WIFI_Handle_t *hwifi);
extern ER   wifi_recv(WIFI_Handle_t *hwifi, struct wifi_pkt *pktp);
extern uint32_t wifi_link_detect(WIFI_Handle_t *hwifi);
extern ER   wifi_reset(WIFI_Handle_t *hwifi);
extern WIFI_Handle_t *wifi_gethandler(ID portid);
extern ER wifi_ble_send(WIFI_Handle_t *hwifi, uint8_t *pdata, uint32_t length);
extern void wifi_dispatch(WIFI_Handle_t *hwifi);

#ifdef __cplusplus
}
#endif

#endif /* _WIFI_H_ */

