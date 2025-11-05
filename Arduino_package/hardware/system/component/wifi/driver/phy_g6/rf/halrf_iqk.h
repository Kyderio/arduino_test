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
#ifndef _HALRF_IQK_H_
#define _HALRF_IQK_H_

/*@--------------------------Define Parameters-------------------------------*/
#define TXIQK 0
#define RXIQK 1
#define RXIQK1 2
#define RXIQK2 3
#define NBTXK 4
#define NBRXK 5
//#define NUM 2

#define ID_TXAGC 0x0
#define ID_FLoK_coarse 0x1
#define ID_FLoK_fine 0x2
#define ID_TXK 0x3
#define ID_RXAGC 0x4
#define ID_RXK 0x5
#define ID_NBTXK 0x6
#define ID_NBRXK 0x7
#define ID_FLOK_vbuffer 0x8
#define ID_A_FLoK_coarse 0x9
#define ID_G_FLoK_coarse 0xa
#define ID_A_FLoK_fine 0xb
#define ID_G_FLoK_fine 0xc
#define ID_TX_PAD_GainGapK 0xe
#define ID_TX_PA_GainGapK 0xf
#define ID_IQK_Restore 0x10
#define ID_TX_TIA_coarse 0x11
#define ID_TX_TIA_fine 0x12
#define ID_RX_AGC 0x13


/*@-----------------------End Define Parameters-----------------------*/

struct halrf_iqk_info {
	bool lok_cor_fail[2]; /*channel/path */
	bool lok_fin_fail[2]; /*channel/path */
	bool iqk_tx_fail[2]; /*channel/path */
	bool iqk_rx_fail[2]; /*channel/path */
	bool is_iqk_enable;
	bool is_lok_enable;
	u8 iqk_band;
	u8 iqk_times;
	//u8 lok_times;

	u8 reg_60;
	u32 temp_rf61;
	u32 bp_txkresult[2];
	u32 bp_rxkresult[2];
	u32 bp_lokresult[2];
	u32 bp_iqkenable[2];

	u8 thermal[2];
	bool thermal_rek_en;
	u8 iqk_mcc_ch[2][NUM];
	u8 iqk_table_idx[NUM];
	bool is_fw_iqk;

#ifdef RFDBG_TRACE_EN
	u32 reload_cnt;
	u8 iqk_bw[NUM];
	u8 iqk_ch[NUM];
	u8 iqk_fail_cnt;

	bool is_wb_txiqk[2];
	bool is_wb_rxiqk[2];
#endif
};

void halrf_iqk_init(void);
void halrf_iqk(enum phl_phy_idx phy_idx);
void iqk_get_ch_info(enum phl_phy_idx phy);
void iqk_macbb_setting(enum phl_phy_idx phy_idx);
void iqk_preset(void);
void iqk_start_iqk(enum phl_phy_idx phy_idx);
void iqk_restore(void);
void iqk_afebb_restore(enum phl_phy_idx phy_idx);


#endif
