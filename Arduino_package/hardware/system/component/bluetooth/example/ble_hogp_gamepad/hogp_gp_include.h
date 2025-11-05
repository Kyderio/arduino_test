/*
 *******************************************************************************
 * Copyright(c) 2022, Realtek Semiconductor Corporation. All rights reserved.
 *******************************************************************************
 */

#ifndef __HOGP_GP_INCLUDE_H__
#define __HOGP_GP_INCLUDE_H__


#ifdef __cplusplus
extern "C"  {
#endif

#include <rtk_bt_def.h>

/********************** HID service related *********************/
typedef enum {
	HID_PROTOCOL_MODE = 0x01,
	HID_REPORT_INPUT,
	HID_REPORT_OUTPUT,
	HID_REPORT_FEATURE,
	HID_REPORT_MAP,
	HID_EXTERNAL_REPORT_REFER,
	HID_BOOT_KB_IN_REPORT,
	HID_BOOT_KB_OUT_REPORT,
	HID_BOOT_MS_IN_REPORT,
	HID_INFO,
	HID_CONTROL_POINT,
} T_HIDS_PARAM_TYPE;

typedef struct {
	uint16_t bcd_hid;
	uint8_t  b_country_code;
	uint8_t  flags;
} __attribute__((packed)) T_HID_INFO;

typedef enum {
	HID_INPUT_TYPE   = 1,
	HID_OUTPUT_TYPE  = 2,
	HID_FEATURE_TYPE = 3
} T_PROFILE_HID_REPORT_TYPE;

typedef enum {
	HID_SUSPEND         = 0,
	HID_EXIT_SUSPEND    = 1,
} T_HID_CTL_POINT;

typedef enum {
	BOOT_PROTOCOL_MODE = 0,
	REPORT_PROCOCOL_MODE = 1
} T_HID_PROTOCOL_MODE;

void gp_hid_srv_callback(uint8_t event, void *data);

uint16_t gp_hid_srv_add(void);

void gp_hids_disconnect(uint16_t conn_handle);

void gp_hids_status_deinit(void);


/*************** device information service related function ****************/
void gp_device_info_srv_callback(uint8_t event, void *data);

uint16_t gp_device_info_srv_add(void);

void gp_dis_disconnect(uint16_t conn_handle);

void gp_dis_status_deinit(void);

#ifdef __cplusplus
}
#endif

#endif  /* __HOGP_GP_INCLUDE_H__ */