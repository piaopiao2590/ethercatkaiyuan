/*
 * @******************************************************************************: 
 * @Description: 小远机器人底层驱动SYSTICK模块头文件
 * @Version: v1.0.0
 * @Autor: gxf
 * @Date: 2022-08-02 09:51:41
 * @LastEditors: gxf
 * @LastEditTime: 2022-08-03 11:15:49
 * @==============================================================================: 
 */
#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H
#include "stm32f4xx.h"
 
void sysTick_init(void);  
void delay_us(u32 nTime);
void delay_ms(u32 nTime);
void TimingDelay_Decrement(void);

#endif
