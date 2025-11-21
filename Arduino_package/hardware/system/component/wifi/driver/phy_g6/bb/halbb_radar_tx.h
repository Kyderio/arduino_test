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
#ifndef __HALBB_RADAR_TX_H__
#define __HALBB_RADAR_TX_H__

/*@--------------------------[Enum]------------------------------------------*/
enum radar_frame_type {
	//0: AAGC Training Frame, 1: SRK_LMS Training Frame, 2: SRK_S2H Training Frame, 3: Normal Frame, 4: Doppler T2F
	AAGC_TRAINING = 0,
	SRK_LMS = 1,
	SRK_S2H = 2,
	NORMAL_FRAME = 3,
	DOPPLER_T2F = 4,
};

enum radar_chirp_bw_idx {
	//0: 70Mhz, 1: 40MHz FMCW Chirp BandWidth
	RADAR_BW70 = 0,
	RADAR_BW40 = 1,
};

enum radar_chirp_width {
	//0: 8us, 1: 16us, 2: 32us, 3: 64us, 1: 40MHz FMCW Chirp Width
	CHIRP_WIDTH_8US = 0,
	CHIRP_WIDTH_16US = 1,
	CHIRP_WIDTH_32US = 2,
	CHIRP_WIDTH_64US = 3,
};

/*@--------------------------[Structure]-------------------------------------*/
struct radar_agc_initial_gain {
	u8  lna_idx;
	u8  tia_idx;
	u8  rxbb_idx;
};

struct aagc_training_para {
	u8 aatgc_chirp_num;
};

struct srk_lms_frame_para {
	u8 phase_k_num;
	u8 normal_for_srk_num;
	u8 t2r_delay_num;
	u8 commphase_est_num;
	u8 ref_for_srk_num;
};

struct normal_frame_para {
	u8 phase_k_num;
	u8 normal_for_norm_num;
	u8 t2r_delay_num;
	u8 commphase_est_num;
	u8 ref_for_norm_num;
};

// para Identical to normal frame
struct srk_s2h_frame_para {
	u8 phase_k_num;
	u8 normal_for_norm_num;
	u8 t2r_delay_num;
	u8 commphase_est_num;
	u8 ref_for_norm_num;
};


// struct srk_s2h_frame{} the same as normal
// struct doppler frame{} only for report


/*@--------------------------[Prptotype]-------------------------------------*/
void halbb_radar_disable_wlan_trx(void);
void halbb_radar_enable_wlan_trx(void);
void halbb_radar_enable_radar_trx(void);
void halbb_radar_enable_radar_range_t2f(void);
void halbb_radar_retore_wifi_t2f(void);
void halbb_radar_config_radar_retry(void);
void halbb_radar_disable_radar_trx(bool radar_en);
void halbb_radar_set_frame_type(u32 frame_type);
void halbb_radar_set_fmcw_bw(u32 bw_idx);
void halbb_radar_set_fmcw_chirp_width(u32 chirp_width);
void halbb_radar_set_fmcw_chirp_num(u32 frame_type, u32 phasek_chirp_num, u32 normal_chirp_num, u32 chirp_width);
void halbb_radar_tx_start_normal(void);
void halbb_radar_tx_start_pure_fmcw(void);
bool halbb_radar_set_radar_channel(u8 central_ch, u32 bw_idx);
void halbb_radar_set_gain_error(u8 central_ch, u32 bw_idx);
void halbb_radar_set_rx_gain_idx(struct radar_agc_initial_gain *initial_gain);
bool halbb_radar_protection_contrl(u8 pr_format, u32 bw_idx);
void halbb_radar_set_fmcw_txpower(s16 fmcw_power_dBm);
void halbb_radar_set_pr_txpower(s16 pr_power_dBm);
void halbb_radar_set_radar_srk_delay(s32 srk_delay_value);
void halbb_radar_set_pmac(void);
void halbb_radar_set_lbk_mode(void);
void halbb_radar_set_adc_sign_bit(void);
void halbb_radar_sw_t2f_config(u8 sw_radar_fft_size,
							   bool sw_radar_fft_mode,
							   u16 sw_radar_input_num,
							   u8 sw_t2f_times);
void halbb_radar_sw_t2f_trig(void);
void halbb_radar_enable_wr_sw_buf(void);
void halbb_radar_disable_wr_sw_buf(void);
void halbb_radar_disable_sw_fft(void);
void halbb_radar_set_t2f_win_size(u32 range_win_size, u32 doppler_win_size);
void halbb_radar_write_t2f_win_coef(void);
void halbb_radar_disable_dfe_module(u8 frame_type);
void halbb_radar_restore_dfe_module(u8 frame_type);
u8 halbb_radar_read_range_valid_smp(void);
void halbb_radar_reset_range_bin_idx(void);
void halbb_radar_set_rpt_en(bool radar_rpt_en);
void halbb_radar_update_aagc_gain_idx(u8 lna_idx, u8 tia_idx, u8 rxbb_idx);
u16 halbb_radar_get_doppler_output_sample_num(void);
void halbb_radar_set_range_t2f_valid_smp(void);
#endif
