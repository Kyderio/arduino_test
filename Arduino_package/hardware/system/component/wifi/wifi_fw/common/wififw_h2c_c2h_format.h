#ifndef __WIFIFW_H2C_C2H_FORMAT_H__
#define __WIFIFW_H2C_C2H_FORMAT_H__

/* Field     SYNC       CMD_LEN     CONTENT    CMD_SEQ      CMD_ID */
/* BITS   [127:120]    [119:112]    [111:16]   [15:8]        [7:0] */
struct c2h_evt_content {
	u8	cmd_id;
	u8	cmd_seq;
	u8	content[9]; //change 12B to 32B for FTM C2H
	u8	cmd_len;
};

/* C2H Command ID List */
enum c2h_command_id {
	C2HID_NAN_EVENT			    = 0x18,

	/*coex use 0x6X,0x7X IDs*/
	C2HID_WL2BT_MAILBOX_FAIL	= 0x60,
	C2HID_RCV_BT2WL_SCB			= 0x61,
	C2HID_BT2WL_MAILBOX			= 0x62,

	/*0x8X IDs for other function*/
	C2HID_MAX					= 0xFF
};

/*--------------------Define Struct-------------------------------------*/
/* H2C Command ID List */
enum h2c_command_id {
	/* Class1: Common */
	H2CID_RSVDPAGE				= 0x00,
	H2CID_JOININFO				= 0x01,
	H2CID_KEEP_ALIVE			= 0x03,
	H2CID_PHYREG_ADDR			= 0x04,
	H2CID_AFEREG_ADDR			= 0x05,
	/* Class2: Power Save */
	H2CID_SETPWRMODE			= 0x20,
	H2CID_WTNPS_SET_FATHER_AID	= 0x25,
	H2CID_WTNPS_SET_REFUGEE_AID	= 0x26,
	H2CID_LPS_I_TWT_INFO1		= 0x31,
	H2CID_LPS_I_TWT_INFO2		= 0x32,
	H2CID_LPS_I_TWT_INFO3		= 0x33,
	/* Class3: Dynamic Mechaism */
	H2CID_MACID_CFG				= 0x40,
	H2CID_FW_DBG				= 0x41,
	H2CID_RSSI_SETTING			= 0x42,
	H2CID_CSI_Report			= 0x58,
	/* Class4: BT Coex */
	H2CID_WL_CTRL_TDMA			= 0x60,
	H2CID_WL2BT_MAILBOX			= 0x62,
	H2CID_WL2BT_MAILBOX_EXT		= 0x63,
	H2CID_BT_WIFICTRL			= 0x69,
	H2CID_BT_INIT				= 0x70,
	/* Class5: WOWLAN */
	H2CID_WoWLAN				= 0x80
};

/* H2C Index: 0x0 */
struct h2c_rsvdpage {
	union {
		u32 dw0;
		struct {
			u32	cmd_id				: 8;	//B0
			u32	loc_pspoll			: 8;	//B1
			u32	loc_nulldata			: 8;	//B2
			u32	loc_QosNull			: 8;	//B3
		};
	};

	union {
		u32 dw1;
		struct {
			u32	loc_BT_QoSNull		: 8;	//B4
			u32	Rsvd_W0				: 8;	//B5
			u32	loc_arp				: 8;	//B6
			u32	loc_CSI_Frame			: 8;	//B7
		};
	};
};

/* H2C Index: 0x1 */
struct h2c_join_info {
	u32	cmd_id				: 8;	//B0
	u32	Connected			: 1;	//B1
	u32	W0Rsvd0				: 7;
	u32	macid_start			: 8;	//B2
	u32	macid_end			: 8;	//B3
};

/* H2C Index: 0x3 */
struct h2c_keepalive {
	u32 cmd_id				: 8;	//B0
	u32 Enable				: 1;	//B1
	u32 W0Rsvd0				: 1;
	u32 PktType				: 1;
	u32 W0Rsvd1				: 5;
	u32 KeepAliveCountLimit	: 8;	//B2
	u32 KeepAliveCountUnit  : 2;    //(0:1s 1:100ms)
	u32 W0Rsvd2				: 6;
};

/* H2C Index: 0x4 */
struct h2c_phy_reg_addr {
	u32 cmd_id      : 8;
	u32 array_len	: 16;
	u32 rfe_type		: 8;
	u32 phy_array_addr	: 32;
};

/* H2C Index: 0x5 */
struct h2c_afe_reg_addr {
	u32 cmd_id      : 8;
	u32 array_len	: 16;
	u32 rsvd		: 8;
	u32 afe_array_addr	: 32;
};

/* H2C Index: 0x20 */
struct h2c_pwrsave {
	u32	cmd_id				: 8;	//B0
	u32	ps_mode				: 3;	//B1
	u32	bcnmode_en			: 1;
	u32 lpsofld_bmc_rx_dis	: 1;
	u32	W0Rsvd0				: 3;
	u32	lps_trx_mode		: 4;	//B2
	u32	rxbcn_interval_sel	: 4;	//RX Listen BCN Mode
	u32	rxbcn_interval		: 8;	//B3, Unit: AP actual beacon interval, only valid in PS Self-Defined mode

	u32	ReqPwrState			: 8;	//B4
	u32	bAllQueueUAPSD		: 1;	//B5
	u32	W1Rsvd0				: 7;
	u32	wtn_max_node_num	: 8;	//B6
	u32	W2Rsvd0				: 8;	//B7
};

/* H2C Index: 0x25 */
struct h2c_wtnps_father_aid_info {
	u32 cmd_id				: 8;
	u32 add_del				: 8;	//1: add father aid; 0: delete father aid
	u32 father_aid			: 8;
	u32 rsvd				: 8;
	u32 rsvd1;
};

/* H2C Index: 0x26 */
struct h2c_wtnps_refugee_aid_info {
	u32 cmd_id				: 8;
	u32 add_del				: 8;	//1: add refugee aid; 0: delete refugee aid
	u32 refugee_aid0		: 8;	//if refugee_aidx is not 0, the refugee_aidx is valid for add or delete option
	u32 refugee_aid1		: 8;
	u32 refugee_aid2		: 8;
	u32 refugee_aid3		: 8;
	u32 refugee_aid4		: 8;
	u32 refugee_aid5		: 8;
};

/* H2C Index: 0x31 */
struct h2c_itwtinfo1 {
	u32	cmd_id				: 8;	//B0
	u32	FLOW_ID				: 2;	//B1
	u32	TWT_En				: 1;
	u32	TRIGGER_En			: 1;
	u32	ANNOUNCED			: 1;
	u32	W0Rsvd0				: 3;
	u32	DURATION			: 16;	//B2

	u32	INTERVAL;					//B4
};

/* H2C Index: 0x32 */
struct h2c_itwtinfo2 {
	u32	cmd_id				: 8;	//B0
	u32	FLOW_ID				: 8;	//B1
	u32	W0Rsvd0				: 16;

	u32	TWTIME_H;					//B4
};

/* H2C Index: 0x33 */
struct h2c_itwtinfo3 {
	u32	cmd_id				: 8;	//B0
	u32	FLOW_ID				: 8;	//B1
	u32	W0Rsvd0				: 16;

	u32	TWTIME_L;					//B4
};

/* H2C Index: 0x40 */
struct h2c_ra_cfginfo {
	u32	cmd_id				: 8;	//B0
	u32	is_dis_ra			: 1;	//B1
	u32	bw					: 2;
	u32	macid				: 5;
	u32	bcn_rssi			: 8;	//B2
	u32	mode_ctrl			: 5;	//B3
	u32	is_5g				: 1;
	u32	en_sgi				: 1;
	u32	ldpc_cap			: 1;

	u32	ramask;					//B4
};

/* H2C Index: 0x41 */
struct h2c_fw_dbg {
	u32 cmdid			: 8;
	u32 ra_dbg_en		: 1;
	u32 bcn_time_log_en	: 1;
	u32 wake_time_log_en	: 1;
	u32 keepalive_log_en	: 1;
	u32 W0Rsvd0			: 20;
	u32 W1Rsvd0			: 32;
};

/* H2C Index: 0x42 */
struct h2c_ra_rssi_set {
	u32	cmd_id				: 8;	//B0
	u32	macid				: 8;	//B1
	u32	rssi				: 8; 	//B2, BIT7: parse rssi_b
	u32	bcn_rssi			: 8; 	//B3, BIT7: parse bcn_rssi

	u32	is_fixed_rate		: 1;	//B4
	u32	fixed_rate			: 7;
	u32	fixed_rate_md		: 2;	//B5
	u32	fixed_giltf			: 3;
	u32	fixed_bw			: 2;
	u32	W0Rsvd0				: 17;
};


/* H2C Index: 0x58 */
struct h2c_csi_report {
	u32	cmd_id				: 8;	//B0
	u32	enable				: 1;	//B1
	u32	csi_type			: 1;
	u32	band_width			: 1;
	u32	mac_id				: 4;
	u32	is_softap			: 1;
	u32	period				: 8;	//B2
	u32	W0Rsvd0				: 8;

	u32	rate				: 9;	//B4
	u32	W1Rsvd0				: 23;
};

/* H2C Index: 0x60 */
struct h2c_bt_tdma {
	u32	cmd_id				: 8;	//B0
	u32	WLCtrlTdmaEn		: 1;	//B1
	u32	BTCtrlTdmaEn		: 1;
	u32	NullDataEn			: 1;
	u32	BtQNullEn			: 1;
	u32	NoTxPause			: 1;
	u32	CCKPriorityToggle	: 1;
	u32	BtAutoSlot			: 1;
	u32	BtBouncingSlot		: 1;

	u32	WifiDynamicSlot		: 1;	//B2
	u32	DisTdmaLeakAPMode	: 1;
	u32	rsvd				: 6;

	u32	WLSlotPercent		: 8;	//B3

	u32	Reg778InWlSlot		: 4;	//B4
	u32	Reg778InBtSlot		: 4;

	u32	Reg778TdmaOff		: 4;	//B5
	u32	SecondBtSlotLen		: 4;
	//B6,B7
	u32	insert_skip_mode	: 1;	//0: insert mode; 1: skip mode;
	//u32 insert_interval	: 8;
	u32	insert_skip_times	: 4;	//if set 0, run 2 slot tdma inside origin bcn interval whether insert_skip_mode is insert or skip;
	u32	rsvd2				: 11;
};

/* H2C Index: 0x61 */
struct h2c_bt_info {
	u32	cmd_id				: 8;	//B0
	u32	Trigger				: 1;	//B1
	u32	W0Rsvd0				: 23;
};

/* H2C Index: 0x62 */
struct h2c_force_bt_txpower {
	u32	cmd_id				: 8;	//B0
	u32	PowerIndex			: 8;	//B1
	u32	W0Rsvd0				: 16;
};

/* H2C Index: 0x63 */
struct h2c_bt_ignore_wlact {
	u32	cmd_id				: 8;	//B0
	u32	Enable				: 1;	//B1
	u32	W0Rsvd0				: 23;
};

/* H2C Index: 0x69 */
enum h2c_btwifi_ctrl {
	BT_SET_TXRETRY_REPORT   = 0,
	BT_SET_PTATABLE         = 1,
	BT_SET_PSD_MODE         = 2,
	BT_SET_LNA_CONSTRAINT   = 3,
	BT_RA_RETRYPENALTY      = 6,
	BT_WIFI_RQT_INFO        = 8,
	BT_SET_A2DP_EMPTY_THD   = 10,
	BT_SET_BCN_INTERVAL     = 11,
	BT_SET_LEAK_AP_MODE     = 12,
	BT_PROTECT_BCN          = 14,
	BT_ONOFF_NOTIFY         = 15,
	BIT_RA_MASK_LOW_RATE	= 17,
	BT_MAX_ID               = 0xFF
};

/* H2C Index: 0x70 */
struct h2c_bt_init {
	u32	cmd_id				: 8;	//B0
	u32	PTASignalMode		: 2;	//B1
	u32	W0Rsvd0				: 22;
};

/* H2C Index: 0x80 */
struct h2c_wowlan {
	u32	cmd_id				: 8;	//B0
	u32	WoWlan_En			: 1;	//B1
	u32	ArpOffload_En		: 1;
	u32	IPV6En				: 1;
	u32	WakePktFilterEn		: 1;
	u32	TryPKTCountLimit	: 4;
	u32	DisconnectCntLimit	: 8;	//B2

	u32	PairwiseEncAlg		: 4;	//B3
	u32	GroupEncAlg			: 4;
	u32	W1Rsvd0				: 32;
};

#endif //__WIFIFW_H2C_C2H_FORMAT_H__
