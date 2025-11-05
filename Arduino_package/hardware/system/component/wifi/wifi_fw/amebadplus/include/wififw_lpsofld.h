#ifndef _WIFIFW_LPSOFLD_H_
#define _WIFIFW_LPSOFLD_H_

/*--------------------Define --------------------------------------------*/
#define LPSOfld_WaitFCSToms	(10)
#define LPSOfld_HIOEOnClrIntCmdNum	(3) //unit 8 bytes
#define LPSOfld_BCNTO	(10000)//us
#define LPSOfld_TSFT_DIFF_THRES	(200)//us
#define KeyCAMHIOEEntrySize (16)
#define HIOECMD_RfcRegBaseAddr		(0x3c00)
#define RFCRegToByteAddr(x)		((x)<<2)
#define LPSOfld_BcnTo_MaxLimit		3
#define LPSOfld_BcnTo_MinLimit		1
#define LPSOfld_BcnTo_MidLimit		2
#define PTimerA_KEEPALIVE_TIME		20
#define LPSOFLD_FAKE_BCNRX_CNT	10
#define CPU_Compensation_Time		50//us
#define Bcn_Early_Compensation_Time		10//ms
#define Bcn_Timeout_Compensation_Time		20000//us
#define TSF_DIFF_Threshold_Min		10000//us
#define TSF_DIFF_Threshold_Margin		2000//us

/*------------------------------Function declaration--------------------------*/
extern void wififw_hw_rxbcn_cnt_statistic_init(void);
extern void wififw_rfoff_by_edcca_init(void);
#endif
