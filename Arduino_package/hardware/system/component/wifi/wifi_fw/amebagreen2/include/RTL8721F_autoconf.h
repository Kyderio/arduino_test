#ifndef _AUTOCONF_H_
#define _AUTOCONF_H_

/* powersave*/
#define CONFIG_BCNEARLY_FIXED			1
#define CONFIG_BEACON_MODE				1
#define CONFIG_LPS_Normal				0
#define CONFIG_SWBB_PERIOD_CCA			1
#define CONFIG_HWMAC_PERIOD_CCA			0
#define CONFIG_S1_NULL1_IVL_PATCH   	1
#define CONFIG_LPS_Offload 				1
#define CONFIG_LPS_I_TWT 				0
#define CONFIG_PHYSTS_BUF		        1
#define CONFIG_CHINFO_BUF               1
#define CONFIG_BCNRXWINDOW_ADJUST   	1
#define CONFIG_LPS_TIME_LOG   	        0
#define CONFIG_RX_BCN_CNT					0
#define CONFIG_RECORD_TSF					0
#define CONFIG_LEAK_AP          		1
#define CONFIG_RF_OFF_BY_EDCCA			0
#if CONFIG_LPS_Offload
#define CONFIG_MULTI_RX_BCN             1
#else
#define CONFIG_MULTI_RX_BCN             0
#endif

/*WOWLAN*/
#define CONFIG_BroadDHCP_WAKE			0

/*WIFI TUNNEL*/
//#define CONFIG_WIFIFW_TUNNEL
#ifdef CONFIG_WIFIFW_TUNNEL //wifi tunnel can only run under normal lps for now
#undef CONFIG_LPS_Normal
#define CONFIG_LPS_Normal				1
#undef CONFIG_LPS_Offload
#define CONFIG_LPS_Offload 				0
#endif

/*PHY Dynamic*/
#define RA_V3
#define CONFIG_NEW_RATE_ADAPTIVE		1
#define CONFIG_DIG_OFFLOAD 				0

/*BTCOEX*/
#define BREDR_SUPPORT					0
#define LE_AUDIO_SUPPORT				0
#define CONFIG_BTCOEX_SLOT_DEBUG    	0    //CONFIG_BTCOEX

/*verification*/
#define CONFIG_FPGA_TEST 				1
#define CONFIG_DV_SIMULATION_TEST		0
#ifndef CONFIG_WIFI_FW_VERIFY
#define CONFIG_WIFI_FW_VERIFY 0
#endif

/*MISC*/
#define CONFIG_CSI_REPORT				1
#define CONFIG_PS_TIMER_KEEP_ALIVE		0

/*include rx filter setting, enable after dplus IC*/
#define CONFIG_ADDR_CAM_SUPPORT                 1
//#define CONFIG_TICKLESS_LONGRUN_TEST

/*patch macro block*/
/*for special AP behavior patch configs start*/
#define CONFIG_CONSTANT_ARPREQ_POWERSAVE_PATCH 0
/*for special AP behavior patch configs  end*/
#define CONFIG_TSFT_PATCH			    0

#endif  /* #ifndef _AUTOCONF_H_ */
