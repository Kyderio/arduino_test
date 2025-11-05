#ifndef __ROM_WIFI_HAL_DEBUG_H__
#define __ROM_WIFI_HAL_DEBUG_H__

#define OFFSET_BB   0x10000
#define MASK_RF		0xfffff

void rom_wifi_hal_dbg_no_beacon(u8 param);
void rom_wifi_hal_dbg_fifo(char *cmd_ptr, u32 param);
void rom_wifi_hal_dbg_rx_filter(char *cmd_ptr, u32 param);
void rom_wifi_hal_dbg_plcp(char *cmd_ptr, u32 param);


#endif
