#include "WDT.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "ameba_soc.h"

#ifdef __cplusplus
}
#endif

WDG_TypeDef *WDG_DEV = CPU0_NS_WDG_DEV;
IRQn_Type WDG_IRQNUM = CPU0_NS_WDG_IRQ;
WDTIrqHandler user_handler = NULL;
void *user_data = NULL;

static uint32_t WDG_IrqHandler(void *data)
{
    (void)data;

    if (user_handler != NULL) {
        user_handler(user_data);
    }

    WDG_ClearINT(WDG_DEV, WDG_BIT_EIC);
    WDG_ClearINT(WDG_DEV, WDG_BIT_EIC);//remember to clear twice for wdg run slower

    return 0;
}

/**
 * @brief  Initialize the watchdog, including time and early interrupt settings.
 * @param  timeout_ms: Timeout value of watchdog timer in units of ms.
 * @retval none
 * @note  By default, watchdog will reset the whole system once timeout occurs.
 */
void WDT::InitWatchdog(uint32_t timeout_ms) {
    WDG_InitTypeDef WDG_InitStruct;

    WDG_StructInit(&WDG_InitStruct);
    WDG_InitStruct.Timeout = timeout_ms;
    /*set early int to 100ms if timeout is bigger than 100ms*/
    WDG_InitStruct.EICNT = timeout_ms > 100 ? 100 : timeout_ms / 2;
    WDG_InitStruct.EIMOD     = ENABLE;

    WDG_Init(WDG_DEV, &WDG_InitStruct);
}

/**
 * @brief  Enable the watchdog and it starts to count.
 * @param  none
 * @retval none
 */
void WDT::StartWatchdog(void) {
    WDG_Enable(WDG_DEV);
}

/**
 * @brief  Disable the watchdog and it stops counting.
 * @param  none
 * @retval none
 * @note  Once watchdog is enabled, it cannot be disabled by software.
 */
void WDT::StopWatchdog(void) {
    printf("Once enabled, watchdog cannot be disabled.\r\n");
    assert_param(0);
}

/**
 * @brief  Refresh count of the watchdog in avoidance of WDT timeout.
 * @param  none
 * @retval none
 */
void WDT::RefreshWatchdog(void) {
    WDG_Refresh(WDG_DEV);
}

/**
 * @brief  Enable eraly interrupt and register a watchdog timer timeout interrupt handler.
 *        The interrupt handler will be called at a programmable time prior to watchdog timeout, for users to prepare for reset
 * @param  handler: WDT timeout interrupt callback function.
 * @param  data: WDT timeout interrupt callback parameter.
 * @retval none
 */
void WDT::InitWatchdogIRQ(WDTIrqHandler handler, void *data) {
    WDG_ClearINT(WDG_DEV, WDG_BIT_EIC);
    user_handler = handler;
    user_data = data;
    InterruptRegister((IRQ_FUN)WDG_IrqHandler, WDG_IRQNUM, NULL, INT_PRI_MIDDLE);
    InterruptEn(WDG_IRQNUM, INT_PRI_MIDDLE);
    WDG_INTConfig(WDG_DEV, WDG_BIT_EIE, ENABLE);
}
