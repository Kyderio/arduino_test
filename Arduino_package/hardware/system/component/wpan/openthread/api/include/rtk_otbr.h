#ifndef RTK_OTBR_H_
#define RTK_OTBR_H_

#include <openthread/instance.h>
#include "rtk_ot_sys.h"

#ifdef __cplusplus
extern "C" {
#endif

void rtk_otbr_state_callback(otInstance *instance, otChangedFlags changed_flags);
int rtk_otbr_setup(otInstance *instance);
int rtk_otbr_teardown(otInstance *instance);
int rtk_otbr_init(void);
int rtk_otbr_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
