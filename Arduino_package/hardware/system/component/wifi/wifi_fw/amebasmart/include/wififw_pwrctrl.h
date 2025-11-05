#ifndef __WIFIFW_PWRCTRL_H__
#define __WIFIFW_PWRCTRL_H__

#define BACKUP 			FALSE
#define RESTORE 			TRUE
#define PFMMODE 			TRUE
#define PWMMODE 			FALSE

/*--------------------Function declaration---------------------------------*/
extern u8 wifi_is_enable;
extern const u16 MAC_REG_BackupRestore_Table[];
extern const u16 array_AFE_BB_for_RFK[];
extern void wififw_ps_bbrf_set_radio_on(u8 on);
extern void wififw_ps_gntbt_sw_ctrl(u8 on);
extern void wififw_ps_set_wlact_gate(u8 on);
extern void wififw_pg_txreg_backup_restore(bool on);
extern void wififw_pg_tx_power_backup_restore(bool on);
extern void wififw_pg_rfdpk_backup_restore(u8 on);
extern void wififw_pg_drfc_restore(bool on);
extern void wififw_pg_tssi_backup_restore(bool on);
extern void wififw_pg_bbrf_para_backup_restore(bool on);
extern u8 wififw_lps_check_wldrv_on(void);
extern void wififw_pg_parm_backup(void);
extern void wififw_pg_chnon_cmdfile_set(void);
extern void wififw_lps_exit_bbrf_set_before_restore(void);
extern void wififw_lps_exit_bbrf_set_after_restore(void);
extern void wififw_ps_wlon_4m_on(u8 on);
extern void wififw_ps_tx_parameter_ready(void);
extern void wififw_ps_rf_channel_backup(void);
extern void wififw_rf_x2k_reg_hioe_init(void);
extern void wififw_ps_bbrx_rssi_update(void);
extern void wififw_cg_chnon_cmdfile_set(void);
#endif  /* __WIFIFW_PWRCTRL_H__ */
