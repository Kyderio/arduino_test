/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_ROM_PATCH_H_
#define _AMEBA_ROM_PATCH_H_

/* AUTO_GEN_START */

/* AUTO_GEN_END */

/* MANUAL_GEN_START */

//Please add your defination here

#define SYSCFG_OTP_ROM_PATCH_DIS          0
#define SYSCFG_OTP_ROM_PATCH_EMPTY        3

/* OTPC_LOGICAL_Format_definitions */
#define OTP_LTYP0					                0x00UL
#define OTP_LTYP1								   	0x01UL
#define OTP_LTYP2								   	0x02UL
#define OTP_LTYP3								   	0x03UL
#define OTP_GET_LTYP(x)						    	((u32)(((x) >> 28) & 0x0000000F))

#define OTP_LBASE_EFUSE						    	0x07UL
#define OTP_LBASE_PAD								0x06UL
#define OTP_LBASE_REG								0x0FUL
#define OTP_LBASE_ROM								0x0EUL

#define OTP_GET_LTYP1_DATA(x)						((u32)(((x) >> 16) & 0x000000FF))
#define OTP_GET_LTYP1_BASE(x)						((u32)(((x) >> 12) & 0x0000000F))
#define OTP_GET_LTYP1_OFFSET(x)						((u32)(((x) >> 0) & 0x00000FFF))

#define OTP_GET_LTYP2_LEN(x)						((u32)(((((x) >> 24) & 0x00F) + 1) << 2)) /* Byte_len = 4 * (Word_len + 1) */
#define OTP_SET_LTYP2_LEN(x)						((u32)((((x) - 1) & 0x03F) >> 2))
#define OTP_GET_LTYP2_BASE(x)						((u32)(((x) >> 12) & 0x0000000F))
#define OTP_GET_LTYP2_OFFSET(x)						((u32)(((x) >> 0) & 0x00000FFF))

#define OTP_GET_LTYP3_OFFSET(x)						((u32)(((x) >> 0) & 0x0FFFFFFF))

#define OTP_CRC0_BASE								0x370
#define OTP_CRC1_BASE								0x372
#define OTP_CRC2_BASE								0x374
#define OTP_CRC3_BASE								0x376

#define OTP_RTKPATCH_BASE							0x500
#define OTP_RTKPATCH_END							0x6FC

#define OTP_LPGPKT_SIZE 							16

typedef struct {
	u32 address; /*!< Specifies the register going to config.
      0xFFFFFFFF means end of the register config sequence */

	u32 cmd;/*!<  Bit0~ Bit7 Specifies the read/write/polling/delay/end command.
      Bit8~Bit12 specifies the config sequence index range 0x0~0x1E, 0x1F means all allowed.
      BIT13 means whether need skip this cmd, Delay CMD won't care this bits.
      BIT14~ BIT31 rsvd*/

	u32 bitsc; /* bit mask clear or polling target */
	u32 bitss; /* bit mask set or polling mask */
} REG_CONFIG_SEQ;

enum ROM_PATCH_CMD {
	ROM_PATCH_CMD_INVALID = 0x00,
	ROM_PATCH_CMD_READ    = 0xFA,
	ROM_PATCH_CMD_WRITE   = 0xFB,
	ROM_PATCH_CMD_POLLING = 0xFC,
	ROM_PATCH_CMD_DELAY   = 0xFD,
	ROM_PATCH_CMD_LOGE    = 0xFE,
	ROM_PATCH_CMD_END     = 0xFF,
};

typedef struct {
	u32 address; /*!< Specifies the register going to config.
      0xFFFFFFFF means end of the register config sequence */

	u8 rsvd; /* reserved for further use */
	u8 cmd;/*specifies the cmd */
	u16 index; /* specifies the config sequence index  */

	u32 bitsc; /* bit mask clear or polling target */
	u32 bitss; /* bit mask set or polling mask */
} _PACKED_ ROM_PATCH_TABLE;

/* MANUAL_GEN_END */

#endif
