/******************************************************************************
  *
  * This module is a confidential and proprietary property of RealTek and
  * possession or use of this module requires written permission of RealTek.
  *
  * Copyright(c) 2016, Realtek Semiconductor Corporation. All rights reserved.
  *
******************************************************************************/

#ifndef __RTW_DEBUG_H__
#define __RTW_DEBUG_H__


extern u8 OtherDebugPortEnable;
extern u32 GlobalDebugModule;

#undef	_dbgdump
#undef   _dbgdump_nr

#define _dbgdump_nr	DiagPrintf("\n\r"); DiagPrintf
#define _dbgdump	DiagPrintf


#include <diag.h> // for DRIVER_PREFIX

#if defined (_dbgdump)
#if defined(__GNUC__)

extern int msg_uart_port(const char *fmt, ...);
#define RTW_PRINT_MSG(...) 	\
	do {\
		if(OtherDebugPortEnable){\
			msg_uart_port(__VA_ARGS__);\
		} else {\
			_dbgdump(__VA_ARGS__);\
		} \
	}while(0)
#endif
#endif


#endif	//__RTW_DEBUG_H__

