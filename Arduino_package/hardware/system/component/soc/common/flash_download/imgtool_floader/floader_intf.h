/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _FLOADER_INTF_H_
#define _FLOADER_INTF_H_

/* Includes ------------------------------------------------------------------*/

#include "ameba_soc.h"
#include "ameba_ftl.h"
#include "floader_intf.h"
#include "floader_fb.h"
#include "floader_rom_api.h"

/* Exported defines ----------------------------------------------------------*/

/* OTP support */
#define FL_OTP_PROGRAM_EN

/* Downloading mp image to ram */
#if defined(CONFIG_AMEBALITE) || defined(CONFIG_AMEBADPLUS)
#define FL_MP_BOOTLOADER                        0x3000A020
#define FL_MP_RAM_ENTRY                         (0x20012000 + 4 * 1024)	//ram addr, boot.bin: 4k manifest + 1k entry + boot text
#endif

#if defined(CONFIG_AMEBASMART) || defined(CONFIG_AMEBASMARTPLUS)
#define FL_TX_BUF_LEN                           (5 * 1024U)
#define FL_RX_BUF_LEN                           (5 * 1024U)
#else
#define FL_TX_BUF_LEN                           (2 * 1024U)
#define FL_RX_BUF_LEN                           (2 * 1024U)
#endif

#if defined(CONFIG_AMEBASMART)
#define FL_PWM_TIMER_NUM                        8
#define FL_PWM_PERIPH                           APBPeriph_TIM8
#define FL_PWM_CLOCK                            APBPeriph_TIM8_CLOCK
#define FL_PWM_PINMUX_FUNCTION_ID               PINMUX_FUNCTION_PWM
#define FL_PWM_NODE                             TIM8
#define FL_PWM_IRQ                              TIMER8_IRQ
#define FL_PWM_PRESCALER                        40 // 40MHz / 40 = 1MHz => 1us
#elif defined(CONFIG_AMEBASMARTPLUS)
#define FL_PWM_TIMER_NUM                        8
#define FL_PWM_PERIPH                           APBPeriph_TIM8
#define FL_PWM_CLOCK                            APBPeriph_TIM8_CLOCK
#define FL_PWM_NODE                             TIM8
#define FL_PWM_IRQ                              TIMER8_IRQ
#define FL_PWM_PRESCALER                        40 // 40MHz / 40 = 1MHz => 1us
#elif defined(CONFIG_AMEBADPLUS)
#define FL_PWM_TIMER_NUM                        8
#define FL_PWM_PERIPH                           APBPeriph_PWM0
#define FL_PWM_CLOCK                            APBPeriph_PWM0_CLOCK
#define FL_PWM_NODE                             TIM8
#define FL_PWM_IRQ                              TIMER8_IRQ
#define FL_PWM_PRESCALER                        40 // 40MHz / 40 = 1MHz => 1us
#elif defined(CONFIG_AMEBALITE)
#define FL_PWM_TIMER_NUM                        8
#define FL_PWM_PERIPH                           APBPeriph_TIM_PWM
#define FL_PWM_CLOCK                            APBPeriph_TIM_PWM_CLOCK
#define FL_PWM_NODE                             TIM8
#define FL_PWM_IRQ                              TIMER8_IRQ
#define FL_PWM_PRESCALER                        40 // 40MHz / 40 = 1MHz => 1us
#elif defined(CONFIG_AMEBAGREEN2)
#define FL_PWM_PRESCALER                        40 // 40MHz / 40 = 1MHz => 1us
#define FL_PWM_NUM_MIN                          6
#define FL_PWM_NUM_MAX                          (FL_PWM_NUM_MIN + PWM_TIMER_NUM - 1)
#elif defined(CONFIG_AMEBAL2)
#define FL_PWM_PRESCALER                        40 // 40MHz / 40 = 1MHz => 1us
#define FL_PWM_NUM_MIN                          6
#define FL_PWM_NUM_MAX                          (FL_PWM_NUM_MIN + PWM_TIMER_NUM - 1)
#else
#error "ERROR: SoC NOT supported yet"
#endif

#if defined(CONFIG_AMEBASMART) || defined(CONFIG_AMEBASMARTPLUS)
#ifdef CONFIG_FPGA
#define FL_SHARED_BT_MEM_ADDR					0x20020000  //0x20020000 ~ 0x20040000, FPGA does not support BT share ram
#define FL_FRAME_BUF_LEN                        (128 * 1024U)
#else
#define FL_SHARED_BT_MEM_ADDR					HP_SRAM_EXT_BASE  //0x2200_0000 ~ 0x2200_0000, 48K+48K+80K+96K = 272K
#define FL_FRAME_BUF_LEN                        (272 * 1024U)
#endif
#elif defined(CONFIG_AMEBADPLUS)
#define FL_SHARED_BT_MEM_ADDR					SHARE_MEM_BT_E0_ADDRESS  //0x2008_0000 ~ 0x2009_E000, 64K+56K = 120K
#define FL_FRAME_BUF_LEN                        (120 * 1024U)
#elif defined(CONFIG_AMEBALITE)
#define FL_SHARED_BT_MEM_ADDR					SHARE_MEM_BTOFF_E0_ADDRESS  //0x2200_0000 ~ 0x2204_4000, 272K
#define FL_FRAME_BUF_LEN                        (224 * 1024U)
#elif defined(CONFIG_AMEBAGREEN2)
#define FL_SHARED_BT_MEM_ADDR					SHARE_MEM_BT_E0_ADDRESS  //0x20080000 ~ 0x200A_6000, 96K+56K = 152K
#define FL_FRAME_BUF_LEN                        (152 * 1024U)
#elif defined(CONFIG_AMEBAL2)
#define FL_SHARED_BT_MEM_ADDR					SHARE_MEM_BT_E0_ADDRESS  // 0x20080000 ~ 0x20A60000, 96K+56K = 152K
#define FL_FRAME_BUF_LEN                        (152 * 1024U)
#else
#error "ERROR: SoC NOT supported yet"
#endif

#define FL_FRAME_BUF_START_ADDR					FL_SHARED_BT_MEM_ADDR

#define FL_GET_MAX_FRAME_NUM(payload_len)       ((FL_FRAME_BUF_LEN) / (payload_len))
#define FL_GET_MAX_FRAME_PAYLOAD_LEN(page_size) ((page_size) + 6U)
#define FL_MIN_FRAME_PAYLOAD_LEN                1

#define FL_PAGE_SIZE_1K                         1024U
#define FL_PAGE_SIZE_2K                         2048U
#define FL_PAGE_SIZE_4K                         4096U

#define FL_MAX_FRAME_PAYLOAD_LEN_1K             (FL_GET_MAX_FRAME_PAYLOAD_LEN(FL_PAGE_SIZE_1K))
#define FL_MAX_FRAME_PAYLOAD_LEN_2K             (FL_GET_MAX_FRAME_PAYLOAD_LEN(FL_PAGE_SIZE_2K))
#define FL_MAX_FRAME_PAYLOAD_LEN_4K             (FL_GET_MAX_FRAME_PAYLOAD_LEN(FL_PAGE_SIZE_4K))

#define FL_GET_FRAME_LEN(payload_len)           ((payload_len) + 5U)

#define FL_MIN_FRAME_LEN                        (FL_GET_FRAME_LEN(FL_MIN_FRAME_PAYLOAD_LEN))
#define FL_MAX_FRAME_LEN(page_size)             (FL_GET_FRAME_LEN(FL_GET_MAX_FRAME_PAYLOAD_LEN(page_size)))

#define FL_FRAME_HEADER_LEN                     4U

#define FL_CMD_MODE_MASK                        0x80
#define FL_CMD_MODE_ASYNC                       0x80
#define FL_CMD_MODE_SYNC                        0x00

#define FL_ASYNC_CMD(x)                         ((x) | FL_CMD_MODE_ASYNC)
#define FL_SYNC_CMD(x)                          ((x) | FL_CMD_MODE_SYNC)
#define FL_IS_SYNC_CMD(x)                       (((x) & FL_CMD_MODE_MASK) == FL_CMD_MODE_SYNC)
#define FL_IS_ASYNC_CMD(x)                      (((x) & FL_CMD_MODE_MASK) == FL_CMD_MODE_ASYNC)

/* Common operations */
#define BAUDSET                                 FL_ASYNC_CMD(0x01)	/* Set baudrate */
#define QUERY                                   FL_SYNC_CMD(0x02)   /* Query device info */
#define CONFIG                                  FL_ASYNC_CMD(0x03)	/* Config download parameters */
#define	WRITE                                   FL_ASYNC_CMD(0x04)	/* Write data to RAM */
#define READ                                    FL_SYNC_CMD(0x05)	/* Read data from RAM */
#define CHKSM                                   FL_SYNC_CMD(0x06)	/* Calculate checksum for RAM */
#define SENSE                                   FL_SYNC_CMD(0x07)	/* Query comamnd execute status */
#define NEXTOP                                  FL_SYNC_CMD(0x08)   /* Next operation after download process */

/* Flash operations */
#define FS_ERASE                                FL_ASYNC_CMD(0x20)	/* Erase flash */
#define	FS_RDSTS                                FL_SYNC_CMD(0x21)	/* Read flash status register */
#define	FS_WRSTS                                FL_ASYNC_CMD(0x22)	/* Write flash status register */
#define FS_MKBAD                                FL_ASYNC_CMD(0x23)	/* Mark NAND flash bad block */
#define FS_CHKMAP                               FL_SYNC_CMD(0x24)	/* Read NAND flash bad block table */
#define	FS_CHKBAD                               FL_SYNC_CMD(0x25)	/* Read NAND block bad mark */
#define FS_CHKBLK                               FL_SYNC_CMD(0x26)	/* Read NAND block status */

/* OTP operations */
#define OTP_RRAW                                FL_SYNC_CMD(0x40)   /* Read physical efuse */
#define OTP_WRAW                                FL_ASYNC_CMD(0x41)  /* Write physical efuse */
#define OTP_RMAP                                FL_SYNC_CMD(0x42)   /* Read logical efuse */
#define OTP_WMAP                                FL_ASYNC_CMD(0x43)  /* Write logical efuse */

#define FL_SOF                                  0xA5

/* NEXTOP opcode */
#define NEXTOP_NONE                             0x00 /* Nothing to do*/
#define NEXTOP_INDICATE                         0x01 /* Indicate download result with GPIO/PWM as configured in CONFIG request */
#define NEXTOP_EXIT                             0x02 /* Exit the download progress */
#define NEXTOP_BOOT                             0x03 /* Boot from RAM after download */
#define NEXTOP_REBURN                           0x04 /* Reboot and re-enter download mode*/


// Memory type
#define MEM_TYPE_RAM                            0x00U
#define MEM_TYPE_NOR                            0x01U
#define MEM_TYPE_NAND                           0x02U
#define MEM_TYPE_VENDOR                         0x03U
#define MEM_TYPE_HYBRID                         0x04U

/* Payload length */

#define READ_REQUEST_PAYLOAD_LEN                10U
#define READ_RESPONSE_PAYLOAD_LEN(data_len)     (1 + (data_len))

#define CHKSM_REQUEST_PAYLOAD_LEN               14U
#define CHKSM_RESPONSE_PAYLOAD_LEN              5U

#define NEXTOP_REQUEST_PAYLOAD_LEN              6U

#define BAUDSET_REQUEST_PAYLOAD_LEN             5U

#define SENSE_REQUEST_PAYLOAD_LEN               1U
#define SENSE_RESPONSE_PAYLOAD_LEN              7U

#define QUERY_REQUEST_PAYLOAD_LEN               1U
#define QUERY_RESPONSE_PAYLOAD_LEN              129U

#define CONFIG_REQUEST_PAYLOAD_LEN              17U

#define FS_ERASE_REQUEST_PAYLOAD_LEN            15U

#define FS_RDSTS_REQUEST_PAYLOAD_LEN            3U
#define FS_RDSTS_RESPONSE_PAYLOAD_LEN           2U
#define FS_WRSTS_REQUEST_PAYLOAD_LEN            4U

#define FS_CHKBLK_REQUEST_PAYLOAD_LEN           5U
#define FS_CHKBLK_RESPONSE_PAYLOAD_LEN          18U

#define FS_CHKBAD_REQUEST_PAYLOAD_LEN           5U
#define FS_CHKBAD_RESPONSE_PAYLOAD_LEN          2U

#define FS_MKBAD_REQUEST_PAYLOAD_LEN            5U

#define OTP_RRAW_REQUEST_PAYLOAD_LEN            9U
#define OTP_WRAW_REQUEST_PAYLOAD_MIN_LEN        9U
#define OTP_RMAP_REQUEST_PAYLOAD_LEN            9U
#define OTP_WMAP_REQUEST_PAYLOAD_MIN_LEN        9U

/* Device info */
#define DEV_INFO_IMG_TYPE                       0x01U  /* Flashloader */
#define DEV_INFO_CMD_SET_VERSION                0x0200U  /* 2.0 */

/* Chip ID */
#define CHIP_AMEBADPLUS                         0x6845 /* Read REG_LSYS_CHIP_INFO[15:0] */
#define CHIP_AMEBALITE                          0x6842 /* Read REG_LSYS_CHIP_INFO[15:0] */
#define CHIP_AMEBASMART                         0x6678 /* Read REG_LSYS_SCAN_CTRL[15:0] */
#define CHIP_AMEBAGREEN2                        0x7005 /* Read REG_LSYS_CHIP_INFO[15:0] */
#define CHIP_AMEBASMARTPLUS                     0x7061 /* Read REG_LSYS_SCAN_CTRL[15:0] */

/* Address check */
#define IS_RAM_ADDR(addr)                       (((addr) >= 0x20000000) && ((addr) <= 0x3FFFFFFF))
#define IS_NOR_ADDR(addr)                       (IS_FLASH_ADDR(addr))

/* Floader handshake buadrate */
#define HANDSHAKE_BAUD                          115200

/* WiFi MAC */
#define WIFI_MAC_OTP_ADDR                       0x11A
#define WIFI_MAC_LEN                            6

/* Configuration */
#define CONFIG_NAND_BITFLIP_FAIL_LEVEL_INDEX    0U
#define CONFIG_NAND_BITFLIP_FAIL_LEVEL_MASK     0x00000003U
#define CONFIG_NAND_BITFLIP_FAIL_LEVEL_SHIFT    0U
#define CONFIG_NAND_BITFLIP_FAIL_AT_ERROR       0U
#define CONFIG_NAND_BITFLIP_FAIL_AT_FATAL       1U
#define GET_CONFIG_NAND_BITFLIP_FAIL_LEVEL(cfg) (((cfg) >> CONFIG_NAND_BITFLIP_FAIL_LEVEL_SHIFT) && CONFIG_NAND_BITFLIP_FAIL_LEVEL_MASK)

#define CONFIG_RAM_MEMSET_INDEX                 0U
#define CONFIG_RAM_MEMSET_EN                    (BIT4)
#define IS_CONFIG_RAM_MEMSET_EN(cfg)            (((cfg) & CONFIG_RAM_MEMSET_EN) != 0)
#define CONFIG_RAM_MEMSET_VALUE_MASK            0x000000FFU
#define CONFIG_RAM_MEMSET_VALUE_SHIFT           16U
#define GET_CONFIG_RAM_MEMSET_VALUE(cfg)        ((u8)(((cfg) >> CONFIG_RAM_MEMSET_VALUE_SHIFT) && CONFIG_RAM_MEMSET_VALUE_MASK))

#define CONFIG_INDICATE_PWM_TIMER_NUM_INDEX     0U
#define CONFIG_INDICATE_PWM_TIMER_NUM_MASK      0x0000000FU
#define CONFIG_INDICATE_PWM_TIMER_NUM_SHIFT     24U
#define GET_CONFIG_INDICATE_PWM_TIMER_NUM(cfg)  ((u8)(((cfg) >> CONFIG_INDICATE_PWM_TIMER_NUM_SHIFT) && CONFIG_INDICATE_PWM_TIMER_NUM_MASK))

#define CONFIG_INDICATE_PWM_CHAN_INDEX          0U
#define CONFIG_INDICATE_PWM_CHAN_MASK           0x0000000FU
#define CONFIG_INDICATE_PWM_CHAN_SHIFT          28U
#define GET_CONFIG_INDICATE_PWM_CHAN(cfg)       ((u8)(((cfg) >> CONFIG_INDICATE_PWM_CHAN_SHIFT) && CONFIG_INDICATE_PWM_CHAN_MASK))

#define CONFIG_INDICATE_STRATEGY_INDEX          0U
#define CONFIG_INDICATE_STRATEGY_MASK           0x00000003U
#define CONFIG_INDICATE_STRATEGY_SHIFT          2U
#define CONFIG_INDICATE_STRATEGY_GPIO           1U
#define CONFIG_INDICATE_STRATEGY_PMW            2U
#define GET_CONFIG_INDICATE_STRATEGY(cfg)       (((cfg) >> CONFIG_INDICATE_STRATEGY_SHIFT) && CONFIG_INDICATE_STRATEGY_MASK)

#define CONFIG_INDICATE_PIN_INDEX               0U
#define CONFIG_INDICATE_PIN_MASK                0x000000FFU
#define CONFIG_INDICATE_PIN_SHIFT               8U
#define GET_CONFIG_INDICATE_PIN(cfg)            ((u8)(((cfg) >> CONFIG_INDICATE_PIN_SHIFT) && CONFIG_INDICATE_PIN_MASK))

#define CONFIG_INDICATE_GPIO_LEVEL_INDEX        1U
#define CONFIG_INDICATE_GPIO_LEVEL_MASK         (BIT0)
#define CONFIG_INDICATE_GPIO_LEVEL_SHIFT        0U
#define GET_CONFIG_INDICATE_GPIO_LEVEL(cfg)     (((cfg) >> CONFIG_INDICATE_GPIO_LEVEL_SHIFT) && CONFIG_INDICATE_GPIO_LEVEL_MASK)

#define CONFIG_INDICATE_PWM_INDEX               1U
#define CONFIG_INDICATE_PWM_PERIOD_MASK         0x01FFFFFFU
#define CONFIG_INDICATE_PWM_PERIOD_SHIFT        0U
#define GET_CONFIG_INDICATE_PWM_PERIOD(cfg)     (((cfg) >> CONFIG_INDICATE_PWM_PERIOD_SHIFT) && CONFIG_INDICATE_PWM_PERIOD_MASK)
#define CONFIG_INDICATE_PWM_DUTY_CYCLE_MASK     0x0000007FU
#define CONFIG_INDICATE_PWM_DUTY_CYCLE_SHIFT    25U
#define GET_CONFIG_INDICATE_PWM_DUTY_CYCLE(cfg) (((cfg) >> CONFIG_INDICATE_PWM_DUTY_CYCLE_SHIFT) && CONFIG_INDICATE_PWM_DUTY_CYCLE_MASK)

enum fl_intf_type {
	INTF_NONE = 0,
	INTF_UART,
	INTF_USB
};

enum fl_buf_status {
	ACK_FREE = 0xB0,
	ACK_FULL = 0xB1
};

struct __PACKED fl_frame_header {
	u8 magic_key;
	u8 len_low;
	u8 len_high;
	u8 len_xor;
};

struct fl_exe_status {
	u8 cmd_opcode;
	enum ftl_errno error_status;
	u32 extra_data;
};

struct __PACKED fl_device_info {
	u16 device_id;
	u16 image_type;
	u16 cmd_set_version;
	u8 memory_type;
	struct ameba_flash_info flash_info;
	u8 wifi_mac[WIFI_MAC_LEN];
	u8 reserved[51];  /* Padding for 128 bytes */
};

struct fl_intf_ops {
	void(* transmit_data)(u8 *buf, u32 len);
	void(* transmit_status)(u8 status);
	void(* set_baudrate)(u32 baudrate);
};

struct fl_ctrl_block {
	u32 config[4];
	struct fl_device_info device_info;
	struct fl_exe_status exe_status;
	struct fl_intf_ops *ops;
	u32 expected_addr;
	u32 baudrate;
	u32 uart_frame_timeout;
	u8 rx_buf[FL_RX_BUF_LEN];
	u8 tx_buf[FL_TX_BUF_LEN];
	u32 page_size;
	u32 max_frame_len;
	u32 max_frame_payload_len;
	int max_frame_num;
	enum fl_intf_type intf;
	u8 *frame_buf;
	u8 uart_idx;
	u8 initialized: 1;
	u8 jump_to_ram: 1;
	u8 usb_enabled: 1;
	u8 uart_enabled: 1;
};

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

extern struct fl_ctrl_block *fl_ctrl;

/* Exported functions ------------------------------------------------------- */

static inline u8 fl_check_frame_header_magic(struct fl_frame_header *header)
{
	/* Check magic key */
	if (header->magic_key != FL_SOF) {
		return ERR_INVALID;
	}

	return ERR_NONE;
}

u8 fl_init(u8 uart_idx, u32 baudrate);
void fl_rx_handler(void);
void fl_transmit_status(u8 status);
u8 fl_check_frame_header(struct fl_frame_header *header, u16 *payload_len);
u8 fl_check_frame_header_length(struct fl_frame_header *header, u16 *payload_len);
u8 fl_check_frame_payload(u8 *payload, u16 len);

#endif /* _FLOADER_INTF_H_ */

