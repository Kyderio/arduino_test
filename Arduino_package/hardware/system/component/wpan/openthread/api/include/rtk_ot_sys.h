#ifndef RTK_OT_SYS_H_
#define RTK_OT_SYS_H_

#include <openthread/instance.h>
#include "rtk_wpan_osif.h"
#include "lib/platform/exit_code.h"

#ifdef __cplusplus
extern "C" {
#endif

int rtk_ot_radio_init(void);
int rtk_ot_radio_deinit(void);
void rtk_ot_radio_state_changed(otInstance *instance, otChangedFlags flags);
void rtk_ot_uart_process(otInstance *instance);
void rtk_ot_radio_process(otInstance *instance);
void rtk_ot_alarm_process(otInstance *instance);
otInstance *rtk_ot_get_instance(void);
int rtk_ot_init(void);
int rtk_ot_deinit(void);
void rtk_ot_loop(void);
int rtk_ot_loop_exit(void);
void rtk_ot_check_reset(void);

#if defined(WPAN_EXIT_LOG_RPINT) && WPAN_EXIT_LOG_RPINT
#define OT_FUNC_EXIT(execute_func)	 \
	do {\
		error = execute_func;\
		if (error != OT_ERROR_NONE) {\
			WPAN_LOGSE("%s %d func fail, %s", __func__, __LINE__, otThreadErrorToString(error));\
			goto exit;\
		}\
	} while (0)
#else
#define OT_FUNC_EXIT(execute_func)	 \
	do {\
		error = execute_func;\
		if (error != OT_ERROR_NONE) {\
			goto exit;\
		}\
	} while (0)
#endif

#ifdef __cplusplus
}
#endif

#endif