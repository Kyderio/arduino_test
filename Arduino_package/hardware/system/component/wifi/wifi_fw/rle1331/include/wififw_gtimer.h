#ifndef __WIFIFW_GTIMER_H__
#define __WIFIFW_GTIMER_H__

/*--------------------Define --------------------------------------------*/
#define CLKSYNCTIME					35

/* General Purpose Timer (Offset: 0x0150 - 0x016Fh) */
#define UNIT_MS					1
#define UNIT_32US				0

#define TC_ENABLE					BIT0
#define TC_TIMER_MODE				BIT1
#define TC_INT_ENABLE				BIT2

/*TIMER allcation*/
#define COUNTER_WAITFCS						REG_TC0_CTRL //start a protect timer for MAC not receive FCS after lps offload tim hit
#define COUNTER_LEAKAP						REG_TC0_CTRL
#define COUNTER_BCNTO						REG_TC1_CTRL  // counter used by BCNTO is the same with DTIM
#define COUNTER_DTIM						REG_TC1_CTRL
#define COUNTER_PSTRX 						REG_TC2_CTRL
#define COUNTER_BTC_MULTI_SLOT_INSERT       REG_TC3_CTRL
#define COUNTER_BT_CTRL_PROTECT_BCN         REG_TC3_CTRL
#define COUNTER_DELAYKEEPALIVE				REG_TC1_CTRL
#define COUNTER_CSITX						REG_TC3_CTRL
#define COUNTER_BTCOEX				        REG_TC3_CTRL

/*--------------------Function declaration---------------------------------*/
extern void wififw_gtimer_set_timeout(u16 timer_addr, u8 unit, u32 counter);
extern void wififw_inthdl_gtimer_reset(u16 reg_addr, u32 bit);
extern void wififw_inthdl_gtimer0(void);
extern void wififw_inthdl_gtimer1(void);
extern void wififw_inthdl_gtimer2(void);
extern void wififw_inthdl_gtimer3(void);
extern void wififw_inthdl_gtimer4(void);
extern void wififw_inthdl_gtimer5(void);

#endif  /* __WIFIFW_GTIMER_H__ */
