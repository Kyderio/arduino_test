#ifndef __WIFIFW_RATE_ADAPTIVE__
#define __WIFIFW_RATE_ADAPTIVE__

/*--------------------Define -------------------------------------------*/
#define MODE_MASK           0x80
#define MCS_MASK            0x7f

#define TXRPT_AHB_BASE RTL8721D_TRXRPT_BASE

/*--------------------Define Struct-------------------------------------*/
struct TxRpt_Cfg {
	//offset:0
	u32 data_rate: 7;
	u32 gi_ltf: 1;
	//offset 1
	u32 pwrsts: 3;
	u32 try_ness_cnt: 4;
	u32 try_rate: 1;
	//offset 2
	u32 rsvd0: 6;
	u32 try_result: 1;
	u32 try_finish: 1;
	//offset 3
	u32 rsvd1: 6;
	u32 pause_rpt: 1;
	u32 rst_rpt: 1;
	//0ffset 4
	u32 rts_drop_count: 8;
	//offset 5
	u32 data_bw: 2;
	u32 pkt_drop: 1;
	u32 smooth: 1;
	u32 rsvd2: 4;
	//offset 6/7
	u32 total_pkt_cnt: 16;
	//offset 8
	u32 li_drop: 8;
	//offset 9
	u32 rty_drop: 8;
	//offset 10/11
	u32 rty0: 16;
	//offset 12
	u32 rty1: 8;
	//offset 13
	u32 rty2: 8;
	//offset 14
	u32 rty3: 8;
	//offset 15
	u32 rty4: 8;
};

struct CcxRpt_Cfg {
	//offset 0
	u8 qsel: 5;
	u8 bmc: 1;
	u8 life_time_over: 1;
	u8 retry_over: 1;
	//offset 1
	u8 macid;
	//offset 2
	u8 data_rty_count: 6;
	u8 rsvd1: 2;
	//offset 3
	u8 queue_time_l;
	//offset 4
	u8 queue_time_h;
	//offset 5
	u8 final_rate;
	//offset 6
	u8 sw_def_l;
	//offset 7
	u8 sw_def_h: 4;
	u8 rsvd2: 4;
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
extern void wififw_ra_mask_low_rate(u8 low_rate);
extern void wififw_false_alarm_fetch(void);
extern void wififw_ccxrpt_fetch(void);
#endif