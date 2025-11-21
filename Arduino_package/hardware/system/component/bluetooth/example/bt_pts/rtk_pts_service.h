/*
 *******************************************************************************
 * Copyright(c) 2022, Realtek Semiconductor Corporation. All rights reserved.
 *******************************************************************************
 */

#ifndef __RTK_PTS_SERVICE_H__
#define __RTK_PTS_SERVICE_H__


#ifdef __cplusplus
extern "C"  {
#endif

#include <rtk_bt_def.h>


void pts_service_callback(uint8_t event, void *data);

uint16_t pts_srv_add(void);

void pts_srv_disconnect(uint16_t conn_handle);

void pts_status_deinit(void);

#ifdef __cplusplus
}
#endif

#endif  /* __BAS_H__ */