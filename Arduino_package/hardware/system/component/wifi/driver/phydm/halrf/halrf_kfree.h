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

#ifndef __HALRF_KFREE_H__
#define __HALRF_KFREE_H__

#define KFREE_VERSION "1.0"

#define KFREE_BAND_NUM 9
#define KFREE_CH_NUM 3

#define KFREE_FLAG_ON BIT(0)
#define KFREE_FLAG_THERMAL_K_ON BIT(1)

#define KFREE_FLAG_ON_2G BIT(2)
#define KFREE_FLAG_ON_5G BIT(3)

#define PA_BIAS_FLAG_ON BIT(4)
#define TSSI_TRIM_FLAG_ON BIT(5)
#define LNA_FLAG_ON BIT(6)

/*8721DA*/
#define PPG_THERMAL_OFFSET_8721DA 0x7B0
#define PPG_PABIAS_8721DA 0x7B1
#define PPG_2GL_TXG_8721DA 0x7B5
#define PPG_2GH_TXG_8721DA 0x7B6
#define PPG_5GL1_TXA_8721DA 0x7B7
#define PPG_5GL2_TXA_8721DA 0x7B8
#define PPG_5GM1_TXA_8721DA 0x7B9
#define PPG_5GM2_TXA_8721DA 0x7BA
#define PPG_5GH1_TXA_8721DA 0x7BB
#define PPG_5GH2_TXA_8721DA 0x7BC
#define PPG_IQKPLL_VCO_8721DA 0x7C8
/*8721D*/
/*#define KFREE_BAND_NUM_8721D 6*/
#define PPG_THERMAL_OFFSET_8721D 0x1EF
#define PPG_2G_TXA_8721D 0x1EE
#define PPG_5GL1_TXA_8721D 0x1ED
#define PPG_5GL2_TXA_8721D 0x1EC
#define PPG_5GM1_TXA_8721D 0x1EB
#define PPG_5GM2_TXA_8721D 0x1EA
#define PPG_5GH1_TXA_8721D 0x1E9

struct odm_power_trim_data {
	u8 flag;
	s8 bb_gain[KFREE_BAND_NUM][MAX_RF_PATH];
	s8 thermal;
};

enum phydm_kfree_channeltosw {
	PHYDM_2G = 0,
	PHYDM_5GLB1 = 1,
	PHYDM_5GLB2 = 2,
	PHYDM_5GMB1 = 3,
	PHYDM_5GMB2 = 4,
	PHYDM_5GHB = 5,
};

s8 phydm_get_thermal_offset(void);

void phydm_do_new_kfree(void);

#endif /*__HALRF_KFREE_H__*/
