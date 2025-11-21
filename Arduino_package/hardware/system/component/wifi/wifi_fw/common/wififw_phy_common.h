#ifndef __WIFIFW_PHY_H__
#define __WIFIFW_PHY_H__

#define	DIG_MAX_LPS			0x3e
#define	DIG_MIN_LPS			0x20

#define	RSSI_TABLE_SIZE			4
#define	RSSI_DIFF_THRESHOLD			30

#define RFREG_MASK		0xfffff

#define TYPE_AGC_REG 			0
#define TYPE_PHY_REG 			1
#define TYPE_AFE_REG 			2
#define TYPE_PG_REG	 			3
#define TYPE_AFE_FOR_RFK_REG  	4

#define DONT_CARE		0xff
#define IF				0x8
#define ELSE_IF			0x9
#define ELSE			0xa
#define END				0xb
#define CHK				0x4

struct RSSI_PARM {
	u8		abs_rssi_temp[RSSI_TABLE_SIZE];
	u8		abs_rssi_average;
	u16		abs_rssi_sum;
} ;

/*------------------------------Function declaration--------------------------*/
extern void wififw_phy_rssi_average(u8 abs_rssi);
extern void wififw_phy_dig_by_bcn_rssi(u16 phystsofst);
extern void wififw_h2c_get_phy_reg_addr(struct h2c_phy_reg_addr *pbuf);
extern void wififw_h2c_get_afe_reg_addr(struct h2c_afe_reg_addr *pbuf);
extern void wififw_hioe_phy_reg_init(u8 reg_type);
extern u32 wififw_phy_bitmask_shift(u32 bit_mask);
extern u32 wififw_phy_read_bb_reg(u32 addr, u32 mask);
extern void wififw_phy_write_bb_reg(u32 addr, u32 mask, u32 val);
extern u32 wififw_phy_get_bb_reg(u32 addr, u32 mask, u32 val);
extern u32 wififw_phy_read_rf_reg(u32 reg_addr, u32 bit_mask);
extern void wififw_phy_write_rf_reg(u32 reg_addr, u32 bit_mask, u32 val);

#endif
