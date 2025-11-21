#ifndef __WIFIFW_PS_TWT_COMMON_H__
#define __WIFIFW_PS_TWT_COMMON_H__

/*--------------------Define MACRO--------------------------------------*/
#define ITWTCLIENTNUM						3
#define ITWTBCNMISSMAXTIME					0x9C4000//us
#define ITWTKEEPALIVEINTERVAL				0x3A98000//us

enum ITWTCLT {
	ITWTCLIENTA               = 0x0,
	ITWTCLIENTB               = 0x1,
	ITWTCLIENTC               = 0x2,
};

struct ITWTCLIENT_PARM {
	u32		FLOW_ID				: 2;	//B1
	u32		TWT_En				: 1;
	u32		TRIGGER_En			: 1;
	u32		ANNOUNCED			: 1;
	u32		W0Rsvd0				: 11;
	u32		DURATION			: 16;	//B2
	u32		INTERVAL;					//B4

	u32		TWTIME_H;
	u32		TWTIME_L;
	u8		TXPAUSE: 1;
	u8		SPSTARTFLAG: 1;
	u8		rsvd: 6;
	u8		TWTEarly;
} ;

struct LPS_ITWT_PARM {
	struct ITWTCLIENT_PARM ITWTCLIENT[ITWTCLIENTNUM];
	u32		TWTTSFRxBcn;
	u8		TWTVALID;
	u8		TWTBCNTo;
} ;

/*------------------------------Function declaration--------------------------*/
extern const char *TAG_FW_ITWT;
extern bool wififw_twt_no_client_enable(void);
extern bool wififw_twt_check_client_sp_end(void);
extern void wififw_twt_sp_target_time_update(u8 clientnum);
extern void  wififw_twt_sp_work(bool ITWTSTART);
extern void wififw_twt_sp_rx_data(void);
extern void wififw_twt_client_set(u8 clientnum);
extern void wififw_twt_sp_ely_handle(u8 clinetnum);
extern void wififw_twt_sp_handle(u8 clinetnum);
extern void wififw_twt_sp_end_handle(u8 clinetnum);
extern void wififw_h2c_lps_itwt_info1(struct h2c_itwtinfo1 *pbuf);
extern void wififw_h2c_lps_itwt_info2(struct h2c_itwtinfo2 *pbuf);
extern void wififw_h2c_lps_itwt_info3(struct h2c_itwtinfo3 *pbuf);

#endif  /* __WIFIFW_PS_TWT_COMMON_H__ */