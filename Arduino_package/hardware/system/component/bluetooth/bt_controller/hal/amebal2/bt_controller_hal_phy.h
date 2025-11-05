#ifndef BT_CONTROLLER_HAL_PHY_H
#define BT_CONTROLLER_HAL_PHY_H

#define BT_MODEM_LE_ACC_CHK2_TH32              0xFEFFFFF5
#define BT_RF_SETTLING_TIME                    3

#define BT_MODEM_MDM_INI_0x00                  0x6F76
#define BT_MODEM_MDM_INI_0x01                  0x4115
#define BT_MODEM_MDM_INI_0x02                  0x94DB
#define BT_MODEM_MDM_INI_0x03                  0x309A
#define BT_MODEM_MDM_INI_0x04                  0x361F
#define BT_MODEM_MDM_INI_0x05                  0x00B0
#define BT_MODEM_MDM_INI_0x06                  0x4912
#define BT_MODEM_MDM_INI_0x07                  0x13F2
#define BT_MODEM_MDM_INI_0x08                  0x569E
#define BT_MODEM_MDM_INI_0x09                  0x0F48
#define BT_MODEM_MDM_INI_0x0A                  0x0000
#define BT_MODEM_MDM_INI_0x0B                  0x5A32
#define BT_MODEM_MDM_INI_0x0C                  0x690B
#define BT_MODEM_MDM_INI_0x16                  0x4400
#define BT_MODEM_MDM_INI_0x17                  0x0CC0
#define BT_MODEM_MDM_INI_0x19                  0x01D4
#define BT_MODEM_MDM_INI_0x1A                  0x0030
#define BT_MODEM_MDM_INI_0x1B                  0x0001
#define BT_MODEM_MDM_INI_0x1C                  0x034D
#define BT_MODEM_MDM_INI_0x1D                  0x2521
#define BT_MODEM_MDM_INI_0x1E                  0x0019

#define BT_MODEM_MDM_INI_0x30                  0x5693
#define BT_MODEM_MDM_INI_0x31                  0x0000
#define BT_MODEM_MDM_INI_0x32                  0x6F73
#define BT_MODEM_MDM_INI_0x33                  0x044F

#define BT_RF_LONG_READY_TIME_US                110
#define BT_RF_SHORT_READY_TIME_US               30
#define BT_RF_RX_WIN                            (BT_RF_SHORT_READY_TIME_US + 20)
#define BT_RF_RX_2_TX_READY_TIME_US             60
#define BT_RF_TX_2_RX_READY_TIME_US             30

#define BT_TRX_PATH_DELAY_TX_1M_US              5
#define BT_TRX_PATH_DELAY_RX_1M_US              10

struct bt_controller_modem_param {
	uint16_t addr;
	uint16_t mask;
	uint16_t data;
};

struct bt_controller_rf_param {
	uint8_t addr;
	uint16_t mask;
	uint16_t data;
};


void bt_controller_phy_init(void);
void bt_controller_phy_reset(void);

void bt_controller_write_modem_reg(uint16_t addr, uint16_t data);
uint16_t bt_controller_read_modem_reg(uint16_t addr);
void bt_controller_write_rf_reg(uint16_t addr, uint16_t data);
uint16_t bt_controller_read_rf_reg(uint16_t addr);

void bt_controller_phy_set_rf_settling_time(uint8_t time_us);

#endif