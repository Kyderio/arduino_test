#ifndef __RTW_NAN_NDP_ENTRY_H_
#define __RTW_NAN_NDP_ENTRY_H_

struct ndp_entry_t *rtw_nan_ndp_entry_alloc(struct nan_peer_info_t *ppeer_info);
struct ndp_entry_t *rtw_nan_ndp_entry_find(struct nan_peer_info_t *ppeer_info, void *data, u8 search_type);
struct ndp_entry_t *rtw_nan_ndp_entry_get_first_sec(struct nan_peer_info_t *ppeer_info);
void rtw_nan_ndp_entry_free(struct ndp_entry_t *pndp_entry);
void rtw_nan_ndp_data_free(struct nan_peer_info_t *ppeer_info);
u8 rtw_nan_ndp_entry_count_get_by_ndi(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry);

struct wpa_eapol_key *rtw_nan_sec_info_rsna_key_desc_alloc(u32 len);
void rtw_nan_sec_info_rsna_key_desc_free(struct wpa_eapol_key **eapol_key);
#endif /* __RTW_NAN_NDP_ENTRY_H_ */