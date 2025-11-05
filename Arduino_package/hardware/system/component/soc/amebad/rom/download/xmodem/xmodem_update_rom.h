/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FW_UPDATE_ROM_H_
#define _FW_UPDATE_ROM_H_

#include "ameba_soc.h"

#define BOOT_UART_IDX           0
#define BOOT_UART_PIN_MUX       1
#define BOOT_UART_BAUD_RATE     38400
#define BOOT_UART_MAX_IMG_SZ    (32*1024*1024)      // 32M

extern void xmodem_img_write(char *ptr,  unsigned int wr_offset, unsigned int frame_size);
extern void xmodem_img_download(u8 uart_idx);

#endif  // end of "#define _FW_UPDATE_ROM_H_"

