#ifndef __WIFIFW_HIOE_COMMON_H__
#define __WIFIFW_HIOE_COMMON_H__
/*--------------------Define --------------------------------------------*/
#define HIOE_BACKUP		1
#define HIOE_RESTORE	0
#define HIOEDelayCmd		(0xFFFE)
#define HIOECmdFileEndFlg	(0xFFFF)//avoid same as hioe byte/dowrd/delay cmd
#define HIOECmdFileValEndFlg	(0xFFFFFFFF)
#define HIOE_ACCESS_BYTE_MODE	(0x00000000)
#define HIOE_ACCESS_DWORD_MODE	(0x00000001)
#define HIOE_DELAY_MODE	(0x00000003)
#define HIOE_MODE_MASK	(0x00000003)
#define HIOE_BYTE_SEL_MASK	(0x0000000F)
#define HIOE_BYTE_SEL_MASK_SHT	(24)
#define HIOE_REG_ADDR_MASK	(0x003FFFFF)
#define HIOE_REG_ADDR_MASK_SHT	(2)
#define HIOE_DATA_BYTE0_MASK	(0xFF000000) //bit 24~31
#define HIOE_DATA_BYTE123_MASK	(0x00FFFFFF) //bit 32~55
#define HIOECMD_SIZE_WM		(8)
#define HIOECMD_SIZE_BM		(4)
#define HIOECMD_SIZE_DM		(4)
#define HIOECMD_TYPE_DELAY	(0xFFFFFFFF)
#define HIOECMD_ARfcRegBaseAddr		(0x17000)
#define HIOECMD_DRfcRegBaseAddr		(0x1E000)
#define HIOECMD_BBRegBaseAddr		(0x10000)
#define TXFF_RETENTION_START_ADDR (24 * 1024)

#define HIOE_DM_INITVALTAB_TYPE(x) 	((x)|BIT(4))
#define HIOE_CMDFILE_SIZE(x)		((sizeof(x) - 4)*2)

#define HIOECMD_WM0(reg_addr)		\
	(HIOE_ACCESS_DWORD_MODE | ((((u32)(reg_addr)) & HIOE_REG_ADDR_MASK)<<HIOE_REG_ADDR_MASK_SHT))

#define HIOECMD_WM1(byte_sel)		(((u32)(byte_sel) & HIOE_BYTE_SEL_MASK)<<HIOE_BYTE_SEL_MASK_SHT)


#define HIOECMD_BM(reg_addr)		\
	(HIOE_ACCESS_BYTE_MODE | ((((u32)(reg_addr)) & HIOE_REG_ADDR_MASK)<<HIOE_REG_ADDR_MASK_SHT))

#define HIOECMD_DM(delay_time)		\
	(HIOE_DELAY_MODE | ((((u32)(delay_time)) & HIOE_REG_ADDR_MASK)<<HIOE_REG_ADDR_MASK_SHT))
#define HIOECMD_GetMode(x)	((x)&HIOE_MODE_MASK)

#define HIOE_ADDR_32BIT 1
#define HIOE_ADDR_16BIT 0

/*--------------------Function declaration---------------------------------*/
extern const char *TAG_FW_HIOE;
extern void wififw_hioe_write_dwcmd_to_txff(u32 CmdAddrIn8byte, u32 cmddw1, u32 cmddw2);
extern void wififw_hioe_single_cmd_into_txff(u32 cmdaddr, u32 reg_addr, u32 value);
extern u32 wififw_hioe_set_phyreg_value(u32 bit_mask, u32 val, u32 ori_val);
extern bool wififw_hioe_reg_match(u32 CmdFileStartAddr, u16 index, u32 addr, u32 *reg_value);
extern bool wififw_hioe_cmd_value_type_chk(u8 HIOECmdType, u8 InitValByteMask);
extern bool wififw_hioe_chn_idle_chk(u32 chn_ctrl_reg, u32 restore_reg_bit, u32 backup_req_bit);
extern void wififw_hioe_cmdfile_into_txff(u8 addr_bit_num, const void *HIOECmdAddrTab, const u32 *HIOECmdFileValTab);
extern void wififw_hioe_continuous_addr_cmdfile_init(u32 base_addr, u32 len_in_4byte);
extern void wififw_hioe_set_config_file(void);
extern void wififw_hioe_backup_restore(u32 option_bit, u16 cmdfile_start_addr, u16 cmdfile_end_addr);
#endif
