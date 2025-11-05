#ifndef __WIFIFW_CTRLINFO_H__
#define __WIFIFW_CTRLINFO_H__

#define CTRLINFO_AHB_BASE	 RTL8721D_TRXRPT_BASE

struct CCTRL_INFO {
	//offset:0
	u32 data_rate: 7;
	u32 gi_ltf: 1;
	//offset 1
	u32 pwrsts: 3;
	u32 data_bw: 2;
	u32 fara_bw_en: 1;
	u32 try_rate: 1;
	u32 ampdu_time_en: 1;
	//offset 2
	u32 rsvd0: 8;
	//offset 3
	u32 data_rty_lowest_rate: 7;
	u32 rty_low_rate_en: 1;
	//0ffset 4
	u32 rts_rty_lowest_rate: 7;
	u32 rty_cnt_lmt_en: 1;
	//offset 5
	u32 rty_cnt_lmt: 6;
	u32 pkt_tx_one_sel: 1;
	u32 ampdu_size_en: 1;
	//offset 6
	u32 darf_tc_index: 2;	//dplus don't have, for common
	u32 protection_ctrl: 1;
	u32 cts2self: 1;
	u32 rts_en: 1;
	u32 hw_rts_en: 1;
	u32 smooth_ctrl: 1;
	u32 rsvd2: 1;
	//offset 7
	u32 ampdu_max_len: 4;
	u32 ampdu_max_time: 4;
	//offset 8
	u64 aes_iv: 48;
	u64 rsvd3: 16;
	//offset 16
	u64 mac_address: 48;
	u64 rsvd4: 16;
	//offset 24
	u8 tx_path_map_a: 2;
	u8 tx_path_map_b: 2;
	u8 tx_path_map_c: 2;
	u8 tx_path_map_d: 2;
	//offset 25
	u8 ntx_path_map: 4;
	u8 antsel_a: 4;
	//offset 26
	u8 antsel_b: 4;
	u8 antsel_c: 4;
	//offset 27
	u8 antsel_d: 4;
	u8 csi_txbf_en: 1;
	u8 csi_stbc_en: 1;
	u8 csi_ldpc_en: 1;
	u8 antsel_en: 1;
	//offset 28
	u8 mfb: 7;
	u8 ctrlpkt_chk_en: 1;
	//offset 29
	u8 resp_ref_rate: 7;	//tx_init_rate
	u8 rxid_match_en: 1;
	//offset 30
	u8 nc: 3;
	u8 nr: 3;
	u8 ng: 2;
	//offset 31
	u8 cb: 2;
	u8 coefficient_size: 2;
	u8 bssid_sel: 3;
	u8 bf_en: 1;
};

#endif
