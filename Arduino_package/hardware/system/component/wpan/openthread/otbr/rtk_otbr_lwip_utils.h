
#ifndef RTK_OTBR_LWIP_UTILS_H_
#define RTK_OTBR_LWIP_UTILS_H_

#include <string.h>
#include <openthread/message.h>
#include <rtk_wpan_osif.h>

#include <lwip/tcpip.h>
#include <lwip/dhcp.h>
#include <lwip/ip_addr.h>
#include <lwip/ip6_addr.h>
#include <lwip/mld6.h>
#include <lwip/icmp6.h>
#include <lwip/prot/mld6.h>
#include <lwip/tcp.h>
#include <lwip/prot/tcp.h>
#include <lwip/udp.h>
#include <lwip/icmp.h>
#include <lwip/nd6.h>
#include <lwip/nd6.h>
#include <lwip/priv/nd6_priv.h>
#include <lwip/prot/nd6.h>
#include <lwip/prot/icmp6.h>
#include <lwip/snmp.h>
#include <lwip/priv/tcpip_priv.h>
#include <lwip/netif.h>
#include <lwip/netifapi.h>
#include <lwip/etharp.h>
#include <lwip/raw.h>
#include <lwip/sockets.h>
#include <lwip/priv/raw_priv.h>
#include <lwip/inet_chksum.h>
#include <lwip/dns.h>
#include <lwip/prot/dns.h>

#include "rtk_otbr_mdns.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MDNS_STRING_BUF_LEN (MDNS_LABEL_MAXLEN + 1)
#define MDNS_MAX_STRING_BUF_LEN MDNS_DOMAIN_MAXLEN
#define MDNS_MAX_SUB_TYPE_NUM MDNS_MAX_SUB_TYPE_SERVICES
#define ICMP6_TYPE_MLRV2 143

typedef int (*lwip_callback_fn)(void *ctx);

typedef struct {
	ip6_addr_t addr;
	uint8_t netif_index;
	uint8_t is_join: 1;
} multicast_join_leave_task_t;

typedef struct {
	int ret;
} lwip_cmn_task_t;

typedef struct {
	char *hostname;
	char *instance;
	char *service;
	char *subtype[MDNS_MAX_SUB_TYPE_NUM];
	service_get_txt_fn_t txt_fn;
	uint8_t *txt_data;
	enum _mdns_sd_proto proto;
	uint16_t port;
	int8_t slot;
	int8_t new_service;
	uint8_t txt_len;
	uint8_t subtype_num;
	uint8_t unpublish: 1;
} mdns_publish_service_task_t;

typedef struct {
	char *hostname;
	char *instance;
	char *service;
	search_result_fn_t result_fn;
	void *arg;
	enum _mdns_sd_proto proto;
	uint8_t stop: 1;
} mdns_search_task_t;

#if defined(WPAN_EXIT_LOG_RPINT) && WPAN_EXIT_LOG_RPINT
#define LWIP_FUNC_EXIT(execute_func)	 \
	do {\
		err = execute_func;\
		if (err != ERR_OK) {\
			WPAN_LOGSE("%s %d func fail, %d", __func__, __LINE__, err);\
			goto exit;\
		}\
	} while (0)
#else
#define LWIP_FUNC_EXIT(execute_func)	 \
	do {\
		err = execute_func;\
		if (err != ERR_OK) {\
			goto exit;\
		}\
	} while (0)
#endif

int rtk_otbr_lwip_call_sync_init(void);
int rtk_otbr_lwip_call_sync_deinit(void);
int rtk_otbr_lwip_call_sync(lwip_callback_fn function, void *ctx);
int rtk_otbr_lwip_multicast_join_leave_task(void *ctx);
struct netif *rtk_otbr_get_backbone_netif(void);
int rtk_otbr_lwip_backbone_create_ip6_linklocal_addr(void);
uint8_t *rtk_otbr_lwip_get_mac(void);
struct ip6_addr_t *rtk_otbr_lwip_hook_nd6_get_gw(struct netif *netif, const ip6_addr_t *dest);
struct netif *rtk_otbr_lwip_hook_ip6_route(const ip6_addr_t *src, const ip6_addr_t *dest);
int rtk_otbr_lwip_udp_bind(struct udp_pcb *pcb, const ip_addr_t *ipaddr, u16_t port);
bool rtk_otbr_lwip_hook_ip4_input(struct pbuf *p, struct netif *inp);
bool rtk_otbr_lwip_hook_ip6_input(struct pbuf *p, struct netif *inp);

#ifdef __cplusplus
}
#endif

#endif