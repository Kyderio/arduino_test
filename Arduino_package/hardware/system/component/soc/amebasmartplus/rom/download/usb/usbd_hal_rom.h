/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef USBD_HAL_ROM_H
#define USBD_HAL_ROM_H

/* Includes ------------------------------------------------------------------*/

#include "ameba_soc.h"
#include "usbd_def_rom.h"
#include "usbd_regs_rom.h"
#include "usbd_dbg_rom.h"

/* Exported defines ----------------------------------------------------------*/

/* USB section configurations */
#define USBD_DATA_SECTION                      HAL_ROM_DATA_SECTION
#define USBD_BSS_SECTION                       HAL_ROM_BSS_SECTION_BANK
#define USBD_TEXT_SECTION                      HAL_ROM_TEXT_SECTION
#define USBD_WEEK                              __weak

/* USB buffer configurations */
#define USBD_BUF_START_ADDR                    (MSP_RAM_HP_NS + 4 - 16 * 1024)

/* USB Core SW configurations */
#define USBD_MAX_NUM_INTERFACES                1U
#define USBD_MAX_NUM_CONFIGURATION             1U
#define USBD_MAX_ENDPOINTS                     4U

/* USB Core ID */
#define USB_OTG_CORE_ID_300A                   0x4F54300AU
#define USB_OTG_CORE_ID_310A                   0x4F54310AU
#define USB_OTG_CORE_ID_420A                   0x4F54420AU

/* USB Core Mode */
#define USB_OTG_MODE_DEVICE                    0U
#define USB_OTG_MODE_HOST                      1U
#define USB_OTG_MODE_DRD                       2U

/* USB Core Speed */
#define USB_OTG_SPEED_HIGH                     0U
#define USB_OTG_SPEED_HIGH_IN_FULL             1U
#define USB_OTG_SPEED_FULL                     3U

/* USB Core Turnaround Timeout Value */
#define USBD_UTMI_16_BIT_TRDT_VALUE            5U
#define USBD_UTMI_8_BIT_TRDT_VALUE             9U

/* USB Core MPS */
#define USB_OTG_HS_MAX_PACKET_SIZE             512U
#define USB_OTG_FS_MAX_PACKET_SIZE             64U
#define USB_OTG_MAX_EP0_SIZE                   64U

/* USB Core PHY Frequency */
#define DSTS_ENUMSPD_HS_PHY_30MHZ_OR_60MHZ     (0U << 1)
#define DSTS_ENUMSPD_FS_PHY_30MHZ_OR_60MHZ     (1U << 1)
#define DSTS_ENUMSPD_LS_PHY_6MHZ               (2U << 1)
#define DSTS_ENUMSPD_FS_PHY_48MHZ              (3U << 1)

/* USB Core Frame Interval */
#define DCFG_FRAME_INTERVAL_80                 0U
#define DCFG_FRAME_INTERVAL_85                 1U
#define DCFG_FRAME_INTERVAL_90                 2U
#define DCFG_FRAME_INTERVAL_95                 3U

/* USB Core EP0 MPS */
#define DEP0CTL_MPS_64                         0U
#define DEP0CTL_MPS_32                         1U
#define DEP0CTL_MPS_16                         2U
#define DEP0CTL_MPS_8                          3U

/* USB EP Speed */
#define EP_SPEED_LOW                           0U
#define EP_SPEED_FULL                          1U
#define EP_SPEED_HIGH                          2U

/* USB EP Type */
#define EP_TYPE_CTRL                           0U
#define EP_TYPE_ISOC                           1U
#define EP_TYPE_BULK                           2U
#define EP_TYPE_INTR                           3U
#define EP_TYPE_MSK                            3U

/* USB EP Address Mask */
#define EP_ADDR_MSK                            0xFU

/* USB STS Defines */
#define STS_GOUT_NAK                           1U
#define STS_DATA_UPDT                          2U
#define STS_XFER_COMP                          3U
#define STS_SETUP_COMP                         4U
#define STS_SETUP_UPDT                         6U

#define GRXSTS_PKTSTS_IN                       2U
#define GRXSTS_PKTSTS_IN_XFER_COMP             3U
#define GRXSTS_PKTSTS_DATA_TOGGLE_ERR          5U
#define GRXSTS_PKTSTS_CH_HALTED                7U

/* Exported types ------------------------------------------------------------*/
/* USB endpoint structure */
typedef struct {
	u32 xfer_len;             /*!< Current transfer length                                                  */
	u32 xfer_count;           /*!< Partial transfer length in case of multi packet transfer                 */
	u8  *xfer_buff;           /*!< Pointer to transfer buffer                                               */
	u16 maxpacket;            /*!< Endpoint Max packet size
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 64KB */
	u8  num;                  /*!< Endpoint number
                                       This parameter must be a number between Min_Data = 1 and Max_Data = 15   */
	u8  type;                 /*!< Endpoint type
                                       This parameter can be any value of @ref USB_EP_Type_                     */
	u8 tx_fifo_num;          /*!< Transmission FIFO number
                                       This parameter must be a number between Min_Data = 1 and Max_Data = 15   */
	u8  is_zlp : 1;               /*!< ZLP packet */
	u8  is_in : 1;                /*!< Endpoint direction
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 1    */
	u8  is_stall : 1;             /*!< Endpoint stall condition
                                       This parameter must be a number between Min_Data = 0 and Max_Data = 1    */
} USB_EPTypeDef;

/* PCD state */
typedef enum {
	HAL_PCD_STATE_RESET   = 0x00,
	HAL_PCD_STATE_READY   = 0x01,
	HAL_PCD_STATE_ERROR   = 0x02,
	HAL_PCD_STATE_BUSY    = 0x03,
	HAL_PCD_STATE_TIMEOUT = 0x04
} USB_PCD_StateTypeDef;

/* PCD handle structure */
typedef struct {
	/*!< IN endpoint parameters */
	USB_EPTypeDef IN_ep[USBD_MAX_ENDPOINTS];
	/*!< OUT endpoint parameters */
	USB_EPTypeDef OUT_ep[USBD_MAX_ENDPOINTS];
	/*!< PCD communication state */
	__IO USB_PCD_StateTypeDef State;
	/*!< Setup packet buffer */
	u32 Setup[12];
	/*!< Pointer to upper stack Handler */
	void *pData;
	/*!< PHY initialized */
	u8 PHY_Initialized : 1;
	/*!< ISR installed */
	u8 ISR_Installed : 1;
} USB_PCD_HandleTypeDef;

/* USB device speed */
typedef enum {
	USBD_SPEED_HIGH  = 0U,
	USBD_SPEED_FULL  = 1U,
	USBD_SPEED_LOW   = 2U,
} USBD_SpeedTypeDef;

struct _USBD_HandleTypeDef;

/* USB class structure */
typedef struct {
	void(*EarlyInit)(struct _USBD_HandleTypeDef *pdev);
	u8(*Init)(struct _USBD_HandleTypeDef *pdev);
	u8(*DeInit)(struct _USBD_HandleTypeDef *pdev);
	/* Control Endpoints*/
	u8(*Setup)(struct _USBD_HandleTypeDef *pdev, USBD_SetupReqTypedef *req);
	u8(*EP0_TxSent)(struct _USBD_HandleTypeDef *pdev);
	u8(*EP0_RxReady)(struct _USBD_HandleTypeDef *pdev);
	/* Class Specific Endpoints*/
	u8(*DataIn)(struct _USBD_HandleTypeDef *pdev, u8 epnum);
	u8(*DataOut)(struct _USBD_HandleTypeDef *pdev, u8 epnum);
	u8(*SOF)(struct _USBD_HandleTypeDef *pdev);

	u8 *(*GetDeviceDescriptor)(struct _USBD_HandleTypeDef *pdev, u16 *length);
	u8 *(*GetLangIDStrDescriptor)(struct _USBD_HandleTypeDef *pdev, u16 *length);
	u8 *(*GetManufacturerStrDescriptor)(struct _USBD_HandleTypeDef *pdev, u16 *length);
	u8 *(*GetProductStrDescriptor)(struct _USBD_HandleTypeDef *pdev, u16 *length);
	u8 *(*GetSerialStrDescriptor)(struct _USBD_HandleTypeDef *pdev, u16 *length);
	u8 *(*GetInterfaceStrDescriptor)(struct _USBD_HandleTypeDef *pdev, u16 *length);
	u8 *(*GetConfigDescriptor)(struct _USBD_HandleTypeDef *pdev, u16 *length);
	u8 *(*GetOtherSpeedConfigDescriptor)(struct _USBD_HandleTypeDef *pdev, u16 *length);
	u8 *(*GetDeviceQualifierDescriptor)(struct _USBD_HandleTypeDef *pdev, u16 *length);
} USBD_ClassTypeDef;

/* USB device handle structure */
typedef struct {
	u32 status;
	u32 total_length;
	u32 rem_length;
	u16 maxpacket;
	u8 is_used;
} USBD_EndpointTypeDef;

/* USB device handle structure */
typedef struct _USBD_HandleTypeDef {
	USBD_SpeedTypeDef       dev_speed;
	USBD_EndpointTypeDef    ep_in[USBD_MAX_ENDPOINTS];
	USBD_EndpointTypeDef    ep_out[USBD_MAX_ENDPOINTS];
	USBD_SetupReqTypedef    request;
	USBD_ClassTypeDef       *pClass;
	void                    *pClassData;
	void                    *pUserData;
	void                    *pData;
	u32 dev_config_status;
	u32 ep0_data_len;
	u8 dev_config;
	u8 dev_default_config;
	u8 dev_state;
	u8 dev_old_state;
	u8 dev_address;
	u8 dev_remote_wakeup;
	u8 dev_remote_wakeup_en;
	u8 dev_self_powered;
	u8 ep0_state;
} USBD_HandleTypeDef;

/* Unaligned 32 bit type for DFIFO usage */
typedef struct {
	u32 data __PACKED;
} USB_Unaligned32TypeDef;

/* Exported macros -----------------------------------------------------------*/

/* USB registers */
#define USB_GLOBAL     ((USB_OTG_GlobalTypeDef *)(USB_OTG_REG_BASE))
#define USB_PCGCCTL    *(__IO u32 *)(USB_OTG_REG_BASE + USB_OTG_PCGCCTL_BASE)
#define USB_DEVICE     ((USB_OTG_DeviceTypeDef *)(USB_OTG_REG_BASE + USB_OTG_DEVICE_BASE))
#define USB_INEP(i)    ((USB_OTG_INEndpointTypeDef *)(USB_OTG_REG_BASE + USB_OTG_IN_ENDPOINT_BASE + ((i) * USB_OTG_EP_REG_SIZE)))
#define USB_OUTEP(i)   ((USB_OTG_OUTEndpointTypeDef *)(USB_OTG_REG_BASE + USB_OTG_OUT_ENDPOINT_BASE + ((i) * USB_OTG_EP_REG_SIZE)))
#define USB_DFIFO(i)   *(__IO u32 *)(USB_OTG_REG_BASE + USB_OTG_FIFO_BASE + ((i) * USB_OTG_FIFO_SIZE))

/* Delay macros */
#define USB_DELAY_MS				DelayMs
#define USB_DELAY_US				DelayUs

/* Register access macros */
#define USB_READ32(addr)           (HAL_READ32(0, (addr)))
#define USB_WRITE32(addr, value)   (HAL_WRITE32(0, (addr), (value)))

#ifndef SWAPBYTE
#define  SWAPBYTE(addr)        (((u16)(*((u8 *)(addr)))) + \
								   (((u16)(*(((u8 *)(addr)) + 1U))) << 8U))
#endif

#ifndef LOBYTE
#define LOBYTE(x)  ((u8)(x & 0x00FFU))
#endif

#ifndef HIBYTE
#define HIBYTE(x)  ((u8)((x & 0xFF00U) >> 8U))
#endif

/* Exported variables --------------------------------------------------------*/

extern USBD_HandleTypeDef USBD_Device;

/* Exported functions --------------------------------------------------------*/

HAL_Status USB_HalInit(USB_PCD_HandleTypeDef *hpcd);
HAL_Status USB_DevInit(USB_PCD_HandleTypeDef *hpcd);
HAL_Status USB_EnableGlobalInt(void);
HAL_Status USB_DisableGlobalInt(void);
HAL_Status USB_SetTurnaroundTime(USB_PCD_HandleTypeDef *hpcd);
HAL_Status USB_SetDeviceMode(USB_PCD_HandleTypeDef *hpcd);
HAL_Status USB_SetDevSpeed(USB_PCD_HandleTypeDef *hpcd, u8 speed);
HAL_Status USB_FlushRxFifo(USB_PCD_HandleTypeDef *hpcd);
HAL_Status USB_FlushTxFifo(USB_PCD_HandleTypeDef *hpcd, u32 num);
HAL_Status USB_ActivateEndpoint(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
HAL_Status USB_DeactivateEndpoint(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
HAL_Status USB_EPStartXfer(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
HAL_Status USB_EP0StartXfer(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
HAL_Status USB_WritePacket(USB_PCD_HandleTypeDef *hpcd, u8 *src, u8 ch_ep_num, u16 len);
void *USB_ReadPacket(USB_PCD_HandleTypeDef *hpcd, u8 *dest, u16 len);
HAL_Status USB_EPSetStall(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
HAL_Status USB_EPClearStall(USB_PCD_HandleTypeDef *hpcd, USB_EPTypeDef *ep);
HAL_Status USB_SetDevAddress(USB_PCD_HandleTypeDef *hpcd, u8 address);
HAL_Status USB_DevConnect(USB_PCD_HandleTypeDef *hpcd);
HAL_Status USB_DevDisconnect(USB_PCD_HandleTypeDef *hpcd);
HAL_Status USB_StopDevice(USB_PCD_HandleTypeDef *hpcd);
HAL_Status USB_ActivateSetup(USB_PCD_HandleTypeDef *hpcd);
HAL_Status USB_EP0_OutStart(USB_PCD_HandleTypeDef *hpcd);
u8 USB_GetDevSpeed(USB_PCD_HandleTypeDef *hpcd);
u32 USB_GetMode(USB_PCD_HandleTypeDef *hpcd);
u32 USB_ReadInterrupts(void);
u32 USB_ReadDevAllOutEpInterrupt(USB_PCD_HandleTypeDef *hpcd);
u32 USB_ReadDevOutEPInterrupt(USB_PCD_HandleTypeDef *hpcd, u8 epnum);
u32 USB_ReadDevAllInEpInterrupt(USB_PCD_HandleTypeDef *hpcd);
u32 USB_ReadDevInEPInterrupt(USB_PCD_HandleTypeDef *hpcd, u8 epnum);
void USB_ClearInterrupts(USB_PCD_HandleTypeDef *hpcd, u32 interrupt);
u8 USB_GetTxFifoNum(USB_EPTypeDef *ep);
#endif /* USBD_HAL_ROM_H */

