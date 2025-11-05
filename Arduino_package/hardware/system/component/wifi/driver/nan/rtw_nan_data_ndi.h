
u8 rtw_nan_ndi_stainfo_alloc(u8 *mac_addr, u8 peer_nmi_macid, struct nan_peer_info_t *ppeer_info);
void rtw_nan_ndi_stainfo_free(u8 *mac_addr);
void rtw_nan_ndi_sec_stainfo_free(struct nan_peer_info_t *ppeer_info,
								  struct ndp_entry_t *pndp_entry);
u8 rtw_nan_ndi_peerinfo_match(struct nan_peer_info_t *ppeer_info, u8 *peer_ndi);