#ifndef __RTW_WNM_H_
#define __RTW_WNM_H_

#define WNM_MAX_ACTION_LEN	100
#define WNM_DEFAULT_VALIDITY_TIME 6000
#define WNM_DISASSOC_TIME 5000
#define WNM_EXT_VALIDITY_TIME	4000/* for wifi test, need more validity time to wait scan done */

#define RTW_MAX_NB_RPT_NUM	16
#define RTW_ROAM_SCAN_RESULT_EXP_MS	(5*1000)

enum rtw_btm_req_mod {
	PREFERRED_CANDIDATE_LIST_INCLUDED = BIT(0),
	ABRIDGED = BIT(1),
	DISASSOC_IMMINENT = BIT(2),
	BSS_TERMINATION_INCLUDED = BIT(3),
	ESS_DISASSOC_IMMINENT = BIT(4),
};

struct btm_rpt_cache {
	/* from BTM req */
	u32 validity_time;
	u32 req_starttime;
	u8 dialog_token;
	u8 req_mode;
};

struct wnm_btm_cant {
	struct list_head  list;
	struct nb_rpt_hdr nb_rpt;
	u8 preference;	/* BSS Transition Candidate Preference */
};

struct roam_nb_info {
	struct nb_rpt_hdr nb_rpt[RTW_MAX_NB_RPT_NUM];
	struct btm_rpt_cache btm_cache;
	u8 nb_rpt_ch_list[RTW_MAX_NB_RPT_NUM];
	u8 roam_target_addr[ETH_ALEN];
	u8	nb_rpt_ch_list_num;
	u8 nb_rpt_valid : 1;
	u8 preference_en : 1;
};

struct kvr_priv_t {
	struct roam_nb_info *nb_info;
	unsigned long last_scan_time;
	u8 current_ap_bssid[6]; /*current AP bssid, mainly for BTM req&rsp process*/
	u8 target_roam_bssid[6];
	u8 self_mac[6];
	u8 roam_try_cnt; /* roaming trying times */
	u8 need_to_roam;
	u8 btm_cap_en;
#ifdef CONFIG_IEEE80211R
	struct ft_roam_info *ft_info;
	struct timer_list	ft_auth_timer;
	u32 grp_privacy;
	u8 *rsnie;
	u8 unicast_privacy;
	u8 reauth_count;
	u8 ft_peer_en : 1;
#endif
};

#endif /* __RTW_WNM_H_ */

