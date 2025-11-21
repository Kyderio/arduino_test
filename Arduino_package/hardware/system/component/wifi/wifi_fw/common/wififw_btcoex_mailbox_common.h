#ifndef __WIFIFW_BTCOEX_MAILBOX_H__
#define __WIFIFW_BTCOEX_MAILBOX_H__
/*--------------------Define --------------------------------------------*/
#define MAILBOX_MAX_LENGTH    7

/* for MAILBOX 0x11A4~0x11B7, OUT->WL2BT, IN->BT2WL */
#define REG_MAILBOX_WL2BT_DATA0     0x0
#define REG_MAILBOX_WL2BT_DATA1     0x4
#define REG_MAILBOX_WL2BT_RDY       0x8  //bit[0] : OutReady, bit[1] : OutEmptyIntEn

#define REG_MAILBOX_BT2WL_DATA0     0xC
#define REG_MAILBOX_BT2WL_DATA1     0x10
#define REG_MAILBOX_BT2WL_RDY       0xA  //bit[0] : InReady, bit[1] : InRdyIntEn

struct btc_mailbox_format {
	u8	cmd_id;
	u8	cmd_len;
	u8	content[MAILBOX_MAX_LENGTH - 1];
};

/*--------------------Define Enum---------------------------------------*/
enum BTC_Mailbox_CMD {
	_BT_FW_PATCH                      	= 0x0a,
	_WL_OP_MODE                       	= 0x11,
	_WIFI_RF_CALIBRATION_EN           	= 0x15,
	_FORCE_BT_TXPWR                   	= 0x17,
	_BT_IGNORE_WLAN_ACT               	= 0x1b,
	_PSD_CONTROL                      	= 0x21,
	_BT_INFO_REPORT                   	= 0x23,
	_BT_PSD_REPORT                    	= 0x24,
	_BT_INFO_REPORT_BY_ITSELF         	= 0x27,
	_BT_INFO_REPORT_CONTROL           	= 0x28,
	_BT_SET_TXRETRY_REPORT_PARAMETER  	= 0x29,
	_BT_SET_PTA_TABLE                 	= 0x2A,
	_BT_MP_REPORT                     	= 0x30,
	_BT_PSD_MODE                      	= 0x31,
	_BT_SET_BT_LNA_CONSTRAINT         	= 0x32,
	_BT_LOOPBACK                      	= 0x33,
	_BT_CALIBRATION                   	= 0x34,
	_INTERNAL_SWITCH                  	= 0x35,
	_BT_CHECK_WLAN_STATE              	= 0x36,
	_CHANGE_WIFI_RF_STATE             	= 0x37,
	_BT_PAGE_SCAN_INTERVAL            	= 0x38,
	_BT_AUTO_SLOT                     	= 0x39,
	_MAILBOX_EN                       	= 0x40,
	_BT_CALIBRATION_FAIL              	= 0x41,
	_WIFI_TDMA_IN_BT_SLOT             	= 0x42,
	_WIFI_RPT_TDMA                    	= 0x43,
	_LE_AUDIO_BT_INFO_BT_RPT    		= 0x46,
	_LE_AUDIO_BT_INFO_BT_RES    		= 0x47,
	_BT_SLOT_CTRL               		= 0x48
};

/*--------------------Function declaration---------------------------------*/
extern const char *TAG_FW_COEX;

extern void wififw_btc_init_mailbox(void);
extern void wififw_btc_forward_mailbox(struct btc_mailbox_format *mailbox);
extern void wififw_btc_forward_mailbox_ext(u8 *content);
extern void wififw_btc_wl2bt_mailbox_send(struct btc_mailbox_format *mailbox);
extern void wififw_btc_get_bt2wl_mailbox(void);
extern void wififw_btc_bt2wl_mailbox_int_check(void);
extern void wififw_btc_bt2wl_scoreboard_int_hdl(void);
extern void wififw_btc_gnt_bt_bb_imr_enable(u8 on);
#endif /*  __WIFIFW_BTCOEX_MAILBOX_H__ */
