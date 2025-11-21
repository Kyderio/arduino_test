#ifndef __WIFIFW_INIT_RAM_H__
#define __WIFIFW_INIT_RAM_H__

#ifndef CONFIG_WIFI_FW_VERIFY
#define CONFIG_WIFI_FW_VERIFY 0
#endif

/* REG_FWHW_TXQ_HWSSN_CTRL[31:24] */
#define BIT_HWSEQ_VO_EN			BIT0
#define BIT_HWSEQ_VI_EN			BIT1
#define BIT_HWSEQ_BE_EN			BIT2
#define BIT_HWSEQ_BK_EN			BIT3
#define BIT_HWSEQ_MGT_EN		BIT4
#define BIT_HWSEQ_HI_EN			BIT5
#define BIT_HWSEQ_BCN_EN		BIT6
#define BIT_HWSEQ_CPUM_EN		BIT7

/*--------------------Function declaration---------------------------------*/
extern const char *TAG_FW_COM;
extern uint32_t irq_get_pending(IRQn_Type irqn);
extern void driver_fw_flow_ipc_int(void *Data, u32 IrqStatus, u32 ChanNum);
extern void wififw_initialize(void);
extern void wififw_init_func_pointer_table_rom(void);
extern void wififw_vera_test(void);
extern void wififw_int_init(void);

#endif /* __WIFIFW_INIT_RAM_H__ */

