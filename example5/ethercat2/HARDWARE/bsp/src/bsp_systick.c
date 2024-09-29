/*
 * @******************************************************************************: 
 * @Description: 底层驱动SYSTICK模块源文件
 * @Version: v1.0.0
 * @Autor: gxf
 * @Date: 2022-08-02 09:51:52
 * @LastEditors: gxf
 * @LastEditTime: 2022-08-03 11:15:11
 * @==============================================================================: 
 */

#include "bsp_systick.h"


static volatile u32 TimingDelay;
/**
 * @******************************************************************************: 
 * @func: [sysTick_init]
 * @description: 滴答定时器初始化
 * @note: 
 * @author: gxf
 * @param [*]
 * @return [*]
 * @==============================================================================: 
 */
void sysTick_init(void)
{
  if (SysTick_Config(SystemCoreClock / 1000000))//  SystemCoreClock
  { 
    while (1);
  }  
}

/**
 * @******************************************************************************: 
 * @func: [delay_us]
 * @description: 微妙延时
 * @note: 
 * @author: gxf
 * @param [u32] nTime 微妙数
 * @return [*]
 * @==============================================================================: 
 */
void delay_us(u32 nTime)
{ 
  TimingDelay = nTime;  

  while(TimingDelay != 0);
}

/**
 * @******************************************************************************: 
 * @func: [delay_ms]
 * @description: 毫秒延时
 * @note: 
 * @author: gxf
 * @param [u32] nTime 毫秒数
 * @return [*]
 * @==============================================================================: 
 */
void delay_ms(u32 nTime)
{ 
  TimingDelay = nTime*1000;  

  while(TimingDelay != 0);
}

/**
 * @******************************************************************************: 
 * @func: [TimingDelay_Decrement]
 * @description: 计数器
 * @note: 
 * @author: gxf
 * @param [*]
 * @return [*]
 * @==============================================================================: 
 */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}
