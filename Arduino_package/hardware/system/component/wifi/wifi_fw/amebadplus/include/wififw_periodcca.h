#ifndef _WIFIFW_PERIODCCA_H_
#define _WIFIFW_PERIODCCA_H_

#define FCS_LEN             4
#define IGI_PERIOD_CCA_ADD  16//for narrower range of RSSI reception to avoid misjudgment

enum TYPE_PERIODCCA_STATUS {
	PERIODCCA_ENTER = 0,
	PERIODCCA_EXIT = 1,
};

extern void wififw_ps_periodcca(bool on);
extern void wififw_lpsofld_macperiodcca_enter_flow_init(u32 StartPosition);
extern void wififw_ps_periodcca_init(void);
extern void wififw_ps_macperiodcca_exit(void);
extern void wififw_periodcca_bb_parm_set(u8 periodcca_status, u8 bb_parameter_set);
extern void wififw_bbgain_idx_backup(void);
#endif