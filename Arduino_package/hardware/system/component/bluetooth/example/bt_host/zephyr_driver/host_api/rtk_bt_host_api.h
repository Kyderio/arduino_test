/*
 *******************************************************************************
 * Copyright(c) 2021, Realtek Semiconductor Corporation. All rights reserved.
 *******************************************************************************
 */

#ifndef _rtk_BT_HOST_API_H_
#define _rtk_BT_HOST_API_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <zephyr/init.h>
#include <zephyr/drivers/bluetooth.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/device.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/bluetooth/hci_types.h>
#include <soc.h>

#include "whc_bridge_sdio_host.h"

/** Bluetooth HCI protocol type */
#define BT_HCI_PROTOCOL_NONE            0
#define BT_HCI_PROTOCOL_H4              0
#define BT_HCI_PROTOCOL_H5              0
#define BT_HCI_PROTOCOL_SPI             0
#define BT_HCI_PROTOCOL_SDIO            1
#define BT_HCI_PROTOCOL_USB             0

struct INIC_TX_DESC {
	/* u4Byte 0 */
	uint32_t    txpktsize: 16;      // bit[15:0]
	uint32_t    offset: 8;              // bit[23:16], store the sizeof(struct INIC_TX_DESC)
	uint32_t    bus_agg_num: 8;     // bit[31:24], the bus aggregation number

	/* u4Byte 1 */
	uint32_t type: 8;               // bit[7:0], the packet type
	uint32_t data: 8;               // bit[8:15], the value to be written to the memory
	uint32_t reply: 1;              // bit[16], request to send a reply message
	uint32_t rsvd0: 15;

	/* u4Byte 2 */
	uint32_t    start_addr;         // 1) memory write/read start address 2) RAM start_function address

	/* u4Byte 3 */
	uint32_t data_len: 16;          // bit[15:0], the length to write/read
	uint32_t rsvd2: 16;         // bit[31:16]
};

/**
  * @brief  INIC RX DESC structure definition
  * @note: Ameba1 is 6 dword, but AmebaZ is 4 dwords
  */
struct INIC_RX_DESC {
	/* u4Byte 0 */
	uint32_t    pkt_len: 16;            // bit[15:0], the packet size
	uint32_t    offset: 8;          // bit[23:16], the offset from the packet start to the buf start, also means the size of RX Desc
	uint32_t    rsvd0: 6;               // bit[29:24]
	uint32_t    icv: 1;             //icv error
	uint32_t    crc: 1;             // crc error

	/* u4Byte 1 */
	/************************************************/
	/*****************receive packet type*********************/
	/*  0x82:   802.3 packet                              */
	/*  0x80:   802.11 packet                             */
	/*  0x10:   C2H command                       */
	/*  0x50:   Memory Read                           */
	/*  0x52:   Memory Write                              */
	/*  0x54:   Memory Set                            */
	/*  0x60:   Indicate the firmware is started              */
	uint32_t    type: 8;                // bit[7:0], the type of this packet
	uint32_t    rsvd1: 24;          // bit[31:8]

	/* u4Byte 2 */
	uint32_t    start_addr;

	/* u4Byte 3 */
	uint32_t data_len: 16;          // bit[15:0], the type of this packet
	uint32_t result: 8;             // bit[23:16], the result of memory write command
	uint32_t rsvd2: 8;              // bit[31:24]
};

#define SIZE_RX_DESC    (sizeof(struct INIC_RX_DESC))
#define SIZE_TX_DESC    (sizeof(struct INIC_TX_DESC))

/** Bluetooth HCI packet type */
typedef enum {
	/** ACK, only valid when interface is 3-wire uart */
	HCI_3WIRE_ACK = 0x00,
	/** HCI command */
	HCI_CMD = 0x01,
	/** ACL data */
	HCI_ACL = 0x02,
	/** SCO data */
	HCI_SCO = 0x03,
	/** HCI event */
	HCI_EVT = 0x04,
	/** ISO data */
	HCI_ISO  = 0x05,
	/** Link, only valid when interface is 3-wire uart */
	HCI_3WIRE_LINK = 0x0f,
} T_HCI_PACKET_TYPE;

/**
 * @brief To notify bluetooth stack that packet is received from controller.
 *
 * This callback notifies that a HCI packet is received from controller.
 * This could be set to the receive API of bluetooth stack.
 * Packet buffer is only valid during this callback, it will be freed when callback finishes.
 *
 * @param type HCI packet type.
 * @param buf  HCI packet buffer. It will be freed when callback finishes.
 * @param len  HCI packet buffer length.
 */
typedef void (*APP_RECV)(uint8_t packetType, uint8_t *data, uint16_t len);

/**
 * @brief Register transport callbacks and enable SDIO content parsing and bluetooth controller.
 *
 * This API will send vendor command to enable controller.
 * Make sure HCI transport is enabled when call this API, if SDIO on/off is controlled outside host driver.
 *
 * @param opts SDIO interface operations.
 * @param recv Host driver notifies bluetooth stack data received.
 *
 * @return True on success or false on failure.
 */
bool rtk_bt_host_enable_with_sdio(APP_RECV recv);

/**
 * @brief Disable bluetooth controller.
 *
 * This API will send vendor command to disable controller.
 * If HCI interface is controlled outside this host driver, make sure this API is called when HCI interface enabled.
 */
void rtk_bt_host_disable(void);

/**
 * @brief Check if bluetooth controller is enabled.
 *
 * @return True on enabled or false on disabled.
 */
bool rtk_bt_host_is_dev_enabled(void);

/**
 * @brief To send HCI packet to controller.
 *
 * @param type HCI packet type.
 * @param buf  HCI packet buffer.
 * @param len  HCI packet buffer length.
 *
 * @return Actual data length sent to controller.
 */
uint16_t rtk_bt_host_send(uint8_t type, uint8_t *buf, uint16_t len);

/**
 * @brief HCI transport receives packet from controller and notifies host driver.
 *
 * @param type HCI packet type.
 * @param buf  HCI packet buffer.
 * @param len  HCI packet buffer length.
 */
void rtk_bt_host_recv(uint8_t type, uint8_t *buf, uint16_t len);

/**
 * @brief Low level interface notifies host driver that data is received.
 *
 * Host driver will parse raw data to HCI packet according to protocol used (e.g. H4, H5, SDIO, SPI).
 *
 * @param buf Data received from low level interface.
 * @param len Length of data received.
 */
void rtk_bt_host_recv_raw(uint8_t *buf, uint16_t len);

/*******************************************************************/
#endif /* _rtk_BT_HOST_API_H_ */