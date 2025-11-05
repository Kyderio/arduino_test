/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef USBD_OTP_ROM_H
#define USBD_OTP_ROM_H

/* Includes ------------------------------------------------------------------*/

#include "ameba_soc.h"
#include "usbd_hal_rom.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

typedef struct {
	u8 *otp_map;
	u8 *mfg_str;
	u8 *prod_str;
	u8 *sn_str;
	u16 vid;
	u16 pid;
	u8 mfg_str_len;
	u8 prod_str_len;
	u8 sn_str_len;
	u8 self_powered : 1;
	u8 remote_wakeup_en : 1;
	u8 otp_sn : 1;
	u8 otp_param : 1;
} USB_OTP_TypeDef;

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

u8 USB_OTP_Init(USB_OTP_TypeDef *otp);

#endif  /* USBD_OTP_ROM_H */

