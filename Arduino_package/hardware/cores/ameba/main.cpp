/*
  main.cpp - Main loop for Arduino sketches
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#define ARDUINO_MAIN
#include "Arduino.h"
#include "os_wrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void console_init(void);
#if defined (__GNUC__)
/* Add This for C++ support to avoid compile error */
void* __dso_handle = 0;

int _close(int file) {
    return -1;
}
#endif

//osThreadId main_tid = 0;

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

#ifdef CONFIG_MBED_TLS_ENABLED
/*
 * //app_mbedtls_rom_init 
 */
static void* app_mbedtls_calloc_func(size_t nelements, size_t elementSize) {
    size_t size;
    void *ptr = NULL;

    size = nelements * elementSize;
    ptr = pvPortMalloc(size);

    if (ptr) {
        _memset(ptr, 0, size);
    }

    return ptr;
}

void app_mbedtls_rom_init(void) {
    mbedtls_platform_set_calloc_free(app_mbedtls_calloc_func, vPortFree);
    //rom_ssl_ram_map.use_hw_crypto_func = 1;
    rtl_cryptoEngine_init();
}
#endif

/*
 * \brief handle sketch
 */
#if defined(Arduino_STD_PRINTF)
// Redirect regular printf output to UART
// #include "serial_api.h"
// extern serial_t log_uart_obj;
int _write(int file, char *ptr, unsigned int len) {
    (void)file;
    unsigned int i;
    for (i = 0; i < len; i++) {
        //while (serial_writable(&log_uart_obj) != 1);
        //serial_putc(&log_uart_obj, ((int)ptr[i]));
        //while (!UART_Writable((UART_TypeDef*)UART0_DEV));
        //UART_CharPut((UART_TypeDef*)UART0_DEV, ptr[i]);
        LOGUART_PutChar((uint8_t)ptr[i]);
    }
    return i;
}
#endif

//void main_task(void const *arg)
//void main_task(void *arg)
void main_task(void *args) {
    (void)args;

    delay(1);

    setup();

    for (;;) 
    {        
        loop();
        if (serialEventRun) {
            serialEventRun();
        }
        rtos_task_yield();
        //vTaskDelete(NULL);
    }
}

void app_rtc_init(void)
{
	RTC_InitTypeDef RTC_InitStruct;
	RTC_TimeTypeDef RTC_TimeStruct;

	RTC_TimeStructInit(&RTC_TimeStruct);
	RTC_TimeStruct.RTC_Year = 2021;
	RTC_TimeStruct.RTC_Hours = 10;
	RTC_TimeStruct.RTC_Minutes = 20;
	RTC_TimeStruct.RTC_Seconds = 30;

	RTC_StructInit(&RTC_InitStruct);
	/*enable RTC*/
	RTC_Enable(ENABLE);
	RTC_Init(&RTC_InitStruct);
	RTC_SetTime(RTC_Format_BIN, &RTC_TimeStruct);
}

u32 rtc_irq_init(void *Data)
{
	/* To avoid gcc warnings */
	(void) Data;
	u32 temp;

	RTC_ClearDetINT();
	SDM32K_Enable();
	SYSTIMER_Init(); /* 0.2ms */
	RCC_PeriphClockCmd(NULL, APBPeriph_RTC_CLOCK, ENABLE);

	if ((Get_OSC131_STATE() & RTC_BIT_FIRST_PON) == 0) {
		app_rtc_init();
		/*set first_pon to 1, this indicate RTC first pon state*/
		temp = Get_OSC131_STATE() | RTC_BIT_FIRST_PON;
		Set_OSC131_STATE(temp);

		/*before 131k calibratopn, cke_rtc should be enabled*/
		if (SYSCFG_CHIPType_Get() == CHIP_TYPE_ASIC_POSTSIM) {//Only Asic need OSC Calibration
			OSC131K_Calibration(30000); /* PPM=30000=3% *//* 7.5ms */
		}
	}

	RTC_ClkSource_Select(SDM32K);

	return 0;
}

/*
 * \brief Main entry point of Arduino application
 */
int main(void) {
    init();

    initVariant();

    /*Register RTC_DET_IRQ callback function */
	InterruptRegister((IRQ_FUN) rtc_irq_init, RTC_DET_IRQ, (u32)NULL, INT_PRI_LOWEST);
	InterruptEn(RTC_DET_IRQ, INT_PRI_LOWEST);

#ifdef CONFIG_MBED_TLS_ENABLED
    app_mbedtls_rom_init();
#endif

//For all amebad boards, Analog pin needs to pull none. GPIO_PuPd_NOPULL/GPIO_PuPd_DOWN/GPIO_PuPd_UP
    // PAD_PullCtrl(_PB_1, GPIO_PuPd_NOPULL);
    // PAD_PullCtrl(_PB_2, GPIO_PuPd_NOPULL);
    // PAD_PullCtrl(_PB_3, GPIO_PuPd_NOPULL);

    // if (xTaskCreate(main_task, ((const char*)"init"), MAIN_THREAD_STACK_SIZE, NULL, tskIDLE_PRIORITY + 3/* + PRIORITIE_OFFSET*/, NULL) != pdPASS) {
    //     //printf("\n\r%s xTaskCreate(main_task) failed", __FUNCTION__);
    // }

    if (RTK_SUCCESS != rtos_task_create(NULL, "main_task", (rtos_task_function_t)main_task, (void *)NULL, MAIN_THREAD_STACK_SIZE, (1))) {
        //printf("Create main_task Err!!!\n");
    }

    rtos_sched_start();

    while(1);

    return 0;
}

#ifdef __cplusplus
}
#endif
