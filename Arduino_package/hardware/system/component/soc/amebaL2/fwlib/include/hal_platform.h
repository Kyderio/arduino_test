/*
 * Copyright (c) 2024 Realtek Semiconductor Corp.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _HAL_PLATFORM_
#define _HAL_PLATFORM_

#define ROMVERSION			0x01
#define ROMVERSION_SUB		0 /* ACUT is v1.0, BCUT is v1.1 ... */

#define HAL_READ32(base, addr)				((u32)(*((volatile u32*)(base + addr))))
#define HAL_WRITE32(base, addr, value32)	((*((volatile u32*)(base + addr))) = ((u32)(value32)))
#define HAL_READ16(base, addr)				((u16)(*((volatile u16*)(base + addr))))
#define HAL_WRITE16(base, addr, value)		((*((volatile u16*)(base + addr))) = ((u16)(value)))
#define HAL_READ8(base, addr)				(*((volatile u8*)(base + addr)))
#define HAL_WRITE8(base, addr, value)		((*((volatile u8*)(base + addr))) = value)


#ifdef __cplusplus
#define __I		volatile             /*!< Defines 'read only' permissions                 */
#else
#define __I		volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define __O		volatile             /*!< Defines 'write only' permissions                */
#define __IO	 	volatile             /*!< Defines 'read / write' permissions              */

/**************************************************************************//**
 * @defgroup AmebaD_Outline
 * @{
 *****************************************************************************/

/** @addtogroup AmebaD_Outline
  * @verbatim
  *****************************************************************************************
  * CPU
  *****************************************************************************************
  *	-Clock speed:		125MHz
  *	-Core:				CM4F
  *	-Working votage:	3.3V
  *
  *****************************************************************************************
  * Memory
  *****************************************************************************************
  *	-ROM:				512KB
  *	-RAM:				256KB
  *	-FLash:				128MB
  *
  *****************************************************************************************
  * GPIO
  *****************************************************************************************
  *	-GPIOA:				0~31, IN/OUT/INT
  *	-GPIOB:				0~31, IN/OUT/INT
  *
  *****************************************************************************************
  * Flash
  *****************************************************************************************
  *	-Max. speed:		100MHz
  *	-SPI Mode:			Quad IO mode
  *	-cache:				32K I/D read cache
  *	-XIP:				support executed in place
  *
  *****************************************************************************************
  * Firmware Protection
  *****************************************************************************************
  *	-RSIP(OTF):(Realsil Image Protection)
  *		-Flash Encryption
  *		-key store in OTP EFUSE Area, and can not read
  *	-RDP
  *		-4K RAM read protection
  *		-key store in OTP EFUSE Area, and can not read
  *
  *****************************************************************************************
  * UART
  *****************************************************************************************
  *	-Set count:			2
  *	-IrDA:				support
  *	-Low Power:			support
  *	-Sleep wakeup:		support
  *	-Baud rate:			110~6000000
  *	-GDMA:				support
  *
  *****************************************************************************************
  * UART LOG
  *****************************************************************************************
  *	-Set count:			1
  *	-IrDA:				support
  *	-Low Power:			not support
  *	-Sleep wakeup:		not support
  *	-Baud rate:			110~6000000
  *
  *****************************************************************************************
  * SPI Master
  *****************************************************************************************
  *	-Set count:			1
  *	-Max. Speed:		31.25MHz
  *	-GDMA:				support
  *
  *****************************************************************************************
  * SPI Slave
  *****************************************************************************************
  *	-Set count:			1
  *	-Max. Speed:		31.25MHz
  *	-GDMA:				support
  *
  *****************************************************************************************
  * I2C
  *****************************************************************************************
  *	-Set count:			1
  *	-Speed:				Standard (up to 100 kHz) and Fast (up to 400 kHz) Modes
  *	-Role:				Master & Slave
  *	-Sleep wakeup:		support
  *	-GDMA:				support
  *
  *****************************************************************************************
  * RTC
  *****************************************************************************************
  *	-Set count:			1
  *	-H:					12/24 hour mode
  *	-M:					0~59
  *	-S:					0~59
  *	-D:					0~511
  *	-Alarm:				support D/H/M/S
  *	-Daylight:			support
  *	-Calibration:		support
  *
  *****************************************************************************************
  * PWM
  *****************************************************************************************
  *	-Channel count:		6(NP)/18(AP)
  *	-Max. Resolution:	16bits (customizable)
  *	-Max. Frequency:	40MHz@1-bit mode, 40/(2^x))MHz@x-bit
  *
  *****************************************************************************************
  * Capture
  *****************************************************************************************
  *	-Channel count:		1
  *	-Max. Resolution:	16bits (customizable)
  *	-Max. Frequency:	40MHz@1-bit mode, 40/(2^x))MHz@x-bit
  *	-capture width:		supoort
  *	-capture number:	support
  *
  *****************************************************************************************
  * Timer
  *****************************************************************************************
  *	-Set count:			12
  *	-32KHz timer:		8
  *	-40MHz timer:		4
  *
  *****************************************************************************************
  * I2S
  *****************************************************************************************
  *	-Set count:			1
  *	-Source clk:		45.1584MHz or 98.304MHz(default)
  *	-Sample rate:		8K, 12K, 16K, 24K, 32K, 48K, 64K, 96K, 192K, 384K, 7.35K, 11.025K, 14.7K, 22.05K, 29.4K, 44.1K, 58.8K, 88.2K, 176.4K
  *	-Sample bit:		16 bit, 24 bit
  *	-DMA:				support
  *
  *****************************************************************************************
  * WIFI
  *****************************************************************************************
  *	-Set count:			1
  *	-Mode:				B/G/N(2.4G)
  *	-BW:				20MHz/40MHz
  *	-Ant:				1T/1R
  *
  *****************************************************************************************
  * USB device
  *****************************************************************************************
  *	-Set count:			1
  *	-DMA:				support
  *
  *****************************************************************************************
  * SDIO device
  *****************************************************************************************
  *	-Set count:			1
  *	-GSPI:				support
  *	-DMA:				support
  *
  *****************************************************************************************
  * BACKUP REG
  *****************************************************************************************
  *	-Set count:			4 dwords
  *
  *****************************************************************************************
  * CRYPTO
  *****************************************************************************************
  *	-MD5
  *	-SHA1
  *	-SHA2
  *	-HMAC-MD5
  *	-HMAC-SHA1
  *	-HMAC-SHA2
  *
  *	-AES-CBC
  *	-AES-ECB
  *	-AES-CTR
  *	-AES-CFB
  *	-AES-OFB
  *	-AES-GCM
  *	-3DES-CBC
  *	-3DES-ECB
  *	-DES-CBC
  *	-DES-ECB
  *
  *****************************************************************************************
  * ADC
  *****************************************************************************************
  *	-Set count:			1
  *	-Channel:			4
  *	-Sample rate:		max frequency up to 1MHz per channel, configurable
  *	-Resolution:		12 bit
  *	-signal sampling:	CH1 & CH3: 0 ~ 3V, CH2: 0~5V
  *	-power save:		Support one shot mode
  *	-GDMA:				support
  *
  *****************************************************************************************
  * GDMA
  *****************************************************************************************
  *	-Set count:			2
  *	-Channel:			2*6
  *
  *****************************************************************************************
  * @endverbatim
  */

/* TBD AutoGen */
#define SPI_FLASH_BASE           0x08000000        /* ID:S0, Inter. Type:AXI4, Top Address:0xFFFFFFF, Size(KB):128M, Clk Domain:SPIC_CLK */

/**************************************************************************//**
 * @defgroup AmebaD2_Address_Map AmebaD2 HS/LP Address Map
 * @{
 *****************************************************************************/
/* AUTO_GEN_START */
#define SRAM_BASE                          0x20000000        /* ID:P2S0, Inter. Type:AXI4, Top Address:0x200FFFFF, Size(KB):1M, Clk Domain:SRAM_CLK */
#define SRAM0_BASE                         0x20000000        /* ID:P2S0, Inter. Type:AXI4, Top Address:0x200FFFFF, Size(KB):1M, Clk Domain:SRAM_CLK */
#define WIFI_REG_BASE                      0x40000000        /* ID:P1S0-0, Inter. Type:AHB, Top Address:0x4007FFFF, Size(KB):512K, Clk Domain:PERI_HCLK */
#define WIFI_RF_REG_BASE                   0x40003C00        /* ID:P1S0-0, Inter. Type:AHB, Top Address:0x4007FFFF, Size(KB):512K, Clk Domain:PERI_HCLK */
#define PKE_REG_BASE                       0x40080000        /* ID:P1S0-1, Inter. Type:APB4, Top Address:0x400BFFFF, Size(KB):256K, Clk Domain:PERI_HCLK */
#define AES_REG_BASE                       0x400C0000        /* ID:P1S0-2, Inter. Type:APB4, Top Address:0x400C0FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define SHA_REG_BASE                       0x400C1000        /* ID:P1S0-3, Inter. Type:APB4, Top Address:0x400C1FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define AES_SHA_DMA_REG_BASE               0x400C2000        /* ID:P1S0-4, Inter. Type:APB4, Top Address:0x400C2FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define AES_KEY_REG_BASE                   0x400C3000        /* ID:P1S0-5, Inter. Type:APB4, Top Address:0x400C3FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define SHA_KEY_REG_BASE                   0x400C4000        /* ID:P1S0-6, Inter. Type:APB4, Top Address:0x400C4FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define TRNG_REG_BASE                      0x400C8000        /* ID:P1S0-8, Inter. Type:APB4, Top Address:0x400C8FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define OTPC_REG_BASE                      0x40800000        /* ID:P1S1-0, Inter. Type:APB4, Top Address:0x40800FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define SYSTEM_NS_CTRL_BASE                0x40801000        /* ID:P1S1-1, Inter. Type:APB4, Top Address:0x40801FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define UART3_REG_BASE                     0x40802000        /* ID:P1S1-2, Inter. Type:APB4, Top Address:0x40802FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define IPC0_REG_BASE                      0x40803000        /* ID:P1S1-3, Inter. Type:APB4, Top Address:0x40803FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define IPC0_SEMA_BASE                     0x40803200        /* ID:P1S1-3, Inter. Type:APB4, Top Address:0x40803FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define DEBUGTIMER_REG_BASE                0x40804000        /* ID:P1S1-4, Inter. Type:APB4, Top Address:0x40804FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define PMC0_TIMER_REG_BASE                0x40805000        /* ID:P1S1-5, Inter. Type:APB4, Top Address:0x40805FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER4_REG_BASE                    0x40806000        /* ID:P1S1-6, Inter. Type:APB4, Top Address:0x40806FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER5_REG_BASE                    0x40806200        /* ID:P1S1-6, Inter. Type:APB4, Top Address:0x40806FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define SYSTEM_TZ_CTRL_BASE                0x41000000        /* ID:P0S0-0, Inter. Type:APB4, Top Address:0x41001FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define UART0_REG_BASE                     0x41002000        /* ID:P0S0-1, Inter. Type:APB4, Top Address:0x41002FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define UART1_REG_BASE                     0x41003000        /* ID:P0S0-2, Inter. Type:APB4, Top Address:0x41003FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define UART2_REG_BASE                     0x41004000        /* ID:P0S0-3, Inter. Type:APB4, Top Address:0x41004FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define UARTLOG_REG_BASE                   0x41005000        /* ID:P0S0-4, Inter. Type:APB4, Top Address:0x41005FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define IPC1_REG_BASE                      0x41006000        /* ID:P0S0-5, Inter. Type:APB4, Top Address:0x41006FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define IPC1_SEMA_BASE                     0x41006200        /* ID:P0S0-5, Inter. Type:APB4, Top Address:0x41006FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define PMC1_TIMER_REG_BASE                0x41007000        /* ID:P0S0-6, Inter. Type:APB4, Top Address:0x41007FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER0_REG_BASE                    0x41008000        /* ID:P0S0-7, Inter. Type:APB4, Top Address:0x41008FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER1_REG_BASE                    0x41008200        /* ID:P0S0-7, Inter. Type:APB4, Top Address:0x41008FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER2_REG_BASE                    0x41008400        /* ID:P0S0-7, Inter. Type:APB4, Top Address:0x41008FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER3_REG_BASE                    0x41008600        /* ID:P0S0-7, Inter. Type:APB4, Top Address:0x41008FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define GPIO_REG_BASE                      0x41009000        /* ID:P0S0-8, Inter. Type:APB4, Top Address:0x41009FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define ADC_REG_BASE                       0x4100A000        /* ID:P0S0-9, Inter. Type:APB4, Top Address:0x4100AFFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define CMP_REG_BASE                       0x4100A800        /* ID:P0S0-9, Inter. Type:APB4, Top Address:0x4100AFFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define CTC_REG_BASE                       0x4100B000        /* ID:P0S0-10, Inter. Type:APB4, Top Address:0x4100BFFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define RMII_REG_BASE                      0x41800000        /* ID:P0S1-0, Inter. Type:AXI4, Top Address:0x41801FFF, Size(KB):8K, Clk Domain:PERI_HCLK */
#define GDMA0_REG_BASE                     0x41802000        /* ID:P0S1-1, Inter. Type:APB4, Top Address:0x41802FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define CAN0_REG_BASE                      0x41803000        /* ID:P0S1-2, Inter. Type:APB4, Top Address:0x41803FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define CAN1_REG_BASE                      0x41804000        /* ID:P0S1-3, Inter. Type:APB4, Top Address:0x41804FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define DVP_REG_BASE                       0x41805000        /* ID:P0S1-4, Inter. Type:APB4, Top Address:0x41805FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define USB_REG_BASE                       0x41840000        /* ID:P0S1-5, Inter. Type:AHB, Top Address:0x4187FFFF, Size(KB):256K, Clk Domain:PERI_HCLK */
#define UVC_REG_BASE                       0x41871000        /* ID:P0S1-5, Inter. Type:AHB, Top Address:0x4187FFFF, Size(KB):256K, Clk Domain:PERI_HCLK */
#define SDIO_CCCR_REG_BASE                 0x41880000        /* ID:P0S1-6, Inter. Type:AHB, Top Address:0x41883FFF, Size(KB):16K, Clk Domain:PERI_HCLK */
#define SDIO_WIFI_REG_BASE                 0x41881000        /* ID:P0S1-6, Inter. Type:AHB, Top Address:0x41883FFF, Size(KB):16K, Clk Domain:PERI_HCLK */
#define SDIO_BT_REG_BASE                   0x41882000        /* ID:P0S1-6, Inter. Type:AHB, Top Address:0x41883FFF, Size(KB):16K, Clk Domain:PERI_HCLK */
#define SDIO_LOCAL_REG_BASE                0x41883000        /* ID:P0S1-6, Inter. Type:AHB, Top Address:0x41883FFF, Size(KB):16K, Clk Domain:PERI_HCLK */
#define SPORT_REG_BASE                     0x41884000        /* ID:P0S1-7, Inter. Type:AHB, Top Address:0x41884FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define SPI0_REG_BASE                      0x41885000        /* ID:P0S1-8, Inter. Type:APB4, Top Address:0x41885FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define SPI1_REG_BASE                      0x41886000        /* ID:P0S1-9, Inter. Type:APB4, Top Address:0x41886FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define LCDC_REG_BASE                      0x41888000        /* ID:P0S1-10, Inter. Type:APB4, Top Address:0x4188FFFF, Size(KB):32K, Clk Domain:PERI_HCLK */
#define I3C_REG_BASE                       0x41890000        /* ID:P0S1-11, Inter. Type:APB4, Top Address:0x41890FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define RXI300_REG_BASE                    0x41892000        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_S_ELR_REG_BASE              0x41892100        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_S_DIR_REG_BASE              0x41892200        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_NS_GPR_REG_BASE             0x41893000        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_NS_ELR_REG_BASE             0x41893100        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_NS_DIR_REG_BASE             0x41893200        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_NS_TMO_REG_BASE             0x41893300        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RSIP_REG_BASE                      0x41894000        /* ID:P0S1-13, Inter. Type:APB4, Top Address:0x41894FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER6_REG_BASE                    0x41895000        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER7_REG_BASE                    0x41895200        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER8_REG_BASE                    0x41895400        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER9_REG_BASE                    0x41895600        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER10_REG_BASE                   0x41895800        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define UPS_REG_BASE                       0x41895A00        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define I2C0_REG_BASE                      0x41896000        /* ID:P0S1-15, Inter. Type:APB4, Top Address:0x41896FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define I2C1_REG_BASE                      0x41897000        /* ID:P0S1-16, Inter. Type:APB4, Top Address:0x41897FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define MJPEG_REG_BASE                     0x418C0000        /* ID:P0S1-17, Inter. Type:APB4, Top Address:0x418FFFFF, Size(KB):256K, Clk Domain:PERI_SHCLK */
#define PPE_REG_BASE                       0x41900000        /* ID:P0S1-18, Inter. Type:APB4, Top Address:0x41907FFF, Size(KB):32K, Clk Domain:PERI_SHCLK */
#define PSRAM_PHY_REG_BASE                 0x41908000        /* ID:P0S1-19, Inter. Type:APB4, Top Address:0x41908FFF, Size(KB):4K, Clk Domain:PSRAM_CLK */
#define PSRAM_REG_BASE                     0x41909000        /* ID:P0S1-20, Inter. Type:AXI4, Top Address:0x41909FFF, Size(KB):4K, Clk Domain:PSRAM_CLK */
#define QSPI_REG_BASE                      0x4190A000        /* ID:P0S1-21, Inter. Type:AXI4, Top Address:0x4190AFFF, Size(KB):4K, Clk Domain:VO_CLK */
#define SPI_FLASH_CTRL_BASE                0x4190B000        /* ID:P0S1-22, Inter. Type:AXI4, Top Address:0x4190BFFF, Size(KB):4K, Clk Domain:SPIC_CLK */
#define PSRAM_BASE                         0x60000000        /* ID:P4S0, Inter. Type:AXI4, Top Address:0x6FFFFFFF, Size(KB):256M, Clk Domain:PSRAM_CLK */
#define AON_BACKUP_REG_BASE                0x410000E0
#define LDO_REG_BASE                       0x41000100
#define SWR_REG_BASE                       0x41000180
#define PMC_BASE                           0x41000300
#define PLL_REG_BASE                       0x41000500
#define SYSTEM_MEM_CTRL_BASE               0x41000600
#define PINMUX_REG_BASE                    0x41000800
#define RTC_REG_BASE                       0x41000A00
#define IWDG_REG_BASE                      0x41000C00
#define WDG1_REG_BASE_S                    0x51000D40
#define WDG2_REG_BASE                      0x41000D80
#define RETENTION_RAM_BASE                 0x41000E00
#define SDM_REG_BASE                       0x41001000
#define LEDC0_REG_BASE                     0x41001200
#define LEDC1_REG_BASE                     0x41001300
#define XTAL_REG_BASE                      0x40801400
#define WLAFE_REG_BASE                     0x40801480
#define WDG0_REG_BASE                      0x40801D00

#define SRAM0_BASE_S                       0x30000000        /* ID:P2S0, Inter. Type:AXI4, Top Address:0x200FFFFF, Size(KB):1M, Clk Domain:SRAM_CLK */
#define WIFI_REG_BASE_S                    0x50000000        /* ID:P1S0-0, Inter. Type:AHB, Top Address:0x4007FFFF, Size(KB):512K, Clk Domain:PERI_HCLK */
#define WIFI_RF_REG_BASE_S                 0x50003C00        /* ID:P1S0-0, Inter. Type:AHB, Top Address:0x4007FFFF, Size(KB):512K, Clk Domain:PERI_HCLK */
#define PKE_REG_BASE_S                     0x50080000        /* ID:P1S0-1, Inter. Type:APB4, Top Address:0x400BFFFF, Size(KB):256K, Clk Domain:PERI_HCLK */
#define AES_REG_BASE_S                     0x500C0000        /* ID:P1S0-2, Inter. Type:APB4, Top Address:0x400C0FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define SHA_REG_BASE_S                     0x500C1000        /* ID:P1S0-3, Inter. Type:APB4, Top Address:0x400C1FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define AES_SHA_DMA_REG_BASE_S             0x500C2000        /* ID:P1S0-4, Inter. Type:APB4, Top Address:0x400C2FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define AES_KEY_REG_BASE_S                 0x500C3000        /* ID:P1S0-5, Inter. Type:APB4, Top Address:0x400C3FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define SHA_KEY_REG_BASE_S                 0x500C4000        /* ID:P1S0-6, Inter. Type:APB4, Top Address:0x400C4FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define TRNG_REG_BASE_S                    0x500C8000        /* ID:P1S0-8, Inter. Type:APB4, Top Address:0x400C8FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define OTPC_REG_BASE_S                    0x50800000        /* ID:P1S1-0, Inter. Type:APB4, Top Address:0x40800FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define SYSTEM_NS_CTRL_BASE_S              0x50801000        /* ID:P1S1-1, Inter. Type:APB4, Top Address:0x40801FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define UART3_REG_BASE_S                   0x50802000        /* ID:P1S1-2, Inter. Type:APB4, Top Address:0x40802FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define IPC0_REG_BASE_S                    0x50803000        /* ID:P1S1-3, Inter. Type:APB4, Top Address:0x40803FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define IPC0_SEMA_BASE_S                   0x50803200        /* ID:P1S1-3, Inter. Type:APB4, Top Address:0x40803FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define DEBUGTIMER_REG_BASE_S              0x50804000        /* ID:P1S1-4, Inter. Type:APB4, Top Address:0x40804FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define PMC0_TIMER_REG_BASE_S              0x50805000        /* ID:P1S1-5, Inter. Type:APB4, Top Address:0x40805FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER4_REG_BASE_S                  0x50806000        /* ID:P1S1-6, Inter. Type:APB4, Top Address:0x40806FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER5_REG_BASE_S                  0x50806200        /* ID:P1S1-6, Inter. Type:APB4, Top Address:0x40806FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define SYSTEM_TZ_CTRL_BASE_S              0x51000000        /* ID:P0S0-0, Inter. Type:APB4, Top Address:0x41001FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define UART0_REG_BASE_S                   0x51002000        /* ID:P0S0-1, Inter. Type:APB4, Top Address:0x41002FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define UART1_REG_BASE_S                   0x51003000        /* ID:P0S0-2, Inter. Type:APB4, Top Address:0x41003FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define UART2_REG_BASE_S                   0x51004000        /* ID:P0S0-3, Inter. Type:APB4, Top Address:0x41004FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define UARTLOG_REG_BASE_S                 0x51005000        /* ID:P0S0-4, Inter. Type:APB4, Top Address:0x41005FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define IPC1_REG_BASE_S                    0x51006000        /* ID:P0S0-5, Inter. Type:APB4, Top Address:0x41006FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define IPC1_SEMA_BASE_S                   0x51006200        /* ID:P0S0-5, Inter. Type:APB4, Top Address:0x41006FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define PMC1_TIMER_REG_BASE_S              0x51007000        /* ID:P0S0-6, Inter. Type:APB4, Top Address:0x41007FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER0_REG_BASE_S                  0x51008000        /* ID:P0S0-7, Inter. Type:APB4, Top Address:0x41008FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER1_REG_BASE_S                  0x51008200        /* ID:P0S0-7, Inter. Type:APB4, Top Address:0x41008FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER2_REG_BASE_S                  0x51008400        /* ID:P0S0-7, Inter. Type:APB4, Top Address:0x41008FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER3_REG_BASE_S                  0x51008600        /* ID:P0S0-7, Inter. Type:APB4, Top Address:0x41008FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define GPIO_REG_BASE_S                    0x51009000        /* ID:P0S0-8, Inter. Type:APB4, Top Address:0x41009FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define ADC_REG_BASE_S                     0x5100A000        /* ID:P0S0-9, Inter. Type:APB4, Top Address:0x4100AFFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define CMP_REG_BASE_S                     0x5100A800        /* ID:P0S0-9, Inter. Type:APB4, Top Address:0x4100AFFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define CTC_REG_BASE_S                     0x5100B000        /* ID:P0S0-10, Inter. Type:APB4, Top Address:0x4100BFFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define RMII_REG_BASE_S                    0x51800000        /* ID:P0S1-0, Inter. Type:AXI4, Top Address:0x41801FFF, Size(KB):8K, Clk Domain:PERI_HCLK */
#define GDMA0_REG_BASE_S                   0x51802000        /* ID:P0S1-1, Inter. Type:APB4, Top Address:0x41802FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define CAN0_REG_BASE_S                    0x51803000        /* ID:P0S1-2, Inter. Type:APB4, Top Address:0x41803FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define CAN1_REG_BASE_S                    0x51804000        /* ID:P0S1-3, Inter. Type:APB4, Top Address:0x41804FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define DVP_REG_BASE_S                     0x51805000        /* ID:P0S1-4, Inter. Type:APB4, Top Address:0x41805FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define USB_REG_BASE_S                     0x51840000        /* ID:P0S1-5, Inter. Type:AHB, Top Address:0x4187FFFF, Size(KB):256K, Clk Domain:PERI_HCLK */
#define UVC_REG_BASE_S                     0x51871000        /* ID:P0S1-5, Inter. Type:AHB, Top Address:0x4187FFFF, Size(KB):256K, Clk Domain:PERI_HCLK */
#define SDIO_CCCR_REG_BASE_S               0x51880000        /* ID:P0S1-6, Inter. Type:AHB, Top Address:0x41883FFF, Size(KB):16K, Clk Domain:PERI_HCLK */
#define SDIO_WIFI_REG_BASE_S               0x51881000        /* ID:P0S1-6, Inter. Type:AHB, Top Address:0x41883FFF, Size(KB):16K, Clk Domain:PERI_HCLK */
#define SDIO_BT_REG_BASE_S                 0x51882000        /* ID:P0S1-6, Inter. Type:AHB, Top Address:0x41883FFF, Size(KB):16K, Clk Domain:PERI_HCLK */
#define SDIO_LOCAL_REG_BASE_S              0x51883000        /* ID:P0S1-6, Inter. Type:AHB, Top Address:0x41883FFF, Size(KB):16K, Clk Domain:PERI_HCLK */
#define SPORT_REG_BASE_S                   0x51884000        /* ID:P0S1-7, Inter. Type:AHB, Top Address:0x41884FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define SPI0_REG_BASE_S                    0x51885000        /* ID:P0S1-8, Inter. Type:APB4, Top Address:0x41885FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define SPI1_REG_BASE_S                    0x51886000        /* ID:P0S1-9, Inter. Type:APB4, Top Address:0x41886FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define LCDC_REG_BASE_S                    0x51888000        /* ID:P0S1-10, Inter. Type:APB4, Top Address:0x4188FFFF, Size(KB):32K, Clk Domain:PERI_HCLK */
#define I3C_REG_BASE_S                     0x51890000        /* ID:P0S1-11, Inter. Type:APB4, Top Address:0x41890FFF, Size(KB):4K, Clk Domain:PERI_HCLK */
#define RXI300_REG_BASE_S                  0x51892000        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define PPC_BASE_S                         0x51892000        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_S_ELR_REG_BASE_S            0x51892100        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_S_DIR_REG_BASE_S            0x51892200        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define MPC1_BASE_S                        0x51892400        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define MPC2_BASE_S                        0x51892500        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define MPC3_BASE_S                        0x51892600        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_NS_GPR_REG_BASE_S           0x51893000        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_NS_ELR_REG_BASE_S           0x51893100        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_NS_DIR_REG_BASE_S           0x51893200        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RXI300_NS_TMO_REG_BASE_S           0x51893300        /* ID:P0S1-12, Inter. Type:APB4, Top Address:0x41893FFF, Size(KB):8K, Clk Domain:PERI_LCLK */
#define RSIP_REG_BASE_S                    0x51894000        /* ID:P0S1-13, Inter. Type:APB4, Top Address:0x41894FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER6_REG_BASE_S                  0x51895000        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER7_REG_BASE_S                  0x51895200        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER8_REG_BASE_S                  0x51895400        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER9_REG_BASE_S                  0x51895600        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define TIMER10_REG_BASE_S                 0x51895800        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define UPS_REG_BASE_S                     0x51895A00        /* ID:P0S1-14, Inter. Type:APB4, Top Address:0x41895FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define I2C0_REG_BASE_S                    0x51896000        /* ID:P0S1-15, Inter. Type:APB4, Top Address:0x41896FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define I2C1_REG_BASE_S                    0x51897000        /* ID:P0S1-16, Inter. Type:APB4, Top Address:0x41897FFF, Size(KB):4K, Clk Domain:PERI_LCLK */
#define MJPEG_REG_BASE_S                   0x518C0000        /* ID:P0S1-17, Inter. Type:APB4, Top Address:0x418FFFFF, Size(KB):256K, Clk Domain:PERI_SHCLK */
#define PPE_REG_BASE_S                     0x51900000        /* ID:P0S1-18, Inter. Type:APB4, Top Address:0x41907FFF, Size(KB):32K, Clk Domain:PERI_SHCLK */
#define PSRAM_PHY_REG_BASE_S               0x51908000        /* ID:P0S1-19, Inter. Type:APB4, Top Address:0x41908FFF, Size(KB):4K, Clk Domain:PSRAM_CLK */
#define PSRAM_REG_BASE_S                   0x51909000        /* ID:P0S1-20, Inter. Type:AXI4, Top Address:0x41909FFF, Size(KB):4K, Clk Domain:PSRAM_CLK */
#define QSPI_REG_BASE_S                    0x5190A000        /* ID:P0S1-21, Inter. Type:AXI4, Top Address:0x4190AFFF, Size(KB):4K, Clk Domain:VO_CLK */
#define SPI_FLASH_CTRL_BASE_S              0x5190B000        /* ID:P0S1-22, Inter. Type:AXI4, Top Address:0x4190BFFF, Size(KB):4K, Clk Domain:SPIC_CLK */
#define PSRAM_BASE_S                       0x70000000        /* ID:P4S0, Inter. Type:AXI4, Top Address:0x6FFFFFFF, Size(KB):256M, Clk Domain:PSRAM_CLK */
/* AUTO_GEN_END */
/** @} End of group AmebaD_Address_Map */
#define DATA_FLASH_BASE                    0x60000000

#define TZ_IDAU_SEC_OFFSET                 0x10000000
#define KBYTES(x)                          ((x) << 10)
#define MBYTES(x)                          ((x) << 20)


/**************************************************************************//**
 * @defgroup AmebaD_Peripheral_Declaration  AmebaD HS/LP Peripheral Declarations
 * @{
 *****************************************************************************/
#define RRAM_DEV			((RRAM_TypeDef			*) RETENTION_RAM_BASE)		/*retention mem */

#define UART0_DEV			((UART_TypeDef			*) UART0_REG_BASE)		/*hp uart0 */
#define UART1_DEV			((UART_TypeDef			*) UART1_REG_BASE)		/*hp uart1 */
#define UART2_DEV			((UART_TypeDef			*) UART2_REG_BASE)		/*hp uart2 */
#define UART3_DEV			((UART_TypeDef			*) UART3_REG_BASE)		/*hp uart3 */
#define UART0_DEV_S			((UART_TypeDef			*) UART0_REG_BASE_S)		/*hp uart0 secure */
#define UART1_DEV_S			((UART_TypeDef			*) UART1_REG_BASE_S)		/*hp uart1 secure*/
#define UART2_DEV_S			((UART_TypeDef			*) UART2_REG_BASE_S)		/*hp uart2 secrue*/
#define UART3_DEV_S			((UART_TypeDef			*) UART3_REG_BASE_S)		/*hp uart3 secrue*/

#define LOGUART_DEV			((LOGUART_TypeDef		*) UARTLOG_REG_BASE)
#define LOGUART_DEV_S		((LOGUART_TypeDef		*) UARTLOG_REG_BASE_S)


#define SPI0_DEV			((SPI_TypeDef			*) SPI0_REG_BASE)		/*hp spi0 */
#define SPI1_DEV			((SPI_TypeDef			*) SPI1_REG_BASE)		/*hp spi1 */
#define SPI0_DEV_S			((SPI_TypeDef			*) SPI0_REG_BASE_S)		/*hp spi0 secure */
#define SPI1_DEV_S			((SPI_TypeDef			*) SPI1_REG_BASE_S)		/*hp spi1 secure */

#define PSRAMC_DEV			((SPIC_TypeDef			*) PSRAM_REG_BASE)				/*AP */
#define PSRAMPHY_DEV		((PSPHY_TypeDef			*) PSRAM_PHY_REG_BASE)				/*AP */

#define LCDC				((LCDC_TypeDef			*) LCDC_REG_BASE)
#define SPIC				((SPIC_TypeDef			*) SPI_FLASH_CTRL_BASE)
#define SPIC_COMBO			((SPIC_TypeDef			*) PSRAM_REG_BASE)
#define QSPI				((SPIC_TypeDef			*) QSPI_REG_BASE)
#define DVP					((DVP_TypeDef			*) DVP_REG_BASE)
#define ADC					((ADC_TypeDef			*) ADC_REG_BASE)
#define ADC_S				((ADC_TypeDef			*) ADC_REG_BASE_S)
#define CAPTOUCH_DEV		((CAPTOUCH_TypeDef		*) CTC_REG_BASE)
#define CAPTOUCH_DEV_S		((CAPTOUCH_TypeDef		*) CTC_REG_BASE_S)
#define I2C0_DEV			((I2C_TypeDef			*) I2C0_REG_BASE)		/*lp i2c0 */
#define I2C1_DEV			((I2C_TypeDef			*) I2C1_REG_BASE)		/*hp i2c1 */
#define I2C1_DEV_S			((I2C_TypeDef			*) I2C1_REG_BASE_S)		/*hp i2c1 secure */
#define TIM0				((RTIM_TypeDef			*) TIMER0_REG_BASE)
#define TIM1				((RTIM_TypeDef			*) TIMER1_REG_BASE)
#define TIM2				((RTIM_TypeDef			*) TIMER2_REG_BASE)
#define TIM3				((RTIM_TypeDef			*) TIMER3_REG_BASE)
#define TIM4				((RTIM_TypeDef			*) TIMER4_REG_BASE)
#define TIM5				((RTIM_TypeDef			*) TIMER5_REG_BASE)
#define TIM6				((RTIM_TypeDef			*) TIMER6_REG_BASE)
#define TIM7				((RTIM_TypeDef			*) TIMER7_REG_BASE)
#define TIM8				((RTIM_TypeDef			*) TIMER8_REG_BASE)
#define TIM9				((RTIM_TypeDef			*) TIMER9_REG_BASE)
#define TIM10				((RTIM_TypeDef			*) TIMER10_REG_BASE)

#define TIM0_S				((RTIM_TypeDef			*) TIMER0_REG_BASE_S)
#define TIM1_S				((RTIM_TypeDef			*) TIMER1_REG_BASE_S)
#define TIM2_S				((RTIM_TypeDef			*) TIMER2_REG_BASE_S)
#define TIM3_S				((RTIM_TypeDef			*) TIMER3_REG_BASE_S)
#define TIM4_S				((RTIM_TypeDef			*) TIMER4_REG_BASE_S)
#define TIM5_S				((RTIM_TypeDef			*) TIMER5_REG_BASE_S)
#define TIM6_S				((RTIM_TypeDef			*) TIMER6_REG_BASE_S)
#define TIM7_S				((RTIM_TypeDef 			*) TIMER7_REG_BASE_S)
#define TIM8_S				((RTIM_TypeDef			*) TIMER8_REG_BASE_S)
#define TIM9_S				((RTIM_TypeDef 			*) TIMER9_REG_BASE_S)
#define TIM10_S				((RTIM_TypeDef			*) TIMER10_REG_BASE_S)

#define PMCTIMER_DEV0		((PMCTIMER_TpyeDef		*) PMC0_TIMER_REG_BASE)
#define PMCTIMER_DEV1		((PMCTIMER_TpyeDef		*) PMC1_TIMER_REG_BASE)
#define PMCTIMER_DEV0_S		((PMCTIMER_TpyeDef		*) PMC0_TIMER_REG_BASE_S)
#define PMCTIMER_DEV1_S		((PMCTIMER_TpyeDef		*) PMC1_TIMER_REG_BASE_S)

#define IR_DEV				((IR_TypeDef			*) IR_REG_BASE)
#define IR_DEV_S			((IR_TypeDef			*) IR_REG_BASE_S)

#define RTC_DEV				((RTC_TypeDef			*) RTC_REG_BASE)					/*NP */
#define RTC_DEV_S			((RTC_TypeDef			*) (RTC_REG_BASE + TZ_IDAU_SEC_OFFSET))
#define PINMUX				((PINMUX_TypeDef		*) PINMUX_REG_BASE)			/*NP */
#define PINMUX_S			((PINMUX_TypeDef		*) (PINMUX_REG_BASE + TZ_IDAU_SEC_OFFSET))			/*NP */
#define GPIOA_BASE			((GPIO_TypeDef			*) GPIO_REG_BASE)			/*NP */
#define GPIOB_BASE			((GPIO_TypeDef			*) (GPIO_REG_BASE + 0x400))	/*NP */
#define GPIOC_BASE			((GPIO_TypeDef			*) (GPIO_REG_BASE + 0x800))	/*NP */
#define GPIOA_BASE_S		((GPIO_TypeDef			*) GPIO_REG_BASE_S)
#define GPIOB_BASE_S		((GPIO_TypeDef			*) (GPIO_REG_BASE_S + 0x400))
#define GPIOC_BASE_S		((GPIO_TypeDef			*) (GPIO_REG_BASE_S + 0x800))
#define BACKUP_REG			((BACKUP_REG_TypeDef	*) AON_BACKUP_REG_BASE)			/*AON */

#define AP_MPC1			((MPC_TypeDef			*) MPC1_BASE_S)			/*AP */
#define AP_MPC2			((MPC_TypeDef			*) MPC2_BASE_S)			/*AP */
#define AP_MPC3			((MPC_TypeDef			*) MPC3_BASE_S)			/*AP */

#define AP_PPC				((PPC_TypeDef			*) PPC_BASE_S)			/*AP */

#define IPCNP_DEV 			((IPC_TypeDef 			*) IPC0_REG_BASE)				/*NP */
#define IPCAP_DEV 			((IPC_TypeDef 			*) IPC1_REG_BASE)				/*AP */
#define IPCAP_DEV_S 		((IPC_TypeDef 			*) IPC0_REG_BASE_S)				/*NP Secure */
#define IPCNP_DEV_S 		((IPC_TypeDef 			*) IPC1_REG_BASE_S)				/*AP Secure*/

#define TM_DEV				((THERMAL_TypeDef		*) THERMAL_REG_BASE)
#define TM_DEV_S			((THERMAL_TypeDef		*) THERMAL_REG_BASE_S)

#define GDMA_BASE			((GDMA_TypeDef			*) (GDMA0_REG_BASE))

#define IWDG_DEV			((WDG_TypeDef			*) (IWDG_REG_BASE))
#define CPU1_WDG_DEV		((WDG_TypeDef			*) (WDG0_REG_BASE))
#define CPU0_S_WDG_DEV		((WDG_TypeDef			*) (WDG1_REG_BASE_S))
#define CPU0_NS_WDG_DEV		((WDG_TypeDef			*) (WDG2_REG_BASE))
#define SDM_DEV				((SDM_TypeDef			*) (SDM_REG_BASE))
#define SDM_DEV_S			((SDM_TypeDef			*) (SDM_REG_BASE_S))
#define OTPC_DEV			((OTPC_TypeDef			*) (OTPC_REG_BASE))
#define OTPC_DEV_S			((OTPC_TypeDef			*) (OTPC_REG_BASE_S))
#define DTIMER_DEV			((DEBUGTIMER_TypeDef	*) (DEBUGTIMER_REG_BASE))
#define DTIMER_DEV_S		((DEBUGTIMER_TypeDef	*) (DEBUGTIMER_REG_BASE_S))
#define TRNG_DEV			((TRNG_TypeDef			*) (TRNG_REG_BASE))
#define TRNG_SDEV			((TRNG_TypeDef			*) (TRNG_REG_BASE_S))

#define RSIP_BASE			((RSIP_REG_TypeDef		*) (RSIP_REG_BASE))

#ifndef AMEBAL2_TODO
#define AUDIO_SPORT_DEV	((AUDIO_SPORT_TypeDef	*) SPORT_REG_BASE)
#define AUDIO_SPORT_DEV_S	((AUDIO_SPORT_TypeDef	*) SPORT_REG_BASE_S)	/*SPORT0 secure */
#endif

#define SDIO_HOST			((SDIOHOST_TypeDef		*) SDIO_HOST_CCCR_REG_BASE)
#define SDIO_WIFI			((SDIO_TypeDef			*) SDIO_WIFI_REG_BASE)
#define SDIO_BT				((SDIO_TypeDef			*) SDIO_BT_REG_BASE)

#define UVC					((UVC_TypeDef			*) UVC_REG_BASE)
#define PPE					((PPE_TypeDef			*) PPE_REG_BASE)
#define MJPEG					((MJPEG_TypeDef			*) MJPEG_REG_BASE)

#define RCAN0					((RCAN_TypeDef			*) CAN0_REG_BASE)
#define RCAN1					((RCAN_TypeDef			*) CAN1_REG_BASE)
#define RCAN0_S				((RCAN_TypeDef			*) CAN0_REG_BASE_S)
#define RCAN1_S				((RCAN_TypeDef			*) CAN1_REG_BASE_S)

/* syson related ip*/
#define LDO_BASE      ((LDO_TypeDef *)  (LDO_REG_BASE))
#define REGU_BASE     ((REGU_TypeDef *)  (LDO_REG_BASE))
#define PLL_BASE      ((PLL_TypeDef *)  (PLL_REG_BASE))
#define SWR_BASE      ((SWR_TypeDef *)  (SWR_REG_BASE))
#define WLAFE_BASE    ((WLAFE_TypeDef *) (WLAFE_REG_BASE))
#define XTAL_BASE     ((XTAL_TypeDef *) (XTAL_REG_BASE))
#define OSC131K_BASE      ((RTC_MISC_TypeDef *)  (RTC_MISC_REG_BASE))
#define PSEUDO_I2C0_DEV      ((LEDC_PRO_TypeDef *)  (LEDC0_REG_BASE))
#define PSEUDO_I2C1_DEV      ((LEDC_PRO_TypeDef *)  (LEDC1_REG_BASE))

#define RXI_300				((RXI300_TypeDef			*) RXI300_REG_BASE)
#define RXI_300_S				((RXI300_TypeDef			*) RXI300_REG_BASE_S)

/** @} End of group AmebaD_Peripheral_Declaration */
#define MSP_RAM_LP					0x20003000						/* rom used, can not change, RISC-V kept 16-byte aligned */
#define MSPLIM_RAM_HP				N_BYTE_ALIGMENT((u32)__rom_bss_end_s__, 8U)						/* rom used, can not change */
#define MSP_RAM_HP					0x30001000						/* rom used, can not change */
#define MSPLIM_RAM_HP_NS		0x20001600
#define MSP_RAM_HP_NS				0x20002200

#define BOOT_LOADER_START			0x30003000						/* rom used, can not change */
#define BOOT_LOADER_LIMIT			0x30080000						/* rom used, can not change */
#define LOADER_DOWNLOAD_ADDR		(BOOT_LOADER_LIMIT - 64 * 1024)	/* rom used, can not change */

#define FULLMAC_ADDR_START			0x30001600						/* rom used, can not change */
#define FULLMAC_ADDR_END			0x30080000						/* rom used, can not change */

/*BT share mem with system*/
#define SHARE_MEM_BT_E0_ADDRESS		0x20080000
#define SHARE_MEM_BT_E0_LEN			(96 * 1024)	/* size: 96KB */
#define SHARE_MEM_BT_E1_ADDRESS		0x20098000
#define SHARE_MEM_BT_E1_LEN			(56 * 1024)	/* size:56KB */

#if defined(CONFIG_RSICV_CORE_KR4)
#define CONTEXT_SAVE_SIZE	320	/* portCONTEXT_SIZE:66*4 = 288 roundup to 64B aligned */
#elif defined(CONFIG_ARM_CORE_CA32)
#define CONTEXT_SAVE_SIZE	320 /* 15*4 + 32*8: general reg and floating reg */
#elif defined(CONFIG_ARM_CORE_CM4)
#define CONTEXT_SAVE_SIZE	192 /* 15*4 + 16*8: s16~s31 if use float */
#elif defined(CONFIG_ARM_CORE_CM0)
#define CONTEXT_SAVE_SIZE	64	/* not support hw float, 15*4 */
#endif

#if defined(CONFIG_BUILD_ROM) || \
    (!defined(CONFIG_SOLO) || \
     (defined(CONFIG_SOLO) && defined(CONFIG_ARM_CORE_CM4_KM4TZ)))
#define SYSTEM_CTRL_BASE         SYSTEM_TZ_CTRL_BASE
#define SYSTEM_CTRL_BASE_S       SYSTEM_TZ_CTRL_BASE_S
#elif defined(CONFIG_SOLO) && defined(CONFIG_ARM_CORE_CM4_KM4NS)
#define SYSTEM_CTRL_BASE         SYSTEM_NS_CTRL_BASE
#define SYSTEM_CTRL_BASE_S       SYSTEM_NS_CTRL_BASE_S
#endif

/** @} End of group AmebaD_Outline */
#endif //_HAL_PLATFORM_
