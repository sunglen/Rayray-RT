#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "SPI_TMC.h"
#include "stm32f4xx_nucleo.h"


void delay(u32 us)
{
	dly_tsk(us);
}

static int dev_spi_writenb(char *tbuf, int len) //tbuf, 5
{
	TMC_SPI_WriteNBytes(tbuf, len);
	return 0;
}

static int dev_spi_transfernb(char *tbuf, char *rbuf, int len) //tbuf, rbuf, 5
{
	TMC_SPI_ReadNBytes(tbuf, rbuf, len);
	return 0;
}


void tmc5160_initSPI(void)
{
	TMC_SPI_Init();
}

// TMC5160 SPI wrapper
void tmc5160_writeDatagram(uint8 motor, uint8 address, uint8 x1, uint8 x2, uint8 x3, uint8 x4)
{
    int value = x1;
	value <<= 8;
	value |= x2;
	value <<= 8;
	value |= x3;
	value <<= 8;
	value |= x4;

    tmc40bit_writeInt(motor, address, value);
}

void tmc5160_writeInt(uint8 motor, uint8 address, int value)
{
    tmc40bit_writeInt(motor, address, value);
}

int tmc5160_readInt(u8 motor, uint8 address)
{
    tmc40bit_readInt(motor, address);
    return tmc40bit_readInt(motor, address);
}

// General SPI decription
void tmc40bit_writeInt(u8 motor, uint8 address, int value)
{
    char tbuf[5];
    tbuf[0] = address | 0x80;
    tbuf[1] = 0xFF & (value>>24);
    tbuf[2] = 0xFF & (value>>16);
    tbuf[3] = 0xFF & (value>>8);
    tbuf[4] = 0xFF & value;

    dev_spi_writenb (tbuf, 5);
}

int tmc40bit_readInt(u8 motor, uint8 address)
{
    char tbuf[5], rbuf[5];
    int value;
	// clear write bit
	tbuf[0] = address & 0x7F;
    
    dev_spi_transfernb (tbuf, rbuf, 5);

	value =rbuf[1];
	value <<= 8;
	value |= rbuf[2];
	value <<= 8;
	value |= rbuf[3];
	value <<= 8;
	value |= rbuf[4];

	return value;
}

/*
 * SPI motor test utility (using spidev driver, spi-gpio-custom, and TMC5610)
 *
 * Copyright (c) 2016  Glen <sun.ge@126.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 * before using this tool, the following steps must be done:
 * insmod spi-gpio-custom bus1=2,39,56,57,3,1000000,124
 * 1)GPIO_1_0 is 32; GPIO_3_0 is GPIO96
 * 2)MODE is 3. (pol=1, pha=1)
 *
 * IMX280A <--> TMC5610-BOB
 * MX28_PAD_LCD_D07__GPIO_1_7 (SCK) --> SCK
 * MX28_PAD_LCD_RD_E__GPIO_1_24 (MOSI) --> SDI
 * MX28_PAD_LCD_WR_RWN__GPIO_1_25 (MISO) --> SDO
 * MX28_PAD_PWM3__GPIO_3_28 (CS) --> CSN
 * GND(OR GPIO) --> DRV_ENN
 * GND(OR GPIO) --> CLK16
 * 3V3(OR GPIO) --> VCC_IO
 *
 * POWER <--> TMC5610-BOB
 * 9~36V --> VS
 * GND --> GND
 *
 * QY1503(1024 line) <--> TMC5610-BOB
 * 1(GND) <--> GND
 * 2(VCC) <--> 3V3 or 5V (from SBC board)
 * 3(A) <--> ENCA
 * 4(B) <--> ENCB
 * 5(Z) <--> ENCN(or zero position switch)
 *
 * Encoder Connector <--> DB15 <--> Function
 * 3(Black) <--> 1 <--> A+
 * 1(Red) <--> 2 <--> +5V
 * 2(White) <--> 3 <--> GND
 * 7(Black) <--> 6 <--> Shield
 * 5(Orange) <--> 7 <--> Z+
 * 6(Gray) <--> 8 <--> Z-
 * 8(Yellow) <--> 11 <--> B+
 * 9(Green) <--> 12 <--> B-
 * 4(Blue) <--> 13 <--> A-
 *
 * Encoder(2000CPR) <--> RMLS-701(AM26C32 Quadruple Differential Line Receiver)
 * +5V <--> +5V or +3.3V (from SBC or TMC5610, 3.3V will also work)
 * GND <--> GND (to SBC or TMC5610)
 * A- <--> A-
 * A+ <--> A+
 * B- <--> B-
 * B+ <--> B+
 * Z- <--> Z- (optional)
 * Z+ <--> Z+ (optional)
 *
 *
 * HN3806-AB-600N(600 line) <--> YTDZ(24V->3.3V Module) <--> TMC5610-BOB
 * VCC(5.8V-24V, Red) <--> 12-24V
 * GND(Black) <--> 0V
 * OUTA(White, pull-up to VCC) <--> I1+(Y1) <--> ENCA
 * OUTB(Green, pull-up to VCC) <--> I2+(Y2) <--> ENCB
 *
 * root@OpenWrt:/# TMCAPI_EXAMPLE
 * spi mode 0x3, 8 bits per word, 1000000 Hz max
 * TMC5160_INP_OUT: 0x30000000
 * Please reset TMC5160 by turn off/on VCC_IO
 * TMC5160_GCONF: 0x0000000c
 *
 *
 * MOTOR（42） <--> TMC5610 (pins of A4988)
 * RED --> A1 (1A of A4988)
 * GREEN --> A2 (1B of A4988)
 * YELLOW --> B1 (2A of A4988)
 * BLUE --> B2 (2B of A4988)
 *
 * MOTOR(20) <--> TMC5610
 * Red(A+) --> A1
 * Red/White(A-) --> A2
 * Green(B+) --> B1
 * Green/White(B-) --> B2
 *
 * SPI motor test utility for toppers
 * STM32F407(SPI1) <--> TMC5610-BOB
 * PA5 (SCK) --> SCK
 * PB5 (MOSI) --> SDI
 * PB4 (MISO) <-- SDO
 * PC13 (CS) --> CSN
 * GND(OR GPIO) --> DRV_ENN
 * GND(OR GPIO) --> CLK16
 * 3V3(OR GPIO) --> VCC_IO
 *
 * SBC <--> YTDZ(24V->3.3V Module) <--> Limit Switch
 * 3.3V <--> VDD <-->
 * GND <--> GND <-->
 * Y0   <--> I0+ <--> 24V
 * Y0   <--> I0- <--> Black
 *
 * Limit Switch <--> Power
 * Brown <--> 24V
 * Blue <--> 0V
 *
 */

// Include the IC(s) you want to use
#include "TMC-API/tmc/ic/TMC5160/TMC5160.h"

#define MOTOR0			0 // Motor 0

void resetMotorDrivers(uint8 motor);

int tmc5160_test(void) {
	int i;
	//gpio_init();

	// Initiate SPI
	tmc5160_initSPI();

/*
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST); // MSB first
  	bcm2835_spi_setDataMode(BCM2835_SPI_MODE3); // SPI Mode 3
  	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256); // 1 MHz clock
  	bcm2835_spi_chipSelect(BCM2835_SPI_CS0); // define CS pin
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW); // set CS polarity to low
*/

	/***** TMC5160-BOB Example *****/
/*
	pinMode(2, OUTPUT);
	digitalWrite(2, HIGH); // Apply VCC_IO voltage to Motor 0
	pinMode(3, OUTPUT);
	digitalWrite(3, LOW); // Use internal clock
	pinMode(4, OUTPUT);
	digitalWrite(4, LOW); // Enable driver stage
*/
	printf("TMC5160_INP_OUT: 0x%08x\n", tmc5160_readInt(MOTOR0, TMC5160_INP_OUT));

	resetMotorDrivers(MOTOR0);

	// MULTISTEP_FILT=1, EN_PWM_MODE=1 enables stealthChop™
	tmc5160_writeInt(MOTOR0, TMC5160_GCONF, 0x0000000C);

	printf("TMC5160_GCONF: 0x%08x\n", tmc5160_readInt(MOTOR0, TMC5160_GCONF));

	// TOFF=3, HSTRT=4, HEND=1, TBL=2, CHM=0 (spreadCycle™)
	tmc5160_writeInt(MOTOR0, TMC5160_CHOPCONF, 0x000100C3);

	// IHOLD=8, IRUN=15 (max. current), IHOLDDELAY=6
	tmc5160_writeInt(MOTOR0, TMC5160_IHOLD_IRUN, 0x00080F0A);

	// TPOWERDOWN=10: Delay before power down in stand still
	tmc5160_writeInt(MOTOR0, TMC5160_TPOWERDOWN, 0x0000000A);

	// TPWMTHRS=500
	tmc5160_writeInt(MOTOR0, TMC5160_TPWMTHRS, 0x000001F4);

	// Values for speed and acceleration
	tmc5160_writeInt(MOTOR0, TMC5160_VSTART, 1);
	tmc5160_writeInt(MOTOR0, TMC5160_A1, 5000);
	tmc5160_writeInt(MOTOR0, TMC5160_V1, 26843);
	tmc5160_writeInt(MOTOR0, TMC5160_AMAX, 5000);
	tmc5160_writeInt(MOTOR0, TMC5160_VMAX, 100000);
	tmc5160_writeInt(MOTOR0, TMC5160_DMAX, 5000);
	tmc5160_writeInt(MOTOR0, TMC5160_D1, 5000);
	tmc5160_writeInt(MOTOR0, TMC5160_VSTOP, 10);
	tmc5160_writeInt(MOTOR0, TMC5160_RAMPMODE, TMC5160_MODE_POSITION);

	for(i=0;i<10;i++)
	{
		// put your main code here, to run repeatedly:
		printf("TMC5160_XACTUAL: 0x%08x\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));
		tmc5160_writeInt(MOTOR0, TMC5160_XTARGET, 0x0007D000);
		//XTARGET = 512000 -> 10 revolutions with micro step = 256

		delay(2000000);

		printf("TMC5160_XACTUAL: 0x%08x\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));
		tmc5160_writeInt(MOTOR0, TMC5160_XTARGET, 0x00000000); //XTARGET=0

		delay(2000000);

		printf("TMC5160_XENC: 0x%08x\n", tmc5160_readInt(MOTOR0, TMC5160_XENC));
	}

	// End SPI communication
  	//bcm2835_spi_end();
   	//bcm2835_close();

	return 0;
}

int tmc5160_test_xtarget(int32_t xtarget) {
	//int xactual;

	// Initiate SPI
	tmc5160_initSPI();

	/***** TMC5160-BOB Example *****/
/*
	pinMode(2, OUTPUT);
	digitalWrite(2, HIGH); // Apply VCC_IO voltage to Motor 0
	pinMode(3, OUTPUT);
	digitalWrite(3, LOW); // Use internal clock
	pinMode(4, OUTPUT);
	digitalWrite(4, LOW); // Enable driver stage
*/
	printf("TMC5160_INP_OUT: 0x%08x\n", tmc5160_readInt(MOTOR0, TMC5160_INP_OUT));

	resetMotorDrivers(MOTOR0);

	// MULTISTEP_FILT=1, EN_PWM_MODE=1 enables stealthChop™
	tmc5160_writeInt(MOTOR0, TMC5160_GCONF, 0x0000000C);

	printf("TMC5160_GCONF: 0x%08x\n", tmc5160_readInt(MOTOR0, TMC5160_GCONF));

	// TOFF=3, HSTRT=4, HEND=1, TBL=2, CHM=0 (spreadCycle™)
	tmc5160_writeInt(MOTOR0, TMC5160_CHOPCONF, 0x000100C3);

	// IHOLD=8, IRUN=15 (max. current), IHOLDDELAY=6
	//tmc5160_writeInt(MOTOR0, TMC5160_IHOLD_IRUN, 0x00080F0A);

	// reduce hold current to avoid motor over-heat. IHOLD=2
	//tmc5160_writeInt(MOTOR0, TMC5160_IHOLD_IRUN, (1)|(16<<8)|(6<<16));
	//IHOLD=1
	tmc5160_writeInt(MOTOR0, TMC5160_IHOLD_IRUN, (1)|(16<<8)|(6<<16));

	// TPOWERDOWN=10: Delay before power down in stand still
	tmc5160_writeInt(MOTOR0, TMC5160_TPOWERDOWN, 0x0000000A);

	// TPWMTHRS=500
	tmc5160_writeInt(MOTOR0, TMC5160_TPWMTHRS, 0x000001F4);

	// Values for speed and acceleration
	tmc5160_writeInt(MOTOR0, TMC5160_VSTART, 1);
	tmc5160_writeInt(MOTOR0, TMC5160_A1, 5000);
	//tmc5160_writeInt(MOTOR0, TMC5160_V1, 26843);
	tmc5160_writeInt(MOTOR0, TMC5160_V1, 0);
	//tmc5160_writeInt(MOTOR0, TMC5160_AMAX, 5000);
	tmc5160_writeInt(MOTOR0, TMC5160_AMAX, 50000);
	//tmc5160_writeInt(MOTOR0, TMC5160_VMAX, 100000);
	//tmc5160_writeInt(MOTOR0, TMC5160_VMAX, 2000000);
	tmc5160_writeInt(MOTOR0, TMC5160_VMAX, 6000000);
	//tmc5160_writeInt(MOTOR0, TMC5160_DMAX, 5000);
	tmc5160_writeInt(MOTOR0, TMC5160_DMAX, 50000);
	tmc5160_writeInt(MOTOR0, TMC5160_D1, 5000);
	tmc5160_writeInt(MOTOR0, TMC5160_VSTOP, 10);
	tmc5160_writeInt(MOTOR0, TMC5160_RAMPMODE, TMC5160_MODE_POSITION);

	// test xtarget
	printf("TMC5160_XACTUAL: 0x%08x\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));

	printf("moving to xtarget: %d\n", xtarget);

	tmc5160_writeInt(MOTOR0, TMC5160_XTARGET, xtarget);
	//XTARGET = 512000 -> 10 revolutions with micro step = 256

	while(tmc5160_readInt(MOTOR0, TMC5160_XACTUAL) != xtarget){
		delay(500000);
	}

	printf("TMC5160_XACTUAL: 0x%08x\n", tmc5160_readInt(MOTOR0, TMC5160_XACTUAL));

	printf("TMC5160_XENC: 0x%08x\n", tmc5160_readInt(MOTOR0, TMC5160_XENC));

	return 0;
}

void resetMotorDrivers(uint8 motor)
{
	if(!tmc5160_readInt(MOTOR0, TMC5160_VACTUAL))
	{
		/*
		digitalWrite(2, LOW); // Apply VCC_IO voltage to Motor 0
		delay(10);
		digitalWrite(2, HIGH); // Apply VCC_IO voltage to Motor 0
		delay(10);
		*/
		printf("Please reset TMC5160 by turn off/on VCC_IO\n");
	}
}

