
#ifndef __WIFIFW_RA_DBG_NEW__
#define __WIFIFW_RA_DBG_NEW__

struct bb_rx_statistic {
	u16 cck_crc_err;
	u16 ofdm_crc_err;
	u16 ht_crc_err;
	u16 vht_crc_err;
	u16 he_crc_err;
};

extern struct bb_rx_statistic ra_bb_rx_statistic;
extern const char *TAG_FW_RA;
extern void wififw_ra_dbg_rate_statistic(void);
extern void wififw_ra_txrpt_final_rate_statistic(u8 macid, u8 ok_num);
extern void wififw_ra_txrpt_drop_retry_statistic(u8 macid, u8 drop_num, u8 retry_num);
#endif
