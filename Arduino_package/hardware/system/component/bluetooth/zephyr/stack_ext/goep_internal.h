/*
*******************************************************************************
* Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

#ifndef __GOEP_INTERNAL_H__
#define __GOEP_INTERNAL_H__

#include <stack/host/conn_internal.h>
#include <zephyr/bluetooth/classic/rfcomm.h>

#define FINAL_PKT_SET(op)            ((op) | 0x80)
#define OPCODE_GET_VALID(op)         ((op) & 0x7F)
#define OPCODE_GET_FINAL(op)         (!!((op) & 0x80))

#define OBEX_HDR_ID_ENC(hdr_id)      (((hdr_id) & 0xc0) >> 6)
#define OBEX_HDR_ID_INDEX(hdr_id)    ((hdr_id) & 0x3F)

#define OBEX_HDR_ENC_UNICODE        0
#define OBEX_HDR_ENC_BYTE_SEQ       1
#define OBEX_HDR_ENC_1BYTE          2
#define OBEX_HDR_ENC_4BYTE          3

#define OBEX_OP_CONNECT             0x00
#define OBEX_OP_DISCONNECT          0x01
#define OBEX_OP_PUT                 0x02
#define OBEX_OP_GET                 0x03
#define OBEX_OP_RESERVED0           0x04
#define OBEX_OP_SET_PATH            0x05
#define OBEX_OP_ACTION              0x06
#define OBEX_OP_SESSION             0x07
#define OBEX_OP_ABORT               0x7F

#define OBEX_RSP_CONTINUE           0x10
#define OBEX_RSP_OK                 0x20
#define OBEX_RSP_CREATED            0x21
#define OBEX_RSP_ACCEPTED           0x22
#define OBEX_RSP_FORBIDDEN          0x43
#define OBEX_RSP_INTERNAL_SERVER_ERROR   0x50
#define OBEX_RSP_NOT_IMPLEMENTED         0x51
#define OBEX_RSP_SERVICE_UNAVAILABLE     0x53

#define OBEX_HDR_ID_COUNT           0xc0
#define OBEX_HDR_ID_NAME            0x01
#define OBEX_HDR_ID_TYPE            0x42
#define OBEX_HDR_ID_LENGTH          0xc3
#define OBEX_HDR_ID_TIME            0x44
#define OBEX_HDR_ID_DESCRIPTION     0x05
#define OBEX_HDR_ID_TARGET          0x46
#define OBEX_HDR_ID_HTTP            0x47
#define OBEX_HDR_ID_BODY            0x48
#define OBEX_HDR_ID_BODY_END        0x49
#define OBEX_HDR_ID_WHO             0x4a
#define OBEX_HDR_ID_CONN_ID         0xcb
#define OBEX_HDR_ID_APP_PARAM       0x4c
#define OBEX_HDR_ID_AUTH_CHAL       0x4d
#define OBEX_HDR_ID_AUTH_RSP        0x4e
#define OBEX_HDR_ID_CREATOR_ID      0xcf
#define OBEX_HDR_ID_WAN_UUID        0x50
#define OBEX_HDR_ID_OBJECT_CLASS    0x51
#define OBEX_HDR_ID_SESSION_PARAM   0x52
#define OBEX_HDR_ID_SESSION_SEQ     0x93
#define OBEX_HDR_ID_ACTION          0x94
#define OBEX_HDR_ID_DESTNAME        0x15
#define OBEX_HDR_ID_PERMISSIONS     0xd6
#define OBEX_HDR_ID_SRM             0x97
#define OBEX_HDR_ID_SRMP            0x98

#define OBEX_HDR_MAX_NUM            0x20

#define OBEX_CONN_ID_NONE   0xFFFFFFFF

#define BT_L2CAP_PSM_GOEP   0x1023 /* It's dynamically assigned, and shall exist on goep sdp attribute */ 

typedef enum {
	GOEP_CB_OK = 0,
	GOEP_CB_PENDING = 1,
	GOPE_CB_FAILED = 2,
} __packed goep_cb_ret_t;

typedef enum {
	GOEP_ROLE_SERVER,
	GOEP_ROLE_CLIENT,
} __packed bt_goep_role_t;

enum {
	BT_GOEP_STATE_IDLE = 0,
	BT_GOEP_STATE_CHAN_CONNECTED,
	BT_GOEP_STATE_OBEX_CONNECTED,
	BT_GOEP_STATE_OPERATING,
	BT_GOEP_STATE_OBEX_DISCONNECTED,
};

struct obex_obj_info {
	uint16_t *file_name; /* unicode string pointer */
	uint16_t file_name_len;
	char *file_type;
	uint32_t file_len;
	void *file_desc;
};

struct obex_conn {
	uint32_t conn_id;
	uint16_t tx_mtu; /* Max packet len remote can receive */
	uint32_t file_len; /* file data length remain to transfer */
	void *file_desc;
};

struct bt_goep {
	struct bt_rfcomm_dlc rfcomm_dlc;
	struct bt_conn *acl;
	bt_goep_role_t role;
	struct bt_goep_driver *driver;
	uint8_t state;

	uint8_t tx_cmd_pending; /* the request pending for server's response */

	uint8_t prev_rx_cmd;
	uint32_t rx_pkts_cnt; /* Received packet(final or not final) counts of an obex request */
	struct net_buf *rx_frag_buf; /* When a pkt is fraged, this field is used to recombine these frags */

	struct obex_conn obc;
};

struct obex_hdr_parsed {
	bool is_parsed;
	uint16_t val_len;
	union {
		uint8_t value_1;
		uint32_t value_4; /* in cpu endian */
		const uint8_t *pvalue; /* point to hdr data field in net_buf */
	};
};

struct bt_goep_driver {
	uint8_t *target;
	uint16_t target_len;

	void (*chan_connected) (struct bt_goep *goep);
	void (*chan_disconnected) (struct bt_goep *goep);
	void (*obex_connected) (struct bt_goep *goep);
	void (*obex_disconnected) (struct bt_goep *goep);
	goep_cb_ret_t (*put_recv)(struct bt_goep *goep, bool is_final, 
					struct net_buf *buf, struct obex_hdr_parsed *parse_buf);
	int32_t (*get_body) (void *file_desc, uint8_t *buf, uint32_t len);
	void (*put_complete) (struct bt_goep *goep, uint8_t err);
	void (*abort) (struct bt_goep *goep);
};

struct obex_hdr_parsed *find_parsed_obex_hdr(struct obex_hdr_parsed *parse_buf,
													uint8_t hdr_id);

int bt_goep_init_session(struct bt_conn *conn, struct bt_goep *goep,
						bt_goep_role_t role, struct bt_goep_driver *driver);

struct obex_conn *goep_processing_obex_conn(struct bt_goep *goep);

int goep_send_rsp(struct bt_goep *goep, uint8_t code);

int bt_goep_connect(struct bt_conn *conn, struct bt_goep *goep, uint8_t channel);

int bt_goep_put_start(struct bt_goep *goep, struct obex_obj_info *info);

int bt_goep_disconnect(struct bt_goep *goep);

int bt_goep_abort(struct bt_goep *goep);

void unicode_from_big_endian(uint16_t *unicode, uint32_t unicode_num);

#endif