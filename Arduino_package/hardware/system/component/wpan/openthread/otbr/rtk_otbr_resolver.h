#ifndef RTK_OTBR_RESOLVER_H_
#define RTK_OTBR_RESOLVER_H_

#include <openthread/instance.h>
#include <openthread/dnssd_server.h>

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_resolver_setup(otInstance *instance);
int rtk_otbr_resolver_teardown(otInstance *instance);
int rtk_otbr_resolver_init(void);
int rtk_otbr_resolver_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
