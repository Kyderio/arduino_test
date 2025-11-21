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
#ifndef __HALBB_RADAR_RPT_H__
#define __HALBB_RADAR_RPT_H__

#define NOISE_FLOOR_DBM_TH 0
#define RATIO_POLLUTED_CHIRP_TH 0.75

#define RADAR_BIT8				0x100
#define RADAR_BIT0_to_BIT8   	0x1FF
#define RADAR_BIT18				0x40000
#define RADAR_BIT0_to_BIT18   	0x7FFFF
#define RADAR_BIT12				0x1000
#define RADAR_BIT0_to_BIT12   	0x1FFF
#define RADAR_BIT10				0x400
#define RADAR_BIT0_to_BIT10   	0x7FF
#define RADAR_BIT23				0x800000
#define RADAR_BIT0_to_BIT23   	0xFFFFFF

/*@--------------------------[Enum]------------------------------------------*/
enum radar_rpt_t {
	RADAR_RPT_SUCCESS = 0, /*Get radar rpt segment success*/
	RADAR_RPT_LAST_SEG, /*Get radar rpt segment success, and which is the last segment*/
	RADAR_RPT_FAIL /*Get radar rpt segment fail*/
};


/*@--------------------------[Structure]-------------------------------------*/
struct radar_rpt_agc_hdr_info {
	/*RADAR_FW_INFO_0*/
	u64 rsvd_0: 18;
	u64 temperature_valid_flag: 1;
	u64 temperature: 8;
	u64 lna_idx: 3;
	u64 tia_idx: 1;
	u64 rxbb_idx: 5;
	u64 chirp_width: 2;
	u64 num_of_chirp_num: 8;
	u64 chirp_bw_idx: 1;
	u64	frame_type: 3;
	u64	radar_rpt_seg_end: 1;
	u64 radar_rpt_len_bytes: 13;

	/*RADAR_FW_INFO_1*/
	u64 rsvd_1: 24;
	u64 noise_floor_dBm: 9;  /*S(9,1)*/
	u64 noise_floor_valid_flag: 1;
	u64 rsvd_2: 30;
};

struct radar_rpt_normal_hdr_info {
	/*RADAR_FW_INFO_0*/
	u64 rsvd_0: 12;
	u64 valid_td_num_of_range_T2F: 7;
	u64 chirp_width: 2;
	u64 num_of_normal_chirp: 8;
	u64 num_of_phaseK_chirp: 6;
	u64 ratio_of_polluted_chirp: 8;  /*U(8,7)*/
	u64 chirp_bw_idx: 1;
	u64 debug_mode_opt: 2;
	u64 debug_mode_flag: 1;
	u64	frame_type: 3;
	u64	radar_rpt_seg_end: 1;
	u64 radar_rpt_len_bytes: 13;

	/*RADAR_FW_INFO_1*/
	u64 rsvd_1: 18;
	u64 normal_wi_chirp_num_valid_flag: 1;
	u64 normal_wo_chirp_num_valid_flag: 1;
	u64 phasek_chirp_num_valid_flag: 1;
	u64 rsvd_2: 4;
	u64 normal_dagc_stage2_done_flag: 1;
	u64 rsvd_3: 3;
	u64 phasek_dagc_stage1_done_flag: 1;
	u64 cmn_phase_est_done_flag: 1;
	u64 t2r_dly_est_done_flag: 1;
	u64 t2r_dly_ns_calib_chirp: 19;  /*S(19,10)*/
	u64 rpt_range_data_of_normal_chirp: 2;
	u64 rpt_range_data_of_srk_ref_chirp: 1;
	u64 rsvd_4: 10;

	/*RADAR_FW_INFO_2*/
	u64 fft_strt_idx: 10;
	u64 fft_num_sub: 10;
	u64 stage4_dagc_gain_dB_k_mode: 13;  /*S(13,6)*/
	u64 stage1_dagc_gain_dB_k_mode: 13;  /*S(13,6)*/
	u64 normal_chirp_num: 6;
	u64 normal_chirp_num_is_enough: 1;
	u64 phasek_chirp_num: 6;
	u64 phasek_chirp_num_is_enough: 1;
	u64	payload_size_for_srk_train: 2;
	u64 rsvd_5: 2;

	/*RADAR_FW_INFO_3*/
	u64 rssi_dBm_normal_mode: 9;  /*S(9,1)*/
	u64 noise_floor_dBm: 9; /*S(9,1)*/
	u64 noise_floor_valid_flag: 1;
	u64 common_phase: 19; /*S(19,18)*/
	u64 temperature_valid_flag: 1;
	u64 temperature: 8;
	u64 rsvd_6: 17;

	/*RADAR_FW_INFO_4*/
	u64 stage1_dagc_gain_dB_normal_mode: 13;  /*S(13,6)*/
	u64 stage2_dagc_gain_dB_normal_mode: 13;  /*S(13,6)*/
	u64 stage3_dagc_gain_dB_normal_mode: 13;  /*S(13,6)*/
	u64 stage4_dagc_gain_dB_normal_mode: 13;  /*S(13,6)*/
	u64 rsvd_7: 12;
};

struct radar_rpt_doppler_hdr_info {
	/*RADAR_FW_INFO_0*/
	u64 doppler_t2f_strt_idx_2: 10;
	u64 doppler_t2f_end_idx_2: 10;
	u64 doppler_t2f_step_2: 3;
	u64 doppler_t2f_strt_idx_3: 10;
	u64 doppler_t2f_end_idx_3: 10;
	u64 doppler_t2f_step_3: 3;
	u64 chirp_bw_idx: 1;
	u64 frame_type: 3;
	u64 radar_rpt_seg_end: 1;
	u64 radar_rpt_len_bytes: 13;

	/*RADAR_FW_INFO_1*/
	u64 rsvd_0: 24;
	u64 doppler_t2f_strt_idx_1: 10;
	u64 doppler_t2f_end_idx_1: 10;
	u64 doppler_t2f_step_1: 3;
	u64 range_bin_idx: 6;
	u64 rsvd_1: 11;
};

struct radar_rpt_srk_lms_data {
	u64 data_0: 11;  /*S(11,10)*/
	u64 data_1: 11;  /*S(11,10)*/
	u64 data_2: 11;  /*S(11,10)*/
	u64 data_3: 11;  /*S(11,10)*/
	u64 data_4: 11;  /*S(11,10)*/
	u64 rsvd: 9;
};

struct radar_rpt_normal_data {
	s16 data_0;  /*S(16,10)*/
	s16 data_1;  /*S(16,10)*/
	s16 data_2;  /*S(16,10)*/
	s16 data_3;  /*S(16,10)*/
};

struct radar_rpt_TD_data {
	u64 data_0: 24;  /*S(24,18)*/
	u64 data_1: 24;  /*S(24,18)*/
	u64 rsvd: 16;
};

enum radar_rpt_t halbb_radar_rpt_agc_training_parsing(u8 *addr, u32 len,
		struct rtw_radar_training_hdr *drv_rpt);
enum radar_rpt_t halbb_radar_rpt_srk_lms_training_parsing(u8 *addr, u32 len,
		struct rtw_radar_srk_lms_iq_data *rpt_training_buf,
		struct rtw_radar_training_hdr *drv_rpt);
enum radar_rpt_t halbb_radar_rpt_srk_s2h_training_parsing(u8 *addr, u32 len,
		struct rtw_radar_srk_s2h_iq_data *rpt_training_buf,
		struct rtw_radar_training_hdr *drv_rpt);
enum radar_rpt_t halbb_radar_rpt_range_parsing(u8 *addr, u32 len,
		struct rtw_radar_iq_data *rpt_range_buf_phasek,
		struct rtw_radar_iq_data *rpt_range_buf_near,
		struct rtw_radar_iq_data *rpt_range_buf_far,
		struct rtw_radar_range_hdr *drv_rpt);
enum radar_rpt_t halbb_radar_rpt_doppler_parsing(u8 *addr, u32 len,
		struct rtw_radar_abs_data *doppler_data,
		struct rtw_radar_doppler_hdr *drv_rpt);
void halbb_radar_static_remove(struct rtw_radar_iq_data *rpt_range_buf0,
							   struct rtw_radar_iq_data *rpt_range_buf1,
							   struct rtw_radar_iq_data *rpt_range_sr_buf,
							   u8 sample_num_per_frame,
							   u8 frame_num);
void halbb_radar_doppler_cfar(struct rtw_radar_abs_data *rpt_doppler_buf,
							  u8 frame_num,
							  u8 frame_intev_ms,
							  u8 bw_idx,
							  u8 chirp_width_idx,
							  u16 chirp_num,
							  s16 range_bin_strt_idx,
							  u8 range_bin_num,
							  s16 *doppler_strt_idx,
							  s16 *doppler_end_idx,
							  u8 *doppler_step,
							  u16 doppler_bin_num,
							  u8 ch_idx,
							  struct radar_cfar_result *cfar_res);
void halbb_radar_doppler_target_combine(struct radar_cfar_result *cfar_res_near,
										struct radar_cfar_result *cfar_res_far,
										float aagc_gain,
										float *dagc_gain,
										struct radar_cfar_result *cfar_res_final);

#endif
