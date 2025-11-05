#include "ameba_soc.h"

/* Exported constants --------------------------------------------------------*/

/* UART */
#define CORNER_UARTA_TXD	_PB_8
#define CORNER_UARTA_RXD	_PB_9
#define CORNER_UARTA_DEV	UART0_DEV

#define CORNER_UARTB_TXD	_PB_10
#define CORNER_UARTB_RXD	_PB_11
#define CORNER_UARTB_DEV	UART1_DEV

/* SPI */
#define CORNER_SPI_MST_MOSI	_PB_0
#define CORNER_SPI_MST_MISO	_PA_29
#define CORNER_SPI_MST_SCLK	_PA_31
#define CORNER_SPI_MST_CS	_PA_30
#define CORNER_SPI_MST_DEV	SPI0_DEV

#define CORNER_SPI_SLV_MOSI	_PB_30
#define CORNER_SPI_SLV_MISO	_PB_31
#define CORNER_SPI_SLV_SCLK	_PB_29
#define CORNER_SPI_SLV_CS	_PC_0
#define CORNER_SPI_SLV_DEV	SPI1_DEV

/* I2C */
#define CORNER_I2C0_SCL		_PB_4
#define CORNER_I2C0_SDA		_PB_5

#define CORNER_I2C1_SCL		_PB_6
#define CORNER_I2C1_SDA		_PB_7

/* USB */
#define USB_IN			_PA_30 // SWD_CLK
#define USB_OUT			_PB_22

/* ADC */
#define ADC_CHA_NUM		1

/* wakeup pin */
#define WAKEUP_PIN		_PA_3


/* Exported functions --------------------------------------------------------*/
void corner_I2CTest(void *);
void corner_SPITest(void *);
void corner_UARTTest(void *);
void corner_USBTest(void *);
void corner_ADCTest(void *);
void corner_PSRAMTest(void *);
