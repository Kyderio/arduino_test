#ifndef __WIFIFW_H2C_COMMON_H__
#define __WIFIFW_H2C_COMMON_H__

/*--------------------Define --------------------------------------------*/
// HMETFR
#define H2CINTBOX_BITMASK				0xF
#define H2CINTBOX_NUMMASK				0x3

//RXDEC
#define BIT_MASK_RXDEC_LENGTH		0x3FFF
#define BIT_RXDEC_C2HINDEX    		BIT4

// H2C
#define LENGTH_H2C						8
#define LENGTH_H2C_CMD_HDR			sizeof(struct H2C_CMD_HDR)
#define LENGTH_H2C_CONTENT			(LENGTH_H2C -LENGTH_H2C_CMD_HDR)
#define ADOPT_H2C_VALUE				BIT7
#define LENGTH_H2C_BUFF				10
#define H2C_Q_FULL(x, y)				(((((x) == 0) && ((y) == (LENGTH_H2C_BUFF - 1)))||((y) == ((x) - 1))) ? TRUE : FALSE)
#define H2C_Q_EMPTY(x, y)				(((x) == (y)) ? TRUE : FALSE)
#define H2CPTR_REACH_BOTTOM(x)		(((x) == LENGTH_H2C_BUFF) ? TRUE : FALSE)

// C2H
#define LENGTH_C2H						16
#define LENGTH_C2H_EVT_HDR			2
#define LENGTH_C2H_LEN_FIELD			1
#define LENGTH_C2H_SYNC				1
#define LENGTH_C2H_CONTENT 			(LENGTH_C2H - LENGTH_C2H_EVT_HDR - LENGTH_C2H_LEN_FIELD - LENGTH_C2H_SYNC)
#define LENGTH_C2H_BUFF				8
#define WAIT_C2H_CHECK_CNT 			(10) //ms
#define C2H_DATA_RDY					0xFF
#define C2HPTR_REACH_BOTTOM(x)		(((x) == LENGTH_C2H_BUFF) ? TRUE : FALSE)
#define C2H_Q_EMPTY(x, y)				(((x) == (y)) ? TRUE : FALSE)
#define C2H_Q_FULL(x, y)				(((((x) == 0) && ((y) == (LENGTH_C2H_BUFF - 1)))||((y) == ((x) - 1))) ? TRUE : FALSE)

#define MACID_NUM_NEW					(MACID_NUM/8)

/*--------------------Define Struct---------------------------------------*/
struct H2C_EVT_CONTENT {
	u8		Content[LENGTH_H2C];
};

struct H2C_EVT {
	struct H2C_EVT_CONTENT    h2c_buff[LENGTH_H2C_BUFF];
	u8		h2c_r_ptr;
	u8		h2c_w_ptr;
	u8		h2c_index;
};

struct C2H_EVT {
	struct c2h_evt_content    c2h_buff[LENGTH_C2H_BUFF];
	u8		c2h_r_ptr;
	u8		c2h_w_ptr;
};

struct MEDIA_STATUS {
	u8	bConnected[MACID_NUM_NEW];
	u8		MaxConnectedMacid;
};

/*------------------------------Define Struct---------------------------------*/
//H2C command format
struct H2C_CMD_HDR {
	u8 cmd_id;
};

/*--------------------Function declaration---------------------------------*/
extern u8 wififw_get_h2c_valid_index(void);
extern void wififw_get_h2c_message(void);
extern void wififw_update_h2c_pointer(u8 msgbox_index);
extern void wififw_h2c_c2h_init(void);
extern void wififw_h2c_inqueue(void);
extern void wififw_h2c_dequeue(void);
extern void wififw_h2c_rsvd_page_location(struct h2c_rsvdpage *pbuf);
extern void wififw_h2c_set_pwr_mode(struct h2c_pwrsave *pbuf);
extern void wififw_h2c_fw_dbg(u8  *pbuf);
extern void wififw_h2c_cmd_func(u8 *content);
#endif
