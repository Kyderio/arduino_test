#ifndef RTK_WPAN_PLATFORM_POWER_H_
#define RTK_WPAN_PLATFORM_POWER_H_

#include "platform_autoconf.h"
#include "ameba_soc.h"
#include "rtk_wpan_log.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_WPAN_DRIVER_UART_UART) && CONFIG_WPAN_DRIVER_UART_UART

#if defined(CONFIG_AMEBASMARTPLUS) && CONFIG_AMEBASMARTPLUS

int rtk_wpan_platform_rcp_power_on(void);

#endif

#endif

#ifdef __cplusplus
}
#endif

#endif