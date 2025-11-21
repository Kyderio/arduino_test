#ifndef RTK_OTBR_SRP_SERVER_H_
#define RTK_OTBR_SRP_SERVER_H_

#include <openthread/instance.h>
#include <openthread/srp_server.h>
#include <lwip/netif.h>

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_srp_server_setup(otInstance *instance);
int rtk_otbr_srp_server_teardown(otInstance *instance);
int rtk_otbr_srp_server_init(void);
int rtk_otbr_srp_server_deinit(void);
int rtk_otbr_srp_server_report(struct netif *netif, uint8_t result, int8_t slot);

#ifdef __cplusplus
}
#endif

#endif
