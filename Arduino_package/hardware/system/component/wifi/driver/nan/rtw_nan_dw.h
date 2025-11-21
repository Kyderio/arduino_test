
void rtw_nan_dw_next_calculate(u64 cur_tsf_aline);
void rtw_nan_dw_early_hdl(u8 ch);
void rtw_nan_dw_start_hdl(u8 sdf);
void rtw_nan_dw_end_hdl(void);
void rtw_nan_dw_timer_hdl(void *ctx);
void rtw_nan_dw_timer_next_dw_set(void);
void rtw_nan_dw_timer_reset(struct nan_srvc_inst_t *psrvc_inst);
void rtw_nan_dw_schedule_para_set(u8 rmv);
void rtw_nan_dw_awake_interval_update_4subpub(u8 new_awakw_dw_intvl);
void rtw_nan_dw_sdf_tx_ctrl(u8 enable);