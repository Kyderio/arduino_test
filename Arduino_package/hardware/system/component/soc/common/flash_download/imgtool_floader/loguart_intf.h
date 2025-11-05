/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _LOGUART_INTF_H_
#define _LOGUART_INTF_H_

/* Includes ------------------------------------------------------------------*/

#include "ameba_soc.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

enum fl_uart_rx_flag {
	RX_IDLE,
	RX_ING,
	RX_ERR,
};

enum fl_uart_check_progress {
	CK_END,
	CK_HEADER,
	CK_CHECKSUM,
};

struct fl_uart_status {
	u32 rx_count; // RX data length (Unit: Bytes)
	u32 frame_len;
	u32 checksum;
	u32 time_stamp;
	u16 payload_len;
	u8 *rx_buf;
	u8 *cur_frame;
	enum fl_uart_rx_flag rx_flag;
	enum fl_uart_check_progress check_progress;
	u8 initialized;
};

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

void loguart_init(void);

void loguart_deinit(void);

#endif /* _LOGUART_INTF_H_ */
