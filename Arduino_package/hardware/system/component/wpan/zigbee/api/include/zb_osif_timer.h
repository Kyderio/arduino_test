#ifndef ZB_OSIF_TIMER_H
#define ZB_OSIF_TIMER_H

void zb_osif_sched_sleep(zb_uint32_t sleep_tmo);
zb_uint32_t zb_osif_get_time_slept(void);
zb_time_t osif_transceiver_time_get(void);

#endif /*ZB_OSIF_TIMER_H*/
