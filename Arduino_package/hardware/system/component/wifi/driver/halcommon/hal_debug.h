#ifndef __HAL_DEBUG_H__
#define __HAL_DEBUG_H__

#define PHYDM_MSG_LEN	1024

struct dbg_func_t {
	u8 cmdname[17];
	void (*func)(char *cmd_ptr, u32 extra_arg);
};

void wifi_hal_dbg_tx_q(char *cmd_ptr, u32 extra_arg);
void wifi_hal_fw_dbg_en(char *cmd_ptr, u32 dbg_bitmap);
void wifi_hal_legacy_ps_listen_interval(char *cmd_ptr, u32 extra_arg);
void wifi_hal_phydm_dbg(char *cmd_ptr, u32 extra_arg);

#ifdef CONFIG_IEEE80211K
void wifi_hal_wx_priv_rrm(char *cmd_ptr, u32 extra_arg);
#endif

void wifi_hal_dbg_wpa_mode(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_tx_pwr_get(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_tx_pwr_set(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_fix_rate(char *cmd_ptr, u32 extra_arg);

#if (PHYDM_VERSION == 3)
void wifi_hal_dbg_fix_bcc(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_bb_log(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_bb_ability(char *cmd_ptr, u32 extra_arg);
#endif

void wifi_hal_dbg_heap(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_module(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_regu(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_os_static(char *cmd_ptr, u32 extra_arg);

void wifi_hal_dbg_power_save(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_write_mac_reg(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_write_bb_reg(char *cmd_ptr, u32 extra_arg);
void wifi_hal_dbg_read_rf_reg(char *cmd_ptr, u32 extra_arg);

void wifi_hal_check_dma_error(void);
#endif
