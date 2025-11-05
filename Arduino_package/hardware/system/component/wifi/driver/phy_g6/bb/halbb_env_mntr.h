/******************************************************************************
 *
 * Copyright(c) 2007 - 2020  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/
#ifndef __HALBB_ENV_MNTR_H__
#define __HALBB_ENV_MNTR_H__
#ifdef HALBB_ENV_MNTR_SUPPORT

/*--------------------------[Define] ---------------------------------------*/
#define ENV_MNTR_FAIL_BYTE		0xff
#define ENV_MNTR_FAIL_WORD		0xffff
#define ENV_MNTR_FAIL_DWORD	0xffffffff
#define MAX_ENV_MNTR_TIME		2	/*second*/
#define MS_TO_4US_RATIO		250

#ifdef NHM_SUPPORT
/*NHM*/
#define RSSI_2_NHM_TH(rssi)	((rssi) << 1) /*NHM_threshold = u(8,1)*/
#define NHM_TH_2_RSSI(th)		(th >> 1)
#define NHM_PWR_OFST		20
#define NHM_NOISE_F_TH		60	/*60/2 = 30 = -80 dBm*/
#define NHM_WA_TH			109	/*109 = -1 dBm*/
#define NHM_WA_PWR		26 /*26 - 110 = -84dBm, only for 52A*/
#define	NHM_TH_NUM		11	/*threshold number of NHM*/
#define	NHM_RPT_NUM		12
#endif

#ifdef FAHM_SUPPORT
/*FAHM*/
#define RSSI_2_FAHM_TH(rssi)	((rssi) << 1) /*FAHM_threshold = u(8,1)*/
#define FAHM_TH_2_RSSI(th)		(th >> 1)
#define FAHM_PWR_OFST		20
#define FAHM_WA_TH		109	/*109 = -1 dBm*/
#define FAHM_INCLU_FA		BIT(0)
#define FAHM_INCLU_CRC_OK		BIT(1)
#define FAHM_INCLU_CRC_ERR		BIT(2)
#define FAHM_TH_NUM		11	/*threshold number of FAHM*/
#define FAHM_RPT_NUM		12
#endif

#ifdef IFS_CLM_SUPPORT
/*IFS-CLM*/
#define	IFS_CLM_NUM		4
#endif

/*--------------------------[Enum]------------------------------------------*/
enum ccx_unit {
	CCX_04_US		= 0,	/*4us*/
	CCX_08_US		= 1,	/*8us*/
	CCX_16_US		= 2,	/*16us*/
	CCX_32_US		= 3	/*32us*/
};

enum ccx_edcca_opt_bw_idx {
	CCX_EDCCA_BW20_0	= 0,	/*seg0:SC=4*/
	CCX_EDCCA_BW20_1	= 1,	/*seg0:SC=2*/
	CCX_EDCCA_BW20_2	= 2,	/*seg0:SC=1*/
	CCX_EDCCA_BW20_3	= 3,	/*seg0:SC=3*/
	CCX_EDCCA_BW20_4	= 4,	/*seg1:SC=4*/
	CCX_EDCCA_BW20_5	= 5,	/*seg1:SC=2*/
	CCX_EDCCA_BW20_6	= 6,	/*seg1:SC=1*/
	CCX_EDCCA_BW20_7	= 7	/*seg2:SC=3*/
};

enum mntr_result_lv {
	CCX_FAIL		= 0,
	NHM_SUCCESS		= BIT(0),
	CLM_SUCCESS		= BIT(1),
	IFS_CLM_SUCCESS		= BIT(2),
	EDCCA_CLM_SUCCESS		= BIT(3),
	CCX_SUCCESS		= 0xf, /*exclude FAHM*/
};

enum halbb_racing_lv {
	RAC_RELEASE		= 0,
	RAC_LV_1		= 1,	/* Low Priority function */
	RAC_LV_2		= 2,	/* Middle Priority function */
	RAC_LV_3		= 3,	/* High priority function (ex: Check hang function) */
	RAC_LV_4		= 4,	/* Debug function (the highest priority) */
	RAC_MAX_NUM		= 5
};

enum ccx_edcca_opt_sc_idx {
	CCX_EDCCA_SEG0_P0	= 0,	/*seg0:p20*/
	CCX_EDCCA_SEG0_S1	= 1,	/*seg0:s20*/
	CCX_EDCCA_SEG0_S2	= 2,	/*seg0:s40, opposite of p20*/
	CCX_EDCCA_SEG0_S3	= 3,	/*seg0:s40, opposite of s20*/
	CCX_EDCCA_SEG1_P0	= 4,	/*seg1:p20*/
	CCX_EDCCA_SEG1_S1	= 5,	/*seg1:s20*/
	CCX_EDCCA_SEG1_S2	= 6,	/*seg1:s40, opposite of p20*/
	CCX_EDCCA_SEG1_S3	= 7	/*seg1:s40, opposite of s20*/
};

#ifdef FAHM_SUPPORT
enum fahm_application {
	FAHM_INIT		= 0,
	FAHM_BACKGROUND		= 1, /*IEEE 11K for background*/
	FAHM_DIG			= 2,
	FAHM_TDMA_DIG		= 3,
	FAHM_DBG_11K		= 4, /*IEEE 11K for dbg cmd*/
	FAHM_DBG_RSSI		= 5, /*fahm_th[0]=rssi-20, th_ofst=3dB*/
	FAHM_DBG_MANUAL		= 6 /*fahm_th[0] & th_ofst is manual*/
};
#endif

#ifdef CLM_SUPPORT
enum clm_opt_input {
	CLM_CCA_P20		= 0,
	CLM_CCA_S20		= 1,
	CLM_CCA_S40		= 2,
	CLM_CCA_S80		= 3,
	CLM_FROM_DBG		= 4,
	CLM_TXON_CCA		= 5,
	CLM_CCA_S80_S40_S20	= 6,
	CLM_CCA_S80_S40_S20_P20	= 7,
	CLM_CCA_INIT
};

enum clm_idmatch_input {
	CLM_IDMATCH_OFF		= 0,
	CLM_IDMATCH_ON		= 1,
	CLM_IDMATCH_INIT
};

enum clm_application {
	CLM_INIT		= 0,
	CLM_BACKGROUND		= 1,/*default*/
	CLM_ACS			= 2,
	CLM_DBG			= 3
};
#endif

#ifdef NHM_SUPPORT
enum nhm_option_cca_all {
	NHM_EXCLUDE_CCA		= 0,
	NHM_INCLUDE_CCA		= 1,
	NHM_CCA_INIT
};

enum nhm_idmatch_input {
	NHM_IDMATCH_OFF		= 0,
	NHM_IDMATCH_ON		= 1,
	NHM_IDMATCH_INIT
};

enum nhm_application {
	NHM_INIT		= 0,
	NHM_BACKGROUND		= 1, /*IEEE 11K for background*/
	NHM_ACS			= 2,
	NHM_DBG_11K		= 3, /*IEEE 11K for dbg cmd*/
	NHM_DBG_RSSI		= 4, /*nhm_th[0]=rssi-20, th_ofst=3dB*/
	NHM_DBG_MANUAL		= 5 /*nhm_th[0] & th_ofst is manual*/
};
#endif

#ifdef IFS_CLM_SUPPORT
enum ifs_clm_application {
	IFS_CLM_INIT		= 0,
	IFS_CLM_BACKGROUND	= 1,/*default*/
	IFS_CLM_ACS		= 2,
	IFS_CLM_DBG		= 3,
	IFS_CLM_DBG_MANUAL	= 4
};
#endif

#ifdef EDCCA_CLM_SUPPORT
enum edcca_clm_application {
	EDCCA_CLM_INIT		= 0,
	EDCCA_CLM_BACKGROUND	= 1,/*default*/
	EDCCA_CLM_ACS		= 2,
	EDCCA_CLM_DBG		= 3
};
#endif
/*--------------------------[Structure]-------------------------------------*/

struct env_trig_rpt {
	u8			ccx_rpt_stamp;
};

struct env_mntr_rpt {
	u8			ccx_rpt_stamp;
#ifdef CLM_SUPPORT
	u8			clm_ratio; /*percent*/
	u16			clm_result; /*sample cnt*/
#endif
#ifdef NHM_SUPPORT
	u8			nhm_rpt[NHM_RPT_NUM]; /*percent*/
	u8			nhm_ratio; /*percent*/
	u8			nhm_tx_ratio; /*percent*/
	u8			nhm_cca_ratio; /*percent*/
	u8			nhm_idle_ratio; /*percent*/
	u16			nhm_tx_cnt; /*sample cnt*/
	u16			nhm_cca_cnt; /*sample cnt*/
	u16			nhm_idle_cnt; /*sample cnt*/
	u8			nhm_pwr_0p5; /*110+x/2(dBm), unit = 0.5dB*/
#endif
#ifdef IFS_CLM_SUPPORT
	u8			ifs_clm_tx_ratio; /*percent*/
	u8			ifs_clm_edcca_excl_cca_ratio; /*percent*/
	u8			ifs_clm_cck_fa_ratio; /*percent*/
	u8			ifs_clm_ofdm_fa_ratio; /*percent*/
	u8			ifs_clm_cck_cca_excl_fa_ratio; /*percent*/
	u8			ifs_clm_ofdm_cca_excl_fa_ratio; /*percent*/
	u16			ifs_clm_cck_fa_permil; /*permil*/
	u16			ifs_clm_ofdm_fa_permil; /*permil*/
	u16			ifs_clm_total_ifs; /*cnt*/
	u16			ifs_clm_his[IFS_CLM_NUM]; /*cnt*/
	u32			ifs_clm_ifs_avg[IFS_CLM_NUM]; /*us*/
	u32			ifs_clm_cca_avg[IFS_CLM_NUM]; /*us*/
#endif
#ifdef EDCCA_CLM_SUPPORT
	u8			edcca_clm_ratio; /*percent*/
#endif
};

struct ccx_para_info {
	enum halbb_racing_lv		rac_lv;
	u16				mntr_time;	/*0~2097ms*/
	enum ccx_edcca_opt_sc_idx	ccx_edcca_opt_sc_idx;
#ifdef CLM_SUPPORT
	enum clm_application		clm_app;
	enum clm_opt_input		clm_input_opt;
	enum clm_idmatch_input  clm_input_idmatch;
#endif
#ifdef NHM_SUPPORT
	enum nhm_application		nhm_app;
	u8				nhm_manual_th_ofst;
	u8				nhm_manual_th0;	/*dbg manual mode*/
	enum nhm_option_cca_all		nhm_incld_cca; /*Include CCA*/
	enum nhm_idmatch_input  nhm_input_idmatch; /*nhm macid match*/
#endif
#ifdef IFS_CLM_SUPPORT
	enum ifs_clm_application	ifs_clm_app;
	u32				ifs_clm_manual_th_times;
	u32				ifs_clm_manual_th0;/*us*/
#endif
#ifdef EDCCA_CLM_SUPPORT
	enum edcca_clm_application	edcca_clm_app;
#endif
};

#ifdef FAHM_SUPPORT
struct fahm_trig_report {
	u8			fahm_rpt_stamp;
};

struct fahm_para_info {
	enum halbb_racing_lv		fahm_rac_lv;
	u16				fahm_mntr_time;	/*0~2097ms*/
	enum fahm_application		fahm_app;
	u8				fahm_manual_th_ofst;
	u8				fahm_manual_th0; /*dbg manual mode*/
	u8				fahm_numer_opt;
	u8				fahm_denom_opt;
};

struct fahm_report {
	u8			fahm_rpt_stamp;
	bool			fahm_rpt_result;
	u8			fahm_rpt[FAHM_RPT_NUM]; /*percent*/
	u8			fahm_ratio; /*percent*/
	u8			fahm_denom_ratio; /*percent*/
	u16			fahm_permil; /*permil*/
	u16			fahm_denom_permil; /*permil*/
	u8			fahm_pwr; /*110+x(dBm), unit = 1dB*/
	u8			fahm_pwr_0p5; /*110+x/2(dBm), unit = 0.5dB*/
};
#endif

struct bb_env_mntr_info {
	/*sw ctrl*/
	u32			ccx_trigger_time;
	u8			ccx_rpt_stamp;
	u8			ccx_watchdog_result;
	u8			ccx_watchdog_channel;
	u8			ccx_chk_result;
	bool		ccx_ongoing;
	u8			ccx_rac_lv;
	bool		ccx_manual_ctrl;

	/*hw ctrl*/
	u16			ccx_period;
	u8			ccx_unit_idx;
	enum ccx_edcca_opt_bw_idx	ccx_edcca_opt_bw_idx;

#ifdef EDCCA_CLM_SUPPORT
	enum edcca_clm_application	edcca_clm_app;
	u16 		edcca_clm_mntr_time; /*0~2097 ms*/
	/*hw report*/
	u16 		edcca_clm_result; /*sample cnt*/
	/*sw report*/
	u8			edcca_clm_ratio; /*percent*/
	u8			edcca_noise_bg; /*dBm+110, only for 52A*/
#endif

#ifdef FAHM_SUPPORT
	enum fahm_application		fahm_app;

	u32 		fahm_trigger_time;
	u8			fahm_rpt_stamp;
	bool		fahm_watchdog_result;
	bool		fahm_ongoing;
	u8			fahm_rac_lv;
	bool		fahm_manual_ctrl;
	u8			fahm_pre_rssi;
	u16			fahm_mntr_time; /*0~2097 ms*/
	u16			fahm_period;
	u8			fahm_numer_opt;
	u8			fahm_denom_opt;
	u8			fahm_th[FAHM_TH_NUM];
	/*hw report*/
	u16			fahm_result[FAHM_RPT_NUM]; /*sample cnt*/
	u16			fahm_denom_result; /*sample cnt*/

	/*sw report*/
	u16			fahm_sw_result[FAHM_RPT_NUM]; /*sample cnt*/
	u8			fahm_wgt[FAHM_RPT_NUM]; /*dBm+110*/
	u8			fahm_rpt[FAHM_RPT_NUM]; /*percent*/
	u16			fahm_result_sum; /*sample cnt*/
	u8			fahm_ratio; /*percent*/
	u8			fahm_denom_ratio; /*percent*/
	u16			fahm_permil; /*permil*/
	u16			fahm_denom_permil; /*permil*/
	u8			fahm_pwr; /*110+x => dBm, unit = 1dB*/
	u8			fahm_pwr_0p5; /*110+x/2 => dBm, unit = 0.5dB*/
	struct fahm_report	fahm_report_bg;
	struct fahm_para_info	fahm_para_info_bg;
#endif

#ifdef CLM_SUPPORT
	enum clm_opt_input		clm_input_opt;
	enum clm_idmatch_input	clm_input_idmatch;
	enum clm_application		clm_app;

	u16			clm_mntr_time; /*0~2097 ms*/
	/*hw report*/
	u16			clm_result; /*sample cnt*/

	/*sw report*/
	u8			clm_ratio; /*percent*/
#endif

#ifdef NHM_SUPPORT
	enum nhm_application		nhm_app;
	enum nhm_option_cca_all	nhm_include_cca;
	enum nhm_idmatch_input  nhm_input_idmatch;
	u16			nhm_mntr_time; /*0~2097 ms*/
	u8			nhm_pre_rssi;
	u8			nhm_th[NHM_TH_NUM];
	/*hw report*/
	u16			nhm_result[NHM_RPT_NUM]; /*sample cnt*/
	u16			nhm_tx_cnt; /*sample cnt*/
	u16			nhm_cca_cnt; /*sample cnt*/
	u16			nhm_idle_cnt; /*sample cnt*/

	/*sw report*/
	u8			nhm_rpt[NHM_RPT_NUM]; /*percent*/
	u8			nhm_tx_ratio; /*percent*/
	u8			nhm_cca_ratio; /*percent*/
	u8			nhm_idle_ratio; /*percent*/
	u8			nhm_ratio; /*percent*/
	u8			nhm_pwr_0p5; /*110+x/2 => dBm, unit = 0.5dB*/
#endif

#ifdef IFS_CLM_SUPPORT
	enum ifs_clm_application	ifs_clm_app;
	u16			ifs_clm_mntr_time; /*0~2097 ms*/
	u16			ifs_clm_th_l[IFS_CLM_NUM];
	u16			ifs_clm_th_h[IFS_CLM_NUM];
	/*hw report*/
	u16			ifs_clm_tx; /*sample cnt*/
	u16			ifs_clm_edcca_excl_cca; /*sample cnt*/
	u16			ifs_clm_ofdmfa; /*sample cnt*/
	u16			ifs_clm_ofdmcca_excl_fa; /*sample cnt*/
	u16			ifs_clm_cckfa; /*sample cnt*/
	u16			ifs_clm_cckcca_excl_fa; /*sample cnt*/
	u16			ifs_clm_total_ifs; /*cnt*/
	u16			ifs_clm_his[IFS_CLM_NUM]; /*cnt*/
	u16			ifs_clm_avg[IFS_CLM_NUM]; /*sample cnt*/
	u16			ifs_clm_cca[IFS_CLM_NUM]; /*sample cnt*/
	/*sw report*/
	u8			ifs_clm_tx_ratio; /*percent*/
	u8			ifs_clm_edcca_excl_cca_ratio; /*percent*/
	u8			ifs_clm_cck_fa_ratio; /*percent*/
	u8			ifs_clm_ofdm_fa_ratio; /*percent*/
	u8			ifs_clm_cck_cca_excl_fa_ratio; /*percent*/
	u8			ifs_clm_ofdm_cca_excl_fa_ratio; /*percent*/
	u16			ifs_clm_cck_fa_permil; /*permil*/
	u16			ifs_clm_ofdm_fa_permil; /*permil*/
	u32			ifs_clm_ifs_avg[IFS_CLM_NUM]; /*us*/
	u32			ifs_clm_cca_avg[IFS_CLM_NUM]; /*us*/
#endif


	/*sw report*/
	struct env_mntr_rpt	env_mntr_rpt_bg;
	struct ccx_para_info	ccx_para_info_bg;
	u16			idle_pwr_physts; /*RSSI u(16,3) Idle time pwr from physts*/
};

/*--------------------------[Prptotype]-------------------------------------*/

#ifdef CLM_SUPPORT
bool halbb_clm_get_result(void);
int halbb_clm_set(struct ccx_para_info *para);
void halbb_clm_init(void);
void halbb_clm_dbg(char input[][16], u32 *_used, char *output, u32 *_out_len);
#endif

#ifdef NHM_SUPPORT
bool halbb_nhm_get_result(void);
int halbb_nhm_set(struct ccx_para_info *para);
void halbb_nhm_init(void);
void halbb_nhm_dbg(char input[][16], u32 *_used, char *output, u32 *_out_len);
#endif

#ifdef IFS_CLM_SUPPORT
bool halbb_ifs_clm_get_result(void);
int halbb_ifs_clm_set(struct ccx_para_info *para);
void halbb_ifs_clm_init(void);
void halbb_ifs_clm_dbg(char input[][16], u32 *_used, char *output, u32 *_out_len);
#endif

#ifdef FAHM_SUPPORT
bool halbb_fahm_trigger(struct fahm_para_info *para, struct fahm_trig_report *trig_rpt);
bool halbb_fahm_result(struct fahm_report *rpt);
void halbb_fahm_init(void);
void halbb_fahm_dbg(char input[][16], u32 *_used, char *output, u32 *_out_len);
#endif

#ifdef EDCCA_CLM_SUPPORT
bool halbb_edcca_clm_get_result(void);
int halbb_edcca_clm_set(struct ccx_para_info *para);
void halbb_edcca_clm_init(void);
void halbb_edcca_clm_dbg(char input[][16], u32 *_used, char *output, u32 *_out_len);
#endif

void halbb_ccx_query_clm_info(union rtw_phy_stats *phy_stats);
u16 halbb_ccx_get_ratio(u16 rpt, u16 score);
void halbb_ccx_ms_2_period_unit(u16 time_ms, u32 *period, u32 *unit_idx);
u32 halbb_ccx_idx_cnt_2_us(u16 idx_cnt);
u16 halbb_ccx_us_2_idx_cnt(u32 time_us);
void halbb_ccx_racing_release(void);
int halbb_ccx_racing_ctrl(enum halbb_racing_lv rac_lv);
void halbb_ccx_trigger(void);
void halbb_env_mntr_log(u32 dbg_comp);
void halbb_idle_time_pwr_physts(bool is_cck_rate);
void halbb_env_mntr(void);
void halbb_env_mntr_init(void);
void halbb_env_mntr_dbg(char input[][16], u32 *_used, char *output, u32 *_out_len);

void halbb_env_mntr_get_bg_result(struct env_mntr_rpt *bg_rpt);
void halbb_env_mntr_get_bg_setting(struct ccx_para_info *bg_para);
u8 halbb_env_mntr_trigger(struct ccx_para_info *para, struct env_trig_rpt *trig_rpt);
u8 halbb_env_mntr_result(struct env_mntr_rpt *rpt);

#endif/*HALBB_ENV_MNTR_SUPPORT*/

#endif
