/*
*******************************************************************************
* Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

typedef int (*hfp_ag_app_cb_t) (uint8_t evt_code, uint8_t *data, uint32_t len);

enum HFP_AG_CB_EVT {
	HFP_AG_EVT_CONNECTED_IND = 1,
	HFP_AG_EVT_DISCONNECTED_IND,

	HFP_AG_EVT_SDP_ATTR_IND,
	HFP_AG_EVT_REMOTE_BATTERY_IND,
	HFP_AG_EVT_SPEAKER_VOLUME_IND,
	HFP_AG_EVT_MICROPHONE_VOLUME_IND,
	HFP_AG_EVT_CALL_ACCEPT_IND,
	HFP_AG_EVT_CALL_REJECT_IND,
	HFP_AG_EVT_CALL_TERMINATE_IND,
	HFP_AG_EVT_DIAL_NUMBER_IND,
	HFP_AG_EVT_DIAL_LAST_IND,
	HFP_AG_EVT_DIAL_CANCEL_IND,

	HFP_AG_EVT_SCO_LINK_CONNECTED_IND,
	HFP_AG_EVT_SCO_LINK_DISCONNECTED_IND,
	HFP_AG_EVT_SCO_DATA_IND,
};

typedef struct {
	bt_addr_t addr;
	uint8_t value;
} bt_hfp_ag_remote_battery_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t volume;
} bt_hfp_ag_spk_vol_ind_t,
bt_hfp_ag_mic_vol_ind_t;

typedef struct {
	bt_addr_t addr;
	char *number;
} bt_hfp_ag_dial_number_req_t;

int bt_hfp_ag_register_callback(hfp_ag_app_cb_t cb);

int bt_hfp_ag_create_connect(bt_addr_t *addr);

int bt_hfp_ag_terminate_connect(bt_addr_t *remote_addr);

int bt_hfp_ag_remote_call_incoming(bt_addr_t *remote_addr, const char *number, uint8_t number_type);

int bt_hfp_ag_set_speaker_volume(bt_addr_t *remote_addr, uint8_t volume);

int bt_hfp_ag_set_microphone_volume(bt_addr_t *remote_addr, uint8_t volume);

int bt_hfp_ag_create_sco_connect(bt_addr_t *remote_addr);

int bt_hfp_ag_terminate_sco_connect(bt_addr_t *remote_addr);

int bt_hfp_ag_call_outgoing(bt_addr_t *remote_addr, const char *number);

int bt_hfp_ag_accept_call(bt_addr_t *remote_addr);

int bt_hfp_ag_terminate_call(bt_addr_t *remote_addr);
