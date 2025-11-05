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

#ifndef __HALRF_EX_H__
#define __HALRF_EX_H__

struct rf_info;

/**************halrf.c**************/
void halrf_watchdog(void);
void halrf_ability_set_xtal_track(u8 enable);
int halrf_chl_rfk_trigger(
	enum phl_phy_idx phy_idx,
	bool force);
void halrf_dack_trigger(bool force);
void halrf_rx_dck_trigger(
	enum phl_phy_idx phy_idx, bool is_afe);
void halrf_iqk_trigger(enum phl_phy_idx phy_idx);
void halrf_iqk_trigger_start(
	enum phl_phy_idx phy_idx);
void halrf_spur_compensation(void);
void halrf_set_bias(void);
void halrf_synk_trigger(void);
void halrf_lck_trigger(void);
void halrf_rck_trigger(void);
void halrf_lck_tracking(void);
//void halrf_lok_trigger(enum phl_phy_idx phy_idx);
void halrf_lok_tracking(void);
void halrf_rx_dck_8730e_restore(void);
#ifndef CONFIG_MP_SHRINK
void halrf_dbg_log_print(void);
void halrf_dbg_watchdog_print(void);
#endif
void halrf_dpk_trigger(
	enum phl_phy_idx phy_idx,
	bool force);
void halrf_tssi_trigger(enum phl_phy_idx phy_idx);
void halrf_do_tssi_scan(enum phl_phy_idx phy_idx);
void halrf_do_tssi_init(void);

void halrf_gapk_trigger(enum phl_phy_idx phy_idx);
void halrf_dpk_onoff(bool is_enable);
void halrf_dpk_reload(void);
void halrf_tssi_set_efuse_to_de_8721f(void);
void halrf_dpk_track_onoff(bool is_enable);
void halrf_dpk_switch(bool is_enable);
void halrf_dpk_init(void);
void halrf_rx_dck_track_onoff(bool is_enable);
void halrf_rx_dck_init(void);
bool halrf_get_dpk_onoff(void);
bool halrf_get_dpk_track_onoff(void);
void halrf_lo_test(bool is_on);
int halrf_get_predefined_pw_lmt_regu_type_from_str(const char *str);
const char *const *halrf_get_predefined_pw_lmt_regu_type_str_array(u8 *num);
const char *halrf_get_pw_lmt_regu_type_str(u8 band);
s8 halrf_get_power_by_rate(
	u8 rf_path, u16 rate, u8 dcm, u8 offset);
s8 halrf_get_power_by_rate_band(u16 rate, u8 dcm, u8 offset, u32 band);
s8 halrf_get_power_limit(
	enum phl_phy_idx phy, u8 rf_path, u16 rate, u8 bandwidth,
	u8 beamforming, u8 tx_num, u8 channel);
s8 halrf_get_power_limit_ru(
	enum phl_phy_idx phy, u8 rf_path, u16 rate, u8 bandwidth,
	u8 tx_num, u8 channel);
s8 halrf_get_power(
	u8 rf_path, u16 rate, u8 dcm, u8 offset, u8 bandwidth,
	u8 beamforming, u8 channel);
s16 halrf_get_band_power(enum phl_phy_idx phy,
						 u8 rf_path, u16 rate, u8 dcm, u8 offset, u8 bandwidth,
						 u8 beamforming, u8 channel);
u8 halrf_get_thermal(void);
s32 halrf_get_online_tssi_de(s32 dbm, s32 puot);
void halrf_set_tssi_de_for_tx_verify(u32 tssi_de);
void halrf_set_tssi_de_offset(u32 tssi_de_offset);
void halrf_set_power_track(enum phl_phy_idx phy_idx, u8 value);
u8 halrf_get_power_track(void);
void halrf_tssi_get_efuse_ex(enum phl_phy_idx phy_idx);
void halrf_set_ref_power_to_struct(void);

/**************halrf_init.c**************/
void halrf_dm_init(void);
int  halrf_init(void);
void halrf_deinit(void);
/**************halrf_hw_cfg.c**************/
void halrf_config_nctl_reg(void);
bool halrf_config_radio_a_reg(void);
void halrf_config_radio(void);
void halrf_config_rf_parameter(enum phl_phy_idx phy);
s8 halrf_config_power_limit_by_ch(u8 limit_rate, u8 regulation, u8 chnl);
s8 halrf_config_power_limit_ru_by_ch(u8 regulation, u8 bandwith, u8 chnl);
/*******************************************/
void halrf_set_tx_power_by_user(void);
s8 halrf_get_tx_power_by_user(u8 rate, u8 ru_type);

bool halrf_set_power(enum phl_pwr_table pwr_table);

bool halrf_get_efuse_power_table_switch(enum phl_phy_idx phy_idx);

void halrf_set_power_table_switch(u8 pwr_table);

void halrf_get_efuse_trim(enum phl_phy_idx phy_idx);

void halrf_dpk_tracking(void);

void halrf_tssi_tracking(void);

void halrf_power_limit_set_ext_pwr_limit_table(
	enum phl_phy_idx phy);

void halrf_power_limit_set_ext_pwr_limit_ru_table(
	enum phl_phy_idx phy);

bool halrf_iqk_get_ther_rek(void);

void halrf_psd_init(enum phl_phy_idx phy,
					u8 path, u8 iq_path, u32 avg, u32 fft);

void halrf_psd_restore(enum phl_phy_idx phy);

u32 halrf_psd_get_point_data(s32 point);

void halrf_psd_query(
	u32 point, u32 start_point, u32 stop_point, u32 *outbuf);

bool halrf_ctl_bw(enum channel_width bw);
bool halrf_ctl_ch(u8 central_ch, enum rtw_band_type band);
void halrf_ctrl_bw_ch(enum phl_phy_idx phy, u8 central_ch,
					  enum rtw_band_type band, enum channel_width bw);
void halrf_rxmode_in_out(bool in_out);

u32 halrf_get_nctl_reg_ver(void);
void halrf_config_nctl_reg_ic(void);
void halrf_wifi_event_notify(
	enum phl_msg_evt_id event, enum phl_phy_idx phy_idx);

u32 halrf_get_rfk_cap(void);

void halrf_reload_pwr_limit_tbl_and_set(enum phl_pwr_table pwr_table);

u32 halrf_struct_size_get(void);

#endif
