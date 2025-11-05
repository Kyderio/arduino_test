/*
 *******************************************************************************
 * Copyright(c) 2025, Realtek Semiconductor Corporation. All rights reserved.
 *******************************************************************************
 * note: amebalite ota client platform include file
 */

#ifndef __OTA_CLIENT_PLATFORM_H__
#define __OTA_CLIENT_PLATFORM_H__

#ifdef __cplusplus
extern "C"  {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>


#define OTA_IMAGE_FLASH_ADDRESS     0x08216000 //ota image storage flash address

#define OTA_FILE_IMG_MAX_NUM     2
#define OTA_FILE_HDR_LEN         8
#define OTA_FILE_IMG_HDR_LEN     24


typedef struct {
	uint8_t Signature[4];  /* the OTA signature, this value is "OTA" */
	uint32_t HdrLen;       /* the length of OTA header */
	uint32_t Checksum;     /* the checksum of OTA fw image */
	uint32_t ImgLen;       /* the length of OTA fw image */
	uint32_t Offset;       /* the start position of fw image in current image */
	uint32_t ImgID;        /* the image ID of current image */
} ota_img_hdr_t;

typedef struct {
	uint32_t HdrVer;  /* the version of OTA header */
	uint32_t HdrNum;  /* the number of OTA header */
	ota_img_hdr_t ota_img_hdr[OTA_FILE_IMG_MAX_NUM];
} ota_hdr_t;


bool ble_ota_client_handle_image_data(uint8_t *p_header, uint32_t *image_len, uint8_t *hdr_len);

uint32_t ble_ota_client_get_image_offset(uint8_t index);

uint32_t ble_ota_client_get_image_len(uint8_t index);

uint32_t ble_ota_client_get_image_id(uint8_t index);

uint32_t ble_ota_client_get_header_num(void);

uint8_t *ble_ota_client_get_image(void);



#ifdef __cplusplus
}
#endif

#endif  /* __OTA_CLIENT_PLATFORM_H__ */
