/******************************************************************************
 *
 * Copyright(c) 2019 Realtek Corporation.
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
 *****************************************************************************/
#ifndef _HALRF_API_H_
#define _HALRF_API_H_
/*@--------------------------[Define] ---------------------------------------*/
#define HALRF_ABS(a,b) ((a>b) ? (a-b) : (b-a))
/*@--------------------------[Enum]------------------------------------------*/
enum phlrf_lna_set {
	PHLRF_LNA_DISABLE = 0,
	PHLRF_LNA_ENABLE = 1,
};

enum halrf_rfk_type {
	RF_BTC_IQK		= 0,
	RF_BTC_LCK		= 1,
	RF_BTC_DPK		= 2,
	RF_BTC_TXGAPK		= 3,
	RF_BTC_DACK		= 4,
	RF_BTC_RXDCK		= 5,
	RF_BTC_TSSI		= 6,
	RF_BTC_NOTIFY		= 7
};

enum halrf_rfk_process {
	RFK_STOP		= 0,
	RFK_START		= 1,
	RFK_ONESHOT_START	= 2,
	RFK_ONESHOT_STOP	= 3
};

enum adc_ck {
	ADC_NA	= 0,
	ADC_480M	= 1,
	ADC_960M	= 2,
	ADC_1920M	= 3,
};

enum dac_ck {
	DAC_40M	= 0,
	DAC_80M	= 1,
	DAC_120M	= 2,
	DAC_160M	= 3,
	DAC_240M	= 4,
	DAC_320M	= 5,
	DAC_480M	= 6,
	DAC_960M	= 7,
};

enum halrf_event_idx {
	RF_EVENT_PWR_TRK = 0,
	RF_EVENT_IQK = 1,
	RF_EVENT_DPK = 2,
	RF_EVENT_TXGAPK = 3,
	RF_EVENT_DACK = 4
};

enum halrf_event_func {
	RF_EVENT_OFF = 0,
	RF_EVENT_ON = 1,
	RF_EVENT_TRIGGER = 2
};

/*@--------------------------[Structure]-------------------------------------*/

/*@--------------------------[Prptotype]-------------------------------------*/
struct rf_info;

void halrf_dump_reg(void);

void halrf_tmac_tx_pause(enum phl_phy_idx band_idx, bool pause);

void halrf_thermal_period(void);

void halrf_btc_rfk_ntfy(u8 phy_map, enum halrf_rfk_type type,
						enum halrf_rfk_process process);

void halrf_fast_chl_sw_backup(u8 chl_index, u8 t_index);

void halrf_fast_chl_drv_reload(u8 chl_index, u8 t_index, enum phl_phy_idx phy);

/*MCC function*/
void halrf_mcc_info_init(enum phl_phy_idx phy);
void halrf_mcc_get_ch_info(enum phl_phy_idx phy);
void  halrf_watchdog_stop(bool is_stop);
bool halrf_btc_rf_bton_para(bool bt_s1);
bool halrf_btc_rf_switchband_para(void);
bool halrf_detect_lck_done(void);
void halrf_bkup_bb_reg(u32 *reg, u32 *reg_backup, u32 reg_num);
void halrf_reload_bb_reg(u32 *reg, u32 *reg_backup, u32 reg_num);
void halrf_bkup_rf_reg(u32 *reg, u32 *reg_backup, u32 reg_num);
void halrf_reload_rf_reg(u32 *reg, u32 *reg_backup, u32 reg_num);
u8 halrf_tssi_get_efuse_group(u8 channel);

#endif
