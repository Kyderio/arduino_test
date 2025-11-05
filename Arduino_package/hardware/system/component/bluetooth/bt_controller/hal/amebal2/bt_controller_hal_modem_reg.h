#ifndef BT_CONTROLLER_HAL_MODEM_REG_H
#define BT_CONTROLLER_HAL_MODEM_REG_H

#define BT_CONTROLLER_MODEM_REG(page_idx, offset)     (((page_idx) << 6) | (offset))

//Page 0

//Page 1
#define BT_CONTROLLER_MODEM_REG_PAGE1_0x00                0x00
#define BT_CONTROLLER_MODEM_REG_PAGE1_0x01                0x01
#define BT_CONTROLLER_MODEM_REG_PAGE1_0x02                0x02
#define BT_CONTROLLER_MODEM_REG_PAGE1_0x1A                0x1A
#define BT_CONTROLLER_MODEM_REG_PAGE1_0x1B                0x1B
#define BT_CONTROLLER_MODEM_REG_PAGE1_0x18                0x18
#define BT_CONTROLLER_MODEM_REG_PAGE1_0x19                0x19

//Page 2
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x04                0x04
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x05                0x05
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x18                0x18
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x19                0x19
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x1A                0x1A
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x20                0x20
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x21                0x21
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x22                0x22
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x23                0x23
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x24                0x24
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x26                0x26
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x28                0x28
#define BT_CONTROLLER_MODEM_REG_PAGE2_0x30                0x30

struct bt_controller_modem_reg_page2_0x1a {
	uint16_t reg_bb_pw_time_bt4: 3;       //[2:0]
	uint16_t reg_bb_pw_time_bt2: 3;       //[5:3]
	uint16_t reg_bb_pw_time2_bt4: 3;      //[8:6]
	uint16_t reg_bb_pw_time2_bt2: 3;      //[11:9]
	uint16_t reg_agc_stop: 1;             //[12]
	uint16_t reg_share_lna_en: 1;         //[13]
	uint16_t reg_sharelna_adc_gat_en: 1;  //[14]
	uint16_t rsvd: 1;                     //[15]
};


union bt_modem_reg {
	uint16_t raw_data;
	struct bt_controller_modem_reg_page2_0x1a reg_page2_0x1a;

};


#endif

