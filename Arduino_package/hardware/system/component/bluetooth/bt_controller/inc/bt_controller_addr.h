#ifndef BT_CONTROLLER_LL_ADDR_H
#define BT_CONTROLLER_LL_ADDR_H

#define BT_ADDR_LE_PUBLIC       0x00
#define BT_ADDR_LE_RANDOM       0x01

#define BT_ADDR_SIZE            6

struct bt_le_addr_t {
	uint8_t type;
	uint8_t addr[BT_ADDR_SIZE];
};


#endif