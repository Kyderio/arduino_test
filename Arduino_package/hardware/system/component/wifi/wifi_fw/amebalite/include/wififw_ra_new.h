
#ifndef __WIFIFW_RA_NEW__
#define __WIFIFW_RA_NEW__

/*--------------------Define MACRO--------------------------------------*/
#define TXRPTFIELD_RPT_SEL              (BIT7|BIT6|BIT5)
#define TXRPT_UPDATE_RSSI_CNT 10
#define TX_STATUS_OK			0x8
#define TXRPT_AHB_BASE	 RTL8720E_TRXRPT_AHB_BASE

#define RATESIZE                        108
#define MODE_MASK           0x180
#define MCS_MASK            0x01f

#define RATEIDX_MODE_OFFSET	7

/*--------------------Define Struct---------------------------------------*/
struct TxRpt_Cfg {
	//offset 0
	u8 tx_polluted: 1;
	u8 tx_state: 4;
	u8 rpt_sel: 3;
	//offset 1
	u8 rpt_qsel: 5;
	u8 collision_head: 1; //for 97G/12F
	u8 collision_tail: 1; //for 97G/12F
	u8 fixed_rate: 1; //driver fixed rate
	//offset 2
	u16 macid: 7;
	//offset 3
	u16 init_rate: 9;
	//offset 4
	u8 ok_num: 6;
	u8 rsvd0: 1;
	u8 try_rate: 1;
	//offset 5
	u8 drop_num: 6;
	u8 rsvd1: 2;
	//offset 6
	u8 sw_def;
	//offset 7
	u8 rts_rty_count: 4;
	u8 tb_ppdu_flag: 1;
	u8 rts_bmc: 1;
	u8 rx_polluted: 1;
	u8 rsvd2: 1;
	//offset 8
	u16 data_rty_count: 6;
	//offset 9
	u16 final_data_rate: 9;
	u16 rsvd3: 1;
	//offset 10
	u8 rsvd4;
	//offset 11
	u8 rsvd5: 2;
	u8 ch_sc: 4;
	u8 ch_bw: 2;
	//offset 12
	u8 total_cnt: 6; /*total number of MPDU have been transmitted*/
	u8 ppdu_type: 2;
	//offset 13
	u8 zero_retry_pkt_num: 6;
	u8 rsvd: 2;
	//offset 14
	u16 bSR: 1;
	u16 init_data_gi_ltf: 3;
	u16 final_gi_ltf: 3;
	//offset 15
	u16 txpwr_pd: 5;
};

/*------------------------------Function declaration--------------------------*/
extern void wififw_ra_init(void);
extern void wififw_ra_fallback_rate_table_init(void);
extern void wififw_ra_fallback_init(u8 macid, u8 ldpc_cap);
extern void wififw_ra_set_fallback_step_table(u64 fallback_step_table);
extern void wififw_ra_set_fallback_step(u8 init_rate, u8 init_rate_rty_cnt, u8 rty_fallback_step);
extern void wififw_false_alarm_fetch(void);
extern void wififw_rx_err_fetch(void);
extern u8 wififw_txrpt_tx_ok(struct TxRpt_Cfg *tx_rpt);
extern void wififw_ra_mask_low_rate(u8 low_rate);
extern void wififw_ra_issue_null_data(u8 macid, u8 rate_idx, u8 RtyLmt, u8 bw_idx);
extern u8 wififw_txrpt_valid_check(struct TxRpt_Cfg *tx_rpt);
#endif
