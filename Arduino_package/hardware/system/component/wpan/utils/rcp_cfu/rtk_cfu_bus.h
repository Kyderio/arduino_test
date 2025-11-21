#ifndef RTK_CFU_BUS_H_
#define RTK_CFU_BUS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include <rtk_wpan_osif.h>
#include "ameba_soc.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef FIXED_DEVICE_CONFIG
#define FIXED_DEVICE_CONFIG 0
#endif

#define DEVICE_NODE_PATH_LEAN_MAX 5
#define kMaxWaitTime 2000 // ms

typedef enum {
	NO_ERR,
	ERR_TIMEOUT,
	ERR_DISCONN,
	ERR_UNEXPECTED,
	ERR_UNKNOWN,
} T_EXEC_RESULT;

struct CfuTTYDeviceConfiguration {
	char  device_node[DEVICE_NODE_PATH_LEAN_MAX];
	int baudrate;
	char parity[8];
	int flowctl;
	int stopbit;
};

#define kMaxFrameSize 512

typedef bool (*FrameHandler)(uint8_t *buff, uint16_t len);

int device_open(void);
void device_close(void);
int ttyWrite(const uint8_t *aFrame, uint16_t aLength);
int ttyWaitForFrame(uint64_t aTimeoutUs, FrameHandler handler);
bool ttyGetDeviceName(char dev_name[48], uint16_t *len);
bool ttydevice_baud_set(int baudrate);
bool ttydevice_flowctl_set(bool enable);

#ifdef __cplusplus
}
#endif

#endif