/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#include "ameba_soc.h"

#define NORMAL_OLT_TEST

/** @brief Log Module Definition */
typedef enum {
	_OLT_GPIO		= 0,
	_OLT_ADC		, // 1
	_OLT_CAPTOUCH	, // 2
	_OLT_WIFI		, // 3
	_OLT_OTP		, // 4
	_OLT_USB		, // 5
	_OLT_THERMAL	, // 6
	_OLT_RSTCTRL	, // 7
	_OLT_LEDC		, // 8
	_OLT_APCore		, // 9
	_OLT_MAX		, // 10

	_OLT_IGNORE = 0xFF,
} OLT_ITEMS_DEFINE;

typedef struct _OLT_CASE_TABLE_ {
	char *name;
	u32  Index;
	u32  CaseFlag;
	u32  ErrStatus;
	u32  DoneFlag;
	//u32(*func)(u16 argc, u8 *argv[]);
	//const   u8 *msg;
} OLT_CASE_TABLE, *POLT_CASE_TABLE;

//================functions=================
void OLT_MarkR(u32 BitPos, bool PassOrNot);

void olt_ADCInit(void);
void olt_getADCData(u8 ch_idx, u16 *adcVal);
void olt_CapTouchInit(void);
void olt_getCapTouchData(u16 *ctc_data);
bool olt_gpioloopbackTest(u8 gpio_in, u8 gpio_out);
void olt_USBInit(void);
bool olt_USBloopbackTest(void);
