#ifndef RTK_WPAN_TIME_H_
#define RTK_WPAN_TIME_H_

#include <stdbool.h>
#include <stdint.h>

#include "platform_autoconf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*time_timeout_callback)(void);

uint64_t rtk_wpan_time_get_us(void);
uint64_t rtk_wpan_time_get_ms(void);
int rtk_wpan_time_init(void);
int rtk_wpan_time_deinit(void);
uint64_t rtk_wpan_time_get_target_us(uint64_t t0, uint64_t dt, uint64_t now);
uint64_t rtk_wpan_time_get_remain_us(uint64_t t0, uint64_t dt);
uint32_t rtk_wpan_time_granularity_get(void);
void rtk_wpan_time_error_print(void);

/**
 *@}
 **/

#ifdef __cplusplus
}
#endif

#endif