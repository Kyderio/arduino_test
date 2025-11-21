#ifndef __WIFIFW_TXRPT_COMMON_H__
#define __WIFIFW_TXRPT_COMMON_H__
/*--------------------Define MACRO--------------------------------------*/
#define TXRPT_UPDATE_RSSI_CNT 10

#define RATE_CCK_1M					0x00
#define RATE_CCK_2M					0x01
#define RATE_CCK_5M					0x02
#define RATE_CCK_11M				0x03
#define RATE_OFDM_6M        		0x04
#define RATE_OFDM_9M        		0x05
#define RATE_OFDM_12M       		0x06
#define RATE_OFDM_18M       		0x07
#define RATE_OFDM_24M       		0x08
#define RATE_OFDM_36M       		0x09
#define RATE_OFDM_48M       		0x0A
#define RATE_OFDM_54M       		0x0B
#define RATE_MCS0        			0x0C
#define RATE_MCS1        			0x0D
#define RATE_MCS2        			0x0E
#define RATE_MCS3        			0x0F
#define RATE_MCS4        			0x10
#define RATE_MCS5        			0x11
#define RATE_MCS6        			0x12
#define RATE_MCS7        			0x13
#define RATE_MCS8        			0x14
#define RATE_MCS9        			0x15

/*--------------------Define Struct---------------------------------------*/
enum RPT_TYPE {
	TXRPT       = 0,
	FTMRPT      = 1,
	CCXRPT      = 2,
	FTMACKRPT   = 3,
	TXBCNRPT    = 4,
	RXBCNRPT    = 6,
	TXRPTNew	= 7,
	TRIGGER		= 8,
};

/*------------------------------Function declaration--------------------------*/
extern void wififw_ctrlinfo_init(void);
extern void wififw_txrpt_fetch(void);
extern void wififw_txrpt_ra_handle(struct TxRpt_Cfg *tx_rpt);
extern void wififw_ctrlinfo_rate_write(u8 macid, u8 rate_idx, u8 darfc_index, u8 rty_lmt, u8 bw_idx, u8 lowest_rate_idx);
extern void wififw_h2c_macid_cfg(u8 *pbuf);
extern void wififw_h2c_rssi_setting(u8 *pbuf);
extern void wififw_txrpt_init(void);
extern void wififw_txrpt_handle(struct TxRpt_Cfg *tx_rpt);
#endif  /* #ifndef   __WIFIFW_TXRPT_H__ */
