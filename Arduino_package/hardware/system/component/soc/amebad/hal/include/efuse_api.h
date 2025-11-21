/** mbed Microcontroller Library
  ******************************************************************************
  * @file    efuse_api.h
  * @author
  * @version V1.0.0
  * @brief   This file provides mbed EFUSE API.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2015, Realtek Semiconductor Corp.
  * All rights reserved.
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  ******************************************************************************
  */

#ifndef MBED_EXT_EFUSE_API_EXT_H
#define MBED_EXT_EFUSE_API_EXT_H

#include "device.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup efuse EFUSE
 *  @ingroup    hal
 *  @brief      efuse functions
 *  @{
 */

///@name Ameba Common
///@{

/**
  * @brief  Get remaining efuse length
  * @retval : remaining efuse length
  */
int efuse_get_remaining_length(void);

/**
  * @brief  Read efuse contant of specified user
  * @param  data: Specified the address to save the readback data.
  * @retval none
  */
void efuse_mtp_read(uint8_t *data);

/**
  * @brief  Write user's contant to efuse
  * @param  data: Specified the data to be programmed.
  * @param  len: Specifies the data length of programmed data.
  * @retval value:
  *          - 0~32: Success
  *          - -1: Failure
  */
int efuse_mtp_write(uint8_t *data, uint8_t len);

/**
  * @brief  Read efuse OTP contant
  * @param  address: Specifies the offset of the OTP.
  * @param  len: Specifies the length of readback data.
  * @param  buf: Specified the address to save the readback data.
  * @retval 0: Success
  * @retval -1: Failure
  */
int efuse_otp_read(u8 address, u8 len, u8 *buf);

/**
  * @brief  Write user's contant to OTP efuse
  * @param  address: Specifies the offset of the programmed OTP.
  * @param  len: Specifies the data length of programmed data.
  * @param  buf: Specified the data to be programmed.
  * @retval 0: Success
  * @retval -1: Failure
  */
int efuse_otp_write(u8 address, u8 len, u8 *buf);

/**
  * @brief  ckeck user's contant to OTP efuse
  * @param  buf: Specified the data to be programmed.
  * @param  len: Specifies the data length of programmed data.
  * @retval 0: Success
  * @retval -1: Failure
  */
int efuse_otp_chk(u8 len, u8 *buf);


///@}

/*\@}*/

#ifdef __cplusplus
}
#endif

#endif // MBED_EXT_EFUSE_API_EXT_H
