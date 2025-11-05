/******************************************************************************
 *
 * Copyright(c) 2019 Realtek Corporation.
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
#ifndef _HALRF_PWR_TRACK_H_
#define _HALRF_PWR_TRACK_H_

/*@--------------------------Define Parameters-------------------------------*/
#define AVG_THERMAL_NUM 8
#define MAX_RF_PATH 4
#define DELTA_SWINGIDX_SIZE 30
#define BAND_NUM 3
#define BAND_NUM_6G 4
#define TSSI_EFUSE_NUM 32
#define TSSI_HIDE_EFUSE_NUM 8
#define TSSI_HIDE_EFUSE_NUM_6G 16
#define AVG_THERMAL_NUM_TSSI 2
#define MAX_CH_NUM 67
#define TSSI_ALIMK_VAULE_NUM 8

#define MAX_HALRF_PATH 1
#define DELTA_SWINTSSI_SIZE 64
/*@---------------------------End Define Parameters---------------------------*/

enum halrf_tssi_rate_type {
	EFUSE_TSSI_CCK = 0,
	EFUSE_TSSI_MCS,
#ifndef RF_6G_NOT_SUPPORT
	EFUSE_TSSI_6G,
#endif
	EFUSE_TSSI_RATE_MAX
};

enum halrf_tssi_type {
	TSSI_OFF = 0,
	TSSI_ON,
	TSSI_CAL
};

enum halrf_tssi_slope_type {
	TSSI_SLOPE_DEFAULT = 0,
	TSSI_SLOPE_ON,
	TSSI_SLOPE_OFF
};

enum halrf_tssi_alimk_band {
	TSSI_ALIMK_2G = 0,
#ifndef RF_5G_NOT_SUPPORT
	TSSI_ALIMK_5GL,
	TSSI_ALIMK_5GM,
	TSSI_ALIMK_5GH,
#endif
	TSSI_ALIMK_MAX
};

struct halrf_tssi_info {
	u8 base_ther;
	u8 tssi_j_2;
	s32 tssi_de;
	u8 tssi_type[MAX_HALRF_PATH];
	s8 tssi_efuse[EFUSE_TSSI_RATE_MAX][TSSI_EFUSE_NUM];
#ifdef RF_8721F_SUPPORT
	s8 tssi_efuse_aux[EFUSE_TSSI_RATE_MAX][TSSI_EFUSE_NUM];
#endif
	s8 tssi_trim[TSSI_HIDE_EFUSE_NUM];
	s8 curr_tssi_cck_de;
	s8 curr_tssi_efuse_cck_de;
	s8 curr_tssi_ofdm_de;
	s8 curr_tssi_efuse_ofdm_de;
	s8 curr_tssi_trim_de;
	u8 cur_ch;
#ifdef	RFDBG_TRACE_EN
	u32 tssi_alimk_time;
	u32 tssi_slope_time;
	u32 tssi_total_time;
#endif
};

#endif
