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

#ifndef __HALRF_8721DA_H__
#define __HALRF_8721DA_H__

#define AVG_THERMAL_NUM_8721DA 4
#define MAX_PATH_NUM_8721DA 1
#define RF_T_METER_8721DA 0x42
#define DADCK_BK_REG 8


u8 halrf_thermal_read_8721da(u8 path);

void phy_lc_calibrate_8721da(void);

void phy_set_rf_path_switch_8721da(bool is_main);

void halrf_afedck_8721da(void);

void halrf_dis_cca_8721da(bool is_dis_cca);

void halrf_tx_pause_8721da(void);

void backup_bb_register_8721da(u32 *bb_backup, u32 *backup_bb_reg, u32 counter);

void restore_bb_register_8721da(u32 *bb_backup, u32 *backup_bb_reg, u32 counter);

void halrf_set_bt_rx_dck_8721da(void);

void halrf_sw_mode_rx_dck_8721da(void);

void halrf_set_rx_dck_8721da(void);

void halrf_rx_dck_8721da(void);
void halrf_rx_dck_enable_disable_8721da(bool is_enable);
void halrf_synk_8721da(void);
void halrf_lck_track_8721da(void);
void halrf_powertracking_thermal_8721da(void);
void halrf_xtaltracking_thermal_8721da(void);
void halrf_nctl_rst_8721da(void);
void halrf_bandedge_settings_8721da(u8 ch, u8 shape_idx, bool is_ofdm);
void halrf_lok_track_8721da(void);

#endif /*__HALRF_8721DA_H__*/
