/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __USBH_CORE_H
#define __USBH_CORE_H

/* Includes ------------------------------------------------------------------*/

#include "usbh_hal.h"
#include "usbh.h"

/* Exported defines ----------------------------------------------------------*/

#define USBH_MPS_DEFAULT                        0x40U
#define USBH_CFG_DATA_BUFFER_MIN_LEN            2*(USBH_MPS_DEFAULT)

#define USBH_MAX_DATA_BUFFER					0x200U
#define USBH_MAX_ERROR_COUNT					0x02U
#define USBH_MSG_QUEUE_DEPTH					0x10U

#define USBH_ADDRESS_DEFAULT                    0x00U

#define USBH_TOKEN_SETUP                        0U
#define USBH_TOKEN_DATA                         1U

#define USBH_SETUP_PKT_SIZE                     8U

/*Standard Feature Selector for clear feature command*/
#define USBH_FEATURE_SELECTOR_ENDPOINT          0x00U
#define USBH_FEATURE_SELECTOR_DEVICE            0x01U
#define USBH_FEATURE_SELECTOR_REMOTEWAKEUP      0X01U

#define USBH_ENABLE_BOS_DESCRIPTOR              0U

/* Exported types ------------------------------------------------------------*/

/* USB descriptor header */
typedef struct {
	u8  bLength;										/* Descriptor length */
	u8  bDescriptorType;								/* Descriptor type */
} usbh_desc_header_t;

/* USB enumeration state */
typedef enum {
	USBH_ENUM_IDLE = 0U,
	USBH_ENUM_GET_FULL_DEV_DESC,
	USBH_ENUM_GET_ADDR,
	USBH_ENUM_SET_ADDR,
	USBH_ENUM_GET_CFG_DESC,
	USBH_ENUM_GET_FULL_CFG_DESC,
	USBH_ENUM_DEVICE_VALIDATE,
	USBH_ENUM_GET_MFC_STRING_DESC,
	USBH_ENUM_GET_PRODUCT_STRING_DESC,
	USBH_ENUM_GET_SERIALNUM_STRING_DESC,
#if USBH_ENABLE_BOS_DESCRIPTOR
	USBH_ENUM_GET_BOS_DESC,
	USBH_ENUM_GET_FULL_BOS_DESC,
#endif
} usbh_enum_state_t;

typedef enum {
	USBH_ENUM_HUB_IDLE = 0U,
	USBH_ENUM_GET_HUB_ADDR,
	USBH_ENUM_SET_HUB_ADDR,
	USBH_ENUM_GET_HUB_MFC_STRING_DESC,
	USBH_ENUM_GET_HUB_PRODUCT_STRING_DESC,
	USBH_ENUM_GET_HUB_SERIALNUM_STRING_DESC,

#if USBH_ENABLE_BOS_DESCRIPTOR
	USBH_ENUM_GET_HUB_BOS_DESC,
	USBH_ENUM_GET_HUB_FULL_BOS_DESC,
#endif

	USBH_ENUM_GET_HUB_CFG_DESC,
	USBH_ENUM_GET_HUB_FULL_CFG_DESC,
	USBH_ENUM_GET_HUB_SET_CFG_IDX,
	USBH_ENUM_SET_HUB_REMOTE_WAKEUP,
	USBH_ENUM_SET_HUB_ITF,
	USBH_ENUM_GET_HUB_DEV_STATUS,
	USBH_ENUM_GET_HUB_DESC,
	USBH_ENUM_SET_HUB_PORT_POWER_ON,
	USBH_ENUM_GET_HUB_PORT_POWER_STATUS,
	USBH_ENUM_GET_HUB_STATUS,
	USBH_ENUM_GET_HUB_PORT_CONNECT_EVENT,
	USBH_ENUM_CLEAR_HUB_PORT_CONNECT_STATUS,
	USBH_ENUM_HUB_STATUS_FINISH,

	USBH_ENUM_HUB_PORT_XFER,
	USBH_ENUM_GET_VALID_HUB_PORT,
	USBH_ENUM_SET_HUB_PORT_RESET,
	USBH_ENUM_SET_HUB_PORT_RESET_EVENT,
	USBH_ENUM_CLEAR_HUB_PORT_RESET_STATUS,
	USBH_ENUM_GET_HUB_PORT_STATUS,

	USBH_ENUM_HUB_SWITCH_TO_DEVICE,
} usbh_hub_enum_state_t;

/* USB control transfer state */
typedef enum {
	USBH_CTRL_IDLE = 0U,
	USBH_CTRL_SETUP,
	USBH_CTRL_SETUP_BUSY,
	USBH_CTRL_DATA_IN,
	USBH_CTRL_DATA_IN_BUSY,
	USBH_CTRL_DATA_OUT,
	USBH_CTRL_DATA_OUT_BUSY,
	USBH_CTRL_STATUS_IN,
	USBH_CTRL_STATUS_IN_BUSY,
	USBH_CTRL_STATUS_OUT,
	USBH_CTRL_STATUS_OUT_BUSY,
	USBH_CTRL_ERROR,
	USBH_CTRL_STALLED,
	USBH_CTRL_COMPLETE
} usbh_ctrl_transfer_state_t;

/* USB control request state */
typedef enum {
	USBH_CTRL_REQ_IDLE = 0U,
	USBH_CTRL_REQ_SEND,
	USBH_CTRL_REQ_BUSY
} usbh_ctrl_req_state_t;

/* USB event */
typedef enum {
	USBH_PORT_EVENT = 1U,
	USBH_URB_EVENT,
	USBH_CONTROL_EVENT,
	USBH_CLASS_EVENT,
	USBH_STATE_CHANGED_EVENT,
} usbh_event_t;

/* USB control request */
typedef struct {
	usbh_setup_req_t  *setup;							/* Setup request */
	u8                *buf;								/* Request buffer */
	u16               length;							/* Request length */
	usbh_ctrl_transfer_state_t state;					/* Control transfer state */
	u8                pipe_in;							/* In pipe */
	u8                pipe_out;							/* Out pipe */
	u8                pipe_size;						/* Pipe size */
	u8                error_cnt;						/* Error count, USBH_MSG_ERROR will be issued if USBH_MAX_ERROR_COUNT achieved */
} usbh_ctrl_req_t;

/* USB config descriptor struct*/
typedef struct {
	usbh_cfg_desc_t     cfg_desc;							/* Parsed configuration descriptor */
	u8                  *cfg_buf;							/* Raw data for configuration descriptor */
	u16                 cfg_buf_length;
} usbh_cfg_desc_array;

/*
	Support hub based on the following assumptions:
	1. only one hub at the top
	2. only one config descriptor for the hub
*/
typedef struct {
	u8                  hub_cfg_buf[USBH_MAX_DATA_BUFFER];		/* Raw data for configuration descriptor */
	usbh_dev_desc_t     hub_dev_desc;							/* hub device descriptor */
	usbh_dev_bos_t      hub_bos_desc;							/* hub bos descriptor */
	usbh_cfg_desc_t     hub_cfg_desc;							/* hub configuration descriptor */

	usbh_hub_desc_t     hub_desc;								/* hub descriptor */

	u32                 port_power_status; 						/* used to save all hub port power status */

	u16                 port_status;
	u16                 port_change;

	u8                  port_idx;								/* choose port idx 1,2,3.... 32 */
	u32                 port_connected;							/* hub port connected idx */
	u32                 port_connected_check;					/* hub port connected idx backup */

	u8                  hub_address;							/* hub address */
	u8                  hub_cfg_idx;							/* index for config desc, which config is used */
} usbh_hub_dev_t;

/* USB device */
typedef struct {
	usbh_dev_desc_t dev_desc;							/* Parsed device descriptor */
	usbh_dev_bos_t  bos_desc;							/* Bos descriptor */
	u8              *desc_buf;							/* Raw buffer for device descriptor */
	u8              *desc_string_buf;					/* Raw buffer for device string descriptor */
	usbh_cfg_desc_array *config_desc_array;				/* configuration descriptors */
	usbh_hub_dev_t  *hub_dev;

	u16             string_buf_length;					/* desc_string_buf length */
	u8              active_if;							/* Active device interface */
	u8              cfg_idx;							/* index for config_desc_array, which config is used */
	u8              cfg_count_max;						/* max count for config_desc */
	u8              dev_num;						/* default Address is 0, real addresses start with 1 */
	u8              address;							/* Device address */
	u8              speed;							/* Device speed 0~3*/
	__IO u8         is_connected;					/* Flag indicates whether device is connected 0~1 */
	__IO u8         port_enabled;					/* Flag indicates whether port is enabled 0~1 */
	__IO u8         hub_connected;					/* Flag indicates hub is connected 0~1 */
	__IO u8         hub_multi_port;					/* Flag indicates hub has more than 1 port */
} usbh_dev_t;

/* USB host */
typedef struct {
	/* Host parameters */
	u32                   pipes[USB_MAX_PIPES];			/* Pipes */
	usbh_dev_t            device;						/* Attached device */

	/* Host process routine parameters */
	usb_os_queue_t        msg_queue;					/* Host message queue */
	usb_os_task_t         main_task;					/* Host main task dealing with host message queue */
	usb_os_task_t         isr_task;						/* Host ISR task dealing with host interrupts */

	usbh_ctrl_req_t       ctrl_req;						/* Current control request */
	usb_host_t            *host;						/* Host handler */
	void                  *hcd;							/* HCD handler */

	/* State parameters */
	usbh_hub_enum_state_t hub_status;
	usbh_enum_state_t     enum_state;    				/* Enumeration state */
	usbh_ctrl_req_state_t ctrl_req_state;				/* Control request state */
} usbh_core_t;

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

int usbh_core_init(usb_host_t *host);
int usbh_core_deinit(usb_host_t *host);
int usbh_core_reenumerate(usb_host_t *host);

int usbh_core_alloc_pipe(usbh_core_t *core, u8 ep_addr);
int usbh_core_free_pipe(usbh_core_t *core, u8 pipe_num);
int usbh_core_open_pipe(usbh_core_t *core, u8 pipe_num, u8 ep_num, u8 ep_type, u16 mps, u8 dev_addr);
int usbh_core_close_pipe(usbh_core_t *core, u8 pipe_num);
u8 usbh_core_get_eptype(usbh_core_t *core, u8 pipe_num);
int usbh_core_reactivate_pipe(usbh_core_t *core, u8 pipe_num);

int usbh_core_set_toggle(usbh_core_t *core, u8 pipe_num, u8 toggle);
u8 usbh_core_get_toggle(usbh_core_t *core, u8 pipe_num);

int usbh_core_ctrl_set_interface(usbh_core_t *core, u8 if_num, u8 if_alt);
int usbh_core_ctrl_set_feature(usbh_core_t *core, u8 value);
int usbh_core_ctrl_clear_feature(usbh_core_t *core, u8 ep_num);
int usbh_core_ctrl_request(usbh_core_t *core, usbh_setup_req_t *req, u8 *buf);

int usbh_core_bulk_send_data(usbh_core_t *core, u8 *buf, u16 len, u8 pipe_num);
int usbh_core_bulk_receive_data(usbh_core_t *core, u8 *buf, u16 len, u8 pipe_num);
int usbh_core_intr_receive_data(usbh_core_t *core, u8 *buf, u16 len, u8 pipe_num);
int usbh_core_intr_send_data(usbh_core_t *core, u8 *buf, u16 len, u8 pipe_num);
int usbh_core_isoc_receive_data(usbh_core_t *core, u8 *buf, u16 len, u8 pipe_num);
int usbh_core_isoc_send_data(usbh_core_t *core, u8 *buf, u16 len, u8 pipe_num);

void usbh_core_notify_host_state_change(usbh_core_t *core);
void usbh_core_notify_port_state_change(usbh_core_t *core);
void usbh_core_notify_class_state_change(usbh_core_t *core, u32 param);
int usbh_core_notify_urb_state_change(usbh_core_t *core, u32 param);

usbh_urb_state_t usbh_core_get_urb_state(usbh_core_t *core, u8 pipe_num);
u8 usbh_core_get_active_class(usbh_core_t *core);
u8 usbh_core_get_cfgid_from_subclass(usbh_core_t *core, u8 subclass);
int usbh_core_set_configuration(usbh_core_t *core, u8 cfg_id);
u8 usbh_core_get_interface(usbh_core_t *core, u8 class_code, u8 sub_class_code, u8 protocol);
int usbh_core_set_interface(usbh_core_t *core, u8 if_num);
usbh_if_desc_t *usbh_core_get_interface_descriptor(usbh_core_t *core, u8 if_num, u8 alt_num);

void usbh_core_disable_port(usbh_core_t *core);
void usbh_core_enable_port(usbh_core_t *core);
int usbh_core_is_port_enabled(usbh_core_t *core);

int usbh_core_connect(usbh_core_t *core);
int usbh_core_disconnect(usbh_core_t *core);

u32 usbh_core_get_time_tick(void);

#endif /* __USBD_CORE_H */

