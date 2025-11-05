/******************************************************************************
 *
 * Copyright(c) 2007 - 2012 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef _RTW_MP_H_
#define _RTW_MP_H_

#define bRFRegOffsetMask	0xfffff

#ifdef CONFIG_MP_INCLUDED
//	00 - Success
//	11 - Error
#define STATUS_SUCCESS				(0x00000000L)
#define STATUS_PENDING				(0x00000103L)

#define STATUS_UNSUCCESSFUL			(0xC0000001L)
#define STATUS_INSUFFICIENT_RESOURCES		(0xC000009AL)
#define STATUS_NOT_SUPPORTED			(0xC00000BBL)

#define NDIS_STATUS_CLOSING			((NDIS_STATUS)0xC0010002L)

enum _ANTENNA_PATH {
	ANTENNA_NONE	= 0x00,
	ANTENNA_D		,
	ANTENNA_C		,
	ANTENNA_CD		,
	ANTENNA_B		,
	ANTENNA_BD		,
	ANTENNA_BC		,
	ANTENNA_BCD 	,
	ANTENNA_A		,
	ANTENNA_AD		,
	ANTENNA_AC		,
	ANTENNA_ACD 	,
	ANTENNA_AB		,
	ANTENNA_ABD 	,
	ANTENNA_ABC 	,
	ANTENNA_ABCD
};


#define MAX_MP_XMITBUF_SZ 	2048


struct mp_wiparam {
	u32 bcompleted;
	u32 act_type;
	u32 io_offset;
	u32 io_value;
};

struct mp_tx {
	u8 stop;
	u32 count, sended;
	u8 payload;
	struct pkt_attrib attrib;
	struct tx_desc desc;
	u8 *pallocated_buf;
	u8 *buf;
	u32 buf_size, write_size;
	//_thread_hdl_	PktTxThread;
	struct task_struct	MpXmitThread;
};

#define MP_MAX_LINES		1000
#define MP_MAX_LINES_BYTES	256

struct pmac_pktinfo_t {
	u8			MCS;
	u8			Nss;
	u8			Nsts;
	u32			N_sym;
	u8			SIGA2B3;
	u8			PPDU_Type;
	u8			HE_ERSU_RU106;
};

struct pmac_txinfo_t {
	u8			bEnPMacTx: 1;		/* 0: Disable PMac 1: Enable PMac */
	u8			Mode: 3;				/* 0: Packet TX 3:Continuous TX */
	u8			Ntx: 4;				/* 0-7 */
	u16			TX_RATE;			/* MPT_RATE_E */
	u16			TX_RATE_HEX;
	u8			He_Dcm;
	u8			TX_SC;
	u8			bSGI: 1;
	u8			bSPreamble: 1;
	u8			bSTBC: 1;
	u8			bLDPC: 1;
	u8			NDP_sound: 1;
	u8			BandWidth: 3;		/* 0: 20 1:40 2:80Mhz */
	u8			m_STBC;			/* bSTBC + 1 */
	u16			PacketPeriod;
	u32			PacketCount;
	u32			PacketLength;
	u8			PacketPattern;
	u16			SFD;
	u8			SignalField;
	u8			ServiceField;
	u16			LENGTH;
	u8			CRC16[2];
	u8			LSIG[3];
	u8			HT_SIG[6];
	u8			VHT_SIG_A[6];
	u8			VHT_SIG_B[4];
	u8			VHT_SIG_B_CRC;
	u8			VHT_Delimiter[4];
	u8			MacAddress[6];
	u16			RU_Alloc;
};

struct mp_context_t {
	// Indicate if we have started Mass Production Test.
	bool			bMassProdTest;

	// Indicate if the driver is unloading or unloaded.
	bool			bMptDrvUnload;

	rtos_sema_t			MPh2c_Sema;
	struct timer_list	MPh2c_timeout_timer;
// Event used to sync H2c for BT control

	bool		MptH2cRspEvent;
	bool		MptBtC2hEvent;
	bool		bMPh2c_timeout;

	/* 8190 PCI does not support NDIS_WORK_ITEM. */
	// Work Item for Mass Production Test.
	//NDIS_WORK_ITEM	MptWorkItem;
//	RT_WORK_ITEM		MptWorkItem;
	// Event used to sync the case unloading driver and MptWorkItem is still in progress.
//	NDIS_EVENT		MptWorkItemEvent;
	// To protect the following variables.
//	NDIS_SPIN_LOCK		MptWorkItemSpinLock;
	// Indicate a MptWorkItem is scheduled and not yet finished.
	bool			bMptWorkItemInProgress;
	// An instance which implements function and context of MptWorkItem.
	void (*CurrMptAct)(void *padapter);

	// 1=Start, 0=Stop from UI.
	u32			MptTestStart;
	// _TEST_MODE, defined in MPT_Req2.h
	u32			MptTestItem;
	// Variable needed in each implementation of CurrMptAct.
	u32			MptActType; 	// Type of action performed in CurrMptAct.
	// The Offset of IO operation is depend of MptActType.
	u32			MptIoOffset;
	// The Value of IO operation is depend of MptActType.
	u32			MptIoValue;
	// The RfPath of IO operation is depend of MptActType.
	u32			MptRfPath;

	enum _WIRELESS_MODE		MptWirelessModeToSw;	// Wireless mode to switch.
	u8			MptChannelToSw; 	// Channel to switch.
	u8			MptInitGainToSet; 	// Initial gain to set.
	//u32			bMptAntennaA; 		// TRUE if we want to use antenna A.
	u32			MptBandWidth;		// bandwidth to switch.
	u32			MptRateIndex;		// rate index.
	// Register value kept for Single Carrier Tx test.
	u8			btMpCckTxPower;
	// Register value kept for Single Carrier Tx test.
	u8			btMpOfdmTxPower;
	// For MP Tx Power index
	u8			TxPwrLevel[2];	// rf-A, rf-B

	// Content of RCR Regsiter for Mass Production Test.
	u32			MptRCR;
	// TRUE if we only receive packets with specific pattern.
	bool			bMptFilterPattern;
	// Rx OK count, statistics used in Mass Production Test.
	u32			MptRxOkCnt;
	// Rx CRC32 error count, statistics used in Mass Production Test.
	u32			MptRxCrcErrCnt;

	bool			bCckContTx;	// TRUE if we are in CCK Continuous Tx test.
	bool			bOfdmContTx;	// TRUE if we are in OFDM Continuous Tx test.
	bool			bStartContTx; 	// TRUE if we have start Continuous Tx test.
	// TRUE if we are in Single Carrier Tx test.
	bool			bSingleCarrier;
	// TRUE if we are in Carrier Suppression Tx Test.
	bool			bCarrierSuppression;
	//TRUE if we are in Single Tone Tx test.
	bool			bSingleTone;

	// ACK counter asked by K.Y..
	bool			bMptEnableAckCounter;
	u32			MptAckCounter;

	// SD3 Willis For 8192S to save 1T/2T RF table for ACUT	Only fro ACUT delete later ~~~!
	//s8		BufOfLines[2][MAX_LINES_HWCONFIG_TXT][MAX_BYTES_LINE_HWCONFIG_TXT];
	//s8			BufOfLines[2][MP_MAX_LINES][MP_MAX_LINES_BYTES];
	//s32			RfReadLine[2];

	u8		APK_bound[2];	//for APK	path A/path B
	bool		bMptIndexEven;

	u8			h2cReqNum;
	u8			c2hBuf[20];

	u8          btInBuf[100];
	u32			mptOutLen;
	u8          mptOutBuf[100];
	struct pmac_txinfo_t		pmac_txinfo;
	struct pmac_pktinfo_t	pmac_pktinfo;
};
//#endif

//#define RTPRIV_IOCTL_MP 					( SIOCIWFIRSTPRIV + 0x17)
enum {
	WRITE_REG = 1,
	READ_REG,
	WRITE_RF,
	READ_RF,
	WRITE_SYS,
	READ_SYS,
	MP_START,
	MP_STOP,
	MP_RATE,
	MP_HE_DCM,
	MP_CHANNEL,
	MP_BANDWIDTH,
	MP_TXPOWER,
	MP_RXPATH,
	MP_ANT_TX,
	MP_ANT_RX,
	MP_CTX,
	MP_HW_TX,
	MP_QUERY,
	MP_ARX,
	MP_PSD,
	MP_PWRTRK,
	MP_THER,
	EFUSE_GET,
	EFUSE_SET,
	CONFIG_GET,
	CONFIG_SET,
	MP_RESET_STATS,
	MP_DUMP,
	MP_PHYPARA,
	MP_SetRFPathSwh,
	MP_GET_TXPOWER_INX,
	MP_BT,
	MP_PwrCtlDM,
	MP_IQK,
	MP_LCK,
	MP_DPK,
	MP_GET_TSSIDE,
	MP_SET_TSSIDE,
	MP_PHYDM,
	MP_TX_PLCP_USER,
	MP_TX_PLCP_DATA,
	MP_RFE,
	MP_ANTSW,
	MP_BTGSW,
	POWER_SUPPLY_MODE,
	MP_PWR_TABLE,
	FASTMP_CMD,
	MP_ANTDIV_GPIO,
	MP_XTAL_TRACK,
	BT_PA_PWR_MODE,
	MP_PWR_BY_RATE,
	MP_PWR_BY_LMT,
	MP_PG_NORMAL_TRX,
	MP_PG_BCN_RX,
	MP_PG_BCN_PCCA_RX,
};

struct mp_priv {
	struct wlan_network mp_network;
	struct __queue free_mp_xmitqueue;
	struct mp_wiparam workparam;
	struct mp_tx tx;
	struct mp_context_t mp_ctx;

	//Testing Flag
	u32 mode;//0 for normal type packet, 1 for loopback packet (16bytes TXCMD)
	u32 prev_fw_state;
	u32 tx_pktcount;
	u32 pktInterval;
	u32 rx_pktcount;
	u32 rx_crcerrpktcount;
	u32 rx_macpktcount;
	u32 preamble;
	u32 CrystalCap;
	u32 free_mp_xmitframe_cnt;
	u32 rssi_avg_cal;
	u32 rssi_avg;
	u32 rssi_count;

	u16 antenna_tx;
	u16 antenna_rx;

	u8 iface_type;
	u8 TID;
	u8 rx_pkt_by_mac;


	//RF/BB relative
	u8 channel;
	u8 do_dpk;
	u8 bandwidth;
	u8 prime_channel_offset;
	u8 txpoweridx;
	u8 txpoweridx_b;
	u8 rateidx; /*val: RTW_RATE_1M, RTW_RATE_2M...*/
	u8 he_dcm;
	u8 rfe_type;
	/* add for support pmac tx: start */
	u8 ppdu_type;  //0:cck;1:legacy;2:ht_mf;3:ht_gf;4:vht;5:he_su;6:he_er_su;7:he_mu_ofdma;8:he_tb
	u8 er_su_ru_106_en;  //he_er_su:0-242tone;1-106tone
	u16 ru_alloc;
	/* add for support pmac tx: end */
	u8 check_mp_pkt;
	u8 bSetTxPower;
	u8 bCCKTxPowerAdjust;
	u8 bFAStatistics;
	u8 mp_dm;
	u8 network_macaddr[6];

	u8 *pallocated_mp_xmitframe_buf;
	u8 *pmp_xmtframe_buf;

	u8 antdiv_gpio;
};

struct _IOCMD_STRUCT_ {
	u8	cmdclass;
	u16	value;
	u8	index;
};

struct fastmp_priv {
	/* golden map related */
	u8 *golden_map;
	u16 map_recv_flag;
	int max_golden_map_len;
	int mac_offset;
	int xtal_k_offset;
	u32 xtal_k_addr;
	int ofdm_diff_2G_offset;
	u32 ofdm_diff_2G_addr;
	int ofdm_diff_5G_offset;
	u32 ofdm_diff_5G_addr;
	int bw40_2G_offset;
	u32 bw40_2G_addr;
	int bw40_5G_offset;
	u32 bw40_5G_addr;

	/* fastmp test config */
	u8 max_fastmp_para_num;
	u8 fastmp_test_mode; //0:both, 1:only test 2.4G, 2:only test 5G
	u8 fastmp_2G_chl;
	u8 fastmp_5G_chl;
	u8 fastmp_tx_pktnum;
	u32 fastmp_tx_pktlen;
	u32 min_fastmp_txlen;
	u32 max_fastmp_txlen;
	u8 fastmp_tx_interval;
	u8 fastmp_tx_rateidx;/*val: RTW_RATE_1M, RTW_RATE_2M...*/

	/* fastmp test param */
	u8 src_mac_addr[6];
	u8 dst_mac_addr[6];
	u8 sync_code[8];
	rtos_sema_t stop_recv_sema;
	rtos_timer_t recv_timeout_timer;
	void (*fastmp_rx_callback)(union recv_frame *precvframe, u8 *pphy_info);

	/* fastmp test result */
	int fastmp_rx_num;
	int fastmp_rx_rssi;
	int fastmp_rx_evm;
	float fastmp_rx_cfo;
};


//=======================================================================

#define LOWER 	TRUE



enum _MP_MODE_ {
	MP_OFF,
	MP_ON,
	MP_ERR,
	MP_CONTINUOUS_TX,
	MP_SINGLE_CARRIER_TX,
	MP_SINGLE_TONE_TX,
	MP_PACKET_TX,
	MP_PACKET_RX
};

enum _TEST_MODE {
	TEST_NONE,
	PACKETS_TX,
	PACKETS_RX,
	CONTINUOUS_TX,
};


/* MP set force data rate base on the definition. */
enum _MPT_RATE_INDEX {
	/* CCK rate. */
	MPT_RATE_1M,	/* 0 */
	MPT_RATE_2M,
	MPT_RATE_55M,
	MPT_RATE_11M,	/* 3 */

	/* OFDM rate. */
	MPT_RATE_6M,	/* 4 */
	MPT_RATE_9M,
	MPT_RATE_12M,
	MPT_RATE_18M,
	MPT_RATE_24M,
	MPT_RATE_36M,
	MPT_RATE_48M,
	MPT_RATE_54M,	/* 11 */

	/* HT rate. */
	MPT_RATE_MCS0,	/* 12 */
	MPT_RATE_MCS1,
	MPT_RATE_MCS2,
	MPT_RATE_MCS3,
	MPT_RATE_MCS4,
	MPT_RATE_MCS5,
	MPT_RATE_MCS6,
	MPT_RATE_MCS7,	/* 19 */
	MPT_RATE_MCS8,
	MPT_RATE_MCS9,
	MPT_RATE_MCS10,
	MPT_RATE_MCS11,
	MPT_RATE_MCS12,
	MPT_RATE_MCS13,
	MPT_RATE_MCS14,
	MPT_RATE_MCS15,	/* 27 */
	MPT_RATE_MCS16,
	MPT_RATE_MCS17, // #29
	MPT_RATE_MCS18,
	MPT_RATE_MCS19,
	MPT_RATE_MCS20,
	MPT_RATE_MCS21,
	MPT_RATE_MCS22, // #34
	MPT_RATE_MCS23,
	MPT_RATE_MCS24,
	MPT_RATE_MCS25,
	MPT_RATE_MCS26,
	MPT_RATE_MCS27, // #39
	MPT_RATE_MCS28, // #40
	MPT_RATE_MCS29, // #41
	MPT_RATE_MCS30, // #42
	MPT_RATE_MCS31, // #43

	/* VHT rate. Total: 20*/
	MPT_RATE_VHT1SS_MCS0 = 100,//  #44
	MPT_RATE_VHT1SS_MCS1, // #
	MPT_RATE_VHT1SS_MCS2,
	MPT_RATE_VHT1SS_MCS3,
	MPT_RATE_VHT1SS_MCS4,
	MPT_RATE_VHT1SS_MCS5,
	MPT_RATE_VHT1SS_MCS6, // #
	MPT_RATE_VHT1SS_MCS7,
	MPT_RATE_VHT1SS_MCS8,
	MPT_RATE_VHT1SS_MCS9, //#53
	MPT_RATE_VHT2SS_MCS0, /* #54 */
	MPT_RATE_VHT2SS_MCS1,
	MPT_RATE_VHT2SS_MCS2,
	MPT_RATE_VHT2SS_MCS3,
	MPT_RATE_VHT2SS_MCS4,
	MPT_RATE_VHT2SS_MCS5,
	MPT_RATE_VHT2SS_MCS6,
	MPT_RATE_VHT2SS_MCS7,
	MPT_RATE_VHT2SS_MCS8,
	MPT_RATE_VHT2SS_MCS9, /* #63 */
	MPT_RATE_VHT3SS_MCS0,
	MPT_RATE_VHT3SS_MCS1,
	MPT_RATE_VHT3SS_MCS2,
	MPT_RATE_VHT3SS_MCS3,
	MPT_RATE_VHT3SS_MCS4,
	MPT_RATE_VHT3SS_MCS5,
	MPT_RATE_VHT3SS_MCS6, /*  #126 */
	MPT_RATE_VHT3SS_MCS7,
	MPT_RATE_VHT3SS_MCS8,
	MPT_RATE_VHT3SS_MCS9,
	MPT_RATE_VHT4SS_MCS0,
	MPT_RATE_VHT4SS_MCS1, /*  #131 */
	MPT_RATE_VHT4SS_MCS2,
	MPT_RATE_VHT4SS_MCS3,
	MPT_RATE_VHT4SS_MCS4,
	MPT_RATE_VHT4SS_MCS5,
	MPT_RATE_VHT4SS_MCS6, /*  #136 */
	MPT_RATE_VHT4SS_MCS7,
	MPT_RATE_VHT4SS_MCS8,
	MPT_RATE_VHT4SS_MCS9,
	MPT_RATE_HE1SS_MCS0,
	MPT_RATE_HE1SS_MCS1,
	MPT_RATE_HE1SS_MCS2,
	MPT_RATE_HE1SS_MCS3,
	MPT_RATE_HE1SS_MCS4,
	MPT_RATE_HE1SS_MCS5,
	MPT_RATE_HE1SS_MCS6,
	MPT_RATE_HE1SS_MCS7,
	MPT_RATE_HE1SS_MCS8,
	MPT_RATE_HE1SS_MCS9,
	MPT_RATE_HE1SS_MCS10,
	MPT_RATE_HE1SS_MCS11,/* 151 */
	MPT_RATE_LAST
};







enum _MPT_TXPWR_DEF {
	MPT_CCK,
	MPT_OFDM, // L and HT OFDM
	MPT_OFDM_AND_HT,
	MPT_HT,
	MPT_VHT
};

enum _OFDM_TX_MODE {
	OFDM_ALL_OFF		= 0,
	OFDM_ContinuousTx	= 1,
	OFDM_SingleCarrier	= 2,
	OFDM_SingleTone 	= 4,
};

enum _MP_PPDU_TYPE {
	RTW_MP_TYPE_CCK = 0,
	RTW_MP_TYPE_LEGACY,
	RTW_MP_TYPE_HT_MF,
	RTW_MP_TYPE_HT_GF,
	RTW_MP_TYPE_VHT,
	RTW_MP_TYPE_HE_SU,
	RTW_MP_TYPE_HE_ER_SU,
	RTW_MP_TYPE_HE_MU_OFDMA,
	RTW_MP_TYPE_HE_TB
};

enum _MP_ANTDIV_GPIO {
	ANTDIV_GPIO_PB2PB3 = 0,
	ANTDIV_GPIO_PA19PA20,
	ANTDIV_GPIO_PA26PA27,
	ANTDIV_GPIO_PB14PB15,
	ANTDIV_GPIO_PB18PB19,
};

#define PPDU_TYPE_STR(idx)\
	(idx == RTW_MP_TYPE_CCK) ? "CCK" :\
	(idx == RTW_MP_TYPE_LEGACY) ? "LEGACY" :\
	(idx == RTW_MP_TYPE_HT_MF) ? "HT_MF" :\
	(idx == RTW_MP_TYPE_HT_GF) ? "HT_GF" :\
	(idx == RTW_MP_TYPE_VHT) ? "VHT" :\
	(idx == RTW_MP_TYPE_HE_SU) ? "HE_SU" :\
	(idx == RTW_MP_TYPE_HE_ER_SU) ? "HE_ER_SU" :\
	(idx == RTW_MP_TYPE_HE_MU_OFDMA) ? "HE_MU" :\
	(idx == RTW_MP_TYPE_HE_TB) ? "HE_TB" :\
	"UNknow"

#define MPT_IS_CCK_RATE(_value)		(_value <= MPT_RATE_11M)
#define MPT_IS_OFDM_RATE(_value)	(MPT_RATE_6M <= _value && _value <= MPT_RATE_54M)
#define MPT_IS_HT_RATE(_value)		(MPT_RATE_MCS0 <= _value && _value <= MPT_RATE_MCS31)

#define MPT_IS_VHT_RATE(_value)		(MPT_RATE_VHT1SS_MCS0 <= _value && _value <= MPT_RATE_VHT4SS_MCS9)
#define MPT_IS_VHT_1S_RATE(_value)	(MPT_RATE_VHT1SS_MCS0 <= _value && _value <= MPT_RATE_VHT1SS_MCS9)
#define MPT_IS_VHT_2S_RATE(_value)	(MPT_RATE_VHT2SS_MCS0 <= _value && _value <= MPT_RATE_VHT2SS_MCS9)
#define MPT_IS_VHT_3S_RATE(_value)	(MPT_RATE_VHT3SS_MCS0 <= _value && _value <= MPT_RATE_VHT3SS_MCS9)
#define MPT_IS_VHT_4S_RATE(_value)	(MPT_RATE_VHT4SS_MCS0 <= _value && _value <= MPT_RATE_VHT4SS_MCS9)

#define MPT_IS_HE_1S_RATE(_value)	(MPT_RATE_HE1SS_MCS0 <= _value && _value <= MPT_RATE_HE1SS_MCS11)

#define MPT_IS_2SS_RATE(_rate) ((MPT_RATE_MCS8 <= _rate && _rate <= MPT_RATE_MCS15) || \
	(MPT_RATE_VHT2SS_MCS0 <= _rate && _rate <= MPT_RATE_VHT2SS_MCS9))
#define MPT_IS_3SS_RATE(_rate) ((MPT_RATE_MCS16 <= _rate && _rate <= MPT_RATE_MCS23) || \
	(MPT_RATE_VHT3SS_MCS0 <= _rate && _rate <= MPT_RATE_VHT3SS_MCS9))
#define MPT_IS_4SS_RATE(_rate) ((MPT_RATE_MCS24 <= _rate && _rate <= MPT_RATE_MCS31) || \
	(MPT_RATE_VHT4SS_MCS0 <= _rate && _rate <= MPT_RATE_VHT4SS_MCS9))

extern u8 wifi_mp_pg_trx_enable;
extern u8 wifi_mp_pg_trx_mode;
extern u8 wifi_enable;
extern u8 wifi_disable;
extern rtos_sema_t	fw_ipc_cmd_sema;

extern void wifi_hal_mp_resetbb(void);
extern void wifi_hal_mp_settxedca(void);
extern void wifi_hal_mp_rx_cca(bool cca_en);
extern int wifi_hal_mp_arx(struct rtw_point *wrqu);
extern void wifi_hal_txdesc_mp_fill(struct mp_priv *pmp_priv);
extern void wifi_hal_mp_dump(u32 column);
extern void wifi_hal_mp_rx_filter(void);
extern void wifi_hal_mp_dpk(struct rtw_point *wrqu);
extern void wifi_hal_mp_select_rf_ant(u8 ant_sw);
extern void wifi_hal_mp_config_power_supply_mode(u8 pwr_supply_mode, u8 *input, u32 input_len);
extern void wifi_hal_mp_set_bt_ant(u8 bt_ant);
extern u32 wifi_hal_mp_set_period(u32 period);
extern void wifi_hal_mp_query_phy(u8 *input, u32 input_len);
extern int wifi_hal_fastmp_cmd_handle(struct rtw_point *wrqu);

extern void	rtw_mp_set_bandwidth(void);

extern void rtw_mp_set_rf_path_switch(bool bMain);

extern void	rtw_mp_fill_txdesc_for_mp(struct tx_desc *ptxdesc);
extern void	rtw_mp_set_packet_tx(u8 iface_type);
extern void	rtw_mp_set_packet_rx(u8 bStartRx);

extern void wifi_hal_mp_set_rf_path_switch(bool is_main);

extern void wifi_hal_mp_init_psd(struct rtw_point *wrqu);
extern void wifi_hal_mp_get_point_data_psd(struct rtw_point *wrqu);
extern void wifi_hal_mp_restore_psd(struct rtw_point *wrqu);
extern u32 wifi_hal_mp_query_psd(u8 *data, int data_len);
extern void wifi_hal_mp_crystal_cap(u32 CrystalCapVal);


extern void wifi_hal_mp_set_bandwidth(void);
extern void wifi_hal_mp_set_carriersuppression_tx(u8 bStart);
extern void wifi_hal_mp_set_singletone_tx(u8 bStart);
extern void wifi_hal_mp_set_singlecarrier_tx(u8 bStart);
extern void wifi_hal_mp_set_continuous_tx(u8 bStart);

/* for mp common merge temp */
void wifi_hal_mp_pmac_get_pkt_param(struct pmac_txinfo_t *ppmac_txinfo, struct pmac_pktinfo_t *ppmac_pktinfo);
extern void halbb_reset_bb_hw_cnt(void);
extern void halbb_set_crystal_cap(u8 crystal_cap);
extern void _halrf_dpk_info(u32 *_used, char *output, u32 *_out_len);
extern void halbb_cck_tx_cnt_statistics(void);
extern void halbb_ofdm_tx_cnt_statistics(enum phl_phy_idx phy_idx);
extern void halrf_set_power_track(enum phl_phy_idx phy_idx, u8 value);
extern u8 halrf_get_power_track(void);
extern u8 halrf_get_thermal(void);
extern void halrf_lo_test(bool is_on);
extern void Hal_SetHwPacketTx(u8 bStart, u32 period, u32 len, u32 count);

extern void Hal_SetDataRate(void);
extern void Hal_SetChannel(void);
extern void Hal_SetAntennaPathPower(void);
extern s32 Hal_SetThermalMeter(u8 target_ther);
extern int Hal_SetPowerTracking(u8 enable);
extern void Hal_GetPowerTracking(u8 *enable);
extern void Hal_GetThermalMeter(u8 *value);
extern u8 rtw_mp_mgnt_rate_to_mp_rate(u8 rate);
extern void rtw_dynamic_timer_mp(void *FunctionContext);
extern void wifi_hal_mp_enable_firmware(u8 mp_pg_trx_test_mode);
#endif // #ifdef CONFIG_MP_INCLUDED

#endif //_RTW_MP_H_

