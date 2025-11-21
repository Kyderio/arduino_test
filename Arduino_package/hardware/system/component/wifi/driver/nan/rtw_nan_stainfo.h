void rtw_nan_stainfo_init(struct sta_mlme_priv *psta_mlmepriv);
void rtw_nan_stainfo_update(struct sta_mlme_priv *psta_mlmepriv);
u8 rtw_nan_stainfo_alloc(u8 *mac_addr, u8 *mac_id, struct nan_peer_info_t *ppeer_info);
void rtw_nan_stainfo_free(u8 *mac_addr, u8 *mac_id);
void rtw_nan_stainfo_bssrate_update(struct sta_mlme_priv *psta_mlmepriv, u8 *rateset, u8 rateset_len);