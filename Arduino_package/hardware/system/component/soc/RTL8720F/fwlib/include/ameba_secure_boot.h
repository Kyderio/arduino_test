/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _AMEBA_SECURITY_BOOT_H_
#define _AMEBA_SECURITY_BOOT_H_

#include "bootutil_misc.h"

#define SBOOT_ERR_AUTH_NOT_SUPPORT					-1
#define SBOOT_ERR_PK_HASH_INVALID					-2
#define SBOOT_ERR_SIGN_INVALID						-3
#define SBOOT_ERR_ECDSA_CURVE_NOT_SUPPORT			-4
#define SBOOT_ERR_HASH_NOT_SUPPORT					-6
#define SBOOT_ERR_IMG_HASH_INVALID					-7
#define SBOOT_ERR_PK_HASH_ENGINE_ERROR				-8
#define SBOOT_ERR_EDDSA_HASH_ENGINE					-9
#define SBOOT_ERR_ECDSA_HASH_ENGINE					-10
#define SBOOT_ERR_IMG_HASH_ENGINE					-11
#define SBOOT_ERR_AUTH_ALG_NOT_MATCH				-12
#define SBOOT_ERR_HASH_ALG_NOT_MATCH				-13

#define IMG_SIZE_INVALID							-0xFFFE
#define IMG_INVALID									-0xFFFF

/*ImgID_TypeDef*/
#define IMGID_BOOT	0
#define IMGID_NSPE	1
#define IMGID_SPE	2
#define IMGID_BL1	3

/*AuthAlg_TypeDef*/
#define AUTHID_EDDSA_25519				0
#define AUTHID_ECDSA_SECP192R1			1 /* PKE_ECP_CURVE_SECP192R1 */
#define AUTHID_ECDSA_SECP224R1			2
#define AUTHID_ECDSA_SECP256R1			3
#define AUTHID_ECDSA_SECP384R1			4
#define AUTHID_ECDSA_BP256R1			6
#define AUTHID_ECDSA_BP384R1			7
#define AUTHID_ECDSA_BP512R1			8
#define AUTHID_ECDSA_CURVE25519			9
#define AUTHID_ECDSA_SECP192K1			10
#define AUTHID_ECDSA_SECP224K1			11
#define AUTHID_ECDSA_SECP256K1			12

#define SBOOT_ECP_MAX_BITS				512   /**< Maximum bit size of ecdsa groups */
#define SBOOT_ECP_MAX_BYTES				( ( SBOOT_ECP_MAX_BITS + 7 ) / 8 )
#define SBOOT_ECP_MAX_PT_LEN			( 2 * SBOOT_ECP_MAX_BYTES)
#define SBOOT_ECP_BIT2BYTE(x)			( ( (x) + 7 ) / 8 )

#define IS_EDDSA(x)				(x == AUTHID_EDDSA_25519)
#define IS_ECDSA(x)				(x == AUTHID_ECDSA_SECP192R1) || \
								(x == AUTHID_ECDSA_SECP224R1) || \
								(x == AUTHID_ECDSA_SECP256R1) || \
								(x == AUTHID_ECDSA_SECP384R1) || \
								(x == AUTHID_ECDSA_BP256R1) || \
								(x == AUTHID_ECDSA_BP384R1) || \
								(x == AUTHID_ECDSA_BP512R1) || \
								(x == AUTHID_ECDSA_CURVE25519) || \
								(x == AUTHID_ECDSA_SECP192K1) || \
								(x == AUTHID_ECDSA_SECP224K1) || \
								(x == AUTHID_ECDSA_SECP256K1)

/*HashAlg_TypeDef*/
#define HASHID_SHA256		0
#define HASHID_SHA384		1
#define HASHID_SHA512		2
#define HASHID_HMAC256		3
#define HASHID_HMAC384		4
#define HASHID_HMAC512		5

#define HASH_MAX_LEN		64
#define PKEY_MAX_LEN		144 //((((2 * MBEDTLS_ECP_MAX_BYTES -1) >> 4) + 1) << 4) //144 byte (16-byte aligned, format type field not included)
#define SIGN_MAX_LEN		144 //((((2 * MBEDTLS_ECP_MAX_BYTES -1) >> 4) + 1) << 4) //144 byte (16-byte aligned, raw data format, not ASN.1)

#define CRYPTO_CHK(f, errno) do { if((ret = f) != 0) {ret = errno; goto exit;}} while( 0 )

#define MANIFEST_SIZE_4K_ALIGN		0x1000

/* Manifest RSIP Configuration (RSIPConfig) */
#define MANIFEST_BOOTLOADER_IMG1_ID                1
#define MANIFEST_AP_NP_IMG2_ID                     2
#define MANIFEST_SECURE_IMG3_ID                    3
#define MANIFEST_IMG_ID_IS_VALID(x)                (x == MANIFEST_BOOTLOADER_IMG1_ID) || \
												   (x == MANIFEST_AP_NP_IMG2_ID) || \
												   (x == MANIFEST_SECURE_IMG3_ID)

#define MANIFEST_RSIP_GET_IMG_MODE(id, cfg)                ((u32)(((cfg >> 2 * (id)) & 0x00000003)))  /* IMG1 is bit[7:6] */

/* These 3 mode define keep same with manifest.json */
#define MANIFEST_RSIP_CTR_MODE                     0  /* rsip CTR MODE */
#define MANIFEST_RSIP_XTS_MODE                     1  /* rsip XTS MODE */
#define MANIFEST_RSIP_GCM_MODE                     2  /* rsip GCM MODE */
#define MANIFEST_RSIP_INVALID_MODE                 3  /* rsip INVALID MODE */

#define MANIFEST_RSIP_GCM_4_BYTE_TAG               0  /* 4 byte gcm tag length */
#define MANIFEST_RSIP_GCM_8_BYTE_TAG               1  /* 8 byte gcm tag length */
#define MANIFEST_RSIP_GCM_16_BYTE_TAG              2  /* 16 byte gcm tag length */
#define MANIFEST_RSIP_GCM_INVALID_TAG              3  /* invalid gcm tag length */
#define MANIFEST_RSIP_CFG_GET_GCM_TAG_LEN(x)       ((u32)(((x >> 0) & 0x00000003)))  /* Manifest_TypeDef.RSIPConfig bit[1:0]: gcm tag length. 2b`00: 4 byte length; 2b`01: 8 byte length; 2b`10: 16 byte length; default is 2b`11: invalid */

typedef struct {
	u32 Pattern[2];
	u8 Rsvd1[7];
	u8 RSIPConfig;
	u8 Ver;
	u8 ImgID;
	u8 AuthAlg;
	u8 HashAlg;
	u16 MajorImgVer;
	u16 MinorImgVer;
	u32 ImgSize;
	u32 SecEpoch;
	u8 RsipIV[16];
	u8 ImgHash[HASH_MAX_LEN];
	u8 SBPubKey[PKEY_MAX_LEN];
	u8 Signature[SIGN_MAX_LEN];
} Manifest_TypeDef;

typedef struct {
	u32 Addr;
	u32 Len;
} SubImgInfo_TypeDef;

fih_ret SBOOT_Validate_Algorithm(u8 *AuthAlg, u8 *HashAlg, u8 ManiAuth, u8 ManiHash);
fih_ret SBOOT_Validate_PubKey(u8 AuthAlg, u8 *Pk, u8 *Hash);
fih_ret SBOOT_Validate_Signature(u8 AuthAlg, u8 HashAlg, u8 *Pk, u8 *Msg, u32 Len, u8 *Sig);
fih_ret SBOOT_Validate_ImgHash(u8 HashAlg, u8 *ImgHash, SubImgInfo_TypeDef *SubImgInfo, u8 Num);
fih_ret SBOOT_SignatureVerify(u8 *PubKeyHash, Manifest_TypeDef *Manifest, SubImgInfo_TypeDef *SubImgInfo, u8 SubImgCnt);
fih_ret BOOT_ROM_SignatureCheck(Manifest_TypeDef *Manifest, SubImgInfo_TypeDef *SubImgInfo, u8 SubImgNum);
fih_ret BOOT_ROM_OTFCheck(u32 start_addr, u32 end_addr, u32 IV_index, u32 OTF_index,
						  u8 RSIP_KEY_ID, u32 GCM_TagBase, u8 RSIPConfig, u8 img_index);
void SBOOT_Verify_BootFromRAM(void);
void BOOT_ROM_CheckGCM(Manifest_TypeDef *Manifest, SubImgInfo_TypeDef *SubImgInfo, u32 ImgPhyAddr, u8 img_index);
__NO_RETURN void SBOOT_Validate_Fail_Stuck(u32 wdg_fresh);
#endif

