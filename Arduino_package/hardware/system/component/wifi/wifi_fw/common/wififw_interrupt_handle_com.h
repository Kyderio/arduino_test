#ifndef __WIFIFW_INTERRUPT_HANDLE_COM_H__
#define __WIFIFW_INTERRUPT_HANDLE_COM_H__

/*--------------------Define --------------------------------------------*/

/*--------------------Function declaration---------------------------------*/
extern void wififw_wlan_int_handle(void);
extern void wififw_ft_int_handle(void);
extern void wififw_inthdl_bcnearly(u32 AggEly);
extern void wififw_inthdl_bcnearly_port1(void);
extern void wififw_inthdl_rxdone(void);
extern void wififw_inthdl_rxbmc_with_more_data(void);
extern void wififw_inthdl_rxbmc_no_more_data(void);
extern void wififw_inthdl_rxunic_with_more_data(void);
extern void wififw_inthdl_rxunic_no_more_data(void);
extern void wififw_inthdl_nulldata0_finish(void);
extern void wififw_inthdl_nulldata1_finish(void);
extern void wififw_inthdl_dwearly(void);
extern void wififw_inthdl_dwstart(void);
extern void wififw_inthdl_trigger_pkt(void);
extern void wififw_inthdl_eosp(void);
extern void wififw_inthdl_rx_uapsdmd0(void);
extern void wififw_inthdl_rx_uapsdmd1(void);

extern void wififw_inthdl_tbtt(void);
extern u8 wififw_txpkt_nulldata_result(u8 pwr_bit);
extern u8 wififw_txpkt_get_rsvdpage_head(void);

extern void wififw_int_tbtt_agg_imr_enable(u8 on);
extern void wififw_int_tbtt0_imr_enable(u8 on);
#endif  //__WIFIFW_INTERRUPT_HANDLE_COM_H__

