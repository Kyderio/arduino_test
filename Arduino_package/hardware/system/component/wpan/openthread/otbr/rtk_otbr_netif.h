#ifndef RTK_OTBR_NETIF_H_
#define RTK_OTBR_NETIF_H_

#include <openthread/instance.h>
#include <openthread/message.h>
#include <lwip/err.h>
#include <lwip/pbuf.h>
#include <lwip/netif.h>

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_netif_state_callback(otInstance *instance, otChangedFlags changed_flags);
int rtk_otbr_netif_setup(otInstance *instance);
int rtk_otbr_netif_teardown(otInstance *instance);
int rtk_otbr_netif_init(void);
int rtk_otbr_netif_deinit(void);
err_t rtk_otbr_netif_output(struct netif *netif, struct pbuf *p);
int rtk_otbr_netif_input(otMessage *message);
struct netif *rtk_otbr_get_openthread_netif(void);

#ifdef __cplusplus
}
#endif

#endif
