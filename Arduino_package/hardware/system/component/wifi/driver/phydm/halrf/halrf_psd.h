/******************************************************************************
 *
 * Copyright(c) 2007 - 2017 Realtek Corporation.
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
 *****************************************************************************/

#ifndef __HALRF_PSD_H__
#define __HALRF_PSD_H__

struct _halrf_psd_data {
	u32 point;
	u32 start_point;
	u32 stop_point;
	u32 bb_backup[30];
	u32 psd_data[320];
	u8  psd_progress: 1;
};

u32
halrf_psd_init(
	void);

void _halrf_init_psd_iqk_8721da(u8 iq_path, u32 avg, u32 fft);
u32 _halrf_get_point_psd_data_8721da(s32 point);
void _halrf_restore_psd_iqk_8721da(void);

u32
halrf_psd_query(
	u32 *outbuf,
	u32 buf_size);

u32
halrf_init_psd(u8 iq_path, u32 avg, u32 fft);

u32 halrf_get_point_psd(s32 point);

void halrf_query_psd_all(u32 point, u32 start_point, u32 stop_point);

u32 halrf_restore_psd(void);

#endif /*#__HALRF_PSD_H__*/
