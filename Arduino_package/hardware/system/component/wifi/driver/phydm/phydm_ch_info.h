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
#ifndef __PHYDM_CH_INFO_H__
#define __PHYDM_CH_INFO_H__

#define PLATFOM_IS_LITTLE_ENDIAN	1 //for halbb use


#ifdef PHYDM_CH_INFO_SUPPORT

#define _os_mem_cpy(dst, src, sz)  memcpy(dst, src, sz)

#ifndef memcpy
#define memcpy(dst, src, sz)			_memcpy(dst, src, sz)
#endif


#define PHYDM_TRACE            DiagPrintf

#define PHYDM_WARNING  DiagPrintf


/*@-------------------------FROM ch_info_ex.h START-------------------------*/


/*@--------------------------[Define] ---------------------------------------*/
#define CH_DESI_OPT_NUM 4 /*CH info decimation number 1/2/4/16 */
#define CH_INFO_BW_NUM 4 /*20/40/80/160*/
#define CH_INFO_RXD_LEN 8 /*len of a ch_info */
#define CH_INFO_SNR_BIN_NUM 9 /*SNR BIN number*/

/*@--------------------------[Enum]------------------------------------------*/
enum bb_ch_info_t {
	BB_CH_INFO_SUCCESS = 0, /*Get ch_info segment success*/
	BB_CH_INFO_LAST_SEG, /*Get ch_info segment success, and which is the last segment*/
	BB_CH_INFO_FAIL, /*Get ch_info segment fail*/
};

enum bb_ch_mode_t {
	BB_CH_LEGACY_CH = 0,
	BB_CH_MIMO_CH = 1
};

/*@------------------------[Structure] ---------------------------*/
#if DBG
struct bb_ch_rpt_size_info {
	u16 ch_info_tone_num[CH_INFO_BW_NUM]; /*20,40,80; Byte; current tone decimatin configuration*/
	u16 ch_info_tone_num_he[CH_INFO_BW_NUM]; /*HE 20,40,80; Byte; current tone decimatin configuration*/
	u16 tone_num[CH_INFO_BW_NUM][CH_DESI_OPT_NUM]; /*look up table for tone number under different tone decimatin CR configuration*/
	u16 tone_num_he[CH_INFO_BW_NUM][CH_DESI_OPT_NUM];/*look up table for HE tone number under different tone decimatin CR configuration*/
	u8 data_byte; /* 1&2 Byte, 1Byte:S(8,4), 2Byte:S(16,12)*/
};
#endif

struct bb_ch_info_cr_cfg_info {
#if DBG
	enum bb_ch_mode_t ch_i_type; /*0~1: Legacy-CH, MIMO-CH*/
#endif
	u32	ch_i_ele_bitmap; /*Channel matrix size, ex: 0x303:2X2, 0x1: 1X1*/ //8721da:r_ch_info_ele_bitmap d24[23:16]

	u8	ch_i_data_src; /*0~1: CH-estimation, CH-smoothing*/ //8721da:r_ch_info_alg_opt d24[10]
	u8	ch_i_grp_num; /*[Lgcy/HT/VHT] 0~3: decimation to 1/1, 1/2, 1/4, 1/16*/ //8721da:r_ch_info_group d24[12:11]
	u8	ch_i_grp_num_he; /*[HE]0~3: decimation to 1/1, 1/2, 1/4, 1/16*/
#if DBG
	u8	ch_i_blk_start_idx; /*1~10*/
	u8	ch_i_blk_end_idx; /*1~10*/
#endif
	u8	ch_i_seg_len; /*0~3: 12/28/60/124 (8byte)*/ //8721da:1f0c[18:17]
	u8	ch_i_ch_opt;
	u8	b_ch_i_cmprs: 1; /*0~1: 8/16 bit, 0:S(8,4), 1:S(16,12)*/ //8721da:r_ch_info_wl_opt d24[13]
};

struct bb_ch_info_buf_cfg_info {
	u8	ch_i_blk_start_idx; /*1~10*/
	u8	ch_i_blk_end_idx; /*1~10*/
	u8	ch_i_seg_len; /*0~3: 12/28/60/124 (8byte)*/
};

struct bb_ch_rpt_hdr_info {
	u8 rxevm_nss0; // S(8,1)
	u8 ele_bitmap;
	u32 is_pkt_end: 1;
	u32 set_valid: 1;
	u32 segment_size: 11; //length of each segment unit:bytes,ex:12(default)*8=96bytes
	u32 BB_Hdr_RSVD_1: 3;
	u32 total_len: 14; // 8 + 8 + len_rawdata of all seg
	u32 BB_Hdr_RSVD_2: 2;
	u8 total_seg_num; // number of segment
	u8 seq_num; // segment index
};

struct bb_phy_info_rpt {
	u32 cfo_fine: 11; // unit: cfo_fine_kHz/312.5	(kHz)  S(11,10)
	u32 pkt_fmt: 4; // 0:legacy 1:HT 2:VHT
	u32 grp_num: 2; // 1/2/4/8 tone report
	u32 rxsc: 4;
	u32 wl_opt: 1; // S(8,3) or S(16,11)
	u32 data_src: 2;
	u32 rssi_path0: 8; //-110?
	u8 SNR_dB;
	u8 agc_path0: 7; // unit:dB U(7,0)
	u8 phyinfo_RSVD_1: 1;
	u8 smooth: 1;
	u8 phyinfo_RSVD_2: 7;
	u8 rxevm_nss1;
};

struct bb_ch_info_drv_rpt {
	u32 raw_data_len;
	u8 seg_idx_curr;
	bool get_ch_rpt_success;
};

/*@--------------------------[Prptotype]-------------------------------------*/
bool phydm_ch_info_chk_cr_valid(struct bb_ch_info_cr_cfg_info *cfg);
bool phydm_cfg_ch_info_cr(struct bb_ch_info_cr_cfg_info *cfg);
void phydm_ch_info_cfg_mu_buff_cr(bool en);
void phydm_ch_info_status_en(bool en, enum phl_phy_idx phy_idx);
enum bb_ch_info_t phydm_ch_info_get_data(u8 **addr, u32 len,
		struct bb_ch_rpt_hdr_info *hdr,
		struct bb_phy_info_rpt *phy_info,
		struct bb_ch_info_drv_rpt *drv);

enum bb_ch_info_t phydm_ch_info_parsing(u8 *addr, u32 len,
										u8 *rpt_buf,
										struct bb_ch_rpt_hdr_info *hdr,
										struct bb_phy_info_rpt *phy_info,
										struct bb_ch_info_drv_rpt *drv);




/*@-------------------------FROM ch_info_ex.h END-------------------------*/


/*@--------------------------[Define] ---------------------------------------*/
#define TEST_CH_INFO_MAX_SEG	4
#define TEST_CH_SEG_LEN	(12 * 8) /*Byte*/
/*@--------------------------[Enum]------------------------------------------*/

/*@--------------------------[Structure]-------------------------------------*/
struct bb_ch_info_raw_info {
	s16 *octet;
	u32 ch_info_buf_len; /*Byte*/
};

struct bb_ch_rpt_info {
	struct bb_ch_info_cr_cfg_info bb_ch_info_cr_cfg_i;
#if DBG
	struct bb_ch_rpt_size_info bb_ch_rpt_size_i;
#endif
	struct bb_ch_info_raw_info	bb_ch_info_raw_i; /*save dumped ch-info data*/

	u32 csi_raw_data_total_len;  /*Raw data length(Unit: byte) = total_len - 16*/
	u32 total_len_remnant;
	u8 seg_idx_pre;

	u8 b_skip_ch_info: 1; /*wait for seg_0*/
	u8 b_print_en: 1;
};

struct bb_info;

/*#ifdef PHYDM_CH_INFO_SUPPORT
	struct bb_ch_rpt_info bb_ch_rpt_i;
#endif

	enum phl_phy_idx bb_phy_idx;*/


/*@--------------------------[Parameter]-------------------------------------*/
#define CH_INFO_EMPTY_REPORT_EN_C		0x2008
#define CH_INFO_EMPTY_REPORT_EN_C_M		0x10000000


#endif
#endif
