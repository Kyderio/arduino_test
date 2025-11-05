/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_CHIPINFO_ROM_H_
#define _AMEBA_CHIPINFO_ROM_H_

/* MANUAL_GEN_START */

#define OTP_CHIPVER							0x7F0
#define OTP_GET_CHIP_VERSION(x)				((u32)(((x >> 0) & 0x0000001F)))
#define OTP_GET_ES_FLAG(x)					((u32)(((x >> 5) & 0x00000001)))

#define OTP_UUID							0x7F4
#define OTP_LOT_NUM							0x7F8
#define OTP_INFO							0x7FC
/* remark-info: 0x7FC~0x7FD */
#define OTP_GET_CPUCLK(x)					((u32)(((x >> 0) & 0x00000003)))
#define OTP_GET_SECURITY(x)					((u32)(((x >> 2) & 0x00000003)))
#define OTP_GET_BTPROTOCOL(x)				((u32)(((x >> 4) & 0x00000003)))
#define OTP_GET_802PROTOCOL(x)				((u32)(((x >> 6) & 0x00000003)))
#define OTP_GET_RSVD0(x)					((u32)(((x >> 0) & 0x00000003)))
#define OTP_GET_WIFI6SUPPORT(x)				((u32)(((x >> 2) & 0x00000003)))
#define OTP_GET_RSVD2(x)					((u32)(((x >> 4) & 0x00000003)))
#define OTP_GET_RSVD3(x)					((u32)(((x >> 6) & 0x00000003)))

#define OTP_CHIPINFO						0x7FF
#define OTP_GET_PACKAGE_NUM(x)						((u32)(((x >> 0) & 0x0000001F)))
#define OTP_GET_INTERNAL_BDNUM(x)					((u32)(((x >> 5) & 0x00000007)))

enum OTP_Info {
	OTP_CPUClk = 0,
	OTP_Security = 1,
	OTP_BTProtocol = 2,
	OTP_802Protocol = 3,
	OTP_RSVD0 = 4,
	OTP_WIFI6Support = 5,
	OTP_RSVD2 = 6,
	OTP_RSVD3 = 7,
};

/** @defgroup EFUSE_Physical_Address_functions
  * @{
  */
_LONG_CALL_ u8 EFUSE_GetESFlag(void);
_LONG_CALL_ void EFUSE_GetUUID(u32 *UUID);
_LONG_CALL_ u8 EFUSE_Get_Info(u32 FuncID);
_LONG_CALL_ u8 EFUSE_GetChipInfo(void);
/**
  * @}
  */
/* MANUAL_GEN_END */

#endif

