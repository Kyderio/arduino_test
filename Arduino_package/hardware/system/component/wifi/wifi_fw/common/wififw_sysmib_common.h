#ifndef __WIFIFW_SYSMIB_H__
#define __WIFIFW_SYSMIB_H__

struct mib_info {
	struct H2C_EVT				H2CEvt;
	struct C2H_EVT				C2HEvt;
	struct MEDIA_STATUS			MediaStatus;

#if CONFIG_NEW_RATE_ADAPTIVE
	struct RA_PARM				RaParm;
#endif

	struct h2c_rsvdpage			H2cRsvdPage;
	struct h2c_pwrsave			H2cPwrSave;
	struct PS_PARM				PSParm;
	struct LPSOFFLOADParm		LPSOffloadParm;
	struct LPSPG_PARM	   		LPSPGParm;
#if CONFIG_LPS_I_TWT
	struct LPS_ITWT_PARM		LPSITWTParm;
#endif

#if CONFIG_HWMAC_PERIOD_CCA
	struct MACPDCCAParm			MACPDCCAParm;
#endif
#if CONFIG_BCNRXWINDOW_ADJUST
	struct BcnWindow_Adjust_Stat   	BcnWindowAdjustStat;
#endif
#if CONFIG_LPS_TIME_LOG
	struct lps_time_stat_log lpstime_log;
#endif
#ifdef CONFIG_WIFIFW_TUNNEL
	struct WTN_PS_PARM			WTNPsParm;
#endif

	struct h2c_bt_tdma			H2cBtTdma; 			//H2C Index: 0x60
	struct BTC_PsTdma_Parm		BtcPsTdma;

	struct h2c_wowlan			H2cWoWlan;
	struct WoWlan_Parm			WoWlanParm;
	struct AOAC_INFO			AOACInfo;

	struct h2c_keepalive		H2cKeepAlive;
	struct h2c_phy_reg_addr		H2cPhyRegAddr;
	struct h2c_afe_reg_addr		H2cAfeRegAddr;
	struct Keep_Alive_Parm		KeepAliveParm;
	struct PS_RSSIPARM			PSRSSIParm;
#if CONFIG_CSI_REPORT
	struct CSI_Report_Parm		CSIReportParm;
#endif

#if CONFIG_S1_NULL1_IVL_PATCH
	struct S1_Null1_Ctrl		s1_null1_ctrl;
#endif
	volatile u8					TaskBitMap;
} ;

extern struct mib_info SysMib;

#endif  //__WIFIFW_SYSMIB_H__

