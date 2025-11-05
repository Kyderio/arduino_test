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
#ifndef __HAL_CMD_H__
#define __HAL_CMD_H__

enum rxbcn_intvl {
	BCN_INTVL_MIN = 0x0,	/* rxbcn at each TBTT */
	BCN_INTVL_MAX = 0x1,	/* rxbcn according AP dtim period */
	BCN_INTVL_USER_DEFINE = 0x2,	/* rx bcn according to defined DTIM interval */
};

#ifdef CONFIG_WMMPS_STA
#define RSVD_PAGE_PS_POLL			FW_USED_OFFSET
#define RSVD_PAGE_QOS_NULL_DATA		FW_USED_OFFSET + 1
#endif
#define RSVD_PAGE_PS_NULL_DATA      FW_USED_OFFSET + 2
#define RSVD_PAGE_BT_QOS_NULL       FW_USED_OFFSET + 3
#define RSVD_PAGE_CSI_TRIG_FRAME    FW_USED_OFFSET + 4/*for CSI trigger frame*/
#define RSVD_PAGE_ARP_RSP           FW_USED_OFFSET + 5
#define RSVD_PAGE_CTS2SELF          FW_USED_OFFSET + 6

#ifdef CONFIG_NAN
#define RSVD_PAGE_NAN_SYNC_BCN		0
#define RSVD_PAGE_NAN_DISC_BCN		BCN0_NAN_SYNC_PAGE_NUM + 0
#define RSVD_PAGE_NAN_SDF			BCN0_NAN_SYNC_PAGE_NUM + 1
#endif

#define FW_WOWLAN_REASON_RX_PAIRWISEKEY		0x01
#define FW_WOWLAN_REASON_RX_DISASSOC			0x04
#define FW_WOWLAN_REASON_RX_DEAUTH			0x08
#define FW_WOWLAN_REASON_FWDECISION_DISCONNECT		0x10

#define cpMacAddr(des,src)					((des)[0]=(src)[0],(des)[1]=(src)[1],(des)[2]=(src)[2],(des)[3]=(src)[3],(des)[4]=(src)[4],(des)[5]=(src)[5])
#define cpIpAddr(des,src)					((des)[0]=(src)[0],(des)[1]=(src)[1],(des)[2]=(src)[2],(des)[3]=(src)[3])

//ARP element
#define SET_ARP_PKT_HW(__pHeader, __Value)  			WriteEF2Byte( ((u8*)(__pHeader)) + 0, __Value)
#define SET_ARP_PKT_PROTOCOL(__pHeader, __Value)  		WriteEF2Byte( ((u8*)(__pHeader)) + 2, __Value)
#define SET_ARP_PKT_HW_ADDR_LEN(__pHeader, __Value)  		WriteEF1Byte( ((u8*)(__pHeader)) + 4, __Value)
#define SET_ARP_PKT_PROTOCOL_ADDR_LEN(__pHeader, __Value)  	WriteEF1Byte( ((u8*)(__pHeader)) + 5, __Value)
#define SET_ARP_PKT_OPERATION(__pHeader, __Value) 		WriteEF2Byte( ((u8*)(__pHeader)) + 6, __Value)
#define SET_ARP_PKT_SENDER_MAC_ADDR(__pHeader, _val) 		cpMacAddr(((u8*)(__pHeader))+8, (u8*)(_val))
#define SET_ARP_PKT_SENDER_IP_ADDR(__pHeader, _val) 		cpIpAddr(((u8*)(__pHeader))+14, (u8*)(_val))
#define SET_ARP_PKT_TARGET_MAC_ADDR(__pHeader, _val) 		cpMacAddr(((u8*)(__pHeader))+18, (u8*)(_val))
#define SET_ARP_PKT_TARGET_IP_ADDR(__pHeader, _val) 		cpIpAddr(((u8*)(__pHeader))+24, (u8*)(_val))

//---------------------------------------------------------------------------------------------------------//
//----------------------------------    Function Statement     --------------------------------------------------//
//---------------------------------------------------------------------------------------------------------//
// host message to firmware cmd
void wifi_hal_rsvpage_fill_txff(u16 addr_offset, u8 *ReservedPagePacket, u16 len);
void wifi_hal_rsvpage_read_txff(u16 addr_offset, u8 *buf, u16 len);
void wifi_hal_h2c_joinbss(u8 mstatus);
void wifi_hal_h2c_set_media_status(u8 mstatus, u8 macid);
void wifi_hal_rsvpage_pkt_download(u8 iface_type, u8 mstatus);
void wifi_hal_c2h_pkt_pre_hdl(u8 *buf, u16 len);
s32 wifi_hal_h2c_fill_cmd(u32 CmdLen, u8 *pCmdBuffer);
int wifi_hal_h2c_keep_alive_cmd(u8 enable, u8 pkt_type, u8 keepalive_interval);
int wifi_hal_h2c_wowlan_ctrl_cmd(u8 enable, u32 dot11PrivacyAlgrthm, u32 dot118021XGrpPrivacy);

void wifi_hal_rsvpage_pkt_btcoex(u8 iface_type);
void wifi_hal_rsvpage_pkt_construct(u8 iface_type);

void wifi_hal_rsvpage_construct_mgnt(u8 iface_type, u8 *pframe,	u32 *pLength, u8 *StaAddr);
void wifi_hal_rsvpage_construct_null(u8 iface_type, u8 *pframe, u32 *pLength, u8 *StaAddr, u8 bQoS, u8 AC, u8 bEosp, u8 bForcePowerSave);
void wifi_hal_rsvpage_construct_null_bt(u8 iface_type, u8 *pframe, u32 *pLength, u8 *StaAddr, u8 bQoS, u8 AC, u8 bEosp, u8 bForcePowerSave);
void wifi_hal_h2c_set_rsvpage_cmd(void);
void wifi_hal_rsvpage_construct_arp_response(u8 iface_type, u8 *pframe, u32 *pLength, u8 *pIPAddress, u8 *gateway, u8 *tkip_mic_skey);
void wifi_hal_h2c_set_phyreg_addr(void);
void wifi_hal_h2c_set_afereg_addr(void);
#ifdef CONFIG_WIFI_TUNNEL
void wifi_hal_h2c_set_wtn_father_aid(u8 father_aid, u8 add);
void wifi_hal_h2c_set_wtn_refugee_aid(u8 refugee_aid, u8 add);
#endif
#endif

#ifndef __HAL_COMMON_C2H_H__
#define __HAL_COMMON_C2H_H__
/*
* C2H event format:
* Fields    TRIGGER     PLEN      PAYLOAD    SEQ      ID
* BITS    [127:120]  [119:112]  [111:16]   [15:8]   [7:0]
*/
#define C2H_ID(_c2h)		LE_BITS_TO_1BYTE(((u8*)(_c2h)), 0, 8)
#define C2H_SEQ(_c2h)		LE_BITS_TO_1BYTE(((u8*)(_c2h)) + 1, 0, 8)
#define C2H_PAYLOAD(_c2h)	(((u8*)(_c2h)) + 2)
#define C2H_PLEN(_c2h)		LE_BITS_TO_1BYTE(((u8*)(_c2h)) + 14, 0, 8)

enum _C2H_EVT {
	C2H_DBG = 0x00,
	C2H_RA_RPT = 0x0C,
	C2H_RA_PARA_RPT = 0x0E,
	C2H_IQK_FINISH = 0x11,
	C2H_MCC = 0x17,
	C2H_NAN = 0x18,
#if defined(CONFIG_UNSUPPORT_PLCPHDR_RPT) && (CONFIG_UNSUPPORT_PLCPHDR_RPT)
	C2H_PLCPHDR_RPT = 0x2B,
#endif
	C2H_COEX_START = 0x60, /*coex use 0x60 ~ 0x7F C2H IDs*/
	C2H_COEX_END = 0x7F,
	C2H_EXTEND = 0xff,
};

#endif /* __HAL_CMD_H__ */
