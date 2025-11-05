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
#ifndef __HALRF_8721F_H__
#define __HALRF_8721F_H__
#ifdef RF_8721F_SUPPORT

//#define RXDCK_VER_8721F 0x1
//#define RCK_VER_8721F 0x1

//#define LCK_TH_8721F 0x20
void halrf_set_bias_for_ch11_8721f(void);
void halrf_lo_test_8721f(bool is_on);
void halrf_set_singletone_8721f(bool is_on);
void halrf_rxdck_track_8721f(void);
void halrf_set_rx_dck_8721f(bool is_Wifi, bool is_Amode);
void halrf_rx_dck_8721f(bool is_afe);
void halrf_xtal_tracking_8721f(void);
//extern struct rfk_iqk_info rf_iqk_hwspec_8721f;
bool halrf_ctrl_ch_8721f(u8 central_ch, enum rtw_band_type band);
bool halrf_ctrl_bw_8721f(enum channel_width bw);
#if 0
void halrf_rx_dck_onoff_8721f(bool is_enable);
void halrf_rck_8721f(void)
void halrf_bf_config_rf_8721f(void);
void halrf_dpk_init_8721f(void);
void halrf_rxbb_bw_8721f(enum phl_phy_idx phy, enum channel_width bw);
void halrf_fw_ntfy_8721f(enum phl_phy_idx phy_idx);
void halrf_disconnect_notify_8721f(struct rtw_chan_def *chandef) ;
bool halrf_check_mcc_ch_8721f(struct rtw_chan_def *chandef) ;
void halrf_quick_checkrf_8721f(void);
void halrf_before_one_shot_enable_8721f(void);
bool halrf_one_shot_nctl_done_check_8721f(enum rf_path path);
#endif
void halrf_synk_8721f(void);
void halrf_lck_8721f(void);
void halrf_lck_tracking_8721f(void);
void halrf_aack_8721f(void);
void halrf_lok_tracking_8721f(void);
#endif
#endif /*  __HALRF_8721f_H__ */
