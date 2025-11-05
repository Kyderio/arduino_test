#ifndef RTK_OTBR_MDNS_H_
#define RTK_OTBR_MDNS_H_

#include <openthread/instance.h>
#include "mdns/mdns.h"
#include "mdns/mdns_priv.h"

#ifdef __cplusplus
extern "C" {
#endif

int rtk_otbr_mdns_init(void);
int rtk_otbr_mdns_deinit(void);
int rtk_otbr_lwip_mdns_split_full_service_name(const char *full_name, char *instance, char *service, char *proto, char *dimain_name);
int rtk_otbr_lwip_mdns_split_full_host_name(const char *full_name, char *host_name, char *dimain_name);
int rtk_otbr_lwip_mdns_txt_add_string(struct _mdns_service *service, const char *head, const char *str);
int rtk_otbr_lwip_mdns_txt_add_data(struct _mdns_service *service, const char *head, const uint8_t *data, uint32_t data_len);
void rtk_otbr_lwip_append_txt(struct _mdns_service *service, void *txt_userdata);
int rtk_otbr_lwip_mdns_translate_domain_to_dotname(char *domain, uint16_t total_len);

#ifdef __cplusplus
}
#endif

#endif
