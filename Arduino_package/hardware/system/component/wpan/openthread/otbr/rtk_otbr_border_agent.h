#ifndef RTK_OTBR_BORDER_AGENT_H_
#define RTK_OTBR_BORDER_AGENT_H_

#include <openthread/instance.h>
#include <lwip/netif.h>

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_border_agent_meshcop_epskc_report(struct netif *netif, uint8_t result, int8_t slot);
int rtk_otbr_border_agent_meshcop_report(struct netif *netif, uint8_t result, int8_t slot);
int rtk_otbr_border_agent_setup(otInstance *instance);
int rtk_otbr_border_agent_teardown(otInstance *instance);
int rtk_otbr_border_agent_init(void);
int rtk_otbr_border_agent_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
