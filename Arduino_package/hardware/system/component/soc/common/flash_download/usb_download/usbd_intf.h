/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_INTF_H
#define __USBD_INTF_H

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

int USBD_Init(void);

int USBD_DeInit(void);

int USBD_IsAttached(void);

int USBD_Process(void);


#endif /* __USBD_INTF_H */

