
#ifndef ZB_TRANSCEIVER_MEM_H__
#define ZB_TRANSCEIVER_MEM_H__

#include "dlist.h"

/* Single entry of the RX queue .*/
typedef struct {
	uint8_t   *p_data;
	int8_t     power;
	uint8_t    lqi;
	uint64_t   time;
	zb_bool_t  pending_bit;
} rx_queue_item_t;

typedef struct {
	struct list_head queue_data_list;
	rx_queue_item_t queue_item;
	zb_bool_t   occupy_flag;
} rx_queue_data_t;

/* for 802154 buffer free @ higher layer of zboss*/
typedef void (*zb_802154_buffer_free_func)(zb_uint8_t *pbuf);

void zb_osif_rx_queue_init(void);
void zb_osif_rx_queue_deinit(zb_802154_buffer_free_func fn_buffer_free);
zb_ret_t zb_osif_rx_data_alloc_and_put(uint8_t *p_data, int8_t power, uint8_t lqi, uint64_t time, zb_bool_t pending_bit);
zb_bool_t zb_osif_rx_queue_pending(void);
zb_bool_t zb_osif_rx_queue_full(void);
rx_queue_data_t *zb_osif_rx_data_get_next_pkt(void);
void zb_osif_rx_data_free(rx_queue_data_t *p_context, zb_802154_buffer_free_func fn_buffer_free);

#endif /* ZB_TRANSCEIVER_MEM_H__ */
