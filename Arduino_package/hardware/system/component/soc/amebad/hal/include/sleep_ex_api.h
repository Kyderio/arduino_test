/** mbed Microcontroller Library
  ******************************************************************************
  * @file    sleep_ex_api.h
  * @author
  * @version V1.0.0
  * @brief   This file provides mbed API for SLEEP.
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
#ifndef MBED_SLEEP_EX_API_H
#define MBED_SLEEP_EX_API_H

#include "device.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup sleep_ex SLEEP_EX
 *  @ingroup    hal
 *  @brief      sleep extended functions
 *  @{
 */

///@name Ameba Common
///@{

/**
  * @brief  To make the system entering the Clock Gated power saving.
  *         This function just make the system to enter the clock gated
  *         power saving mode and pending on wake up event waitting.
  *         The user application need to configure the peripheral to
  *         generate system wake up event, like GPIO interrupt,
  *         G-Timer timeout, etc. befor entering power saving mode.
  * @param  wakeup_event: A bit map of wake up event.
  *   This parameter can be any combination of the following values:
  *		 @arg SLEEP_WAKEUP_BY_STIMER
  *		 @arg SLEEP_WAKEUP_BY_GTIMER
  *		 @arg SLEEP_WAKEUP_BY_GPIO_INT
  *		 @arg SLEEP_WAKEUP_BY_WLAN
  *		 @arg SLEEP_WAKEUP_BY_SDIO
  *		 @arg SLEEP_WAKEUP_BY_USB
  *		 @arg SLEEP_WAKEUP_BY_GPIO
  *		 @arg SLEEP_WAKEUP_BY_UART
  *		 @arg SLEEP_WAKEUP_BY_I2C
  *		 @arg SLEEP_WAKEUP_BY_RTC
  *		 @arg SLEEP_WAKEUP_BY_RESETPIN
  * @param  sleep_duration: the system sleep duration in ms, only valid
  *         for SLEEP_WAKEUP_BY_STIMER wake up event.
  * @retval None
  */
void sleep_ex(uint32_t wakeup_event,  uint32_t sleep_duration);

/**
  * @brief  To make the system entering the Clock Gated power saving.
  *         This function just make the system to enter the clock gated
  *         power saving mode and pending on wake up event waitting.
  *         The user application need to configure the peripheral to
  *         generate system wake up event, like GPIO interrupt
  *         , G-Timer timeout, etc. befor entering power saving mode.
  * @param  wakeup_event: A bit map of wake up event.
  *   This parameter can be any combination of the following values:
  *		 @arg SLEEP_WAKEUP_BY_STIMER
  *		 @arg SLEEP_WAKEUP_BY_GTIMER
  *		 @arg SLEEP_WAKEUP_BY_GPIO_INT
  *		 @arg SLEEP_WAKEUP_BY_WLAN
  *		 @arg SLEEP_WAKEUP_BY_SDIO
  *		 @arg SLEEP_WAKEUP_BY_USB
  *		 @arg SLEEP_WAKEUP_BY_GPIO
  *		 @arg SLEEP_WAKEUP_BY_UART
  *		 @arg SLEEP_WAKEUP_BY_I2C
  *		 @arg SLEEP_WAKEUP_BY_RTC
  *		 @arg SLEEP_WAKEUP_BY_RESETPIN
  * @param  sleep_duration: the system sleep duration in ms, only valid
  *         for SLEEP_WAKEUP_BY_STIMER wake up event.
  * @param  clk_sourec_enable: the option for SCLK on(1)/off(0)
  * @param  sdr_enable: the option for turn off the SDR controller (1:off, 0:on)
  * @retval None
  */
void sleep_ex_selective(uint32_t wakeup_event,  uint32_t sleep_duration, uint32_t clk_sourec_enable, uint32_t sdr_enable);


/**
  * @brief  To make the system entering the Deep Sleep power saving mode.
  *         The CPU, memory and peripheral power is off when entering
  *         deep sleep power saving mode. The program needs to be reload
  *         and all peripheral needs be re-configure when system resume.
  * @param  wakeup_event: A bit map of wake up event.
  *   This parameter can be any combination of the following values:
  *		 @arg DSLEEP_WAKEUP_BY_TIMER
  *		 @arg DSLEEP_WAKEUP_BY_GPIO
  * @param  sleep_duration: the system sleep duration in ms, only valid
  *         for DSLEEP_WAKEUP_BY_TIMER wake up event.
  * @retval None
  */
void deepsleep_ex(uint32_t wakeup_event, uint32_t sleep_duration);

/**
  * @brief  To delete a wake up event for wakeing up the system from the
  *         deep standby power saving mode.
  * @param  wakeup_event: A bit map of wake up event.
  *   This parameter can be any combination of the following values:
  *		 @arg STANDBY_WAKEUP_BY_STIMER
  *		 @arg STANDBY_WAKEUP_BY_GPIO
  *		 @arg STANDBY_WAKEUP_BY_RTC
  *		 @arg STANDBY_WAKEUP_BY_RESETPIN
  * @retval None
  */
void standby_wakeup_event_del(uint32_t wakeup_event);

///@}


#ifdef __cplusplus
}
#endif

//#endif
/*\@}*/
#endif
