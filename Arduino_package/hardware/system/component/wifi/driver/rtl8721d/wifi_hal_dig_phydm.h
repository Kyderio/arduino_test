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

#define DIG_R_RX_GAIN_INI_PATH0_C                  0xC50
#define DIG_R_RX_GAIN_INI_PATH0_C_M                0x0000007F

#define DIG_R_CNT_FA_UPPER_C                       0xA58
#define DIG_R_CNT_FA_UPPER_C_M                     0xFF000000
#define DIG_R_CNT_FA_LOWER_C                       0xA5C
#define DIG_R_CNT_FA_LOWER_C_M                     0x000000FF
#define DIG_R_CNT_CCK_CCA_NUM_C                    0xA60
#define DIG_R_CNT_CCK_CCA_NUM_C_M                  0x0000FFFF

#define DIG_R_CNT2_IND_OFDM_RATE_IDX_C             0xF04
#define DIG_R_CNT2_IND_OFDM_RATE_IDX_C_M           0x0000F000
#define DIG_R_CNT2_IND_HT_MCS_C                    0xF04
#define DIG_R_CNT2_IND_HT_MCS_C_M                  0x007F0000

#define DIG_R_CNT_RX_L_ERR_PARITY_C                0xDA0
#define DIG_R_CNT_RX_L_ERR_PARITY_C_M              0xFFFF0000
#define DIG_R_CNT_OFDM_CCA_NUM_C                   0xDA0
#define DIG_R_CNT_OFDM_CCA_NUM_C_M                 0x0000FFFF

#define DIG_R_CNT_RX_L_ERR_RATE_C                  0xDA4
#define DIG_R_CNT_RX_L_ERR_RATE_C_M                0x0000FFFF
#define DIG_R_CNT_RX_HT_ERR_CRC8_C                 0xDA4
#define DIG_R_CNT_RX_HT_ERR_CRC8_C_M               0xFFFF0000
#define DIG_R_CNT_RX_HT_NOT_SUPPORT_MCS_C          0xDA8
#define DIG_R_CNT_RX_HT_NOT_SUPPORT_MCS_C_M        0x0000FFFF

#define DIG_R_CNT_CCK_CRC32_OK_C                   0xF88
#define DIG_R_CNT_CCK_CRC32_OK_C_M                 0xFFFFFFFF
#define DIG_R_CNT_CCK_CRC32_FAIL_C                 0xF84
#define DIG_R_CNT_CCK_CRC32_FAIL_C_M               0xFFFFFFFF

#define DIG_R_CNT_OFDMRX_HT_CRC_OK_C               0xF90
#define DIG_R_CNT_OFDMRX_HT_CRC_OK_C_M             0x0000FFFF
#define DIG_R_CNT_OFDMRX_HT_CRC_ERR_C              0xF90
#define DIG_R_CNT_OFDMRX_HT_CRC_ERR_C_M            0xFFFF0000
#define DIG_R_CNT_OFDMRX_L_CRC_OK_C                0xF94
#define DIG_R_CNT_OFDMRX_L_CRC_OK_C_M              0x0000FFFF
#define DIG_R_CNT_OFDMRX_L_CRC_ERR_C               0xF94
#define DIG_R_CNT_OFDMRX_L_CRC_ERR_C_M             0xFFFF0000

#define DIG_R_CNT2_OFDMRX_HT_CRC_OK_C              0xF98
#define DIG_R_CNT2_OFDMRX_HT_CRC_OK_C_M            0x0000FFFF
#define DIG_R_CNT2_OFDMRX_HT_CRC_ERR_C             0xF98
#define DIG_R_CNT2_OFDMRX_HT_CRC_ERR_C_M           0xFFFF0000
#define DIG_R_CNT2_OFDMRX_L_CRC_OK_C               0xf9c
#define DIG_R_CNT2_OFDMRX_L_CRC_OK_C_M             0x0000FFFF
#define DIG_R_CNT2_OFDMRX_L_CRC_ERR_C              0xf9c
#define DIG_R_CNT2_OFDMRX_L_CRC_ERR_C_M            0xFFFF0000


#define DIG_R_CNT_SEG0_ERR_FAST_FSYNC_C            0xCF0
#define DIG_R_CNT_SEG0_ERR_FAST_FSYNC_C_M          0x0000FFFF
#define DIG_R_CNT_SEG0_SEARCH_FAIL_C               0xCF0
#define DIG_R_CNT_SEG0_SEARCH_FAIL_C_M             0xFFFF0000

#define DIG_R_CNT_OFDM_TX_EN_C                     0x9cc
#define DIG_R_CNT_OFDM_TX_EN_C_M                   0xFFFF0000
#define DIG_R_CNT_OFDM_TX_ON_C                     0x9cc
#define DIG_R_CNT_OFDM_TX_ON_C_M                   0x0000FFFF
#define DIG_R_CNT_CCK_TX_EN_C                      0x9d0
#define DIG_R_CNT_CCK_TX_EN_C_M                    0xFFFF0000
#define DIG_R_CNT_CCK_TX_ON_C                      0x9d0
#define DIG_R_CNT_CCK_TX_ON_C_M                    0x0000FFFF

#ifdef CONFIG_WIFI_CCKPD
#define CCK_FA_MA_RESET 0xffffffff
enum cckpd_mode {
	CCK_BW20_1R = 0,
	//CCK_BW20_2R = 1,
	//CCK_BW20_3R = 2,
	//CCK_BW20_4R = 3,
	CCK_BW40_1R = 1,//4,
	//CCK_BW40_2R = 5,
	//CCK_BW40_3R = 6,
	//CCK_BW40_4R = 7
};

#define CCKPD_R_PD_LIM_RFBW20_1R_C                  0xAC8
#define CCKPD_R_PD_LIM_RFBW20_1R_C_M                0x000000FF

#define CCKPD_R_PD_LIM_RFBW40_1R_C                  0xACC
#define CCKPD_R_PD_LIM_RFBW40_1R_C_M                0x000000FF

#define CCKPD_R_CS_RATIO_RFBW20_1R_C                  0xAD0
#define CCKPD_R_CS_RATIO_RFBW20_1R_C_M                0x0000001F

#define CCKPD_R_CS_RATIO_RFBW40_1R_C                  0xAD0
#define CCKPD_R_CS_RATIO_RFBW40_1R_C_M                0x01F00000

#define CCKPD_R_COR_IN_SHIFT_C                  	0xA08
#define CCKPD_R_COR_IN_SHIFT_C_M                	0x00300000

#define CCKPD_R_NRX_C								0xA2c
#define CCKPD_R_NRX_C_M								0x00020000

#define CCKPD_R_RF_MODE_C							0x800
#define CCKPD_R_RF_MODE_C_M							0x00000001

void wifi_hal_set_cck_pd(void);
void wifi_hal_cck_pd_init(void);
#endif

void wifi_hal_init_rateidx_for_cnt2(void);
void wifi_hal_fa_counter_reg_reset(void);
void wifi_hal_fa_counter_statistics(void);
#endif
