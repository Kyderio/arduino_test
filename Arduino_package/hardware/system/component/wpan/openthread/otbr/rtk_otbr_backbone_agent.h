#ifndef RTK_OTBR_BACKBONE_AGENT_H_
#define RTK_OTBR_BACKBONE_AGENT_H_

#include <openthread/instance.h>
#include "rtk_otbr_lwip_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_backbone_nd6_handler(struct netif *inp, struct pbuf *p, struct ip6_hdr *ip6hdr, ip6_addr_t *current_iphdr_src, ip6_addr_t *current_iphdr_dest);
struct ip6_addr_t *rtk_otbr_backbone_nd6_get_gw(struct netif *netif, const ip6_addr_t *dest);
struct netif *rtk_otbr_backbone_route(const ip6_addr_t *src, const ip6_addr_t *dest);
int rtk_otbr_backbone_init(void);
int rtk_otbr_backbone_deinit(void);
int rtk_otbr_backbone_setup(otInstance *instance);
int rtk_otbr_backbone_teardown(otInstance *instance);
int rtk_otbr_backbone_state_callback(otInstance *instance, otChangedFlags flags);

#ifdef __cplusplus
}
#endif

#endif
