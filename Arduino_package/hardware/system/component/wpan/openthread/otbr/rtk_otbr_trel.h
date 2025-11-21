#ifndef RTK_OTBR_TREL_H_
#define RTK_OTBR_TREL_H_

#include <openthread/instance.h>
#include <lwip/netif.h>

#ifdef __cplusplus
extern "C" {
#endif
int rtk_otbr_trel_setup(otInstance *instance);
int rtk_otbr_trel_teardown(otInstance *instance);
int rtk_otbr_trel_init(void);
int rtk_otbr_trel_deinit(void);
int rtk_otbr_trel_publish_service_report(struct netif *netif, uint8_t result, int8_t slot);

#ifdef __cplusplus
}
#endif

#endif
