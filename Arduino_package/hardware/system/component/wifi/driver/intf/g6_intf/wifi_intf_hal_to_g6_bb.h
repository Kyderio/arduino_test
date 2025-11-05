#ifndef __WIFI_HAL_API_BB_H__
#define __WIFI_HAL_API_BB_H__

/*this file calls halbb's APIs*/
void rtw_hal_bb_set_pow_patten_sharp(u8 channel, u8 is_cck, u8 sharp_id, enum phl_phy_idx phy_idx);
bool rtw_hal_bb_physts_parsing(u8 iface_type, struct rx_pkt_attrib	*pattrib, u8 *addr, u16 physts_total_length);
u8 rtw_hal_bb_acs_mntr_trigger(u16 mntr_time, u8 nhm_incld_cca);
void rtw_hal_bb_acs_mntr_result(u8 is_first_channel, u8 trigger_result, u8 survey_channel, u16 time, u8 scan_done);
#define rtw_phydm_func_disable_all()
#define rtw_phydm_func_clr(ability) halbb_ability_ops( HALBB_FUNC_CLR, ability)
#define rtw_phydm_ability_backup()
#define rtw_phydm_ability_restore()
#define rtw_phydm_ability_set()
#define rtw_phydm_ability_get()
#define wifi_hal_bb_struct_size_get()	halbb_buffer_size_get()
#ifdef CONFIG_CSI
enum csi_parsing_status rtw_hal_bb_csi_parsing(u8 *addr, u32 len, u8 *rpt_buf,
		struct rtw_csi_rpt_hdr_info *rpt_hdr, struct rtw_csi_phyinfo_rpt *phy_info, struct rtw_csi_drv_rpt *drv);
void rtw_hal_bb_csi_cfg(struct rtw_csi_bbcr_cfg *cfg);
#endif /* CONFIG_CSI */

#ifdef CONFIG_MP_INCLUDED
void rtw_hal_bb_plcp_gen(void);
#endif

void rtw_hal_bb_set_pmac_packet_tx(u8 enable,
								   u8 is_cck, u16 tx_cnt, u16 period,
								   u16 tx_time, u8 cck_lbk_en,
								   enum phl_phy_idx phy_idx);

#endif
