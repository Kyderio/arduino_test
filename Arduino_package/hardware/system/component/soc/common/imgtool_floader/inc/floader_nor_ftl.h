/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLOADER_NOR_FTL_H
#define _FLOADER_NOR_FTL_H

/* Includes ------------------------------------------------------------------*/

#include "floader_flash_ftl.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

void NOR_FTL_Init(void);
void NOR_FTL_Query(Flash_InfoTypeDef *info);
void NOR_FTL_ReadPage(u32 addr, u8 *buf);
void NOR_FTL_EraseBlock(u32 addr, u32 size);
void NOR_FTL_WritePage(u32 addr, const u8 *buf);
u16 NOR_FTL_GetStatus(u8 cmd, u8 size);
void NOR_FTL_SetStatus(u8 cmd, u8 size, u8 *status);

#endif // _FLOADER_NOR_FTL_H

