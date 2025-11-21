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
#ifndef _HALRF_PSD_H_
#define _HALRF_PSD_H_

/*@--------------------------Define Parameters-------------------------------*/

#define PSD_RF_PATH_MAX 1
#define PSD_RF_REG_NUM 5
#define PSD_BB_REG_NUM 19

#ifdef CONFIG_MP_INCLUDED
#define PSD_RF_DATA_NUM 320
#else
#define PSD_RF_DATA_NUM 1
#endif


/*@-----------------------End Define Parameters-----------------------*/
struct halrf_psd_data {
	u32 psd_data[PSD_RF_DATA_NUM];
	u32 psd_progress;
	u8 psd_result_running;
	u32 psd_reg_backup[PSD_BB_REG_NUM];
	u32 rf_bkup[PSD_RF_REG_NUM];
};

#endif	/*_HALRF_PSD_H_*/
