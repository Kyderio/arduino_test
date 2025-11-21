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

#ifndef __ROM_HAL_COMMON_H__
#define __ROM_HAL_COMMON_H__

struct rtw_csi_trigger_cfg {
	u16 csi_mgnt_trig_frame;
	u16 csi_ctrl_trig_frame;
	u16 csi_data_trig_frame;
};

/* The following is a unified statement of rom function, which must be strictly followed by each chip */
void ROM_WIFI_DISCONNECT(void);
void ROM_WIFI_BSSID_SET(u8 iface_type, u8 *val);
void ROM_WIFI_SetMSR(u8 iface_type, u8 val);
void ROM_WIFI_ACM_CTRL(u8 ctrl);
void ROM_WIFI_PHY_STATUS_CFG(u8 enable);
void ROM_WIFI_SET_APMODE(u8 enable, u32 pIntrMask[]);
void ROM_WIFI_UPDATE_Slottime(u16 updateCap, u8 *preamble_mode, u8 *slotTime, u8 cur_channel);
void ROM_WIFI_SET_CCA(u8 enable);
void ROM_WIFI_SET_EDCCA(u8 enable);
void ROM_WIFI_Set_AC_Param(u32 ACParam[], u32 *pBE_param);
void ROM_WIFI_Set_MLME_JOIN(u8 buddy_is_AP, u8 buddy_is_assoc, u8 type);
void ROM_WIFI_Set_TXOP_Thres(u16 rts_th, u8 enable);
void ROM_WIFI_ADDR_CAM_ENTRY_VALID(u32 entrys, u8 valid);
void ROM_WIFI_Set_MLME_Sitesurvey(u8 iface_type, u8 buddy_is_AP_on, u8 survey_state);
void ROM_WIFI_PORT_EN_CTRL(u8 port, u8 enable);
void ROM_WIFI_SET_NAV_CHK(u8 nav_update_th, u8 ignore_tx_nav);
void ROM_WIFI_SET_LIFETIME(u16 lifetime_bebk, u16 lifetime_vivo);
/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_init.c
--------------------------------------------------------------------------------*/
void ROM_WIFI_InitRetryFunction(void);
int ROM_WIFI_InitLLTTable(void);
void ROM_WIFI_INIT_MACADDR_SET(u8 iface_type, u8 *val);
void ROM_WIFI_INIT_BeaconParameters(sint BeSta);
void ROM_WIFI_INIT_ReadChipVersion(enum chip_name_e *name, enum chip_cut_e *cut);
void ROM_WIFI_InitTxBufferBoundary(u8 txpktbuf_bndy);
void ROM_WIFI_InitNormalChipRegPriority(u16 beQ, u16 bkQ, u16 viQ, u16 voQ, u16 mgtQ, u16 hiQ);
void ROM_WIFI_InitPageBoundary(u16 rxff_bndy);
void ROM_WIFI_InitNetworkType(u8 iface_type, u32 NetType);
void ROM_WIFI_InitAdaptiveCtrl(u32 RATE_RRSR, u16 SIFS, u16 RetryLimit);
void ROM_WIFI_InitSIFS(u16 SPEC_SIFS, u16 MAC_SPEC_SIFS, u16 SIFS_CTX, u16 SIFS_TRX);
void ROM_WIFI_InitEDCA(u32 EDCA_BE, u32 EDCA_BK, u32 EDCA_VI, u32 EDCA_VO);
void ROM_WIFI_InitBurstPktLen(u8 PKT_LIMIT);
void ROM_WIFI_InitMacClk(u8 clk);
void ROM_WIFI_Init32kClk(void);
void ROM_WIFI_ENABLE_BB_RF(u8 enable);
void ROM_WIFI_DISABLE_MAC_CG(void);

void ROM_WIFI_InitRateFallback(u32 DARFRC0, u32 DARFRC1, u32 RARFRC, u32 RARFRC1);
void ROM_WIFI_InitQueueReservedPage(u32 tx_total_page_number);


void ROM_WIFI_Init_RESP_RATE(void);
/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_misc.c
--------------------------------------------------------------------------------*/
void ROM_WIFI_32K_Cmd(u32 NewStatus, u8 AckEnable, u32 SleepType);
void ROM_WIFI_FIFO_CLEARN_UP(u8 bkeepfwalive);
void ROM_WIFI_CHECK_TXBUF(void);
void ROM_WIFI_CONFIG_CSI(u8 enable, u8 mode, u8 *mac_addr, struct rtw_csi_trigger_cfg *csi_cfg);
void ROM_WIFI_CONFIG_RADAR(u8 enable);

void ROM_WIFI_IMR_UPDATE(u32 pIntrMask[], u32 pAddMSRB[], u32 pRemoveMSR[]);
void ROM_WIFI_ICV_CHECK_CFG(u32 security_alg);
void ROM_WIFI_CTRL_PKT_RPT(u8 enable);
void ROM_WIFI_SET_MAX_AGG_NUM(u16 max_num);
u8 ROM_WIFI_GET_MAX_AGG_NUM(void);
u8 ROM_WIFI_High_Queue_Empty_Check(void);
u32 ROM_WIFI_GET_TXBUF_PKT_NUM(void);
void ROM_WIFI_MAC_CCK_CHECK(u8 enable);

void ROM_WIFI_RX_COND_SET(u8 physts_cond_value);
u32 ROM_WIFI_RX_COND_GET(void);

bool ROM_WIFI_GetChnlGroup(u8 Channel, u8 *pGroup);

/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_bcn.c
--------------------------------------------------------------------------------*/
void ROM_WIFI_BCN_FUNC(u8 iface_type, u8 *val);
void ROM_WIFI_BCN_Tx_Ctrl(u8 enable);
void ROM_WIFI_BCN_Interval(u8 iface_type, u16 bcn_interval);
void ROM_WIFI_BCN_FUNC_Enable(void);
void ROM_WIFI_BCN_VALID(u8 iface_type);

/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_debug.c
--------------------------------------------------------------------------------*/
u32 _rom_wifi_hal_get_rf_addr(u32 path, u32 reg_addr);
void _rom_wifi_hal_write_rf_reg(u32 addr, u32 data);
void rom_wifi_hal_dbg_mac_reg_dump(char *cmd_ptr, u32 param);
void rom_wifi_hal_dbg_bb_reg_dump(char *cmd_ptr, u32 param);
void rom_wifi_hal_dbg_rf_reg_dump(char *cmd_ptr, u32 param);
void rom_wifi_hal_dbg_rx_cnt(char *cmd_ptr, u32 param);

void rom_wifi_hal_dbg_change_edcca_mode(u32 param, unsigned char rtw_edcca_mode);
void rom_wifi_hal_dbg_tx_cnt(char *cmd_ptr, u32 param);
void rom_wifi_hal_dbg_rxff(char *cmd_ptr, u32 param);
void rom_wifi_hal_dbg_txff(char *cmd_ptr, u32 param);
void rom_wifi_hal_dbg_read_bb_reg(char *cmd_ptr, u32 param);

void rom_wifi_hal_dbg_change_cca_mode(char *cmd_ptr, u32 param);

/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_media_access
--------------------------------------------------------------------------------*/
void ROM_WIFI_INIT_ADDR_CAM(void);

/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_rate
--------------------------------------------------------------------------------*/
void ROM_WIFI_BRate_Get(u8 *mBratesOS, u16 *pBrateCfg);
void ROM_WIFI_BRate_Set(u8 *pval);

/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_rxdesc
--------------------------------------------------------------------------------*/
s32 ROM_WIFI_HAL_RXDESC_Percentage2dbm(u32 SignalStrengthIndex);
u8 ROM_WIFI_HAL_RXDESC_Power2strength(s8 ant_power);
void ROM_WIFI_HAL_RXDESC_ProcessSignal(struct smooth_signal_stat *signal_stat, s8 current_signal, s8 *avg_signal);

/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_secure
--------------------------------------------------------------------------------*/
void ROM_WIFI_CAM_READ(u8 id, u8 *ctrl, u8 *mac, u8 *key);
void ROM_WIFI_SEC_CFG(u8 sec_cfg, u32 sw_encrypt);
void ROM_WIFI_CAM_WriteSppAmsduValid(u8 entry, u8 value);
void ROM_WIFI_CAM_Entry_Clear(u8 entry);
void ROM_WIFI_CAM_FLUSH_ALL(u32 is_STA, u32 buddy_linked);

/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_tsf
--------------------------------------------------------------------------------*/
u64 ROM_WIFI_TSF_GetFreeRun(void);
void ROM_WIFI_TSF_TIMER0_SOURCE_CFG(u8 sel);
u64 ROM_WIFI_TSF_GetByPort(u8 port);
void ROM_WIFI_TSF_Sync(void);
void ROM_WIFI_TSF_Sync_P1_From_P0(void);
void ROM_WIFI_TSF_FREERUN_CFG(u8 enable);

/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_txdesc
--------------------------------------------------------------------------------*/
u8 ROM_WIFI_TXDESC_BWMapping(u8 bwmode, enum channel_width CurrentChannelBW);
u8 ROM_WIFI_TXDESC_SCMapping(u8 bwmode, enum channel_width CurrentChannelBW, u8 pri_ch, u8 central_ch);
u8 ROM_WIFI_TXDESC_FillSectype(u8 encrypt, u8 bswenc);
void ROM_WIFI_TXDESC_FillFake(u32 dot11PrivacyAlgrthm, u8 *pDesc, u32 BufferLen, u8 IsPsPoll, u8 IsBTQosNull, u8 bDataFrame);
u16 ROM_WIFI_TXDESC_Get_BufAddr(u16 ff_hwaddr);

/*-------------------------------------------------------------------------------
	common function in rom_wifi_hal_txpower
--------------------------------------------------------------------------------*/
void wifi_hal_pwr_lmt_regu_remapping(u8 *pRegulation, u8 chnlplan);

#endif
