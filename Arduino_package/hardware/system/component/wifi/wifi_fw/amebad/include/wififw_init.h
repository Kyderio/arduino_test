#ifndef __WIFIFW_INIT_H__
#define __WIFIFW_INIT_H__


/*--------------------Function declaration---------------------------------*/
extern const char *TAG_FW_COM;

extern uint32_t irq_get_pending(IRQn_Type irqn);
extern u8 wifi_hal_wlan_int_disable(void);
extern void wifi_hal_wlan_int_enable(u8 irq_state);
extern void driver_fw_flow_ipc_int(void *Data,	u32 IrqStatus,	u32 ChanNum);
extern void wififw_vera_test(void);
extern void wififw_initialize(void);
extern void wififw_int_init(void);
extern void wififw_ctrlinfo_init(void);
extern void wififw_txrpt_init(void);
#endif

