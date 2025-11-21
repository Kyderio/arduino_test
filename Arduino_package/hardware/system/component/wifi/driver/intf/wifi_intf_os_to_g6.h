#ifndef __HAL_HEADERS_LE_H__
#define __HAL_HEADERS_LE_H__

/*this file is shared for 11ax submodules*/
#include <rtw_adapter.h>
#include "wifi_hal.h"

/*==================phl_types.h of g6 driver=====================*/
#define _os_dbgdump DiagPrintf

#ifndef false
#define false 0
#endif

#ifndef true
#define true 1
#endif

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

/*==================pltfm_ops_linux.h of g6 driver==================*/
static inline void _os_init_timer(struct timer_list *timer,
								  void (*call_back_func)(void *context), void *context,
								  const char *sz_id)
{
	rtw_init_timer(timer, NULL, call_back_func, context, sz_id);
}

static inline void _os_set_timer(struct timer_list *timer, u32 ms_delay)
{
	rtw_set_timer(timer, ms_delay);
}

static inline void _os_cancel_timer(struct timer_list *timer)
{
	rtw_cancel_timer(timer);
}

static inline void _os_release_timer(struct timer_list *timer)
{
	rtw_del_timer(timer);
}

#define _os_mem_alloc(sz)  rtos_mem_zmalloc(sz)
#define _os_mem_free(buf, sz)  rtos_mem_free(buf)
#define _os_mem_set(buf, val, sz)  memset(buf, val, sz)
#define _os_mem_cpy(dst, src, sz)  memcpy(dst, src, sz)
#define _os_mem_cmp(dst, src, sz)  !memcmp(dst, src, sz)

#define hal_mem_set(buf, val, sz) memset(buf, val, sz)
#define hal_mem_cpy(dst, src, sz) memcpy(dst, src, sz)

#define _os_get_cur_time_us() rtos_time_get_current_system_time_ms() //AX_TODO: need find a us timer

#define _os_snprintf(s, sz, fmt, ...) snprintf(s, sz, fmt, ##__VA_ARGS__)

#define _os_strcmp(s1, s2) strcmp(s1, s2)
#define _os_strcpy(dest, src) strcpy(dest, src)
#define _os_sscanf(buf, fmt, ...) _sscanf_ss(buf, fmt, ##__VA_ARGS__)
#define _os_strsep(s, ct) strsep(s, ct)
#define _os_strlen(buf) strlen(buf)

#define hal_read32(addr) HAL_READ32(WIFI_REG_BASE, addr)
#define hal_read16(addr) HAL_READ16(WIFI_REG_BASE, addr)
#define hal_read8(addr) HAL_READ8(WIFI_REG_BASE, addr)
#define hal_write32(addr, val) HAL_WRITE32(WIFI_REG_BASE, addr, val)
#define hal_write16(addr, val) HAL_WRITE16(WIFI_REG_BASE, addr, val)
#define hal_write8(addr, val) HAL_WRITE8(WIFI_REG_BASE, addr, val)

#define phl_is_mp_mode()	(rtw_halphy_shareinfo.phl_drv_mode == RTW_DRV_MODE_MP)

#endif
