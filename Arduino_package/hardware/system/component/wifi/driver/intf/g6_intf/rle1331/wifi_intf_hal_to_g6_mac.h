#ifndef __RTL8720E_API_MAC_H__
#define __RTL8720E_API_MAC_H__

void rtw_hal_mac_set_xcap(u8 sc_xo, u32 value);
void rtw_hal_mac_get_xcap(u8 sc_xo, u32 *value);

void rtw_hal_mac_lamode_cfg(u8 func_en,
							u8 restart_en, u8 timeout_en, u8 timeout_val, u8 data_loss_imr, u8 la_tgr_tu_sel, u8 tgr_time_val);
void rtw_hal_mac_get_buffer_data(u32 start_addr, u8 *buf, u32 len, u32 dbg_path);

void rtw_hal_tx_pause(bool tx_pause, enum tx_pause_rson rson);
void rtw_hal_mac_update_mac_address(u8 mac_id, u8 *mac_addr);
void rtw_hal_mac_update_sounding_cfg(u8 enable, u8 *mac_addr);
void rtw_hal_mac_set_ru_cfg(struct sta_mlme_priv *psta_mlmepriv);
void rtw_hal_mac_bfee_set_vht_gid(u8 *gid_vld, u8 *user_pos);
#endif
