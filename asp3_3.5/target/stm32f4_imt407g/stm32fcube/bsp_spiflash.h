#ifndef __BSP_SPIFLASH_H__
#define __BSP_SPIFLASH_H__

/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* 类型定义 ------------------------------------------------------------------*/
/* 宏定义 --------------------------------------------------------------------*/
//#define  SPI_FLASH_ID                       0xEF3015     //W25X16   2MB
//#define  SPI_FLASH_ID                       0xEF4015	   //W25Q16   4MB
//#define  SPI_FLASH_ID                       0XEF4017     //W25Q64   8MB
#define  SPI_FLASH_ID                       0XEF4018     //W25Q128  16MB YS-F4Pro开发默认使用

/*
SPI1 GPIO Configuration of IMT407G
PG8     ------> SPI1_NSS
PB3     ------> SPI1_SCK
PB4     ------> SPI1_MISO
PB5     ------> SPI1_MOSI
*/

#define FLASH_SPIx                                 SPI1
#define FLASH_SPIx_RCC_CLK_ENABLE()                __HAL_RCC_SPI1_CLK_ENABLE()
#define FLASH_SPIx_RCC_CLK_DISABLE()               __HAL_RCC_SPI1_CLK_DISABLE()

#define FLASH_SPI_GPIO_ClK_ENABLE()                {__HAL_RCC_GPIOB_CLK_ENABLE();__HAL_RCC_GPIOG_CLK_ENABLE();}

#define FLASH_SPI_SCK_PORT                         GPIOB
#define FLASH_SPI_MISO_PORT                        GPIOB
#define FLASH_SPI_MOSI_PORT                        GPIOB

#define FLASH_SPI_SCK_PIN                          GPIO_PIN_3
#define FLASH_SPI_MISO_PIN                         GPIO_PIN_4
#define FLASH_SPI_MOSI_PIN                         GPIO_PIN_5

#define FLASH_SPI_CS_PORT                        GPIOG
#define FLASH_SPI_CS_PIN                           GPIO_PIN_8
#define FLASH_SPI_CS_ENABLE()                      HAL_GPIO_WritePin(FLASH_SPI_CS_PORT, FLASH_SPI_CS_PIN, GPIO_PIN_RESET)
#define FLASH_SPI_CS_DISABLE()                     HAL_GPIO_WritePin(FLASH_SPI_CS_PORT, FLASH_SPI_CS_PIN, GPIO_PIN_SET)

#define FLASH_SPI_AF                        GPIO_AF5_SPI1


/* 扩展变量 ------------------------------------------------------------------*/
extern SPI_HandleTypeDef hspiflash;

/* 函数声明 ------------------------------------------------------------------*/

#if 0
void BSP_SPIFlash_Init(void);
int BSP_SPIFlash_Makefs(void);
int BSP_SPIFlash_SimpleTest(void);
int BSP_SPIFlash_Test(void);
#endif

void SPI_FLASH_SectorErase(uint32_t SectorAddr);
void SPI_FLASH_BulkErase(void);
void SPI_FLASH_PageWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void SPI_FLASH_BufferWrite(uint8_t* pBuffer, uint32_t WriteAddr, uint16_t NumByteToWrite);
void SPI_FLASH_BufferRead(uint8_t* pBuffer, uint32_t ReadAddr, uint16_t NumByteToRead);
uint32_t SPI_FLASH_ReadID(void);
uint32_t SPI_FLASH_ReadDeviceID(void);
void SPI_FLASH_StartReadSequence(uint32_t ReadAddr);
void SPI_Flash_PowerDown(void);
void SPI_Flash_WAKEUP(void);

uint8_t SPI_FLASH_ReadByte(void);
uint8_t SPI_FLASH_SendByte(uint8_t byte);
void SPI_FLASH_WriteEnable(void);
void SPI_FLASH_WaitForWriteEnd(void);

#endif  /* __BSP_SPIFLASH_H__ */

/******************* (C) COPYRIGHT 2015-2020 硬石嵌入式开发团队 *****END OF FILE****/
