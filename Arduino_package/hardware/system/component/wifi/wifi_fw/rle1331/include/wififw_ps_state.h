#ifndef __WIFIFW_PS_STATE_H__
#define __WIFIFW_PS_STATE_H__
/*--------------------Define --------------------------------------------*/
//1331 todo
#if CONFIG_AMEBAL2
#define MAC_RS_TXREG_NUM	27
#define MAC_RS_TXPWRREG_NUM 	143
#define MAC_RS_PAGE3_NUM 	32
#define BB_RS_DPKREG_NUM	15
#endif

#define PS_BCNELY_32US_MAX      		0x20

#define DEFAULT_BCN_TO_LIMIT			2
#define DEFAULT_BCN_TOLMT_HANDLE		2
#define DEFAULT_BCN_TOLMT_WAIT_BCN  	3
#define DEFAULT_BCN_TOLMT_UPDATE_BCNRSSI  4
#define DEFAULT_BCN_TMOUT_RESET			2

#define DEFAULT_DTIM_TIMEOUT    		15//ms
#define DEFAULT_TRX_TIMEOUT      		40// ms
#define DEFAULT_RECEIVE_PACKET_TIMEOUT	10	//5ms
#define DEFAULT_PS_TIMEOUT      		40  // 20       // 20 ms

#define LPS_KeepCurrentVal					(0xFF)

/*--------------------Define Struct---------------------------------------*/
struct MACPDCCAParm {
	u16 HIOEPeriodCCARxModeStartAddr;
	u16 HIOEPeriodCCARxModeEndAddr;
	u16 HIOEPeriodCCASTDBYModeStartAddr;
	u16 HIOEPeriodCCASTDBYModeEndAddr;
};

struct LPSOFFLOADParm {
	u8	MACRXBCNOfldEn: 1; /*the whole enable bit of MACRXBCN offload function, can be added into H2C parm controled by driver*/
	u8	HWCtrlTRXOnOff: 1;
	u8	ByPassLsysWakeEn: 1;
	u8	WaitFCSOptionEn: 1;
	u8	RcvingTimhitBcn: 1;
	u8	BKForPGResDone: 1;
	u8	rsvd: 2;
	u16 RxbcnModeCmdFileStartAddr;
	u16 ExitRxbcnModeCmdFileStartAddr;
	u16 PeriodCCACmdFileStartAddr;
	u16 ExitPeriodCCACmdFileStartAddr;
	u16 TRXOnCmdFileHWStartAddr;
	u16 TRXOnCmdFileFWStartAddr;
	u16 TRXOnCmdFileEndAddr;
	u16 TRXOffCmdFileStartAddr;
	u16 TRXOffCmdFileEndAddr;
	u16 SysSleepCHNOffEndAddr;
	u16 PGRSCmdFileStartAddr;
	u16 PGRSCmdFileEndAddr;
	u16 CGHIOEChnOnStartAddr;
	u16 BBBkRsCmdFileEndAddr;
	u32 TSF_Diff_Avg;
	u32 TSF_Diff_Statics_Pos;//rx_mac_tsf > TSFT
	u32 TSF_Diff_Statics_Neg;//rx_mac_tsf < TSFT
	u8 TSF_Diff_Dir;// 1:rx_mac_tsf > TSFT bcn ahead
	u8 TSF_Diff_Statics_Cnt;
};

struct RFDPK_Parm {
	u8 	dpkbackup_flag;
};

struct LPSPG_PARM {
	u8      LpsPG_En: 1;
	u8		IpsPG_En: 1;
	u8     	HioeRestoreDone: 1;
	u8 		BKBcnMode_status: 1;
	u8		WIFI_5GMode: 1;
	u8		RFBW40MMode: 1;
	u8		keycam_update: 1;
	u8		hioe_init_ok: 1;
	u32   	LPS_Option;
	u16 	HIOE_STR_ADDR;
	u16		HIOE_BACKUP_END_ADDR;
	u16 	HIOE_RESTORE_END_ADDR;
	u32 	RFC18;
	u16 	NormalCH;
#if CONFIG_BEACON_MODE
	u16 	BCNModeCH;
#endif
	struct RFDPK_Parm	RFDPKParm;
	u16		HIOECmd_Mem_WPtr;
	u32 	macid0ctrlinfo[SIZE_CTRLINFO_ENTRY / 4]; //UNIT :4 BYTES
	u32 mactxreg[MAC_RS_TXREG_NUM];
	u32 mactxpower[MAC_RS_TXPWRREG_NUM];
};
#endif  //__WIFIFW_PS_STATE_H__
