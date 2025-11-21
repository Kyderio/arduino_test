/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef USBD_PCD_H
#define USBD_PCD_H

/* Includes ------------------------------------------------------------------*/
#include "usbd_hal.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

int usbd_pcd_init(usb_dev_t *dev, usbd_config_t *config);
int usbd_pcd_deinit(usb_dev_t *dev);
int usbd_pcd_start(usbd_pcd_t *pcd);
int usbd_pcd_stop(usbd_pcd_t *pcd);
int usbd_pcd_dev_connected(usbd_pcd_t *pcd);
int usbd_pcd_dev_desconnected(usbd_pcd_t *pcd);
int usbd_pcd_set_address(usbd_pcd_t *pcd, u8 address);
int usbd_pcd_ep_init(usbd_pcd_t *pcd, usbd_ep_t *ep);
int usbd_pcd_ep_deinit(usbd_pcd_t *pcd, usbd_ep_t *ep);
int usbd_pcd_ep_receive(usbd_pcd_t *pcd, usbd_ep_t *ep);
int usbd_pcd_ep_transmit(usbd_pcd_t *pcd, usbd_ep_t *ep);
int usbd_pcd_ep_transmit_zlp(usbd_pcd_t *pcd, u8 ep_addr);
u32 usbd_pcd_ep_get_rx_data_size(usbd_pcd_t *pcd, u8 ep_addr);
int usbd_pcd_ep_set_stall(usbd_pcd_t *pcd, u8 ep_addr);
int usbd_pcd_ep_clear_stall(usbd_pcd_t *pcd, u8 ep_addr);
int usbd_pcd_ep_flush(usbd_pcd_t *pcd, u8 ep_addr);

#endif /* USBD_PCD_H */

