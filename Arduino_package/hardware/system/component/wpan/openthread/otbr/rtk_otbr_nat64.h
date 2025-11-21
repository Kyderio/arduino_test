#ifndef RTK_OTBR_NAT64_H_
#define RTK_OTBR_NAT64_H_

#include <openthread/instance.h>
#include "rtk_otbr_lwip_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OTBR_NAT64_DEBUG 0
bool rtk_otbr_nat64_ip4_input(struct pbuf *p, struct netif *inp, ip4_addr_t *current_iphdr_dest);
int rtk_otbr_nat64_state_callback(otInstance *instance, otChangedFlags changed_flags);
int rtk_otbr_nat64_setup(otInstance *instance);
int rtk_otbr_nat64_teardown(otInstance *instance);
int rtk_otbr_nat64_init(void);
int rtk_otbr_nat64_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
