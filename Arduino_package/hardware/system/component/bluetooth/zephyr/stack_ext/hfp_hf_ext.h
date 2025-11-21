/*
*******************************************************************************
* Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

#define HFP_ROLE_AG  0x0
#define HFP_ROLE_HF  0x1

enum HFP_HF_CB_EVT {
	HFP_HF_EVT_CONNECTED_IND = 1,
	HFP_HF_EVT_DISCONNECTED_IND,

	HFP_HF_EVT_RING_IND,
	HFP_HF_EVT_CALLER_ID_IND,
	HFP_HF_EVT_CALL_STATUS_IND,
	HFP_HF_EVT_REMOTE_SUPPORT_FEAT_IND,
	HFP_HF_EVT_REMOTE_BATTERY_IND,
	HFP_HF_EVT_XAPL_COMPLETE_IND,
	HFP_HF_EVT_SPEAKER_VOLUME_SET_IND,
	HFP_HF_EVT_MICROPHONE_VOLUME_SET_IND,

	HFP_HF_EVT_SEND_BATT_LEVEL_COMPLETE_IND,
	HFP_HF_EVT_SEND_SPEAKER_GAIN_COMPLETE_IND,
	HFP_HF_EVT_SEND_MICROPHONE_GAIN_COMPLETE_IND,
	HFP_HF_EVT_DIAL_NUMBER_COMPLETE_IND,
	HFP_HF_EVT_DIAL_LAST_NUMBER_COMPLETE_IND,

	HFP_HF_EVT_SCO_LINK_CONNECTED_IND,
	HFP_HF_EVT_SCO_LINK_DISCONNECTED_IND,
	HFP_HF_EVT_SCO_DATA_IND
};

typedef int (*hfp_hf_app_cb_t) (uint8_t evt_code, uint8_t *data, uint32_t len);

enum HFP_CALL_STATUS {
	HFP_CALL_IDLE = 0,
	HFP_CALL_INCOMING,
	HFP_CALL_OUTGOING,
	HFP_CALL_ACTIVE,
};

typedef struct {
	bt_addr_t addr;
	char *number;
	uint8_t type;
} bt_hfp_caller_id_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t prev_status;
	uint8_t curr_status;
} bt_hfp_call_status_ind_t;

typedef struct {
	bt_addr_t addr;
	uint32_t features;
} bt_hfp_remote_support_feat_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t xapl_feat;
} bt_hfp_xapl_complete_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t value;
} bt_hfp_remote_battery_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t result;  /* ref enum at_result */
	uint8_t cme_err;  /* ref enum at_cme */
} bt_hfp_atcmd_common_complete_ind_t,
bt_hfp_atcmd_batt_level_complete_ind_t,
bt_hfp_atcmd_spk_gain_complete_ind_t,
bt_hfp_atcmd_mic_gain_complete_ind_t,
bt_hfp_atcmd_dial_num_complete_ind_t,
bt_hfp_atcmd_dial_last_num_complete_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t volume;
} bt_hfp_spk_vol_set_t,
bt_hfp_mic_vol_set_t;

int bt_hfp_hf_register_callback(hfp_hf_app_cb_t cb);

int bt_hfp_hf_call_answer(bt_addr_t *remote_addr);

int bt_hfp_hf_call_terminate(bt_addr_t *remote_addr);

int bt_hfp_hf_send_batt_level(bt_addr_t *remote_addr, uint8_t batt_level);

int bt_hfp_hf_send_speaker_gain(bt_addr_t *remote_addr, uint8_t gain);

int bt_hfp_hf_send_microphone_gain(bt_addr_t *remote_addr, uint8_t gain);

int bt_hfp_hf_create_sco_connect(bt_addr_t *remote_addr);

int bt_hfp_hf_terminate_sco_connect(bt_addr_t *remote_addr);

int bt_hfp_hf_dial_with_number(bt_addr_t *remote_addr, const char *number);

int bt_hfp_hf_dial_last_number(bt_addr_t *remote_addr);
