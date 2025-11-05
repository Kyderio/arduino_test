#ifndef __WIFIFW_PWRCTRL_H__
#define __WIFIFW_PWRCTRL_H__

/*--------------------Define --------------------------------------------*/
#define BACKUP 			FALSE
#define RESTORE 			TRUE

/*--------------------Function declaration---------------------------------*/
extern u8 wifi_is_enable;
extern const u16 MAC_REG_BackupRestore_Table[];
extern const u16 array_AFE_BB_for_RFK[];
extern void wififw_ps_bbrf_set_radio_on(u8 on);
extern void wififw_ps_gntbt_sw_ctrl(u8 on);
extern void wififw_ps_set_wlact_gate(u8 on);
extern void wififw_pg_txreg_backup_restore(bool on);
extern void wififw_pg_tx_power_backup_restore(bool on);
extern void wififw_pg_drfc_restore(bool on);
extern void wififw_pg_tssi_backup_restore(bool on);
extern void wififw_pg_bbrf_para_backup_restore(bool on);
extern void wififw_pg_rfdpk_backup_restore(u8 on);
extern void wififw_pg_parm_backup(void);
extern u8 wififw_lps_check_wldrv_on(void);
extern void wififw_pg_chnon_cmdfile_set(void);
extern void wififw_lps_exit_bbrf_set_before_restore(void);
extern void wififw_lps_exit_bbrf_set_after_restore(void);
extern void wififw_ps_wlon_4m_on(u8 on);
extern void wififw_ps_tx_parameter_ready(void);
extern void wififw_ps_rf_channel_backup(void);
extern void wififw_ps_bbrx_rssi_update(void);
extern void wififw_ps_bt_scoreboard_imr_disable(u8 dis);
extern void wififw_cg_chnon_cmdfile_set(void);
extern u32 halrf_get_drfc_size(void);
extern const u32 array_mp_8721f_radioa_drfc[];



#endif  /* __WIFIFW_PWRCTRL_H__ */
