#ifndef __RTW_NAN_CH_H_
#define __RTW_NAN_CH_H_

#define	NAN_MAX_OP_CHANNEL_SET_NUM	13

struct nan_ch_opclass {
	u32	global_op_class;
	u32	len;
	u16	channel[NAN_MAX_OP_CHANNEL_SET_NUM];
	u8	bandwidth;
};

inline void convert_to_central_channel(struct nan_phyinfo_t  *p_phyinfo)
{
	if (p_phyinfo->bw == CHANNEL_WIDTH_40) {
		if (p_phyinfo->primary_ch_idx == VHT_DATA_SC_20_LOWER_OF_80MHZ) {
			p_phyinfo->channel = p_phyinfo->channel + 2;
		} else {
			p_phyinfo->channel = p_phyinfo->channel - 2;
		}
	}
}

inline void fill_in_primary_ch_idx(struct nan_phyinfo_t  *p_phyinfo, u8 op_class)
{
	if (p_phyinfo->bw == CHANNEL_WIDTH_40) {
		switch (op_class) {
		case 83:
		case 116:
		case 126:
			p_phyinfo->primary_ch_idx = VHT_DATA_SC_20_LOWER_OF_80MHZ;
			break;
		case 84:
		case 117:
		case 127:
			p_phyinfo->primary_ch_idx = VHT_DATA_SC_20_UPPER_OF_80MHZ;
			break;
		default:
			break;
		}
	} else if (p_phyinfo->bw == CHANNEL_WIDTH_80) {
#ifdef NAN_SUPPORT_BW_80MHZ
		switch (p_phyinfo->primary_ch_idx) {
		case BIT0:
			p_phyinfo->primary_ch_idx = VHT_DATA_SC_20_LOWEST_OF_80MHZ;
			break;
		case BIT1:
			p_phyinfo->primary_ch_idx = VHT_DATA_SC_20_LOWER_OF_80MHZ;
			break;
		case BIT2:
			p_phyinfo->primary_ch_idx = VHT_DATA_SC_20_UPPER_OF_80MHZ;
			break;
		case BIT3:
			p_phyinfo->primary_ch_idx = VHT_DATA_SC_20_UPPERST_OF_80MHZ;
			break;
		default:
			break;
		}
#endif
	}

}

inline u8 get_primary_channel(struct nan_phyinfo_t  *p_phyinfo)
{
	u8 channel = 0;
	if (p_phyinfo->bw == CHANNEL_WIDTH_80) {
#ifdef NAN_SUPPORT_BW_80MHZ
		if (p_phyinfo->primary_ch_idx == VHT_DATA_SC_20_LOWEST_OF_80MHZ) {
			channel = p_phyinfo->channel - 6;
		} else if (p_phyinfo->primary_ch_idx == VHT_DATA_SC_20_UPPERST_OF_80MHZ) {
			channel = p_phyinfo->channel + 6;
		} else if (p_phyinfo->primary_ch_idx == VHT_DATA_SC_20_UPPER_OF_80MHZ) {
			channel = p_phyinfo->channel + 2;
		} else if (p_phyinfo->primary_ch_idx == VHT_DATA_SC_20_LOWER_OF_80MHZ) {
			channel = p_phyinfo->channel - 2;
		}
#else
		RTK_LOGE(TAG_WLAN_NAN, "%s not support 80M!! will return invalid ch(0)\n", __func__);
#endif
	} else if (p_phyinfo->bw == CHANNEL_WIDTH_40) {
		if (p_phyinfo->primary_ch_idx == VHT_DATA_SC_20_LOWER_OF_80MHZ) {
			channel = p_phyinfo->channel - 2;
		} else {
			channel = p_phyinfo->channel + 2;
		}
	} else if (p_phyinfo->bw == CHANNEL_WIDTH_20) {
		channel = p_phyinfo->channel;
	}
	return channel;
}

u8 rtw_nan_get_ch_set(struct rtw_ieee80211_channel *pch_set, u8 *bw, u8 op_class);
struct nan_ch_opclass  *rtw_nan_get_op_class_and_channel(struct nan_phyinfo_t *p_phyinfo, u8 *ch_num);
u8 rtw_nan_parse_is_primary_channel_valid(u8 primary_channel);
u8 rtw_nan_parse_channel_entry(struct ch_entry_t *pch_entry,  struct nan_phyinfo_t  *p_phyinfo);
u8 rtw_nan_get_channel_info(struct avl_entry_t *pavl_entry, struct nan_cmt_schdl_t *p_cmd_schdl);
void rtw_nan_channel_switch(unsigned char channel, unsigned char channel_offset, unsigned short bwmode);

#endif /* __RTW_NAN_CH_H_ */
