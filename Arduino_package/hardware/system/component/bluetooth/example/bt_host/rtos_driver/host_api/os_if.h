/**
 * Copyright (c) 2015, Realsil Semiconductor Corporation. All rights reserved.
 */

#ifndef _OSIF_H_
#define _OSIF_H_

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <mem_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BT_TIMEOUT_NONE             0
#define BT_TIMEOUT_FOREVER          0xffffffffUL

/* OS schedule interfaces */
void bt_osif_delay(uint32_t ms);

/* OS task interfaces */
bool bt_osif_task_create(void **pp_handle, const char *p_name, void (*p_routine)(void *),
						 void *p_param, uint16_t stack_size, uint16_t priority);
void bt_osif_task_delete(void *p_handle);

/* OS synchronization interfaces */
void bt_osif_lock(void);
void bt_osif_unlock(void);
bool bt_osif_sem_create(void **pp_handle, uint32_t init_count, uint32_t max_count);
void bt_osif_sem_delete(void *p_handle);
bool bt_osif_sem_take(void *p_handle, uint32_t wait_ms);
bool bt_osif_sem_give(void *p_handle);
uint32_t bt_osif_sem_get_count(void *p_handle);
bool bt_osif_mutex_create(void **pp_handle);
void bt_osif_mutex_delete(void *p_handle);
bool bt_osif_mutex_take(void *p_handle, uint32_t wait_ms);
bool bt_osif_mutex_give(void *p_handle);

/* OS message queue interfaces */
bool bt_osif_msg_queue_create(void **pp_handle, uint32_t msg_num, uint32_t msg_size);
void bt_osif_msg_queue_delete(void *p_handle);
bool bt_osif_msg_queue_peek(void *p_handle, uint32_t *p_msg_num);
bool bt_osif_msg_send(void *p_handle, void *p_msg, uint32_t wait_ms);
bool bt_osif_msg_recv(void *p_handle, void *p_msg, uint32_t wait_ms);
bool bt_osif_msg_peek(void *p_handle, void *p_msg, uint32_t wait_ms);

/* OS memory management interfaces */
void *bt_osif_mem_alloc(size_t size);
void *bt_osif_mem_aligned_alloc(size_t size, uint8_t alignment);
void bt_osif_mem_free(void *p_block);
void bt_osif_mem_aligned_free(void *p_block);

#ifdef __cplusplus
}
#endif

#endif /* _OSIF_H_ */
