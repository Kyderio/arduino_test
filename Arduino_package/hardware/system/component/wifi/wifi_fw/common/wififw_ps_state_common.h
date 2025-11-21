#ifndef __WIFIFW_PS_STATE_COMMON_H__
#define __WIFIFW_PS_STATE_COMMON_H__
/*--------------------Define --------------------------------------------*/
#define MACID_CLIENT        0
#define LEAKAGE_DELAY_TIME					2
#define RECEIVE_CNT_LIMIT   				3

#define S1_NULL1_FAIL_CNT_LMT	20
#define S1_NULL1_INTERVAL_AFTER_FAILLMT	500

#define MACPGResumeDone						(0x12345678)

#define RXDATAIN0								BIT0  //PSTX
#define RXDATAIN1								BIT1  //PSRX
#define RXDATAIN2								BIT2
#define RXMGTIN0								BIT3
#define RXCTRLIN0								BIT4

#define PS_STATE_MASK           (0x0F)
#define PS_IS_TX_NULL(x)        ((x) & PS_TX_NULL )
#define PS_IS_CLK_ON(x)         ((x) & (PS_RF_OFF |PS_ALL_ON ))
#define PS_IS_RF_OFF(x)         ((x)|PS_RF_OFF)
#define PS_IS_RF_ON(x)          ((x) & (PS_RF_ON))
#define PS_IS_ACTIVE(x)         ((x) & (PS_REGISTER_ACTIVE))

#define PS_STATUS_S0            (PS_REGISTER_ACTIVE | PS_RF_ON)                    //(1,1,0) all on = register active + rf on
#define PS_STATUS_S1            (PS_REGISTER_ACTIVE | PS_RF_ON | PS_TX_NULL)        //(1,1,1) all on + tx null(1)
#define PS_STATUS_S2            (PS_RF_ON)                                         //(0,1,0) register sleep + rf on
#define PS_STATUS_S3            (PS_RF_ON | PS_TX_NULL)                            //(0,1,1) register sleep + rf on + tx null(0)
#define PS_STATUS_S4            0                                                 //(0,0,0) all OFF
#define PS_STATUS_S5            (PS_TX_NULL )                                      //(0,0,1) SCAN = register sleep + rf on + scan enable

/* DATA FIN Condition Flags */
#define STA_DATA_OPEN           			BIT0  // indicate that FW open due to TIM = 1 condition. (PS-POLL as trigger frame)
#define BC_DATA_OPEN            			BIT1   // indicate that FW open due to DTIM = 1 condition.  (BC & MC)
#define QOS_DATA_OPEN           			BIT2 // indicate that FW open due to UAPSD trigger condition. (QNULL)
#define C2H_DATA_OPEN          				BIT3   // indicate that FW open due to C2H event 
#define BCN_DATA_OPEN           			BIT4

#define ALL_80211_DATA_OPEN     			(STA_DATA_OPEN | BC_DATA_OPEN | QOS_DATA_OPEN)
#define IS_80211_DATA_OPEN(x)			((x) & ALL_80211_DATA_OPEN)
#define IS_C2H_DATA_OPEN(x)     			((x) & C2H_DATA_OPEN)

#define SET_DATA_OPEN(x, type)  		((x) |= (type))
#define CLR_DATA_OPEN(x, type)  		((x) &= (~type))
#define IS_DATA_OPEN(x, type)   			((x) & (type))

#define NULL_DATA0_ALLOW        1
#define NULL_DATA0_DENY         0

#define PS_RF_OFF               0
#define PS_GO_ON                BIT0
#define PS_TX_NULL              BIT1
#define PS_RF_ON                BIT2
#define PS_REGISTER_ACTIVE      BIT3

//cpwm
#define PS_TOGGLE               BIT7

//rpwm
#define PS_32K_IN               BIT0
/*driver use bit1*/
#define IPS_PG					BIT2
#define PS_32K_PG               BIT4
#define KEYCAM_UPDATE			BIT5
#define PS_ACK                  BIT6

//pwr state
#define PS_TYPE_CURRENT_PS_STATE    1
#define PS_TYPE_LASTRPWM            2

#define REG_PGRSStateInd						((u32)(&WIFI_SHARE_INFO->PG_POWER_MARK) - WIFI_REG_BASE)		//1100

#define Multi_RxBcn_Dtim_Period_Thresmax	(5)
#define Multi_RxBcn_Dtim_Period_Thresmid	(3)

//default lps
#define DEFAULT_PS_BCN_EARLY			5
#define DEFAULT_PS_BCN_EARLY_128US		0
#define DEFAULT_PS_BCN_EARLY_32US		0
#define DEFAULT_BCN_TO_PERIOD			15


/*--------------------Define Enum---------------------------------------*/
enum RxListenBeaconMode {
	RLBM_MIN                = 0,
	RLBM_MAX,
	RLBM_SELF_DEFINED
};

enum _RT_MEDIA_STATUS {
	RT_MEDIA_DISCONNECT     = 0,
	RT_MEDIA_CONNECT        = 1
};

enum PS_MODE_SETTING_SELECTION {
	MODE_SETTING_ACTIVE     = 0,
	MODE_SETTING_LEGACY     = 1,
	MODE_SETTING_WMMPS      = 2,
	MODE_SETTING_WTNPS      = 3,
};

enum SMART_PS_MODE_FOR_LEGACY {
	SMART_PS_MODE_LEGACY_PWR1           = 0,        // TRX all use PS_POLL
	SMART_PS_MODE_TX_PWR0               = 1,        // TX: pwr bit = 0, RX: PS_POLL
	SMART_PS_MODE_TRX_PWR0              = 2,        // TX: pwr bit = 0, RX: NULL(0)
	SMART_PS_MODE_TX_PWR1				= 3 		// TX: pwr bit = 1, RX: NULL(0)
};

enum FW_S2_CONDITION_ERR {
	BIT_S2_TXQUEUE_NOT_EMPTY = 1,
	BIT_TRX_PERIOD,
	BIT_S2_RPWM_NOT_MATCH,
	BIT_WIFI_ACTIVE,
};

enum FW_S4_CONDITION_ERR {
	BIT_S4_TXQUEUE_NOT_EMPTY = 1,
	BIT_TRX_TIM_DTIM,
	BIT_S4_RPWM_NOT_MATCH,
	BIT_USP_NOT_OVER,
	BIT_TX_ACTIVE_INDEX,
	BIT_RX_ACTIVE_INDEX,
	BIT_BCN_DATA_OPEN,
	BIT_RfOffLicenseForBCNRx,
	BIT_WLANON_PERIOD,
	BIT_SCAN_EN,
	BIT_S4_TXCPUMGQ_NOT_EMPTY,
	BIT_LEPAP_NOT_END,
	BIT_TWTSP_NOT_END,
	BIT_PSTRX_RXCNT_NOT_EMPTY,
	BIT_BCNLEN_NOT_VALID,
	BIT_RSSI_NOT_VALID,
	BIT_WTN_RFON
};

enum FW_MAC_LPS_CONDITION_ERR {
	BIT_RXFF_NOT_EMPTY = 1,
	BIT_MAC_SCHDULE_SET,
	BIT_C2HPKT_REQ,
	BIT_RXDMA_NOT_IDLE,
	BIT_WOW_WAKEUP,
	BIT_CPUMQ_EMPTY,
	BIT_RCVING_TIMHIT_BCN,
	BIT_BB_FUNC_NOT_RST,
	BIT_IN_HWCtrlOff_Period,
	BIT_BCN_DCK_NOT_RDY,
	BIT_NEXT_TBTT_NOT_MATCH,
	BIT_CSIBUF_NOT_EMPTY,
};

/*--------------------Define Struct---------------------------------------*/
struct S1_Null1_Ctrl {
	u32 S1_null1_unlock_time;
	u16 S1_null1_interval;
	u8 S1_null1_fail_cnt;
	u8 S1_null1_fail_limit;
};

struct PS_PARM {
	u8		Enter32KHzPermission: 1;
	u8		ps_dtim_flag: 1;            // indicate dtim of current beacon.
	u8		pstrx_rxcnt_period: 1;
	u8		TxNull0: 1;
	u8 		TxNull0ok: 1;
	u8		TxNull1: 1;
	u8		TxNull1ok: 1;
	u8		RfOffLicenseForBCNRx: 1;    //filen: After we received ps_bcn_cnt beacons, we can sleep(rf off).

	u8		BCNAggEn: 1;
	u8		IsGoingTo32K: 1;
	u8		BcnTraceDone: 1;
	u8		bcn_time_log_en: 1;
	u8		wake_time_log_en: 1;
	u8		BcnNeedCatch: 1;
	u8		rcv_action: 1;
	u8		AckNull0: 1;

	u8		current_ps_state;
	u8		request_ps_state;
	u8 		ps_data_open;
	u8		ps_dtim_period: 4;
	u8		ps_dtim_cnt: 4;
	u8		bcn_to_cnt: 4;                 // indicate the total number of contnuous BCN_TO we have received.
	u8		bcn_to_times_cnt: 4;        //20140806
	u8		bcn_to_cnt_lpsofld: 7;		  //20240312
	u8		bcn_to_rxbcn_flag: 1;		 //20240312

	u8 		BCNNumForDRV;//driver
	u8		Bcnlength;
#if CONFIG_LEAK_AP
	bool waiting_leakage_check;
#endif
	u8		PS_multibcnrxEn: 1;
	u8		PS_multibcnrx_cnt: 4;
	u8		bAllQueueUAPSD: 1;
	u8      BcnModeValid: 1;
	u8      bcn_mode_change: 1;
	u32		LastTSFOnBCNTO;
	u32		CurntTSFOnBCNTO;

	u8		bcnearlyitvl1ms;
	u8 		bcnearlyitvl128us;
	u8		bcnearlyitvl32us;
	u16		bcntimeout;

	u8		period_cca_en: 1;
	u8		rsvd: 7;
};

/*------------------------------Function declaration--------------------------*/
extern const char *TAG_FW_BCNM;
extern const char *TAG_FW_PCCA;
extern const char *TAG_FW_LPS;
extern const char *TAG_FW_LPSOFLD;
extern const char *TAG_FW_WAKESTAT;

extern void wififw_ps_init(void);
extern bool wififw_ps_32k_condition_match(void);
extern void wififw_ps_get_rxbcn_window(u8 *bcnearlyitvlms, u8 *bcnearlyitvl128us, u8 *bcnearlyitvl32us, u16 *bcntimeout);
extern void wififw_ps_set_rxbcn_window_reg(u8 bcnearlyitvl1ms, u8 bcnearlyitvl128us, u8 bcnearlyitvl32us, u32 bcntimeout);
extern void wififw_ps_set_rxbcn_window_value(u8 bcnearlyitvlms, u8 bcnearlyitvl128us, u8 bcnearlyitvl32us, u32 bcntimeout);
extern void wififw_ps_set_rxbcn_interval(u8  RLBM, u8  AwakeInterval);
extern void wififw_ps_state_switch(u8  request_ps_state, u8  nulldata0Allow);
extern void wififw_ps_state_mac_lps(void);
extern bool wififw_ps_s2_condition_match(void);
extern u8 wififw_ps_s4_condition_match(void);
extern void wififw_ps_s2_to_s0(void);
extern void wififw_ps_s3_to_s2_or_s0(void);
extern void wififw_ps_s1_to_s0_or_s2(void);
extern void wififw_ps_s2_to_s5(void);
extern void wififw_ps_s5_to_s2(void);
extern void wififw_ps_s2_to_s4(void);
extern void wififw_ps_s4_to_s2(void);
extern void wififw_ps_s0_to_s6(void);
extern void wififw_ps_s6_to_s0(void);
extern void wififw_ps_s2_to_s3(u8 nulldata0Allow);
extern void wififw_ps_s0_to_s1(void);
extern void wififw_ps_start_wait_rx_period(void);
extern void wififw_ps_set_power_state(u8 PwrStateType, u8 value);
extern void wififw_ps_parameter_reset(void);
extern bool wififw_ps_check_txqueue_empty(void);
extern void wififw_ps_mode_lps(void);
extern void wififw_ps_mode_active(void);
extern void wififw_ps_extend_wait_rx_period(void);
extern bool wififw_ps_s1_condition_match(void);
extern void wififw_ps_start_tx_period(void);
extern u8 wififw_check_cpumgq_empty(void);
#ifdef CONFIG_WMMPS_STA
extern void wififw_wmmps_setting(void);
#endif
extern void wififw_ps_set_rxbcn_timeup_cnt_lmt(u8 rxbcn_timeup_counter);
extern void wififw_ps_set_tsft_diff_threshold(u16 tsft_diff);
extern void wififw_ps_mode_lps_int_set(u8 on);
#endif //__WIFIFW_TASK_H__
