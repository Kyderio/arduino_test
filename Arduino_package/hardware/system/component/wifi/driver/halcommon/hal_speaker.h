/******************************************************************************
 *
 * Copyright(c) 2007 - 2013 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __WIFI_HAL_SPEAKER_H__
#define __WIFI_HAL_SPEAKER_H__

void wifi_hal_speaker_init(void *param);
void wifi_hal_speaker_audio_latch_count(u8 latch_port, u8 latch_period);
void wifi_hal_speaker_txrpt_fetch(void);

u32 wifi_hal_speaker_tsf_interrupt(void	*param);
u32 wifi_hal_speaker_dma_interrupt(void	*param);

void wifi_hal_async_i2s_tsf_init(void);
void wifi_hal_async_init(u8 mode);
void wifi_hal_async_set_tsf_period(u32 period);
u64 wifi_hal_async_get_wmac_tsf_ns(void);
u64 wifi_hal_async_get_i2s_tsf_counter(void);
void wifi_hal_async_set_drift(u32 drift);
void wifi_hal_async_register_interrupt_irq(void (*callback)(uint));

void wifi_hal_speaker_set_tsf_timer(u8 enable, u64 tsft, u8 port);
#endif
