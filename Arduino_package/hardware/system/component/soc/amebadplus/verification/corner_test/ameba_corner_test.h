#include "ameba_soc.h"

/* Exported constants --------------------------------------------------------*/

/* UART */
#define CORNER_UARTA_TXD	_PA_22
#define CORNER_UARTA_RXD	_PA_23
#define CORNER_UARTA_DEV	UART0_DEV

#define CORNER_UARTB_TXD	_PA_24
#define CORNER_UARTB_RXD	_PA_25
#define CORNER_UARTB_DEV	UART1_DEV

/* SPI */
#define CORNER_SPI_MST_MOSI	_PB_24
#define CORNER_SPI_MST_MISO	_PB_25
#define CORNER_SPI_MST_SCLK	_PB_23
#define CORNER_SPI_MST_CS	_PB_26
#define CORNER_SPI_MST_DEV	SPI0_DEV

#define CORNER_SPI_SLV_MOSI	_PB_7
#define CORNER_SPI_SLV_MISO	_PB_8
#define CORNER_SPI_SLV_SCLK	_PB_6
#define CORNER_SPI_SLV_CS	_PB_9
#define CORNER_SPI_SLV_DEV	SPI1_DEV

/* I2C */
#define CORNER_I2C0_SCL		_PB_0
#define CORNER_I2C0_SDA		_PB_1

#define CORNER_I2C1_SCL		_PB_2
#define CORNER_I2C1_SDA		_PB_3

/* USB */
#define USB_IN			_PA_30 // SWD_CLK
#define USB_OUT			_PB_22

/* ADC */
#define ADC_CHA_NUM		1
#define ADC_1V0			1000 // 1.0V
#define ADC_ERR			15 // 15mV
#define ADC_1V0_DIFF(x)	(((x) > ADC_1V0)? ((x)-ADC_1V0):(ADC_1V0-(x)))

/* CAPTOUCH */
#define CTC_CHA_NUM		1


/* Exported functions --------------------------------------------------------*/
void corner_I2CTest(void);
void corner_SPITest(void);
void corner_UARTTest(void);
void corner_GPIOTest(void);
void corner_USBTest(void);
void corner_ADCTest(void);
void corner_CTCTest(void);
void corner_PSRAMTest(void);
