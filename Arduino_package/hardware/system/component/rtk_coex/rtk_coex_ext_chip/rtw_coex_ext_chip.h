#ifndef RTW_COEX_EXT_CHIP_H
#define RTW_COEX_EXT_CHIP_H

enum WL_STEP_INFO {
	STEP_UNDEF = 0,
	STEP_WL_CHG_IPS,
	STEP_WL_CHG_CONNECT,
	STEP_WL_CHG_SCAN,
	STEP_EXT_COMMON_CHG_WL_PERF,
	STEP_EXT_WP_CHG_CHANNEL,
	STEP_EXT_BT_CHG_PROFILE,
} ;

enum rtk_coex_ext_wp_prio {
	RTK_COEX_EXTWP_PRIO_WL = 0,
	RTK_COEX_EXTWP_PRIO_WP
};

struct rtk_coex_ext_board_info {
	bool b_dedicated_ant;
	u8 ext_pta_active_protocol; //-> EXT_PROTOCOL
	u8 ext_pta_pri_det_time; // T1 us
	u8 ext_pta_trx_det_time; // T2 us
	u8 ext_pta_pri_mode : 1; // 1: static Priority; 0: directional Priority
	u8 ext_pta_req_polar : 1; // 1: active high; 0: active low
	u8 ext_pta_gnt_polar : 1; // 1: active high; 0: active low
	u8 ext_pta_index : 1; // 0(EXT_PTA1): wl-zb-pta; 1(EXT_PTA2): wl-bt-pta
	u8 rsvd: 4;
	u8 ext_pta_pad_req;
	u8 ext_pta_pad_pri;
	u8 ext_pta_pad_gnt;
};


struct rtk_coex_ext_chip_ops {
	void (*pta_enable)(void *p_rtk_coex, bool enable);
	void (*pta_para_set)(void *p_rtk_coex);
	void (*pta_set_tbl)(void *p_rtk_coex, u8 coex_tbl_choose, u32 coex_tbl_1, u32 coex_tbl_2, u32 coex_break_tbl);
	void (*pta_set_pinmux)(void *p_rtk_coex);
	void (*pta_gnt_config)(void *p_rtk_coex, bool manual);
};

struct rtk_coex_ext_chip_dm {
	u8 wl_performance;
};

struct rtk_coex_ext_chip_para {
	u8 chip_id;
	struct rtk_coex_ext_chip_ops *ops;
};

struct rtk_coex_ext_wpan_info {
	u8 channel : 5;
	u8 rsvd: 3;
};
struct rtk_coex_ext_bt_info {
	u8 profile;
};

struct rtk_coex_ext_chip {
	u8 ext_coex_ready;
	u32 ext_coex_state_map;

	struct rtk_coex_ext_chip_para *p_chip_para;
	struct rtk_coex_ext_chip_dm coex_dm;
	struct rtk_coex_ext_board_info board_info;
	struct rtk_coex_ext_wpan_info ext_wpan_info;
	struct rtk_coex_ext_bt_info ext_bt_info;
};

#endif
