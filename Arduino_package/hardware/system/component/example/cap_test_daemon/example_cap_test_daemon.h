#ifndef _EXAMPLE_CAP_TEST_DAEMON_H_
#define _EXAMPLE_CAP_TEST_DAEMON_H_

#include "platform_stdlib.h"
#include "basic_types.h"
#include "ameba_soc.h"
#include "cJSON/cJSON.h"
#include "os_wrapper.h"
#include "os_wrapper.h"
#include "PinNames.h"
#include "serial_api.h"
#include "serial_ex_api.h"
#include "timer_api.h"
#include "platform_autoconf.h"

#define CAP_SW_VERSION			"1.0"

#define CAP_MAX_CH				CT_CHANNEL_NUM

#define CAP_TIMER				TIMER5
#define MBIAS_MAX_VALUE			64
#ifdef CONFIG_AMEBALITE
#define CAP_UART_NODE			1
#define CAP_UART_RX				PA_0
#define CAP_UART_TX				PA_1
#define PINMUX_FUNCTION_CTCADC	PINMUX_FUNCTION_AUXIN
#define CAP_SCAN_INTERVAL		CT_GET_SCAN_INTERVAL
#define CHIP_NAME				"AmebaLite"
#elif defined(CONFIG_AMEBASMART)
#define CAP_UART_NODE			1
#define CAP_UART_RX				PB_10
#define CAP_UART_TX				PB_11
#define PINMUX_FUNCTION_CTCADC	PINMUX_FUNCTION_CAPTOUCH
#define CAP_SCAN_INTERVAL		CT_GET_SCAN_INTERVAL
#define CHIP_NAME				"AmebaSmart"
#elif defined(CONFIG_AMEBADPLUS)
#define CAP_UART_NODE			1
#define CAP_UART_RX				PB_30
#define CAP_UART_TX				PB_31
#define PINMUX_FUNCTION_CTCADC	PINMUX_FUNCTION_CAP_TOUCH
#define CAP_SCAN_INTERVAL		CT_GET_SLEEP_TIME_CNT
#define CHIP_NAME				"AmebaDplus"
#endif
#define CAP_UART_TX_DMA_EN		1
#define CAP_UART_BAUDRATE		1500000
#define MBIAS_TUNE_TARGET		3300
#define MBIAS_TUNE_ERROR		300

typedef struct {
	int cmd;
	char *txt;
} cap_cmd_t;

typedef struct {
	int scan_int;
	int step;
	int avg_samp;
	int etc_en;
	int etc_int;
	int etc_factor;
	int deb_en;
	int deb_cnt;
	int clk_src;
	int xtal_div;
	int proof;
	int filter_en;
	int mdec;
	int med_coef;
	int iir_en;
	int iir_a1;
	int iir_gain;
	char *chip_name;
} cap_cfg_req_t;

typedef struct {
	int ch;
	int enable;
	int mbias;
	int diff_th;
	int abs_th;
	int nn_th;
	int pn_th;
} cap_ch_cfg_req_t;

typedef struct {
	u8 ch;
	u16 raw_data;
	u16 baseline;
	s16 diff_data;
	u16 cap;
} _PACKED_ cap_ch_rt_data_t;

typedef struct {
	u16 samp_int;
	u8 debug_en;
	u8 switch_ctrl;
	u8 channels[CAP_MAX_CH];
} cap_start_req_t;

typedef struct {
	u32 cmd_rx_cnt;
	u32 cmd_start_cnt;
	u32 cmd_end_cnt;

	u32 rx_cnt;
	u32 tx_cnt;

	u8 monitor_channels;
	u8 monitor_stop;
	u8 monitor_status;

	cap_start_req_t monitor_cfg;

	gtimer_t timer_obj;

	serial_t serial_obj;

	rtos_sema_t rx_sema;
	rtos_sema_t timer_sema;
	rtos_sema_t dma_tx_sema;
	rtos_mutex_t tx_mutex;

	rtos_task_t tx_task;
} cap_ctrl_t;

void example_cap_test_daemon(void);

#endif // _EXAMPLE_CAP_TEST_DAEMON_H_

