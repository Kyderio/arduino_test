/**
 * @file
 * MDNS responder
 */

/*
* Copyright (c) 2015 Verisure Innovation AB
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
* 3. The name of the author may not be used to endorse or promote products
*    derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
* SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
* OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
* OF SUCH DAMAGE.
*
* This file is part of the lwIP TCP/IP stack.
*
* Author: Erik Ekman <erik@kryo.se>
* Author: Jasper Verschueren <jasper.verschueren@apart-audio.com>
*
*/

#ifndef LWIP_HDR_APPS_MDNS_H
#define LWIP_HDR_APPS_MDNS_H

#include "mdns_opts.h"
#include "lwip/netif.h"

#ifdef __cplusplus
extern "C" {
#endif

#if LWIP_MDNS_RESPONDER

enum _mdns_sd_proto {
	DNSSD_PROTO_UDP = 0,
	DNSSD_PROTO_TCP = 1
};

#define MDNS_PROBING_HOST_CONFLICT   0
#define MDNS_PROBING_SERVICE_CONFLICT 1
#define MDNS_PROBING_SUCCESSFUL 2

#define MDNS_LABEL_MAXLEN  63
#define MDNS_DOMAIN_MAXLEN 256

struct _mdns_host;
struct _mdns_service;

/* Domain structs */
struct _mdns_domain {
	/* Total length of domain name, including zero */
	u16_t length;
	/* Encoded domain name */
	u8_t name[MDNS_DOMAIN_MAXLEN];
	/* Set if compression of this domain is not allowed */
	u8_t skip_compression;
};

/** Domain, type and class.
 *  Shared between questions and answers */
struct _mdns_rr_info {
	struct _mdns_domain domain;
	u16_t type;
	u16_t klass;
};

struct _mdns_answer {
	struct _mdns_rr_info info;
	/* Validity time in seconds */
	u32_t ttl;
	/** cache flush command bit */
	u16_t cache_flush;
	/** Length of variable answer */
	u16_t rd_length;
	/** Offset of start of variable answer in packet */
	u16_t rd_offset;
};

/** Callback function to add text to a reply, called when generating the reply */
typedef void (*service_get_txt_fn_t)(struct _mdns_service *service, void *txt_userdata);

/** Callback function to let application know the result of probing network for name
 * uniqueness, called with result MDNS_PROBING_SUCCESSFUL if no other node claimed
 * use for the name for the netif or a service and is safe to use, or MDNS_PROBING_CONFLICT
 * if another node is already using it and mdns is disabled on this interface */
typedef void (*_mdns_name_result_cb_t)(struct netif *netif, u8_t result, s8_t slot);

typedef void (*_mdns_recv_cb_t)(struct netif *netif, struct pbuf *p, const ip_addr_t *addr, u16_t port);

void *_mdns_get_service_txt_userdata(struct netif *netif, s8_t slot);

void _mdns_resp_init(void);
void _mdns_resp_deinit(void);
struct udp_pcb *get_mdns_pcb(void);

void _mdns_resp_register_name_result_cb(_mdns_name_result_cb_t cb);
void _mdns_resp_register_recv_cb(_mdns_recv_cb_t cb);

err_t _mdns_resp_add_netif(struct netif *netif, const char *hostname);
err_t _mdns_resp_remove_netif(struct netif *netif);
err_t _mdns_resp_rename_netif(struct netif *netif, const char *hostname);
int _mdns_resp_netif_active(struct netif *netif);

s8_t  _mdns_resp_add_service(struct netif *netif, const char *hostname, const char *instance, const char *service, enum _mdns_sd_proto proto, u16_t port,
							 service_get_txt_fn_t txt_fn, void *txt_data, u8_t txt_len, char **sub_type, u8_t sub_type_num, s8_t *new_service);
err_t _mdns_resp_del_service(struct netif *netif, u8_t slot);
s8_t _mdns_resp_del_service_with_name(struct netif *netif, const char *hostname, const char *instance, const char *service, enum _mdns_sd_proto proto);
err_t _mdns_resp_rename_service(struct netif *netif, u8_t slot, const char *name);

err_t _mdns_resp_add_service_txtitem(struct _mdns_service *service, const char *txt, u8_t txt_len);
err_t _mdns_resp_reset_service_port(struct netif *netif, u8_t slot, u16_t port);

s8_t _mdns_resp_add_delegate_host(struct netif *netif, const char *hostname, ip_addr_t *address, u8_t address_num, s8_t *new_host);
err_t _mdns_resp_del_delegate_host(struct netif *netif, u8_t slot);
s8_t _mdns_resp_del_delegate_host_with_name(struct netif *netif, const char *hostname);

void _mdns_resp_restart_delay(struct netif *netif, uint32_t delay);
void _mdns_resp_restart(struct netif *netif);
void _mdns_resp_announce(struct netif *netif);

/**
 * @ingroup mdns
 * Announce IP settings have changed on netif.
 * Call this in your callback registered by netif_set_status_callback().
 * No need to call this function when LWIP_NETIF_EXT_STATUS_CALLBACK==1,
 * this handled automatically for you.
 * @param netif The network interface where settings have changed.
 */
#define _mdns_resp_netif_settings_changed(netif) _mdns_resp_announce(netif)

#if LWIP_MDNS_SEARCH
typedef void (*search_result_fn_t)(struct _mdns_answer *answer, const char *varpart, int varlen, int flags, void *arg);
/* flags bits, both can be set! */
#define MDNS_SEARCH_RESULT_FIRST    1 /* First answer in received frame. */
#define MDNS_SEARCH_RESULT_LAST     2 /* Last answer. */

err_t _mdns_search_service(const char *instance, const char *service, enum _mdns_sd_proto proto,
						   struct netif *netif, search_result_fn_t result_fn, void *arg,
						   u8_t *request_id);
void _mdns_search_stop(u8_t request_id);
err_t _mdns_search_host_aaaa(const char *hostname, struct netif *netif, search_result_fn_t result_fn, void *arg, u8_t *request_id);
s8_t _mdns_search_service_stop(const char *instance, const char *service, enum _mdns_sd_proto proto, struct netif *netif, search_result_fn_t result_fn,
							   void *arg);
s8_t _mdns_search_host_stop(const char *hostname, struct netif *netif, search_result_fn_t result_fn, void *arg);

#endif /* LWIP_MDNS_SEARCH */
#if LWIP_MDNS_SUB_TYPE_SERVICE
s8_t _mdns_resp_add_sub_type_service(struct netif *netif, u8_t slot, const char *sub_type);
s8_t _mdns_resp_del_sub_type_service_with_name(struct netif *netif, u8_t slot, const char *sub_type);
#endif
#endif /* LWIP_MDNS_RESPONDER */

#ifdef __cplusplus
}
#endif

#endif /* LWIP_HDR_APPS_MDNS_H */
