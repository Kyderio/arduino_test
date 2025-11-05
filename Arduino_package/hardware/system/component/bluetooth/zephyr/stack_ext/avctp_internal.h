/*
*******************************************************************************
* Copyright(c) 2023, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

#ifndef  __AVCTP_INTERNAL_H__
#define  __AVCTP_INTERNAL_H__

#include <zephyr/sys/util.h>
#include <zephyr/sys/slist.h>
#include <zephyr/bluetooth/l2cap.h>

#define BT_L2CAP_PSM_AVCTP 0x0017

#define PROFILE_ID_AVRC	0x110E

#define AVCTP_PKT_TYPE_SINGLE 0x00
#define AVCTP_PKT_TYPE_START  0x01
#define AVCTP_PKT_TYPE_CONTINUE  0x02
#define AVCTP_PKT_TYPE_END  0x03

#define AVCTP_CHAN(_ch)  CONTAINER_OF(_ch, struct bt_avctp, br_chan.chan)

/* structure of avctp session */
struct bt_avctp {
	struct bt_l2cap_br_chan br_chan;
	uint8_t local_trans_label;
	void *avrcp_info;
};

struct bt_avctp_single_pkt_hdr {
	uint8_t hdr;
	uint16_t profile_id;
} __packed;

struct bt_avctp_event_cb {
	uint16_t profile_type;
	int (*recv)(struct bt_l2cap_chan *chan, uint8_t trans_label,
						uint8_t cmd_or_rsp, struct net_buf *buf);
	int (*connected) (struct bt_l2cap_chan *chan);
	int (*disconnected) (struct bt_l2cap_chan *chan);
	sys_snode_t node;
};

int bt_avctp_register(struct bt_avctp_event_cb *cb);

int bt_avctp_init(void);

uint8_t avctp_get_next_trans_label(struct bt_avctp *session);

int avctp_chan_send(struct bt_avctp *session, struct net_buf *buf);

int bt_avctp_connect(struct bt_conn *conn, struct bt_avctp **avctp_session);

#endif /* __AVCTP_INTERNAL_H__ */