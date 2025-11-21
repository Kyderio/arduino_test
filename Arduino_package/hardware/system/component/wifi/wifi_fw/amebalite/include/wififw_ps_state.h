#ifndef __WIFIFW_PS_STATE_H__
#define __WIFIFW_PS_STATE_H__

/*--------------------Define --------------------------------------------*/
#define LPS_KeepCurrentVal	(0xFF)
#define MAC_RS_TXREG_NUM 	26
#define MAC_RS_TXPWRREG_NUM 	102

//Power Save Tuning Parameter
#define DEFAULT_BCN_TO_LIMIT    			2  // 1
#define DEFAULT_BCN_TOLMT_HANDLE	2
#define DEFAULT_BCN_TOLMT_UPDATE_BCNRSSI  4
#define DEFAULT_BCN_TOLMT_WAIT_BCN  	2
#define DEFAULT_BCN_TMOUT_RESET		2
#define DEFAULT_DTIM_TIMEOUT    			15  // 7         // 7 ms
#define DEFAULT_PS_TIMEOUT      			40  // 20       // 20 ms
#define DEFAULT_PS_DTIM_PERIOD  		7
#define DEFAULT_RECEIVE_PACKET_TIMEOUT	10	//5ms

/*--------------------Define Struct---------------------------------------*/
struct LPSOFFLOADParm {
	u8	MACRXBCNOfldEn: 1;/*the whole enable bit of MACRXBCN offload function, can be added into H2C parm controled by driver*/
	u8	HWCtrlTRXOnOff: 1;
	u8	ByPassLsysWakeEn: 1;
	u8	WaitFCSOptionEn: 1;
	u8	RcvingTimhitBcn: 1;
	u8	BKForPGResDone: 1;
	u8	rsvd: 2;
	u16 RxbcnModeCmdFileStartAddr;
	u16 ExitRxbcnModeCmdFileStartAddr;
	u16 PeriodCCACmdFileStartAddr;
	u16 TRXOnCmdFileHWStartAddr;
	u16 TRXOnCmdFileFWStartAddr;
	u16 TRXOnCmdFileEndAddr;
	u16 TRXOffCmdFileStartAddr;
	u16 TRXOffCmdFileEndAddr;
	u16 SysSleepCHNOffEndAddr;
	u16 BBBkRsCmdFileStartAddr;
	u16 BBBkRsCmdFileEndAddr;
	u16 PGRSCmdFileStartAddr;
	u16 PGRSCmdFileEndAddr;
	u16 CGHIOEChnOnStartAddr;
	u16 TSF_Diff_Avg;
	u32 TSF_Diff_Statics_Pos;//rx_mac_tsf > TSFT
	u32 TSF_Diff_Statics_Neg;//rx_mac_tsf < TSFT
	u8 TSF_Diff_Dir;// 1:rx_mac_tsf > TSFT bcn ahead
	u8 TSF_Diff_Statics_Cnt;
};

struct LPSPG_PARM {
	u8      LpsPG_En: 1;
	u8     	HioeRestoreDone: 1;
	u8 		BKBcnMode_status: 1;
	u8		WIFI_5GMode: 1;
	u8		keycam_update: 1;
	u8		hioe_init_ok: 1;
	u8 	    rsvd: 2;
	u32   	LPS_Option;
	u16 HIOE_STR_ADDR;
	u16 HIOE_BACKUP_END_ADDR;
	u16 HIOE_RESTORE_END_ADDR;
	u32	ARFC18;
	u32	DRFC18;
	u32 	DRFC0;
#if CONFIG_BEACON_MODE
	u32 	bbagcreg[BCN_MODE_2G_SIZE / 3];
	u32 	BCN_DCKG[8];
	u32 	BB4454;
	u16 	BCNModeCH;
#endif
#if CONFIG_SWBB_PERIOD_CCA
	u8 		period_cca_reg_backup_done;
	u8 		period_cca_bbreg_backup[7];
#endif
	u32 mactxreg[MAC_RS_TXREG_NUM];
	u32 	macid0ctrlinfo[SIZE_CTRLINFO_ENTRY / 4]; //UNIT :4 BYTES
	u32 mactxpower[MAC_RS_TXPWRREG_NUM];
	u32 ccktxshaping[CCK_TX_SHAPING_REG_SIZE];
	u32 tssi_bbpage56[64];
	u32 tssi_bbpage58[64];
	u16		HIOECmd_Mem_WPtr;
};
#endif  //__WIFIFW_PS_STATE_H__
