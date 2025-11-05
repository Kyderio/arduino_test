/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
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
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/

/*This header file is for all driver teams to use the same station info.
If you want to change this file please make sure notify all driver teams maintainers.*/

/*Created by YuChen 20170301*/

#ifndef __INC_RTW_STA_INFO_H
#define __INC_RTW_STA_INFO_H

/*--------------------Define ---------------------------------------*/
#define __STA_INFO_H_

#define NUM_ACL 16

#define STA_DM_CTRL_ACTIVE			BIT(0)
#define STA_DM_CTRL_CFO_TRACKING	BIT(1)

#ifdef CONFIG_BEAMFORMEE_VHT
#define	BEAMFORMING_HT_BEAMFORMER_ENABLE	BIT(0)	/*Declare sta support beamformer*/
#define	BEAMFORMING_HT_BEAMFORMEE_ENABLE	BIT(1)	/*Declare sta support beamformee*/
#define	BEAMFORMING_HT_BEAMFORMER_TEST		BIT(2)	/*Transmiting Beamforming no matter the target supports it or not*/
#define	BEAMFORMING_HT_BEAMFORMER_STEER_NUM		(BIT(4)|BIT(5))		/*Sta Bfer's capability*/
#define	BEAMFORMING_HT_BEAMFORMEE_CHNL_EST_CAP	(BIT(6)|BIT(7))		/*Sta BFee's capability*/

#define	BEAMFORMING_VHT_BEAMFORMER_ENABLE	BIT(0)	/*Declare sta support beamformer*/
#define	BEAMFORMING_VHT_BEAMFORMEE_ENABLE	BIT(1)	/*Declare sta support beamformee*/
#define	BEAMFORMING_VHT_MU_MIMO_AP_ENABLE	BIT(2)	/*Declare sta support MU beamformer*/
#define	BEAMFORMING_VHT_MU_MIMO_STA_ENABLE	BIT(3)	/*Declare sta support MU beamformer*/
#define	BEAMFORMING_VHT_BEAMFORMER_TEST		BIT(4)	/*Transmiting Beamforming no matter the target supports it or not*/
#define	BEAMFORMING_VHT_BEAMFORMER_STS_CAP		(BIT(8)|BIT(9)|BIT(10))		/*Sta BFee's capability*/
#define	BEAMFORMING_VHT_BEAMFORMEE_SOUND_DIM	(BIT(12)|BIT(13)|BIT(14))	/*Sta Bfer's capability*/
#endif

#define HT_STBC_EN	BIT(0)
#define VHT_STBC_EN	BIT(1)

#define HT_LDPC_EN	BIT(0)
#define VHT_LDPC_EN	BIT(1)

#define MAX_RF_PATH_NUM 1

/*--------------------Define Enum-----------------------------------*/

#if (PHYDM_VERSION == 2)/*bb_path and rf_syn are in halbb files when use halbb*/
enum bb_path {
	BB_PATH_A = 0x00000001,
	BB_PATH_B = 0x00000002,
	BB_PATH_C = 0x00000004,
	BB_PATH_D = 0x00000008,

	BB_PATH_AB = (BB_PATH_A | BB_PATH_B),
	BB_PATH_AC = (BB_PATH_A | BB_PATH_C),
	BB_PATH_AD = (BB_PATH_A | BB_PATH_D),
	BB_PATH_BC = (BB_PATH_B | BB_PATH_C),
	BB_PATH_BD = (BB_PATH_B | BB_PATH_D),
	BB_PATH_CD = (BB_PATH_C | BB_PATH_D),

	BB_PATH_ABC = (BB_PATH_A | BB_PATH_B | BB_PATH_C),
	BB_PATH_ABD = (BB_PATH_A | BB_PATH_B | BB_PATH_D),
	BB_PATH_ACD = (BB_PATH_A | BB_PATH_C | BB_PATH_D),
	BB_PATH_BCD = (BB_PATH_B | BB_PATH_C | BB_PATH_D),

	BB_PATH_ABCD = (BB_PATH_A | BB_PATH_B | BB_PATH_C | BB_PATH_D),
};

enum rf_syn {
	RF_SYN0 = 0,
	RF_SYN1 = 1,
};
#endif

enum rf_path {
	RF_PATH_A = 0,
};

enum wireless_set {
	WIRELESS_CCK	= 0x00000001,
	WIRELESS_OFDM	= 0x00000002,
	WIRELESS_HT	= 0x00000004,
	WIRELESS_VHT	= 0x00000008,
};

/*--------------------Define MACRO---------------------------------*/

/*--------------------Define Struct-----------------------------------*/
//if mode ==0, then the sta is allowed once the addr is hit.
//if mode ==1, then the sta is rejected once the addr is non-hit.
struct rtw_wlan_acl_node {
	struct list_head		        list;
	u8       addr[ETH_ALEN];
	u8       valid;
};

struct rtw_chan_def {
	enum rtw_band_type band; /* protocol -2.4G,5G,6G*/
	enum channel_width bw;
	enum chan_offset offset;/*used as offset of 40MHz, g6 driver may also used as offset of primary channel*/
	u8 chan; /*primary channel*/
	u8 center_ch;
};

/*
Protocol - RX CAP from 80211 PKT,
driver TX related function need to
reference __rx__ of phy_sta_info->asoc_cap
*/
struct asoc_cap_t {
	u8 stbc_ht_rx: 2;	//halbb used

#if (PHYDM_VERSION == 3)
	/* MAC related */
	u8 htc_rx: 1;
	u8 trig_padding: 2;	//hal_mac used
	/* bit0:twt requester; bit1:twt responder; bit2:b-twt;
	 * bit3:Flex twt schedule; bit4:psr responder; bit5:sst;
	 */
	u8 twt: 6;
	u8 all_ack: 1;
	u8 a_ctrl: 3;	/* bit0:TRS; bit1:BSR; bit2:BQR */
	u8 ops: 1;
	u8 ht_vht_trig_rx: 1;
	u8 bsscolor;
	u16 rts_th: 10;

	/* BB related */
	u8 ht_ldpc: 1;
	u8 vht_ldpc: 1;
	u8 he_ldpc: 1;	//halbb used

	/*
	 * supported_rates: Supported data rate of CCK/OFDM.
	 * The rate definition follow Wi-Fi spec, unit is 500kb/s,
	 * and the MSB(bit 7) represent basic rate.
	 * ex. CCK 2Mbps not basic rate is encoded as 0x04,
	 *     and OFDM 6M basic rate is encoded as 0x8c.
	 * Suppose rates come from Supported Rates and Extended Supported
	 * Rates IE.
	 * Value 0 means it is end of array, and no more valid data rate follow.
	 */
	u8 he_rx_mcs[6];/*80,160,80+80*/
	u8 he_tx_mcs[6];/*80,160,80+80*/

	u8 stbc_vht_rx: 3;	//halbb used
	u8 stbc_vht_tx: 1;
	u8 stbc_he_rx: 1;	//halbb used
	u8 stbc_he_tx: 1;
	u8 ltf_gi;	//halbb used
	u8 dcm_max_const_rx: 2;	//halbb used
	u8 pkt_padding: 2;
	u8 er_su: 1;	//halbb used
	u8 partial_bw_su_er: 1;

	u8 explicit_beamformee: 1;
	u8 vht_mu_beamformee_capable: 1;
	u8 beamformee_sts_cap;

	/* RF related */
	u8 nss_tx: 3;
	u8 nss_rx: 3;	//halbb used
	u8 dcm_max_const_tx: 2;
#else
	u8 sta_tx_high_power_lvl: 4;
	u8 sta_last_dtp_lvl: 4;
#endif
	u32	rom_rsvd;
};

struct asoc_spec_t {
	struct asoc_cap_t asoc_spec;

	u32			max_mpdu_length;
	u16			max_ampdu_buffer_size;

	u8			bw_cap;				/* value of BW_CAP_XXX */
	u8			max_ampdu_length_exponent;
	u8 			rom_rsvd[8];

};

struct sta_rssi_info {
	u8 rssi; /* u(8,1), hal-bb provide, read only : 0~110 (dBm = rssi -110) */
	u8 rssi_ofdm; /* u(8,1),  hal-bb provide, read only : packet, for debug */
	u8 rssi_cck; /* u(8,1),  hal-bb provide, read only : packet, for debug */
	u8 assoc_rssi; /* phl_rx provide, read only */
	u16 rssi_ma; /* u(16,5),  hal-bb provide, read only : u16 U(12,4)*/

#if (PHYDM_VERSION == 3)
	u16 rssi_ma_path[MAX_RF_PATH_NUM];
	u16 pkt_cnt_data;
	u16 rssi_bcn_ma; /* u(16,5),  beacon RSSI, hal-bb provide, read only*/
	u16 rssi_bcn_ma_path[MAX_RF_PATH_NUM];
	u16 pkt_cnt_bcn;
	u16 snr_ma; /* u(16,4), hal-bb provide, read only, SNR= snr_ma dBm*/

	u8 rssi_bcn; /* u(8,1), beacon RSSI, hal-bb provide, read only : 0~110 (dBm = rssi -110) */
	u8 ma_factor: 4;
	u8 ma_factor_bcn: 4;
	/* phl_rx provide, read only : Moving Average RSSI information for the STA */
	u8 ma_rssi; /* moving average : 0 ~ PHL_MAX_RSSI (dBm = rssi - PHL_MAX_RSSI) */
	u8 ma_rssi_mgnt; /* moving average rssi for beacon/probe : 0 ~ PHL_MAX_RSSI (dBm = rssi - PHL_MAX_RSSI) */
#else
	u16 cck_sum_power;
	u8 packet_map;
	u8 ofdm_pkt_cnt;
	u8 cck_pkt_cnt;
	u8 is_send_rssi;
	u8 valid_bit;
#endif
};

struct phy_sta_info {
	s32 stainfo_cfo_tail;
	u16 stainfo_cfo_cnt;
#if (PHYDM_VERSION == 3)
	u8 dpt_dyn_tx_pwr_lvl: 4;
	u8 dpt_last_pwr_lvl: 4;
#endif
};

struct rtw_speaker_stainfo {
	u8 tx_drop_map[5];
	u8 tx_drop_sum;
	u8 tx_rpt_seq;
};
#endif
