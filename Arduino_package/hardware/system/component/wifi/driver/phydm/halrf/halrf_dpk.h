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

#ifndef __HALRF_DPK_H__
#define __HALRF_DPK_H__

/*@--------------------------Define Parameters-------------------------------*/
#define LBK_RXIQK 0
#define GAIN_LOSS 1
#define DO_DPK 2
#define DPK_ON 3
#define GAIN_LOSS_PULSE 4
#define DPK_PAS 5
#define DPK_LMS 6
#define DPK_LOK 4
#define DPK_TXK 5
#define DAGC 4
#define SYNC_DC 5
#define MDPK_DC 6
#define LOSS_CHK 0
#define GAIN_CHK 1
#define SYNC_CHK 3
#define PAS_READ 2
#define AVG_THERMAL_NUM 8
#define AVG_THERMAL_NUM_DPK 8
#define THERMAL_DPK_AVG_NUM 4
#define DPK_GROUP_EN 0

/*define RF path numer*/
#define KPATH 1
/*@---------------------------End Define Parameters---------------------------*/

struct dm_dpk_info {
#if RFDBG
	u16 pwsf[KPATH];				/*path*/
#endif
	u16 dpk_path_ok;
#if (defined(CONFIG_AMEBADPLUS) && RFDBG)
	u8	one_shot_cnt;
#endif
#if defined(CONFIG_AMEBADPLUS)
	u8	txagc[2], dpk_fail[2];
	u32	gainscaling[2];
	u32 even_lut[2][32], odd_lut[2][32];
	u8	dpk_thermal;
#endif
#if defined(CONFIG_AMEBAD)
#if DPK_GROUP_EN
		u8	dpk_2g_result[3];		/*group*/
		u8	pwsf_2g[3];			/*group*/
		u32	lut_2g_even[3][16];		/*group/LUT data1*/
		u32	lut_2g_odd[3][16];		/*group/LUT data2*/
		/*5G DPK data*/
		u8	dpk_5g_result[6];		/*group*/
		u8	pwsf_5g[6];			/*group*/
		u32	lut_5g_even[6][16];		/*group/LUT data3*/
		u32	lut_5g_odd[6][16];		/*group/LUT data4*/
		//s16	tmp_pas_i[32];			/*PAScan I data*/
		//s16	tmp_pas_q[32];			/*PAScan Q data*/
#else
	u8	dpk_result;
	u8	pwsf;
	u32	lut_even[16];		/*LUT data1*/
	u32	lut_odd[16];		/*LUT data2*/
#endif
		u8	thermal_dpk_avg_index;
		s8	thermal_dpk_avg[8];
		s8	dpk_thermal;
#endif
	u8	dpk_ch;
	u8	dpk_band;
	u8	dpk_bw;
	u8	is_dpk_enable: 1;
	u8	is_dpk_pwr_on: 1;
	u8	is_dpk_by_channel: 1;
};
#endif /*__HALRF_DPK_H__*/
