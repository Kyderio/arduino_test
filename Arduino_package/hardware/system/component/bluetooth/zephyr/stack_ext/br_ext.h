/*
*******************************************************************************
* Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

#ifndef __BR_EXT_H__
#define __BR_EXT_H__

enum BR_GAP_CB_EVT {
	BR_GAP_EVT_ACL_CONNECT_IND = 1,
	BR_GAP_EVT_ACL_DISCONNECT_IND,
	BR_GAP_EVT_INQUIRY_RESULT_IND,
	BR_GAP_EVT_REMOTE_NAME_IND,
	BR_GAP_EVT_MODE_CHANGE_IND,
};

typedef struct {
	uint8_t err;
	uint16_t conn_handle;
	bt_addr_t peer_addr;
	uint8_t role;
} bt_br_acl_conn_ind_t;

typedef struct {
	uint8_t reason;
	uint16_t conn_handle;
	bt_addr_t peer_addr;
	uint8_t role;
} bt_br_acl_disconn_ind_t;

typedef struct {
	uint8_t err;
	bt_addr_t addr;
	char name[40];
} bt_br_remote_name_ind_t;

typedef struct {
	uint8_t err;
	uint16_t conn_handle;
	bt_addr_t peer_addr;
	uint8_t role;
	uint8_t air_mode;
	bool is_esco;
} bt_br_sco_conn_ind_t;

typedef struct {
	uint8_t reason;
	uint16_t conn_handle;
	bt_addr_t peer_addr;
	uint8_t role;
	bool is_esco;
} bt_br_sco_disconn_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t cod[3];
	int8_t rssi;
	char name[40];
	uint8_t eir[240];
} bt_br_inquiry_result_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t mode;
	uint16_t interval;
} bt_br_mode_change_ind_t;

typedef int (*br_gap_app_cb_t) (uint8_t evt_code, uint8_t *data, uint32_t len);

typedef void (*br_connected_cb_t) (struct bt_conn *conn);

int bt_br_gap_register_callback(br_gap_app_cb_t cb);

int bt_br_write_class_of_device(uint32_t cod);

int bt_br_get_bd_addr(bt_addr_t *addr);

int bt_br_write_local_name(char *name);

int bt_br_write_ext_inquiry_rsp(uint8_t *eir_data, uint8_t eir_len);

int bt_br_switch_role(bt_addr_t *addr, uint8_t role);

int bt_br_write_scan_enable(uint8_t scan);

int bt_br_write_inquiry_scan_type(uint8_t scan_type);

int bt_br_write_inquiry_scan_activity(uint16_t interval, uint16_t window);

int bt_br_write_inquiry_mode(uint16_t mode);

int bt_br_write_page_scan_type(uint8_t scan_type);

int bt_br_write_page_scan_activity(uint16_t interval, uint16_t window);

int bt_br_write_page_timeout(uint16_t timeout);

int bt_br_start_inquiry(bool limited, uint8_t timeout);

int bt_br_set_sniff_mode(uint16_t conn_handle, uint16_t max_interval, uint16_t min_interval,
						uint16_t attempt, uint16_t timeout);

int bt_br_write_default_link_policy_settings(bool role_switch, bool hold_mode, bool sniff_mode);

int bt_br_write_link_policy_settings(uint16_t conn_handle, bool role_switch, bool hold_mode, bool sniff_mode);


int bt_br_disconnect_with_reason(bt_addr_t *addr, uint8_t reason);

int bt_br_disconnect(bt_addr_t *addr);

int bt_br_connect_with_cb(bt_addr_t *addr, br_connected_cb_t conn_cb);

int bt_br_connect(bt_addr_t *addr);

/*########################### For bredr keys ##########################*/
void print_br_key_pool(void);

uint16_t bt_br_max_bond_num_get(void);

uint16_t bt_br_bond_num_get(void);

int bt_br_bond_addr_get(uint8_t priority, bt_addr_t *paddr);

int bt_br_bond_index_get(bt_addr_t *paddr, uint8_t *index);

int bt_br_link_key_get(bt_addr_t *paddr, uint8_t *link_key, uint8_t *key_type);

int bt_br_link_key_set(bt_addr_t *paddr, uint8_t *link_key, uint8_t key_type);

#endif /* __BR_EXT_H__ */