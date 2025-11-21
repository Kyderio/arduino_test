/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLOADER_FW_UPDATE_H_
#define _FLOADER_FW_UPDATE_H_

#include "ameba_soc.h"

extern u32 sector_addr;
_LONG_CALL_ void UARTIMG_Write(char *ptr,  unsigned int wr_offset, unsigned int frame_size);
_LONG_CALL_ void UARTIMG_WritePageEmpty(char *ptr,  unsigned int wr_offset, unsigned int frame_size);
#endif  // end of "#define _FLOADER_FW_UPDATE_H_"

