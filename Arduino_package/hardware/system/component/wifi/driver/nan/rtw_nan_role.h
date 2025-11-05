
void rtw_nan_role_transit(enum nan_dev_role_e targetRole);
void rtw_nan_state_transit(u32 targetState);
void rtw_nan_role_state_transit_in_DWET(void);
void rtw_nan_role_state_transit_during_DW(u8 idx, struct anchor_mast_record_t *pamr_bcn);
void rtw_nan_role_master_indication_refresh_check(void);
u64 rtw_nan_role_state_get_master_rank(struct mast_rankinfo_t *pmst_rank);