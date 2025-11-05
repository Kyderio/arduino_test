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
#ifndef __HALRF_DPK_H__
#define __HALRF_DPK_H__

/*@--------------------------Define Parameters-------------------------------*/
#define AVG_THERMAL_NUM_DPK 8
#define THERMAL_DPK_AVG_NUM 1
#define DPK_BKUP_NUM 2

enum dpk_id {
	LBK_RXIQK	= 0x06,
	SYNC		= 0x10,
	MDPK_IDL	= 0x11,
	MDPK_MPA	= 0x12,
	GAIN_LOSS	= 0x13,
	GAIN_CAL	= 0x14,
	DPK_RXAGC	= 0x15,
	KIP_PRESET	= 0x16,
	KIP_RESTORE	= 0x17,
	DPK_TXAGC	= 0x19,
	D_KIP_PRESET	= 0x28,
	D_TXAGC		= 0x29,
	D_RXAGC		= 0x2a,
	D_SYNC		= 0x2b,
	D_GAIN_LOSS	= 0x2c,
	D_MDPK_IDL	= 0x2d,
	D_GAIN_NORM	= 0x2f,
	D_KIP_THERMAL	= 0x30,
	D_KIP_RESTORE	= 0x31
};

struct dpk_bkup_para {
	enum rtw_band_type	band;		/* 2.4G,5G,6G*/
	enum channel_width	bw;
	u8	ch;
	u8	path_ok;
	u8	txagc_dpk;		/*txagc@dpk with path*/
	u8	ther_dpk;		/*thermal@dpk with path*/
	//u8	trk_idx_dpk;		/*track_idx@dpk with path*/
	//u8	ther_tssi;		/*thermal@tssi with path*/
	u8	gs;
	u16	pwsf;
};

/*@---------------------------End Define Parameters---------------------------*/

struct halrf_dpk_info {

	bool	is_dpk_enable;
	bool	is_dpk_track_en;
	bool	is_lut1_en;
	u8	ther_avg[AVG_THERMAL_NUM_DPK];	/*path*/
	u8	ther_avg_idx;
	u8	cur_idx;				/*path*/
	u8  txagc_lut0;
#ifdef RFDBG_TRACE_EN
	u32 dpk_cal_cnt;
	u32 dpk_ok_cnt;
	u32 dpk_reload_cnt;
#endif
#ifdef RF_8721F_SUPPORT
	u32 *dpk_gs;
	u32 *dpk_pwsf;
	u32 *dpk_txagc_lut0;
	u32 *dpk_txagc_lut1;
	u32 *dpk_txagc_bnd0;
	u32 *dpk_txagc_bnd2;
	u32 **dpk_lut0;
	u32 **dpk_lut1;
	u8 dpk_fail;
	u8 ant_num;
	u8 dpk_cnt;
#endif
	struct dpk_bkup_para bp[DPK_BKUP_NUM];	/*path/index*/
};

#endif /*__HALRF_DPK_H__*/

