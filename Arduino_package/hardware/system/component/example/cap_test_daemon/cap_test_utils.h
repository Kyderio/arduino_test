/**
  ******************************************************************************
  * @file    cap_test_utils.h
  * @author  Realsil WLAN5 Team
  * @version V1.0.0
  * @date    2022-11-10
  * @brief   This file declare the captouch access API for captouch test daemon
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2021, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CAP_TEST_UTILS_H
#define CAP_TEST_UTILS_H

#include <platform_autoconf.h>
#include "example_cap_test_daemon.h"

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

void ctc_init(void);
void ctc_start(cap_start_req_t *req);
void ctc_stop(void);
void ctc_get_config(cap_cfg_req_t *cfg);
void ctc_set_config(cap_cfg_req_t *cfg);
void ctc_get_ch_config(cap_ch_cfg_req_t *cfg);
void ctc_set_ch_config(cap_ch_cfg_req_t *cfg);
void ctc_get_ch_rt_data(cap_ch_rt_data_t *data);
void ctc_reset_baseline(void);
u32 ctc_get_ch_baseline(int channel);
void ctc_set_debug(u8 state);
u32 ctc_set_debug_ch(int channel, u8 state);
u16 ctc_get_snr(void);
void ctc_tune_ch_mbias(cap_ch_cfg_req_t *cfg, u16 target, u16 error);

#endif /* CAP_TEST_UTILS_H */

