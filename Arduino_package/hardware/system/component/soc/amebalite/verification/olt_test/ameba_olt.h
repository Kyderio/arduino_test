#include "ameba_soc.h"

#include "ameba_olt_ft_adc_dac.h"

/** @brief Log Module Definition */
typedef enum {
	_OLT_GPIO		= 0,
	_OLT_I2C		, // 1
	_OLT_UART		, // 2
	_OLT_PSRAM	, // 3

	_OLT_AUDIO		, // 4

	_OLT_ADC		, // 5

	_OLT_CAPTOUCH 	, // 6
	_OLT_WIFI		, // 7

	_OLT_BT 		, // 8

	_OLT_APCore		, // 9
	_OLT_LEDC		, // 10
	_OLT_MAX		, // 11

	_OLT_OTP		, // 12
	_OLT_DSP		, // 13
	_OLT_THERMAL		,//14
	_OLT_IGNORE 	= 0xFF, //
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

#define OLT_DONE_FLAG_REG	0x4200D010
#define OLT_ERROR_FLAG_REG	BKUP_REG1

/*
 * @brief: ADC Test Items
 */
#define ADC_ROUTE_NUM	1

/*
 * UART TEST PIN
 */
/* QFN48 */
#define OLT_UART0_TXD0	_PA_15
#define OLT_UART0_RXD0	_PA_16
#define OLT_UART1_TXD0	_PA_17
#define OLT_UART1_RXD0	_PA_18

/* QFN68 */
#define OLT_UART0_TXD1	_PA_23
#define OLT_UART0_RXD1	_PA_24
#define OLT_UART1_TXD1	_PA_25
#define OLT_UART1_RXD1	_PA_26

/*
 * SPI TEST PIN
 */
#define OLT_SPI_MTR_MOSI	_PB_3
#define OLT_SPI_MTR_MISO	_PB_4
#define OLT_SPI_MTR_SCLK	_PB_2
#define OLT_SPI_MTR_CS		_PB_5
#define OLT_SPI_MTR_DEV		SPI1_DEV

#define OLT_SPI_SLV_MOSI	_PA_29
#define OLT_SPI_SLV_MISO	_PA_30
#define OLT_SPI_SLV_SCLK	_PA_28
#define OLT_SPI_SLV_CS		_PA_31
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
s32 ADC_GetVolValue(u16 chan_data);
void olt_getADCData(u32 *adcVal, u32 Num);
void olt_CapTouchInit(u8 channel);
u32 olt_getCapTouchData(void);
u32 olt_i2c_pinmuxInit(uint8_t sda, uint8_t scl, u32 i2cIndex);
u32 olt_i2cTRXPollingTest(u32 MasterIndex, u32 SlaveIndex);
void olt_uart_pinmuxInit(void);
u32 olt_uartLoopbackTest(void);
u32 olt_SPILoopbackTest(void);
u32 olt_gpioloopbackTest(u8 gpio_in, u8 gpio_out);
_LONG_CALL_ void example_audio_ft_test(void);

