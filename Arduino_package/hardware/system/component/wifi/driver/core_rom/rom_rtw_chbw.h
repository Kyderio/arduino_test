/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This is ROM code section.
 *
 *
 ******************************************************************************/
#ifndef __ROM_RTW_CHBW_H_
#define __ROM_RTW_CHBW_H_

u8 wifi_rom_get_center_ch(u8 channel, u8 chnl_bw, u8 chnl_offset);
u8 wifi_rom_get_offset_by_chbw(u8 ch, u8 bw, u8 *r_offset);
u8 wifi_rom_get_primary_ch(u8 center_ch, u8 chnl_bw, u8 chnl_offset40, u8 chnl_offset80);

#endif

