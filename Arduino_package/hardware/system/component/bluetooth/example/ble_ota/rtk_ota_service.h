/*
 *******************************************************************************
 * Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
 *******************************************************************************
 */

#ifndef __RTK_OTA_SERVICE_H__
#define __RTK_OTA_SERVICE_H__

#ifdef __cplusplus
extern "C"  {
#endif

#include <rtk_bt_def.h>
#include <ota_server_platform.h>


#define DFU_DATA_BUFFER_SIZE    4096


typedef enum {
	OTA_IMAGE_HEADER_GET = 0x01,
	OTA_HEADER_CHECK = 0x02,
	OTA_CHECKSUM_VERIFY = 0x03,
	OTA_COMPLETE = 0x04
} OTA_CTRL_IND_OPCODE;

typedef enum {
	OTA_HDR_CHECK_OK = 0x01,
	OTA_HDR_CHECKSUM_ERR,
	OTA_HDR_INFO_ERR,
	OTA_HDR_LEN_ERR
} OTA_HDR_CHECK_RESULT;

typedef enum {
	OTA_CHECKSUM_OK = 0x01,
	OTA_DATA_CHECKSUM_ERR,
	OTA_IMAGE_CHECKSUM_ERR,
	OTA_DATA_OFFSET_ERR
} OTA_CHECKSUM_VERIFY_RESULT;

typedef struct {
	ota_update_header_info_t OtaHdrInfo;
	uint16_t conn_handle;
	uint8_t index;                              //index of current handling ota fw image info
	uint8_t OtaCompletedFlag;                   //the ota process completed flag
	uint8_t OtaErrFlg;                          //OTA error disconnect flag
	uint8_t target_idx;                         //(0 - OTA1, 1 - OTA2) which flash space the new fw image will be updated
	uint8_t image_id;                           //current handling ota fw image id. (can be set 0xff if no used)
	uint8_t skip_boot_ota_flg;                  //skip bootloader OTA2 flag, 0 not skip, 1 skip bootloader ota
	uint32_t flash_addr;                        //flash address of ota image upgrade
	uint32_t cur_offset;                        //received data length of current handling ota fw image
	uint32_t image_len[OTA_FILE_IMAGE_MAX_NUM]; //current image len
	uint32_t ota_image_total_len;               //ota image total length
	uint32_t sign_offset;                       //current handling ota fw image signature offset
	uint32_t checksum;                          //checksum of current handling ota fw image
	uint8_t rsvd[4];
} ota_dfu_ctrl_info_t;

void ble_ota_srv_callback(uint8_t event, void *data);

uint16_t ble_ota_srv_add(void);

void ble_ota_srv_disconnect(uint16_t conn_handle);

void ble_ota_srv_status_deinit(void);

void ble_ota_srv_app_init(void);

void ble_ota_srv_app_deinit(void);

void ble_ota_srv_timer_stop(void);

void ble_ota_reboot(void);


#ifdef __cplusplus
}
#endif

#endif  /* __RTK_OTA_SERVICE_H__ */
