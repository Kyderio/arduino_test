#ifndef RTK_WPAN_TIMER_SCHED_H_
#define RTK_WPAN_TIMER_SCHED_H_

#include <stdbool.h>
#include <stdint.h>
#include "platform_autoconf.h"
#include "rtk_wpan_timer.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (* rtk_wpan_timer_callback_t)(void *p_context);

typedef struct rtk_wpan_timer_s {
	uint64_t                    t0;        ///< Base time of the timer, in microseconds.
	uint64_t                    dt;        ///< Timer expiration delta from @p t0, in microseconds.
	rtk_wpan_timer_callback_t   callback;  ///< Callback function called when timer expires.
	void                        *p_context; ///< User-defined context passed to the callback function.
	struct rtk_wpan_timer_s     *p_next;    ///< Pointer to the next running timer.
} rtk_wpan_timer_t;

int rtk_wpan_timer_sched_init(void);

int rtk_wpan_timer_sched_deinit(void);

bool rtk_wpan_timer_sched_time_is_in_future(uint64_t now, uint64_t t0, uint64_t dt);

int rtk_wpan_timer_sched_add(rtk_wpan_timer_t *p_timer, bool round_up);

int rtk_wpan_timer_sched_remove(rtk_wpan_timer_t *p_timer, bool *p_was_running);

bool rtk_wpan_timer_sched_is_running(rtk_wpan_timer_t *p_timer);

#ifdef __cplusplus
}
#endif

#endif /* RTK_WPAN_TIMER_SCHED_H_ */
