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
#ifndef _HAL_EDCCA_H_
#define _HAL_EDCCA_H_

/*@--------------------------[Define] ---------------------------------------*/
#define IGI_2_DBM(value)                   (value - 110)
#define EDCCA_HL_DIFF_ADPTVTY              7
#define EDCCA_HL_DIFF_NORMAL               8

#if (PHYDM_VERSION == 3)
/* cr for edcca start: need sync with bb */
#define EDCCA_R_DWN_LVL_C                  0x4848
#define EDCCA_R_DWN_LVL_C_M                0x1F000
#define EDCCA_R_TH_L2H_C                   0x4840
#define EDCCA_R_TH_L2H_C_M                 0xFF00
/* cr for edcca end */

#define EDCCA_NORMAL_TH                    -31  /*@-62 dBm from IEEE: in response to higher thres in normal mode */
#define EDCCA_ADAPT_TH_5G                  -65  /*@-62 dBm -3 dB margin*/
#define EDCCA_ADAPT_TH                     -60  /*@-57 dBm -3 dB margin*/
#define EDCCA_CARRIER_SENSE_TH             -59  /*@-56 dBm -3 dB margin*/
#define EDCCA_TH_MAPPING_DBM_DIFF          128  /*dbm+0x80->edcca_th*/
#define EDCCA_MAX                          127

#elif (PHYDM_VERSION == 2)
#include "wifi_hal_edcca.h"
#endif


/*@--------------------------[Enum]------------------------------------------*/
enum rtw_edcca_pause_type {
	EDCCA_PAUSE   = 1,
	EDCCA_RESUME  = 2
};

/*@--------------------------[Structure]-------------------------------------*/
struct rtw_edcca_info {
#ifdef CONFIG_WIFI_EDCCA
	s8 rvrt_val[2];           /* backup edcca_th_h when pause */
	s8 th_h2l;                /* dbm */
	s8 th_l2h;                /* dbm */
	s8 th_l2h_ini;            /* dbm */
	s8 th_l2h_ini_5g;         /* dbm */
#if (PHYDM_VERSION == 2)
	s8 l2h_dyn_min;           /* dbm */
	u8 l2h_dyn_offset;        /* adc offset: (power in linear region) < (igi_dbm + offset) */
#endif
	u8 th_hl_diff;
	u8 b_edcca_enable : 1;    /* edcca capability enable */
	u8 b_edcca_pause_en : 1;  /* 0-run edcca;1-pause edcca */
#endif
};

/*@--------------------------[Prptotype]-------------------------------------*/
void wifi_hal_edcca_watchdog(void);
void wifi_hal_edcca_init(void);
void wifi_hal_edcca_scan_cfg(enum rtw_edcca_pause_type pause_type);
void wifi_hal_edcca_connect_cfg(enum rtw_edcca_pause_type pause_type);
#endif

