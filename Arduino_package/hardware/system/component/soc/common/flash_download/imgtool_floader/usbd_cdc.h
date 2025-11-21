/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __USBD_CDC_H
#define __USBD_CDC_H

/* Includes ------------------------------------------------------------------*/

#include "usbd_hal.h"

/* Exported defines ----------------------------------------------------------*/

/* CDC Endpoints parameters */
#ifdef CONFIG_AMEBAGREEN2
#define CDC_IN_EP                                   0x82U  /* EP2 for BULK IN */
#define CDC_OUT_EP                                  0x02U  /* EP2 for BULK OUT */
#define CDC_CMD_EP                                  0x84U  /* EP4 for INTR IN */
#elif defined(CONFIG_AMEBASMARTPLUS) || defined(CONFIG_AMEBAL2)
#define CDC_IN_EP                                   0x81U  /* EP1 for BULK IN */
#define CDC_OUT_EP                                  0x01U  /* EP1 for BULK OUT */
#define CDC_CMD_EP                                  0x82U  /* EP2 for INTR IN */
#else
#define CDC_IN_EP                                   0x81U  /* EP1 for BULK IN */
#define CDC_OUT_EP                                  0x02U  /* EP2 for BULK OUT */
#define CDC_CMD_EP                                  0x83U  /* EP3 for INTR IN */
#endif
#define CDC_HS_BINTERVAL                            0x10U
#define CDC_FS_BINTERVAL                            0x10U

#define CDC_DATA_HS_MAX_PACKET_SIZE                 512U  /* High speed BULK IN & OUT Packet size */
#define CDC_DATA_FS_MAX_PACKET_SIZE                 64U   /* Full speed BULK IN & OUT Packet size */
#define CDC_CMD_PACKET_SIZE                         8U    /* INTR IN Packet size */

#define USB_CDC_CONFIG_DESC_SIZ                     67U
#define CDC_DATA_HS_IN_PACKET_SIZE                  CDC_DATA_HS_MAX_PACKET_SIZE
#define CDC_DATA_HS_OUT_PACKET_SIZE                 CDC_DATA_HS_MAX_PACKET_SIZE

#define CDC_DATA_FS_IN_PACKET_SIZE                  CDC_DATA_FS_MAX_PACKET_SIZE
#define CDC_DATA_FS_OUT_PACKET_SIZE                 CDC_DATA_FS_MAX_PACKET_SIZE

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

/* Exported types ------------------------------------------------------------*/

typedef struct {
	u32 bitrate;
	u8  format;
	u8  paritytype;
	u8  datatype;
} USBD_CDC_LineCodingTypeDef;

typedef struct {
	u8  Data[CDC_DATA_HS_MAX_PACKET_SIZE];
	u8  CmdOpCode;
	u8  CmdLength;
	u8  *RxBuffer;
	u32 RxLength;

	__IO u32 TxState;
	__IO u32 RxState;
} USBD_CDC_HandleTypeDef;

typedef struct {
	u8(* Init)(USBD_CDC_HandleTypeDef *handle);
	u8(* DeInit)(void);
	u8(* Control)(u8 cmd, u8 *buf, u16 len);
	u8(* Receive)(u8 *buf, u32 len);

} USBD_CDC_ItfTypeDef;

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

extern USBD_ClassTypeDef USBD_CDC;
extern USBD_CDC_HandleTypeDef USBD_CDC_Handle;

/* Exported functions --------------------------------------------------------*/

u8  USBD_CDC_Transmit(u8 *buf, u32 len);

#endif  /* __USBD_CDC_H */

