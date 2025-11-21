#ifndef __WIFIFW_CSI_COMMON_H__
#define __WIFIFW_CSI_COMMON_H__

/*--------------------Define MACRO--------------------------------------*/
#define CSICLIENTNUM		0x5
#define RTY_LMT_SW_CSITXDATA					3
#define RTY_LMT_HW_CSITXDATA					0

#define INTERRUPTDELAY		0x6
#define CSIMUTIPLETIME		10
#if defined(CONFIG_AMEBALITE) || defined(CONFIG_AMEBASMART) || defined(CONFIG_AMEBAGREEN2) || defined(CONFIG_AMEBAPRO3) || defined(CONFIG_AMEBASMARTPLUS)
#define CSIRACTRLINFOFFSET  0x20
#elif defined (CONFIG_AMEBADPLUS)
#define CSIRACTRLINFOFFSET  0x10
#elif defined (CONFIG_AMEBAL2)
#define CSIRACTRLINFOFFSET  0x0
#else
#define CSIRACTRLINFOFFSET  0x0
#endif

enum CSI_TYPE {
	CSI_TYPE_UNICAST_TX = 0,
	CSI_TYPE_BROADCAST_TX,
};

struct CSI_Tx_Parm {
	u32		Enable: 1;
	u32 	CSIWorkType: 1;
	u32		Is_SoftAP: 1;
	u32		CSITxBW: 1;
	u32 	Macid: 4;
	u32		CSITxRate: 9;
	u32		TxPeriod: 8;
	u32		rsvd: 2;
	u32		CSITxCycleOn: 1;
	u32		CSITxretrycnt: 4;
	u8		TxRecvAddr[6];
};

struct CSI_Report_Parm {
	u8 		CSIWorkEn;
	u8 		CSITxPeriod;
	struct CSI_Tx_Parm CSITxParm[CSICLIENTNUM];
};

/*------------------------------Function declaration--------------------------*/
extern const char *TAG_FW_CSI;
extern bool wififw_csi_check_csitx_done(void);
extern bool wififw_csi_no_client_enable(void);
extern void wififw_csi_client_disable(u8 clientnum);
extern void wififw_csi_check_next_client(u8 clientnum);
extern void wififw_csi_check_csitx_retry(u8 clientnum, u8 txstate);
extern void wififw_csi_client_enable(struct h2c_csi_report *pbuf, u8 clientnum);
extern void wififw_csi_tx_period_update(void);
extern void wififw_csi_halbb_reset(void);
extern void wififw_csi_period_worktx(u8 clientnum);
extern void wififw_h2c_csi_report(struct h2c_csi_report *pbuf);
extern void wififw_csi_period_timer_handle(void);

#endif  /* #ifndef   __WIFIFW_CSI_COMMON_H__ */
