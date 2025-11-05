/*
 *******************************************************************************
 * Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
 *******************************************************************************
 */


#ifndef __RTK_OTA_CLIENT_H__
#define __RTK_OTA_CLIENT_H__

#ifdef __cplusplus
extern "C"  {
#endif

#include <rtk_bt_common.h>
#include <ota_client_platform.h>


#define OTA_BUFFER_SIZE     4096

typedef enum {
	OTA_IMG_HDR_CHAR_WRITE = 0,
	OTA_HDR_CHECKSUM_CHAR_WRITE,
	OTA_DATA_CHAR_WRITE,
	OTA_DATA_CHECKSUM_CHAR_WRITE,
	OTA_CTRL_CHAR_INDI,
	OTA_CHAR_MAX_NUM,
} OTA_CHAR_INDEX;

typedef enum {
	OTA_IMAGE_HEADER_GET_OP = 0x01,
	OTA_HEADER_CHECK_OP = 0x02,
	OTA_CHECKSUM_VERIFY_OP = 0x03,
	OTA_COMPLETE_OP = 0x04
} OTA_CTRL_INDI_OP;

typedef enum {
	OTA_HDR_OK = 0x01,
	OTA_HDR_ERR_CHECKSUM,
	OTA_HDR_ERR_INFO,
	OTA_HDR_ERR_LEN
} OTA_HDR_STATUS;

typedef enum {
	OTA_CHECKSUM_OK = 0x01,
	OTA_CHECKSUM_ERR_DATA,
	OTA_CHECKSUM_ERR_IMAGE,
	OTA_CHECKSUM_ERR_OTHERS
} OTA_CHECKSUM_VERIFY_STATUS;

typedef struct {
	uint16_t mtu_size;
	uint8_t index;                 //index of current handling ota fw image info
	uint8_t image_id;              //current handling ota fw image id
	uint8_t hdr_total_len;         //ota file header total len
	uint8_t hdr_num;               //the ota header number in ota file
	uint32_t image_offset;         //start position of fw image in image file
	uint32_t cur_offset;           //have sended data offset (without header)
	uint32_t cur_image_len;        //current image length
	uint32_t ota_image_total_len;  // total_len=image1 len( +image2 len)
} ota_msg_t;

rtk_bt_evt_cb_ret_t ble_ota_client_app_callback(uint8_t event, void *data);

uint16_t ble_ota_client_attach_conn(uint16_t conn_handle);

uint16_t ble_ota_client_detach_conn(uint16_t conn_handle);

uint16_t ble_ota_client_add(void);

uint16_t ble_ota_client_delete(void);

uint16_t ble_ota_client_srv_discover(uint16_t conn_handle);

#ifdef __cplusplus
}
#endif

#endif  /* __RTK_OTA_CLIENT_H__ */

