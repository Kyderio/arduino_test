/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This is ROM code section.
 *
 *
 ******************************************************************************/
#ifndef __ROM_RTW_RATE_H_
#define __ROM_RTW_RATE_H_

int wifi_rom_cckratesonly_included(unsigned char *rate, int ratelen);
int wifi_rom_cckrates_included(unsigned char *rate, int ratelen);
void wifi_rom_updateBratetbl(u8	*mBratesOS);
void wifi_rom_updateBratetbl_softap(u8 *bssrateset, u32 bssratelen);


#endif

