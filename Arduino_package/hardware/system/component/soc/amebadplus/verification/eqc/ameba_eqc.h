/*
 *  Routines to access hardware
 *
 *  Copyright (c) 2013 Realtek Semiconductor Corp.
 *
 *  This module is a confidential and proprietary property of RealTek and
 *  possession or use of this module requires written permission of RealTek.
 */

#include "ameba_soc.h"

#define NORMAL_EQC_TEST

/** @brief Log Module Definition */
typedef enum {
	_EQC_GPIO = 0,
	_EQC_ADC,	// 1
	_EQC_CTC,	// 2
	_EQC_USB,	// 3
	_EQC_WIFI,	// 4
	_EQC_BT,	// 5
	_EQC_KM4,	// 6
	_EQC_MEM,	// 7
	_EQC_TM,	// 8
	_EQC_MAX,	// 9

	_EQC_IGNORE = 0xFF,
} EQC_ITEMS_DEFINE;

typedef struct _EQC_CASE_TABLE_ {
	char *name;
	u32  Index;
	u32  CaseFlag;
	u32  ErrStatus;
	u32  DoneFlag;
} EQC_CASE_TABLE, *PEQC_CASE_TABLE;

//================functions=================

void eqc_ADCInit(u8 ChanNum, u8 *ChanIdx);
void eqc_getADCData(u8 ADC_channel, u16 *ADC_data);
void eqc_CapTouchInit(u8 ChanNum, u8 *ChanIdx);
bool eqc_GPIOLoopbackTest(u8 gpio_in, u8 gpio_out);
void eqc_USBInit(void);

extern void GDFlashEraseApp(void);
extern void GDFlashWRApp(void);
extern void PYFlashEraseApp(void);
extern void PYFlashWRApp(void);
extern void ZBFlashEraseApp(void);
extern void ZBFlashWRApp(void);
extern void WBPsramWRApp(void);
extern void APMPsramWRApp(void);

