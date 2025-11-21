#ifndef RTK_WPAN_OSIF_H_
#define RTK_WPAN_OSIF_H_

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stdbool.h>
#include <stdint.h>

#include <platform_autoconf.h>
#include <os_wrapper.h>
#include <basic_types.h>
#include <ameba_soc.h>

#include "rtk_wpan_misc.h"

#ifdef __cplusplus
extern "C" {
#endif

#define WPAN_OSIF_CRITICAL_CHECK    0
#define WPAN_OSIF_MEMORY_LEAK_CHECK 0
#define WPAN_OSIF_MEMORY_FREE_CHECK 0
#define WPAN_OSIF_SPINLOCK_CHECK    0
#define WPAN_OSIF_SPINLOCK_EN 0

#if defined(CONFIG_ARM_CORE_CA32) && CONFIG_ARM_CORE_CA32
#undef WPAN_OSIF_SPINLOCK_EN
#define WPAN_OSIF_SPINLOCK_EN 1
#endif

#if defined(WPAN_OSIF_SPINLOCK_EN) && WPAN_OSIF_SPINLOCK_EN
#include "spinlock.h"
#define WPAN_OSIF_LOCK_USE_CRITICAL_INSTEAD_OF_SPINLOCK 0 // dont suggest enable to use critical instead of spinlock in multicore CPU like CA32
typedef spinlock_t wpan_osif_lock;
#else
#define WPAN_OSIF_LOCK_USE_CRITICAL_INSTEAD_OF_SPINLOCK 1
typedef void *wpan_osif_lock;
#endif

#define WPAN_OSIF_MAX_TIMEOUT		RTOS_MAX_TIMEOUT
#define WPAN_OSIF_SEMA_MAX_COUNT	RTOS_SEMA_MAX_COUNT
#define WPAN_OSIF_TIMER_MAX_DELAY	RTOS_TIMER_MAX_DELAY
#define WPAN_OSIF_TASK_MAX_PRIORITIES	RTOS_TASK_MAX_PRIORITIES
typedef rtos_sema_t wpan_osif_sema;
typedef rtos_queue_t wpan_osif_queue;
typedef rtos_mutex_t wpan_osif_mutex;
typedef rtos_timer_t wpan_osif_timer;
typedef rtos_task_t wpan_osif_task;

#define WPAN_OSIF_TASK_PRIORITY	    (WPAN_OSIF_TASK_MAX_PRIORITIES - 2)

#define SWAP_64(x) ((((uint64_t)(x) & 0xff) << 56) | \
                   (((uint64_t)(x) & 0xff00) << 40) | \
                   (((uint64_t)(x) & 0xff0000) << 24) | \
                   (((uint64_t)(x) & 0xff000000) << 8) | \
                   (((uint64_t)(x) & 0xff00000000) >> 8) | \
                   (((uint64_t)(x) & 0xff0000000000) >> 24) | \
                   (((uint64_t)(x) & 0xff000000000000) >> 40) | \
                   (((uint64_t)(x) & 0xff00000000000000) >> 56))

/*#define SWAP_32(x) ((uint32_t)(                         \
 			(((uint32_t)(x) & (uint32_t)0x000000ff) << 24) |            \
 			(((uint32_t)(x) & (uint32_t)0x0000ff00) <<  8) |            \
 			(((uint32_t)(x) & (uint32_t)0x00ff0000) >>  8) |            \
 			(((uint32_t)(x) & (uint32_t)0xff000000) >> 24)))

#define SWAP_16(x) ((uint16_t)(                         \
 			(((uint16_t)(x) & (uint16_t)0x00ff) <<  8) |            \
 			(((uint16_t)(x) & (uint16_t)0xff00) >>  8)))*/

#if !defined(WPAN_OSIF_CRITICAL_CHECK) || !WPAN_OSIF_CRITICAL_CHECK
uint32_t rtk_wpan_osif_enter_critical(void);
void rtk_wpan_osif_exit_critical(void);
#else
uint32_t rtk_wpan_osif_enter_critical_fn(const char *func, const int line);
#define rtk_wpan_osif_enter_critical() rtk_wpan_osif_enter_critical_fn(__func__, __LINE__)
void rtk_wpan_osif_exit_critical_fn(const char *func, const int line);
#define rtk_wpan_osif_exit_critical() rtk_wpan_osif_exit_critical_fn(__func__, __LINE__)
#endif
#if defined(WPAN_OSIF_SPINLOCK_EN) && WPAN_OSIF_SPINLOCK_EN
#if !defined(WPAN_OSIF_SPINLOCK_CHECK) || !WPAN_OSIF_SPINLOCK_CHECK
uint32_t rtk_wpan_osif_spin_lock(void *lock);
void rtk_wpan_osif_spin_unlock(void *lock, uint32_t isr_status);
#else
uint32_t rtk_wpan_osif_spin_lock_fn(void *lock, const char *func, const int line);
#define rtk_wpan_osif_spin_lock(lock) rtk_wpan_osif_spin_lock_fn(lock, __func__, __LINE__)
void rtk_wpan_osif_spin_unlock_fn(void *lock, uint32_t isr_status, const char *func, const int line);
#define rtk_wpan_osif_spin_unlock(lock, isr_status) rtk_wpan_osif_spin_unlock_fn(lock, isr_status, __func__, __LINE__)
#endif
#endif
#if defined(WPAN_OSIF_LOCK_USE_CRITICAL_INSTEAD_OF_SPINLOCK) && WPAN_OSIF_LOCK_USE_CRITICAL_INSTEAD_OF_SPINLOCK
#define rtk_wpan_osif_lock(lock) rtk_wpan_osif_enter_critical(); (void)lock
#define rtk_wpan_osif_unlock(lock, isr_status) rtk_wpan_osif_exit_critical()
#else
#define rtk_wpan_osif_lock(lock) rtk_wpan_osif_spin_lock(lock)
#define rtk_wpan_osif_unlock(lock, isr_status) rtk_wpan_osif_spin_unlock(lock, isr_status)
#endif
bool rtk_wpan_osif_is_in_interrupt(void);
int rtk_wpan_osif_init_mutex(wpan_osif_mutex *mutex);
int rtk_wpan_osif_free_mutex(wpan_osif_mutex mutex);
int rtk_wpan_osif_get_timeout_mutex(wpan_osif_mutex mutex, uint32_t timeout_ms);
int rtk_wpan_osif_put_mutex(wpan_osif_mutex mutex);
int rtk_wpan_osif_init_sema(wpan_osif_sema *sema, uint32_t init_val, uint32_t max_val);
int rtk_wpan_osif_free_sema(wpan_osif_sema sema);
int rtk_wpan_osif_up_sema(wpan_osif_sema sema);
int rtk_wpan_osif_down_timeout_sema(wpan_osif_sema sema, uint32_t timeout_ms);
int rtk_wpan_osif_init_queue(wpan_osif_queue *queue, uint32_t number_of_messages, uint32_t message_size);
int rtk_wpan_osif_free_queue(wpan_osif_queue queue);
int rtk_wpan_osif_push_to_queue(wpan_osif_queue queue, void *message, uint32_t timeout_ms);
int rtk_wpan_osif_pop_from_queue(wpan_osif_queue queue, void *message, uint32_t timeout_ms);
int rtk_wpan_osif_peek_from_queue(wpan_osif_queue queue, void *message, uint32_t timeout_ms);
int rtk_wpan_osif_init_task(wpan_osif_task *task, const char *p_name, void (*p_routine)(void *),
							void *p_param, uint16_t stack_size_in_byte, uint16_t priority);
int rtk_wpan_osif_free_task(wpan_osif_task task);
int rtk_wpan_osif_init_timer(wpan_osif_timer *timer, const char *name, uint32_t timer_id,
							 uint32_t interval_ms, uint8_t reload, void (*p_timer_callback)(void *));
int rtk_wpan_osif_free_timer(wpan_osif_timer timer, uint32_t wait_ms);
int rtk_wpan_osif_start_timer(wpan_osif_timer timer, uint32_t wait_ms);
int rtk_wpan_osif_stop_timer(wpan_osif_timer timer, uint32_t wait_ms);
int rtk_wpan_osif_change_timer_period(wpan_osif_timer timer, uint32_t interval_ms, uint32_t wait_ms);
bool rtk_wpan_osif_is_timer_active(wpan_osif_timer timer);
int rtk_wpan_osif_delay_ms(uint32_t ms);
int rtk_wpan_osif_delay_us(uint32_t us);
uint64_t rtk_wpan_osif_get_current_system_time_ms(void);
uint64_t rtk_wpan_osif_get_current_system_time_us(void);
#if (!defined(WPAN_OSIF_MEMORY_LEAK_CHECK) || !WPAN_OSIF_MEMORY_LEAK_CHECK) && (!defined(WPAN_OSIF_MEMORY_FREE_CHECK) || !WPAN_OSIF_MEMORY_FREE_CHECK)
void *rtk_wpan_osif_zmalloc(uint32_t size);
int rtk_wpan_osif_free(void *pbuf);
#else
void *rtk_wpan_osif_zmalloc_fn(uint32_t size, const char *func, const int line);
#define rtk_wpan_osif_zmalloc(a) rtk_wpan_osif_zmalloc_fn((a), __func__, __LINE__)
int rtk_wpan_osif_free_fn(void *pbuf, const char *func, const int line);
#define rtk_wpan_osif_free(a) rtk_wpan_osif_free_fn((a), __func__, __LINE__)
#endif

#ifdef __cplusplus
}
#endif

#endif
