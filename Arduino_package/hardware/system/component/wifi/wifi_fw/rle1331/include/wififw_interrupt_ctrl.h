#ifndef __WIFIFW_INTERRUPT_CTRL_H__
#define __WIFIFW_INTERRUPT_CTRL_H__

extern const u16 fimr_addr[4];
extern const u16 fisr_addr[4];

/*------------------------------Function declaration--------------------------*/
extern int rtos_critical_is_in_interrupt(void);
extern void wififw_int_disable(void);
extern void wififw_int_enable(void);
extern void wififw_int_reset(void);
extern void wififw_int_update_wlan_isr(u32 *fisr);
extern void wififw_int_set_wlan_imr(u32 index, u32 bitmask);
extern void wififw_int_clr_wlan_imr(u32 index, u32 bitmask);

#endif