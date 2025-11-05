#ifndef __WIFI_INTF_DRV_TO_MP_SDIO__
#define __WIFI_INTF_DRV_TO_MP_SDIO__

#if defined(CONFIG_MP_INCLUDED) && defined(CONFIG_WHC_INTF_SDIO)

#define SDIO_MP_RESULT_OK		0
#define SDIO_MP_PARAM_ERR		-1
#define SDIO_MP_RESULT_FAIL	-2
#define SDIO_MP_MALLOC_FAIL	-3
#define SDIO_MP_SUB_ID_ERR		-4

#define WHC_MP_DEFAULT_OUTBUF_SIZE 	64
#define WHC_MP_MAX_OUTBUF_SIZE	4096

enum MP_QUERY_RX_ITEM {
	QUERY_DRIVER_RX_PACKET_RECEIVED,
	QUERY_DRIVER_RX_PACKET_CRC32ERR,
	QUERY_MAC_RX_PACKET_RECEIVED,
	QUERY_MAC_RX_PACKET_CRC32ERR,
	QUERY_PHY_RX_PACKET_RECEIVED,
	QUERY_PHY_RX_PACKET_CRC32ERR,
};

enum MP_RESET_RX_ITEM {
	RESET_PHY_RX_PACKET_CNT,
	RESET_MAC_RX_PACKET_CNT,
	RESET_DRIVER_RX_PACKET_CNT,
};

enum MP_REG_TYPE {
	MAC_REG,
	RF_REG,
	BB_REG,
	INVALID_REG
};

enum WHC_SDIO_MP_FUNC_ID {
	SDIO_MP_SET_ANTENNA,
	SDIO_MP_SET_PWRTRK,
	SDIO_MP_GET_PWRTRK,
	SDIO_MP_GET_THERMAL,
	SDIO_MP_SET_TXPOWER,
	SDIO_MP_GET_TXINFO_POWER,
	SDIO_MP_SET_SINGLETONE_TX,
	SDIO_MP_SET_RF_MODE,
	SDIO_MP_QUERY_RX_CNT,
	SDIO_MP_RESET_RX_CNT,
	SDIO_MP_GET_RSSI,
	SDIO_MP_GET_RXEVM,
	SDIO_MP_SET_GAIN_OFFSET,
	SDIO_MP_SET_CRYSTAL_CAP,
	SDIO_MP_GET_CRYSTAL_CAP,
	SDIO_MP_TRIGGER_DPK,
	SDIO_MP_SET_TSSI_DE_OFFSET,
	SDIO_MP_GET_TSSI_DE,
	SDIO_MP_SET_TSSI_DE,
	SDIO_MP_READ_REGISTER,
	SDIO_MP_WRITE_REGISTER,
	SDIO_MP_READ_EFUSE,
	SDIO_MP_WRITE_EFUSE,
	SDIO_MP_GET_EFUSE_SIZE,
};


struct mp_func_t {
	u32 mp_id;
	int (*func)(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
};

int rtw_sdio_mp_set_antenna(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_set_pwrtrk(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_get_pwrtrk(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_get_thermal(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_set_txpower(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_get_txinfo_power(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_set_singletone_tx(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_set_rf_mode(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_query_rx_cnt(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_reset_rx_cnt(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_get_rssi(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_get_rxevm(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_set_gain_offset(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_set_crystal_cap(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_get_crystal_cap(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_trigger_dpk(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_set_tssi_de_offset(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_get_tssi_de(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_set_tssi_de(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_read_register(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_write_register(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_read_efuse(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_write_efuse(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
int rtw_sdio_mp_get_efuse_size(struct net_device *dev, u8 *inbuf, u8 *outbuf, u32 *outlen);
void rtw_sdio_mp_cmd_dispatch(u32 api_id, u32 *param);

#endif

#endif
