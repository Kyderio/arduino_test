#ifndef __ROM_WIFI_HAL_TXPOWER_H__
#define __ROM_WIFI_HAL_TXPOWER_H__

//====================================================
//	  EEPROM/Efuse PG Offset for 8721D
//====================================================
// 0x10 ~ 0x63 = TX power area.
#define EEPROM_TX_PWR_INX				0x20
#define EEPROM_TX_PWR_INX_5G			0x32
#define EEPROM_ChannelPlan				0XC8
#define EEPROM_XTAL					0xC9
#define EEPROM_THERMAL_METER				0xCA

#define EEPROM_IQK_LCK					0xCB
#define EEPROM_2G_5G_PA_TYPE				0xCC
#define EEPROM_2G_LNA_TYPE_GAIN_SEL			0xCD
#define EEPROM_5G_LNA_TYPE_GAIN_SEL			0xCE

#define EEPROM_RF_BOARD_OPTION				0x131

#define EEPROM_FEATURE_OPTION				0x132
#define EEPROM_RF_BT_SETTING				0x133

#define EEPROM_VERSION					0x134
#define EEPROM_CustomID					0x135

#define EEPROM_TX_BBSWING_2G				0x136
#define EEPROM_TX_PWR_CAL_RATE				0x138
#define EEPROM_RF_ANTENNA_OPT				0x139
#define EEPROM_RFE_OPTION				0x13A

#define EEPROM_MAC_ADDR					0x11A
#define EEPROM_TX_KFREE					0xEE
#define EEPROM_THERMAL_OFFSET	     		  	0xEF
#define EEPROM_PACKAGE_TYPE				0x1F8

//====================================================
//			EEPROM/Efuse Value Type
//====================================================
#define EETYPE_TX_PWR					0x0

//====================================================
//			EEPROM/Efuse Default Value
//====================================================
#define EEPROM_CID_DEFAULT				0x0
#define EEPROM_CID_DEFAULT_EXT				0xFF // Reserved for Realtek
#define EEPROM_CID_TOSHIBA				0x4
#define EEPROM_CID_CCX					0x10
#define EEPROM_CID_QMI					0x0D
#define EEPROM_CID_WHQL 				0xFE

#define EEPROM_CHANNEL_PLAN_FCC				0x0
#define EEPROM_CHANNEL_PLAN_IC				0x1
#define EEPROM_CHANNEL_PLAN_ETSI			0x2
#define EEPROM_CHANNEL_PLAN_SPAIN			0x3
#define EEPROM_CHANNEL_PLAN_FRANCE			0x4
#define EEPROM_CHANNEL_PLAN_MKK				0x5
#define EEPROM_CHANNEL_PLAN_MKK1			0x6
#define EEPROM_CHANNEL_PLAN_ISRAEL			0x7
#define EEPROM_CHANNEL_PLAN_TELEC			0x8
#define EEPROM_CHANNEL_PLAN_GLOBAL_DOMAIN		0x9
#define EEPROM_CHANNEL_PLAN_WORLD_WIDE_13		0xA
#define EEPROM_CHANNEL_PLAN_NCC_TAIWAN			0xB
#define EEPROM_CHANNEL_PLAN_CHIAN			0XC
#define EEPROM_CHANNEL_PLAN_SINGAPORE_INDIA_MEXICO	0XD
#define EEPROM_CHANNEL_PLAN_KOREA			0xE
#define EEPROM_CHANNEL_PLAN_TURKEY              	0xF
#define EEPROM_CHANNEL_PLAN_JAPAN                 	0x10
#define EEPROM_CHANNEL_PLAN_FCC_NO_DFS			0x11
#define EEPROM_CHANNEL_PLAN_JAPAN_NO_DFS		0x12
#define EEPROM_CHANNEL_PLAN_WORLD_WIDE_5G		0x13
#define EEPROM_CHANNEL_PLAN_TAIWAN_NO_DFS 		0x14

#define EEPROM_USB_OPTIONAL1				0xE

#define RTL_EEPROM_ID							0x8721

#define EEPROM_Default_TSSI				0x0
#define EEPROM_Default_BoardType			0x02
#define EEPROM_Default_ThermalMeter		0x1A

#define EEPROM_Default_CrystalCap			0x38
#define EEPROM_Default_CrystalFreq			0x0
#define EEPROM_Default_TxPowerLevel_2G			0x2C
#define EEPROM_Default_TxPowerLevel_5G			0x22
#define EEPROM_Default_TxPowerLevel			0x22
#define EEPROM_Default_HT40_2SDiff			0x0
#define EEPROM_Default_HT20_Diff			2
#define EEPROM_Default_LegacyHTTxPowerDiff		0x3
#define EEPROM_Default_HT40_PwrMaxOffset		0
#define EEPROM_Default_HT20_PwrMaxOffset		0

#define EEPROM_Default_PID				0x1234
#define EEPROM_Default_VID				0x5678
#define EEPROM_Default_CustomerID			0xAB
#define EEPROM_Default_SubCustomerID			0xCD
#define EEPROM_Default_Version				0

#define EEPROM_Default_PAType				0
#define EEPROM_Default_LNAType				0

//New EFUSE deafult value
#define EEPROM_DEFAULT_24G_INDEX	    		0x40
#define EEPROM_DEFAULT_24G_HT20_DIFF			0X00
#define EEPROM_DEFAULT_24G_OFDM_DIFF			0X02

#define EEPROM_DEFAULT_5G_INDEX				0X44
#define EEPROM_DEFAULT_5G_HT20_DIFF			0X00
#define EEPROM_DEFAULT_5G_OFDM_DIFF			0X04

#define EEPROM_DEFAULT_DIFF				0XFE
#define EEPROM_DEFAULT_CHANNEL_PLAN			0x7F
#define EEPROM_DEFAULT_BOARD_OPTION			0x01	// Enable power by rate and power limit
#define EEPROM_DEFAULT_RFE_OPTION			0x04
#define EEPROM_DEFAULT_FEATURE_OPTION			0x00
#define EEPROM_DEFAULT_BT_OPTION			0x10
#define EEPROM_DEFAULT_TX_CALIBRATE_RATE		0x00

#define EEPROM_DEFAULT_POWER_MODE			0x00

#endif
