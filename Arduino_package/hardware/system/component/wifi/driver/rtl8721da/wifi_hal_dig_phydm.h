/******************************************************************************
 *
 * Copyright(c) 2007 - 2017  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/
#ifndef __WIFI_HAL_DIG_PHYDM_H__
#define __WIFI_HAL_DIG_PHYDM_H__

/* cr for dig start: need sync with bb: WB-230516-Dplus_CR_R05 */
#define DIG_R_RX_COMMON_CLK_GATING_C               0x1D70
#define DIG_R_RX_COMMON_CLK_GATING_C_M             0X80000000
#define DIG_R_RX_GAIN_INI_PATH0_C                  0x1D70
#define DIG_R_RX_GAIN_INI_PATH0_C_M                0x0000007F
#define DIG_R_CNT2_IND_VHT_NSS_C                   0x1EB8
#define DIG_R_CNT2_IND_VHT_NSS_C_M                 0x000000C0
#define DIG_R_CNT2_IND_OFDM_RATE_IDX_C             0x1EB8
#define DIG_R_CNT2_IND_OFDM_RATE_IDX_C_M           0x00000F00
#define DIG_R_CNT2_IND_VHT_MCS_C                   0x1EB8
#define DIG_R_CNT2_IND_VHT_MCS_C_M                 0x0000F000
#define DIG_R_CNT2_IND_HT_MCS_C                    0x1EB8
#define DIG_R_CNT2_IND_HT_MCS_C_M                  0x007F0000
#define DIG_R_CCK_RX_DIS_CCA_C                     0x2A24
#define DIG_R_CCK_RX_DIS_CCA_C_M                   0x00002000
#define DIG_R_CCK_RX_RPT_RST_C                     0x2A44
#define DIG_R_CCK_RX_RPT_RST_C_M                   0x0020000
#define DIG_R_CNT_CCK_CCA_NUM_C                    0x2AA0
#define DIG_R_CNT_CCK_CCA_NUM_C_M                  0x0000FFFF
#define DIG_R_CNT_CCK_SFD_FAIL_C                   0x2AA8
#define DIG_R_CNT_CCK_SFD_FAIL_C_M                 0x0000FFFF
#define DIG_R_CNT_CCK_CRC16_FAIL_C                 0x2AA8
#define DIG_R_CNT_CCK_CRC16_FAIL_C_M               0xFFFF0000
#define DIG_R_CNT_CCK_CRC32_OK_C                   0x2AAC
#define DIG_R_CNT_CCK_CRC32_OK_C_M                 0x0000FFFF
#define DIG_R_CNT_CCK_CRC32_FAIL_C                 0x2AAC
#define DIG_R_CNT_CCK_CRC32_FAIL_C_M               0xFFFF0000
#define DIG_R_CNT_OFDM_CCA_NUM_C                   0x2C08
#define DIG_R_CNT_OFDM_CCA_NUM_C_M                 0xFFFF0000
#define DIG_R_CNT_OFDMRX_VHT_CRC_OK_C              0x2C0C
#define DIG_R_CNT_OFDMRX_VHT_CRC_OK_C_M            0x0000FFFF
#define DIG_R_CNT_OFDMRX_VHT_CRC_ERR_C             0x2C0C
#define DIG_R_CNT_OFDMRX_VHT_CRC_ERR_C_M           0xFFFF0000
#define DIG_R_CNT_OFDMRX_HT_CRC_OK_C               0x2C10
#define DIG_R_CNT_OFDMRX_HT_CRC_OK_C_M             0x0000FFFF
#define DIG_R_CNT_OFDMRX_HT_CRC_ERR_C              0x2C10
#define DIG_R_CNT_OFDMRX_HT_CRC_ERR_C_M            0xFFFF0000
#define DIG_R_CNT_OFDMRX_L_CRC_OK_C                0x2C14
#define DIG_R_CNT_OFDMRX_L_CRC_OK_C_M              0x0000FFFF
#define DIG_R_CNT_OFDMRX_L_CRC_ERR_C               0x2C14
#define DIG_R_CNT_OFDMRX_L_CRC_ERR_C_M             0xFFFF0000
#define DIG_R_CNT2_OFDMRX_HT_CRC_OK_C              0x2C18
#define DIG_R_CNT2_OFDMRX_HT_CRC_OK_C_M            0x0000FFFF
#define DIG_R_CNT2_OFDMRX_HT_CRC_ERR_C             0x2C18
#define DIG_R_CNT2_OFDMRX_HT_CRC_ERR_C_M           0xFFFF0000
#define DIG_R_CNT2_OFDMRX_L_CRC_OK_C               0x2C1C
#define DIG_R_CNT2_OFDMRX_L_CRC_OK_C_M             0x0000FFFF
#define DIG_R_CNT2_OFDMRX_L_CRC_ERR_C              0x2C1C
#define DIG_R_CNT2_OFDMRX_L_CRC_ERR_C_M            0xFFFF0000
#define DIG_R_CNT_AMPDU_RX_CRC32_OK_C              0x2C40
#define DIG_R_CNT_AMPDU_RX_CRC32_OK_C_M            0x0000FFFF
#define DIG_R_CNT_AMPDU_RX_CRC32_ERR_C             0x2C40
#define DIG_R_CNT_AMPDU_RX_CRC32_ERR_C_M           0xFFFF0000
#define DIG_R_CNT_RX_L_ERR_PARITY_C                0x2D04
#define DIG_R_CNT_RX_L_ERR_PARITY_C_M              0xFFFF0000
#define DIG_R_CNT_RX_L_ERR_RATE_C                  0x2D08
#define DIG_R_CNT_RX_L_ERR_RATE_C_M                0x0000FFFF
#define DIG_R_CNT_RX_HT_ERR_CRC8_C                 0x2D08
#define DIG_R_CNT_RX_HT_ERR_CRC8_C_M               0xFFFF0000
#define DIG_R_CNT_VHT_ERR_SIGA_CRC8_C              0x2D0C
#define DIG_R_CNT_VHT_ERR_SIGA_CRC8_C_M            0x0000FFFF
#define DIG_R_CNT_VHT_ERR_SIGB_CRC8_C              0x2D0C
#define DIG_R_CNT_VHT_ERR_SIGB_CRC8_C_M            0xFFFF0000
#define DIG_R_CNT_RX_HT_NOT_SUPPORT_MCS_C          0x2D10
#define DIG_R_CNT_RX_HT_NOT_SUPPORT_MCS_C_M        0x0000FFFF
#define DIG_R_CNT_RX_VHT_NOT_SUPPORT_MCS_C         0x2D10
#define DIG_R_CNT_RX_VHT_NOT_SUPPORT_MCS_C_M       0xFFFF0000
#define DIG_R_CNT_SEG0_ERR_FAST_FSYNC_C            0x2D20
#define DIG_R_CNT_SEG0_ERR_FAST_FSYNC_C_M          0x0000FFFF
#define DIG_R_CNT_SEG0_SEARCH_FAIL_C               0x2D20
#define DIG_R_CNT_SEG0_SEARCH_FAIL_C_M             0xFFFF0000
#define DIG_R_SEG0_EDCCA_FLAG_C                    0x2D38
#define DIG_R_SEG0_EDCCA_FLAG_C_M                  0x01000000
#define DIG_R_BB_MONITOR_0_C                       0x2DB4
#define DIG_R_BB_MONITOR_0_C_M                     0xFFFFFFFF
#define DIG_R_CNT_OFDM_TX_EN_C                     0x2DE0
#define DIG_R_CNT_OFDM_TX_EN_C_M                   0x0000FFFF
#define DIG_R_CNT_OFDM_TX_ON_C                     0x2DE0
#define DIG_R_CNT_OFDM_TX_ON_C_M                   0xFFFF0000
#define DIG_R_CNT_CCK_TX_EN_C                      0x2DE4
#define DIG_R_CNT_CCK_TX_EN_C_M                    0x0000FFFF
#define DIG_R_CNT_CCK_TX_ON_C                      0x2DE4
#define DIG_R_CNT_CCK_TX_ON_C_M                    0xFFFF0000

void wifi_hal_init_rateidx_for_cnt2(void);
void wifi_hal_fa_counter_reg_reset(void);
void wifi_hal_fa_counter_statistics(void);
void wifi_hal_dig_set_pd_lower_bound(u8 new_igi, u8 b_dis_pd_low_bd);


#endif
