#ifndef RTK_OTBR_ND_PROXYING_H_
#define RTK_OTBR_ND_PROXYING_H_

#include <openthread/instance.h>
#include "rtk_otbr_lwip_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_nd_proxying_ns_handler(struct netif *inp, struct pbuf *p,	ip6_addr_t *current_iphdr_src, ip6_addr_t *current_iphdr_dest);
int rtk_otbr_nd_proxying_enable(void);
int rtk_otbr_nd_proxying_disable(void);
int rtk_otbr_nd_proxying_setup(otInstance *instance);
int rtk_otbr_nd_proxying_teardown(otInstance *instance);

#ifdef __cplusplus
}
#endif

#endif
