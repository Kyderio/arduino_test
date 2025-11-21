#ifndef __WIFIFW_INTERRUPT_HANDLE_H__
#define __WIFIFW_INTERRUPT_HANDLE_H__

/*--------------------Define --------------------------------------------*/
#if defined (CONFIG_FW_DRIVER_COEXIST) && CONFIG_FW_DRIVER_COEXIST
extern u8 driver_resume_state;
#endif

/*--------------------Function declaration---------------------------------*/
extern void wififw_inthdl_rpwm(void);
extern void wififw_ps_cpwm_ack(u8 rpwm_val);
#endif  //__WIFIFW_INTERRUPT_HANDLE_H__

