/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_WAKEPIN_H_
#define _AMEBA_WAKEPIN_H_


#define	WAKEPIN_0							((u32)0x00000000)
#define	WAKEPIN_1							((u32)0x00000001)
#define	WAKEPIN_2							((u32)0x00000002)
#define	WAKEPIN_3							((u32)0x00000003)

enum wakepin_config {
	LOW_LEVEL_WAKEUP	= 0, /* Wake up on falling edge*/
	HIGH_LEVEL_WAKEUP	= 1, /* Wake up on rising edge*/
	DISABLE_WAKEPIN	= 2, /* disable wakepin */
};

struct WAKEPIN_TypeDef {
	u32 wakepin;
	enum wakepin_config config;
};

int WakePin_Get_Idx(void);
void Wakepin_Select(u32 pin_sel);
void Wakepin_Setting(u32 PinIdx, u32 Polarity);
void Wakepin_Debounce_Setting(u32 Dbnc_cycle, u32 Status);
void WakePin_ClearINT(u32 wakepin);

#endif  //_AMEBA_WAKEPIN_H_
