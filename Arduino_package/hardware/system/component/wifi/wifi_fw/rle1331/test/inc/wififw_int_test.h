#ifndef __WIFIFW_INT_TEST_H__
#define __WIFIFW_INT_TEST_H__

#define WAIT_TSF_STABLE_BREAK_CNT       (5000)
#define TSFIS32K                        1
#define TSFIS40M                        0
#define GET_TSF_STATE() ((HAL_READ16(WIFI_REG_BASE, REG_WL_CLK_CTRL) & BIT_TSF_IS_32K) ? TSFIS32K : TSFIS40M)

enum PSTIMER_TEST {
	TIMERA = 0,
	TIMERB,
	TIMERC,
	TIMERD,
	TIMERE,
};


extern void wififw_wlan_inttest_handle(void);
extern void lpsoffload_inttest(void);
extern void wififw_set_bcn_agg_imr(u8 on);
extern void GTimerTest(u8 Gtimerid, u32 timeout_ms);
extern void PSTimerTest(u8 PSTimerid, u32 interval_ms, u8 elytime_ms);
extern void RXBCN_TSF_GT_THRES_INTtest(void);
extern void EDCCA_IDLE_TOCNT_INTtest(void);
extern void lpsoffloadsimplifyenbale(void);
extern void HIOEDelayModeTest(void);
extern void wififw_hioe_chn_bbmac_hw_init(void);
extern void wififw_hioe_chn_mac_hw0_test(void);
extern void wififw_hioe_chn_mac_hw1_test(void);
extern void wififw_hioe_chn_bb_hw_lowpri_test(void);
extern void wififw_hioe_chn_bb_hw_highpri_test(void);
#endif  /* __WIFIFW_INT_TEST_H__ */