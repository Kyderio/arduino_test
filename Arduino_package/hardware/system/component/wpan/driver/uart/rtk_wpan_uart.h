#ifndef RTK_WPAN_UART_H_
#define RTK_WPAN_UART_H_

#include "platform_autoconf.h"
#include "ameba_soc.h"
#include "rtk_wpan_log.h"
#include "rtk_wpan_osif.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*uart_receive_handler)(const uint8_t *buff, uint16_t len);
typedef void (*uart_trans_done)(void);
typedef void (*uart_recv_callback)(void);
typedef void (*uart_tran_callback)(void);

int rtk_wpan_uart_init(bool flowctl, int baudrate, uart_recv_callback callback);
int rtk_wpan_uart_deinit(void);
void rtk_wpan_uart_read(const uart_receive_handler receive_handler, const uint16_t receive_len_limit);
uint16_t rtk_wpan_uart_write_sync(const uint8_t *pstr, uint16_t len);
uint16_t rtk_wpan_uart_write_async(const uint8_t *pstr, uint16_t len, uart_trans_done callback);
int rtk_wpan_uart_rxbuf_reset(void);
uint16_t rtk_wpan_uart_get_rxbuf_szie(void);

#ifdef __cplusplus
}
#endif

#endif /* RTK_WPAN_UART_H_ */