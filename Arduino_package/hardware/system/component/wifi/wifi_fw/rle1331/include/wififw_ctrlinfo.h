#ifndef __WIFIFW_CTRLINFO_H__
#define __WIFIFW_CTRLINFO_H__

#define CTRLINFO_AHB_BASE	 RLE1331_CtrlInfo_AHB_BASE

struct ctrl_info {
	//offset:0
	u32 address_l;

	//offset:4
	u32 address_h: 16;
	u32 refugee_fit: 1;
	u32 rsvd0417: 1;
	u32 repeat_fit: 1;
	u32 repeat_vap_fit: 1;
	u32 super_a3_fit: 1;
	u32 rsvd0421: 1;
	u32 mbssid_fit: 1;
	u32 rsvd0423: 9;

	//offset 8
	u32 data_rate: 6;
	u32 rsvd0806: 1;
	u32 data_bw: 1;
	u32 gi_ltf: 3;
	u32 darf_tc_index: 1;
	u32 rsvd0812: 1;
	u32 dcm: 1;
	u32 data_er: 1;
	u32 data_bw_er: 1;
	u32 retry_limit: 5;
	u32 rsvd0821: 1;
	u32 agg_en: 1;
	u32 use_ctrl_info_agg: 1;
	u32 rsvd0824: 1;
	u32 txpwr_tolerence: 6;
	u32 dis_sr: 1;

	//offset 12
	u32 ul_dl: 1;
	u32 nominal_pkt_padding: 2;
	u32 bsr_queue_size: 1;
	u32 smooth_ctrl: 1;
	u32 a_ctrl_bqr: 1;
	u32 a_ctrl_uph: 1;
	u32 a_ctrl_bsr: 1;
	u32 a_ctrl_cas: 1;
	u32 all_ack_support: 1;
	u32 ctrl_wrapper_en: 1;
	u32 rxid_match: 1;
	u32 rsvd1212: 2;
	u32 ofdma_force_rts : 1;
	u32 ht_force_rts : 1;
	u32 rts_retry_limit : 5;
	u32 rsvd1221 : 5;
	u32 data_lowest_rate: 6;
};

#endif
