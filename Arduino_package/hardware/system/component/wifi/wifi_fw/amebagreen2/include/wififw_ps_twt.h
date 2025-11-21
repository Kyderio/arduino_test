#ifndef __WIFIFW_PS_TWT_H__
#define __WIFIFW_PS_TWT_H__

/*--------------------Define MACRO--------------------------------------*/

/*------------------------------Function declaration--------------------------*/
extern void wififw_twt_sp_endtime_update(u8 clientnum);
extern void wififw_twt_timer_reg_set(u8 clientnum);
extern void wififw_twt_timer_mode_set(u8 clientnum);
extern void wififw_twt_int_set(bool ByPassLsysWakeEn);
extern void wififw_twt_client_sp_set(u8 clientnum, u32 TWTH, u32 TWTL);
extern void wififw_twt_client_sp_early_set(u8 clientnum, u8 TWTEarly);
extern void wififw_twt_trigger_enable_set(bool enable);

#endif  /* __WIFIFW_PS_TWT_H__ */
