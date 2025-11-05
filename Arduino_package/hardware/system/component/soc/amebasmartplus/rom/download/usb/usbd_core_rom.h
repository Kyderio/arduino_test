/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __USBD_CORE_ROM_H
#define __USBD_CORE_ROM_H

/* Includes ------------------------------------------------------------------*/

#include "usbd_hal_rom.h"
/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

HAL_Status USBD_Core_Init(USBD_ClassTypeDef *classcb, void *fops, USBD_SpeedTypeDef speed);
HAL_Status USBD_Core_DeInit(void);
HAL_Status USBD_SetupStage(USBD_HandleTypeDef *pdev, u8 *psetup);
HAL_Status USBD_DataOutStage(USBD_HandleTypeDef *pdev, u8 epnum, u8 *pdata);
HAL_Status USBD_DataInStage(USBD_HandleTypeDef *pdev, u8 epnum, u8 *pdata);
HAL_Status USBD_Reset(USBD_HandleTypeDef  *pdev);
HAL_Status USBD_SetSpeed(USBD_HandleTypeDef  *pdev, USBD_SpeedTypeDef speed);
HAL_Status USBD_Suspend(USBD_HandleTypeDef  *pdev);
HAL_Status USBD_Resume(USBD_HandleTypeDef  *pdev);
HAL_Status USBD_DevConnected(USBD_HandleTypeDef  *pdev);
HAL_Status USBD_DevDisconnected(USBD_HandleTypeDef  *pdev);
HAL_Status USBD_OpenEP(USBD_HandleTypeDef *pdev, u8  ep_addr, u8  ep_type, u16 ep_mps);
HAL_Status USBD_CloseEP(USBD_HandleTypeDef *pdev, u8 ep_addr);
HAL_Status USBD_Transmit(USBD_HandleTypeDef *pdev, u8  ep_addr, u8  *pbuf, u16  size);
HAL_Status USBD_PrepareReceive(USBD_HandleTypeDef *pdev, u8  ep_addr, u8  *pbuf, u16  size);
HAL_Status USBD_CtlSendData(USBD_HandleTypeDef *pdev, u8 *pbuf, u16 len);
HAL_Status USBD_CtlPrepareRx(USBD_HandleTypeDef  *pdev, u8 *pbuf, u16 len);
u32 USBD_GetRxDataSize(USBD_HandleTypeDef *pdev, u8  ep_addr);
void USBD_CtlError(USBD_HandleTypeDef  *pdev, USBD_SetupReqTypedef *req);
void USBD_GetString(u8 *desc, u8 *unicode, u16 *len);
void USBD_IRQHandler(void);

#endif /* __USBD_CORE_ROM_H */

