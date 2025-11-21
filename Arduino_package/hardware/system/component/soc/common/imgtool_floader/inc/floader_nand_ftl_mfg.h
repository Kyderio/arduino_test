/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLOADER_NAND_FTL_MFG_H
#define _FLOADER_NAND_FTL_MFG_H

/* Includes ------------------------------------------------------------------*/

#include "floader_nand_ftl.h"

/* Exported defines ----------------------------------------------------------*/

#define NAND_MFG_DOSILICON	0xE5U
#define NAND_MFG_GIGADEVICE	0xC8U
#define NAND_MFG_MACRONIX	0xC2U
#define NAND_MFG_MICRON		0x2CU
#define NAND_MFG_WINBOND	0xEFU

/* Exported types ------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

u8 NAND_FTL_MfgInit(NAND_FTL_DeviceTypeDef *nand);

#endif // _FLOADER_NAND_FTL_MFG_H

