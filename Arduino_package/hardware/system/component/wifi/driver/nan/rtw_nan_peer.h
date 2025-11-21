
struct nan_peer_info_t *rtw_nan_peer_info_get_by_ndi(u8 *mac_addr);
struct nan_peer_info_t *rtw_nan_peer_info_get(u8 *mac_addr);
struct nan_peer_info_t *rtw_nan_peer_info_alloc(u8 *mac_addr);
struct nan_peer_info_t *rtw_nan_peer_info_first_entry_get(u8 is_ndp_exist);
void rtw_nan_peer_info_queue_free(void);
void rtw_nan_peer_info_free(struct nan_peer_info_t *ppeer_info);