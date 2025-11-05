#ifndef __RTW_NAN_NDL_H_
#define __RTW_NAN_NDL_H_

#define NAN_NDL_CTRL_LEN_IN_NDL_ATTR							(1)
#define NAN_NDL_PEER_ID_LEN_IN_NDL_ATTR							(1)
#define NAN_MAX_IDLE_PERIOD_LEN_IN_NDL_ATTR						(2)

inline u8 *fill_data_path_frame_subtype(u8 *pframe,  u8 ndl_type, u32 *frlen)
{
	u32 len = 1;
	if (ndl_type == NDL_TYPE_REQ) {
		*pframe = NAF_SUBTYPE_DATA_PATH_REQ;
	}
	if (ndl_type == NDL_TYPE_RSP) {
		*pframe = NAF_SUBTYPE_DATA_PATH_RSP;
	}
	if (ndl_type == NDL_TYPE_CONFIRM) {
		*pframe = NAF_SUBTYPE_DATA_PATH_CONFIRM;
	}
	*frlen += len;
	pframe += len;
	return pframe;
}

inline u8 ndl_is_nego_going(u8 ndl_status)
{
	if (ndl_status == NDL_OR_NDP_STATUS_REJECT || ndl_status == NDL_OR_NDP_STATUS_ACCEPT) {
		return FALSE;
	} else {
		return TRUE;
	}
}

inline u8 *fill_schedule_frame_subtype(u8 *pframe,  u8 ndl_type, u32 *frlen)
{
	u32 len = 1;
	if (ndl_type == NDL_TYPE_REQ) {
		*pframe = NAF_SUBTYPE_SCHEDULE_REQ;
	}
	if (ndl_type == NDL_TYPE_RSP) {
		*pframe = NAF_SUBTYPE_SCHEDULE_RSP;
	}
	if (ndl_type == NDL_TYPE_CONFIRM) {
		*pframe = NAF_SUBTYPE_SCHEDULE_CONFIRM;
	}
	*frlen += len;
	pframe += len;
	return pframe;
}

inline u8 is_avail_entry_channel_info_matched(u8 *ref_ch_entry_start, u8 *ch_entry_start, u8 is_channel_entry, u8 entry_num, u8 is_include_auxi_map)
{
	if (is_channel_entry)
		return !memcmp(ref_ch_entry_start, ch_entry_start,
					   ((is_include_auxi_map) ? (CHANNEL_ENTRY_LEN_WITH_AUXI) : (CHANNEL_ENTRY_LEN)) * entry_num);
	else {
		return !memcmp(ref_ch_entry_start, ch_entry_start, BAND_ENTRY_LEN * entry_num);
	}
}

inline u8 convert_period_to_idx(u16 period)
{
	u8 i = 0;
	// input period must describe period based on NAN slot
	period = period >> 3;
	for (i = 1; i < 8; i++) {
		if (period == BIT0) {
			break;
		}
		period = period >> 1;
	}
	return (i == 8) ? (0) : (i);
}

void rtw_nan_ndl_nego_rx(union recv_frame *precv_frame);
u8 rtw_nan_ndl_state_change(struct nan_peer_info_t *ppeer_info, enum ndl_nego_state new_state);
u8 rtw_nan_ndl_any_peer_ndl_established(void);
u8 rtw_nan_ndl_send_with_ndp(struct nan_peer_info_t *ppeer_info, u8 ndl_status, u8 ndl_type);
u8 rtw_nan_ndl_send_without_ndp(struct nan_peer_info_t *ppeer_info, u8 ndl_status, u8 ndl_type);
void rtw_nan_ndl_reply_continue(struct nan_peer_info_t *ppeer_info);
void rtw_nan_ndl_reply_reject(struct nan_peer_info_t *ppeer_info);
u8 rtw_nan_ndl_send_request_with_ndp_uplayer(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry);
u8 rtw_nan_ndl_reply_uplayer(struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry);
#endif /* __RTW_NAN_NDL_H_ */