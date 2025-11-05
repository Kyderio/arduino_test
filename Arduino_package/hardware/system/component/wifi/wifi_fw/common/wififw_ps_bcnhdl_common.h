#ifndef __WIFIFW_PS_BCNHDL_COMMON_H__
#define __WIFIFW_PS_BCNHDL_COMMON_H__

extern u8 wififw_ps_get_bcn_early_agg_cnt(void);
extern void wififw_ps_set_bcn_early_agg_cnt(u8 bcn_early);
extern void wififw_ps_bcn_tim_parse(void);
extern void wififw_ps_bcnely_handle(u32 AggEly);
extern void wififw_ps_bcnely_handle_port1(void);
extern void wififw_ps_bcn_rx_handle(void);
extern void wififw_ps_dtim_rx_timeout_handle(void);
extern void wififw_ps_bcn_rx_timeout_handle(void);
extern void wififw_inthdl_bcnrx(void);
#endif
