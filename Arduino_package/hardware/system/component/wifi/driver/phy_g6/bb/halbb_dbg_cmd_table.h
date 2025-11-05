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
#ifndef _HALBB_DBG_CMD_TABLE_H_
#define _HALBB_DBG_CMD_TABLE_H_
/*@--------------------------[Define] ---------------------------------------*/


/*@--------------------------[Enum]------------------------------------------*/
enum HALBB_CMD_ID {
	HALBB_HELP,
	HALBB_DEMO,
	HALBB_CMN_DBG,
	HALBB_TRACE,
	HALBB_MP_DBG,
	HALBB_SUPPORT_ABILITY,
	HALBB_TX_PW,
	HALBB_SPUR_SUPP,
	HALBB_LA_MODE,
	HALBB_AUTO_DBG,
	HALBB_SHOW_RXRATE,
	HALBB_NBI_EN,
	HALBB_CSI_MASK_EN,
	HALBB_DFS_DBG,
	HALBB_NHM,
	HALBB_CLM,
	HALBB_IFS_CLM,
	HALBB_FAHM,
	HALBB_EDCCA_CLM,
	HALBB_EDCCA,
	HALBB_ENV_MNTR,
	HALBB_BB_INFO,
	HALBB_H2C,
	HALBB_STASISTICS,
	HALBB_DBG_PORT,
	HALBB_CFO_TRK,
	HALBB_UL_TB,
	HALBB_ADAPTIVITY_DBG,
	HALBB_STA_INFO,
	HALBB_PAUSE_FUNC,
	HALBB_PER_TONE_EVM,
	HALBB_DYN_TXPWR,
	HALBB_DCC,
	HALBB_PMAC_TX,
	HALBB_CH_INFO,
	HALBB_DBCC,
	HALBB_ANT_DIV,
	HALBB_HW_SETTING,
	HALBB_PATH_DIV,
	HALBB_DTP,
	HALBB_TX_INFO,
	HALBB_DYN_1R_CCA,
	HALBB_CMN_INFO
};

/*@--------------------------[Structure]-------------------------------------*/

struct halbb_cmd_info {
	char name[16];
	u8 id;
};

static const struct halbb_cmd_info halbb_cmd_i[] = {
	{"-h", HALBB_HELP}, /*@do not move this element to other position*/
	{"demo", HALBB_DEMO}, /*@do not move this element to other position*/
	{"cmn", HALBB_CMN_DBG},
	{"dbg", HALBB_TRACE},
	{"mp_dbg", HALBB_MP_DBG},
	{"ability", HALBB_SUPPORT_ABILITY},
	{"tx_pw", HALBB_TX_PW},
	{"spur", HALBB_SPUR_SUPP},
	{"lamode", HALBB_LA_MODE},
	{"cfo_trk", HALBB_CFO_TRK},
	{"ul_tb", HALBB_UL_TB},
	{"rxrate", HALBB_SHOW_RXRATE},
	{"dfs", HALBB_DFS_DBG},
	{"nhm", HALBB_NHM},
	{"clm", HALBB_CLM},
	{"ifs_clm", HALBB_IFS_CLM},
	{"fahm", HALBB_FAHM},
	{"edcca_clm", HALBB_EDCCA_CLM},
	{"edcca", HALBB_EDCCA},
	{"env_mntr", HALBB_ENV_MNTR},
	{"stat", HALBB_STASISTICS},
	{"dbgport", HALBB_DBG_PORT},
	{"sta_info", HALBB_STA_INFO},
	{"pause", HALBB_PAUSE_FUNC},
	{"pmac_tx", HALBB_PMAC_TX},
	{"ch_info", HALBB_CH_INFO},
	{"dbcc", HALBB_DBCC},
	{"hw_set", HALBB_HW_SETTING},
	{"path_div", HALBB_PATH_DIV},
	{"txinfo", HALBB_TX_INFO},
	{"dyn_1r_cca", HALBB_DYN_1R_CCA},
	{"cmn_info", HALBB_CMN_INFO}
};

/*@--------------------------[Prptotype]-------------------------------------*/

#endif
