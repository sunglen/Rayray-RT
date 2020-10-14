/** 
  ******************************************************************************
  * @file    stm32f4xx_nucleo.h
  * @author  MCD Application Team
  * @version V1.2.2
  * @date    14-August-2015
  * @brief   This file contains definitions for:
  *          - LEDs and push-button available on STM32F4XX-Nucleo Kit 
  *            from STMicroelectronics
  *          - LCD, joystick and microSD available on Adafruit 1.8" TFT LCD 
  *            shield (reference ID 802)
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2015 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************  
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4XX_NUCLEO_H
#define __STM32F4XX_NUCLEO_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
   
/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32F4XX_NUCLEO
  * @{
  */

/** @addtogroup STM32F4XX_NUCLEO_LOW_LEVEL
  * @{
  */ 

/** @defgroup STM32F4XX_NUCLEO_LOW_LEVEL_Exported_Types
  * @{
  */
typedef enum 
{
  LED0 = 0,
  LED1 = 1,
  LED2 = 2,
}Led_TypeDef;

typedef enum 
{  
  BUTTON_KEY0 = 0,
  BUTTON_KEY1 = 1,
  BUTTON_KEY2 = 2,
  BUTTON_KEY3 = 3,
  /* Alias */
  BUTTON_USER  = BUTTON_KEY0,
} Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
}ButtonMode_TypeDef;

typedef enum 
{ 
  CNC_NONE  = 0,
  CNC_SET = 1,

}CNCState_TypeDef;

typedef enum
{
  JOY_NONE  = 0,
  JOY_SEL   = 1,
  JOY_DOWN  = 2,
  JOY_LEFT  = 3,
  JOY_RIGHT = 4,
  JOY_UP    = 5
}JOYState_TypeDef;

/**
  * @}
  */ 

/** @defgroup STM32F4XX_NUCLEO_LOW_LEVEL_Exported_Constants
  * @{
  */ 

/** 
  * @brief Define for STM32F4XX_NUCLEO board  
  */ 
#if !defined (USE_STM32F4XX_NUCLEO)
 #define USE_STM32F4XX_NUCLEO
#endif

/** @addtogroup STM32F4XX_NUCLEO_LOW_LEVEL_LED
  * @{
  */
#define LEDn                                    3

#define LED0_PIN                                GPIO_PIN_9
#define LED0_GPIO_PORT                          GPIOH
#define LED0_GPIO_CLK_ENABLE()                  __GPIOH_CLK_ENABLE()
#define LED0_GPIO_CLK_DISABLE()                 __GPIOH_CLK_DISABLE()

#define LED1_PIN                                GPIO_PIN_5
#define LED1_GPIO_PORT                          GPIOE
#define LED1_GPIO_CLK_ENABLE()                  __GPIOE_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE()                 __GPIOE_CLK_DISABLE()

#define LED2_PIN                                GPIO_PIN_6
#define LED2_GPIO_PORT                          GPIOE
#define LED2_GPIO_CLK_ENABLE()                  __GPIOE_CLK_ENABLE()
#define LED2_GPIO_CLK_DISABLE()                 __GPIOE_CLK_DISABLE()

#define LEDx_GPIO_CLK_ENABLE(__INDEX__)    do{if((__INDEX__) == 0) LED0_GPIO_CLK_ENABLE(); \
                                              if((__INDEX__) == 1) LED1_GPIO_CLK_ENABLE(); \
                                              if((__INDEX__) == 2) LED2_GPIO_CLK_ENABLE(); \
                                             }while(0)
#define LEDx_GPIO_CLK_DISABLE(__INDEX__)    do{if((__INDEX__) == 0) LED0_GPIO_CLK_DISABLE(); \
                                               if((__INDEX__) == 1) LED1_GPIO_CLK_DISABLE(); \
                                               if((__INDEX__) == 2) LED2_GPIO_CLK_DISABLE(); \
                                              }while(0)
/**
  * @}
  */ 
  
/** @addtogroup STM32F4XX_NUCLEO_LOW_LEVEL_BUTTON
  * @{
  */  
#define BUTTONn                                 1

/**
  * @brief Key push-button
  */
#define BUTTON_KEY0_PIN                         GPIO_PIN_0
#define BUTTON_KEY0_GPIO_PORT                   GPIOE
#define BUTTON_KEY0_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOE_CLK_ENABLE()
#define BUTTON_KEY0_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOE_CLK_DISABLE()
#define BUTTON_KEY0_EXTI_LINE                   GPIO_PIN_0
#define BUTTON_KEY0_EXTI_IRQn                   EXTI0_IRQn
/* Aliases */
#define KEY_BUTTON_PIN                          BUTTON_KEY0_PIN
#define KEY_BUTTON_GPIO_PORT                    BUTTON_KEY0_GPIO_PORT
#define KEY_BUTTON_GPIO_CLK_ENABLE()            BUTTON_KEY0_GPIO_CLK_ENABLE()
#define KEY_BUTTON_GPIO_CLK_DISABLE()           BUTTON_KEY0_GPIO_CLK_DISABLE()
#define KEY_BUTTON_EXTI_LINE                    BUTTON_KEY0_EXTI_LINE
#define KEY_BUTTON_EXTI_IRQn                    BUTTON_KEY0_EXTI_IRQn


#define BUTTONx_GPIO_CLK_ENABLE(__BUTTON__)    do { if((__BUTTON__) == BUTTON_KEY0) { BUTTON_KEY0_GPIO_CLK_ENABLE(); } } while(0)

#define BUTTONx_GPIO_CLK_DISABLE(__BUTTON__)   do { if((__BUTTON__) == BUTTON_KEY0) { BUTTON_KEY0_GPIO_CLK_DISABLE(); } } while(0)
/**
  * @}
  */ 

/** @addtogroup STM32F4XX_NUCLEO_LOW_LEVEL_BUS
  * @{
  */
/*############################### SPI1 #######################################*/
#define NUCLEO_SPIx                                     SPI1
#define NUCLEO_SPIx_CLK_ENABLE()                        __SPI1_CLK_ENABLE()

#define NUCLEO_SPIx_SCK_AF                              GPIO_AF5_SPI1
#define NUCLEO_SPIx_SCK_GPIO_PORT                       GPIOA
#define NUCLEO_SPIx_SCK_PIN                             GPIO_PIN_5
#define NUCLEO_SPIx_SCK_GPIO_CLK_ENABLE()               __GPIOA_CLK_ENABLE()
#define NUCLEO_SPIx_SCK_GPIO_CLK_DISABLE()              __GPIOA_CLK_DISABLE()

#define NUCLEO_SPIx_MISO_MOSI_AF                        GPIO_AF5_SPI1
#define NUCLEO_SPIx_MISO_MOSI_GPIO_PORT                 GPIOB
#define NUCLEO_SPIx_MISO_MOSI_GPIO_CLK_ENABLE()         __GPIOB_CLK_ENABLE()
#define NUCLEO_SPIx_MISO_MOSI_GPIO_CLK_DISABLE()        __GPIOB_CLK_DISABLE()
#define NUCLEO_SPIx_MISO_PIN                            GPIO_PIN_4
#define NUCLEO_SPIx_MOSI_PIN                            GPIO_PIN_5
/* Maximum Timeout values for flags waiting loops. These timeouts are not based
   on accurate values, they just guarantee that the application will not remain
   stuck if the SPI communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */   
#define NUCLEO_SPIx_TIMEOUT_MAX                   1000

#define TMC_SPI_CS_PORT                          GPIOC
#define TMC_SPI_CS_PIN                           GPIO_PIN_13
#define TMC_SPI_CS_ENABLE()                      HAL_GPIO_WritePin(TMC_SPI_CS_PORT, TMC_SPI_CS_PIN, GPIO_PIN_RESET)
#define TMC_SPI_CS_DISABLE()                     HAL_GPIO_WritePin(TMC_SPI_CS_PORT, TMC_SPI_CS_PIN, GPIO_PIN_SET)
#define TMC_SPI_CS_GPIO_CLK_ENABLE()             __GPIOC_CLK_ENABLE()
#define TMC_SPI_CS_GPIO_CLK_DISABLE()            __GPIOC_CLK_DISABLE()

void TMC_SPI_Init(void);
void TMC_SPI_WriteNBytes(char *tbuf, int len);
void TMC_SPI_ReadNBytes(char *tbuf, char *rbuf, int len);

/**
  * @brief  SD Control Lines management
  */
#define SD_CS_LOW()       HAL_GPIO_WritePin(SD_CS_GPIO_PORT, SD_CS_PIN, GPIO_PIN_RESET)
#define SD_CS_HIGH()      HAL_GPIO_WritePin(SD_CS_GPIO_PORT, SD_CS_PIN, GPIO_PIN_SET)

/**
  * @brief  LCD Control Lines management
  */
#define LCD_CS_LOW()      HAL_GPIO_WritePin(LCD_CS_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_RESET)
#define LCD_CS_HIGH()     HAL_GPIO_WritePin(LCD_CS_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_SET)
#define LCD_DC_LOW()      HAL_GPIO_WritePin(LCD_DC_GPIO_PORT, LCD_DC_PIN, GPIO_PIN_RESET)
#define LCD_DC_HIGH()     HAL_GPIO_WritePin(LCD_DC_GPIO_PORT, LCD_DC_PIN, GPIO_PIN_SET)
     
/**
  * @brief  SD Control Interface pins
  */
#define SD_CS_PIN                                 GPIO_PIN_5
#define SD_CS_GPIO_PORT                           GPIOB
#define SD_CS_GPIO_CLK_ENABLE()                 __GPIOB_CLK_ENABLE()
#define SD_CS_GPIO_CLK_DISABLE()                __GPIOB_CLK_DISABLE()

/**
  * @brief  LCD Control Interface pins
  */
#define LCD_CS_PIN                                 GPIO_PIN_6
#define LCD_CS_GPIO_PORT                           GPIOB
#define LCD_CS_GPIO_CLK_ENABLE()                 __GPIOB_CLK_ENABLE()
#define LCD_CS_GPIO_CLK_DISABLE()                __GPIOB_CLK_DISABLE()
    
/**
  * @brief  LCD Data/Command Interface pins
  */
#define LCD_DC_PIN                                 GPIO_PIN_9
#define LCD_DC_GPIO_PORT                           GPIOA
#define LCD_DC_GPIO_CLK_ENABLE()                 __GPIOA_CLK_ENABLE()
#define LCD_DC_GPIO_CLK_DISABLE()                __GPIOA_CLK_DISABLE()

/*################################ ADC1 ######################################*/
/**
  * @brief  ADC Interface pins
  *         used to detect motion of CNC Analog in
  */
#define NUCLEO_ADCx                                 ADC1
#define NUCLEO_ADCx_CLK_ENABLE()                  __ADC1_CLK_ENABLE()

#define NUCLEO_ADCx_CHANNEL                       ADC_CHANNEL_8
   
#define NUCLEO_ADCx_GPIO_PORT                       GPIOB
#define NUCLEO_ADCx_GPIO_PIN                        GPIO_PIN_0
#define NUCLEO_ADCx_GPIO_CLK_ENABLE()             __GPIOB_CLK_ENABLE()
#define NUCLEO_ADCx_GPIO_CLK_DISABLE()            __GPIOB_CLK_DISABLE()
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup STM32F4XX_NUCLEO_LOW_LEVEL_Exported_Macros
  * @{
  */  
/**
  * @}
  */ 

/** @defgroup STM32F4XX_NUCLEO_LOW_LEVEL_Exported_Functions
  * @{
  */
uint32_t         BSP_GetVersion(void);  
void             BSP_LED_Init(Led_TypeDef Led);
void             BSP_LED_On(Led_TypeDef Led);
void             BSP_LED_Off(Led_TypeDef Led);
void             BSP_LED_Toggle(Led_TypeDef Led);
uint32_t BSP_LED_GetState(Led_TypeDef Led);
void             BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode);
uint32_t         BSP_PB_GetState(Button_TypeDef Button);
uint8_t          BSP_JOY_Init(void);
JOYState_TypeDef BSP_JOY_GetState(void);
uint8_t          BSP_CNCAnalog_Init(void);
uint16_t         BSP_CNCAnalog_GetValue(void);
CNCState_TypeDef BSP_CNCAnalog_GetState(void);
/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */

/*
 *  USART BLE 関連の定義
 */
#define USART_BLE_INTNO (UART4_IRQn + 16)
#define USART_BLE_NAME  UART4
#define USART_BLE_BASE  UART4_BASE

/*
 *  ボーレート
 */
#define BPS_SETTING_BLE  (9600)

#define BLE_USARTx_RCC_CLK_ENABLE()                 __HAL_RCC_UART4_CLK_ENABLE()
#define BLE_USARTx_RCC_CLK_DISABLE()                __HAL_RCC_UART4_CLK_DISABLE()

#define BLE_USARTx_GPIO_ClK_ENABLE()               __HAL_RCC_GPIOC_CLK_ENABLE()
#define BLE_USARTx_PORT                            GPIOC
#define BLE_USARTx_Tx_PIN                          GPIO_PIN_10
#define BLE_USARTx_Rx_PIN                          GPIO_PIN_11
#define BLE_USARTx_Tx_AF GPIO_AF8_UART4
#define BLE_USARTx_Rx_AF GPIO_AF8_UART4

void BLE_USARTx_Init(void);

#define ETH_INTNO (ETH_IRQn + 16)

#define I2C_INTNO (EXTI1_IRQn + 16)

#define ENC_INTNO (KEY_BUTTON_EXTI_IRQn + 16)

#define I2C_NEW_INTNO (EXTI2_IRQn + 16)

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4XX_NUCLEO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
