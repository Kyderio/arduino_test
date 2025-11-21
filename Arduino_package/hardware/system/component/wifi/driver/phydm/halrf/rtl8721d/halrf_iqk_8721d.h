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

#ifndef __HALRF_IQK_8721D_H__
#define __HALRF_IQK_8721D_H__

#if defined(CONFIG_AMEBAD)
/*--------------------------Define Parameters-------------------------------*/
//#define IQK_8721D_TONE 1
#define IQK_8721D_SHOW 0

#define MAC_REG_NUM_8721D 1
#define BB_REG_NUM_8721D 9
#define RF_REG_NUM_8721D 9
//#define IQK_DELAY_8721D 2
//#define IQK_STEP_8721D 3
//#define RXK_STEP_8721D 6
//#define IQK_CMD_8721D 0x8
#define IQK_DELAY_TIME_8721D 10

#define ID_FLOK_Coarse 0x1
#define ID_FLOK_fine 0x2
#define ID_FTXK_NB 0x3
#define ID_FTXK_WB 0x4
#define ID_FRXK_NB 0x5
#define ID_FRXK_WB 0x6

//#define TX_IQK 1
//#define RX_IQK 1
#define RF_PATH_MAX_8721D 1
/*---------------------------End Define Parameters-------------------------------*/

//void _phy_iq_calibrate_8721d(s32 result[][8], u8 t);
bool phy_simularity_compare_8721d(s32 result[][8], u8 c1, u8 c2);
void _phy_path_a_fill_iqk_matrix_8721d(bool is_iqk_ok,
				  s32 result[][8],
				  u8 final_candidate,
				  bool is_tx_only);
u8 phy_path_a_rx_iqk_8721d(void);
u8 phy_path_a_iqk_8721d(void);
u8 get_right_ch_place_for_iqk(u8 chnl);
void phy_iq_calibrate_8721d(bool is_recovery);
#endif
#endif /*__HALRF_IQK_8721D_H__*/
