/*
* This source file is part of the EtherCAT Slave Stack Code licensed by Beckhoff Automation GmbH & Co KG, 33415 Verl, Germany.
* The corresponding license agreement applies. This hint shall not be removed.
*/

/**
 * \addtogroup Bootloader Bootloader Sample
 * @{
 */

/**
\file bootloader.h
\author EthercatSSC@beckhoff.com

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

#ifndef _BOOTLOADER_APPL_H_
#define _BOOTLOADER_APPL_H_

/*-----------------------------------------------------------------------------------------
------
------    Defines and Types
------
-----------------------------------------------------------------------------------------*/
UINT16 recv_RRQ(UINT16 MBXMEM * pName, UINT16 nameSize, UINT32 password, UINT16 maxBlockSize, UINT16 *pData);
UINT16 recv_ACK(UINT32 offset, UINT16 maxBlockSize, UINT16 *pData);
UINT16 recv_DATA(UINT16 MBXMEM * pData, UINT16 Size, BOOL bDataFollowing);
UINT16 recv_WRQ(UINT16 MBXMEM * pName, UINT16 nameSize, UINT32 password);


#endif //_BOOTLOADER_APPL_H_


#ifdef _BOOTLOADER_APPLICATION_
    #define PROTO
#else
    #define PROTO extern
#endif



#undef PROTO
/** @}*/
