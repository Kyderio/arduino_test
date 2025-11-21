/*
 *******************************************************************************
 * Copyright(c) 2025, Realtek Semiconductor Corporation. All rights reserved.
 *******************************************************************************
 * note: amebasmart ota server platform include file
 */

#ifndef __OTA_SERVER_PLATFORM_H__
#define __OTA_SERVER_PLATFORM_H__

#ifdef __cplusplus
extern "C"  {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define OTA_FILE_IMAGE_MAX_NUM      2
#define OTA_FILE_HEADER_LEN         8
#define OTA_FILE_IMAGE_HEADER_LEN   24
#define OTA_FILE_HEADER_LEN_MAX     (OTA_FILE_HEADER_LEN + OTA_FILE_IMAGE_HEADER_LEN * OTA_FILE_IMAGE_MAX_NUM)

#define OTA_ADDR_INDEX_1    0
#define OTA_ADDR_INDEX_2    1

typedef enum {
	OTA_IMAGE_BOOT_ID = 0x0,
	OTA_IMAGE_APP_ID = 0x01,
	OTA_IMAGE_APIMG_ID = 0x02,
	OTA_IMAGE_ID_MAX
} OTA_IMAGE_ID;


/**
  * @brief  OTA update file header structure definition
  */
typedef struct {
	uint32_t HdrVer;    /* the version of OTA header */
	uint32_t HdrNum;    /* the number of OTA header */
} ota_file_hdr_t;

/**
  * @brief  OTA update file target image header structure definition
  */
typedef struct {
	uint8_t Signature[4];    /* the OTA signature, this value is "OTA" */
	uint32_t HdrLen;         /* the length of OTA header */
	uint32_t Checksum;       /* the checksum of OTA fw image */
	uint32_t ImgLen;         /* the length of OTA fw image */
	uint32_t Offset;         /* the start position of fw image in current image */
	uint32_t ImgID;          /* the image ID of current image */
} ota_file_image_hdr_t;

/**
  * @brief  OTA update file target image manifest structure definition
  */
typedef struct {
	uint32_t Pattern[2];
	uint8_t Rsvd1[8];
	uint8_t Ver;
	uint8_t ImgID;
	uint8_t AuthAlg;
	uint8_t HashAlg;
	uint16_t MajorImgVer;
	uint16_t MinorImgVer;
} ota_file_manifest_info;

/**
  * @brief  OTA update file info structure definition
  */
typedef struct {
	ota_file_hdr_t FileHdr;                                     /* ota update file header */
	ota_file_image_hdr_t ImgHdr[OTA_FILE_IMAGE_MAX_NUM];        /* ota update file target image header */
	ota_file_manifest_info Manifest[OTA_FILE_IMAGE_MAX_NUM];    /* ota update file target image manifest */
	uint8_t ValidImgCnt;                                        /* valid image number in ota file, 0<=ValidImgCnt<=HdrNum */
} ota_update_header_info_t;

/*****************************************************************************************/
typedef struct {
	void (*save_manifest)(uint8_t *buf, uint8_t index);
	void (*update_manifest)(uint8_t index, uint32_t addr);
	uint32_t (*get_manifest_offset)(uint8_t index);
} BLE_OTA_OPS;

extern BLE_OTA_OPS ble_ota_ops;

static inline void ble_ota_save_image_signature(uint8_t *buf, uint8_t index)
{
	return ble_ota_ops.save_manifest(buf, index);
}

static inline void ble_ota_update_image_signature(uint8_t index, uint32_t addr)
{
	return ble_ota_ops.update_manifest(index, addr);
}

static inline uint32_t ble_ota_get_signature_offset(uint8_t index)
{
	return ble_ota_ops.get_manifest_offset(index);
}

/***************************************************************************************/

uint32_t ble_ota_get_cur_index(uint32_t idx);

uint8_t ble_ota_checkbootloader_ota2(void);

uint32_t ble_ota_get_flash_addr(uint8_t index, uint8_t *skip_boot_ota_flg);

void ble_ota_write_flash(uint32_t addr, uint8_t *buf, uint16_t len);

uint32_t ble_ota_get_image_id(uint8_t index);

uint32_t ble_ota_get_image_len(uint32_t *image_len);

bool ble_ota_image_checksum_verify(uint8_t index);

bool ble_ota_image_retransmission_check(ota_update_header_info_t *ota_hdr);

bool ble_ota_parse_target_header(uint8_t *p_value, uint16_t len, ota_update_header_info_t *ota_hdr);

void ble_ota_prepare_system_reset(uint8_t reset);

void ble_ota_platform_system_reset(void);


#ifdef __cplusplus
}
#endif

#endif  /* __AMEBA_OTA_SERVER_CONFIG_H__ */

