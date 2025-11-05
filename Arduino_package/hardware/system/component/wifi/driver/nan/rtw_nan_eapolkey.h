
u8 nan_parse_rsn_key_data(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry,
						  u8 *keydata_start, u16 keydatalen);
u8 *nan_construct_rsn_key_data(u8 *buf, u16 *buf_len, struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry);
