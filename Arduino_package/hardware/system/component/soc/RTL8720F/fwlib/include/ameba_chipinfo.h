/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_CHIPINFO_H_
#define _AMEBA_CHIPINFO_H_

/** @defgroup PSRAM_Size_define
  * @{
  */
enum PSRAM_type {
	PSRAM_A_32Mb = 0x01,
	PSRAM_A_64Mb = 0x02,
	PSRAM_A_128Mb = 0x03,
	PSRAM_A_256Mb = 0x04,
	PSRAM_A_512Mb = 0x05,

	PSRAM_B_32Mb = 0x11,
	PSRAM_B_64Mb = 0x12,
	PSRAM_B_128Mb = 0x13,
	PSRAM_B_256Mb = 0x14,
	PSRAM_B_512Mb = 0x15,

	PSRAM_NotClear = 0xAA,
	PSRAM_None = 0xFF,
};
/**
  * @}
  */


/** @defgroup MEMORY_Type_define
  * @{
  */
enum MEMORY_type {
	MEMORY_MCM_PSRAM = 0,
	MEMORY_ONE_FLASH,
	MEMORY_TWO_FLASH,
	MEMORY_NOT_CLEAR,
};
/**
  * @}
  */



/** @defgroup CHIPINFO_TypeDef
  * @{
  */
typedef struct {
	u8 sub_num;
	u8 package_num;
	u16 bd_num;
	u32 memory_type;
} CHIPINFO_TypeDef;
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup HWINFO_Exported_Functions HWINFO Exported Functions
  * @{
  */
_LONG_CALL_ u8 EFUSE_GetChipVersion(void);
_LONG_CALL_ u16 ChipInfo_BDNum(void);
_LONG_CALL_ u8 ChipInfo_PSRAMType(void);
_LONG_CALL_ u8 ChipInfo_MemoryType(void);
_LONG_CALL_ bool ChipInfo_PsramExists(void);
_LONG_CALL_ u32 ChipInfo_PsramBoundary(void);
_LONG_CALL_ u32 ChipInfo_MCM_Info(void);
_LONG_CALL_ void ChipInfo_GetSocName_ToBuf(char *buf, size_t buflen);
/**
  * @}
  */

#endif
