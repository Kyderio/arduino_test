
#ifndef __WIFIFW_RA_NEW__
#define __WIFIFW_RA_NEW__

/*--------------------Define MACRO--------------------------------------*/
#define RATESIZE            108
#define MODE_MASK           0x30
#define MCS_MASK            0xf

#define RATEIDX_MODE_OFFSET	4

/*--------------------Define Struct---------------------------------------*/
struct TxRpt_Cfg {
	union {
		u32 txrpt_l;
		struct {
			//offset 0
			u32 cw_time: 7;
			u32 total_cnt: 4; /*total number of MPDU have been transmitted*/
			u32 data_rty_count: 6;
			u32 ok_num: 4;	//rpt_ok_pkt_num
			u32 drop_num: 4;	//rpt_drop_pkt_num
			u32 macid: 6;
			u32 tx_polluted: 1;
		};
	};

	union {
		u32 txrpt_h;
		struct {
			//offset 4
			u32 fixed_rate: 1; //driver fixed rate
			u32 init_bw: 1;
			u32 ch_bw: 1;	//final_bw
			u32 ack_rssi: 9;
			u32 sw_def: 8;
			u32 init_rate: 6;
			u32 final_data_rate: 6;	//final_rate
		};
	};

};

/*------------------------------Function declaration--------------------------*/
extern void wififw_ra_init(void);
extern void wififw_ra_fallback_rate_table_init(void);
extern void wififw_ra_fallback_init(u8 macid, u8 ldpc_cap);
extern void wififw_ra_set_fallback_step_table(u8 first_rate_rep, u8 second_rate_rep, u8 third_rate_rep);
extern void wififw_ra_set_fallback_step(u8 init_rate, u8 init_rate_rty_cnt, u8 rty_fallback_step);
extern void wififw_false_alarm_fetch(void);
extern void wififw_rx_err_fetch(void);
extern u8 wififw_txrpt_tx_ok(struct TxRpt_Cfg *tx_rpt);
extern void wififw_ra_mask_low_rate(u8 low_rate);
extern void wififw_ra_issue_null_data(u8 macid, u8 rate_idx, u8 RtyLmt, u8 bw_idx);
extern u8 wififw_txrpt_valid_check(struct TxRpt_Cfg *tx_rpt);
#endif