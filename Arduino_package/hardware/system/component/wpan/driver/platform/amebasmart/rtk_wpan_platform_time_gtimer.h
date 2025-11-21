#ifndef RTK_WPAN_PLATFORM_TIME_GTIMER_H_
#define RTK_WPAN_PLATFORM_TIME_GTIMER_H_

#include <stdbool.h>
#include <stdint.h>

#include "platform_autoconf.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_WPAN_DRIVER_TIME_GTIMER) && CONFIG_WPAN_DRIVER_TIME_GTIMER
#if defined(CONFIG_AMEBASMART) && CONFIG_AMEBASMART

#define RTK_WPAN_TIME_OBJ_GTIMER_INDEX  (10)
#define RTK_WPAN_TIME_OBJ_PERIOD_US     (0xFFFFFFFF)
#define RTK_WPAN_TIME_OBJ_XTAL_ACCURACY     (40) // not sure
#define RTK_WPAN_TIME_OBJ_GRANULARITY  (1) //us per tick

#endif
#endif
/**
 *@}
 **/

#ifdef __cplusplus
}
#endif

#endif