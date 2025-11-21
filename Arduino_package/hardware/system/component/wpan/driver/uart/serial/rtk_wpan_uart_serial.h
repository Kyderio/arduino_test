#ifndef RTK_WPAN_UART_SERIAL_H_
#define RTK_WPAN_UART_SERIAL_H_

#include "platform_autoconf.h"
#include "ameba_soc.h"
#include "rtk_wpan_log.h"

#ifdef __cplusplus
extern "C" {
#endif

#if (defined(CONFIG_WPAN_DRIVER_UART_SERIAL) && CONFIG_WPAN_DRIVER_UART_SERIAL)

int rtk_wpan_uart_obj_set_pin(char *tx, char *rx, char *rts, char *cts);//example: PA_0

#endif

#ifdef __cplusplus
}
#endif

#endif