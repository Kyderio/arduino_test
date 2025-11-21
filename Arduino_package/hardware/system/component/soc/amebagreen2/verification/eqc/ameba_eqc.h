/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#include "ameba_soc.h"

#define EQC_TEST_DUT
#define EQC_TEST_REG	0x4080AFE0
#define EQC_RES_OFFSET	0x10 // result offset: [11:0] -> [27:16]

#define EQC_GET_GPIO_OPT(x)	((x) & 0x3) // [1:0]
#define EQC_GET_BT_OPT(x)	(((x) >> 12) & 0x7) // [14:12]

/** @brief Log Module Definition */
typedef enum {
	EQC_POWER = 0	,
	EQC_OTP			, // 1
	EQC_MEM			, // 2
	EQC_ADC			, // 3
	EQC_CTC			, // 4
	EQC_CPU			, // 5
	EQC_THERMAL		, // 6
	EQC_USB			, // 7
	EQC_GPIO		, // 8
	EQC_WIFI2G		, // 9
	EQC_WIFI5G		, // 10
	EQC_BT			, // 11
	EQC_READY = 15	, // 15
	EQC_MAX = 15	, // 15

	EQC_IGNORE = 0xFF,
} EQC_ITEMS_DEFINE;

typedef struct EQC_CASE_TABLE {
	char *name;
	u32  Index;
	u32  CaseFlag;
	u32  ErrStatus;
	u32  DoneFlag;
	//u32(*func)(u16 argc, u8 *argv[]);
	//const   u8 *msg;
} EQC_CASE_TABLE, *PEQC_CASE_TABLE;


/** @brief Log Module Definition */
typedef enum {
	EQC_WIFI_SOFTAP_2G = 0		, // 0
	EQC_WIFI_SOFTAP_5G		, // 1
	EQC_BT_SERVER			, // 2
} EQC_DUT_ITEMS_DEFINE;


//================functions=================
void EQC_MarkR(u32 BitPos, u8 PassOrNot);

void eqc_ADCInit(void);
void eqc_getADCData(u8 ch_idx, u16 *adcVal);
void eqc_CapTouchInit(void);
void eqc_getCapTouchData(u16 *ctc_data);
bool eqc_GpioLoopbackTest(u8 gpio_in, u8 gpio_out);
int eqc_USBInit(void);
void eqc_USBDeInit(void);
int eqc_USBloopbackTest(void);
