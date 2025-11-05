#ifndef RTK_OTBR_NAT66_H_
#define RTK_OTBR_NAT66_H_

#include <openthread/instance.h>
#include <openthread/ip6.h>
#include "rtk_otbr_lwip_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OTBR_NAT66_DEBUG 0
int rtk_otbr_nat66_add_route(const otIp6Prefix *prefix);
int rtk_otbr_nat66_remove_route(const otIp6Prefix *prefix);
int rtk_otbr_nat66_remove_all_route(void);
bool rtk_otbr_nat66_ip6_input(struct pbuf *p, struct netif *inp, ip6_addr_t *current_ip6hdr_dest);
int rtk_otbr_nat66_init(void);
int rtk_otbr_nat66_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
