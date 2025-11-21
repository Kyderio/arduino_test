#ifndef __ROM_WIFI_HAL_MACID_CAM_H__
#define __ROM_WIFI_HAL_MACID_CAM_H__

#define MACIDCAM_ATTRI_REFUGEE_HIT          BIT(0)  // used in relay mode
#define MACIDCAM_ATTRI_REPEAT_HIT           BIT(2)  // used in repeat/booster mode. if repeat_hit, use macid_cam search result of A1 to search key; otherwise, use A2 result to search key
#define MACIDCAM_ATTRI_REPEAT_AP_HIT        BIT(3)  // used in MBSSID of V-AP
#define MACIDCAM_ATTRI_SUPER_A3_HIT         BIT(4)
#define MACIDCAM_ATTRI_MBSSID_HIT           BIT(6)

enum MACIDCAM_BASE_OPTION {
	CTRLINFO_OPTION = 0,
	KEYCFG_OPTION = 1,
	KEY_OPTION = 2,
	RXFILTER_OPTION = 3,
	MAX_OPTION = 0xff
};

/* 64bit */
struct ctrlinfo_priv {
	/* offset 0 */
	u32 addr_l;

	/* offset 4 */
	u32 addr_h : 16;
	u32 refugee_fit : 1;
	u32 rsvd_0417 : 1;
	u32 repeat_fit : 1;
	u32 repeat_ap_fit : 1;
	u32 super_a3_fit : 1;
	u32 rsvd_0421 : 1;
	u32 mbssid_fit : 1;
	u32 rsvd_0423 : 9;

	/* offset 8 */
	u32 data_rate : 6;
	u32 rsvd_0806 : 1;
	u32 data_bw : 1;
	u32 gi_ltf : 3;
	u32 darf_tc_idx : 1;
	u32 rsvd0812 : 1;
	u32 dcm : 1;
	u32 data_er : 1;
	u32 data_bw_er : 1;
	u32 retry_limit : 5;
	u32 rsvd_0817 : 1;
	u32 agg_en : 1;
	u32 use_ctrl_info : 1;
	u32 rsvd0820 : 1;
	u32 txpwr_tolerance : 6;
	u32 dis_sr : 1;

	/* offset 12 */
	u32 uldl : 1;
	u32 norminal_pkt_padding : 2;
	u32 bsrq_size_format : 1;
	u32 smooth_ctrl : 1;
	u32 a_ctrl : 4;
	u32 all_ack_support : 1;
	u32 ctrl_wrapper_en : 1;
	u32 rxid_match : 1;
	u32 rsvd1212 : 2;
	u32 ofdma_force_rts : 1;
	u32 ht_force_rts : 1;
	u32 rts_rty_limit : 5;
	u32 rsvd0421 : 5;
	u32 data_lowest_rate : 6;
};


void ROM_WIFI_InitCAMCfg(u8 crc5_num, u8 key_num, u8 ba_num, u8 rxfilter_num);
void ROM_WIFI_SET_CRC5(u32 base_addr, u8 *mac_addr, u8 macid);
void ROM_WIFI_SET_CTRLINFO_ADDR(u32 base_addr, u8 *mac_addr, u8 macid);
void ROM_WIFI_SET_CTRLINFO_ATTRI(u32 base_addr, u16 attri, u8 macid);
void ROM_WIFI_GET_CTRLINFO_FILED(u32 base_addr, u8 macid, u8 *mac_addr, u16 *attri, u32 *ctrlinfo, u32 *respinfo);
u32 ROM_WIFI_GET_MACIDCAM_BASE(u8 option);
#endif