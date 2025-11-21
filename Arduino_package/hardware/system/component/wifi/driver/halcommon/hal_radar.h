/******************************************************************************
 *
 * Copyright(c)2019 Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 *****************************************************************************/
#ifndef __HAL_RADAR_H__
#define __HAL_RADAR_H__

#ifdef CONFIG_RADAR

#define RANGE_IQ_BYTES                 4
#define DOPPLER_ABS_BYTES              2

#define SRK_LMS_DATA_NUM               12
#define SRK_S2H_DATA_NUM               80

#define SRK_LMS_SEG_NUM               4  //BB will report to MAC in segments only for srk lms rpt
#define SRK_LMS_RPT_LEN_PER_SEG       2048

/* For optimize buffer size, SW can only process partial samples for specific target distance*/
#define NEAR_SAMPLE_NUM_PER_FRAME      44  /* 29 = 6 + 23: 0~2m + extend_num */
#define FAR_SAMPLE_NUM_PER_FRAME      44  /* 47/35 => 24 + 23: 2~10m + extend_num or 12 + 23: 2~6m + extend_num*/

#define AGC_HEADER_LEN               16
#define NON_AGC_HEADER_LEN           40

#define DOPPLER_FFT_BASE_ADDR            0x40020000
#define DOPPLER_FFT_IN_ADDR            0xE000

#define RADAR_MAX_RETRY_CNT            1

#define RADAR_COEX_TEST            0

enum radar_stage {
	AGC_TRAINING_STAGE = 0,
	SRK_LMS_TRAINING_STAGE,
	SRK_S2H_TRAINING_STAGE,
	RANGE_STAGE,
	DOPPLER_STAGE
};

enum radar_status {
	RADAR_NONE = 0,
	RADAR_TX,
	RADAR_RX_INT_OK,
	RADAR_RX_INT_FAIL,
	RADAR_RX_INT_NONE,
	RADAR_RX_RPT,
	RADAR_RX_RPT_FAIL
};

enum radar_mode {
	NORMAL_MODE = 0,
	SINGLE_FMCW_MODE
};

struct rtw_radar_desc {
	u16 radar_length;
	u32 timestamp;
};

struct rtw_radar_srk_s2h_iq_data {
	s32 real;
	s32 imag;
};

struct rtw_radar_srk_lms_iq_data {
	s16 real;
	s16 imag;
};

struct rtw_radar_iq_data {
	s16 real;
	s16 imag;
};

struct rtw_radar_iq_data_32bit {
	s32 real;
	s32 imag;
};

struct rtw_radar_abs_data {
	s16 abs;
};

struct rtw_radar_training_hdr {
	/* common*/
	u8 seg_end;
	u8 radar_info_valid; /* 0:invalid, 1:valid */
	u8 frame_type; /* 0: AAGC Training Frame; 1: SRK_LMS Training Frame; 2: SRK_S2H Training Frame;  3: Normal Frame; 4: Doppler T2F */
	float temperature;

	/* AGC training only*/
	u8 rxbb_idx;
	u8 tia_idx;
	u8 lna_idx;
	float aagc_gain;
};

struct rtw_radar_range_hdr {
	u8 radar_info_valid; /* 0:invalid, 1:valid */
	u8 frame_type; /* 0: AAGC Training Frame; 1: SRK_LMS Training Frame; 2: SRK_S2H Training Frame;  3: Normal Frame; 4: Doppler T2F */
	u16 fft_num_sub; /* U(10,0) */
	s16 fft_strt_idx; /* S(10,0) */
	u8 valid_td_num_of_range_T2F;
	u8 chirp_bw_idx : 1; /* 0: 40MHz; 1: 70MHz */
	u8 chirp_width : 2; /* FFT duration 0:8us, 1:16us, 2:32us, 3:64us */
	u8 rpt_range_data_of_srk_ref_chirp : 1;  /* 0: not rpt range_data_of_srk_ref_chirp; 1: rpt range_data_of_srk_ref_chirp */
	u8 rpt_range_data_of_normal_chirp : 2;  /* 0: wo SR-C, 1:wi SR-C, 2:wo+wi SR-C */
	float temperature;
	float dagc_gain_normal_mode[4];
};

struct rtw_radar_doppler_hdr {
	u8 frame_type;
	u8 doppler_t2f_step[3];
	s16 doppler_t2f_strt_idx[3];
	s16 doppler_t2f_end_idx[3];
	u8 range_bin_idx;
};

struct rtw_radar_agc_paras {
	u8 rxbb_idx;
	u8 tia_idx;
	u8 lna_idx;
	float temperature;
	float aagc_gain;
};

struct rtw_radar_srk_lms_paras {
	struct rtw_radar_srk_lms_iq_data *training_buf;
	u8 *parsing_buf;
	u16 rpt_len;
	float temperature;
};

struct rtw_radar_srk_s2h_paras {
	struct rtw_radar_srk_s2h_iq_data *training_buf;
	float temperature;
};

struct rtw_radar_range_paras {
	u16 fft_num_sub;
	s16 fft_strt_idx;
	u8 valid_td_num_of_range_T2F;
	float dagc_gain_normal_mode[4];
};

struct radar_cfar_result {
	u32 det_raw_data[64];
	double det_range[64];
	double det_vel[64];
	double snr_of_det_target[64];
	u8 det_target_num;
};

struct radar_priv {
	u8 mode;
	u8 bw_idx;
	u8 chrip_width;
	u8 phasek_chirp_num;
	u8 normal_chirp_num;
	u16 frame_num;
	u8 frame_interval;  //unit ms
	u8 frame_timeout;  //unit ms
	u16 frame_cnt;
	u8 radar_en_ctrl;
	u8 range_normal_num;
	u8 range_normal_cnt;

	u8 sw_radar_fft_size;
	u8 sw_radar_fft_mode;
	u8 sw_t2f_times;

	/* For optimize buffer size, SW can only process partial samples for specific target distance*/
	u8 near_sample_num;  //near samples per frame:6 + 23: 0~2m + extend_num
	u8 far_sample_num;  //far samples per frame:47/35 => 24 + 23: 2~10m + extend_num or 12 + 23: 2~6m + extend_num
	u16 doppler_sample_num;  //doppler samples per range
	u8 near_doppler_process_num;
	u8 far_doppler_process_num;

	enum radar_status radar_status;
	u8 retry_cnt;
	u8 stage;

	struct rtw_radar_agc_paras agc_paras;
	struct rtw_radar_srk_lms_paras srk_lms_paras;
	struct rtw_radar_srk_s2h_paras srk_s2h_paras;
	struct rtw_radar_range_paras range_paras;

	struct rtw_radar_iq_data *range_buffer_wo_0;
	struct rtw_radar_iq_data *range_buffer_wo_1;
	struct rtw_radar_iq_data *range_buffer_wi_0;
	struct rtw_radar_iq_data *range_buffer_wi_1;
	struct rtw_radar_iq_data *static_remove_wo;
	struct rtw_radar_iq_data *static_remove_wi;
	u16 range_frame_cnt;

	struct rtw_radar_abs_data *doppler_buffer_wo;
	struct rtw_radar_abs_data *doppler_buffer_wi;
	u8 doppler_wo_cnt;
	u8 doppler_wi_cnt;

	struct radar_cfar_result *cfar_wo;
	struct radar_cfar_result *cfar_wi;
	struct radar_cfar_result *cfar_final;

#if RADAR_COEX_TEST
	u16 gnt_bt_interval;  //unit us
	u16 gnt_bt_advance;  //unit us
#endif
	u32 range_win_size;
	u32 doppler_win_size;

	u8 delta_intv_ms;
};

//The structure is used to enable radar and describe the cfg parameters used for radar
struct _rtw_radar_action_parm_t {
	unsigned char frame_type;
	unsigned char chrip_bw_idx;
	unsigned char chrip_width;
	unsigned char phasek_chirp_num;
	unsigned char normal_chirp_num;
	unsigned short frame_num;
	unsigned char frame_interval;
	unsigned char frame_timeout;
	unsigned char sw_radar_fft_size;
	unsigned char sw_radar_fft_mode;
	unsigned char sw_t2f_times;
	unsigned char near_sample_num;
	unsigned char far_sample_num;
	unsigned char radar_en_ctrl;
	unsigned short gnt_bt_interval;
	unsigned short gnt_bt_duration;
	unsigned int range_win_size;
	unsigned int doppler_win_size;
	unsigned int range_normal_num;
	unsigned char delta_intv_ms;
	unsigned char enable;
};


void wifi_hal_radar_en_by_user(u8 *radar_en_by_user);
void wifi_hal_radar_rpt_hdl(u8 *buf, struct rtw_radar_desc *radar_desc);
s32 wifi_hal_radar_en(struct _rtw_radar_action_parm_t *act_param);
s32 wifi_hal_radar_cfg(struct _rtw_radar_action_parm_t *act_param);
void wifi_hal_radar_deinit(struct radar_priv *pradarpriv);
void wifi_hal_radar_interrupt_handle(void);

#endif /* CONFIG_RADAR */

#endif /* __HAL_RADAR_H__ */