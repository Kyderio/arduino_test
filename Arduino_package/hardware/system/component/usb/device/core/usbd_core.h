/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __USBD_CORE_H
#define __USBD_CORE_H

/* Includes ------------------------------------------------------------------*/

#include "usbd_hal.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

static inline u8 usbd_core_ep0_get_state(usb_dev_t *dev)
{
	return dev->ep0_state;
}

static inline u8 usbd_core_ep0_get_old_state(usb_dev_t *dev)
{
	return dev->ep0_old_state;
}

static inline void usbd_core_ep0_set_state(usb_dev_t *dev, u8 ep0_state)
{
	dev->ep0_old_state = dev->ep0_state;
	dev->ep0_state = ep0_state;
}

int usbd_core_setup_stage(usb_dev_t *dev, u8 *setup);
int usbd_core_data_out_stage(usb_dev_t *dev, u8 ep_num, u8 *buf);
int usbd_core_data_in_stage(usb_dev_t *dev, u8 ep_num, u8 *buf, u8 status);
int usbd_core_reset(usb_dev_t  *dev);
int usbd_core_set_speed(usb_dev_t  *dev, usb_speed_type_t speed);
int usbd_core_suspend(usb_dev_t  *dev);
int usbd_core_resume(usb_dev_t  *dev);
int usbd_core_sof(usb_dev_t  *dev);
int usbd_core_connected(usb_dev_t  *dev);
int usbd_core_disconnected(usb_dev_t  *dev);
int usbd_core_ep_set_stall(usb_dev_t *dev, u8 ep_addr);
int usbd_core_ep_clear_stall(usb_dev_t *dev, u8 ep_addr);
int usbd_core_ep_is_stall(usb_dev_t *dev, u8 ep_addr);;
u32 usbd_core_get_rx_data_size(usb_dev_t *dev, u8 ep_addr);
int usbd_core_ep_transmit(usb_dev_t *dev, usbd_ep_t *ep);
int usbd_core_ep_receive(usb_dev_t *dev, usbd_ep_t *ep);
int usbd_core_ep0_transmit(usb_dev_t *dev, usbd_ep_t *ep);
int usbd_core_ep0_receive(usb_dev_t *dev, usbd_ep_t *ep);
int usbd_core_ep0_transmit_status(usb_dev_t *dev);
int usbd_core_ep0_receive_status(usb_dev_t *dev);
int usbd_core_ep0_set_stall(usb_dev_t *dev);

#if USBD_ISR_TASK_TIME_DEBUG
int usbd_core_isr_trigger_time(usb_dev_t *dev, u32 cut_time);
int usbd_core_isr_cost_time(usb_dev_t *dev, u32 start_time, u32 end_time);
#endif

#endif /* __USBD_CORE_H */

