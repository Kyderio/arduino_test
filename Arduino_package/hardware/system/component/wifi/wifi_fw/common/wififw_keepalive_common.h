#ifndef __WIFIFW_KEEPALIVE_COMMON_H__
#define __WIFIFW_KEEPALIVE_COMMON_H__

extern void wififw_h2c_keepalive(struct h2c_keepalive *pbuf);
extern void wififw_keepalive_pkt_send(void);
extern void wififw_keepalive_init(void);
extern void wififw_inthdl_pstimera_keepalive(void);
extern void wififw_keepalive_time_update(u8 keepalive_interval);
extern void wififw_keepalive_period_restart(void);
extern void wififw_keepalive_arp_pkt_type_set(void);
extern void wififw_keepalive_set_tbtt_agg_period(u8 cnt);
extern void wififw_keepalive_fail_set_full_bcnrx(u8 set_full_rx);
#endif