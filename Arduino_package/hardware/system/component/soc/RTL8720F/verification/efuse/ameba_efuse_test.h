/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */


#ifndef _AMEBA_EFUSE_TEST_H_
#define _AMEBA_EFUSE_TEST_H_

#define SEC_KEY_S_IPSEC1                          0x0200
#define SEC_KEY_S_IPSEC2                          0x0220
#define SEC_KEY_NS_IPSEC1                         0x0240
#define SEC_KEY_NS_IPSEC2                         0x0260
#define SEC_KEY_ECDSA_PRI1                        0x0280
#define SEC_KEY_ECDSA_PRI2                        0x02A0
#define SEC_KEY_RSIP_ECB                          0x02C0
#define SEC_KEY_RSIP_CTR                          0x02E0
#define SEC_KEY_SWD_PWD                           0x0300
#define SEC_NEWKEY_HUK                            0x0310
#define SEC_PKKEY_PK1                             0x0320
#define SEC_PKKEY_PK2                             0x0340

#define SEC_CFG_SWD_ID                            0x0360//SEC_CFG0

#define SEC_CFG_RSIP_MODE                         0x0369


#define VENDOR_LOGIC_LL1                0x500
#define VENDOR_LOGIC_LL2                0x520
#define VENDOR_LOGIC_LL3                0x540
#define VENDOR_LOGIC_LL4                0x560
#define VENDOR_LOGIC_LH                 0x580
#define VENDOR_LOGIC_H                  0x600



#define SEC_SWD_RMA_PWD                           0x0710
#define SEC_PKKEY_RMA_PK                          0x0720


#endif
