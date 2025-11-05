#ifndef __WIFIFW_BCNMODE_H__
#define __WIFIFW_BCNMODE_H__

/*--------------------Define --------------------------------------------*/
#define PHY_REG_TO_CHANGE 0xffffffff
/*--------------------Define Enum---------------------------------------*/
enum TYPE_BCN_MODE_REG {
	BCN_MODE_Set_2GIQ_REG  = 0,
	BCN_MODE_Cancel_2GIQ_REG = 1,
	BCN_MODE_2G = 2,
	BCN_MODE_Set_Ionly_REG = 3,
	BCN_MODE_Cancel_Ionly_REG = 4,
	BCN_MODE_5G_COM = 5,
	BCN_MODE_5GL = 6,
	BCN_MODE_5GM = 7,
	BCN_MODE_5GH = 8,
};

enum TYPE_RF_BCNMODE_REG {
	RF_ENTER_BCNMODE_2G = 0,
	RF_ENTER_BCNMODE_5G = 1,
	RF_EXIT_BCNMODE_2G = 2,
	RF_EXIT_BCNMODE_5G = 3,
};

enum RX_MODE_SEL {
	NORMAL_RX_MODE = 0,
	BCN_RX_MODE = 1,
};

enum TYPE_BCNMODE {
	BCN_MODE_ENTER = 0,
	BCN_MODE_EXIT = 1,
};

enum TYPE_BB_PARAMETER {
	BB_REG_SET = 0,
	BB_HIOE_SET = 1,
};

enum TYPE_RF_PARAMETER {
	RF_REG_SET = 0,
	RF_HIOE_SET = 1,
};
/*--------------------Function declaration---------------------------------*/
extern const u32 array_mp_8721f_Set_2G_BCNmode_IQ_reg[];
extern const u32 array_mp_8721f_Cancel_2G_BCNmode_IQ_reg[];
extern const u32 array_mp_8721f_BCNmode_2G_reg[];
extern const u32 array_mp_8721f_Set_Ionly_reg[];
extern const u32 array_mp_8721f_Cancel_Ionly_reg[];
extern const u32 array_mp_8721f_BCNmode_5G_com_reg[];
extern const u32 array_mp_8721f_BCNmode_5GL_reg[];
extern const u32 array_mp_8721f_BCNmode_5GM_reg[];
extern const u32 array_mp_8721f_BCNmode_5GH_reg[];
extern const u8 array_bcn_mode_reg_size[];
extern const u32 *array_bcn_mode_reg_table[];
extern const u16 array_rf_bcnmode_reg_size[];
extern const u32 *array_rf_bcnmode_reg_table[];
extern void wififw_bcnmode_normal_agc_backup_restore(bool bk_rs, u8 bb_parameter_set);
extern void wififw_bcnmode_bb_agc_set(u8 rx_mode_sel, u8 bb_parameter_set);
extern void wififw_bcnmode_get_phy_info(void);
extern void wififw_bcnmode_dck_backup(void);
extern void wififw_ps_bcnmode(bool on);
extern u8 wififw_agc_table_backup_restore(u8 reg_type, u8 bbagcreg_index, bool bk_rs, u8 bb_parameter_set);
extern void wififw_bcnmode_bb_parm_set(u8 reg_type, u8 bb_parameter_set);
extern void wififw_ps_bcnmode_set(u8 bcnmode_status, u8 bb_parameter_set);
#endif  /* __WIFIFW_PWRCTRL_H__ */
