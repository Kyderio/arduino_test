#ifndef __WIFIFW_INIT_H__
#define __WIFIFW_INIT_H__

//When this bit enable and EN_HWSEQ of TXDESC, MAC will overwrite MACHDR SEQ according to TXDESC QSEL
#define BIT_HWSEQ_MGT_EN		BIT4
//1: HW will report tx_status  0: no report BIT0: BK Queue BIT1: BE Queue BIT2: VI Queue BIT3: VO Queue BIT4: MGT Queue BIT5: HG Queue BIT6: BCN Queue BIT7: TB Queue
#define BIT_TXRPT_MGT_EN		BIT4
/* FW/DRIVER Message BIT */
#define BIT_WOW_EN              BIT0

/*--------------------Function declaration---------------------------------*/
extern const char *TAG_FW_COM;

extern u8 wifi_hal_wlan_int_disable(void);
extern void wifi_hal_wlan_int_enable(u8 irq_state);
extern void driver_fw_flow_ipc_int(void *Data, u32 IrqStatus, u32 ChanNum);
extern void wififw_vera_test(void);
extern void wififw_initialize(void);
extern void wififw_int_init(void);

#endif /* __WIFIFW_INIT_H__ */
