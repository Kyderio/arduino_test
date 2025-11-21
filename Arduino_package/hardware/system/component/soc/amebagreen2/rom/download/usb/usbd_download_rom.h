/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_DOWNLOAD_ROM_H
#define __USBD_DOWNLOAD_ROM_H

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

int Download_USBD_Init(void);

int Download_USBD_DeInit(void);

int Download_USBD_IsAttached(void);

int Download_USBD_Process(void);

#endif /* __USBD_DOWNLOAD_ROM_H */

