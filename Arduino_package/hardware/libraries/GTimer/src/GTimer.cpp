#include "GTimer.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "ameba_soc.h"

#ifdef __cplusplus
}
#endif

gtimer_resource g_timer_res[GTIMER_NUM] = {{NULL, 0, 2, true, false}, {NULL, 0, 3, true, false}};

static uint32_t gtimer_timeout_handler(void *data)
{
    uint32_t index = (uint32_t)data;
    GTimerHandler timeout_handler;
    uint32_t user_data;
    uint8_t tid;
    bool is_periodic;

    if (index >= GTIMER_NUM) {
        return 1;
    }

    tid = g_timer_res[index].tid;
    timeout_handler = g_timer_res[index].timeout_handler;
    user_data = g_timer_res[index].user_data;
    is_periodic = g_timer_res[index].is_periodic;

    RTIM_INTClear(TIMx[tid]);

    if (is_periodic == false) {
        RTIM_Cmd(TIMx[tid], DISABLE);
    }

    if (timeout_handler != NULL) {
        timeout_handler(user_data);
    }

    return 0;
}

int GTimerClass::begin(uint32_t duration_us, void (*handler)(uint32_t), bool periodic, uint32_t userdata)
{
    RTIM_TimeBaseInitTypeDef TIM_InitStruct;
    uint8_t tid;

    // Find a free gtimer resource
    uint32_t index;
    for (index = 0; index < GTIMER_NUM; ++index) {
        if (g_timer_res[index].is_alloc == false) {
            tid = g_timer_res[index].tid;
            g_timer_res[index].timeout_handler = handler;
            g_timer_res[index].user_data = userdata;
            g_timer_res[index].is_periodic = periodic;
            g_timer_res[index].is_alloc = true;
            break;
        }
    }

    if (index == GTIMER_NUM) {
        printf("No free GTIMER resource!\r\n");
        return -1;
    }

    RCC_PeriphClockCmd(APBPeriph_TIMx[tid], APBPeriph_TIMx_CLOCK[tid], ENABLE);
    RTIM_TimeBaseStructInit(&TIM_InitStruct);
    TIM_InitStruct.TIM_Idx = tid;
    TIM_InitStruct.TIM_Period = duration_us / 1000000 * 32768 - 1;

    RTIM_TimeBaseInit(TIMx[tid], &TIM_InitStruct, (IRQn_Type)TIMx_irq[tid], (IRQ_FUN)gtimer_timeout_handler, index);
    RTIM_INTConfig(TIMx[tid], TIM_IT_Update, ENABLE);
    RTIM_Cmd(TIMx[tid], ENABLE);

    return (int)index;
}

void GTimerClass::end(uint32_t id) {
    uint8_t tid;

    if (id >= GTIMER_NUM) {
        return;
    }

    tid = g_timer_res[id].tid;

    if (g_timer_res[id].is_alloc == true) {
        RTIM_Cmd(TIMx[tid], DISABLE);
        RCC_PeriphClockCmd(APBPeriph_TIMx[tid], APBPeriph_TIMx_CLOCK[tid], DISABLE);
        g_timer_res[id].timeout_handler = NULL;
        g_timer_res[id].user_data = 0;
        g_timer_res[id].is_periodic = true;
        g_timer_res[id].is_alloc = false;
    }
}

void GTimerClass::stop(uint32_t id)
{
    if (id >= GTIMER_NUM) {
        return;
    }

    if (g_timer_res[id].is_alloc == true) {
        RTIM_Cmd(TIMx[g_timer_res[id].tid], DISABLE);
    }
}

void GTimerClass::restart(uint32_t id) {
    if (id >= GTIMER_NUM) {
        return;
    }

    RTIM_Cmd(TIMx[g_timer_res[id].tid], ENABLE);
}

void GTimerClass::reload(uint32_t id, uint32_t duration_us)
{
    RTIM_ChangePeriodImmediate_us(TIMx[g_timer_res[id].tid], g_timer_res[id].tid, duration_us);
}

float GTimerClass::read(uint32_t id)
{
    uint8_t tid = g_timer_res[id].tid;

    float time = 0;
    uint8_t clk_source = 0;

    switch (tid) {
    case 0:
        clk_source = RCC_PeriphClockSourceGet(LTIM0);
        break;
    case 1:
        clk_source = RCC_PeriphClockSourceGet(LTIM1);
        break;
    case 2:
        clk_source = RCC_PeriphClockSourceGet(LTIM2);
        break;
    case 3:
        clk_source = RCC_PeriphClockSourceGet(LTIM3);
        break;
    }

    if (!clk_source) {
        time = (float)RTIM_GetCount(TIMx[tid]) / 32768.0f;
    } else {
        time = (float)RTIM_GetCount(TIMx[tid]);
    }

    return time;
}

uint64_t GTimerClass::readMs(uint32_t id)
{
    uint8_t tid = g_timer_res[id].tid;

    uint64_t time_ms = 0;
    uint8_t clk_source = 0;

    switch (tid) {
    case 0:
        clk_source = RCC_PeriphClockSourceGet(LTIM0);
        break;
    case 1:
        clk_source = RCC_PeriphClockSourceGet(LTIM1);
        break;
    case 2:
        clk_source = RCC_PeriphClockSourceGet(LTIM2);
        break;
    case 3:
        clk_source = RCC_PeriphClockSourceGet(LTIM3);
        break;
    }

    if (!clk_source) {
        time_ms = (uint64_t)(RTIM_GetCount(TIMx[tid]) * ((float)1000 / 32768));
    } else {
        time_ms = RTIM_GetCount(TIMx[tid]);
    }

    return time_ms;
}

uint64_t GTimerClass::readUs(uint32_t id)
{
    uint8_t tid = g_timer_res[id].tid;

    uint64_t time_us = 0;
    uint8_t clk_source = 0;

    switch (tid) {
    case 0:
        clk_source = RCC_PeriphClockSourceGet(LTIM0);
        break;
    case 1:
        clk_source = RCC_PeriphClockSourceGet(LTIM1);
        break;
    case 2:
        clk_source = RCC_PeriphClockSourceGet(LTIM2);
        break;
    case 3:
        clk_source = RCC_PeriphClockSourceGet(LTIM3);
        break;
    }

    if (!clk_source) {
        time_us = (uint64_t)(RTIM_GetCount(TIMx[tid]) * ((float)1000000 / 32768));
    } else {
        time_us = RTIM_GetCount(TIMx[tid]);
    }

    return time_us;
}

GTimerClass GTimer;
