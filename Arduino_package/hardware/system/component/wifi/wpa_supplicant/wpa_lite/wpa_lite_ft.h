#ifndef __RTW_FT_H_
#define __RTW_FT_H_

#ifdef CONFIG_IEEE80211R

#define MAX_FT_AUTH_LEN	300
#define FT_REAUTH_LIMIT	(4)

#define rtw_ft_chk_status(a, s) \
	(a.ft_info->ft_status == (s))

#define rtw_ft_set_status(a, s) \
	(a.ft_info->ft_status = (s));

#define rtw_ft_roam(a)	\
	(a.need_to_roam && a.ft_peer_en)

enum _rtw_ft_sta_status {
	RTW_FT_UNASSOCIATED_STA = 0,
	RTW_FT_AUTHENTICATING_STA,
	RTW_FT_AUTHENTICATED_STA,
	RTW_FT_ASSOCIATING_STA,
	RTW_FT_ASSOCIATED_STA,
};
struct ft_roam_info {
	u16 mdid;
	u8 ft_cap;
	u8	assoc_resp_ies[MAX_FT_IE_LEN];/* MDIE FTIE from Association Response */
	u32	assoc_resp_ies_len;
	u8 ft_status;

	u32 reassoc_deadline;
	u32 key_lifetime;
	u8 snonce[KEY_NONCE_LEN]; //snonce in ft auth/reassoc
	u8 anonce[KEY_NONCE_LEN]; //anonce in ft auth/reassoc
	u8 pmk_r0[PMK_LEN_MAX];
	u8 pmk_r0_len;
	u8 pmk_r0_name[WPA_PMK_NAME_LEN];
	u8 pmk_r1[PMK_LEN_MAX];
	u8 pmk_r1_len;
	u8 pmk_r1_name[WPA_PMK_NAME_LEN];
	u8	ptk[PTK_LEN_TKIP];
	u8	gtk[GTK_LEN];
	u8	gtk_keyid;
	u8 r0kh_id[FT_R0KH_ID_MAX_LEN];
	u8 r0kh_id_len;
	u8 r1kh_id[FT_R1KH_ID_LEN];
#ifdef CONFIG_IEEE80211W
	u8	igtk[WPA_IGTK_MAX_LEN];
	u8	igtk_len;
	u8 igtk_keyid;
#endif
};

struct ft_ie_parse {
	u8 *mdie;
	u32 mdie_len;
	u8 *ftie;
	u32 ftie_len;
	u8 *r1kh_id;
	u8 *gtk;
	u32 gtk_len;
	u8 *r0kh_id;
	u32 r0kh_id_len;
	u8 *rsn;
	u32 rsn_len;
	u8 *rsn_pmkid;
	u8 *igtk;
	u32 igtk_len;
	u8 *ric;
	u32 ric_len;
};

/*from wpa_lite_ft*/
void rtw_ft_cap_update(struct rtw_kvr_param_t *kvr_param);
void rtw_ft_info_init(void);
void rtw_ft_info_deinit(void);
void rtw_ft_roam_reset(void);
void rtw_ft_disable(void);
/*from wpa_lite_ft_frame*/
void rtw_ft_auth_timer_hdl(void *FunctionContext);
/*from wpa_lite_ft_key*/
int rtw_ft_ptk_derive(u8 *sa, u8 *ssid);
int rtw_ft_eapol3_ie_validate(u8 *buf, u32 len);
int rtw_ft_eapol2_ies_build(struct _OCTET_STRING *EapolKeyMsgSend);
void rtw_ft_set_key(void);
int rtw_ft_pmkid_insert(u8 *ies, u32 *ies_len, u8 *pmkid);
int rtw_ft_gtk_subelem_process(u8 *gtk_elem, u32 gtk_elem_len);
int rtw_ft_pmk_r1_derive(u8 *pmk_r0, u8 pmk_r0_len, u8 *pmk_r0_name, u8 *r1kh_id,
						 u8 *s1kh_id, u8 *pmk_r1, u8 *pmk_r1_name);
int rtw_ft_pmk_r1_to_ptk(u8 *pmk_r1, u32 pmk_r1_len, u8 *snonce, u8 *anonce,
						 u8 *sta_addr, u8 *bssid, u8 *ptk);
int rtw_ft_mic(u8 *kck, u32 kck_len, u8 *sta_addr, u8 *ap_addr, u8 transaction_seqnum,
			   u8 *mdie, u32 mdie_len, u8 *ftie, u32 ftie_len,
			   u8 *rsnie, u32 rsnie_len, u8 *ric, u32 ric_len, u8 *mic);
#endif

#endif /* __RTW_FT_H_ */
