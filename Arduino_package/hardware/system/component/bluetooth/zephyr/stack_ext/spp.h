/*
*******************************************************************************
* Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

#ifndef  __SPP_H__
#define  __SPP_H__

enum SPP_CB_EVT {
	SPP_EVT_CONNECTED_IND = 1,
	SPP_EVT_DISCONNECTED_IND,
	SPP_EVT_SDP_ATTR_IND,
	SPP_EVT_DATA_IND,
	SPP_EVT_CREDITS_IND,
};

typedef struct {
	bt_addr_t addr;
	uint8_t chan_num;
	uint16_t credit;
	uint16_t frame_size;
} bt_spp_conn_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t chan_num;
	uint16_t cause;
} bt_spp_disconn_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t chan_num;
	uint8_t *data;
	uint16_t len;
} bt_spp_data_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t chan_num;
	uint8_t credit;
} bt_spp_credits_ind_t;

typedef int (*spp_app_cb_t) (uint8_t evt_code, uint8_t *data, uint32_t len);

void bt_spp_init(void);

int bt_spp_register_callback(spp_app_cb_t cb);

int bt_spp_send_data(bt_addr_t *remote_addr, uint8_t chan_num, uint8_t *data, uint16_t len);

int bt_spp_create_connect(bt_addr_t *remote_addr);

int bt_spp_terminate_connect(bt_addr_t *remote_addr, uint8_t chan_num);

#endif  /* __SPP_H__ */