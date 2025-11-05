/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __USBD_CDC_ROM_H
#define __USBD_CDC_ROM_H

/* Includes ------------------------------------------------------------------*/

#include "usbd_hal_rom.h"

/* Exported defines ----------------------------------------------------------*/

/* CDC Endpoints parameters */
#define CDC_IN_EP                                   0x81U  /* EP1 for BULK IN */
#define CDC_OUT_EP                                  0x01U  /* EP1 for BULK OUT */
#define CDC_CMD_EP                                  0x82U  /* EP2 for INTR IN */

#define CDC_HS_BINTERVAL                            0x10U
#define CDC_FS_BINTERVAL                            0x10U

#define CDC_CTRL_BUF_SIZE                           256U
#define CDC_DATA_HS_MAX_PACKET_SIZE                 512U  /* High speed BULK IN & OUT Packet size */
#define CDC_DATA_FS_MAX_PACKET_SIZE                 64U   /* Full speed BULK IN & OUT Packet size */
#define CDC_CMD_PACKET_SIZE                         8U    /* INTR IN Packet size */

#define CDC_CONFIG_DESC_SIZE                        67U
#define CDC_DESC_BUF_SIZE							128U  /* >= all descriptor sizes e.g. CDC_CONFIG_DESC_SIZE */

#define CDC_DATA_HS_IN_PACKET_SIZE                  CDC_DATA_HS_MAX_PACKET_SIZE
#define CDC_DATA_HS_OUT_PACKET_SIZE                 CDC_DATA_HS_MAX_PACKET_SIZE

#define CDC_DATA_FS_IN_PACKET_SIZE                  CDC_DATA_FS_MAX_PACKET_SIZE
#define CDC_DATA_FS_OUT_PACKET_SIZE                 CDC_DATA_FS_MAX_PACKET_SIZE

#define CDC_DATA_IN_TRANSFER_SIZE                   1U /* 1 bytes for RXREG response */
#define CDC_DATA_OUT_TRANSFER_SIZE                  2056U /* 2056 bytes for STX request */

/*  CDC definitions */
#define CDC_SEND_ENCAPSULATED_COMMAND               0x00U
#define CDC_GET_ENCAPSULATED_RESPONSE               0x01U
#define CDC_SET_COMM_FEATURE                        0x02U
#define CDC_GET_COMM_FEATURE                        0x03U
#define CDC_CLEAR_COMM_FEATURE                      0x04U
#define CDC_SET_LINE_CODING                         0x20U
#define CDC_GET_LINE_CODING                         0x21U
#define CDC_SET_CONTROL_LINE_STATE                  0x22U
#define CDC_SEND_BREAK                              0x23U

/* CDC buffer defines */
#define CDC_DESC_BUF_ADDR                           (USBD_BUF_START_ADDR)
#define CDC_CTRL_BUF_ADDR                           (CDC_DESC_BUF_ADDR + CDC_DESC_BUF_SIZE)
#define CDC_RX_BUF_ADDR                             (CDC_CTRL_BUF_ADDR + CDC_CTRL_BUF_SIZE) /* Length >= CDC_DATA_OUT_TRANSFER_SIZE */
#define CDC_TX_BUF_ADDR                             (CDC_RX_BUF_ADDR + CDC_DATA_OUT_TRANSFER_SIZE) /* Length >= CDC_DATA_IN_TRANSFER_SIZE */
#define CDC_BUF_TOTAL_SIZE                          (CDC_TX_BUF_ADDR + CDC_DATA_IN_TRANSFER_SIZE - USBD_BUF_START_ADDR)

/* Exported types ------------------------------------------------------------*/

typedef struct {
	u32 bitrate;
	u8  format;
	u8  paritytype;
	u8  datatype;
} USBD_CDC_LineCodingTypeDef;

typedef struct {
	USBD_SetupReqTypedef Request;
	__IO u32 TxState;
	__IO u32 RxState;
	u32 RxLength;
	u8 *RxBuffer;
	u8 *TxBuffer;
	u8 *CtrlBuffer;
	u8 *DescBuffer;
} USBD_CDC_HandleTypeDef;

typedef struct {
	u8(* Init)(void);
	u8(* DeInit)(void);
	u8(* Setup)(USBD_SetupReqTypedef *req, u8 *buf);
	u8(* Receive)(USBD_CDC_HandleTypeDef *hcdc);
} USBD_CDC_ItfTypeDef;

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
extern USBD_ClassTypeDef USBD_CDC_ClassCallback;
/* Exported functions --------------------------------------------------------*/
u8 USBD_CDC_Transmit(u8 *buf, u32 len);

#endif  /* __USBD_CDC_ROM_H */

