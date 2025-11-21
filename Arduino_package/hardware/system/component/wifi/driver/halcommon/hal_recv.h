/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/
#ifndef __HAL_RECV_H__
#define __HAL_RECV_H__

#define RXBD_SIZE               8

int wifi_hal_rx_amsdu(u8 *rxbd, struct sk_buff *skb, u8 *pdata, void *dev_addr);
void wifi_mp_normal_rx_process(union recv_frame *precvframe);
void wifi_hal_clear_amsdu_priv(struct amsdu_priv_t *pamsdu);
int wifi_hal_check_rxtg(u16 *pRxExpectTag, u8 *rx_desc);
u16 wifi_hal_check_rxdesc_remain(int rxringcount);
void wifi_hal_rx_ack(u8 enable);
int wifi_hal_if2_clone_recvframe(union recv_frame *precvframe, union recv_frame *precvframe_if2,
								 struct  sk_buff *clone_pkt, u8 *pphy_info);
void wifi_hal_rx_filter(u8 enable, u8 filter);
void wifi_hal_rx_filter_check_promisc(void);
void wifi_hal_rx_get_skb_and_desc(struct sk_buff **ppskb, u8 **prx_desc);
u8 wifi_hal_rx_mpdu(void);
void wifi_hal_rxdesc_phystatus_query(struct rx_pkt_attrib	*pattrib, u8 *physts_ptr);
void wifi_hal_rxdesc_phystatus_query_v2(union recv_frame *precvframe, u8 *pphy_status);
void wifi_hal_normal_rx_process(union recv_frame	*precvframe);
void wifi_hal_normal_rx_phystatus_query(union recv_frame *precvframe, u8 *pphy_info);
int wifi_hal_rx_remaining_phystatus(void);
s8 wifi_hal_rxdesc_rssi_query(struct rx_pkt_attrib *pattrib, u8 *pphy_status);
u8 wifi_hal_rx_promisc(union recv_frame *precvframe, u8 *pphy_info);
void wifi_hal_rx_trigger_process(struct rx_pkt_attrib *pattrib, union recv_frame *precvframe);
int wifi_hal_rx_mpdu_pkt_copy(struct rx_pkt_attrib *pattrib, union recv_frame *precvframe);
int wifi_hal_rx_ring_init(u8 *rxring_addr);
void wifi_hal_rx_ring_free(void);
void wifi_hal_rx_ring_reset(void);
void wifi_hal_mp_rx_process(union recv_frame *precvframe, u8 *pphy_info);

void wifi_hal_rxdesc_query(struct rx_pkt_attrib *pattrib, u8 *pdesc);
void wifi_hal_recv_release_physts_readptr(u16 read_ptr);
int wifi_hal_recv_manual_fetch_physts(u8 rxbd_idx);
void wifi_hal_recv_set_tsf_timer0(u16 timeout);

#ifdef CONFIG_CSI
void wifi_hal_rxdesc_csi_query(struct rtw_csi_desc *csi_desc, u8 *pdesc);
#endif

void wifi_hal_rx_trigger_process(struct rx_pkt_attrib *pattrib,  union recv_frame *precvframe);
void wifi_hal_normal_rx_process(union recv_frame *precvframe);

#endif

