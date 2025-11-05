#include "ameba_soc.h"
#include "ameba_olt_ft_adc_dac.h"

#define NORMAL_OLT_TEST

/** @brief Log Module Definition */
typedef enum {
	_OLT_GPIO		= 0,
	_OLT_I2C		, // 1
	_OLT_UART		, // 2
	_OLT_SPI		, // 3

	_OLT_PSRAM		, // 4
	_OLT_AUDIO		, // 5
	_OLT_ADC		, // 6
	_OLT_CAPTOUCH	, // 7

	_OLT_WIFI		, // 8
	_OLT_BT			, // 9
	_OLT_APCore		, // 10
	_OLT_LEDC		, // 11
	_OLT_OTP		, // 12
	_OLT_DSP		, // 13
	_OLT_USB		, // 14
	_OLT_USBLOOP	, // 15
	_OLT_THERMAL	, // 16
	_OLT_MIPI		, // 17
	_OLT_RSTCTRL	, // 18
	_OLT_MAX		, // 19

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

#define OLT_DONE_FLAG_REG	0x4200D010
#define OLT_ERROR_FLAG_REG	BKUP_REG1

/*
 * @brief: ADC Test Items
 */
#define ADC_ROUTE_NUM	1

/*
 * UART TEST PIN
 */

/* QFN144 */
#define OLT_UART2_TXD	_PA_8
#define OLT_UART2_RXD	_PA_7

/*
 * SPI TEST PIN
 */
#define OLT_SPI_MTR_MOSI	_PB_10
#define OLT_SPI_MTR_MISO	_PB_11
#define OLT_SPI_MTR_SCLK	_PB_12
#define OLT_SPI_MTR_CS		_PB_13
#define OLT_SPI_MTR_DEV		SPI1_DEV

#define OLT_SPI_SLV_MOSI	_PB_19
#define OLT_SPI_SLV_MISO	_PB_20
#define OLT_SPI_SLV_SCLK	_PB_18
#define OLT_SPI_SLV_CS		_PB_17
#define OLT_SPI_SLV_DEV		SPI0_DEV

/*
 * LEDC TEST PIN
 */
#define OLT_LEDC_OUT		_PA_12

typedef struct {
	void *TxData;
	u32 TxLength;
	u32 Index;
	u32 Result;
} LEDC_OBJ, *PLEDC_OBJ;

#define RESULT_COMPLETE	1
#define RESULT_ERR		2
#define RESULT_RUNNING	3

//================functions=================
void OLT_Calibration_patch(void);
void olt_getADCData(u16 *adcVal, u32 ch_idx);
void olt_CapTouchInit(void);
void olt_getCapTouchData(u16 *ctc_data);
u32 olt_i2c_pinmuxInit(uint8_t sda, uint8_t scl, u32 i2cIndex);
u32 olt_i2cTRXPollingTest(u32 MasterIndex, u32 SlaveIndex);
void olt_uart_pinmuxInit(void);
u32 olt_uartLoopbackTest(void);
void olt_SpiInit(void);
u32 olt_SPILoopbackTest(void);
u32 olt_gpioloopbackTest(u8 gpio_in, u8 gpio_out);
_LONG_CALL_ void example_audio_ft_test(void);

