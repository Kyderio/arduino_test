#ifndef __WIFIFW_INTERRUPT_CTRL_COMMON_H__
#define __WIFIFW_INTERRUPT_CTRL_COMMON_H__

extern const u16 fwimr_addr[2];
extern const u16 fwisr_addr[2];
extern const u16 wlanimr_addr[6];
extern const u16 wlanisr_addr[6];
extern const u16 ftimr_addr[3];
extern const u16 ftisr_addr[3];

/*------------------------------Function declaration--------------------------*/
extern uint32_t ulSetInterruptMaskFromISR(void) __attribute__((naked));
extern void vClearInterruptMaskFromISR(uint32_t ulMask)  __attribute__((naked));

extern int rtos_critical_is_in_interrupt(void);
extern void wififw_int_disable(void);
extern void wififw_int_enable(void);
extern void wififw_int_reset(void);
extern void wififw_int_update_wlan_isr(u32 *wlanisr, u32 *fwisr);
extern void wififw_int_update_ft_isr(u32 *ftisr);
extern void wififw_int_set_fw_imr(u32 index, u32 bitmask);
extern void wififw_int_clr_fw_imr(u32 index, u32 bitmask);
extern void wififw_int_set_wlan_imr(u32 index, u32 bitmask);
extern void wififw_int_clr_wlan_imr(u32 index, u32 bitmask);
extern void wififw_int_set_ft_imr(u32 index, u32 bitmask);
extern void wififw_int_clr_ft_imr(u32 index, u32 bitmask);

#endif

