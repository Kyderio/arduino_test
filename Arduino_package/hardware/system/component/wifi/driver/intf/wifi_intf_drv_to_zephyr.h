/**
  ******************************************************************************
  * @file    wifi_intf_drv_to_zephyr.h
  * @author
  * @version
  * @date
  * @brief
  ******************************************************************************
  * @attention
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2024, Realtek Semiconductor Corporation. All rights reserved.
  ******************************************************************************
  */

#ifndef __ZEPHYR_INTF_H__
#define __ZEPHYR_INTF_H__

#ifdef	__cplusplus
extern "C" {
#endif

#include <rtw_skbuff.h>
struct net_pkt;

void wifi_if_tx_inc(int idx);
void wifi_if_tx_dec(int idx);
struct sk_buff *wifi_if_get_recv_skb(int idx);
struct sk_buff *wifi_if_alloc_skb(unsigned int total_len);
void rltk_wlan_set_netif_info(int idx_wlan, void *dev, unsigned char *dev_addr);
void wifi_if_send_skb(int idx, struct sk_buff *skb);
void wifi_if_netif_rx(struct sk_buff *skb, void *preorder_ctrl);
void netif_rx(int idx, unsigned int len);

unsigned char *rltk_wlan_get_ip(int idx);
unsigned char *rltk_wlan_get_gw(int idx);

int net_pkt_read(struct net_pkt *pkt, void *data, size_t length);
int eth_rtk_rx(uint8_t idx, void *buffer, uint16_t len);
u8 *ameba_wifi_get_ip(u8 idx);
u8 *ameba_wifi_get_gw(u8 idx);

#ifdef	__cplusplus
}
#endif

#endif //#ifndef __ZEPHYR_INTF_H__
