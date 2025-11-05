#ifndef __ROM_HAL_DEBUG_H__
#define __ROM_HAL_DEBUG_H__

struct rom_component_status {
	unsigned int mutex_total_num;
	unsigned int mutex_buf_used_num;
	unsigned int mutex_max_buf_used_num;
	unsigned int mutex_dynamic_num;

	unsigned int sema_total_num;
	unsigned int sema_buf_used_num;
	unsigned int sema_max_buf_used_num;
	unsigned int sema_dynamic_num;

	unsigned int timer_total_num;
	unsigned int timer_buf_used_num;
	unsigned int timer_max_buf_used_num;
	unsigned int timer_dynamic_num;
};

void _rom_wifi_hal_debug_dump(unsigned int start_addr, unsigned int end_addr, u8 read_bytes,
							  u8 line_tag, u8 num_in_line, u8 page_tag, u16 num_in_page,
							  u8 is_rf, u32 rf_segment_header, u32 base);

void rom_wifi_hal_dbg_regu(u8 regu_en, u8 Regulation, u8 by_lmt, u8 ChannelPlan, u8 ChPlanVer, u8 *country_code,
						   u8 CounCodeVer); //data type of country_code in rom is char *
void rom_wifi_hal_dbg_os_static(struct rom_component_status *rom_comp_status);
void rom_wifi_hal_dbg_wpa_mode(int set_result, u32 wpa_mode);

void rom_wifi_hal_dbg_read_mac_reg(char *cmd_ptr, u32 extra_arg);

#endif
