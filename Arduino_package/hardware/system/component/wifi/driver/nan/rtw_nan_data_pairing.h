
#ifdef CONFIG_NAN_PAIRING
/* methods for bstrap */
u8 rtw_nan_pairing_identity_init(void);
void rtw_nan_bstrap_phase_reset(struct nan_peer_info_t *ppeer_info);
void rtw_nan_bstrap_comeback_timer_hdl(void *ctx);
void rtw_nan_bstrap_comback_req_send(struct nan_peer_info_t *ppeer_info);
void rtw_nan_sdf_rx_bstrap_req(struct nan_peer_info_t *ppeer_info, struct nan_peer_srvcinfo_t *ppeer_srvcinfo, struct npba_attr_t *npba_attr, u16 attr_len);
void rtw_nan_sdf_rx_bstrap_rsp(struct nan_peer_info_t *ppeer_info, struct nan_peer_srvcinfo_t *ppeer_srvcinfo, struct npba_attr_t *npba_attr, u16 attr_len);

u8 rtw_nan_pasn_attr_exist(struct nan_peer_info_t *ppeer_info, u8 attr_id);
u8 rtw_nan_pasn_prepare(struct nan_peer_info_t *ppeer_info, u8 type, u8 auth_type, u8 nik_ck);
u8 rtw_nan_pasn_rx_checking(u8 *peer_nmi, u8 *auth_frame, u16 auth_frame_len);
void rtw_nan_pasn_tx_mgmt_revise(const u8 *buf);
#endif /* CONFIG_NAN_PAIRING */