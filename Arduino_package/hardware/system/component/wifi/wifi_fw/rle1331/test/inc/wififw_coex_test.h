#ifndef __WIFIFW_COEX_TEST_H__
#define __WIFIFW_COEX_TEST_H__

enum WifiWithBtCOEX_TABLE_Type {
	BT_WL	= 0x0,                                      //BT > WL
	WL_BT	= 0x1,                                      //WL > BT
	WLHighPri_BT_WLLowPri	= 0x2,                      //WL high-pri > BT > WL low-pri
	BTHighPri_WL_BTLowPri	= 0x3,                      //BT high-pri > WL > BT low-pri
	WLHighPri_BTHighPri_WLLowPri_BTLowPri	= 0x4,      //WL high-Pri > BT high-Pri > WL low-Pri > BT low-Pri
	BTHighPri_WLHighPri_BTLowPri_WLLowPri	= 0x5,      //BT high-Pri > WL high-Pri > BT low-Pri > WL low-Pri
	WL_EQUAL_BT	= 0x6,                                  //WL = BT
	WB_TABLE_MAX
};


extern void PTATest(u8 dbgportselect, u8 tablecase, u8 btselect);
extern void WifiWithBtRTKmodePTATest(u8 dbgportselect, u8 tablecase, u8 btselect);
extern void PTA_Test_Choose(void);
extern void PTA_Test_Wifipri_Choose(void);

#endif      /* #ifndef __WIFIFW_COEX_TEST_H__ */