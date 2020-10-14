#ifndef __SMBUS_H
#define __SMBUS_H

#include "stm32f4xx_hal.h"
#include <kernel.h>

#define ACK	 0 //应答
#define	NACK 1 //无应答
#define SA				0x00 //Slave address 单个MLX90614时地址为0x00,多个时地址默认为0x5a
#define RAM_ACCESS		0x00
//RAM access command RAM存取命令
#define EEPROM_ACCESS	0x20 //EEPROM access command EEPROM存取命令
#define RAM_TOBJ1		0x07 //To1 address in the eeprom 目标1温度,检测到的红外温度 -70.01 ~ 382.19度

#define SMBUS_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOD_CLK_ENABLE()

#define SDA_IN()  {GPIOD->MODER&=~(3<<(5*2));GPIOD->MODER|=0<<5*2;}
#define SDA_OUT() {GPIOD->MODER&=~(3<<(5*2));GPIOD->MODER|=1<<5*2;}

#define SMBUS_SDA_PIN     GPIO_PIN_9
#define SMBUS_SCL_PIN     GPIO_PIN_10
#define SMBUS_PORT    GPIOD

#define GPIOD_ODR_Addr    (GPIOD_BASE+20) //0x40021814
#define GPIOD_IDR_Addr    (GPIOD_BASE+16) //0x40021810
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

#define PDout(n)   BIT_ADDR(GPIOD_ODR_Addr,n)  //输出
#define PDin(n)    BIT_ADDR(GPIOD_IDR_Addr,n)  //输入

#define SMBUS_SDA   PDout(9)
#define SMBUS_SCL   PDout(10)
#define READ_SDA    PDin(9)

void BSP_SMBUS_Init(void);
float BSP_SMBUS_ReadTemp(void);
void SMBUS_Start(void);
void SMBUS_Stop(void);
u8 SMBUS_Wait_Ack(void);
void SMBUS_Ack(void);
void SMBUS_NAck(void);
u8 SMBus_SendByte(u8 Tx_buffer);
void SMBus_SendBit(u8 bit_out);
u8 SMBus_ReceiveBit(void);
u8 SMBus_ReceiveByte(u8 ack_nack);
u16 SMBus_ReadMemory(u8 slaveAddress, u8 command);
u8 PEC_Calculation(u8 pec[]);
float SMBus_ReadTemp(void);


#endif
