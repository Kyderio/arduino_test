#ifdef _RTW_ADAPTER_DEFINED_H_
#ifndef _RTW_CORE_FUNCTION_H_
#define _RTW_CORE_FUNCTION_H_

/*-------------------------------------------------------------------------------
	rtw_recv.c.
--------------------------------------------------------------------------------*/
int rtw_recv_init_priv(uint8_t defrag_en);
void rtw_recv_free_priv(void);
union recv_frame *rtw_recv_alloc_frame(struct __queue *pfree_recv_queue);
int rtw_recv_free_frame(union recv_frame *precvframe, struct __queue *pfree_recv_queue);
void rtw_recv_free_frame_queue(struct __queue *pframequeue,  struct __queue *pfree_recv_queue);
int rtw_recv_frame_chkmic(u8 iface_type,  struct security_priv *psecuritypriv, union recv_frame *precvframe);
int rtw_recv_frame_chkpn(struct security_priv *psecuritypriv, union recv_frame *precvframe);
union recv_frame *rtw_recv_decryptor(u8 iface_type, struct security_priv *psecuritypriv, union recv_frame *precv_frame);
void rtw_recv_count_rx_stats(struct net_device_stats *pstats, union recv_frame *prframe, struct sta_mlme_priv *psta_mlmepriv);
struct sta_mlme_priv *rtw_recv_sta2sta_data_frame(u8 iface_type, union recv_frame *precv_frame);
struct sta_mlme_priv *rtw_recv_ap2sta_data_frame(u8 iface_type, union recv_frame *precv_frame, u8 bCheckDestAddress);
struct sta_mlme_priv *rtw_recv_sta2ap_data_frame(u8 iface_type, union recv_frame *precv_frame, struct net_device_stats *pstats);
void rtw_recv_validate_ctrl_frame(u8 iface_type, union recv_frame *precv_frame);
void rtw_recv_validate_mgnt_frame(u8 iface_type, union recv_frame **pprecv_frame);
int rtw_recv_validate_data_frame(u8 iface_type, struct net_device_stats *pstats, union recv_frame *precv_frame, u8 bCheckDestAddress);
int rtw_recv_validate_frame(u8 iface_type, struct net_device_stats *pstats, union recv_frame **pprecv_frame, u8 bCheckDestAddress);
int rtw_recv_wlanhdr_to_ethhdr(union recv_frame *precvframe);
int rtw_recv_indicatepkt(u8 iface_type, union recv_frame *precv_frame);
int rtw_recv_process_indicatepkts(u8 iface_type, union recv_frame *prframe);
int rtw_recv_func_prehandle(u8 iface_type, struct net_device_stats *pstats, union recv_frame *rframe, u8 bCheckDestAddress);
int rtw_recv_func_posthandle(u8 iface_type, struct net_device_stats *pstats, union recv_frame *prframe);
int rtw_recv_entry(union recv_frame *precvframe);
u8 *rtw_recv_get_recvframe_data(union recv_frame *precvframe);
u8 *rtw_recv_recvframe_pull(union recv_frame *precvframe, sint sz);
u8 *rtw_recv_recvframe_put(union recv_frame *precvframe, sint sz);
u8 *rtw_recv_recvframe_pull_tail(union recv_frame *precvframe, sint sz);

/*-------------------------------------------------------------------------------
	rtw_recv_reorder.c.
--------------------------------------------------------------------------------*/
int rtw_recv_reorder(void *preorder_per_tid);
int rtw_recv_reorder_dequeue(struct recv_reorder_ctrl *preorder_ctrl, int bforced);
void rtw_recv_reorder_timer_hdl(void *FunctionContext);
struct recv_reorder_ctrl *rtw_recv_reorder_alloc(u8 ap_compatibilty, u8 iface_type);
void rtw_recv_reorder_free(struct recv_reorder_ctrl **ppreorder_ctrl);

/*-------------------------------------------------------------------------------
	rtw_recv_defrag.c.
--------------------------------------------------------------------------------*/
#ifdef CONFIG_FRAME_DEFRAG
union recv_frame *rtw_recv_frame_check_defrag(u8 iface_type, struct security_priv *psecuritypriv, union recv_frame *precv_frame);
void rtw_defrag_timer_handler(void *FunctionContext);
void rtw_init_defrag_timer(struct sta_recv_priv *psta_recvpriv);
void rtw_defrag_ctrl_deinit(struct recv_defrag_ctrl *pdefrag_ctrl);
#endif

/*-------------------------------------------------------------------------------
	rtw_xmit.c.
--------------------------------------------------------------------------------*/
int	rtw_xmit_priv_init(u32 xmitframe_num);
void rtw_xmit_priv_free(void);
void rtw_xmit_open_pktfile(struct sk_buff *pktptr, struct pkt_file *pfile);
u32 rtw_xmit_read_pktfile(struct pkt_file *pfile, u8 *rmem, u32 rlen);
int rtw_xmit_enc_tkip_addmic(struct security_priv *psecuritypriv, struct sk_buff *pkt, struct sta_security_priv	*psta_security, u16 length);
int rtw_xmit_enc_software(u8 iface_type, struct security_priv *psecuritypriv, struct xmit_frame *pxmitframe);
int rtw_xmit_make_wlanhdr(u8 iface_type, u8 *hdr, struct pkt_attrib *pattrib);
s32 rtw_xmit_pending_queue_check(struct hw_xmit *pendingqueue, int prio);
void rtw_xmit_update_attrib_vcs_info(u8 iface_type, struct xmit_frame *pxmitframe, struct sta_mlme_priv *psta_mlmepriv, u8 f_cts2self);
s32 rtw_xmit_put_snap(u8 *data, u16 h_proto);
void rtw_xmit_count_stats(u8 iface_type, struct net_device_stats *pstats, struct xmit_frame *pxmitframe, int sz);
int rtw_xmit_mgntframe(u8 iface_type, struct xmit_frame *pmgntframe);
int rtw_xmit_entry(struct sk_buff *pkt, struct net_device *pnetdev);
void rtw_xmit_nulldata(u8 iface_type, unsigned int power_mode);
void rtw_xmit_qos_nulldata(u8 iface_type, unsigned char *da, u16 tid);
int rtw_xmit_cts2self(u8 iface_type, u16 duration, u8 *mac_addr);
s32 rtw_txframes_pending(u8 iface_type);
s32 rtw_xmit_pending_queue_check_all(struct hw_xmit *pendingqueue);
u8 rtw_xmit_update_attrib_qos_acm(u8 acm_mask, u8 priority);
void rtw_xmit_update_attrib_set_qos(struct pkt_file *ppktfile, struct pkt_attrib *pattrib);
void rtw_xmit_update_attrib_phy_info(struct pkt_attrib *pattrib, struct sta_mlme_priv *psta_mlmepriv, u8 wifi_speaker_en, u8 bw_40_en);
int rtw_xmit_update_attrib_sec_info(struct security_priv *psecuritypriv, struct pkt_attrib *pattrib, struct sta_security_priv *psta_security);
#ifdef CONFIG_NAN
void rtw_xmit_make_wlanhdr_nanaddr(struct rtw_ieee80211_hdr	*pwlanhdr, struct pkt_attrib *pattrib);
#endif
int rtw_xmit_update_attrib_raw(u8 iface_type, struct sk_buff *pkt, struct pkt_attrib *pattrib, u8 type, u8 wifi_speaker_feature, u8 bw_40_enable);

/*-------------------------------------------------------------------------------
	rtw_xmitbuff.c.
--------------------------------------------------------------------------------*/
struct xmit_frame *rtw_xmitframe_alloc(u8 iface_type);
int rtw_xmitframe_free(struct xmit_frame *pxmitframe);
/*-------------------------------------------------------------------------------
	rtw_shortcut.c.
--------------------------------------------------------------------------------*/
#ifdef RX_SHORTCUT
int rtw_recv_get_rx_sc_index(unsigned char *hdr);
int rtw_recv_get_rx_sc_free_entry(unsigned char *hdr);
int rtw_recv_indicatepkt_sc(struct net_device_stats *padapter_stats, union recv_frame *precv_frame, struct sta_mlme_priv *psta_mlmepriv, int idx);
int rtw_recv_check_rx_shortcut_path(u8 iface_type, struct net_device_stats *padapter_stats, u32 dot11PrivacyAlgrthm, union recv_frame *precv_frame);
#endif // RX_SHORTCUT
#ifdef TX_SHORTCUT
int rtw_get_tx_sc_index(struct sta_sc_priv *psta_scpriv, unsigned char *hdr);
int rtw_get_tx_sc_free_entry(struct sta_sc_priv *psta_scpriv, unsigned char *hdr);
s32 rtw_xmit_entry_sc(u8 iface_type, struct sk_buff *pkt);
void rtw_set_tx_sc_entry(u8 iface_type, struct sta_sc_priv *psta_scpriv, struct pkt_attrib *pattrib, u8 *ptxdesc, u8 *pktdata, u8 sc_user_en);
#endif

/*-------------------------------------------------------------------------------
	rtw_sta_mgt.c.
--------------------------------------------------------------------------------*/
void _rtw_init_stainfo(struct sta_info *psta);
struct	sta_mlme_priv *rtw_alloc_stainfo(u8 iface_type, u8 *hwaddr);
int rtw_free_stainfo(u8 iface_type, struct sta_mlme_priv *psta_mlmepriv);
int rtw_free_stainfo_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
int rtw_free_stainfo_enqueue_cmd(u8 iface_type, struct sta_mlme_priv *psta_mlmepriv);
struct sta_info *rtw_get_stainfo(u8 iface_type, u8 *hwaddr);
void rtw_update_sta_info(u8 iface_type, struct sta_mlme_priv *psta_mlmepriv);
int rtw_init_bcmc_stainfo(u8 iface_type);
void _rtw_sta_del_event_callback(void);
int rtw_sta_del_event_callback(u8 iface_type, struct cmd_obj *cmd_obj);
void rtw_sta_del_event(u8 iface_type, unsigned char *MacAddr, unsigned short reason);
void rtw_ap_del_sta_event(unsigned char *MacAddr);
void rtw_sta_reset_stats(struct sta_mlme_priv *psta_mlmepriv);
void rtw_macid_mgt_init(struct macid_mgt_t *pmacid_mgt);
void rtw_macid_mgt_deinit(void);
u8 rtw_macid_max_num(void);
u8 rtw_macid_max_nan_schedule_num(void);
u8 rtw_macid_max_sta_num_by_port(u8 iface_type);

struct sta_mlme_priv *rtw_sta_get_mlmepriv(u8 iface_type, u8 *sta_addr);
struct sta_security_priv *rtw_sta_get_secpriv(u8 iface_type, u8 *sta_addr);
struct sta_xmit_priv *rtw_sta_get_xmitpriv(u8 iface_type, u8 *sta_addr);
struct sta_recv_priv *rtw_sta_get_recvpriv(u8 iface_type, u8 *sta_addr);
struct ht_priv *rtw_sta_get_htpriv(u8 iface_type, u8 *sta_addr);
struct sta_sc_priv *rtw_sta_get_scpriv(u8 iface_type, u8 *sta_addr);
void rtw_sta_update_rateset(struct wlan_network *pcur_netwk, struct sta_mlme_priv *psta_mlmepriv);
void rtw_sta_update_wset_phydm(struct sta_mlme_priv *psta_mlmepriv);
void rtw_sta_update_asoc_cap_g6(struct sta_mlme_priv *psta_mlmepriv);
void rtw_ap_update_asoc_cap_g6(struct sta_mlme_priv *psta_mlme_priv);
void rtw_update_stainfo_ppe_g6(u8 iface_type, struct sta_mlme_priv *psta_mlmepriv);
u8	rtw_ap_get_assoc_sta_num(void);
/*-------------------------------------------------------------------------------
	rtw_task.c.
--------------------------------------------------------------------------------*/
int rtw_if_wifi_create_task(struct task_struct *ptask, const char *name, u32  stack_size, u32 priority, thread_func_t func, void *thctx);
void rtw_if_wifi_delete_task(struct task_struct *ptask);
void rtw_if_wifi_wakeup_task(struct task_struct *ptask);

/*-------------------------------------------------------------------------------
	rtw_sitesurvey.c.
--------------------------------------------------------------------------------*/
int rtw_scan_start_api(struct rtw_scan_param *scan_param, unsigned char block);
int rtw_scan_start_cmd(u8 iface_type, struct dot11_ssid *pssid, u16 duration, u32 dot11k_token);
int rtw_scan_cmd_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
void rtw_scan_done_user_callback(void);
void rtw_scan_all_channels_done(u8 iface_type);
void rtw_scan_timeout_handler(void *FunctionContext);
void rtw_scan_timer_hdl(void *FunctionContext);
int _rtw_scan_start_scanpriv_init(struct rtw_scan_param *scan_param);
void _rtw_scan_cmd_hdl_find_next_chan(void);

/*-------------------------------------------------------------------------------
	rtw_sitesurvey_report.c.
--------------------------------------------------------------------------------*/
void rtw_scan_report_free_remaining_node(void);
int rtw_scan_report_node_process(struct rtw_scan_report_node *new_node);
int rtw_scan_report_node_sort_and_insert(struct rtw_scan_report_node *new_node);
int rtw_scan_report_one_node(struct wlan_network *bssid);
int rtw_scan_collect_bss_info(u8 iface_type, union recv_frame *precv_frame, struct wlan_network *bssid);
void rtw_scan_one_beacon_report(u8 iface_type, union recv_frame *precv_frame);
void _rtw_scan_report_wps(struct wlan_network *scan_network, struct rtw_scan_result *pscan_result);
#ifdef CONFIG_RTW_MBO
void rtw_mbo_init(void);
void rtw_sta_parse_ap_mbo_element(struct wlan_network *scan_network, u8 *ies_buf, u16 ies_len);
#endif
int _rtw_scan_collect_bss_info_ieproc(u8 iface_type, union recv_frame *precv_frame, struct wlan_network *scan_network,
									  unsigned char rtw_trp_tis_cert_en, unsigned char rtw_802_11d_en, u8 *pchannel_num);
u8 _rtw_scan_check_security_and_rsnie(struct wlan_network *scan_network, struct security_priv *psecuritypriv);
u8 _rtw_scan_check_security_and_rsnie_part2(struct wlan_network *scan_network, struct security_priv *psecuritypriv);

/*-------------------------------------------------------------------------------
	rtw_security.c.
--------------------------------------------------------------------------------*/
int rtw_security_method_get_rsn_ie_for_11w(
	struct wlan_network *target_network,
	struct security_priv *psecuritypriv,
	u16 rsn_len,
	u8 pairwise_count,
	u8 authkey_count,
	u8 cfg80211);
int rtw_security_method_get_from_ie_for_joinbss(
	struct wlan_network *target_network,
	struct security_priv *psecuritypriv,
	struct bcn_info_param *cur_network_bcninfo,
	u8 cfg80211);
int rtw_security_method_set_from_ie_for_joinbss(
	char *pie,
	unsigned short ielen,
	struct security_priv *psecuritypriv,
	u8 *supplicant_ie);
int rtw_security_method_set_from_usr_for_joinbss(
	struct rtw_network_info *connect_param,
	u8 iface_type,
	u8 *mac_addr,
	u8 *bssid,
	struct security_priv *psecuritypriv,
	u8 *rsnxe_ie, u8 wpamode_force);
void rtw_security_method_get_for_scan(u8 privacy, struct rtw_scan_result *pscan_result, struct wlan_network *scan_network);
int rtw_security_method_set_from_usr_for_ap(
	struct rtw_softap_info *softAP_config,
	u8 iface_type,
	u8 *mac_addr,
	u8 *bssid,
	struct security_priv *psecuritypriv);
void rtw_security_method_set_from_ie_for_ap(u8 *ie, u32 IELength, struct security_priv *psecuritypriv);

/*-------------------------------------------------------------------------------
	rtw_join.c.
--------------------------------------------------------------------------------*/
void rtw_joinbss_target_network_update(struct wlan_network *new_target);
void rtw_join_timer_hdl(void *FunctionContext);
void rtw_joinbss_chk_done_concurrent(int join_res);
void rtw_leavebss_indicate(void);
void rtw_joinbss_timeout_handler(void *FunctionContext);
void rtw_joinbss_fail_process(void);
int rtw_joinbss_result_cmd_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
int rtw_joinbss_result_cmd(s32 res);
void rtw_joinbss_done_indicate(u8 iface_type);
void rtw_joinbss_result_callback(int join_res);
void rtw_joinbss_result(int res);
int rtw_joinbss_cmd_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
int rtw_joinbss_cmd(struct wlan_network *ptgt_network);
int rtw_joinbss_in_target_network(void);
u8 rtw_joinbss_scan_done(void);
int rtw_bss_get_password_for_wep(u8 *original_password, int original_password_len, u8 *password, u8 *password_len);
int rtw_joinbss_by_bssid_and_channel_start(struct rtw_network_info *connect_param);
int rtw_joinbss_start_api(struct rtw_network_info *connect_param);
void rtw_leavebss_status_update(void);
int rtw_leavebss_cmd_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
int rtw_leavebss_start(unsigned char *MacAddr, unsigned short reason);
void rtw_leavebss_event_indicate(void);
u8 _rtw_leavebss_event_indicate(void);
void rtw_joinbss_by_roaming(struct rtw_network_info *connect_param);
void rtw_joinbss_set_chanmap(struct rtw_network_info *connect_param);
void rtw_joinbss_chk_done_concurrent_check_5g(struct mlme_info *pmlmeinfo, struct mlme_info *pap_mlmeinfo);
void rtw_joinbss_chk_done_concurrent_check_chan(struct mlme_info *pmlmeinfo, struct mlme_info *pap_mlmeinfo);
void rtw_joinbss_set_mlme_join(u8 join_state);
void _rtw_joinbss_cmd_hdl_ieproc(u8 bw_40_enable);
void _rtw_joinbss_ie_restruct(struct wlan_network *target_network, struct wlan_network *pcur_network, struct joinbss_ie_param *pjoin_ie_param);
void _rtw_joinbss_set_uapsd_default_setting(struct joinbss_ie_param *pjoin_ie_param);
int _rtw_joinbss_cmd(struct wlan_network *target_network, int *pres, struct joinbss_ie_param *pjoin_ie_param);
int _rtw_joinbss_timeout_proc(unsigned char ap_compatibilty_enabled);
int _rtw_joinbss_start_proc(struct rtw_network_info *connect_param, unsigned char wifi_wpa_mode_force);
/*-------------------------------------------------------------------------------
	rtw_probe.c.
--------------------------------------------------------------------------------*/
void rtw_issue_probersp(u8 iface_type, struct wlan_network *pcur_network, unsigned char *da, u8 is_valid_p2p_probereq);
void rtw_issue_probereq(u8 iface_type, struct dot11_ssid *pssid, u8 *ra);
int rtw_on_probereq(u8 iface_type, union recv_frame *precv_frame);
int rtw_on_probersp(u8 iface_type, union recv_frame *precv_frame);

/*-------------------------------------------------------------------------------
	rtw_auth.c.
--------------------------------------------------------------------------------*/
void rtw_start_clnt_join(void);
void rtw_start_clnt_auth(void);
void rtw_issue_auth(u8 iface_type, struct sta_mlme_priv *psta_mlmepriv, unsigned short status);
void rtw_issue_deauth(u8 iface_type, unsigned char *da, u32 reason);
int rtw_ap_on_auth(u8 iface_type, union recv_frame *precv_frame);
int rtw_sta_on_auth(u8 iface_type, union recv_frame *precv_frame);
int _rtw_ap_on_auth(union recv_frame *precv_frame, u8 ap_sta_num, struct on_auth_param *pon_auth_param, u8 *frame_ind);
int _rtw_sta_on_auth(union recv_frame *precv_frame, u8 *go2asoc);
int rtw_on_deauth(u8 iface_type, union recv_frame *precv_frame);
int _rtw_on_deauth_frameproc(u8 iface_type, union recv_frame *precv_frame);

/*-------------------------------------------------------------------------------
	rtw_sme_auth.c.
--------------------------------------------------------------------------------*/
void rtw_sme_set_deauth_ie(u8* ie, u32 ie_len, u16 reason_code);
void rtw_sme_issue_deauth(u8 iface_type, unsigned char *da);
void rtw_sme_auth_event(struct rtw_sme_auth_info *auth_info);
void rtw_sme_join_timer_hdl(void *FunctionContext);
int rtw_sme_issue_auth(struct rtw_sme_auth_info *sme_auth, u16 trans, u16 status, const u8 *extra, size_t extra_len);
int rtw_sme_sta_on_auth(u8 iface_type, union recv_frame *precv_frame);
int rtw_sme_remove_ie(u8 *ies, u32 *ies_len, u32 offset, u8 eid, u8 *oui, u8 oui_len);
void rtw_sme_set_assocreq_ie(u8 *buf, u32 size, u8 wpa_rsn_exist);
int rtw_sme_joinbss_cmd(struct wlan_network *target_network, int *pres, struct joinbss_ie_param *pjoin_ie_param);
u8 *rtw_sme_sta_issue_assocreq_frameproc(u8 is_reassoc, struct mlme_info *pmlmeinfo, struct xmit_frame *pmgntframe, struct pkt_attrib *pattrib);
void rtw_sme_free_priv(void);
int rtw_sme_ap_on_auth(union recv_frame *precv_frame, u8 ap_sta_num, struct on_auth_param *pon_auth_param);
int rtw_sme_dot11w_on_action_sa_query(u8 iface_type, union recv_frame *precv_frame);
int rtw_sme_recv_func_prehandle(u8 iface_type, struct net_device_stats *pstats, union recv_frame *rframe, u8 bCheckDestAddress);
u8* rtw_sme_assocreq_append_addition_ie(u8 *pframe, u32 *pktlen);

/*-------------------------------------------------------------------------------
	rtw_assoc.c.
--------------------------------------------------------------------------------*/
void rtw_start_clnt_assoc(void);
void rtw_sta_issue_assocreq(u8 is_reassoc);
void rtw_ap_issue_assocrsp(unsigned short status, struct sta_mlme_priv *psta_mlmepriv, int pkt_type);
int rtw_ap_on_assocreq(u8 iface_type, union recv_frame *precv_frame);
void rtw_sta_on_assocrsp_wmm(struct mlme_info *pmlmeinfo);
int rtw_sta_on_assocrsp(u8 iface_type, union recv_frame *precv_frame);
int rtw_on_disassoc(u8 iface_type, union recv_frame *precv_frame);
int rtw_disassoc_cmd(void);
void rtw_assoc_resources_free(int lock_network_info);
u8 *_rtw_sta_issue_assocreq_htproc(u8 *pframe, struct pkt_attrib *pattrib, u8 bw_40_enable);
u8 *_rtw_sta_issue_assocreq_frameproc(u8 is_reassoc, struct mlme_info *pmlmeinfo, struct xmit_frame *pmgntframe, struct pkt_attrib *pattrib);
u32 _rtw_sta_issue_assocreq_validcheck(struct mlme_info *pmlmeinfo);
void _rtw_ap_issue_assocrsp(unsigned short status, struct sta_mlme_priv *psta_mlmepriv, int pkt_type, u8 p2p_go);
int _rtw_sta_on_assocrsp_frameproc(struct mlme_info *pmlmeinfo, union recv_frame *precv_frame, int *pres, u8 bw_40_enable);
int _rtw_ap_on_disassoc(u8 *pframe);
int _rtw_sta_on_disassoc(union recv_frame *precv_frame);
void _rtw_ap_on_assocreq_asoc_list(struct security_priv *psecuritypriv, struct sta_mlme_priv *psta_mlmepriv);
int _rtw_ap_on_assocreq_getaid_and_setcam(struct security_priv *psecuritypriv, struct sta_mlme_priv *psta_mlmepriv, u16 *pstatus, u8 ap_sta_num);
int _rtw_ap_on_assocreq_frameproc(struct security_priv *psecuritypriv, union recv_frame *precv_frame, struct sta_mlme_priv *psta_mlmepriv, u16 ie_offset,
								  u16 *pstatus, struct pmksa_cache_entry **pentry, u8 *sta_use_pmksa);
/*-------------------------------------------------------------------------------
	rtw_setkey.c.
--------------------------------------------------------------------------------*/
int rtw_bss_set_key_for_wep(u8 iface_type, u8 *mac_addr, u8 *bssid, struct security_priv *psecuritypriv, int key_idx, int set_tx, u8 *key, u16 key_len);
sint rtw_setkey_to_cam(u8 iface_type, u8 *mac_addr, u8 *bssid, struct security_priv *psecuritypriv, sint keyid, u8 set_tx);
int rtw_setkey_clear_stakey(u8 iface_type, struct sta_mlme_priv *psta_mlmepriv, u8 entry);
int rtw_setkey_set_stakey(u8 iface_type, struct sta_mlme_priv *psta_mlmepriv, struct sta_security_priv *psta_security, u8 unicast_key);
int rtw_setkey_cmd_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
void rtw_setkey_remove_ptk(u8 iface_type, struct sta_mlme_priv *psta_mlmepriv);
int rtw_setkey(struct rtw_crypt_info *crypt);
#ifdef CONFIG_NAN
u8 rtw_setkey_nan_set_sta_key(const u8 *addr, u8 alg, const u8 *key, u8 keyid, u8 gk, u8 macid);
void rtw_setkey_nan_set_group_key(u8 *key, u8 alg, int keyid);
#endif

/*-------------------------------------------------------------------------------
	rtw_network.c.
--------------------------------------------------------------------------------*/
void rtw_target_network_info_reset(void);
void rtw_network_update_for_scan(struct wlan_network *dst, struct wlan_network *src, bool update_ie);
int rtw_network_check_same(struct wlan_network *src, struct wlan_network *dst);

/*-------------------------------------------------------------------------------
	rtw_dynamic.c.
--------------------------------------------------------------------------------*/
int rtw_dynamic_check_work_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
void rtw_dynamic_timer_hdl(void *FunctionContext);
void rtw_sta_dynamic_check_link_status(void);
u32 sta_dynamic_rx_pkts_in2s(struct sta_mlme_priv *psta_mlmepriv);

/*-------------------------------------------------------------------------------
	rtw_mgnt.c.
--------------------------------------------------------------------------------*/
void rtw_mgntframe_dispatcher(u8 iface_type, union recv_frame *precv_frame);
int rtw_mgntframe_do_reserved(u8 iface_type, union recv_frame *precv_frame);
struct xmit_frame *rtw_mgntframe_alloc(u8 iface_type);
void rtw_mgntframe_attrib_update(struct pkt_attrib *pattrib);
void rtw_mgntframe_indicate(u8 *data, u32 len, u8 channel);
int rtw_mgmt_xmitframe_coalesce(u8 iface_type, struct security_priv *psecuritypriv, struct xmit_frame *pxmitframe);

/*-------------------------------------------------------------------------------
	rtw_pmksa_cache.c.
--------------------------------------------------------------------------------*/
void rtw_pmksa_cache_entry_free(struct pmksa_cache_entry *pentry);
int rtw_pmksa_cache_entry_add(struct pmksa_cache *ppmksa, u8 *pmk, u8 *pmkid, u8 *addr1, u32 akmp, u8 *encrypted_addr);
struct pmksa_cache_entry *rtw_pmksa_cache_entry_remove(struct pmksa_cache *ppmksa, struct pmksa_cache_entry *pdelete);
struct pmksa_cache_entry *rtw_pmksa_cache_entry_search(struct pmksa_cache *ppmksa, u8 *addr1, u32 akmp);
void rtw_pmksa_cache_set_current_entry(struct pmksa_cache *ppmksa, struct pmksa_cache_entry *pentry);
struct pmksa_cache_entry *rtw_pmksa_cache_get_current_entry(struct pmksa_cache *ppmksa);
int rtw_pmksa_cache_flush(struct pmksa_cache *ppmksa);
int rtw_pmksa_cache_init(struct pmksa_cache *ppmksa, struct security_priv *psecuritypriv);
int rtw_pmksa_cache_deinit(struct pmksa_cache *ppmksa);

/*-------------------------------------------------------------------------------
	rtw_he.c.
--------------------------------------------------------------------------------*/
#ifdef CONFIG_80211AX_HE
void HE_caps_handler(u8 bw_40_enable, struct ht_priv *phtpriv, struct _NDIS_802_11_VARIABLE_IEs *pIE);
void HE_operation_update_asoc_cap(u8 iface_type, struct _NDIS_802_11_VARIABLE_IEs *pIE);
void HE_operation_handler(struct ht_priv *phtpriv, struct _NDIS_802_11_VARIABLE_IEs *pIE, u8 update);
void HE_mu_edca_handler(struct ht_priv *phtpriv, struct _NDIS_802_11_VARIABLE_IEs *pIE, u8 first, u8 slotTime);
void HE_spatial_reuse_handler(struct ht_priv *phtpriv, struct _NDIS_802_11_VARIABLE_IEs *pIE, u8 first);
void HE_phy_caps_update_asoc_cap(u8 iface_type, struct asoc_cap_t *pasoc_cap, struct rtw_chan_def *pchandef, u8 *ele_start);
void HE_caps_update_asoc_cap(u8 iface_type, u8 *pIE);
u32 rtw_restructure_he_ie(struct ht_priv *phtpriv, u8 *in_ie, u8 *out_ie, u32 in_len, u32 *pout_len);
void rtw_he_fill_htc(u8 *phtc_buf);
void HE_mac_caps_update_asoc_cap(struct asoc_cap_t *pasoc_cap, u8 *ele_start);
void HE_supp_mcs_update_asoc_cap(struct asoc_cap_t *pasoc_cap, u8 *ele_start);
#endif

/*-------------------------------------------------------------------------------
	rtw_ht.c.
--------------------------------------------------------------------------------*/
void rtw_ht_caps_handler(struct ht_priv *phtpriv, struct _NDIS_802_11_VARIABLE_IEs *pIE);
void rtw_ht_info_handler(struct ht_priv *phtpriv, struct _NDIS_802_11_VARIABLE_IEs *pIE);
unsigned int rtw_restructure_ht_ie(u8 *in_ie, u8 *out_ie, u32 in_len, u32 *pout_len, struct ht_priv *phtpriv,
								   struct qos_priv *pqospriv, u32 dot11PrivacyAlgrthm);
void rtw_update_ht_cap(u8 bw_40_en, u8 *pie, u32 ie_len, struct ht_priv *phtpriv);
int rtw_ap_ht_operation_update(void);
int rtw_uapsd_check_ap_support(struct qos_priv *pqospriv, u8 *in_ie, uint in_len);
int rtw_uapsd_restruct_wmm_ie(u8 *in_ie, u8 *out_ie, uint in_len, uint initial_out_len, u8 uapsd_ac_enable, u8 uapsd_max_sp);

/*-------------------------------------------------------------------------------
	rtw_vht.c.
--------------------------------------------------------------------------------*/
#ifdef CONFIG_80211AC_VHT
void rtw_vht_use_default_setting(struct ht_priv *phtpriv);
void rtw_process_vht_op_mode_notify(u8 *pframe, struct sta_mlme_priv *psta_mlmepriv);
u32	rtw_build_vht_op_mode_notify_ie(struct ht_priv *phtpriv, u8 *pbuf, u8 bw);
u32	rtw_build_vht_cap_ie(struct ht_priv *phtpriv, u8 *pbuf, u8 bw_40_enable);
u32 rtw_restructure_vht_ie(struct ht_priv *phtpriv, u8 *in_ie, u8 *out_ie, u32 in_len, u32 *pout_len, u8 bw_40_enable);
int rtw_on_action_vht(u8 iface_type, union recv_frame *precv_frame);
void rtw_vht_caps_handler(struct ht_priv *phtpriv, struct _NDIS_802_11_VARIABLE_IEs *pIE);
#endif /* CONFIG_80211AC_VHT */

/*-------------------------------------------------------------------------------
	rtw_ips.c.
--------------------------------------------------------------------------------*/
void rtw_ips_enter(void);
int rtw_ips_leave(void);
int rtw_ips_enter_check_cmd(void);
int rtw_ips_enter_check_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
int rtw_ips_wakeup(u32 ips_deffer_ms);
int rtw_ips_set_enable(u8 enable);

/*-------------------------------------------------------------------------------
	rtw_lps.c.
--------------------------------------------------------------------------------*/
u8 rtw_ps_rdy_check(void);
void rtw_ps_set_mode(u8 ps_mode, u8 bcn_ant_mode);
void rtw_ps_leave_all_ps(void);
void rtw_ps_init_priv(void);
void rtw_ps_deinit_priv(void);
int rtw_lps_set_enable(u8 enable);
void rtw_lps_sta_traffic_status_watchdog(void);
int rtw_lps_ctrl_wk_cmd(u8 lps_ctrl_type);
int rtw_lps_ctrl_wk_cmd_direct(u8 lps_ctrl_type);
int rtw_lps_ctrl_wk_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
int rtw_mp_stop_hdl(u8 iface_type, struct cmd_obj *cmd_obj);

/*-------------------------------------------------------------------------------
	rtw_twt.c.
--------------------------------------------------------------------------------*/
#ifdef CONFIG_TWT
int rtw_on_action_twt(u8 iface_type, union recv_frame *precv_frame);
void rtw_issue_action_twt(u8 iface_type, u8 setup, struct twt_ie_t *twt_ie);
#endif

/*-------------------------------------------------------------------------------
	rtw_ap.c.
--------------------------------------------------------------------------------*/
void rtw_ap_init_mlme_info(void);
void rtw_ap_free_mlme_info(void);
void rtw_ap_expire_timeout_chk(int skb_num_np_or_ap, unsigned char ap_polling_sta, rtos_sema_t wakeup_sema);
void rtw_ap_start_bss_network(void);
int rtw_ap_add_sta_cmd_callback(u8 iface_type, struct cmd_obj *cmd_obj);
void rtw_ap_add_sta_event(unsigned char *MacAddr, int cam_idx);
void rtw_ap_associated_clients_update(u8 updated);
void rtw_ap_bss_cap_update_on_sta_join(struct sta_mlme_priv *psta_mlmepriv, struct ht_priv *psta_htpriv);
u8 rtw_ap_bss_cap_update_on_sta_leave(struct sta_mlme_priv *psta_mlmepriv);
u8 rtw_ap_deauth_and_free_sta(struct sta_mlme_priv *psta_mlmepriv, unsigned short reason);
int rtw_ap_deauth_asoc_list(void);
void rtw_ap_sta_info_update(struct sta_mlme_priv *psta_mlme_priv);
int rtw_ap_start_api(struct rtw_softap_info *softAP_config);
void rtw_ap_update_bmc_sta(void);
void rtw_ap_polling_sta_hdl(void);
/*-------------------------------------------------------------------------------
	rtw_ap_xmit.c.
--------------------------------------------------------------------------------*/
sint rtw_ap_enqueue_for_sleeping_sta(struct sta_mlme_priv *psta_mlmepriv, struct sk_buff *pkt);
void rtw_ap_stop_sta_xmit(struct sta_mlme_priv *psta_mlmepriv, struct sta_xmit_priv *psta_xmitpriv);
void rtw_ap_wakeup_sta_to_xmit(rtos_sema_t wakeup_sema, struct sta_mlme_priv *psta_mlmepriv, struct sta_xmit_priv *psta_xmitpriv);
void rtw_ap_sleeping_q_to_pending_q(struct sta_mlme_priv *psta_mlmepriv, struct sta_xmit_priv *psta_xmitpriv, u8 all_pkt, u8 high_q);
void rtw_ap_sleeping_q_free(struct sta_mlme_priv *psta_mlmepriv);
/*-------------------------------------------------------------------------------
	rtw_beacon.c.
--------------------------------------------------------------------------------*/
void rtw_on_beacon_bw_check(struct _NDIS_802_11_VARIABLE_IEs *pIE, u8 bw_40_enable);
void rtw_on_beacon_rate_check(struct sta_mlme_priv *psta_mlmepriv, u8 *rate, u8 rate_len, u8 *MCS_rate);
void rtw_on_beacon_info_update(struct mlme_info	*pmlmeinfo, u8 *pframe, u32 pkt_len, struct sta_mlme_priv *psta_mlmepriv, u8 bw_40_enable);
int rtw_on_beacon_info_check(u8 *pframe, u32 packet_len,
							 struct bcn_info_param *pcur_network_BcnInfo,
							 struct wlan_network *pcur_network,
							 u8 cur_channel);
int rtw_on_beacon(u8 iface_type, union recv_frame *precv_frame);
void rtw_get_bcn_info(void);
void rtw_ap_issue_beacon(u8 iface_type);
u8 rtw_ap_beacon_set_param(u8 *ie, struct wlan_network *cur_network, u8 *ERP_IE, u32 *qos_option);
int rtw_ap_set_parameters_from_beacon(u8 iface_type, u8 *pbuf);
int rtw_ap_generate_bcn_ie(u8 *ssid, u16 ssid_len, u8 *ie, u32 max_ie_sz);
void rtw_ap_update_beacon(u8 iface_type, u8 ie_id, u8 tx);
int rtw_ap_tx_beacon_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
int rtw_ap_set_tx_beacon_cmd(u8 iface_type);

/*-------------------------------------------------------------------------------
	rtw_action.c.
--------------------------------------------------------------------------------*/
int rtw_on_action(u8 iface_type, union recv_frame *precv_frame);
int rtw_on_action_block_ack(u8 iface_type, union recv_frame *precv_frame);
int rtw_on_action_wnm(u8 iface_type, union recv_frame *precv_frame);
int rtw_on_action_public(u8 iface_type, union recv_frame *precv_frame);
void rtw_addba_rsp_hdl(struct ht_priv *htpriv, unsigned char *frame_body);
int rtw_addba_delba_hdl(struct ht_priv *htpriv, unsigned char *frame_body, struct sta_recv_priv *sta_recvpriv, u8 ap_compatibilty);

/*-------------------------------------------------------------------------------
	rtw_addba.c.
--------------------------------------------------------------------------------*/
void rtw_on_addba_req(u8 ap_compatibilty_enabled, u8 iface_type, u8 *paddba_req, u8 *addr);
void rtw_issue_action_ba(u8 iface_type, unsigned char *raddr, unsigned char action, unsigned short status);
int rtw_send_delba(u8 iface_type, u8 initiator, u8 *addr);
int rtw_add_ba_hdl(u8 iface_type, struct cmd_obj *cmd_obj);
int rtw_addbareq_cmd(u8 iface_type, u8 tid, u8 *addr);
void rtw_issue_addbareq_cmd(u8 iface_type, struct ht_priv *phtpriv_sta, u8 *pagg_en, u8 priority, u8 *ra);
void rtw_addba_timer_hdl(void *FunctionContext);
void rtw_init_addba_retry_timer(struct sta_info *psta);

/*-------------------------------------------------------------------------------
	rtw_80211w.c.
--------------------------------------------------------------------------------*/
void rtw_dot11w_issue_action_sa_query(u8 iface_type, unsigned char *raddr, unsigned char action, unsigned short tid, u8 key_type);
int rtw_dot11w_on_action_sa_query(u8 iface_type, union recv_frame *precv_frame);
int rtw_dot11w_sta_timeout_event_callback(u8 iface_type, struct cmd_obj *cmd_obj);
void rtw_dot11w_sa_query_timer_hdl(void *FunctionContext);
void rtw_dot11w_init_expire_timer(struct sta_mlme_priv *psta_mlmepriv, struct sta_security_priv *psta_secpriv);
int	rtw_dot11w_BIP_verify(struct security_priv *psecuritypriv, u8 *precvframe);
int rtw_dot11w_validate_mgmt(u8 iface_type, struct security_priv *psecuritypriv, union recv_frame **pprecv_frame);

/*-------------------------------------------------------------------------------
	rtw_11d.c.
--------------------------------------------------------------------------------*/
void rtw_11d_restructure_country_ie(u8 *in_ie, u8 *out_ie, u32 in_len, u32 *pout_len);
void rtw_11d_reset_info(struct dot11d_priv *dot11dpriv);
void rtw_11d_process_country_ie(struct dot11d_priv *dot11dpriv, u8 *country_ie, u8 ie_len);
void rtw_11d_country_decision_default(struct dot11d_priv *pdot11dpriv);
void rtw_11d_update_regulatory_from_country(u8 *country_code);
bool rtw_11d_get_chplan_from_country(u8 *country_code, u8 *domain_code, u8 *power_limit);
/*-------------------------------------------------------------------------------
	rtw_cmd.c.
--------------------------------------------------------------------------------*/
int rtw_cmd_filter(void);
int rtw_enqueue_cmd(u8 iface_type, u8 *parmbuf,
					int(*cmd_hdl)(u8 iface_type, struct cmd_obj *pcmd),
					u32 parm_nobuf);
struct	cmd_obj	*rtw_dequeue_cmd(void);
void rtw_free_cmd_obj(struct cmd_obj *pcmd);
int rtw_cmd_process(void *task);
void rtw_cmd_resource_free(void);
/*-------------------------------------------------------------------------------
	rtw_dfs.c.
--------------------------------------------------------------------------------*/
void rtw_sta_on_beacon_csa(u8 *pframe, u32 pkt_len);
int rtw_sta_on_action_csa(u8 iface_type, union recv_frame *precv_frame);
void rtw_csa_timer_hdl(void *FunctionContext);
void rtw_sta_csa_process(u8 new_ch_mode, u8 new_ch_no, u8 new_ch_count);
void rtw_ap_init_dfs(void);
void rtw_ap_deinit_dfs(void);
/*-------------------------------------------------------------------------------
	rtw_mp.c.
--------------------------------------------------------------------------------*/
#ifdef CONFIG_MP_INCLUDED
int rtw_mp_init_priv(u8 iface_type);
void rtw_mp_deinit_priv(void);
void rtw_mp_pwrctl_dm(u32 bstart);
int rtw_mp_start_test(u8 iface_type);
void rtw_mp_stop_test(u8 iface_type);
void rtw_mp_set_bandwidth(void);
void rtw_mp_fill_txdesc_for_mp(struct tx_desc *ptxdesc);
void rtw_mp_set_packet_tx(u8 iface_type);
void rtw_mp_set_packet_rx(u8 bStartRx);
u8 rtw_mp_rate_to_mgnt_rate(u32 MptRateIdx);
u8 rtw_mp_mgnt_rate_to_mp_rate(u8 rate);

int rtw_mp_rtfloor(float x);
void rtw_mp_byte_to_bit(u8 *out, bool *in, u8	in_size);
void rtw_mp_crc16_generator(bool *out, bool *in, u8 in_size);
void rtw_mp_cck_generator(struct pmac_txinfo_t *ppmac_txinfo, struct pmac_pktinfo_t *ppmac_pktinfo);
u32 rtw_mp_ldpc_parameter_generator(u32 N_pld_int, u32 N_CBPSS, u32 N_SS, u32 R, u32 m_STBC, u32 N_TCB_int);
void rtw_mp_pmac_Nsym_generator(struct pmac_txinfo_t *ppmac_txinfo, struct pmac_pktinfo_t *ppmac_pktinfo);
void rtw_mp_l_sig_generator(u32 N_SYM, struct pmac_txinfo_t *ppmac_txinfo, struct pmac_pktinfo_t *ppmac_pktinfo);
void rtw_mp_crc8_generator(bool *out, bool *in, u8 in_size);
void rtw_mp_ht_sig_generator(struct pmac_txinfo_t *ppmac_txinfo, struct pmac_pktinfo_t *ppmac_pktinfo);
void rtw_mp_vht_sig_a_generator(struct pmac_txinfo_t *ppmac_txinfo, struct pmac_pktinfo_t *ppmac_pktinfo);
void rtw_mp_vht_sig_b_generator(struct pmac_txinfo_t *ppmac_txinfo);
void rtw_mp_vht_delimiter_generator(struct pmac_txinfo_t *ppmac_txinfo);
#endif // #ifdef CONFIG_MP_INCLUDED

/*-------------------------------------------------------------------------------
	rtw_promisc.c.
--------------------------------------------------------------------------------*/
u8 rtw_recv_promisc(union recv_frame	*precvframe, struct rx_pkt_attrib	*pattrib);

/*-------------------------------------------------------------------------------
	rtw_state.c.
--------------------------------------------------------------------------------*/
int rtw_check_ap_exist(void);
int rtw_check_nan_exist(void);
int rtw_check_sta_associated_to_ap(void);
int rtw_check_sta_linking(void);
void rtw_state_set_sitesurvey_doing(u8 state);
int rtw_check_under_sitesurvey(void);
void rtw_state_set_join_prepare(void);
void rtw_state_set_join_doing(void);
void rtw_state_set_auth_doing(void);
void rtw_state_set_assoc_doing(void);
void rtw_state_set_assoc_success(void);
int rtw_state_check_sta_no_link(void);
int rtw_state_check_sta_prepare_join(void);
int rtw_state_check_sta_prepare_auth(void);
int rtw_state_check_sta_auth_doing(void);
int rtw_state_check_sta_assoc_doing(void);
void rtw_state_reset(u8 iface_type);
void rtw_state_set_ap_beacon_on(u8 state);
int rtw_state_check_ap_on(void);
int rtw_check_ap_linked(void);
int rtw_check_sta_connected(void);
void rtw_set_driver_mode(u8 mode);
void rtw_state_set_ap_client_auth_ongoing(struct sta_mlme_priv *psta_mlmepriv);
void rtw_state_set_ap_client_auth_success(struct sta_mlme_priv *psta_mlmepriv);
void rtw_state_set_ap_client_assoc_success(struct sta_mlme_priv *psta_mlmepriv);
void rtw_state_reset_ap_client_state(struct sta_mlme_priv *psta_mlmepriv);
int rtw_state_check_ap_client_auth_ongoing(struct sta_mlme_priv *psta_mlmepriv);
int rtw_state_check_ap_client_auth_success(struct sta_mlme_priv *psta_mlmepriv);
int rtw_state_check_ap_client_assoc_success(struct sta_mlme_priv *psta_mlmepriv);
int rtw_check_nan_datalink_exist(void);
int rtw_check_nan_enabled(void);
u8 rtw_get_p2p_role(void);
/*-------------------------------------------------------------------------------
	rtw_drv_init.c: for core, rtw_intf_inter.
--------------------------------------------------------------------------------*/
void rtw_cancel_all_timer(u8 iface_type);
int rtw_free_drv_sw(u8 iface_type);
int rtw_reset_drv_sw(void);
void rtw_init_drv_sw(u8 iface_type);
void rtw_reset_securitypriv(void);
int rtw_start_drv_threads(void);
void rtw_stop_drv_threads(void);
u8 rtw_is_adapter_up(u8 iface_type);

/*-------------------------------------------------------------------------------	inline func--------------------------------------------------------------------------------*/
__STATIC_INLINE int rtw_check_bcst_bssid(u8 *bssid)
{
	if (bssid[0] == 0xFF && bssid[1] == 0xFF && bssid[2] == 0xFF && bssid[3] == 0xFF && bssid[4] == 0xFF && bssid[5] == 0xFF) {
		return 1;
	}
	return 0;
}

__STATIC_INLINE int rtw_check_empty_bssid(u8 *bssid)
{
	if (bssid[0] == 0x00 && bssid[1] == 0x00 && bssid[2] == 0x00 && bssid[3] == 0x00 && bssid[4] == 0x00 && bssid[5] == 0x00) {
		return 1;
	}
	return 0;
}

__inline static u8 get_supported_rateset(u8 *supported_rateset)
{
	u8 rateset_len = 0;
	extern const unsigned char default_rateset[NumRates];

	if (g_mlmepriv.wireless_mode_support & RTW_80211_B) { /*include b mode rate*/
		memcpy(supported_rateset, (void *)default_rateset, CCK_ONLY_RATE_NUM);
		rateset_len += CCK_ONLY_RATE_NUM;
	}

	if (g_mlmepriv.wireless_mode_support & (RTW_80211_G | RTW_80211_A)) { /*include g/a mode rate*/
		memcpy(supported_rateset + rateset_len, (u8 *)(default_rateset + CCK_ONLY_RATE_NUM), OFDM_ONLY_RATE_NUM);
		rateset_len += OFDM_ONLY_RATE_NUM;
	}

	return rateset_len;
}

__inline static void get_basic_rate(u8 *default_basic_rates)
{
	u8 basic_rates_num = 0;
	extern const u8 rtw_basic_rate_mix[7];

	if (g_mlmepriv.wireless_mode_support & RTW_80211_B) { /*include b mode rate*/
		memcpy(default_basic_rates, (void *)rtw_basic_rate_mix, CCK_ONLY_RATE_NUM);
		basic_rates_num += CCK_ONLY_RATE_NUM;
	}
	if (g_mlmepriv.wireless_mode_support & (RTW_80211_G | RTW_80211_A)) { /*include g/a mode rate*/
		memcpy(default_basic_rates + basic_rates_num, (u8 *)(rtw_basic_rate_mix + CCK_ONLY_RATE_NUM), OFDM_ONLY_BASIC_RATE_NUM);
	}
}

__inline static void set_assocreq_parms(
	struct issue_assoc_req_param *parms,
	struct channel_set_bitmap	*channel_set,
	u8 *supported_rateset)
{
	struct mlme_info *pmlmeinfo = wifi_rom_rtw_get_adapter_mlmeinfo(IFACE_PORT0);

	set_network_info_parms(&parms->net_param, pmlmeinfo->pcur_network);

	parms->channel_set = channel_set;

	parms->cur_channel = pmlmeinfo->cur_channel;

	parms->rateset_len = get_supported_rateset(supported_rateset);
	parms->supported_rateset = supported_rateset;
}

#endif // _RTW_CORE_FUNCTION_H_
#endif // _RTW_ADAPTER_DEFINED_H_

