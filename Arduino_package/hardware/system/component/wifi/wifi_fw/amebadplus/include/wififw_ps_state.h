#ifndef __WIFIFW_PS_STATE_H__
#define __WIFIFW_PS_STATE_H__

/*--------------------Define --------------------------------------------*/

#define LPS_KeepCurrentVal	(0xFF)
#define MAC_RS_TXREG_NUM	28
#define MAC_RS_TXPWRREG_NUM 	6
#define MAC_RS_PAGE3_NUM 	32
#define BB_RS_DPKREG_NUM	15

//Power Save Tuning Parameter
#define DEFAULT_BCN_TO_LIMIT			2
#define DEFAULT_BCN_TOLMT_HANDLE	2
#define DEFAULT_BCN_TOLMT_WAIT_BCN  3
#define DEFAULT_BCN_TOLMT_UPDATE_BCNRSSI  4
#define DEFAULT_BCN_TMOUT_RESET		2
#define DEFAULT_DTIM_TIMEOUT    15  // 7         // 7 ms
#define DEFAULT_PS_TIMEOUT      40  // 20       // 20 ms
#define DEFAULT_PS_DTIM_PERIOD  7
#define DEFAULT_RECEIVE_PACKET_TIMEOUT	10	//5ms

#define BB_AGC_5G_BAND_ML_MAX_SIZE 		((BCN_MODE_5GL_SIZE > BCN_MODE_5GM_SIZE) ?  BCN_MODE_5GL_SIZE : BCN_MODE_5GM_SIZE)
#define BB_AGC_5G_BAND_MAX_SIZE			((BB_AGC_5G_BAND_ML_MAX_SIZE > BCN_MODE_5GH_SIZE)? BB_AGC_5G_BAND_ML_MAX_SIZE: BCN_MODE_5GH_SIZE)
#define BB_AGC_5G_REG_SIZE				(BCN_MODE_5G_COM_SIZE + BB_AGC_5G_BAND_MAX_SIZE)
#define BB_AGC_MAX_REG_SIZE				((BB_AGC_5G_REG_SIZE > BCN_MODE_2G_SIZE) ? BB_AGC_5G_REG_SIZE : BCN_MODE_2G_SIZE)
#define BB_AGC_REG_SIZE					(BB_AGC_MAX_REG_SIZE / 3)
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
	u16 IGI1d70HIOECmdAddr;
	u16 ExitIGI1d70HIOECmdAddr;
	u16 TRXOnCmdFileHWStartAddr;
	u16 TRXOnCmdFileFWStartAddr;
	u16 TRXOnCmdFileEndAddr;
	u16 TRXOffCmdFileStartAddr;
	u16 TRXOffCmdFileEndAddr;
	u16 SysSleepCHNOffEndAddr;
	u16 PGRSCmdFileStartAddr;
	u16 PGRSCmdFileEndAddr;
	u16 BBBkRsCmdFileEndAddr;
	u16 CGHIOEChnOnStartAddr;
#if CONFIG_TSFT_PATCH
	u32 Freerun_Cnt_H1; //base
	u32 Freerun_Cnt_L1;//base
	u32 TSFT_H1;//base
	u32 TSFT_L1;//base
	u32 Freerun_Cnt_H2; //sample value when bcn timeout
	u32 Freerun_Cnt_L2; //ditto
	u32 TSFT_H2; //ditto
	u32 TSFT_L2; //ditto
	u32 Delta_Freerun_Cnt_H;
	u32 Delta_Freerun_Cnt_L;
	u32 Delta_TSF_H;
	u32 Delta_TSF_L;
	u8 tsf_dir;// 1: tsft2>=tsft1 0:tsft1<tsft2
	u8 Enlarge_Flag; //means tsft error detected
	u8 Bcn_Early_BK; //backup bcn early before adjusting
	u16 Bcn_To_BK; //backup bcn timeout before adjusting
	u32 TSF_Diff_Threshold;
#endif
	u16 TSF_Diff_Avg;
	u32 TSF_Diff_Statics_Pos;//rx_mac_tsf > TSFT
	u32 TSF_Diff_Statics_Neg;//rx_mac_tsf < TSFT
	u8 TSF_Diff_Dir;// 1:rx_mac_tsf > TSFT bcn ahead
	u8 TSF_Diff_Statics_Cnt;
};

struct RFDPK_Parm {
	u8 	dpkbackup_flag;
	u32	gainscaling;
	u32	pwsfoffset;
	u32	evenlut[16];
	u32	oddlut[16];
	u32	bbreg[BB_RS_DPKREG_NUM];
};

struct LPSPG_PARM {
	u8      LpsPG_En: 1;
	u8		IpsPG_En: 1;
	u8     	HioeRestoreDone: 1;
	u8 		BKBcnMode_status: 1;
	u8		WIFI_5GMode: 1;
	u8		RFBW40MMode: 1;
	u8		band_5G: 2;	//0:low bannd;1:middle band;2:high band
	u8		keycam_update: 1;
	u8		hioe_init_ok: 1;
	u8		rsvd1: 6;
	u32   	LPS_Option;
	u16 	HIOE_STR_ADDR;
	u16		HIOE_BACKUP_END_ADDR;
	u16 	HIOE_RESTORE_END_ADDR;
	u32 	ARFC18;
#if CONFIG_BEACON_MODE
	u16 	BB93D;
	u32 	BB93C;
	u16 	BCNModeCH;
	u16 	NormalCH;
#endif

	u32 	mactxreg[MAC_RS_TXREG_NUM];
	u32 	macid0ctrlinfo[SIZE_CTRLINFO_ENTRY / 4]; //UNIT :4 BYTES
	u32	page3reg[MAC_RS_PAGE3_NUM];
	u32 	mactxpower[MAC_RS_TXPWRREG_NUM];
	u32 	ccktxshaping[CCK_TX_SHAPING_REG_SIZE];
	u32 	bbagcreg[BB_AGC_REG_SIZE];
	struct RFDPK_Parm	RFDPKParm;
	u16		HIOECmd_Mem_WPtr;
	u32 	bbreg_1d70;
};
#endif  //__WIFIFW_PS_STATE_H__
