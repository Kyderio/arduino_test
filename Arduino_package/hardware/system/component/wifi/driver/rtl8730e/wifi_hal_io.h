/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
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

#ifndef _WIFI_HAL_IO_H_
#define _WIFI_HAL_IO_H_

extern u8 rtw_read8(u32 addr);
extern u16 rtw_read16(u32 addr);
extern u32 rtw_read32(u32 addr);
extern s32 rtw_write8(u32 addr, u8 val);
extern s32 rtw_write16(u32 addr, u16 val);
extern s32 rtw_write32(u32 addr, u32 val);

#endif	//_WIFI_HAL_IO_H_

