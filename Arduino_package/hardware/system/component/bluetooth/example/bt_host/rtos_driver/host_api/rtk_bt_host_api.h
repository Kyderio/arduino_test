/*
 *******************************************************************************
 * Copyright(c) 2021, Realtek Semiconductor Corporation. All rights reserved.
 *******************************************************************************
 */

#ifndef _RTK_BT_HOST_API_H_
#define _RTK_BT_HOST_API_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/** Bluetooth HCI protocol type */
#define BT_HCI_PROTOCOL_NONE            0
#define BT_HCI_PROTOCOL_H4              0
#define BT_HCI_PROTOCOL_H5              0
#define BT_HCI_PROTOCOL_SPI             1
#define BT_HCI_PROTOCOL_SDIO            0
#define BT_HCI_PROTOCOL_USB             0

#if 0
#include <stdio.h>
#define HOST_LOG    printf
#define HOST_DUMP(_data, _len) \
    {   \
        int __idx;  \
        for (__idx = 0; __idx < _len; __idx++) {    \
            printf("%02x ", *(buf + __idx));    \
            if ((__idx + 1) % 16 == 0 || (__idx + 1) == _len) { \
                printf("\r\n"); \
            }   \
        }   \
    }
#else
#define HOST_LOG(...) {}
#define HOST_DUMP(_data, _len) {}
#endif

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

struct hci_transport_opts {
	/**
	 * @brief To enable HCI transport.
	 *
	 * Set this to NULL if HCI transport initialization is done outside host driver.
	 *
	 */
	void (*hci_init)(void);

	/**
	 * @brief To disable HCI transport.
	 *
	 * Set this to NULL if HCI transport deinitialization is done outside host driver.
	 *
	 */
	void (*hci_deinit)(void);

	/**
	 * @brief To send HCI packet to HCI transport.
	 *
	 * @param type HCI packet type.
	 * @param buf  HCI packet buf.
	 * @param len  HCI packet length.
	 *
	 * @return Length of buf actually sent.
	 */
	uint16_t (*hci_send)(uint8_t type, uint8_t *buf, uint16_t len);
};

struct hci_low_level_opts {
	/**
	 * @brief To enable low level interface except for usb (e.g. uart, sdio).
	 *
	 * Set this to NULL if low level interface initialization is done outside host driver.
	 *
	 */
	void (*init)(void);

	/**
	 * @brief To disable low level interface.
	 *
	 * Set this to NULL if low level interface deinitialization is done outside host driver.
	 *
	 */
	void (*deinit)(void);

	/**
	 * @brief To send data through low level interface.
	 *
	 * Host driver will reorganize content of HCI packets according to interface used (e.g. H4, H5, SDIO).
	 * Then host driver call this API to send reorganized data through low level interface.
	 *
	 * @param buf Data to send.
	 * @param len Length of data.
	 *
	 * @return Length of buf actually sent.
	 */
	uint16_t (*send)(uint8_t *buf, uint16_t len);
};

struct hci_spi_opts {
	/**
	 * @brief To initialize two GPIOs used for RX request and device state.
	 *
	 * Set RX request GPIO as input and register rising edge interrupt.
	 * In RX request GPIO interrupt handler, call API rtk_bt_spi_rx_req_rising_irq().
	 * Set device state GPIO as input and register rising edge interrupt.
	 * In device state interrupt handler, call API rtk_bt_spi_device_state_rising_irq().
	 *
	 */
	void (*gpio_init)(void);

	/**
	 * @brief To deinitialize GPIOs.
	 *
	 */
	void (*gpio_deinit)(void);

	/**
	 * @brief To read RX request GPIO value is high or low.
	 *
	 * @return True when GPIO value is high or false when GPIO value is low .
	 *
	 */
	bool (*gpio_read_rx_req)(void);

	/**
	 * @brief To read device state GPIO value is high or low.
	 *
	 * @return True when GPIO value is high or false when GPIO value is low .
	 *
	 */
	bool (*gpio_read_dev_state)(void);

	/**
	 * @brief To set packet length of every SPI packet and enable SPI interface.
	 *
	 * @param fixed_pkt_len Length of every SPI packet.
	 *
	 * Every SPI packet in both directions has fixed packet length.
	 * Please record this parameter, it would be used in 'send' and 'recv' callbacks.
	 *
	 */
	void (*init)(uint16_t fixed_pkt_len);

	/**
	 * @brief To disable SPI interface.
	 *
	 */
	void (*deinit)(void);

	/**
	 * @brief To send data through SPI interface.
	 *
	 * Then host driver call this API to send HCI packets through SPI interface.
	 * It is possible that SPI slave sends data while SPI master sending data to slave.
	 * Therefore, store data received from MISO to rxbuf if rxbuf is not NULL.
	 *
	 * @param txbuf Data to send.
	 * @param rxbuf Memory to store received data.
	 *
	 * @return Length of buf actually sent.
	 *
	 * @note Make sure that callback returns after data is actually sent and received.
	 */
	uint16_t (*send)(uint8_t *txbuf, uint8_t *rxbuf);

	/**
	 * @brief To trigger SPI to receive data from device.
	 *
	 * Then host driver call this API to trigger SPI to receive 'len' of bytes from device.
	 *
	 * @param buf Memory to store received data.
	 *
	 * @return Length of data actually received.
	 */
	uint16_t (*recv)(uint8_t *buf);
};

struct hci_usb_opts {
	/**
	 * @brief To enable USB interface.
	 *
	 * Set this to NULL if USB initialization is done outside host driver.
	 *
	 */
	void (*usb_init)(void);

	/**
	 * @brief To disable USB interface.
	 *
	 * Set this to NULL if USB deinitialization is done outside host driver.
	 *
	 */
	void (*usb_deinit)(void);

	/**
	 * @brief To send HCI packet through USB interface.
	 *
	 * Host driver call this API to send HCI packet through different endpoint according to type.
	 *
	 * @param ep   USB endpoint number.
	 * @param buf  HCI packet buf.
	 * @param len  HCI packet length.
	 *
	 * @return True on success or false on failure.
	 */
	bool (*usb_send)(uint8_t ep, uint8_t *buf, uint16_t len);
};

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
typedef void (*APP_RECV)(uint8_t type, uint8_t *buf, uint16_t len);

/**
 * @brief Register transport callbacks and enable bluetooth controller.
 *
 * This API will send vendor command to enable controller.
 * Make sure HCI transport is enabled when call this API, if HCI transport is controlled outside host driver.
 *
 * @param opts HCI transport operations.
 * @param recv Host driver notifies bluetooth stack data received.
 *
 * @return True on success or false on failure.
 */
bool rtk_bt_host_enable(struct hci_transport_opts *opts, APP_RECV recv);

/**
 * @brief Register transport callbacks and enable H4 parsing and bluetooth controller.
 *
 * This API will send vendor command to enable controller.
 * Make sure HCI transport is enabled when call this API, if uart is controlled outside host driver.
 *
 * @param opts Low level interface operations.
 * @param recv Host driver notifies bluetooth stack data received.
 *
 * @return True on success or false on failure.
 */
bool rtk_bt_host_enable_with_h4(struct hci_low_level_opts *opts, APP_RECV recv);

/**
 * @brief Register transport callbacks and enable H5 parsing and bluetooth controller.
 *
 * This API will send vendor command to enable controller.
 * Make sure HCI transport is enabled when call this API, if uart on/off is controlled outside host driver.
 *
 * @param opts Low level interface operations.
 * @param recv Host driver notifies bluetooth stack data received.
 *
 * @return True on success or false on failure.
 */
bool rtk_bt_host_enable_with_h5(struct hci_low_level_opts *opts, APP_RECV recv);

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
bool rtk_bt_host_enable_with_sdio(struct hci_low_level_opts *opts, APP_RECV recv);

/**
 * @brief Register transport callbacks and enable SPI content parsing and bluetooth controller.
 *
 * This API will send vendor command to enable controller.
 * Make sure HCI transport is enabled when call this API, if SPI on/off is controlled outside host driver.
 *
 * @param opts Low level interface operations.
 * @param recv Host driver notifies bluetooth stack data received.
 *
 * @return True on success or false on failure.
 */
bool rtk_bt_host_enable_with_spi(struct hci_spi_opts *opts, APP_RECV recv);

/**
 * @brief Register transport callbacks and enable SPI content parsing and bluetooth controller.
 *
 * This API will send vendor command to enable controller.
 * Make sure HCI transport is enabled when call this API, if SPI on/off is controlled outside host driver.
 *
 * @param opts Low level interface operations.
 * @param recv Host driver notifies bluetooth stack data received.
 *
 * @return True on success or false on failure.
 */
bool rtk_bt_host_enable_with_usb(struct hci_usb_opts *opts, APP_RECV recv);

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
 * @brief To notify bluetooth contoller that host is suspended.
 *
 * This API will send vendor command to inform controller.
 * If HCI interface is controlled outside this host driver, make sure this API is called when HCI interface enabled.
 */
void rtk_bt_host_suspend(void);

/**
 * @brief To notify bluetooth contoller that host is resumed.
 *
 * This API will send vendor command to inform controller.
 * If HCI interface is controlled outside this host driver, make sure this API is called when HCI interface enabled.
 */
void rtk_bt_host_resume(void);

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

/****************** Functions in spi_protocol.c ********************/
/**
 * @brief Device-state-GPIO rising interrupt handler for SPI interface.
 *
 * Call this function when device-state-GPIO rising edge arrives.
 *
 */
void rtk_bt_spi_device_state_rising_irq(void);

/**
 * @brief RX-req-GPIO rising interrupt handler for SPI interface.
 *
 * Call this function when RX-req-GPIO rising edge arrives.
 *
 */
void rtk_bt_spi_rx_req_rising_irq(void);
/*******************************************************************/
#endif /* _RTK_BT_HOST_API_H_ */