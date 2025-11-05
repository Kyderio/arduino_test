#ifndef BT_CONTROLLER_HAL_H
#define BT_CONTROLLER_HAL_H

#include <bt_controller_hal_mac_reg.h>
#include <bt_controller_hal_modem_reg.h>
#include <bt_controller_hal_phy.h>
#include <bt_controller_hal_mac.h>
#include <bt_controller_hal_le_adv.h>
#include <bt_controller_hal_le_conn.h>

struct bt_controller_hal_info {
	uint8_t mac_addr[BT_ADDR_SIZE];
};


void bt_controller_hal_init(void);
void bt_controller_hal_enable(void);
void bt_controller_hal_disable(void);
void bt_controller_hal_deinit(void);
uint8_t bt_controller_hal_get_isr_tx_status(void);
uint8_t bt_controller_hal_get_isr_rx_status(void);

#endif