#ifndef __WIFI_INTF_G6_TO_HAL_DEF_H__
#define __WIFI_INTF_G6_TO_HAL_DEF_H__

enum tx_pause_rson {
	G6_PAUSE_RSON_NOR_SCAN, /*normal scan*/
	G6_PAUSE_RSON_RFK,
	G6_PAUSE_RSON_PSD,
	G6_PAUSE_RSON_DFS,
	G6_PAUSE_RSON_DFS_CSA,
	G6_PAUSE_RSON_DBCC,
	G6_PAUSE_RSON_RESET,
};

enum bb_rfe_src_sel {
	PAPE_RFM		= 0,
	GNT_BT_INV		= 1,
	LNA0N			= 2,
	LNAON_RFM		= 3,
	TRSW_RFM		= 4,
	TRSW_RFM_B		= 5,
	GNT_BT			= 6,
	ZERO			= 7,
	ANTSEL_0		= 8,
	ANTSEL_1		= 9,
	ANTSEL_2		= 0xa,
	ANTSEL_3		= 0xb,
	ANTSEL_4		= 0xc,
	ANTSEL_5		= 0xd,
	ANTSEL_6		= 0xe,
	ANTSEL_7		= 0xf
};

/*mapping to habb_supportability_t*/
enum bb_support_ablty {
	ODM_BB_RA_MASK = BIT0,
	ODM_BB_FA_CNT = BIT1,
	ODM_BB_DFS = BIT3,
	ODM_BB_EDCCA = BIT4,
	ODM_BB_ENVMNTR = BIT5,
	ODM_BB_CFO_TRK = BIT6,
	ODM_BB_PWR_CTRL = BIT7,
	ODM_BB_DIG = BIT11,
	ODM_BB_ULTB_CTRL = BIT13,
};

#endif
