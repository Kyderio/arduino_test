#ifndef RTK_WPAN_PLATFORM_TIMER_GTIMER_H_
#define RTK_WPAN_PLATFORM_TIMER_GTIMER_H_

#include <stdbool.h>
#include <stdint.h>

#include "platform_autoconf.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_WPAN_DRIVER_TIMER_GTIMER) && CONFIG_WPAN_DRIVER_TIMER_GTIMER
#if defined(CONFIG_AMEBADPLUS) && CONFIG_AMEBADPLUS

#define RTK_WPAN_TIMER_OBJ_GTIMER_INDEX  (11)
#define RTK_WPAN_TIMER_OBJ_TICKS_TO_US(ticks) ((ticks))

#endif
#endif
/**
 *@}
 **/

#ifdef __cplusplus
}
#endif

#endif