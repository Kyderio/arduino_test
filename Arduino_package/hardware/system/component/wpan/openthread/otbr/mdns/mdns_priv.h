/**
 * @file
 * MDNS responder private definitions
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
#ifndef LWIP_HDR_MDNS_PRIV_H
#define LWIP_HDR_MDNS_PRIV_H

#include "mdns.h"
#include "mdns_opts.h"
#include "lwip/pbuf.h"

#ifdef __cplusplus
extern "C" {
#endif

#if LWIP_MDNS_RESPONDER

#define MDNS_READNAME_ERROR 0xFFFF
#define NUM_DOMAIN_OFFSETS 10

#define SRV_PRIORITY 0
#define SRV_WEIGHT   0

/* mDNS TTL: (RFC6762 section 10)
 *  - 120 seconds if the hostname appears somewhere in the RR
 *  - 75 minutes if not (4500 seconds)
 *  - 10 seconds if responding to a legacy query
 */
#define MDNS_TTL_0     0
#define MDNS_TTL_10    10
#define MDNS_TTL_120   120
#define MDNS_TTL_4500  4500

/* RFC6762 section 8.1: If fifteen conflicts occur within any ten-second period,
 * then the host MUST wait at least five seconds before each successive
 * additional probe attempt.
 */
#define MDNS_PROBE_MAX_CONFLICTS_BEFORE_RATE_LIMIT  15
#define MDNS_PROBE_MAX_CONFLICTS_TIME_WINDOW        10000
#define MDNS_PROBE_MAX_CONFLICTS_TIMEOUT            5000

#if LWIP_MDNS_SEARCH
/** Description of a search request */
struct _mdns_request {
	/** Type of service, like '_http' or '_services._dns-sd' */
	struct _mdns_domain service;
	/** Callback function called for each response */
	search_result_fn_t result_fn;
	void *arg;
	struct netif *netif;
	/** Protocol, TCP or UDP */
	u16_t proto;
	/** PTR only request. */
	u16_t only_ptr;
	/** Query type (PTR, SRV, ...) */
	u8_t qtype;
	/** Hostname */
	char hostname[MDNS_LABEL_MAXLEN + 1];
	/** Name of service, like 'myweb' */
	char instance[MDNS_LABEL_MAXLEN + 1];
#if LWIP_MDNS_SEARCH_DELAY
	u8_t wait_send: 1;
#endif
};
#endif

/** Description of a service */
struct _mdns_service {
	/** TXT record to answer with */
	struct _mdns_domain txtdata;
	/** Callback function and userdata
	 * to update txtdata buffer */
	service_get_txt_fn_t txt_fn;
	void *txt_userdata;
	/** Type of sub service, like '_test_subtype._sub._http' */
	char *sub_service[MDNS_MAX_SUB_TYPE_SERVICES];
	/** Port of the service */
	u16_t port;
	/** Protocol, TCP or UDP */
	u16_t proto;
	u8_t txt_len;
	/** Hostname */
	char hostname[MDNS_LABEL_MAXLEN + 1];
	/** Name of service, like 'myweb' */
	char instance[MDNS_LABEL_MAXLEN + 1];
	/** Type of service, like '_http' */
	char service[MDNS_LABEL_MAXLEN + 1];
#if LWIP_MDNS_DETELE_ANNOUNCE
	u8_t sub_under_delete;
	u8_t under_delete: 1;
#endif
	u8_t wait_announce: 1;
};

/** mDNS output packet */
struct _mdns_outpacket {
	/** Packet data */
	struct pbuf *pbuf;
	/** Current write offset in packet */
	u16_t write_offset;
	/** Number of questions written */
	u16_t questions;
	/** Number of normal answers written */
	u16_t answers;
	/** Number of authoritative answers written */
	u16_t authoritative;
	/** Number of additional answers written */
	u16_t additional;
	/** Offsets for written domain names in packet.
	 *  Used for compression */
	u16_t domain_offsets[NUM_DOMAIN_OFFSETS];
};

/** mDNS output message */
struct _mdns_outmsg {
	/** Destination IP/port if sent unicast */
	ip_addr_t dest_addr;
#ifdef LWIP_MDNS_SEARCH
	/** Search query to send */
	struct _mdns_request *query[MDNS_MAX_REQUESTS];
#endif
	/** Identifier. Used in legacy queries */
	u16_t tx_id;
	u16_t dest_port;
	/* Bitmask for which reverse IPv6 hosts to answer */
	u16_t host_reverse_v6_replies[MDNS_MAX_DELEGATED_HOSTS + 1];
	/** dns flags */
	u8_t flags;
	/** If all answers in packet should set cache_flush bit */
	u8_t cache_flush;
	/** If reply should be sent unicast (as requested) */
	u8_t unicast_reply_requested;
	/** If legacy query. (tx_id needed, and write
	 *  question again in reply before answer) */
	u8_t legacy_query;
	/** If the query is a probe msg we need to respond immediately. Independent of
	 *  the QU or QM flag. */
	u8_t probe_query_recv;
	/* Question bitmask for host information */
	u8_t host_questions[MDNS_MAX_DELEGATED_HOSTS + 1];
	/* Questions bitmask per service */
	u8_t serv_questions[MDNS_MAX_SERVICES];
	/* Reply bitmask for host information */
	u8_t host_replies[MDNS_MAX_DELEGATED_HOSTS + 1];
	/* Reply bitmask per service */
	u8_t serv_replies[MDNS_MAX_SERVICES];
	/* Bitmask for which service to answer */
	u8_t serv_reverse_type_replies[MDNS_MAX_SERVICES];

};

/** Delayed msg info */
struct _mdns_delayed_msg {
	/** Output msg used for delayed multicast responses */
	struct _mdns_outmsg delayed_msg_multicast;
	/** Output msg used for delayed unicast responses */
	struct _mdns_outmsg delayed_msg_unicast;
	/** Signals if a multicast msg needs to be send out */
	u8_t multicast_msg_waiting;
	/** Multicast timeout for all multicast traffic except probe answers */
	u8_t multicast_timeout;
	/** Multicast timeout only for probe answers */
	u8_t multicast_probe_timeout;
	/** Prefer multicast over unicast timeout -> 25% of TTL = we take 30s as
	    general delay. */
	u8_t multicast_timeout_25TTL;
	/** Only send out new unicast message if previous was send */
	u8_t unicast_msg_in_use;
};

/* MDNS states */
typedef enum {
	/* MDNS module is off */
	MDNS_STATE_OFF,
	/* Waiting before probing can be started */
	MDNS_STATE_PROBE_WAIT,
	/* Probing the unique records */
	MDNS_STATE_PROBING,
	/* Waiting before announcing the probed unique records */
	MDNS_STATE_ANNOUNCE_WAIT,
	/* Announcing all records */
	MDNS_STATE_ANNOUNCING,
	/* Probing and announcing completed */
	MDNS_STATE_COMPLETE
} _mdns_resp_state_enum_t;

struct _mdns_delegated_host {
	ip_addr_t addr[MDNS_MAX_DELEGATED_HOST_ADDRS];
	/** Hostname */
	char name[MDNS_LABEL_MAXLEN + 1];
	u8_t wait_announce: 1;
#if LWIP_MDNS_DETELE_ANNOUNCE
	u8_t under_delete: 1;
#endif
};

/** Description of a host/netif */
struct _mdns_host {
#if LWIP_IPV4
	/** delayed msg struct for IPv4 */
	struct _mdns_delayed_msg ipv4;
#endif
#if LWIP_IPV6
	/** delayed msg struct for IPv6 */
	struct _mdns_delayed_msg ipv6;
#endif
	/** Pointer to Delegated hosts */
	struct _mdns_delegated_host *delegated_hosts[MDNS_MAX_DELEGATED_HOSTS + 1];
	/** Pointer to services */
	struct _mdns_service *services[MDNS_MAX_SERVICES];
	/** Timestamp of probe conflict saved in list */
	u32_t conflict_time[MDNS_PROBE_MAX_CONFLICTS_BEFORE_RATE_LIMIT];
	/** State of the mdns responder */
	_mdns_resp_state_enum_t state;
	/** Hostname */
	char name[MDNS_LABEL_MAXLEN + 1];
	/** Number of probes/announces sent for the current name */
	u8_t sent_num;
	/** Rate limit flag */
	u8_t rate_limit_activated;
	/** List index for timestamps */
	u8_t index;
	/** number of conflicts since startup */
	u8_t num_conflicts;
#if LWIP_MDNS_DETELE_ANNOUNCE
	u8_t under_delete: 1;
#endif
};

struct _mdns_host *netif_mdns_data(struct netif *netif);
struct udp_pcb *get_mdns_pcb(void);

#endif /* LWIP_MDNS_RESPONDER */

#ifdef __cplusplus
}
#endif

#endif /* LWIP_HDR_MDNS_PRIV_H */
