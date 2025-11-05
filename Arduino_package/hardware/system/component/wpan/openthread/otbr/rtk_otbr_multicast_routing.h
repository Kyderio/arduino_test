#ifndef RTK_OTBR_MULTICAST_ROUTING_H_
#define RTK_OTBR_MULTICAST_ROUTING_H_

#include <openthread/instance.h>
#include "rtk_otbr_lwip_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_multicast_routing_mld6_handler(struct netif *inp, struct pbuf *p, ip6_addr_t *current_iphdr_src, ip6_addr_t *current_iphdr_dest);
bool rtk_otbr_multicast_routing_forward_handler(struct netif *inp, struct ip6_hdr *ip6hdr, struct pbuf *p,
		ip6_addr_t *current_iphdr_src, ip6_addr_t *current_iphdr_dest);
int rtk_otbr_multicast_routing_setup(otInstance *instance);
int rtk_otbr_multicast_routing_teardown(otInstance *instance);
int rtk_otbr_multicast_routing_init(void);
int rtk_otbr_multicast_routing_deinit(void);
int rtk_otbr_backbone_multicast_routing_state_callback(otInstance *instance, otChangedFlags flags);

#ifdef __cplusplus
}
#endif

#endif
