/*
 * @******************************************************************************: 
 * @Description: 
 * @Version: v1.0.0
 * @Autor: gxf
 * @Date: 2023-05-26 17:03:27
 * @LastEditors: gxf
 * @LastEditTime: 2023-05-26 18:20:24
 * @==============================================================================: 
 */
#include "md_ethercat.h"
#include "bsp_time.h"
#include "ecatport.h"
#include "myapp.h"
#include "bsp_spi.h"
#include "applInterface.h"
/**
 * @******************************************************************************: 
 * @func: [ethercat_timer_init]
 * @description: ethercat定时器初始化
 * @note: 
 * @author: gxf
 * @return [*]
 * @==============================================================================: 
 */
void ethercat_timer_init(void)
{
    bsp_time1_init();
}

/**
 * @******************************************************************************: 
 * @func: [ethercat_sync0_init]
 * @description: SYNC0引脚初始化
 * @note: 
 * @author: gxf
 * @return [*]
 * @==============================================================================: 
 */
void ethercat_sync0_init(void)
{
  EXTI_InitTypeDef   EXTI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
  EXTI_InitStructure.EXTI_Line = EXTI_Line0;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

}

/**
 * @******************************************************************************: 
 * @func: [ethercat_sync1_init]
 * @description: SYNC1 引脚初始化
 * @note: 
 * @author: gxf
 * @return [*]
 * @==============================================================================: 
 */
void ethercat_sync1_init(void)
{
  EXTI_InitTypeDef   EXTI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1);

  EXTI_InitStructure.EXTI_Line = EXTI_Line1;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
}

/**
 * @******************************************************************************: 
 * @func: [ethercat_pdi_init]
 * @description: PDI引脚初始化
 * @note: 
 * @author: gxf
 * @return [*]
 * @==============================================================================: 
 */
void ethercat_pdi_init(void)
{
  EXTI_InitTypeDef   EXTI_InitStructure;
  GPIO_InitTypeDef   GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource8);

  EXTI_InitStructure.EXTI_Line = EXTI_Line8;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

}

/**
 * @******************************************************************************: 
 * @func: [ethercat_data_rw]
 * @description: PDI接口读写函数
 * @note: 
 * @author: gxf
 * @param [u8] data 待写入的数据
 * @return [*] 读取的数据
 * @==============================================================================: 
 */
u8 ethercat_data_rw(u8 data)
{
    return spi_data_rw(data);
}

/**
 * @******************************************************************************: 
 * @func: [ethercat_init]
 * @description: Ethercat硬件初始化
 * @note: 
 * @author: gxf
 * @return [*]
 * @==============================================================================: 
 */
void ethercat_init(void)
{
    HW_Init();
    MainInit();    
}
/**
 * @******************************************************************************: 
 * @func: [ethercat_loop]
 * @description: Ethercat轮询
 * @note: 
 * @author: gxf
 * @return [*]
 * @==============================================================================: 
 */
void ethercat_loop(void)
{
    MainLoop();
}
