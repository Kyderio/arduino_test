#include "ameba_soc.h"

/* Exported constants --------------------------------------------------------*/
/*
 * Log Module Definition
 */
typedef enum {
	_EMC_LCDC	= 0,
	_EMC_RMII		, // 1
	_EMC_CAN		, // 2
	_EMC_SDIOH		, // 3
	_EMC_CAPTOUCH	, // 4
	_EMC_USB		, // 5
	_EMC_FLASH		, // 6
	_EMC_PSRAM		, // 7

	_EMC_MAX		,

	_EMC_IGNORE = 0xFF,
} EMC_ITEMS_DEFINE;

typedef struct _EMC_CASE_TABLE_ {
	char *name;
	u32  Index;
	u32  CaseFlag;
	u32  ErrStatus;
	u32  DoneFlag;
} EMC_CASE_TABLE, *PEMC_CASE_TABLE;

/* Exported functions --------------------------------------------------------*/

_LONG_CALL_ void EMC_MarkR(u32 BitPos, bool PassOrNot);

