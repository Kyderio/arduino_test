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
#ifndef __HALBB_MP_EX_H__
#define __HALBB_MP_EX_H__

/*@--------------------------[Define] ---------------------------------------*/
#define MAX_USER_NUM 4

/*@--------------------------[Enum]------------------------------------------*/

/*@--------------------------[Structure]-------------------------------------*/

struct rxevm_usr {
	u8 rxevm_ss_0;
	u8 rxevm_ss_1;
	u8 rxevm_ss_2;
	u8 rxevm_ss_3;
};

struct rxevm_info {
	struct rxevm_usr rxevm_user[MAX_USER_NUM];
};

struct rxevm_physts {
	// Seg0/1
	struct rxevm_info rxevm_seg[2];
};

struct rssi_i {
	s32 rssi[4];
};

struct rssi_physts {
	// Seg0/1
	struct rssi_i rssi_seg[2];
};

struct halbb_mp {
	/*Tx ok count, statistics used in Mass Production Test.*/
	u64 tx_phy_ok_cnt;
	/*Rx CRC32 ok/error count, statistics used in Mass Production Test.*/
	u64 rx_phy_crc_ok_cnt;
	u64 rx_phy_crc_err_cnt;
	/*The Value of IO operation is depend of MptActType.*/
	u32 io_ok_value;
	u32 io_err_value;
};

/*@--------------------------[Prptotype]-------------------------------------*/
u16 halbb_mp_get_tx_ok(u32 rate_index,
					   enum phl_phy_idx phy_idx);
u32 halbb_mp_get_rx_crc_ok(enum phl_phy_idx phy_idx);
u32 halbb_mp_get_rx_crc_err(enum phl_phy_idx phy_idx);
void halbb_mp_cnt_reset(void);
void halbb_mp_reset_cnt(void);
u8 halbb_mp_get_rxevm(u8 user, u8 strm, bool rxevm_table);
struct rxevm_physts halbb_mp_get_rxevm_physts(
	enum phl_phy_idx phy_idx);
//u16 halbb_mp_get_pwdb_diff( enum rf_path path);
u8 halbb_mp_get_rssi(enum rf_path path);
void halbb_cvrt_2_mp(void);
u16 halbb_mp_get_rpl(enum rf_path path, enum phl_phy_idx phy_idx);
u32 halbb_mp_get_dc_lvl(enum rf_path path, bool i_ch, enum phl_phy_idx phy_idx);
u16 halbb_mp_get_cfo(enum phl_phy_idx phy_idx);
void halbb_mp_dbg(char input[][16], u32 *_used,
				  char *output, u32 *_out_len);
#endif
