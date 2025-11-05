#include "ameba_soc.h"

#include "ameba_ft_adc_dac_corner_test.h"

/** @brief Log Module Definition */
typedef enum {
	_EQC_GPIO		= 0,
	_EQC_I2C		, // 1
	_EQC_UART		, // 2
	_EQC_SPI		, // 3

	_EQC_FLASH		, // 4
	_EQC_PSRAM	, // 5

	_EQC_AUDIO		, // 6

	_EQC_ADC		, // 7

	_EQC_CAPTOUCH 	, // 8
	_EQC_WIFI		, // 9

	_EQC_BT 		, // 10

	_EQC_APCore		, // 11
	_EQC_TRNG		, // 12
	_EQC_MAX		,

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

#define EQC_DONE_FLAG_REG	0x4200D010
#define EQC_ERROR_FLAG_REG	BKUP_REG1

/*
 * @brief: ADC Test Items
 */
#define ADC_ROUTE_NUM	1

/*
 * UART TEST PIN
 */
#define EQC_UART1_TXD1	_PA_5
#define EQC_UART1_RXD1	_PA_4
#define EQC_UART2_TXD1	_PA_8
#define EQC_UART2_RXD1	_PA_7

/*
 * SPI TEST PIN
 */
#define EQC_SPI_MTR_MOSI	_PB_10
#define EQC_SPI_MTR_MISO	_PB_11
#define EQC_SPI_MTR_SCLK	_PB_12
#define EQC_SPI_MTR_CS		_PB_13
#define EQC_SPI_MTR_DEV		SPI1_DEV

#define EQC_SPI_SLV_MOSI	_PB_19
#define EQC_SPI_SLV_MISO	_PB_20
#define EQC_SPI_SLV_SCLK	_PB_18
#define EQC_SPI_SLV_CS		_PB_17
#define EQC_SPI_SLV_DEV		SPI0_DEV

/*
 * WLAN
 */
#define EQC_TEST_AP "RealKungFu-2.4G"
#define EQC_TEST_PASSWORD "RealTech"
#define EQC_TEST_SECURITY_TYPE	RTW_SECURITY_WPA2_AES_PSK
#define DEFAULT_PIN_CNT 4

#define WIFI_TEST_DONE_2G BIT0
/** @} */

//================functions=================
void eqc_getADCData(u32 *adcVal, u32 Num);
u32 eqc_getCapTouchData(u8 channel);
u32 eqc_i2c_pinmuxInit(uint8_t sda, uint8_t scl, u32 i2cIndex);
u32 eqc_i2cTRXPollingTest(u32 MasterIndex, u32 SlaveIndex);
void eqc_uart_pinmuxInit(void);
u32 eqc_uartLoopbackTest(void);
u32 eqc_SPILoopbackTest(void);
u32 eqc_gpioloopbackTest(u8 gpio_in, u8 gpio_out);

#ifdef CONFIG_WLAN
extern void do_ping_call(char *ip, int loop, int count);
extern int get_ping_report(int *ping_lost);
void eqc_WlanThread(void);
#endif


_LONG_CALL_ void example_audio_ft_test(void);

