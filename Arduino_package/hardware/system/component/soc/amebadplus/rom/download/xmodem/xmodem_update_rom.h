/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FW_UPDATE_ROM_H_
#define _FW_UPDATE_ROM_H_

#include "ameba_soc.h"

extern void xmodem_img_write(char *ptr,  u32 wr_offset, u32 frame_size);
extern void xmodem_img_download(void);

#endif  // end of "#define _FW_UPDATE_ROM_H_"

