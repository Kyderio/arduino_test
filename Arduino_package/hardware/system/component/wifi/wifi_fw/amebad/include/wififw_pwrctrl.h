#ifndef __WIFIFW_PWRCTRL_H__
#define __WIFIFW_PWRCTRL_H__

/*--------------------Define --------------------------------------------*/
#define BACKUP 				FALSE
#define RESTORE 			TRUE
#define WAIT_TSF_STABLE_BREAK_CNT       (5000)
#define WAIT_TSF_STABLE_CNT             (50)
#define WAIT_TSF_STABLE_ONCE_TIME       (20)
#define TSFIS32K                        1
#define TSFIS40M                        0
#define GET_TSF_STATE() ((HAL_READ16(WIFI_REG_BASE, REG_TSF_CLK_STATE) & BIT_TSF_CLK_STABLE) ? TSFIS32K : TSFIS40M)
/*--------------------Function declaration---------------------------------*/
extern u8 wifi_is_enable;
extern const u16 PG_BackupRestoreREGTable[];
extern const u16 PG_AfeForRfk_REGTable[];
extern void wififw_ps_bbrf_set_radio_on(u8 on);
extern void wififw_ps_gntbt_sw_ctrl(u8 on);
extern void wififw_ps_set_wlact_gate(u8 on);
extern u8 wififw_lps_check_wldrv_on(void);
extern void wififw_lps_exit_bbrf_set_after_restore(void);
extern void wififw_ps_wlon_4m_on(u8 on);
extern void wififw_ps_tx_parameter_ready(void);
extern void wififw_ps_rf_channel_backup(void);
extern void wififw_ps_bbrx_rssi_update(void);
extern void wififw_wlpmc_tsf_clock_switch(u8 on);
#endif  //__WIFIFW_PWRCTRL_H__
