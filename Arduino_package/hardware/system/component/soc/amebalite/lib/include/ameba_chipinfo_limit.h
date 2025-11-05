/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "hal_platform.h"
#include "ameba_otpc.h"

#ifndef _AMEBA_CHIPINFO_LIMIT_H_
#define _AMEBA_CHIPINFO_LIMIT_H_

/* This File shall hidden for customer */
/************* 0x7FC**************/

/**********[7:6]***********/
/*Note Valide when Dsp Disable*/
/*11 or 00 DTCM Share*/
/*01 or 10 DTCM Disable*/

/**********[5:4]***********/
/*11 or 00 LE audio Enable*/
/*01 or 10 LE audio Disable*/

/**********[3:2]***********/
/*11 or 00 DSP EN*/
/*01 or 10 DSP Disable*/

/**********[1:0]***********/
/*11 or 00 CPU full speed*/
/*01 or 10 CPU half speed*/

#define CHIP_FUNCTION_LIMIT_GROUP1				0x7FC
#define SYSCFG_GET_DTCM_SHARE_CFG(x)			((u32)(((x >> 6) & 0x00000003)))
#define SYSCFG_GET_LC3_CFG(x)					((u32)(((x >> 4) & 0x00000003)))
#define SYSCFG_GET_DSP_CFG(x)					((u32)(((x >> 2) & 0x00000003)))
#define SYSCFG_GET_FULLSPEED_CFG(x)			((u32)(((x >> 0) & 0x00000003)))


/************* 0x7FD**************/

/***********[7:6]************/
/*only EA has trustzone function*/
/*11 or 00 Trustzone Enable*/
/*01 or 10 Trustzone Disable*/

/**********[5:4]***********/
/*11 or 00 Zigbee  Enable*/
/*01 or 10 Zigbee Disable*/

/**********[3:2]***********/
/*11 or 00 WIFI AX EN*/
/*01 or 10 WIFI AX Disable*/

/**********[1:0]***********/
/*11 or 00 Classic BT enable*/
/*01 or 10 Classic BT disable*/

#define CHIP_FUNCTION_LIMIT_GROUP2				0x7FD
#define SYSCFG_GET_TRUSTZONE_CFG(x)			((u32)(((x >> 6) & 0x00000003)))
#define SYSCFG_GET_ZIGBEE_CFG(x)				((u32)(((x >> 4) & 0x00000003)))
#define SYSCFG_GET_WIFI_CFG(x)					((u32)(((x >> 2) & 0x00000003)))
#define SYSCFG_GET_BREDR_CFG(x)				((u32)(((x >> 0) & 0x00000003)))


/************* 0x7FE**************/

/***********[7:6]************/
/*RSVD*/

/**********[5:4]***********/
/*RSVD*/

/**********[3:2]***********/
/*RSVD*/

/**********[1:0]***********/
/*11 or 00 CSI DISABLE*/
/*01 or 10 CSI ENABLE*/
#define CHIP_FUNCTION_LIMIT_GROUP3				0x7FE
#define SYSCFG_GET_CSI_CFG(x)					((u32)(((x >> 0) & 0x00000003)))



/*
  * @brief  Check whether DTCM in DSP is shared in OTP
  * @retval
  * TRUE: Support
  * FALSE: Do not support
  */
__STATIC_INLINE u32 ChipInfo_ShareDTCMSupport(void)
{
	u8 OTPinfo;

	OTP_Read8(CHIP_FUNCTION_LIMIT_GROUP1, &OTPinfo);

	//Bit[7] xor Bit[6] = 1'b 0:	768KB
	//Bit[7] xor Bit[6] = 1'b 1:	512KB
	if ((SYSCFG_GET_DTCM_SHARE_CFG(OTPinfo) == 3) || (SYSCFG_GET_DTCM_SHARE_CFG(OTPinfo) == 0)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
  * @brief  LC3 support in OTP
  * @retval
  * TRUE: LC3 support
  * FALSE: LC3 do not support
  */
__STATIC_INLINE u32 ChipInfo_LC3Support(void)
{
	u8 OTPinfo;

	OTP_Read8(CHIP_FUNCTION_LIMIT_GROUP1, &OTPinfo);

	// Bit[1] xor Bit[0] = 1'b 0:  LC3 support
	// Bit[1] xor Bit[0] = 1'b 1:  LC3 do not
	if ((SYSCFG_GET_LC3_CFG(OTPinfo) == 3) || (SYSCFG_GET_LC3_CFG(OTPinfo) == 0)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
  * @brief  Check whether DSP is enable in OTP
  * @retval
  * TRUE: Support
  * FALSE: Do not support
  */
__STATIC_INLINE u32 ChipInfo_DSPSupport(void)
{
	u8 OTPinfo;

	OTP_Read8(CHIP_FUNCTION_LIMIT_GROUP1, &OTPinfo);

	//Bit[3] xor Bit[2] = 1'b 0:  8726 or 8713
	//Bit[3] xor Bit[2] = 1'b 1:  8720 or 8710
	if ((SYSCFG_GET_DSP_CFG(OTPinfo) == 3) || (SYSCFG_GET_DSP_CFG(OTPinfo) == 0)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
  * @brief  Check whether CPU can run in for speed
  * @retval
  * TRUE: Enabled
  * FALSE: Disabled
  */
__STATIC_INLINE u32 ChipInfo_CPUFullSupport(void)
{
	u8 OTPinfo;

	OTP_Read8(CHIP_FUNCTION_LIMIT_GROUP1, &OTPinfo);

	//Bit[3] xor Bit[2] = 1'b 0:  8726 or 8713
	//Bit[3] xor Bit[2] = 1'b 1:  8720 or 8710
	if ((SYSCFG_GET_FULLSPEED_CFG(OTPinfo) == 3) || (SYSCFG_GET_FULLSPEED_CFG(OTPinfo) == 0)) {
		return TRUE;
	} else {
		return FALSE;
	}
}


/**
  * @brief  Check whether Trustzone support
  * @retval
  * TRUE: Support
  * FALSE: Do not support
  */
__STATIC_INLINE u32 ChipInfo_TrustZoneSupport(void)
{
	u8 OTPinfo;

	OTP_Read8(CHIP_FUNCTION_LIMIT_GROUP2, &OTPinfo);

	// Bit[5] xor Bit[4] = 1'b 0:  KM4
	// Bit[5] xor Bit[4] = 1'b 1:  KR4
	if ((SYSCFG_GET_TRUSTZONE_CFG(OTPinfo) == 3) || (SYSCFG_GET_TRUSTZONE_CFG(OTPinfo) == 0)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
  * @brief  Check ZIGBEE protocol in OTP
  * @retval
  * TRUE: Support
  * FALSE: Do not support
  */
__STATIC_INLINE u32 ChipInfo_ZIGBEESupport(void)
{
	u8 OTPinfo;

	OTP_Read8(CHIP_FUNCTION_LIMIT_GROUP2, &OTPinfo);

	// Bit[5] xor Bit[4] = 1'b 0:  enable
	// Bit[5] xor Bit[4] = 1'b 1:  disable
	if ((SYSCFG_GET_ZIGBEE_CFG(OTPinfo) == 3) || (SYSCFG_GET_ZIGBEE_CFG(OTPinfo) == 0)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
  * @brief  Check WIFI protocol in OTP
  * @retval
  * TRUE: Support
  * FALSE: Do not support
  */
__STATIC_INLINE u32 ChipInfo_WIFI6Support(void)
{
	u8 OTPinfo;

	OTP_Read8(CHIP_FUNCTION_LIMIT_GROUP2, &OTPinfo);

	// Bit[3] xor Bit[2] = 1'b 0:  11ax
	// Bit[3] xor Bit[2] = 1'b 1:  11n only
	if ((SYSCFG_GET_WIFI_CFG(OTPinfo) == 3) || (SYSCFG_GET_WIFI_CFG(OTPinfo) == 0)) {
		return TRUE;
	} else {
		return FALSE;
	}
}


/**
  * @brief  Check Classic BT protocol in OTP
  * @retval
  * TRUE: Support
  * FALSE: Do not support
  */
__STATIC_INLINE u32 ChipInfo_BREDRSupport(void)
{
	u8 OTPinfo;

	OTP_Read8(CHIP_FUNCTION_LIMIT_GROUP2, &OTPinfo);

	// Bit[1] xor Bit[0] = 1'b 0:  BT 5.2DM
	// Bit[1] xor Bit[0] = 1'b 1:  BLE 5.2
	if ((SYSCFG_GET_BREDR_CFG(OTPinfo) == 3) || (SYSCFG_GET_BREDR_CFG(OTPinfo) == 0)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

/**
  * @brief  Check CSI support in OTP
  * @retval
  * TRUE: Support
  * FALSE: Do not support
  */
__STATIC_INLINE u32 ChipInfo_CSISupport(void)
{
	u8 OTPinfo;

	OTP_Read8(CHIP_FUNCTION_LIMIT_GROUP3, &OTPinfo);

	// Bit[1] xor Bit[0] = 1'b 0:  BT 5.2DM
	// Bit[1] xor Bit[0] = 1'b 1:  BLE 5.2
	if ((SYSCFG_GET_CSI_CFG(OTPinfo) == 3) || (SYSCFG_GET_CSI_CFG(OTPinfo) == 0)) {
		return FALSE;
	} else {
		return TRUE;
	}
}

#endif
