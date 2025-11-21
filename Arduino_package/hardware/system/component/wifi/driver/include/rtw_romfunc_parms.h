#ifndef __RTW_ROMFUNC_PARMS_H_
#define __RTW_ROMFUNC_PARMS_H_

extern struct wifi_user_conf	wifi_user_config;

__inline static void set_init_channel_parms(
	struct init_chset_parms *parms,
	u8 ChannelPlan)
{
	parms->band_type_support = g_mlmepriv.band_type_support;
	parms->ChannelPlan = ChannelPlan;
}

__inline static void set_update_mode_parms(
	struct update_mode_parms *parms,
	struct mlme_info *pmlmeinfo)
{
	parms->SupportedRates = pmlmeinfo->pcur_network->SupportedRates;
	parms->HT_info_enable = pmlmeinfo->phtpriv->HT_info_enable;
	parms->HT_caps_enable = pmlmeinfo->phtpriv->HT_caps_enable;
	parms->pHT_enable = &pmlmeinfo->phtpriv->HT_enable;
	parms->cur_channel = pmlmeinfo->cur_channel;
#ifdef CONFIG_80211AX_HE
	parms->he_option = pmlmeinfo->phtpriv->he_option;
#endif
	parms->pcur_wireless_mode = &g_mlmepriv.cur_wireless_mode;
	parms->wireless_mode_support = g_mlmepriv.wireless_mode_support;
	parms->puser_tx_rate = &g_mlmepriv.user_tx_rate;
	parms->ht_enable = pmlmeinfo->phtpriv->ht_enable;
	parms->cur_ch_offset = &(pmlmeinfo->cur_ch_offset);
	parms->ht_option = pmlmeinfo->phtpriv->ht_option;
	parms->qos_option = pmlmeinfo->pqospriv->qos_option;
}

__inline static void set_mgnt_wlan_hdr_parms(
	struct fill_wlan_hdr_parms *parms,
	struct xmit_frame *pmgntframe,
	u8 *addr1, u8 *addr2, u8 *addr3, u16 *seq_inc,
	u16 frame_sub_type)
{
	struct pkt_attrib	*pattrib;

	pattrib = &pmgntframe->attrib;
	pattrib->type_subtype = frame_sub_type;
	parms->pstart = pmgntframe->pkt->data - TXDESC_OFFSET;
	parms->paddr1 = addr1;
	parms->paddr2 = addr2;
	parms->paddr3 = addr3;
	parms->frame_ctl = 0;
	parms->pseq = seq_inc;
	parms->frame_subtype = frame_sub_type;
	parms->phdrlen = &(pattrib->hdrlen);
	parms->ppktlen = &(pattrib->pktlen);
}

__inline static void set_bcn_info_parms(
	struct bcn_info_param *parms,
	struct bcn_info_param *BcnInfo)
{
	parms->encryp_protocol = BcnInfo->encryp_protocol;
	parms->group_cipher = BcnInfo->group_cipher;
	parms->ht_cap_info = BcnInfo->ht_cap_info;
	parms->ht_info_infos_0 = BcnInfo->ht_info_infos_0;
	parms->is_8021x = BcnInfo->is_8021x;
	parms->pairwise_cipher = BcnInfo->pairwise_cipher;
}

__inline static void set_network_info_parms(
	struct network_param *param,
	struct wlan_network *pcur_netwk)
{
	param->BeaconPeriod = &(pcur_netwk->BeaconPeriod);
	param->Ssid = pcur_netwk->Ssid.Ssid;
	param->SsidLength = &(pcur_netwk->Ssid.SsidLength);
	param->DSConfig = &(pcur_netwk->DSConfig);
	param->SupportedRates = pcur_netwk->SupportedRates;
	param->Privacy = &(pcur_netwk->Privacy);
	param->IEs = pcur_netwk->IEs;
	param->IELength = pcur_netwk->IELength;
}

__inline static void set_sta_info_parms(
	struct stainfo_parms *param,
	struct sta_mlme_priv *psta_mlmepriv,
	uint *p_sta_qos_option)
{
	param->parms_qos_option = p_sta_qos_option;
	param->capability = &(psta_mlmepriv->sta_capability);
	param->flags = &(psta_mlmepriv->stainfo_flags);

	param->wpa_psk = &(psta_mlmepriv->psta_security->sta_wpa_psk);
	param->wpa_group_cipher = &(psta_mlmepriv->psta_security->sta_wpa_psk);

	param->qos_info = &(psta_mlmepriv->sta_qos_info);

	param->bssrateset = psta_mlmepriv->sta_bssrateset;
	param->bssratelen = &(psta_mlmepriv->sta_bssratelen);

	param->ht_cap = (u8 *) & (psta_mlmepriv->htpriv.ht_cap);
	param->ht_cap_len = sizeof(struct rtw_ieee80211_ht_cap);
}


__inline static void set_securitypriv_parms(
	struct securitypriv_parms *parms,
	struct mlme_info *pmlmeinfo)
{
	u32 wep_enable = pmlmeinfo->psecuritypriv->b_wep_enable;

	parms->dot11PrivacyAlgrthm = &(pmlmeinfo->psecuritypriv->dot11PrivacyAlgrthm);
	parms->dot11_wpa_mode = &(pmlmeinfo->psecuritypriv->dot11_wpa_mode);
	parms->dot118021XGrpPrivacy = &(pmlmeinfo->psecuritypriv->dot118021XGrpPrivacy);
	parms->AuthKeyMgmt = &(pmlmeinfo->psecuritypriv->AuthKeyMgmt);

	parms->ieee80211w = &(pmlmeinfo->psecuritypriv->ieee80211w);
	parms->parm_wep_enable = &(wep_enable);

	parms->wpa_psk = &(pmlmeinfo->psecuritypriv->wpa_psk);
	parms->wpa2_group_cipher = &(pmlmeinfo->psecuritypriv->wpa2_group_cipher);
	parms->wpa2_pairwise_cipher = &(pmlmeinfo->psecuritypriv->wpa2_pairwise_cipher);
	parms->wpa_group_cipher = &(pmlmeinfo->psecuritypriv->wpa_group_cipher);
	parms->wpa_pairwise_cipher = &(pmlmeinfo->psecuritypriv->wpa_pairwise_cipher);

	parms->supplicant_ie = pmlmeinfo->psecuritypriv->supplicant_ie;

	parms->rtw_cmd_tsk_spt_wap3 = 1;
}

__inline static void set_assocreq_parms_2(
	struct issue_assoc_req_param_2 *parms,
	struct mlme_info *pmlmeinfo)
{


	set_network_info_parms(&parms->net_param, pmlmeinfo->pcur_network);
	parms->wps_phase = pmlmeinfo->psecuritypriv->b_wps_phase;
	parms->ht_option = pmlmeinfo->phtpriv->ht_option;
#ifdef CONFIG_80211AC_VHT
	parms->vht_option = pmlmeinfo->phtpriv->vht_option;
#endif // CONFIG_80211AC_VHT
#ifdef CONFIG_80211AX_HE
	parms->he_option = pmlmeinfo->phtpriv->he_option;
#endif // CONFIG_80211AX_HE
}

__inline static void set_assocrsp_parms(
	struct issue_assoc_rsp_param *parms,
	struct mlme_info *pmlmeinfo,
	struct sta_mlme_priv *psta_mlmepriv)
{

	parms->IEs = pmlmeinfo->pcur_network->IEs;
	parms->IELength = pmlmeinfo->pcur_network->IELength;
	parms->bssrateset = psta_mlmepriv->sta_bssrateset;
	parms->bssratelen = psta_mlmepriv->sta_bssratelen;
	parms->stainfo_flags = psta_mlmepriv->stainfo_flags;
	parms->ht_option = pmlmeinfo->phtpriv->ht_option;
	parms->qos_option = pmlmeinfo->pqospriv->qos_option;
	parms->wpspriv = &g_wpspriv;
}

__inline static void set_on_assocreq_parms(
	struct on_assoc_req_param *parms,
	struct mlme_info *pmlmeinfo,
	struct sta_mlme_priv *psta_mlmepriv,
	uint *p_sta_qos_option)
{

	parms->wpspriv = &g_wpspriv;
	set_securitypriv_parms(&parms->secure_params, pmlmeinfo);
	set_network_info_parms(&parms->net_param, pmlmeinfo->pcur_network);
	set_sta_info_parms(&parms->sta_param, psta_mlmepriv, p_sta_qos_option);
	set_update_mode_parms(&parms->mode_param, pmlmeinfo);
}

__inline static void set_dot11w_action_params(
	struct dot11w_action_params *params,
	u8 iface_type, struct pkt_attrib *pattrib,
	unsigned char *ra, unsigned char action, unsigned short tid)
{

	params->ra = ra;
	params->bssid = wifi_rom_rtw_get_adapter_bssid(iface_type);
	params->sa = wifi_rom_rtw_get_adapter_mac_addr(iface_type);
	params->mgnt_seq = &g_mlmepriv.mgnt_seq;
	params->pktlen = &pattrib->pktlen;
	params->sa_query_seq = &g_mlmepriv.sa_query_seq_11w;
	params->action = action;
	params->tid = tid;
}

__inline static uint get_WLAN_BSSID_EX_sz(struct wlan_network *cur_network)
{
	(void)cur_network;
	return (FIELD_OFFSET(struct wlan_network, IEs));
}

__inline static void get_component_status_parms(
	struct component_status *comp_status,
	struct rom_component_status *rom_comp_status)
{
	rom_comp_status->mutex_total_num = comp_status->mutex_total_num;
	rom_comp_status->mutex_buf_used_num = comp_status->mutex_buf_used_num;
	rom_comp_status->mutex_dynamic_num = comp_status->mutex_dynamic_num;
	rom_comp_status->mutex_max_buf_used_num = comp_status->mutex_max_buf_used_num;

	rom_comp_status->sema_total_num = comp_status->sema_total_num;
	rom_comp_status->sema_buf_used_num = comp_status->sema_buf_used_num;
	rom_comp_status->sema_dynamic_num = comp_status->sema_dynamic_num;
	rom_comp_status->sema_max_buf_used_num = comp_status->sema_max_buf_used_num;

	rom_comp_status->timer_total_num = comp_status->timer_total_num;
	rom_comp_status->timer_buf_used_num = comp_status->timer_buf_used_num;
	rom_comp_status->timer_dynamic_num = comp_status->timer_dynamic_num;
	rom_comp_status->timer_max_buf_used_num = comp_status->timer_max_buf_used_num;
}

#endif // __RTW_FUNC_PARMS_H_
