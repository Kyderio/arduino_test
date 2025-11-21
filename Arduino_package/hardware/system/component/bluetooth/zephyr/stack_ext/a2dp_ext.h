/*
*******************************************************************************
* Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

#ifndef __A2DP_EXT_H__
#define __A2DP_EXT_H__

enum A2DP_CB_EVT{
	A2DP_EVT_SDP_ATTR_IND = 1,
	A2DP_EVT_SIGNAL_CONNECTED_IND,
	A2DP_EVT_SIGNAL_DISCONNECTED_IND,
	A2DP_EVT_STREAM_CONNECTED_IND,
	A2DP_EVT_STREAM_DISCONNECTED_IND,

	A2DP_EVT_SET_CONFIG_REQ,
	A2DP_EVT_SET_CONFIG_RSP,
	A2DP_EVT_STREAM_OPEN_IND,
	A2DP_EVT_STREAM_START_REQ,
	A2DP_EVT_STREAM_START_RSP,
	A2DP_EVT_STREAM_CLOSE_IND,
	A2DP_EVT_STREAM_SUSPEND_IND,
	A2DP_EVT_STREAM_ABORT_IND,

	A2DP_EVT_MEDIA_DATA_IND,
	A2DP_EVT_MEDIA_DATA_TX_COMPLETE,
};

typedef struct {
	uint16_t seq_num;
	uint32_t length;
	uint8_t *data;
} bt_a2dp_media_data_ind_t;

typedef struct {
	uint8_t codec_type;
	union {
		struct {
			uint8_t sample_freq;
			uint8_t channel_mode;
			uint8_t block_len;
			uint8_t subbands;
			uint8_t alloc_method;
			uint8_t min_bitpool;
			uint8_t max_bitpool;
		} sbc;
	};
} bt_a2dp_codec_ind_t;

int bt_a2dp_set_role(uint8_t role);

typedef int (*a2dp_app_cb_t) (uint8_t evt_code, uint8_t *data, uint32_t len);

int bt_a2dp_create_endpoint_and_register(uint8_t role, uint8_t codec_type,
							uint8_t *codec_info, uint16_t codec_info_len);

int bt_a2dp_register_callback(a2dp_app_cb_t cb);

int bt_a2dp_profile_init(uint8_t role);

int bt_a2dp_create_connect(bt_addr_t *addr);

int bt_a2dp_send_media_data(bt_addr_t *addr, uint16_t seq_num, uint32_t ts,
					uint8_t frame_num, uint8_t *frame_data, uint16_t len);

int bt_a2dp_start_media_stream(bt_addr_t *addr);

int bt_a2dp_suspend_media_stream(bt_addr_t *addr);

#endif /* __A2DP_EXT_H__ */