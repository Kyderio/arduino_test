#ifndef RTK_OTBR_TREL_MDNS_H_
#define RTK_OTBR_TREL_MDNS_H_

#include <openthread/instance.h>
#include <lwip/netif.h>

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_trel_browse_service(otInstance *instance, bool stop);
int rtk_otbr_trel_publish_service(otInstance *instance, uint16_t port, uint8_t *txt_data, uint8_t txt_length, bool unpublish);
int rtk_otbr_trel_publish_service_report(struct netif *netif, uint8_t result, int8_t slot);
int rtk_otbr_trel_mdns_init(void);
int rtk_otbr_trel_mdns_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
