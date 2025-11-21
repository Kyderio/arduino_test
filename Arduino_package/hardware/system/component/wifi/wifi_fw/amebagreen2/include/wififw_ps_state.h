#ifndef __WIFIFW_PS_STATE_H__
#define __WIFIFW_PS_STATE_H__

/*--------------------Define --------------------------------------------*/
#define LPS_KeepCurrentVal                             (0xFF)

#define MAC_RS_TXREG_NUM 	26
#define MAC_RS_TXPWRREG_NUM 	102
#define BB_RS_DPKREG_NUM		6
#define BB_RS_DPKLUT_NUM		32

//Power Save Tuning Parameter
#define DEFAULT_BCN_TO_LIMIT    			2  // 1
#define DEFAULT_BCN_TOLMT_HANDLE	2
#define DEFAULT_BCN_TOLMT_UPDATE_BCNRSSI  4
#define DEFAULT_BCN_TOLMT_WAIT_BCN  		2
#define DEFAULT_BCN_TMOUT_RESET		2
#define DEFAULT_DTIM_TIMEOUT    			15  // 7         // 7 ms
#define DEFAULT_PS_TIMEOUT      			40  // 20       // 20 ms
#define DEFAULT_PS_DTIM_PERIOD  		7
#define DEFAULT_RECEIVE_PACKET_TIMEOUT	10	//5ms

#define BB_AGC_5G_BAND_ML_MAX_SIZE 		((BCN_MODE_5GL_SIZE > BCN_MODE_5GM_SIZE) ?  BCN_MODE_5GL_SIZE : BCN_MODE_5GM_SIZE)
#define BB_AGC_5G_BAND_MAX_SIZE			((BB_AGC_5G_BAND_ML_MAX_SIZE > BCN_MODE_5GH_SIZE)? BB_AGC_5G_BAND_ML_MAX_SIZE: BCN_MODE_5GH_SIZE)
#define BB_AGC_5G_REG_SIZE				(BCN_MODE_5G_COM_SIZE + BB_AGC_5G_BAND_MAX_SIZE)
#define BB_AGC_MAX_REG_SIZE				((BB_AGC_5G_REG_SIZE > BCN_MODE_2G_SIZE) ? BB_AGC_5G_REG_SIZE : BCN_MODE_2G_SIZE)
#define BB_AGC_REG_SIZE					(BB_AGC_MAX_REG_SIZE / 3)
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
	u16 ExitPeriodCCACmdFileStartAddr;
	u16 TRXOnCmdFileHWStartAddr;
	u16 TRXOnCmdFileFWStartAddr;
	u16 TRXOnCmdFileEndAddr;
	u16 TRXOffCmdFileStartAddr;
	u16 TRXOffCmdFileEndAddr;
	u16 SysSleepCHNOffEndAddr;
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

struct RFDPK_Parm {
	u32	gainscaling;
	u32	pwsfmode;
	u32	pwsfoffset;
	u32	dpk_lut0[BB_RS_DPKLUT_NUM];
	u32	dpk_lut1[BB_RS_DPKLUT_NUM];
	u32	bbreg[BB_RS_DPKREG_NUM];
	u8 	dpkbackup_flag;
};

struct LPSPG_PARM {
	u8      LpsPG_En: 1;
	u8     	HioeRestoreDone: 1;
	u8 		BKBcnMode_status: 1;
	u8		WIFI_5GMode: 1;
	u8		RFBW40MMode: 1;
	u8		band_5G: 2;	//0:low bannd;1:middle band;2:high band
	u8		keycam_update: 1;
	u8		hioe_init_ok: 1;
	u8		rsvd: 7;
	u32   	LPS_Option;
	u16		HIOE_STR_ADDR;
	u16 	HIOE_BACKUP_END_ADDR;
	u16 	HIOE_RESTORE_END_ADDR;
	u32		ARFC18;
	u32		DRFC18;
	u32 	DRFC0;
#if CONFIG_BEACON_MODE
	u32 	BB4454;
	u16 	BCNModeCH;
#endif
	u16 	NormalCH;
#if CONFIG_SWBB_PERIOD_CCA
	u32 	bbreg472c; //[26:24]:lna_idx_init
	u32 	bbreg473c; //[9]:tia_idx_init [7]:r_pure_post_pd
	u32 	bbreg46a8; //[14:10]:rxbb_idx_init
#endif
	u32 	mactxreg[MAC_RS_TXREG_NUM];
	u32 	macid0ctrlinfo[SIZE_CTRLINFO_ENTRY / 4]; //UNIT :4 BYTES
	u32 	mactxpower[MAC_RS_TXPWRREG_NUM];
	u32 	ccktxshaping[CCK_TX_SHAPING_REG_SIZE];
	u32 	tssi_bbpage56[64];
	u32 	tssi_bbpage58[64];
	u32 	tssi_bbpage14[32];
	u16		HIOECmd_Mem_WPtr;
	u32 	bbagcreg[BB_AGC_REG_SIZE];
	struct RFDPK_Parm RFDPKParm;
};
#endif  //__WIFIFW_PS_STATE_H__
