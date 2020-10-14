/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2008-2011 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2015-2018 by TOPPERS PROJECT Educational Working Group.
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
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
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: device.c 698 2018-11-06 20:57:40Z roi $
 */
/*
 * 
 * カップラーメンタイマ用デバイス操作関数群の定義
 *
 */
#include "device.h"

#include "kernel_impl.h"
#include <t_syslog.h>
#include <t_stdlib.h>
#include <sil.h>
#include <target_syssvc.h>

#include "stm32f4xx_nucleo.h"
#include "bsp_dac.h"
#include "bsp_spiflash.h"
#include "bsp_smbus.h"
#include "bsp_i2c_OLED.h"
#include "bsp_i2c_hw_24CXX.h"
#include "SPI_TMC.h"

/*
 *  LED接続ポート初期化
 */ 
void
led_init(intptr_t exinf)
{
	//BSP_LED_Init(LED1);
	BSP_LED_Init(LED2);
}

/*
 *  LED接続ポート読み出し
 */
uint_t
led_in(Led_TypeDef led)
{
	if(BSP_LED_GetState(led) == 0)
		return 1;
	else
		return 0;
}

/*
 *  LED接続ポート書き込み
 */ 
void
led_out(Led_TypeDef led, unsigned short led_data)
{
	  if (led_data == 0)
	  {
		  BSP_LED_Off(led);
	  }
	  else
	  {
		  BSP_LED_On(led);
	  }
}

/*
 *  CNC接続ポート初期化
 */
void
cnc_init(intptr_t exinf)
{
	BSP_CNCAnalog_Init();
	BSP_CNCDigital_Init();
}

/*
 *  CNC接続ポート読み出し
 */
uint_t
cnc_analog()
{
	return  BSP_CNCAnalog_GetValue();
}

/*
 *  CNC接続ポート書き込み
 */
void
cnc_digital(uint_t value)
{
	BSP_CNCDigital_SetValue(value);
}

/*
 *  SPI FLASH初期化
 */
void
flash_init(intptr_t exinf)
{
	BSP_SPIFlash_Init();
}

/*
 *  SPI FLASH test
 */
int
flash_mkfs()
{
	//return BSP_SPIFlash_Makefs();
	return 0;
}

/*
 *  SPI FLASH test
 */
int
flash_test()
{
	//return BSP_SPIFlash_SimpleTest();
	return 0;
}

/*
 *  GPIO TEMP SENSOR DEVICE初期化
 */
void
tmp_init(intptr_t exinf)
{
	BSP_SMBUS_Init();
}

/*
 *  GPIO TEMP SENSOR DEVICE test
 */
float
tmp_read()
{
	return BSP_SMBUS_ReadTemp();
}


/*
 *  I2C OLED Init
 */
void
oled_init(intptr_t exinf)
{
	BSP_OLED_Init();
}

/*
 *  I2C OLED test
 */
void
oled_test()
{
	BSP_OLED_Test();
}

/*
 *  I2C HW EEPROM Init
 */
void
i2c_hw_eeprom_init(intptr_t exinf)
{
	AT24C02_Init();
}

/*
 *  I2C HW EEPROM test
 */
uint_t
i2c_hw_eeprom_test(uint8_t addr, uint8_t data_in, uint8_t* data_out, uint8_t read_only)
{
	return AT24C02_Test(addr, data_in, data_out, read_only);
}

/*
 *  TMC Init
 */
void
tmc_init(intptr_t exinf)
{
	tmc5160_initSPI();
}

/*
 *  TMC test
 */
uint_t
tmc_test(int_t xtarget)
{
	return tmc5160_test_xtarget(xtarget);
}
