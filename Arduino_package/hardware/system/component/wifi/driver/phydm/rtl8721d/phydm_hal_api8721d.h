/******************************************************************************
 *
 * Copyright(c) 2007 - 2017  Realtek Corporation.
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
#ifndef __INC_PHYDM_API_H_8721D__
#define __INC_PHYDM_API_H_8721D__

#if defined(CONFIG_AMEBAD)

#define PHY_CONFIG_VERSION_8721D "0.0.0" /*2018.05.02*/

#define INVALID_RF_DATA 0xffffffff
#define INVALID_TXAGC_DATA 0xff

#define config_phydm_read_rf_check_8721d(data) ((data) != INVALID_RF_DATA)
#define config_phydm_read_txagc_check_8721d(data) ((data) != INVALID_TXAGC_DATA)


s8 phydm_cckrssi_8721d(u8 lna_idx, u8 vga_idx);

u32 config_phydm_read_rf_reg_8721d(enum rf_path path, u32 reg_addr, u32 bit_mask);
bool config_phydm_write_rf_reg_8721d(enum rf_path path, u32 reg_addr,
				u32 bit_mask,
				u32 data);

bool config_phydm_write_txagc_8721d(u32 power_index, enum rf_path path, u8 hw_rate);

u8 config_phydm_read_txagc_8721d(enum rf_path path, u8 hw_rate);

bool config_phydm_switch_band_8721d(u8 central_ch);

bool config_phydm_switch_channel_8721d(u8 central_ch);

bool config_phydm_switch_bandwidth_8721d(u8 primary_ch_idx,
				    enum channel_width bandwidth);

bool config_phydm_switch_channel_bw_8721d(u8 central_ch,
		u8 primary_ch_idx,
		enum channel_width bandwidth);

bool config_phydm_parameter_init_8721d(enum odm_parameter_init type);
void config_phydm_tx_filter_modify_8721d(void);

#endif /* CONFIG_AMEBAD */
#endif /*  __INC_PHYDM_API_H_8721D__ */
