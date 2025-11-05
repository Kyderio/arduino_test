#ifndef __WIFIFW_INTERRUPT_HANDLE_H__
#define __WIFIFW_INTERRUPT_HANDLE_H__

#if defined (CONFIG_FW_DRIVER_COEXIST) && CONFIG_FW_DRIVER_COEXIST
extern u8 driver_resume_state;
#endif

/*--------------------Function declaration---------------------------------*/
extern void wififw_wlan_int_handle(void);
extern void wififw_inthdl_tbtt(void);
extern void wififw_inthdl_rpwm(void);
extern void wififw_ps_cpwm_ack(u8 need_cpwm_ack);
extern u16 wififw_get_hioe_txff_start_addr(void);
extern void wififw_lps_option_set(void);
#endif  //__WIFIFW_INTERRUPT_HANDLE_H__

