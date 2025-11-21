/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLOADER_FLASH_FTL_H
#define _FLOADER_FLASH_FTL_H

/* Includes ------------------------------------------------------------------*/

#include "basic_types.h"
#include "ameba_soc.h"


/* Exported defines ----------------------------------------------------------*/

#define NAND_ONFI_MFG_LEN				12U
#define NAND_ONFI_MODEL_LEN				20U

/* Exported macros -----------------------------------------------------------*/

#define FTL_MEMSET	_memset
#define FTL_MEMCPY	_memcpy

/* Exported types ------------------------------------------------------------*/

typedef struct {
	/* For both NOR and NAND */
	u8  MID;
	u8  DID;
	u8  ExtDID;

	/* For NAND only */
	u8	MFG[NAND_ONFI_MFG_LEN];			/* Manufacture, ONFI parameter page 32-43 */
	u8	Model[NAND_ONFI_MODEL_LEN];		/* Device model, ONFI parameter page 44-63 */
	u32 PageSize;			/* Bytes per page, ONFI parameter page 80-83 */
	u16 OobSize;			/* OOB bytes per page, ONFI parameter page 84-85 */
	u32 PagesPerBlock;		/* Pages per erase block, ONFI parameter page 92-95 */
	u32 BlocksPerLun;		/* Blocks per logical unit, ONFI parameter page 96-99 */
	u8  LunsPerTarget;		/* Logical units per target, ONFI parameter page 100 */
	u16 MaxBadBlocksPerLun;	/* Max bad blocks per logical unit, ONFI parameter page 103-104 */
	u8  ReqHostEccLevel;	/* Required host ECC bits, ONFI parameter page 112 */

	u8  Targets;			/* Targets/dies */
	u32 Capacity;			/* Capacity */

	u8	Reserved[6];		/* Padding to 64 bytes */
} _PACKED_ Flash_InfoTypeDef;

/* Exported variables --------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

#endif // _FLOADER_FLASH_FTL_H

