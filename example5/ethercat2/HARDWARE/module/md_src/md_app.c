/**
  ******************************************************************************
  * @file    md_app.c
  * @author  gxf
  * @version V1.0.0
  * @date    2022.06.06
  * @brief   初始化文档
 ==============================================================================
 */



#include "bsp_sys.h"
#include "bsp_systick.h"
#include "bsp_time.h"
#include "md_ethercat.h"




/**
 * [bsp_init description]
 * @author Gxf
 * @dateTime 2021-10-13
 * @brief    [description] 底层硬件初始化
 * @note     [description]
 */
void bsp_init(void)
{
  sysTick_init();
  nvic_configuration();
  bsp_time1_init();
}

/**
 * [module_init description]
 * @author Gxf
 * @dateTime 2021-10-13
 * @brief    [description] 用户模块初始化
 * @note     [description]
 */
void module_init(void)
{
  ethercat_init();
}


