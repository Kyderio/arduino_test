
u8 rtw_is_nan_frame(union recv_frame *precv_frame);
void rtw_nan_action_frame_queue_send_in_DW(u32 dw_idx, u8 is_5g);
void rtw_nan_action_frame_queue_free(void);
u8 rtw_nan_action_frame_send_insert(struct xmit_frame *pxmitframe, struct nan_peer_info_t *ppeer_info);
int rtw_nan_on_action_public(union recv_frame *precv_frame);
u8 *rtw_nan_action_frame_hdr_construct(u8 *pframe, struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, u32 *frlen);
