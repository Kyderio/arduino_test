#ifndef RTK_OTBR_INFRA_IF_H_
#define RTK_OTBR_INFRA_IF_H_

#include "rtk_otbr_lwip_utils.h"
#include <openthread/instance.h>

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_infra_if_pd_ra_input(struct netif *inp, struct pbuf *p);
int rtk_otbr_infra_if_setup(otInstance *instance);
int rtk_otbr_infra_if_teardown(otInstance *instance);
int rtk_otbr_infra_if_init(void);
int rtk_otbr_infra_if_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
