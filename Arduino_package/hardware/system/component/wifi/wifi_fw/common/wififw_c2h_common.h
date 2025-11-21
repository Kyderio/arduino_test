#ifndef __WIFIFW_C2H_H__
#define __WIFIFW_C2H_H__

/*--------------------------Define -------------------------------------------*/
#define C2HID_LEAUDIOBTINFORPT_LEN			7   /*c2h index : 0x46*/
#define C2HID_LEAUDIO_TDMARPT_LEN			6   /*c2h index : 0x48*/
#define C2HID_BT2WL_MAILBOX_RPT_LEN			MAILBOX_MAX_LENGTH + 1   /*c2h index 0x60 : mailbox id + mailbox content */
#define C2HID_WL2BT_MAILBOX_FAIL_RPT_LEN	MAILBOX_MAX_LENGTH + 2   /*c2h index 0x61 : mailbox id + mailbox content + fail reason */

#define _RSP_LE_AUDIO_WIFI_REQ		1
#define _RSP_LE_AUDIO_BT_RPT		2

enum c2h_pakcet_send_result {
	SEND_FAIL_BY_POLL_C2H_IDLE_TIMEOUT = 0,
	SEND_FAIL_BY_RXDMA_STOP = 1,
	SEND_SUCCESS_BY_POLL_C2H_IDLE_OK = 2,
};

/*--------------------Function declaration------------------------------*/
extern u8 wififw_c2h_pkt_send(struct c2h_evt_content *pc2h_hdr);
extern void wififw_c2h_dequeue(void);
extern void wififw_c2h_inqueue(struct c2h_evt_content *pc2h_hdr);
extern u8 wififw_c2h_check_idle(void);
extern void wififw_c2h_transmit(u8 cmd_id, u8 cmd_len, u8 *content);
#endif //__WIFIFW_C2H_H__
