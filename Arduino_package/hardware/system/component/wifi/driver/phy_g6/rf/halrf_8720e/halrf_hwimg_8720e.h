/******************************************************************************
 *
 * Copyright(c) 2007 - 2020  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/
#ifndef _HALRF_HW_IMG_8720E_H_
#define _HALRF_HW_IMG_8720E_H_
#ifdef RF_8720E_SUPPORT

#define DONT_CARE_8720E	0xff

#define IF_8720E	0x8
#define ELSE_IF_8720E	0x9
#define ELSE_8720E	0xa
#define END_8720E	0xb
#define CHK_8720E	0x4

void halrf_config_8720e_nctl_reg(void);
void halrf_config_8720e_new_radio_a_reg(void);
void halrf_config_8720e_store_xtal_track(void);
void halrf_config_8720e_init_power_limit(void);
s8 halrf_config_8720e_power_limit_by_ch(
	u8 limit_rate, u8 regulation, u8 chnl);
s8 halrf_config_8720e_power_limit_ru_by_ch(
	u8 regulation, u8 bandwidth, u8 chnl);
u32 halrf_get_8720e_nctl_reg_ver(void);
u32 halrf_get_8720e_radio_reg_ver(void);

#endif
#endif /*  _HALRF_HW_IMG_8720E_H_ */
