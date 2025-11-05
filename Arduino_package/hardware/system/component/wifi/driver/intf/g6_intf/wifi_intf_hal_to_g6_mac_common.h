#ifndef __API_MAC_H__
#define __API_MAC_H__

int rtw_hal_mac_send_h2c(struct rtw_g6_h2c_hdr *hdr, u32 *pvalue);
int rtw_hal_mac_send_h2c_ameba(u8 ElementID, u32 CmdLen, u32 *pvalue);

void rtw_hal_mac_lamode_cfg_buf(u8 buf_sel, u32 *addr_start, u32 *addr_end);
u32 rtw_hal_mac_lamode_trig(u8 trig);
void rtw_hal_mac_get_lamode_st(u8 *la_state, u16 *la_finish_addr, bool *la_round_up, bool *la_loss_data);

void rtw_hal_mac_set_tpu_mode(enum rtw_tpu_op_mode op_mode_new, u8 band);
void rtw_hal_mac_write_pwr_limit_reg(enum phl_band_idx phy_idx);
void rtw_hal_mac_write_pwr_by_rate_reg(enum phl_band_idx phy_idx);
void rtw_hal_mac_write_pwr_limit_rua_reg(u8 band);
int rtw_hal_mac_write_msk_pwr_reg(u8 band, u32 offset, u32 mask, u32 val);
int rtw_hal_mac_get_pwr_reg(u8 band, u32 offset, u32 *val);
void rtw_hal_mac_write_pwr_ofst_mode(u8 band);
void rtw_hal_mac_write_pwr_ofst_bw(u8 band);
void rtw_hal_mac_write_pwr_ref_reg(u8 band);
void rtw_hal_mac_set_pwr_reg(u8 band, u32 offset, u32 val);
void rtw_hal_mac_write_pwr_limit_en(u8 band);
void rtw_hal_mac_read_phy_efuse(u32 addr, u32 size, u8 *value);
#endif
