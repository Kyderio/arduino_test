
#ifndef RTK_OTBR_LWIP_HOOK_H_
#define RTK_OTBR_LWIP_HOOK_H_

#include <lwip/ip6_addr.h>
#include <lwip/netif.h>

#ifdef __cplusplus
extern "C" {
#endif

ip6_addr_t *rtk_otbr_lwip_hook_nd6_get_gw(struct netif *netif, const ip6_addr_t *dest);
struct netif *rtk_otbr_lwip_hook_ip6_route(const ip6_addr_t *src, const ip6_addr_t *dest);
bool rtk_otbr_lwip_hook_ip4_input(struct pbuf *p, struct netif *inp);
bool rtk_otbr_lwip_hook_ip6_input(struct pbuf *p, struct netif *inp);

#ifdef __cplusplus
}
#endif

#endif
