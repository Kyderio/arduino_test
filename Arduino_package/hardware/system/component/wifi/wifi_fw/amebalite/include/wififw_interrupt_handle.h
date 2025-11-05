#ifndef __WIFIFW_INTERRUPT_HANDLE_H__
#define __WIFIFW_INTERRUPT_HANDLE_H__
/*--------------------Function declaration---------------------------------*/
extern void wififw_inthdl_rpwm(void);
extern void wififw_ps_cpwm_ack(u8 rpwm_val);
extern u16 wififw_get_hioe_txff_start_addr(void);
extern void wififw_lps_option_set(void);
#endif  /* __WIFIFW_INTERRUPT_HANDLE_H__ */
