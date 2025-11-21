/*
*******************************************************************************
* Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

#ifndef __AVDTP_INTERNAL_EXT_H__
#define __AVDTP_INTERNAL_EXT_H__

enum {
	BT_AVDTP_FIND_SEP_STOP = 0,
	BT_AVDTP_FIND_SEP_CONTINUE,
};

struct bt_avdtp_suspend_params {
	struct bt_avdtp_req req;
	struct bt_avdtp_sep *sep;
	uint8_t status;
	uint8_t acp_stream_ep_id;
};

static void avdtp_get_all_capabilities_handler(struct bt_avdtp *session,
			struct net_buf *buf, uint8_t msg_type, uint8_t tid);

static void avdtp_reset_sep_state(struct bt_avdtp *session);

int bt_avdtp_suspend(struct bt_avdtp *session,
						struct bt_avdtp_suspend_params *param);

void bt_avdtp_foreach_registered_sep(int (* func)(struct bt_avdtp_sep *sep, void *user_data), void *user_data);

int bt_avdtp_send_media_data_with_cb(struct bt_avdtp_sep *sep, struct net_buf *buf, bt_conn_tx_cb_t cb);

bool bt_avdtp_is_sep_state_streaming(struct bt_conn *conn);

#endif /* __AVDTP_INTERNAL_EXT_H__ */