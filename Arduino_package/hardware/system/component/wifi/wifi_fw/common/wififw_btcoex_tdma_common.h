#ifndef __WIFIFW_BTCOEX_TDMA_H__
#define __WIFIFW_BTCOEX_TDMA_H__

#ifndef __ASSEMBLY__
/*--------------------Define MACRO--------------------------------------*/
#define DEFAULT_WLSLOT_BCN_TO_PERIOD		(5)

#define BTC_TDMA_100MS_INTERVAL     100
#define BTC_TDMA_50MS_INTERVAL      50

#define BTC_LEAK_AP_LIMIT           5
#define BTC_LEAK_AP_EXT_MS          5

#define BTC_SEL_COEX_TABLE_BT		0x03   //0x6CC[1:0]=2'b11 -> select 0x6C0
#define BTC_SEL_COEX_TABLE_WL		0xFC   //0x6CC[1:0]=2'b00 -> select 0x6C4

#define BTC_TDMA_TX_NULL1_MS		2 //ms
#define BTC_TDMA_TX_BTQNULL_MS		2 //ms
#define BTC_TDMA_NULL_EARLY_MS		((BTC_TDMA_TX_NULL1_MS > BTC_TDMA_TX_BTQNULL_MS) ? BTC_TDMA_TX_NULL1_MS : BTC_TDMA_TX_BTQNULL_MS) //ms
#define BTC_TDMA_SW_TIME			500 //us
#define BTC_TDMA_TX_NULL1_US		((BTC_TDMA_TX_NULL1_MS << 10) - BTC_TDMA_SW_TIME)   //us
#define BTC_TDMA_TX_BTQNULL_US		((BTC_TDMA_TX_BTQNULL_MS << 10) - BTC_TDMA_SW_TIME) //us
#define BTC_TDMA_WL2BT_US			3*32 //us

#define BTC_TDMA_NULL1_EXT_NUM			5
#define BT_CTRL_TDMA_NULL1_EXT_NUM		2
#define BT_CTRL_TDMA_MAILBOX_DELAY_MS	1 //ms

#define BT_CTRL_TDMA_BCN_EARLY_MS      			1 //ms
#define BT_CTRL_TDMA_BCN_WINDOW_DEFAULT			4
#define BT_CTRL_TDMA_BCN_COUNT_BASE_DEFAULT		(20-1)   //range is 1-32
#define BT_CTRL_TDMA_BCN_THRESHOLD_DEFAULT		2

#if CONFIG_BTCOEX_SLOT_DEBUG
#define BTC_DBG_SLOT_TRACE(GPIO_Pin, Val)            ( wififw_btc_dbg_slot_trace((u32) GPIO_Pin, (u32) Val) )
#define BTC_DBG_GPIO_TOGGLE(GPIO_Pin)                ( wififw_btc_dbg_gpio_toggle((u32) GPIO_Pin) )
#else
#define BTC_DBG_SLOT_TRACE(GPIO_Pin, Val)
#define BTC_DBG_GPIO_TOGGLE(GPIO_Pin)
#endif

/*--------------------Define Enum---------------------------------------*/
enum BTC_Function_Type {
	TBTT_TDMA                 = 0,
	TBTT_ISR                  = 1
};

enum BTC_Slot_Type {
	TDMA_WL_SLOT_COEX_TABLE		= 0,
	TDMA_BT_SLOT_COEX_TABLE		= 1,
	PTA_COEX_TABLE				= 2
};

enum BTC_Tdma_Slot_Index {
	TDMA_WL_SLOT              = 0,
	TDMA_WL2BT_SLOT           = 1,
	TDMA_BT_SLOT              = 2,
	MAX_TDMA_SLOT_IDX         = 3,
};

enum BTC_BT_State {
	BT_OFF		= 0,
	BT_ON		= 1
};

enum BTC_CCK_Priority {
	PRI_LOW		= 0,
	PRI_HIGH	= 1
};

enum BTC_Multi_Slot_Type {
	BTC_TDMA_INSERT_MODE		= 0,//insert several tdma periods as fake bcn interval
	BTC_TDMA_SKIP_MODE			= 1,//skip several bcn interval to forming a longer tdma period than the origin bcn interval(eg.50ms)
};

enum BTC_PTA_Signal_Mode {
	BT_PTA_SIG_RTK_MODE			= 0,
	BT_PTA_SIG_ENH3WIRE_MODE	= 1,
	BT_PTA_SIG_DIRECT_MODE		= 2
};

enum C2HRPT_Mailbox_Fail_Reason {
	MAILBOX_FAIL_HWBUF_FULL		= 1,
	MAILBOX_FAIL_BT_OFF			= 2,
	MAILBOX_FAIL_BT_IN_LPS		= 3,
	MAILBOX_FAIL_ID_MISMATCH	= 4,
};
/*--------------------Define Struct---------------------------------------*/
struct BTC_PsTdma_Parm {
	struct btc_mailbox_format	mailbox_backup;//byte0: mailbox id, byte1 mailbox len, byte2~: mailbox content
	struct h2c_bt_tdma			TdmaH2cTemp;
	u16 tdma_period;
	u8	WLSlotLen;  //unit ms
	u8	WifiActive				: 1;
	u8	TxNull1					: 1;
	u8	TxNull1ok				: 1;
	u8	PTASignalMode			: 2;
	u8	AutoSlotBackup			: 1;
	u8	DynamicSlotOn		    : 1;
	u8	SecondBtSlotOn		    : 1;

	u8	CurrentSlot;
	u8	NullExtensionCount;

	u8	InWlSlot				: 1;
	u8	MultiSlotInsertSkipCnt	: 6;
	u8	rsvd					: 1;

	u8	TdmaLeakAPModeDisable	: 1;
	u8	LeakAPCnt				: 7;
	u8	LeakAPRxCnt;

	u8	TbttISRCnt;    /* Count the TBTT function called by TBTT ISR but not TDMA. */

	u8  H2cWlSlotLenBackup;  //ms
	u8	WlSlotDuration;  //ms
	u32	Wifi2BtSlotDuration;  //us
	u8	BtSlotDuration;  //ms
	u8  RecordPowerMode;

	u8  FirstBtSlotLen;
	u8  NextBtSlotStartTime;

#if LE_AUDIO_SUPPORT
	u8  ProtectBCNOn              : 1;
	u8  LastTimeBCNRxOK           : 1;
	u8  Rsvd1                     : 6;

	u32 RecordBCNRxOK;
	u8  LeAudioISOInterval;
	u8  TBTTCountBase;
	u8  BCNRxThreshold;
	u8  ProtectBCNWindow;
	u8  MailboxRecord[7];
#endif
};

/*--------------------Function declaration---------------------------------*/
extern void wififw_btc_tbtt_prohibit_set(u8 enable, u16 time_before_tbtt_us, u8 time_after_tbtt_ms);
extern void wififw_btc_tdma_lps_state_set(void);
extern void wififw_btc_init(void);
extern void wififw_btc_rxbcn_protect_set(u16 time_before_tbtt_us, u16 duration_us);
extern void wififw_btc_write_reg778(u8 value);
extern void wififw_btc_change_coex_table(u8 slot);
extern u16 wififw_btc_wlslotlen_convert_from_percent(u16 tdma_period, u8 percent_of_wlslot);
extern u8 wififw_btc_tdma_leakap_decide(void);
extern void wififw_btc_tdma_wlslot_random_len(void);
extern void wififw_btc_tdma_wl_slot(void);
extern void wififw_btc_tdma_wl2bt_slot(void);
extern void wififw_btc_tdma_bt_slot(void);
extern u16 wififw_btc_btqnull_nav_value_cal(void);
extern void wififw_btc_cck_priority_set(u8 priority);
extern void wififw_btc_tdma_bcn_early_hdl(void);
extern void wififw_btc_switch_into_next_slot(void);
extern void wififw_btc_tdma_bt_auto_slot(void);
extern void wififw_btc_tdma_nulldata1_finish_hdl(u8 null_result);
extern u8 wififw_btc_tdma_multi_slot_hdl(u8 mode);
extern void wififw_btc_tdma_multi_slot_timeout_hdl(void);
extern u8 wififw_btc_tdma_need_check_leakap(void);
extern void wififw_btc_bt_null_setting(u16 offset, u16 NAV);
extern void wififw_btc_tdma_pkt_fail(void);
extern void wififw_btc_bt_ctrl_tdma_start(void);
extern void wififw_btc_bt_ctrl_tdma_timeout_hdl(void);
extern u8 wififw_btc_bt_ctrl_tdma_protect_bcn_decision(void);
extern void wififw_btc_bt_ctrl_tdma_protect_bcn_action(u8 ProtectBCNEn);
extern void wififw_btc_bt_ctrl_tdma_protect_bcn_end(void);
extern void wififw_h2c_set_tdma(struct h2c_bt_tdma *pbuf);
extern void wififw_h2c_bt_wifi_ctrl(u8 *pbuf);
extern void wififw_h2c_bt_init(struct h2c_bt_init *pbuf);
extern void wififw_btc_init_coex_debug_port(void);
extern void wififw_btc_dbg_slot_trace(u32 GPIO_Pin, u32 Val);
extern void wififw_btc_dbg_gpio_toggle(u32 GPIO_Pin);
extern void wififw_btc_dbg_ps_state(u32 Val);
extern void wififw_gnt_bt_glitch_patch(void);
extern void wififw_gnt_bt_cca_reset_patch(void);

#endif /* #ifndef __ASSEMBLY__ */
#endif /*  __WIFIFW_BTCOEX_TDMA_H__ */
