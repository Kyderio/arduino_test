#ifndef __ROM_WIFI_HAL_INIT_H__
#define __ROM_WIFI_HAL_INIT_H__

#define VO_QUEUE_INX		0
#define VI_QUEUE_INX		1
#define BE_QUEUE_INX		2
#define BK_QUEUE_INX		3
#define BCN_QUEUE_INX		4
#define MGT_QUEUE_INX		5
#define HIGH_QUEUE_INX		6
#define TXCMD_QUEUE_INX		7
#define RTW_MAX_TX_QUEUE_COUNT	8

void ROM_WIFI_InitRCR(u32 ReceiveConfig, u16 RXFLTMAP2, u16 RXFLTMAP1, u16 RXFLTMAP0);
void ROM_WIFI_InitLxDma(u32 *tx_desc, u32 *rx_desc, u8 rxq_desc_number);

#endif
