/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
\addtogroup Bootloader Bootloader Sample
@{
*/

/**
\file Bootloader.c
\author EthercatSSC@beckhoff.com
\brief Implementation

\version 5.12

<br>Changes to version - :<br>
V5.12: file created
*/


/*-----------------------------------------------------------------------------------------
------
------    Includes
------
-----------------------------------------------------------------------------------------*/
#include "ecat_def.h"

#include "applInterface.h"


#define _BOOTLOADER_APPLICATION_
#include "bootloaderappl.h"
#undef _BOOTLOADER_APPLICATION_

#include"bootmode.h"



/*--------------------------------------------------------------------------------------
------
------    local types and defines
------
--------------------------------------------------------------------------------------*/
#define    MAX_FILE_NAME_SIZE    20

/** \brief  MAX_FILE_SIZE: Maximum file size */
#define MAX_FILE_SIZE                             2048

/*-----------------------------------------------------------------------------------------
------
------    local variables and constants
------
-----------------------------------------------------------------------------------------*/
UINT32           nFileWriteOffset;
CHAR             aFileName[MAX_FILE_NAME_SIZE];


#define PSWD   123456


UINT32 u32FileSize = 0;
UINT32 u32Appaddr = 0;

unsigned char foemotordata[MAX_FILE_SIZE];

/*-----------------------------------------------------------------------------------------
------
------    application specific functions
------
-----------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------------------
------
------    generic functions
------
-----------------------------------------------------------------------------------------*/
/**
 * @******************************************************************************: 
 * @func: [recv_RRQ]
 * @description: 接收到读请求信号调用函数
 * @note: 
 * @author: gxf
 * @param [UINT16 MBXMEM *] pName 请求的文件名
 * @param [UINT16] nameSize 请求的文件名长度
 * @param [UINT32] password 密钥
 * @param [UINT16] maxBlockSize 读取数据长度
 * @param [UINT16] *pData 读取数据的存储地址
 * @return [UINT16] 返回读取的数据的长度
 * @==============================================================================: 
 */
UINT16 recv_RRQ(UINT16 MBXMEM * pName, UINT16 nameSize, UINT32 password, UINT16 maxBlockSize, UINT16 *pData)
{
    UINT16 i = 0;
    UINT16 readsize = 0;
    CHAR aReadFileName[MAX_FILE_NAME_SIZE];

    /* 判断文件名长度 */
    if ((nameSize + 1) > MAX_FILE_NAME_SIZE)
    {
        return ECAT_FOE_ERRCODE_DISKFULL;
    }
    if(password != PSWD)
    {   
        /* 密钥无效 */
        return ECAT_FOE_ERRCODE_NORIGHTS;
    }
    /* 拷贝文件名到数组中 */
    MBXSTRCPY(aReadFileName, pName, nameSize);
    aReadFileName[nameSize] = '\0';
    /* 判断文件名 获取文件地址 文件长度 */
    u32FileSize = MAX_FILE_SIZE;
    /* 判断文件大小 */
    if (u32FileSize == 0)
    {
        return ECAT_FOE_ERRCODE_NOTFOUND;
    }
    readsize = maxBlockSize;
    if (u32FileSize < readsize)
    {
        readsize = (UINT16)u32FileSize;
    }
    memcpy((uint8_t *)pData,foemotordata,readsize);
    return readsize;
}

/**
 * @******************************************************************************: 
 * @func: [recv_ACK]
 * @description: 接收到应答信号的调用函数
 * @note: 
 * @author: gxf
 * @param [UINT32] offset 读取的地址的偏移量（相对于首次读取）
 * @param [UINT16] maxBlockSize 读取的数据长度
 * @param [UINT16] *pData 读取数据的存储地址
 * @return [UINT16] 返回读取的数据的长度
 * @==============================================================================: 
 */
UINT16 recv_ACK(UINT32 offset, UINT16 maxBlockSize, UINT16 *pData)
{
    UINT16 readsize = 0;
    
    /* 如果文件大小小于指针的偏移量，说明文件已经读完了*/
    if (u32FileSize < offset)
    {
        return 0;
    }

    /* 剩余未读取 */
    readsize = (UINT16)(u32FileSize - offset);
    /* 读取大小 */
    if (readsize > maxBlockSize)
    {
        readsize = maxBlockSize;
    }
    /* 读取文件 */
    memcpy((uint8_t *)pData,foemotordata+offset,readsize);
    return readsize;
}

/**
 * @******************************************************************************: 
 * @func: [recv_WRQ]
 * @description: 接收到写请求的调用函数
 * @note: 
 * @author: gxf
 * @param [UINT16 MBXMEM *] pName 待写文件的名字
 * @param [UINT16] nameSize 名字长度
 * @param [UINT32] password 密钥
 * @return [*] 0:正确；其他:错误
 * @==============================================================================: 
 */
UINT16 recv_WRQ(UINT16 MBXMEM * pName, UINT16 nameSize, UINT32 password)
{
    if(password != PSWD)
    {   
        /* 密钥无效 */
        return ECAT_FOE_ERRCODE_NORIGHTS;
    }
    /* 擦除flash等待写入 等待使用*/
    memset(foemotordata,0,MAX_FILE_SIZE);
    nFileWriteOffset = 0;
    u32FileSize = 0;
    return 0;
}


/**
 * @******************************************************************************: 
 * @func: [recv_DATA]
 * @description: 接收到数据包的调用函数
 * @note: 
 * @author: gxf
 * @param [UINT16 MBXMEM *] pData 带写入数据的地址
 * @param [UINT16] Size 写入数据的长度
 * @param [BOOL] bDataFollowing 后面是否还有数据
 * @return [*] 0:正确；其他:错误
 * @==============================================================================: 
 */
UINT16 recv_DATA(UINT16 MBXMEM * pData, UINT16 Size, BOOL bDataFollowing)
{

    if ((nFileWriteOffset + Size) > MAX_FILE_SIZE)
    {
        return ECAT_FOE_ERRCODE_DISKFULL;
    }

    if (Size)
    {
        /* 写flash */
		memcpy(foemotordata+nFileWriteOffset,(uint8_t *)pData,Size);	  
    }
    /* 后面是否还有数据 */
    if (bDataFollowing)
    {
        nFileWriteOffset += Size;
    }
    else
    {
        /* 最后一包数据 计算总的接收文件长度 */
        u32FileSize = nFileWriteOffset + Size;
        nFileWriteOffset = 0;           
    }

    return 0;
}



/** @} */

