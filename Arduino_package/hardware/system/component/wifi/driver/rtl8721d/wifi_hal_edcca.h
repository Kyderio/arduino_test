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
#ifndef _WIFI_HAL_EDCCA_H_
#define _WIFI_HAL_EDCCA_H_

/* cr for edcca start: need sync with bb */
#define EDCCA_R_TH_L2H_C                   0xc4c
#define EDCCA_R_TH_L2H_C_M                 0x000000FF
#define EDCCA_R_TH_H2L_C                   0xc4c
#define EDCCA_R_TH_H2L_C_M                 0x00FF0000
/* cr for edcca end */

#define EDCCA_NORMAL_TH                    -74
#define EDCCA_ADAPT_TH_5G                  -74
#define EDCCA_ADAPT_TH                     -74
#define EDCCA_CARRIER_SENSE_TH             -50  /*@-56 dBm +6 dB margin*/
#define ADC_BACKOFF                        0
#define EDCCA_TH_MAPPING_DBM_DIFF          110  /*dbm+110->edcca_th*/
#define EDCCA_MAX                          IGI_2_DBM(127)

void wifi_hal_edcca_set_dcnf(void);
void phydm_edcca_decision_opt(void);

#endif
