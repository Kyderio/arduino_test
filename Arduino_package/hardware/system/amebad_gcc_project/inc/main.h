#ifndef MAIN_H
#define MAIN_H

#include "wifi_api_types.h"

/* Header file declaration*/
void wifi_init(void);
extern int mbedtls_platform_set_calloc_free(
	void *(*calloc_func)(unsigned int, unsigned int),
	void (*free_func)(void *)
);
extern void SystemSetCpuClk(unsigned char CpuClk);
extern void pre_example_entry(void);
extern void example_entry(void);

/* Interactive Mode */
#define SERIAL_DEBUG_RX 1

/* WLAN and Netork */
#define STA_MODE_SSID	"ap"    /* Set SSID here */
#define AP_MODE_SSID		"wlan_ap_ssid"    /* Set SSID here */
#define AP_DEFAULT_CH	6
#define WLAN0_NAME		"wlan0"
#define WLAN1_NAME      	"wlan1"
#define WPA_PASSPHRASE	"1234567890" /* Max 32 cahracters */
#define WEP40_KEY		{0x12, 0x34, 0x56, 0x78, 0x90}

#define ATVER_1 1 // For First AT command
#define ATVER_2 2 // For UART Module AT command

#endif
