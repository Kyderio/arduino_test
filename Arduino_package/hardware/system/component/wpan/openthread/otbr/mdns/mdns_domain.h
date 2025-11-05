/**
 * @file
 * MDNS responder - domain related functionalities
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

#ifndef LWIP_HDR_APPS_MDNS_DOMAIN_H
#define LWIP_HDR_APPS_MDNS_DOMAIN_H

#include "mdns_opts.h"
#include "mdns_priv.h"

#ifdef __cplusplus
extern "C" {
#endif

#if LWIP_MDNS_RESPONDER

/* Domain methods - also visible for unit tests */

err_t _mdns_domain_add_label(struct _mdns_domain *domain, const char *label, u8_t len);
err_t _mdns_domain_add_domain(struct _mdns_domain *domain, struct _mdns_domain *source);
err_t _mdns_domain_add_string(struct _mdns_domain *domain, const char *source);
u16_t _mdns_readname(struct pbuf *p, u16_t offset, struct _mdns_domain *domain);
void _mdns_domain_debug_print(struct _mdns_domain *domain);
int _mdns_domain_eq(struct _mdns_domain *a, struct _mdns_domain *b);
#if LWIP_IPV4
err_t _mdns_build_reverse_v4_domain(struct _mdns_domain *domain, const ip4_addr_t *addr);
#endif
#if LWIP_IPV6
err_t _mdns_build_reverse_v6_domain(struct _mdns_domain *domain, const ip6_addr_t *addr);
#endif
err_t _mdns_build_host_domain(struct _mdns_domain *domain, char *hostname);
err_t _mdns_build_dnssd_domain(struct _mdns_domain *domain);
err_t _mdns_build_service_domain(struct _mdns_domain *domain, struct _mdns_service *service, int include_name);
#if LWIP_MDNS_SUB_TYPE_SERVICE
err_t _mdns_build_sub_service_domain(struct _mdns_domain *domain, struct _mdns_service *service, u8_t sub_id);
#endif
#if LWIP_MDNS_SEARCH
err_t _mdns_build_request_domain(struct _mdns_domain *domain, struct _mdns_request *request, int include_name);
#endif
u16_t _mdns_compress_domain(struct pbuf *pbuf, u16_t *offset, struct _mdns_domain *domain);
err_t _mdns_write_domain(struct _mdns_outpacket *outpkt, struct _mdns_domain *domain);

#endif /* LWIP_MDNS_RESPONDER */

#ifdef __cplusplus
}
#endif

#endif /* LWIP_HDR_APPS_MDNS_DOMAIN_H */
