#ifndef __WIFIFW_LPS_DBG__
#define __WIFIFW_LPS_DBG__

#define WAKESTAT_LOG_INTERVAL 300000000

enum WAKE_TYPE {
	TYPE_TIM = 1,
	TYPE_DTIM,
	TYPE_BCNTO,
	TYPE_MAX
};

#define TYPE_NUM (TYPE_MAX-1)
struct lps_time_stat_log {
	u32		wakeuptsf;
	u32		logouttsf;
	u32		waketimesum[TYPE_NUM]; //unit:128us
	u16		wakecnt[TYPE_NUM];
	u8		wakerecordflag: 1;
	u8		rsvd: 3;
	u8		wake_type:	4;
};

extern void wififw_ps_dbg_bcn_time(bool on);
extern void wififw_ps_dbg_bcn_time_statistic(void);
extern void wififw_ps_dbg_wake_time_logout(void);
extern void wififw_ps_dbg_wake_time_record(void);
extern void wififw_ps_dbg_wake_type_log(u8 type);
#endif
