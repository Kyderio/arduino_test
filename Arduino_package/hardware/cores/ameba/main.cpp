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

#ifdef __cplusplus
extern "C" {
#endif
#include "os_wrapper.h"
#include "ameba_soc.h"

extern void console_init(void);
#if defined (__GNUC__)
/* Add This for C++ support to avoid compile error */
void* __dso_handle = 0;

int _close(int file) {
    return -1;
}
#endif

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

/*
 * \brief handle sketch
 */
#if defined(Arduino_STD_PRINTF)
// Redirect regular printf output to UART
int _write(int file, char *ptr, unsigned int len) {
    (void)file;
    unsigned int i;
    for (i = 0; i < len; i++) {
        LOGUART_PutChar((uint8_t)ptr[i]);
    }
    return i;
}
#endif

void app_pmu_init(void)
{
    SOCPS_SleepInit();
    pmu_init_wakeup_timer();
    pmu_set_sleep_type(SLEEP_PG);

    /* only one core in fullmac mode */
#if !(!defined (CONFIG_WHC_INTF_IPC) && defined (CONFIG_WHC_DEV))
    /* If the current cpu is np, need to hold the lock of another cpu */
    if ((HAL_READ32(PMC_BASE, SYSPMC_CTRL) & PMC_BIT_CPU_IS_AP) == 0) {
        pmu_acquire_wakelock(PMU_CPU1_RUN);
    }
#endif
}

void CPU1_WDG_RST_Handler(void)
{
    /* Let NP run */
    HAL_WRITE32(SYSTEM_CTRL_BASE, REG_LSYS_BOOT_CFG, HAL_READ32(SYSTEM_CTRL_BASE, REG_LSYS_BOOT_CFG) | LSYS_BIT_BOOT_CPU1_RUN);

    /* clear CPU1_WDG_RST intr*/
    HAL_WRITE32(SYSTEM_CTRL_BASE, REG_AON_BOOT_REASON_HW, AON_BIT_RSTF_WDG0_CPU);
}

void main_task(void *args) {
    (void)args;

    setup();

    for (;;) 
    {        
        loop();
        if (serialEventRun) {
            serialEventRun();
        }
        rtos_task_yield();
    }
}

/*
 * \brief Main entry point of Arduino application
 */
int main(void) {
    init();

    initVariant();

    app_pmu_init();

    /* Register CPU1_WDG_RST_IRQ Callback function */
    InterruptRegister((IRQ_FUN) CPU1_WDG_RST_Handler, CPU1_WDG_RST_IRQ, (u32)NULL, INT_PRI_LOWEST);
    InterruptEn(CPU1_WDG_RST_IRQ, INT_PRI_LOWEST);

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
