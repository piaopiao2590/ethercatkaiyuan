/*
 * @******************************************************************************: 
 * @Description: 
 * @Version: v1.0.0
 * @Autor: gxf
 * @Date: 2023-05-26 17:07:07
 * @LastEditors: gxf
 * @LastEditTime: 2023-05-26 19:19:00
 * @==============================================================================: 
 */
#ifndef _BSP_SPI_H_
#define _BSP_SPI_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"


  #define SPIx                           SPI2
  #define SPIx_CLK                       RCC_APB1Periph_SPI2
  #define SPIx_CLK_INIT                  RCC_APB1PeriphClockCmd

  #define SPIx_SCK_PIN                   GPIO_Pin_10
  #define SPIx_SCK_GPIO_PORT             GPIOB
  #define SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
  #define SPIx_SCK_SOURCE                GPIO_PinSource10
  #define SPIx_SCK_AF                    GPIO_AF_SPI2

  #define SPIx_MISO_PIN                  GPIO_Pin_2
  #define SPIx_MISO_GPIO_PORT            GPIOC
  #define SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOC
  #define SPIx_MISO_SOURCE               GPIO_PinSource2
  #define SPIx_MISO_AF                   GPIO_AF_SPI2

  #define SPIx_MOSI_PIN                  GPIO_Pin_3
  #define SPIx_MOSI_GPIO_PORT            GPIOC
  #define SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOC
  #define SPIx_MOSI_SOURCE               GPIO_PinSource3
  #define SPIx_MOSI_AF                   GPIO_AF_SPI2






void bsp_spi3_init(void);
u8 spi_data_rw(u8 data);
#endif