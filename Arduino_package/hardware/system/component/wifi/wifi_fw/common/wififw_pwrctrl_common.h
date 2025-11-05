#ifndef __WIFIFW_PWRCTRL_COMMON_H__
#define __WIFIFW_PWRCTRL_COMMON_H__

#define WAIT_TXSM_STABLE_CNT            (1000)
#define WAIT_TXSM_STABLE_ONCE_TIME      (50)
#define HW_AUTO_LPS_ON  0
#define HW_AUTO_LPS_OFF 1
#define RECORDRSSINUM   8

struct PS_RSSIPARM {
	u8		bcn_rssi_valid: 1;
	u8		bcn_rssi_update: 1;
	u8		bcn_rssi_window_full: 1;
	u8		bcn_rssicnt: 5;
	u8		bcn_rssi;
	u8		record_bcnrssi[RECORDRSSINUM];//0-32
	u16 	bcn_rssisum;
};

extern bool wififw_ps_wait_txcmd_idle(void);
extern void wififw_ps_openrf(void);
extern void wififw_ps_closerf(void);
extern void wififw_pg_ctrl_Info_backup_restore(bool on);
extern void wififw_pg_txllt_reconfig(void);
extern void wififw_pg_wifi_parm_backup_restore(bool on);
extern void wififw_pg_ccktxshaping_backup_restore(bool on);
extern void wififw_pg_bb_afereg_for_rfk_cmdfile_init(void);
extern void wififw_mac_exit_lps(void);
extern void wififw_mac_enter_lps(void);
extern void wififw_ps_wait_mac_exit_lps(void);
extern void wififw_ps_bcn_rssi_reset(void);
extern void wififw_ps_record_bcn_rssi(u8 rssival);
extern void bcn_rssi_sliding_data_window_record(u8 data);
extern void wififw_ps_h2c_get_bcnrssi(u8 bcnrssi);
extern void wififw_mac_auto_enter_lps_enable(u8 on);
extern void wififw_ps_mac_trx_enable(u8 on);
extern void wififw_ps_pstimer_imr_enable(u8 on);
extern void wififw_wmmps_imr_enable(void);
extern void wififw_wmmps_rx_packet_imr_enable(void);
extern void wififw_ps_bcn_early_agg_imr_enable(u8 on);
extern void wififw_ps_bcn_early0_imr_enable(u8 on);
extern void wififw_ps_p0_txpktin_imr_enable(u8 on);
#endif  //__WIFIFW_PWRCTRL_H__