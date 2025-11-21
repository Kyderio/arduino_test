#ifndef RTK_WPAN_PLATFORM_UART_H_
#define RTK_WPAN_PLATFORM_UART_H_

#include "platform_autoconf.h"
#include "ameba_soc.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_WPAN_DRIVER_UART_UART) && CONFIG_WPAN_DRIVER_UART_UART

#if defined(CONFIG_AMEBASMARTPLUS) && CONFIG_AMEBASMARTPLUS

#define UART2INT_DEV             (UART2_DEV)
#define UART2INT_APBPERIPH       (APBPeriph_UART2)
#define UART2INT_APBPERIPH_CLK   (APBPeriph_UART2_CLOCK)
#define UART2INT_IRQ             (UART2_IRQ)
#define UART2INT_IRQ_PRIO        (INT_PRI_LOWEST)

int rtk_wpan_platform_uart_to_host(void);
#endif

#endif

#ifdef __cplusplus
}
#endif

#endif