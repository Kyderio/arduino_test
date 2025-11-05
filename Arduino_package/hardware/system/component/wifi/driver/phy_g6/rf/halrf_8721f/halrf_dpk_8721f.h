/******************************************************************************
 *
 * Copyright(c) 2007 - 2021  Realtek Corporation.
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
#ifndef __HALRF_DPK_8721FH__
#define __HALRF_DPK_8721FH__
#ifdef RF_8721F_SUPPORT
/*--------------------------Define Parameters-------------------------------*/
#define DPK_VER_8721F 0x5
#define DPK_RAMP 0
#define DPK_LUT0 1
//#define DPK_LUT0_TXAGC 0x35
#define DPK_RF_PATH_MAX_8721F 1
#define DPK_KIP_REG_NUM_8721F 5
#define DPK_BB_REG_NUM_8721F 6
#define DPK_RF_REG_NUM_8721F 6
#define DPK_RELOAD_EN_8721F 0
#define DPK_REG_DBG 0
#define DPK_NCTL_RXAGC_8721F 0x15
#define DPK_NCTL_TXAGC_8721F 0x17
#define DPK_NCTL_LMS_8721F 0x18

/*---------------------------End Define Parameters----------------------------*/

void halrf_dpk_8721f(void);
void _dpk_pas_read_8721f(void);
s32 _dpk_rxsram_read_8721f(void);
void halrf_dpk_onoff_8721f(bool off);
void halrf_dpk_onoff_ramp_8721f(bool off);
void halrf_dpk_track_8721f(void);
u8 _dpk_agc_8721f(u8 init_txagc, u8 cnt_max);
void halrf_dpk_reload_8721f(void);
#endif
#endif /*  __HALRF_DPK_8721FH__ */
