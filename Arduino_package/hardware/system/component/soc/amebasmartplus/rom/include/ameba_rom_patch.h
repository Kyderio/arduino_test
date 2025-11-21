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


// add your function statements here

_LONG_CALL_ void Pinmux_Config(u8 PinName, u32 PinFunc);
_LONG_CALL_ u32 SYSCFG_RLVersion(void);
_LONG_CALL_ u32 SYSCFG_GetRLNum(void);
_LONG_CALL_ void AUDIO_SP_SetI2S3ExtDoutPinmux(u32 state);
_LONG_CALL_ void AUDIO_SP_SetI2S3ExtDinPinmux(u32 state);
_LONG_CALL_ void AUDIO_SP_SetI2S3ExtCKPinmux(u32 state);
_LONG_CALL_ void AUDIO_SP_SetI2S2Ext2DoutPinmux(u32 state);
_LONG_CALL_ void AUDIO_SP_SetI2S2Ext2CKPinmux(u32 state);
_LONG_CALL_ void AUDIO_SP_SetI2S2Ext1CKPinmux(u32 state);

#ifdef CONFIG_ARM_CORE_CM4
#include "ameba_secure_boot.h"

int SBOOT_GetMdType_B(u8 HashId, SHA2_TYPE *MdType, u8 *IsHmac);
int SBOOT_Validate_Algorithm_B(u8 *AuthAlg, u8 *HashAlg, u8 ManiAuth, u8 ManiHash);
int SBOOT_Validate_PubKey_B(u8 AuthAlg, u8 *Pk, u8 *Hash);
int SBOOT_Validate_Signature_B(u8 AuthAlg, u8 HashAlg, u8 *Pk, u8 *Msg, u32 Len, u8 *Sig);
int SBOOT_Validate_ImgHash_B(u8 HashAlg, u8 *ImgHash, SubImgInfo_TypeDef *SubImgInfo, u8 Num);
int SBOOT_SignatureVerify_B(u8 *PubKeyHash, Manifest_TypeDef *Manifest, SubImgInfo_TypeDef *SubImgInfo, u8 SubImgCnt);

int CRYPTO_SHA_Init_B(HAL_CRYPTO_ADAPTER *pIE);
int CRYPTO_OTPKey_SHA_Init_B(u32 keynum, u32 status);
int rtl_crypto_sha2_init_B(const SHA2_TYPE sha2type, hw_sha_context *ctx);
int rtl_crypto_sha2_update_B(u8 *message, u32 msglen, hw_sha_context *ctx);
int rtl_crypto_sha2_final_B(u8 *pDigest, hw_sha_context *ctx);
int rtl_crypto_hmac_sha2_update_B(u8 *message, u32 msglen, hw_sha_context *ctx);
int rtl_crypto_hmac_sha2_final_B(u8 *pDigest, hw_sha_context *ctx);

int SBOOT_GetMdType_A(u8 HashId, SHA2_TYPE *MdType, u8 *IsHmac);
int SBOOT_Validate_Algorithm_A(u8 *AuthAlg, u8 *HashAlg, u8 ManiAuth, u8 ManiHash);
int SBOOT_Validate_PubKey_A(u8 AuthAlg, u8 *Pk, u8 *Hash);
int SBOOT_Validate_Signature_A(u8 AuthAlg, u8 HashAlg, u8 *Pk, u8 *Msg, u32 Len, u8 *Sig);
int SBOOT_Validate_ImgHash_A(u8 HashAlg, u8 *ImgHash, SubImgInfo_TypeDef *SubImgInfo, u8 Num);
int SBOOT_SignatureVerify_A(u8 *PubKeyHash, Manifest_TypeDef *Manifest, SubImgInfo_TypeDef *SubImgInfo, u8 SubImgCnt);

int CRYPTO_SHA_Init_A(HAL_CRYPTO_ADAPTER *pIE);
int CRYPTO_OTPKey_SHA_Init_A(u32 keynum, u32 staAtus);
int rtl_crypto_sha2_init_A(const SHA2_TYPE sha2type, hw_sha_context *ctx);
int rtl_crypto_sha2_update_A(u8 *message, u32 msglen, hw_sha_context *ctx);
int rtl_crypto_sha2_final_A(u8 *pDigest, hw_sha_context *ctx);
int rtl_crypto_hmac_sha2_update_A(u8 *message, u32 msglen, hw_sha_context *ctx);
int rtl_crypto_hmac_sha2_final_A(u8 *pDigest, hw_sha_context *ctx);
#endif

/* MANUAL_GEN_END */

#endif
