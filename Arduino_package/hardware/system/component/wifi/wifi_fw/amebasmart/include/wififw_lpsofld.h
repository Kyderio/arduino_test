#ifndef _WIFIFW_LPSOFLD_H_
#define _WIFIFW_LPSOFLD_H_

/*--------------------Define --------------------------------------------*/
#define LPS_KeepCurrentVal	(0xFF)
#define LPSOfld_WaitFCSToms	(10)

#ifdef CONFIG_AMEBASMART
#define LPSOfld_HIOEOnClrIntCmdNum	(2) //unit 8 bytes
#else
#define LPSOfld_HIOEOnClrIntCmdNum	(3) //unit 8 bytes /*smartplus fpga test use*/
#endif

#define LPSOfld_BCNTO	(10000)//us
#define LPSOfld_TSFT_DIFF_THRES	(1000)//us
#define KeyCAMHIOEEntrySize (16) //coresponding to 8 dword per key cam entry format
#define LPSOfld_BcnTo_MaxLimit		3
#define LPSOfld_BcnTo_MinLimit		1
#define LPSOfld_BcnTo_MidLimit		2
#define DEFAULT_BCN_TOCNT_THRES 5
#define LPSOFLD_FAKE_BCNRX_CNT	10

/*------------------------------Function declaration--------------------------*/

#endif
