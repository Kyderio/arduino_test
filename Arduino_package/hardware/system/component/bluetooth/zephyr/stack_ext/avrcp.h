/*
*******************************************************************************
* Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
*******************************************************************************
*/

#ifndef  __AVRCP_H__
#define  __AVRCP_H__

#define AVRCP_OPERATION_ID_PLAY  0x44
#define AVRCP_OPERATION_ID_STOP  0x45
#define AVRCP_OPERATION_ID_PAUSE  0x46
#define AVRCP_OPERATION_ID_REWIND 0x48
#define AVRCP_OPERATION_ID_FAST_FORWARD  0x49
#define AVRCP_OPERATION_ID_BACKWARD  0x4b
#define AVRCP_OPERATION_ID_FORWARD  0x4c

typedef enum {
	AVRCP_MEDIA_ROLE_SRC = 0x0,
	AVRCP_MEDIA_ROLE_SNK = 0x1,
} bt_avrcp_media_role_t;

typedef enum {
	AVRCP_PLAYBACK_STATUS_STOPPED  = 0x00,
	AVRCP_PLAYBACK_STATUS_PLAYING  = 0x01,
	AVRCP_PLAYBACK_STATUS_PAUSED   = 0x02,
	AVRCP_PLAYBACK_STATUS_FWD_SEEK = 0x03,
	AVRCP_PLAYBACK_STATUS_REV_SEEK = 0x04,
	AVRCP_PLAYBACK_STATUS_ERROR    = 0xFF,
} bt_avrcp_playback_status_t;

typedef enum {
	AVRCP_ELEM_ATTR_TITTLE = 0x01,
	AVRCP_ELEM_ATTR_ARTIST_NAME = 0x02,
	AVRCP_ELEM_ATTR_ALBUM_NAME  = 0x03,
	AVRCP_ELEM_ATTR_TRACK_NUM  = 0x04,
	AVRCP_ELEM_ATTR_TOTAL_TRACK_NUM  = 0x05,
	AVRCP_ELEM_ATTR_GENRE  = 0x06,
	AVRCP_ELEM_ATTR_PLAYING_TIME = 0x07,
	AVRCP_ELEM_ATTR_DEFAULT_COVER_ART = 0x08,
} bt_avrcp_elem_attr_id;

typedef struct {
	bt_addr_t addr;
	uint8_t attr_num;
	uint32_t *attr_id_list;
} bt_avrcp_get_elem_attr_req_t;

typedef struct {
	uint32_t attr_id;
	uint16_t charac_set_id;
	uint16_t attr_len;
	uint8_t *attr_value;
} bt_avrcp_elem_attr_info_t;

typedef struct {
	bt_addr_t addr;
	uint8_t attr_num;
	bt_avrcp_elem_attr_info_t *attr_info;
} bt_avrcp_get_elem_attr_rsp_t;

typedef struct {
	bt_addr_t addr;
	uint32_t song_length;
	uint32_t song_position;
	uint8_t play_status;
} bt_avrcp_get_playstatus_info_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t volume;
} bt_avrcp_set_absolute_volume_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t play_status;
} bt_avrcp_play_status_changed_ind_t;

typedef struct {
	bt_addr_t addr;
	uint64_t track_id;
} bt_avrcp_track_changed_ind_t;

typedef struct {
	bt_addr_t addr;
	uint32_t playback_pos;
} bt_avrcp_playback_pos_changed_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t attr_num;
	uint8_t *value;
} bt_avrcp_player_app_setting_changed_ind_t;

typedef struct {
	bt_addr_t addr;
} bt_avrcp_now_playing_content_changed_ind_t;

typedef struct {
	bt_addr_t addr;
} bt_avrcp_avail_player_changed_ind_t;

typedef struct {
	bt_addr_t addr;
	uint16_t player_id;
	uint16_t uid_counter;
} bt_avrcp_addressed_player_channged_ind_t;

typedef struct {
	bt_addr_t addr;
	uint16_t uid_counter;
} bt_avrcp_uid_changed_ind_t;

typedef struct {
	bt_addr_t addr;
	uint8_t volume;
} bt_avrcp_volume_changed_ind_t;

typedef union {
	/* all union member structer shall start with struct member 'bt_addr_t' */
	bt_avrcp_play_status_changed_ind_t play_status_changed_ind;
	bt_avrcp_track_changed_ind_t track_changed_ind;
	bt_avrcp_playback_pos_changed_ind_t playback_pos_changed_ind;
	bt_avrcp_player_app_setting_changed_ind_t app_setting_changed_ind;
	bt_avrcp_now_playing_content_changed_ind_t now_playing_content_changed_ind;
	bt_avrcp_avail_player_changed_ind_t avail_player_changed_ind;
	bt_avrcp_addressed_player_channged_ind_t addressed_player_changed_ind;
	bt_avrcp_uid_changed_ind_t uid_changed_ind;

	bt_avrcp_volume_changed_ind_t vol_changed_ind;
} bt_avrcp_notification_evt_ind_t;

enum AVRCP_CB_EVT {
	AVRCP_EVT_SDP_ATTR_IND = 1,
	AVRCP_EVT_CONNECTED_IND,
	AVRCP_EVT_DISCONNECTED_IND,

	/* event for controller */
	AVRCP_EVT_GET_ELEM_ATTR_RSP,
	AVRCP_EVT_GET_PLAY_STATUS_RSP,
	AVRCP_EVT_REMOTE_SET_ABSOLUTE_VOLUME_IND,

	AVRCP_EVT_NOTIFICATION_PLAYBACK_STATUS_CHANGED_IND,
	AVRCP_EVT_NOTIFICATION_TRACK_CHANGED_IND,
	AVRCP_EVT_NOTIFICATION_PLAYBACK_POS_CHANGED_IND,
	AVRCP_EVT_NOTIFICATION_PLAYER_APP_SETTING_CHANGED_IND,
	AVRCP_EVT_NOTIFICATION_NOW_PLAYING_CONTENT_CHANGED_IND,
	AVRCP_EVT_NOTIFICATION_AVAILABLE_PLAYER_CHANGED_IND,
	AVRCP_EVT_NOTIFICATION_ADDRESSED_PLAYER_CHANGED_IND,
	AVRCP_EVT_NOTIFICATION_UIDS_CHANGED_IND,

	/* event for target */
	AVRCP_EVT_NOTIFICATION_VOLUME_CHANGED_IND,
	AVRCP_EVT_CONTROL_PLAY,
	AVRCP_EVT_CONTROL_STOP,
	AVRCP_EVT_CONTROL_PAUSE,
	AVRCP_EVT_CONTROL_BACKWARD,
	AVRCP_EVT_CONTROL_FORWARD,
	AVRCP_EVT_CONTROL_REWIND_START,
	AVRCP_EVT_CONTROL_REWIND_STOP,
	AVRCP_EVT_CONTROL_FAST_FORWARD_START,
	AVRCP_EVT_CONTROL_FAST_FORWARD_STOP,

	AVRCP_EVT_GET_ELEM_ATTR_REQ,
	AVRCP_EVT_GET_PLAY_STATUS_REQ,
};

int bt_avrcp_set_media_role(uint8_t role);

typedef int (*avrcp_app_cb_t) (uint8_t evt_code, uint8_t *data, uint32_t len);

int bt_avrcp_register_callback(avrcp_app_cb_t cb);

int bt_avrcp_pass_through_control(bt_addr_t *remote_addr, uint8_t operation_id,
															uint8_t is_pressed);

int bt_avrcp_notify_playback_status_changed(bt_addr_t *remote_addr, uint8_t status);

int bt_avrcp_notify_track_changed(bt_addr_t *remote_addr, uint64_t track_id);

int bt_avrcp_notify_available_players_changed(bt_addr_t *remote_addr);

int bt_avrcp_notify_addressed_player_changed(bt_addr_t *remote_addr, 
									uint16_t player_id, uint16_t uid_counter);

int bt_avrcp_notify_volume_changed(bt_addr_t *remote_addr, uint8_t volume);

int bt_avrcp_set_absolute_volume(bt_addr_t *remote_addr, uint8_t volume);

int bt_avrcp_get_current_element_attr_req(bt_addr_t *remote_addr,
								uint8_t attr_num, uint32_t *attr_list);

int bt_avrcp_get_element_attr_rsp(bt_addr_t *remote_addr, uint8_t attr_num, 
									bt_avrcp_elem_attr_info_t *attr_info);

int bt_avrcp_get_play_status_req(bt_addr_t *remote_addr);

int bt_avrcp_get_play_status_rsp(bt_addr_t *remote_addr, uint32_t song_len,
								uint32_t song_pos, uint8_t play_status);

int bt_avrcp_create_connect(bt_addr_t *addr);

#endif  /* __AVRCP_H__ */
