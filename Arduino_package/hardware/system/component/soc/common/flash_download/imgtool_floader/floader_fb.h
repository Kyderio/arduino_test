/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _FLOADER_FB_H_
#define _FLOADER_FB_H_

/* Includes ------------------------------------------------------------------*/

#include "ameba_soc.h"

/* Exported defines ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/

/* Exported functions ------------------------------------------------------- */

/**
  * @brief Get the free frame buffer entry  but do not increment the read index
  * @param  void
  * @return free frame buffer entry
  */
u8 *fl_get_free_frame(void);

/**
  * @brief increments the write index and marks the command as pending after interrupt processing is complete.
  * @param  void
  * @return void
  */
void fl_put_frame(void);

/**
  * @brief Get the pending frame buffer to be processed and increment the read index
  * @param  void
  * @return pending frame buffer entry
  */
u8 *fl_get_pending_frame(void);

/**
  * @brief Get the free frame buffer count
  * @param  void
  * @return  free frame buffer entry count
  */
int fl_get_free_frame_count(void);

/**
  * @brief Get the frame buffer index currently to be written
  * @param  void
  * @return write index
  */
int fl_get_fb_write_index(void);

/**
  * @brief Get the frame buffer index currently to be read
  * @param  void
  * @return read index
  */
int fl_get_fb_read_index(void);

/**
  * @brief Reset frame buffer parameters
  * @param  void
  * @return void
  */
void fl_reset_fb(void);

/**
  * @brief Check frame status
  * @param  void
  * @return Status
  */
u8 fl_check_fb_status(void);

#endif // _FLOADER_FB_H_