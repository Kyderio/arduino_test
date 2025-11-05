
u8 rtw_nan_get_attr(union recv_frame *precv_frame, u8 attr_id, u8 **pattr_start);
u8 rtw_nan_get_attr_start(union recv_frame *precv_frame, u8 **ppattr_start, u16 *total_len);
u8 *rtw_nan_get_specific_attr_from_auth(u8 *pframe, uint len, u8 specific_att_id);

/****************** attr_00 ************************/
void rtw_nan_mstindi_attri_parse(u8 *pmaster_indi_attr, u8 *pbcn_interface_addr);
u8 *rtw_nan_mstindi_attri_construct(u8 *pframe, u32 *frlen);

/****************** attr_01 ************************/
void rtw_nan_cluster_attri_parse(u8 *pcluster_attr, struct anchor_mast_record_t *pamr_bcn);
u8 *rtw_nan_cluster_attri_construct(u8 *pframe, u32 *frlen);

/****************** attr_03 ************************/
u8 *rtw_nan_srvcdesc_attri_construct(u8 *pframe, u32 *frlen, struct nan_srvc_inst_t *psrvc_inst, u8 requestor_inst_id, u16 binding_bitmap);

/****************** attr_04 ************************/
u8 *rtw_nan_concap_attri_construct(u8 *pframe, u32 *frlen);

/****************** attr_0e ************************/
void rtw_nan_srvcdesc_ext_attri_parse(struct nan_peer_info_t *ppeer_info, struct sdea_attr_t *psdea_attr, u16 attr_len,
									  struct nan_peer_srvcinfo_t *ppeer_srvcinfo);
u8 *rtw_nan_srvcdesc_ext_attri_construct(u8 *pframe, u32 *frlen, struct nan_srvc_inst_t *psrvc_inst);

/****************** attr_0f ************************/
u8 *rtw_nan_devcap_attr_construct(u8 *pframe, u32 *frlen);
u8 rtw_nan_devcap_attr_parse(struct nan_peer_info_t *ppeer_info, struct dev_cap_t *pdev_cap, u8 is_allow_alloc);
u16 rtw_nan_devcap_attr_append(u8 *pbuf);

/****************** attr_10 ************************/
struct ndp_entry_t *rtw_nan_ndp_attri_parse(struct nan_peer_info_t *ppeer_info, u8 *pattr_start, u8 *pattr_start_end, u8 *pndp_type, u8 *pndp_status);
u8 *rtw_nan_ndp_attri_construct(u8 *pframe, struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, u8 ndp_type, u8 ndp_status, u32 *frlen);

/****************** attr_12 ************************/
void rtw_nan_avail_attr_config(u8 is_nego_going);
u8 *rtw_nan_avail_attr_construct(u8 *pframe, u8 ndl_status, u32 *frlen, u8 is_renego);
u8 rtw_nan_avail_attr_parse(struct nan_peer_info_t *ppeer_info, u8 *pattr_start, u8 *pattr_start_end);

/****************** attr_13 ************************/
u8 *rtw_nan_ndc_attri_contruct(u8 *pframe, struct nan_peer_info_t *ppeer_info, u8 ndl_type,
							   u8 ndl_status, u32 *frlen);
u8 rtw_nan_ndc_attri_parse(struct ndc_attr_t *pndc_attr, struct nan_peer_info_t *ppeer_info);

/****************** attr_14 ************************/
u8 rtw_nan_ndl_attri_parse(struct ndl_attr_t *pndl_attr, struct nan_peer_info_t *ppeer_info);
u8 *rtw_nan_ndl_attri_construct(u8 *pframe, struct nan_peer_info_t *ppeer_info, u8 ndl_type, u8 ndl_status, u32 *frlen);
struct ndl_attr_t *rtw_nan_ndl_attri_get(u8 *pattr_start, u8 *pattr_start_end);

/****************** attr_15 ************************/
u8 *rtw_nan_qos_attri_construct(u8 *pframe, u8 ndl_status, u32 *frlen);
void rtw_nan_qos_attri_parse(struct qos_attr_t *ndl_qos_attr, struct nan_peer_info_t *ppeer_info);

/****************** attr_1d ************************/
u8 *rtw_nan_container_attri_construct(struct nan_peer_info_t *ppeer_info, u8 *pframe, u32 *frlen);
u8 rtw_nan_container_attri_parse(struct container_attr_t *pcontainer_attr, struct nan_peer_info_t *ppeer_info);

/****************** attr_22 ************************/
void rtw_nan_ciphercuite_attri_append_4pub(struct nan_peer_info_t *ppeer_info);
u8 *rtw_nan_ciphercuite_attri_construct_ndp(u8 *pframe, struct ndp_entry_t *pndp_entry, u8 ndp_type, u8 ndp_status, u32 *frlen);
u8 *rtw_nan_ciphercuite_attri_construct_4pub(u8 *pframe, u32 *frlen, struct nan_srvc_inst_t *psrvc_inst);
u8 rtw_nan_ciphercuite_attri_parse(struct csia_attr_t *pcipher_cuite, struct ndp_entry_t *pndp_entry);

/****************** attr_23 ************************/
u8 *rtw_nan_seccctx_attri_construct_4pub(u8 *pframe, u32 *frlen, struct nan_srvc_inst_t *psrvc_inst);
u8 *rtw_nan_seccctx_attri_construct_ndp(u8 *pframe, struct ndp_entry_t *pndp_entry, u8 ndp_type, u8 ndp_status, u32 *frlen);
u8 rtw_nan_seccctx_attri_parse(struct scia_attr_t *pscia_attr, struct ndp_entry_t *pndp_entry);

/****************** attr_24 ************************/
u8 *rtw_nan_sharekey_attri_construct(u8 *pframe, u32 *frlen, struct nan_peer_info_t *ppeer_info);
u8 *rtw_nan_sharekey_attri_construct_ndp(u8 *pframe, struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry, u8 ndp_type,
		u8 ndp_status, u32 *frlen);
u8 rtw_nan_sharekey_attri_ndp_parse(struct sharedkey_attr_t *psharedkey_attr, struct nan_peer_info_t *ppeer_info, struct ndp_entry_t *pndp_entry);
void rtw_nan_sharekey_attri_parse(struct nan_peer_info_t *ppeer_info, struct sharedkey_attr_t *skda_attr, u16 attr_len);

/****************** attr_2a ************************/
u8 *rtw_nan_devcap_ext_attri_construct(u8 *pframe, u32 *frlen);
void rtw_nan_devcap_ext_attri_append(struct nan_peer_info_t *ppeer_info, void *data, u16 data_len);
void rtw_nan_devcap_ext_attri_parse(struct nan_peer_info_t *ppeer_info, struct devcap_eattr_t *dcea_attr, u16 attr_len);

/****************** attr_2b ************************/
u8 *rtw_nan_identity_attri_construct_4pub(u8 *pframe, u32 *frlen);
void rtw_nan_identity_attri_append(struct nan_peer_info_t *ppeer_info);
void rtw_nan_identity_attri_parse(struct nan_peer_info_t *ppeer_info, struct identity_attr_t *pidentity_attr, u16 attr_len);

/****************** attr_2c ************************/
u8 *rtw_nan_pairbstrap_attri_construct(u8 *pframe, u32 *frlen, struct nan_srvc_inst_t *psrvc_inst, u8 *peer_addr);
void rtw_nan_pairbstrap_attri_append(struct nan_peer_info_t *ppeer_info, void *data, u16 data_len);
void rtw_nan_pairbstrap_attri_parse(struct nan_peer_info_t *ppeer_info, struct npba_attr_t *npba_attr, u16 attr_len,
									struct nan_peer_srvcinfo_t *ppeer_srvcinfo);

