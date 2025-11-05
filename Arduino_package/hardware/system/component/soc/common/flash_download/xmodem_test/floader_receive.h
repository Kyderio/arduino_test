/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLOADER_RECV_H_
#define _FLOADER_RECV_H_
#include "floader_flash_ftl.h"
/****************************
 * protocol cmd key value
 ****************************/
#define BAUDSET		(0x01|0x80)	/* baudrate set*/
#define QUERY		0x02		/* query device info */
#define CONFIG		(0x03|0x80)	/* config downloading parameters*/
#define	WRITE		(0x04|0x80)	/* Start of data */
#define READ		0x05		/* Read data */
#define SENSE		0x06		/* query frame execute status. */
#define CHKSM		0x07		/* check sum */
#define NEXTOP		0x08		/* next option can be exit\cancel etc */

//flash option
#define FS_ERASE	(0x20|0x80)	/* erase flash*/
#define	FS_RDSTS	0x21		/* read flash status reg*/
#define	FS_WRSTS	(0x22|0x80)	/* write flash status reg */
#define FS_MKBAD	(0x23|0x80)	/* mark nad flash bad block*/
#define FS_CHKMAP	0x24		/* get nand bad block table*/
#define	FS_CHKBAD	0x25		/* check specific nand block status*/
#define FS_CHKBLK	0x26		/* check all page status of nand block*/

//OTP operation
#define OTP_RRAW	0x40
#define OTP_WRAW	(0x41|0x80)
#define OTP_RMAP	0x42
#define OTP_WMAP	(0x43|0x80)

#define FRAME_START 0xA5

/**************************
 * next operation code
 ***************************/
#define NP_NONE					0x00 /* nothing to do*/
#define NP_INDICATE				0x01 /* gpio/pwm indicator configuration for keep in download mode. */
#define NP_EXIT					0x02 /* to exit the receive loop, and normally reset */
#define NP_REBURN				0x03 /* reboot and re-enter download mode*/

/**************************
 * protocol body length define
***************************/
/*read/write flash*/
#define WRITE_PACKET_LEN					1029U
#define WRITE_PACKET_ADDR_AVAILABLE_LEN		5U

#define FS_ERASE_PACKET_LEN					10U
#define READ_BASE_PACKET_LEN				1U
#define READ_REQUEST_PACKET_LEN				9U
#define READ_RESPONSE_PACKET_LEN(data_len) 	(READ_BASE_PACKET_LEN + data_len)

#define CHKSM_REQUEST_PACKET_LEN			13U
#define CHKSM_RESPONSE_PACKET_LEN			5U
#define NEXTOP_PACKET_LEN					6U
#define BAUDSET_PACKET_LEN					5U

#define SENSE_REQUEST_PACKET_LEN			1U
#define SENSE_RESPONSE_PACKET_LEN			7U

#define QUERY_REQUEST_PACKET_LEN			1U
#define QUERY_RESPONSE_PACKET_LEN			129U

#define CONFIG_PACKET_LEN					17U

#define FS_RDSTS_REQUEST_PACKET_LEN			3U
#define FS_RDSTS_RESPONSE_PACKET_LEN		2U
#define FS_WRSTS_REQUEST_PACKET_LEN			4U

/* OTP read/write*/
#define OTP_RRAW_REQUEST_PACKET_LEN			9U
#define OTP_WRAW_REQUEST_PACKET_MIN_LEN		9U
#define OTP_RMAP_REQUEST_PACKET_LEN			9U
#define OTP_WMAP_REQUEST_PACKET_MIN_LEN		9U

/**************************
 * Device Configuration
***************************/
#define DEV_INFO_IMG_TYPE					0x0001U  /*Flashloader*/
#define DEV_INFO_CMD_SET_VERSION			0x0101U  /*ver = 1.1*/

#define DEV_INFO_BOOT_MEDIA_NOR				0x00U
#define DEV_INFO_BOOT_MEDIA_NAND			0x01U

#define CHIP_AMEBADPLUS						0x6845 /* read REG_LSYS_CHIP_INFO[15:0]*/
#define CHIP_AMEBALITE						0x6842 /* read REG_LSYS_CHIP_INFO[15:0]*/
#define CHIP_AMEBASMART						0x6678 /* read REG_LSYS_SCAN_CTRL[15:0]*/
#define CHIP_AMEBAGREEN2					0x7005 /* read REG_LSYS_CHIP_INFO[15:0]*/
/**************************
 * Download indicator Configuration
***************************/
#define DOWNLOAD_INDICATOR_PIN_MASK			0x3FFF0000U
#define DOWNLOAD_INDICATOR_PIN_SHIFT		16U
#define DOWNLOAD_INDICATOR_CFG_MASK			0xC0000000U
#define DOWNLOAD_INDICATOR_CFG_DISABLE		0x00000000U
#define DOWNLOAD_INDICATOR_CFG_GPIO			0x40000000U
#define DOWNLOAD_INDICATOR_CFG_PWM			0x80000000U
#define DOWNLOAD_INDICATOR_GPIO_LEVEL_MASK	0x00000001U

#define DOWNLOAD_INDICATOR_PWM_PERIOD_MASK	0x01FFFFFFU
#define DOWNLOAD_INDICATOR_PWM_PERIOD_SHIFT	0U
#define DOWNLOAD_INDICATOR_PWM_PERCENT_MASK	0xFE000000U
#define DOWNLOAD_INDICATOR_PWM_PERCENT_SHIFT	25U

/**************************
 * Frame Data Size
***************************/
#define FRAME_DATA_SIZE	1024U

//1.define receive status
enum RecvFlag {
	RECV_IDLE,
	RECV_ING,
	RECV_ERR,
};
enum CheckProgress {
	CK_END,
	CK_HEADER,
	CK_CHECKSUM,
};
struct RecvStatus {
	u32 rx_count; // RX data length (Unit: Bytes)
	u32 frame_len;
	u32 sum;
	char *rx_buf;
	enum RecvFlag recv_flag;
	enum CheckProgress check_progress;
};

/*2 recording frame execute status */
enum ErrorStatus {
	ERR_NONE = 0x00,	/* no error*/
	ERR_FAIL = 0xC0,	/* Failed to execute cmd*/
	ERR_BUSY,			/* device busy */
	ERR_TIMEOUT,		/* time out*/
	ERR_HARDWARE,		/* hardware error */
	ERR_FULL,			/* buffer full*/
	ERR_INVALID,		/* invalid cmd or parameters */
	ERR_LENGTH,			/* invliad frame length*/
	ERR_CHECKSUM,		/* checksum error*/
	ERR_ADDRESS, 		/* unsupported address, or write addr > end addr */
	ERR_NAND_BAD_BLOCK,	/* nand bad block*/
	ERR_NAND_WORN_BLOCK,	/* NAND wore block */
	ERR_NAND_BITFLIP_WARN, 	/* NAND bitflips < ECC level, corrected */
	ERR_NAND_BITFLIP_ERROR, /* NAND bitflips equals to ECC level, corrected */
	ERR_NAND_BITFLIP_FATAL,	/* NAND bitflips higher than ECC level, cannot be corrected*/
};

struct ExecStatus {
	uint8_t cmd_opcode;
	enum ErrorStatus error_status;
	uint32_t extra_data;
};

enum BufStatus {
	ACK_FREE = 0xB0,
	ACK_FULL = 0xB1
};
//4.define cmd function enum
enum CmdFunc {
	CMD_CONTINUE,
	CMD_CANCEL,
	CMD_COMPLETE,
	CMD_UNKNOWN
};

//5.define cmd async/sync type
enum CmdType {
	SYNC = 0x0,
	ASYNC = 0x80,
};

//6. Device Info struct
struct DeviceInfoTypeDef {
	u16   DID;
	u16   ImageType;
	u16   CmdSetVersion;
	u8    BootMediaType;
	Flash_InfoTypeDef FlashInfo;
	u8    Reserved[57];  /* Padding for 96 bytes */
	u8    Checksum;
} _PACKED_;

extern volatile uint32_t expected_addr;
extern uint8_t response_buf[FRAME_BODY_LEN];
extern volatile struct ExecStatus exec_status;
extern struct DeviceInfoTypeDef device_info;
extern uint8_t download_to_ram;

void frame_RecvStatusReset(struct RecvStatus *prs);
void frame_RecvStatusUpdate(struct RecvStatus *prs, u32 frame_len, char *cmd, enum RecvFlag recv_state, enum CheckProgress chk_prog);
void frame_ExecStatusUpdate(uint8_t cmd_op, enum ErrorStatus fs, uint32_t data);
int frame_CheckHeader(struct CmdTable *pcmd);
void frame_PackAndTransmit(uint8_t *data, u32 data_len);
u32 frame_Execute(struct CmdTable *pcmd, uint32_t len);
u32 frame_ReceiveStart(u32 baud_rate);

#endif
