/*
 * @******************************************************************************: 
 * @Description: 底层驱动模块源文件
 * @Version: v1.0.0
 * @Autor: gxf
 * @Date: 2022-08-02 09:48:29
 * @LastEditors: gxf
 * @LastEditTime: 2022-08-04 17:20:55
 * @==============================================================================: 
 */

#include "bsp_time.h"

/**
 * @******************************************************************************: 
 * @func: [bsp_time1_init]
 * @description: 定时器1初始化
 * @note: 
 * @author: gxf
 * @param [*]
 * @return [*]
 * @==============================================================================: 
 */ 
void bsp_time1_init(void)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); 

  /* 累计 TIM_Period个后产生一个更新或者中断*/		
  TIM_TimeBaseStructure.TIM_Period = 1000;       
  /* 预分频系数 */ 
  TIM_TimeBaseStructure.TIM_Prescaler = 168;	
  /* 采样时钟分频 */
  TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
  /* 计数方式 */
  TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
  /* 重复计数器:重复0次，本次溢出后，再溢出0次就进入中断 */
  TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	

  /* 初始化定时器TIMx, x[1,8] */
  TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
  /* 清除定时器更新中断标志位 */
  TIM_ClearFlag(TIM1, TIM_FLAG_Update);
  /* 开启定时器更新中断 */
  TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);
  /* 使能定时器 */
  TIM_Cmd(TIM1, ENABLE);  
}
