#ifndef __WIFIFW_TWT_TIMER_H__
#define __WIFIFW_TWT_TIMER_H__

enum twt_class {
	TWTCLIENTA               = 0x0,
	TWTCLIENTB               = 0x1,
	TWTCLIENTC               = 0x2,
	TWTCLIENTD               = 0x3,
	TWTCLIENTE               = 0x4,
};

extern void wififw_twt_timer_enable(u8 idx, u8 port);
extern void wififw_twt_timer_disable(u8 idx);
extern void wififw_twt_timer_set_early_time(u8 idx, u32 early_time_us);
extern void wififw_twt_timer_set_target_wake_time(u8 idx, u64 twt_us);

#endif
