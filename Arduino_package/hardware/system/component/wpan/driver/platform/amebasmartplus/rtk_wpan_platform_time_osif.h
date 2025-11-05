#ifndef RTK_WPAN_PLATFORM_TIME_OSIF_H_
#define RTK_WPAN_PLATFORM_TIME_OSIF_H_

#include <stdbool.h>
#include <stdint.h>

#include "platform_autoconf.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_WPAN_DRIVER_TIME_OSIF) && CONFIG_WPAN_DRIVER_TIME_OSIF
#if defined(CONFIG_AMEBASMARTPLUS) && CONFIG_AMEBASMARTPLUS

#define RTK_WPAN_TIME_OBJ_PERIOD_US     (0xFFFFFFFFFFFFFFFF) // not sure
#define RTK_WPAN_TIME_OBJ_XTAL_ACCURACY     (40) // not sure
#define RTK_WPAN_TIME_OBJ_GRANULARITY  (32) //us per tick, not sure

#endif
#endif

/**
 *@}
 **/

#ifdef __cplusplus
}
#endif

#endif