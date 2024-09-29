/*
 * @******************************************************************************: 
 * @Description: 
 * @Version: v1.0.0
 * @Autor: gxf
 * @Date: 2023-05-26 17:03:19
 * @LastEditors: gxf
 * @LastEditTime: 2023-05-26 17:03:20
 * @==============================================================================: 
 */
#ifndef _MD_ETHER_H_
#define _MD_ETHER_H_
#include "stm32f4xx.h" 
//#include "myapp.h"


void ethercat_timer_init(void);
void ethercat_gpio_init(void);
void ethercat_sync0_init(void);
void ethercat_sync1_init(void);
void ethercat_pdi_init(void);
u8 ethercat_data_rw(u8 data);
void ethercat_init(void);
void ethercat_loop(void);

#endif