#ifndef RTK_OTBR_DISCOVERY_H_
#define RTK_OTBR_DISCOVERY_H_

#include <openthread/instance.h>

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_discovery_setup(otInstance *instance);
int rtk_otbr_discovery_teardown(otInstance *instance);
int rtk_otbr_discovery_init(void);
int rtk_otbr_discovery_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
