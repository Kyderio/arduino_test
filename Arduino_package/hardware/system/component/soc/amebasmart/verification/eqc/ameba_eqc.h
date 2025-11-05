#include "ameba_soc.h"

#include "ameba_ft_adc_dac.h"

/** @brief Log Module Definition */
typedef enum {
	_EQC_GPIO		= 0,
	_EQC_I2C		, // 1
	_EQC_UART		, // 2
	_EQC_SPI		, // 3

	_EQC_FLASH		, // 4
	_EQC_PSRAM		, // 5
	_EQC_USB		, // 6
	_EQC_AUDIO		, // 7

	_EQC_ADC		, // 8
	_EQC_MIPI		, // 9
	_EQC_CAPTOUCH 	, // 10
	_EQC_WIFI		, // 11

	_EQC_BT 		, // 12
	_EQC_KM4		, // 13
	_EQC_APCore		, // 14
	_EQC_MAX		, // 15

	_EQC_IGNORE 	= 0xFF, //
} EQC_ITEMS_DEFINE;

typedef struct _EQC_CASE_TABLE_ {
	char *name;
	u32  Index;
	u32  CaseFlag;
	u32  ErrStatus;
	u32  DoneFlag;
	//u32(*func)(u16 argc, u8 *argv[]);
	//const   u8 *msg;
} EQC_CASE_TABLE, *PEQC_CASE_TABLE;

/*
 * @brief: ADC Test Items
 */
#define ADC_ROUTE_NUM	4

/*
 * SPI TEST PIN
 */
#define EQC_SPI_MTR_MOSI  _PB_10
#define EQC_SPI_MTR_MISO  _PB_11
#define EQC_SPI_MTR_SCLK  _PB_12
#define EQC_SPI_MTR_CS    _PB_13
#define EQC_SPI_MTR_DEV   SPI1_DEV

#define EQC_SPI_SLV_MOSI  _PB_19
#define EQC_SPI_SLV_MISO  _PB_20
#define EQC_SPI_SLV_SCLK  _PB_18
#define EQC_SPI_SLV_CS    _PB_17
#define EQC_SPI_SLV_DEV   SPI0_DEV

/*
 * USB
 */
#define USB_ID_INPUT_PIN	_PB_18


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

//================functions=================
void eqc_ADCInit(u32 ChanNum, u8 *ChanIdx);
void eqc_getADCData(u8 ADC_channel, u16 *ADC_data);
void eqc_CapTouchInit(u32 ChanNum, u8 *ChanIdx);
u32 eqc_i2c_pinmuxInit(uint8_t sda, uint8_t scl);
u32 eqc_i2cTRXPollingTest(u32 MasterIndex, u32 SlaveIndex);
u32 eqc_uart_pinmuxInit(u8 tx, u8 rx);
u32 eqc_uartLoopbackTest(u32 uartA, u32 uartB);
u32 eqc_SPILoopbackTest(void);
u32 eqc_gpioloopbackTest(u8 gpio_in, u8 gpio_out);
u32 eqc_usbloopbackTest(void);
bool eqc_mipi_lp_txrx_bist(void);
_LONG_CALL_ void example_audio_ft_test(void);
