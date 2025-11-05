#ifndef _WIFIFW_LPSOFLD_COMMON_H_
#define _WIFIFW_LPSOFLD_COMMON_H_

/*--------------------Define --------------------------------------------*/

/*------------------------------Function declaration--------------------------*/
extern void wififw_lpsofld_bbrf_cmdfiles_init(void);
extern void wififw_lpsofld_hioe_cmdfiles_init(void);
extern void wififw_lpsofld_imr_set(bool HWCtrlTRXOnOff);
extern void wififw_lpsofld_func_init(void);
extern void wififw_lpsofld_pg_restore(void);
extern void wififw_lpsofld_rf_ctrl_mac_offload(bool HWCtrlTRXOnOff);
extern void wififw_lpsofld_rxbcn_handle(void);
extern bool wififw_lpsofld_mac_sleep_protect(void);
extern void wififw_inthdl_tim(u8 tim_hit);
extern void wififw_inthdl_bcnrx_err(void);
extern void wififw_inthdl_rxbcn_timeup(void);
extern void wififw_inthdl_bcn_miss_count_to_limit(void);
extern void wififw_lpsofld_record_freerun_tsft1(void);
extern void wififw_lpsofld_record_freerun_tsft2(void);
extern void wififw_lpsofld_cal_delta_freerun_tsf(void);
extern void wififw_lpsofld_record_tsft_diff(void);
extern void wififw_ps_get_aptsft_diff_ave(void);
extern void wififw_pg_keycam_cmdfile_init(void);
extern void wififw_lpsofld_rxbcn_tocnt_clear(void);
extern void wififw_lpsofld_rxbcn_window_update(void);
extern void wififw_lpsofld_cal_tsft_diff_threshold(void);
extern void wififw_lpsofld_get_tsft_freerun_diff(u32 *DIFF_H, u32 *DIFF_L);
extern void wififw_lpsofld_update_tsft_reg(u32 TSF_Diff_Cmpsation);
extern void wififw_lpsofld_correct_tsft(void);
extern void wififw_ps_enlarge_rxbcn_window(u8 bcn_early_offset,  u16 bcn_to_offset);
extern void wififw_ps_revert_rxbcn_window(void);
extern void wififw_lpsofld_set_tbtt_agg_cnt(void);
extern void wififw_hw_rxbcn_cnt_statistic_init(void);
extern void wififw_rfoff_by_edcca_init(void);
extern void wififw_lpsofld_bbreset_hioecmd_init(void);
extern void wififw_lpsofld_hioe_chon_cmdfile_init(void);
extern void wififw_lpsofld_hioe_choff_cmdfile_init(void);
extern void wififw_lpsofld_hioe_onoff_cmdfiles_reinit(void);
extern void wififw_lpsofld_set_hioe_onoff_cmdfiles_addr(u16 chon_start_addr, u16 chon_end_addr, u16 choff_start_addr, u16 choff_end_addr);
extern void wififw_lpsofld_hioe_onoff_bypass(u8 on);
extern void wififw_lpsofld_hw_function_ctrl(u8 enable);
extern void wififw_lpsofld_get_bcn_space_early_cnt(u16 *bcn_space, u8 *bcncnt, u16 *bcn1ms_cnt,
		u8 *bcn128us_cnt, u8 *bcnearly_ms, u8 *bcnto_ms);
extern u32 wififw_lpsofld_hioeon_to_bcncca_delay(void);
extern void wififw_lpsofld_bcntimeup_lmt_set(void);
extern void wififw_lpsofld_bcn_dtim_mask_set(void);
extern void wififw_lpsofld_hioe_size_check(void);
extern void wififw_lpsofld_hioe_cmdfiles_full_init(void);
#endif
