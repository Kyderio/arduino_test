#ifndef __WIFIFW_CTRLINFO_H__
#define __WIFIFW_CTRLINFO_H__

#define CTRLINFO_AHB_BASE	 RTL8721F_CtrlInfo_AHB_BASE

struct CCTRL_INFO {
	//offset:0
	u32 data_rate: 9;
	u32 dis_sr: 1;
	u32 data_bw: 2;
	u32 gi_ltf: 3;
	u32 darf_tc_index: 1;
	u32 arfr_ctrl: 4;
	u32 rsvd0: 1;
	u32 protection_en: 1;
	u32 rts_en: 1;
	u32 cts2self: 1;
	u32 hw_rts_en: 1;
	u32 rsvd1: 6;
	u32 rty_low_rate_en: 1;
	//offset 4
	u32 data_rty_lowest_rate: 9;
	u32 ampdu_time_en: 1;
	u32 ampdu_max_time: 4;
	u32 rsvd2: 4;
	u32 lsig_txop_en: 1;
	u32 force_txop: 1;
	u32 try_rate: 1;
	u32 fara_bw_en: 1;
	u32 pkt_tx_one_sel: 1;
	u32 rts_rty_lowest_rate: 9;
	//offset 8
	u32 rty_cnt_lmt_en: 1;
	u32 rty_cnt_lmt: 6;
	u32 max_agg_num_en: 1;
	u32 max_agg_num: 5;
	u32 ampdu_len_en: 1;
	u32 ampdu_max_len: 11;
	u32 rsvd3: 7;
	//offset 12
	u32 txpwr_tolenrance: 6;
	u32 dcm: 1;
	u32 extend_range: 1;
	u32 data_bw_er: 1;
	u32 data_ldpc: 1;
	u32 data_stbc: 1;
	u32 ul_dl: 1;
	u32 doppler_ctl: 2;
	u32 nomi_pad20: 2;
	u32 a_ctrl: 4;
	u32 bsr_que_size: 1;
	u32 smooth_ctrl: 1;
	u32 rsvd4: 1;
	u32 ctrl_wrapper_en: 1;
	u32 rxid_match_en: 1;
	u32 bsr_om_upd_en: 1;
	u32 rsvd5: 6;
	//offset 16
	u32 rsvd6: 10;
	u32 paid: 9;
	u32 nc: 3;
	u32 nr: 3;
	u32 ng: 2;
	u32 cb: 2;
	u32 coeffoc_size: 2;
	u32 csi_txbf_en: 1;
	//offset 20
	u32 csi_ldpc_en: 1;
	u32 csi_stbc_em: 1;
	u32 csi_para_en: 1;
	u32 csi_fix_rate: 9;
	u32 csi_bw: 2;
	u32 ctrlpkt_chk_en: 1;
	u32 all_ack_support: 1;
	u32 resp_ref_rate: 9;
	u32 mfb: 7;
};

#endif
