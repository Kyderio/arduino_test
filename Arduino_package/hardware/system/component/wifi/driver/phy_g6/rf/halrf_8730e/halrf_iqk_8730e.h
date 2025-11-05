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
#ifndef __HALRF_IQK_8730EH__
#define __HALRF_IQK_8730EH__
#ifdef RF_8730E_SUPPORT

#define iqk_version_8730e 0xF
#define ss_8730e 1
#define IQK_THR_ReK 0x20

//void iqk_init_8730e(void);
void iqk_preset_8730e(void);
void iqk_txtone_8730e(void);
void iqk_afebb_restore_8730e(void);
void iqk_macbb_setting_8730e(void);
bool halrf_iqk_get_ther_rek_8730e(void);
void halrf_iq_calibrate_8730e(enum phl_phy_idx phy_idx);
bool _iqk_lok_group_8730e(void);
//void halrf_lo_calibrate_8730e(enum phl_phy_idx phy_idx);
#endif
#endif /*  __HALRF_IQK_8730EH__ */

