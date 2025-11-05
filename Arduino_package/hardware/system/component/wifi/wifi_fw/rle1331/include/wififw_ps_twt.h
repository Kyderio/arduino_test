#ifndef __WIFIFW_PS_TWT_H__
#define __WIFIFW_PS_TWT_H__

/*--------------------Define MACRO--------------------------------------*/
#define BIT_RXPSF_DATA2EN                          ((u32)0x00000001 << 18)          /*!<R/W 0  This bit is set to 1 to enable MAC to consider trigging invalid_pkt as rx packet Type=10 and subtype=0010. */

/*------------------------------Function declaration--------------------------*/
extern void wififw_twt_sp_target_time_update(u8 clientnum);
extern void wififw_twt_sp_endtime_update(u8 clientnum);
extern void wififw_twt_timer_reg_set(u8 clientnum);
extern void wififw_twt_timer_mode_set(u8 clientnum);
extern void wififw_twt_int_set(bool ByPassLsysWakeEn);
extern void wififw_twt_client_sp_set(u8 clientnum, u32 TWTH, u32 TWTL);
extern void wififw_twt_client_sp_early_set(u8 clientnum, u8 TWTEarly);
extern void wififw_twt_trigger_enable_set(bool enable);

#endif  /* __WIFIFW_PS_TWT_H__ */
