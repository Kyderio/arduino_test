#ifndef __WIFIFW_INTERRUPT_CTRL_COMMON_H__
#define __WIFIFW_INTERRUPT_CTRL_COMMON_H__

extern const u16 fwimr_addr;
extern const u16 fwisr_addr;
extern const u16 wlanimr_addr;
extern const u16 wlanisr_addr;
extern const u16 ftimr_addr;
extern const u16 ftisr_addr;

/*------------------------------Function declaration--------------------------*/
extern uint32_t ulSetInterruptMaskFromISR(void) __attribute__((naked));
extern void vClearInterruptMaskFromISR(uint32_t ulMask)  __attribute__((naked));

extern int rtos_critical_is_in_interrupt(void);
extern void wififw_int_disable(void);
extern void wififw_int_enable(void);
extern void wififw_int_reset(void);
extern void wififw_int_update_wlan_isr(u32 *fwisr, u32 *wlanisr);
extern void wififw_int_update_ft_isr(u32 *ftisr);
extern void wififw_int_set_fw_imr(u32 index, u32 bitmask);
extern void wififw_int_clr_fw_imr(u32 index, u32 bitmask);
extern void wififw_int_set_wlan_imr(u32 index, u32 bitmask);
extern void wififw_int_clr_wlan_imr(u32 index, u32 bitmask);
extern void wififw_int_set_ft_imr(u32 index, u32 bitmask);
extern void wififw_int_clr_ft_imr(u32 index, u32 bitmask);
extern void wififw_wlan_int_handle(void);
extern void wififw_ft_int_handle(void);
extern void wififw_inthdl_bcnearly(u32 AggEly);
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
#endif

