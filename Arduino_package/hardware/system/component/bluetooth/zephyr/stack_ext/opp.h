/*
*******************************************************************************
* Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

#ifndef __OPP_H__
#define __OPP_H__

typedef int (*bt_opp_app_cb_t) (uint8_t evt_code, uint8_t *data, uint32_t len);

enum OPP_CB_EVT {
	OPP_EVT_CONNECTED_IND = 1,
	OPP_EVT_DISCONNECTED_IND,
	OPP_EVT_SDP_ATTR_IND,
	OPP_EVT_ABORT_IND,
	/* for server */
	OPP_EVT_RECV_OBJ_INFO_CONFIRM_IND,
	OPP_EVT_RECV_OBJ_DATA_WRITE,
	OPP_EVT_RECV_OBJ_COMPLETE_IND,
	OPP_EVT_REMOTE_GET_OBJ_INFO_IND,
	OPP_EVT_REMOTE_GET_OBJ_DATA_READ,
	OPP_EVT_REMOTE_GET_OBJ_COMPLETE_IND,
	/* for client */
	OPP_EVT_SEND_OBJ_DATA_READ,
	OPP_EVT_SEND_OBJ_COMPLETE_IND,
};

enum OPP_ABORT_EVT {
	OPP_RECV_OBJ_DATA_ABORTED = 1,
	OPP_REMOTE_GET_OBJ_DATA_ABORTED,
};

typedef struct {
	bt_addr_t addr;
	uint16_t name[40];  /* unicode */
	char type[20];
	uint32_t total_len;
} bt_opp_recv_obj_info_cfm_ind_t;

typedef struct {
	void *file_desc;
	uint16_t len;
	uint8_t *data;
} bt_opp_recv_obj_data_write_t;

typedef struct {
	void *file_desc;
} bt_opp_recv_obj_complete_ind_t;

typedef struct {
	void *file_desc;
	uint8_t *buf;
	uint32_t len;
	int ret;
} bt_opp_obj_read_t;

typedef struct {
	void *file_desc;
	uint8_t err;
} bt_opp_send_obj_complete_ind_t;

typedef struct {
	void *file_desc;
	uint8_t abort_evt; /* ref enum OPP_ABORT_EVT */
} bt_opp_abort_ind_t;

int bt_opp_confirm_to_recv(bt_addr_t *addr, bool cfm, void *file_desc);

int bt_opp_create_connect(bt_addr_t *remote_addr);

int bt_opp_send_file(bt_addr_t *addr, uint16_t *file_name, uint16_t file_name_len,
						char *file_type, uint32_t file_len, void *file_desc);

int bt_opp_disconnect(bt_addr_t *remote_addr);

int bt_opp_abort(bt_addr_t *remote_addr);

#endif