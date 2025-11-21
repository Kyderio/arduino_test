#ifndef RTK_WPAN_PLATFORM_TIME_SYSTICK_H_
#define RTK_WPAN_PLATFORM_TIME_SYSTICK_H_

#include <stdbool.h>
#include <stdint.h>

#include "platform_autoconf.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_WPAN_DRIVER_TIME_SYSTICK) && CONFIG_WPAN_DRIVER_TIME_SYSTICK
#if defined(CONFIG_AMEBADPLUS) && CONFIG_AMEBADPLUS

#define RTK_WPAN_TIME_OBJ_PERIOD_TICK (0xFFFFFFFF)
#define RTK_WPAN_TIME_OBJ_TICKS_TO_US(ticks) ((ticks) * ((float)1000000 / 32768))
#define RTK_WPAN_TIME_OBJ_PERIOD_US     (131071999969) //(RTK_WPAN_TIME_OBJ_TICKS_TO_US((uint64_t)(RTK_WPAN_TIME_OBJ_PERIOD_TICK)))
#define RTK_WPAN_TIME_OBJ_XTAL_ACCURACY     (40) // not sure
#define RTK_WPAN_TIME_OBJ_GRANULARITY  RTK_WPAN_TIME_OBJ_TICKS_TO_US((uint32_t)1) //us per tick

#endif
#endif

/**
 *@}
 **/

#ifdef __cplusplus
}
#endif

#endif