/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef USBD_DBG_ROM_H
#define USBD_DBG_ROM_H

/* Includes ------------------------------------------------------------------*/

#include "ameba_soc.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

void USBD_DebugInit(void);
void USBD_Debug(u32 code, u32 delay);
void USBD_Debug_Config(u8 enable);

#endif /* USBD_DBG_ROM_H */

