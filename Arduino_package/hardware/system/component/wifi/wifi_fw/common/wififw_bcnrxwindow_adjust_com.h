#ifndef __WIFIFW_BCNRXWINDOW_ADJUST_COM_H__
#define __WIFIFW_BCNRXWINDOW_ADJUST_COM_H__

/*--------------------Define MACRO--------------------------------------*/
#define BCN_CATCHNUM            		100
#define BCN_DELAYMAX	                128//unit:128us, delay rx time max =128*128 us
#define ABNORMALGAP             		4//unit:128us, use for exclude abnormal data
#define MOSTBCNMISS						0xff
#define VALIDMINBCNELYCNT				0x2
#define DEFAULT_MULTIBCN_ADD			128//us

struct BcnWindow_Adjust_Stat {
	u8	Bcnlenvalid: 1;
	u8	BcnToCnt: 4;
	u8	TooManyBcnTo: 1;
	u8	rsvd: 2;
	u8	BcnRx128us[BCN_CATCHNUM];//100 bcn delay time
	u8	RxCnt[BCN_DELAYMAX];//every delay time cnt
	u8	RxNum;
	u8	TicklessCnt;
	u8	RxToNum;
	u8	BcnToExcluded;
	u8	BcnToOutput;
	u8	BcnElyPlus;
	u8	BcnElyOutput;
};


/*--------------------Function declaration---------------------------------*/
extern void wififw_inthdl_rxbcn_timeup(void);
extern void wififw_ps_bcnrx_window_adjust_reset(void);
extern void wififw_ps_get_bcn_adjust_output(void);
extern void wififw_ps_record_bcn_rx_delay(u8 bcnmissflag);
extern void wififw_ps_bcnrx_window_search(void);
extern void wififw_ps_bcnrx_window_update(void);
extern void wififw_ps_record_aptsft_diff(void);
extern void wififw_ps_get_aptsft_diff_ave(void);
extern u8 wififw_ps_get_bcnrx_tsf_offset_value(void);

#endif