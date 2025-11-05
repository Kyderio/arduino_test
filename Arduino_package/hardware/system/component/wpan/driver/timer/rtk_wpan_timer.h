#ifndef RTK_WPAN_TIMER_H_
#define RTK_WPAN_TIMER_H_

#include <stdbool.h>
#include <stdint.h>

#include "platform_autoconf.h"
#include "ameba_soc.h"
#include "rtk_wpan_time.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*timer_timeout_callback)(void);

int rtk_wpan_timer_init(void);
int rtk_wpan_timer_deinit(void);
bool rtk_wpan_timer_run_direct_check(uint64_t remaining_us);
int rtk_wpan_timer_start(uint64_t t0, uint64_t dt);
int rtk_wpan_timer_stop(void);

#define RTK_WPAN_TIMER_RUN_DIRECT RTK_ERR_TIMEOUT

/**
 *@}
 **/

#ifdef __cplusplus
}
#endif

#endif /* RTK_WPAN_TIMER_H_ */