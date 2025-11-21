#ifndef __WIFIFW_RATE_ADAPTIVE__
#define __WIFIFW_RATE_ADAPTIVE__

/*--------------------Define -------------------------------------------*/
#define MODE_MASK           0x80
#define MCS_MASK            0x7f

#define RATEIDX_MODE_OFFSET	7

#define TXRPTFIELD_RPT_SEL              (BIT7|BIT6|BIT5)
#define TX_STATUS_OK			0x0
#define TXRPT_AHB_BASE RTL8721DA_TRXRPT_BASE

/*--------------------Define Struct-------------------------------------*/
struct TxRpt_Cfg {
	//offset 0
	u8 tx_polluted: 1;
	u8 miss_rpt_num: 1;
	u8 rsvd0: 3;
	u8 rpt_sel: 3;
	//offset 1
	u8 rpt_qsel: 5;
	u8 collision_head: 1; //for 97G/12F
	u8 collision_tail: 1; //for 97G/12F
	u8 fixed_rate: 1; //driver fixed rate
	//offset 2
	u8 macid: 7;
	u8 rsvd2: 1;
	//offset 3
	u8 init_rate: 7;
	u8 init_gi: 1;
	//offset 4
	u8 ok_num: 6;
	u8 rsvd4: 1;
	u8 try_rate: 1;
	//offset 5
	u8 drop_num: 6;
	u8 bitmap_short: 2;
	//offset 6
	u8 sw_def;
	//offset 7
	u8 rts_rty_num: 4;
	u8 rts_rty_drop: 1;
	u8 rts_bmc: 1;
	u8 tx_state: 2;
	//offset 8
	u8 data_rty_count: 6;
	u8 rsvd8: 1; //only for 12F
	u8 ex_tx_state: 1;
	//offset 9
	u8 final_data_rate: 7;
	u8 final_gi: 1;
	//offset 10
	u8 ch_lsb;
	//offset 11
	u8 ch_msb: 2;
	u8 ch_sc: 4;
	u8 ch_bw: 2;
	//offset 12
	u8 total_cnt: 6; /*total number of MPDU have been transmitted*/
	u8 ppdu_type: 2; //dplus dont have,for common
	//offset 13
	u8 gid: 6;
	u8 tb_ppdu_flag: 1; //dplus dont have,for common
	u8 rsvd13: 1;
};

enum BW_TYPE {
	TYPE_BW_20M         = 0,
	TYPE_BW_40M         = 1,
	TYPE_BW_80M         = 2,
	TYPE_BW_160M        = 3

};

/*--------------------Function declaration------------------------------*/
extern void wififw_ra_init(void);
extern void wififw_ra_fallback_init(u8 macid, u8 ldpc_cap);
extern void wififw_ra_set_fallback_step_table(u64 fallback_step_table);
extern void wififw_ra_set_fallback_step(u8 init_rate, u8 init_rate_rty_cnt, u8 rty_rate_step);
extern void wififw_false_alarm_fetch(void);
extern u8 wififw_txrpt_tx_ok(struct TxRpt_Cfg *tx_rpt);
extern void wififw_ra_mask_low_rate(u8 low_rate);
extern void wififw_ra_issue_null_data(u8 macid, u8 rate_idx, u8 RtyLmt, u8 bw_idx);
extern u8 wififw_txrpt_valid_check(struct TxRpt_Cfg *tx_rpt);
#endif

