#include "ameba_soc.h"

/* Exported constants --------------------------------------------------------*/
/*
 * Log Module Definition
 */
typedef enum {
	_EMC_LCD	= 0,
	_EMC_AUDIO		, // 1
	_EMC_CAPTOUCH	, // 2
	_EMC_SD			, // 3
	_EMC_USB		, // 4
	_EMC_FLASH		, // 5

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

/*
 * NAND FLASH 1Gb()
 */
#define NAND_PAGE_SIZE_SPARE_64B_BIT_EXP 	(6)

#define NAND_PAGE_SIZE_MAIN_BIT_EXP 		NAND_PAGE_SIZE_MAIN_2K_BIT_EXP
#define NAND_PAGE_SIZE_MAIN 				(1U << NAND_PAGE_SIZE_MAIN_BIT_EXP)

#define NAND_PAGE_SIZE_SPARE_BIT_EXP 		NAND_PAGE_SIZE_SPARE_64B_BIT_EXP
#define NAND_PAGE_SIZE_SPARE 				(1U << NAND_PAGE_SIZE_SPARE_BIT_EXP)

/*page size is 2k + 64 bytes*/
#define NAND_PAGE_SIZE 						(NAND_PAGE_SIZE_MAIN + NAND_PAGE_SIZE_SPARE)

/*Each block has 64 page.*/
#define NAND_BLOCK_PAGE_CNT_BIT_EXP 		(6)
#define NAND_BLOCK_PAGE_CNT 				(1U << NAND_BLOCK_PAGE_CNT_BIT_EXP)
#define NAND_BLOCK_PAGE_MASK 				(NAND_BLOCK_PAGE_CNT - 1)

#define NAND_BLOCK_ID_TO_PAGE_ADDR(block_id)	((block_id) << NAND_BLOCK_PAGE_CNT_BIT_EXP)

/*1Gb Nand Flash has 1024 blocks with 2K page*/
#define NAND_BLOCK_CNT 						(1024)

#define NAND_ADDR_TO_PAGE_ADDR(addr) 		((addr) >> NAND_PAGE_SIZE_MAIN_BIT_EXP)
#define NAND_ADDR_TO_BYTE_ADDR(addr) 		((addr) & BIT_LEN_MASK_32(NAND_PAGE_SIZE_MAIN_BIT_EXP))

/* Exported functions --------------------------------------------------------*/

_LONG_CALL_ void MIPIDemoShow(void);

