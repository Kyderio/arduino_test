#ifndef __WIFIFW_RA_COMMON__
#define __WIFIFW_RA_COMMON__

#define RATE_UNUSED                     0xff

#ifdef RA_V3
#define RA_RETRY_LIMIT					62
#else
#define RA_RETRY_LIMIT					12
#endif

#define INIT_RATE_TRY_LMT 				1
#define FINAL_RATE_STATICS_NUM			20
#define MAX_RA_DEBUG_MACID				3

#define PHYDM_IS_LEGACY_RATE(rate) ((rate <= RATE_OFDM_54M) ? TRUE : FALSE)

#ifdef CONFIG_NAN
#define RA_MACID_NUM						22
#else
#define RA_MACID_NUM						14
#endif
enum ENABLE_MODE {
	TYPE_EN_CCK  = 0x1,
	TYPE_EN_OFDM = 0x2,
	TYPE_EN_HT = 0x4,
	TYPE_EN_VHT = 0x8,
	TYPE_EN_HE = 0x10,

};

enum rtw_gi_ltf {
	GILTF_LGI_4XHE32 = 0,
	GILTF_SGI_4XHE08 = 1,
	GILTF_2XHE16 = 2,
	GILTF_2XHE08 = 3,
	GILTF_1XHE16 = 4,
	GILTF_1XHE08 = 5,
	GILTF_MAX
};

enum current_mode {
	MODE_LEGACY	= 0,
	MODE_HT		= 1,
	MODE_VHT	= 2,
	MODE_HE		= 3,
};


/*-------------------------- Define Struct ------------------------------*/
struct RA_STA_INFO {
	u32 ra_mask: 23;
	u32 cck_mask_backup : 4;
	u32 Initial_BW: 2; /*max support bw*/
	u32 BW_setting: 2; /*current bw */
	u32 is_5g: 1;

	// su-ra info
	u8 highest_rate;
	u8 lowest_rate;
	u8 current_rate;

	u8 mode: 5;
	/*en_cck, en_legofdm, en_ht, en_vht, en_he*/
	u8 DISRA: 1;
	u8 SGI: 2;

	u8 bcn_rssi;

	u8 final_rate_ok[FINAL_RATE_STATICS_NUM];
	u8 final_rate_statics[RATE_MCS9 + 1];
	u8 init_rate_rty_up_failrate_cnt[RATE_MCS9 + 1];
	u8 rpt_seq: 6;
	u8 cck_enable: 1;
	u8 cck_only: 1;

	u8 is_rvr: 1;
	u8 rsvd: 7;

	u8 INIT_RATE_TXOK_PKT_CNT;

	u8 uprate_fail_tbtt_cnt: 4;
	u8 uprate_fail_tbtt_lmt: 4;
	u8 highest_init_rate_in_tbtt;

	u16 init_rate_tx_num[RATE_MCS9 + 1];
	u16 noretry_tx_ok_num[RATE_MCS9 + 1];
	u16 rty_cnt_statics[4]; //corresponding to rty=0, rty=1, rty=2, rty>2
	u16 rpt_cnt;
};

struct RA_DBG { /*the 4-th layer*/
	u32 rssi_min: 8;
	u32 drop_pkt: 24;
	u32 ok_pkt;
	u32 rty_cnt;
};

struct RA_PARM {
	struct RA_STA_INFO sta_info_list[RA_MACID_NUM];
	struct RA_DBG		ra_dbg[MAX_RA_DEBUG_MACID + 1];
	u8 			ra_dbg_en: 1;
	u8			sw_eaual_hw_idx: 1;
	u8			cck_low_rate: 4;
	u8			rsvd: 2;
};

struct ra_table_entry {
	u8 rate_idx;
	u8 lowest_rate;
	u8 uprate_fail_lmt;
	u8 uprate_fail_tbtt_lmt: 4;
	u8 uprate_pkt_lmt: 4;
	u8 hw_idx;
	u8 init_rate_rty_cnt;
	u8 rty_fallback_step;
};

/*--------------------Define MACRO--------------------------------------*/
extern const struct ra_table_entry ra_table[];
extern void wififw_ra_macid_cfg(u8 macid, u8 ldpc_cap);
extern u8 wififw_ra_rate_to_mode(u8 rate_idx);
extern u16 wififw_ra_rateidx_sw_to_hw(u8 macid, u8 rate_idx);
extern u8 wififw_ra_rateidx_hw_to_sw(u16 data_rate);
extern void wififw_ra_initial_rate_update(u8 macid, u8 rate_idx, u8 bw_idx);
extern void wififw_ra_rate_decision(u8 macid, u8 init_rate, u8 final_rate, u8 retry_count);
extern void wififw_ra_fallback_rate_mask_set(u8 macid);
extern void wififw_ra_null_decision(u8 macid, u8 final_rate, u8 bw_idx);
extern void wififw_ra_reset(void);
extern void wififw_ra_reset_initrate_lowest(u8 macid);
extern void wififw_ra_update_initrate_lowest(u8 macid, u8 final_rate, u8 rpt_seq);
extern u8 wififw_ra_select_offset_from_rate(u8 rate_idx);
extern void wififw_ra_tbtt(void);
#endif
