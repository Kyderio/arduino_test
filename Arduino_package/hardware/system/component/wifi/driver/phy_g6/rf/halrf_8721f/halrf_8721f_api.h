/******************************************************************************
 *
 * Copyright(c) 2007 - 2021  Realtek Corporation.
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
#ifndef __HALRF_8721F_API_H__
#define __HALRF_8721F_API_H__
#ifdef RF_8721F_SUPPORT

u8 halrf_get_thermal_8721f(void);

u32 halrf_mac_get_pwr_reg_8721f(u32 addr, u32 mask);

int halrf_mac_set_pwr_reg_8721f(
	u32 addr, u32 mask, u32 val);

bool halrf_wl_tx_power_control_8721f(u32 tx_power_val);

/*
void halrf_wlan_tx_power_control_8721f(
	enum phl_phy_idx phy, enum phl_pwr_ctrl pwr_ctrl_idx,
	u32 tx_power_val, bool enable);

s8 halrf_get_ther_protected_threshold_8721f(void);
s8 halrf_xtal_tracking_offset_8721f(enum phl_phy_idx phy);
void halrf_bt_ultra_low_pwr_adv_8721f(void);
*/
#endif
#endif /*  __INC_PHYDM_API_H_8721F__ */
