/*
  Copyright (c) 2014 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "os_wrapper.h"

#ifdef __cplusplus
}
#endif

#define ADC_RESOLUTION  12

pwm_resource g_pwm_res[PWM_TIMER_NUM*PWM_INDEX_NUM] = {
    {4,0,TOTAL_GPIO_PIN_NUM,false},{4,1,TOTAL_GPIO_PIN_NUM,false},{4,2,TOTAL_GPIO_PIN_NUM,false},{4,3,TOTAL_GPIO_PIN_NUM,false},
    {5,0,TOTAL_GPIO_PIN_NUM,false},{5,1,TOTAL_GPIO_PIN_NUM,false},{5,2,TOTAL_GPIO_PIN_NUM,false},{5,3,TOTAL_GPIO_PIN_NUM,false},
    {6,0,TOTAL_GPIO_PIN_NUM,false},{6,1,TOTAL_GPIO_PIN_NUM,false},{6,2,TOTAL_GPIO_PIN_NUM,false},{6,3,TOTAL_GPIO_PIN_NUM,false},
    {7,0,TOTAL_GPIO_PIN_NUM,false},{7,1,TOTAL_GPIO_PIN_NUM,false},{7,2,TOTAL_GPIO_PIN_NUM,false},{7,3,TOTAL_GPIO_PIN_NUM,false},
};

static int readResolution = 12;
static int writeResolution = 8;
static int writePeriod = 1000;
static uint8_t anaRef = AR_DEFAULT;

static inline uint32_t mapResolution(uint32_t value, uint32_t from, uint32_t to)
{
    if (from == to) {
        return value;
    }
    if (from > to) {
        return value >> (from - to);
    }
    return value << (to - from);
}

int analogRead(pin_size_t pinNumber) {
    uint32_t valueRead = 0;

    amb_ard_pin_check_name(pinNumber);
    amb_ard_pin_check_type(pinNumber, TYPE_ANALOG);
    amb_ard_pin_check_fun(pinNumber, PIO_ADC);

    uint8_t ChIdx = NC;

    switch (g_APinDescription[pinNumber].pinname) {
        case AD_0:
            ChIdx = ADC_CH0;
            break;
        case AD_1:
            ChIdx = ADC_CH1;
            break;
        case AD_2:
            ChIdx = ADC_CH2;
            break;
        case AD_3:
            ChIdx = ADC_CH3;
            break;
        case AD_4:
            ChIdx = ADC_CH4;
            break;
        case AD_5:
            ChIdx = ADC_CH5;
            break;
        case AD_6:
            ChIdx = ADC_CH6;
            break;
        case AD_7:
            ChIdx = ADC_CH7;
            break;
        default:
            break;
    }

    ADC_InitTypeDef ADC_InitStruct;

    /* Enable ADC clock and function */
    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, ENABLE);

    /* Initialize ADC pin */
    Pinmux_Config(g_APinDescription[pinNumber].pinname, PINMUX_FUNCTION_ADC);
    PAD_PullCtrl(g_APinDescription[pinNumber].pinname, PullNone);
    PAD_SleepPullCtrl(g_APinDescription[pinNumber].pinname, PullNone);// avoid immediate wakeup once gated
    /* Disable digital path input */
    PAD_InputCtrl(g_APinDescription[pinNumber].pinname, DISABLE);

    /* Initialize ADC */
    ADC_StructInit(&ADC_InitStruct);
    ADC_InitStruct.ADC_CvlistLen = 0;
    ADC_Init(&ADC_InitStruct);

    ADC_Cmd(ENABLE);

    /* Set channel index into channel switch list*/
    ADC->ADC_CHSW_LIST_0 = ChIdx;

    /* Clear FIFO */
    ADC_ClearFIFO();

    /* SW trigger to sample */
    ADC_SWTrigCmd(ENABLE);
    while (ADC_Readable() == 0);
    ADC_SWTrigCmd(DISABLE);

    valueRead = ADC_GET_DATA_GLOBAL(ADC_Read());

    /* Disable ADC clock and function */
    RCC_PeriphClockCmd(APBPeriph_ADC, APBPeriph_ADC_CLOCK, DISABLE);

    return mapResolution(valueRead, ADC_RESOLUTION, readResolution);
}

void analogReadResolution(int res) {
    readResolution = res;
}

/*
 * @brief Configures the reference voltage used for analog input (i.e. the maximum voltage that can be sensed).
 *
 * @param mode Should be set to AR_DEFAULT.
 */
void analogReference(uint8_t mode) {
    anaRef = mode;
}

void analogWrite(pin_size_t pinNumber, int value) {
    amb_ard_pin_check_name(pinNumber);
    amb_ard_pin_check_fun(pinNumber, PIO_PWM);
    int index;

    if ((g_APinDescription[pinNumber].ulPinMode & PWM_MODE_ENABLED) != PWM_MODE_ENABLED) {
        pinRemoveMode(pinNumber);

        /* Allocate a pwm timer resource */
        for (index = 0; index < PWM_TIMER_NUM*PWM_INDEX_NUM; index++) {
            if (g_pwm_res[index].alloc == false) {
                // obj->pwmtimer_idx = g_pwm_res[index].pwmtimer_idx;
                // obj->pwm_idx = g_pwm_res[index].pwm_idx;
                g_pwm_res[index].pin = pinNumber;
                g_pwm_res[index].alloc = true;
                break;
            }
        }

        if (index == PWM_TIMER_NUM*PWM_INDEX_NUM) {
            printf("No free pwm timer resource!\r\n");
            return;
        }

        RCC_PeriphClockCmd(APBPeriph_TIMx[g_pwm_res[index].pwmtimer_idx], APBPeriph_TIMx_CLOCK[g_pwm_res[index].pwmtimer_idx], ENABLE);
        Pinmux_Config(g_APinDescription[pinNumber].pinname, PINMUX_FUNCTION_TIM4_PWM0 + PWM_INDEX_NUM * (g_pwm_res[index].pwmtimer_idx - 4) + g_pwm_res[index].pwm_idx);
        g_APinDescription[pinNumber].ulPinMode |= PWM_MODE_ENABLED;
        g_APinDescription[pinNumber].ulPinMode &= (~MODE_NOT_INITIAL);
    } else {
        // There is already a PWM configured
        for (index = 0; index < PWM_TIMER_NUM*PWM_INDEX_NUM; index++) {
            if ((g_pwm_res[index].pin == pinNumber) && (g_pwm_res[index].alloc == true)) {
                RTIM_CCxCmd(TIMx[g_pwm_res[index].pwmtimer_idx], g_pwm_res[index].pwm_idx, TIM_CCx_Disable);
                break;
            }
        }
        if (index == PWM_TIMER_NUM*PWM_INDEX_NUM) {
            printf("Cannot find the configured pwm!\r\n");
            return;
        }
    }
    RTIM_TimeBaseInitTypeDef RTIM_InitStruct;
    TIM_CCInitTypeDef TIM_CCInitStruct;

    // Init RTIM_InitStruct
    RTIM_TimeBaseStructInit(&RTIM_InitStruct);

    // Init TIM_CCInitStruct
    RTIM_CCStructInit(&TIM_CCInitStruct);

    // Update RTIM_InitStruct prescaler/period
    RTIM_InitStruct.TIM_Idx = g_pwm_res[index].pwmtimer_idx;
    RTIM_InitStruct.TIM_Prescaler = 0;
    RTIM_InitStruct.TIM_Period = (XTAL_40M / MHZ_TICK_CNT * writePeriod - 1) & 0xFFFF;
    RTIM_TimeBaseInit(TIMx[g_pwm_res[index].pwmtimer_idx], &RTIM_InitStruct, (IRQn_Type)TIMx_irq[g_pwm_res[index].pwmtimer_idx], NULL, NULL);

    // Update TIM_CCInitStruct pulse
    TIM_CCInitStruct.TIM_OCPulse = (XTAL_40M / MHZ_TICK_CNT * writePeriod * value / (1 << writeResolution)) & 0xFFFF;
    RTIM_CCxInit(TIMx[g_pwm_res[index].pwmtimer_idx], &TIM_CCInitStruct, g_pwm_res[index].pwm_idx);

    RTIM_CCxCmd(TIMx[g_pwm_res[index].pwmtimer_idx], g_pwm_res[index].pwm_idx, TIM_CCx_Enable);
    RTIM_Cmd(TIMx[g_pwm_res[index].pwmtimer_idx], ENABLE);
}

void analogWriteResolution(int res) {
    writeResolution = res;
}

int analogConvertVoltage(int valueRead)
{
    int voltage = ADC_GetVoltage(valueRead);

    if (voltage < 0) {
        voltage = 0;
    }

    return voltage;
}

void analogWritePeriod(int us) {
    writePeriod = us;
}

rtos_timer_t timer_handle = NULL;
uint8_t tone_pin = TOTAL_GPIO_PIN_NUM;

static void tone_timer_handler(void *arg) {
    (void)arg;
    noTone(tone_pin);
}

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration) {
    amb_ard_pin_check_name(_pin);
    amb_ard_pin_check_fun(_pin, PIO_PWM);

    int index;

    /* Only one tone can be generated at a time. 
     * If a tone is already playing on a different pin, the call to tone() will have no effect.
     */
    if ((tone_pin != TOTAL_GPIO_PIN_NUM) && (tone_pin != _pin)) {
        return;
    }

    tone_pin = _pin;

    if ((g_APinDescription[_pin].ulPinMode & PWM_MODE_ENABLED) != PWM_MODE_ENABLED) {
        pinRemoveMode(_pin);

        /* Allocate a pwm timer resource */
        for (index = 0; index < PWM_TIMER_NUM*PWM_INDEX_NUM; index++) {
            if (g_pwm_res[index].alloc == false) {
                g_pwm_res[index].pin = _pin;
                g_pwm_res[index].alloc = true;
                break;
            }
        }

        if (index == PWM_TIMER_NUM*PWM_INDEX_NUM) {
            printf("No free pwm timer resource!\r\n");
            return;
        }

        RCC_PeriphClockCmd(APBPeriph_TIMx[g_pwm_res[index].pwmtimer_idx], APBPeriph_TIMx_CLOCK[g_pwm_res[index].pwmtimer_idx], ENABLE);
        Pinmux_Config(g_APinDescription[_pin].pinname, PINMUX_FUNCTION_TIM4_PWM0 + PWM_INDEX_NUM * (g_pwm_res[index].pwmtimer_idx - 4) + g_pwm_res[index].pwm_idx);
        g_APinDescription[_pin].ulPinMode |= PWM_MODE_ENABLED;
        g_APinDescription[_pin].ulPinMode &= (~MODE_NOT_INITIAL);
    } else {
        // There is already a PWM configured
        for (index = 0; index < PWM_TIMER_NUM*PWM_INDEX_NUM; index++) {
            if ((g_pwm_res[index].pin == _pin) && (g_pwm_res[index].alloc == true)) {
                RTIM_CCxCmd(TIMx[g_pwm_res[index].pwmtimer_idx], g_pwm_res[index].pwm_idx, TIM_CCx_Disable);
                break;
            }
        }
        if (index == PWM_TIMER_NUM*PWM_INDEX_NUM) {
            printf("Cannot find the configured pwm!\r\n");
            return;
        }
    }
    RTIM_TimeBaseInitTypeDef RTIM_InitStruct;
    TIM_CCInitTypeDef TIM_CCInitStruct;
    uint32_t period_tick;

    // Init RTIM_InitStruct
    RTIM_TimeBaseStructInit(&RTIM_InitStruct);

    // Init TIM_CCInitStruct
    RTIM_CCStructInit(&TIM_CCInitStruct);

    if (frequency == 0) {
        // Update TIM_CCInitStruct pulse
        TIM_CCInitStruct.TIM_OCPulse = 0;
    } else {
        period_tick = XTAL_40M / frequency;

        // Update RTIM_InitStruct prescaler/period
        RTIM_InitStruct.TIM_Idx = g_pwm_res[index].pwmtimer_idx;
        RTIM_InitStruct.TIM_Prescaler = (period_tick > 0xFFFF)?(period_tick / 0x10000):0;
        RTIM_InitStruct.TIM_Period = (period_tick / (RTIM_InitStruct.TIM_Prescaler + 1) - 1) & 0xFFFF;

        // Update TIM_CCInitStruct pulse
        TIM_CCInitStruct.TIM_OCPulse = (period_tick / (RTIM_InitStruct.TIM_Prescaler + 1) / 2) & 0xFFFF;
    }

    RTIM_TimeBaseInit(TIMx[g_pwm_res[index].pwmtimer_idx], &RTIM_InitStruct, (IRQn_Type)TIMx_irq[g_pwm_res[index].pwmtimer_idx], NULL, NULL);
    RTIM_CCxInit(TIMx[g_pwm_res[index].pwmtimer_idx], &TIM_CCInitStruct, g_pwm_res[index].pwm_idx);

    RTIM_CCxCmd(TIMx[g_pwm_res[index].pwmtimer_idx], g_pwm_res[index].pwm_idx, TIM_CCx_Enable);
    RTIM_Cmd(TIMx[g_pwm_res[index].pwmtimer_idx], ENABLE);

    if (duration > 0) {
        // If a tone timer already exists, assume new tone command to refresh timer
        if (timer_handle != NULL) {
            rtos_timer_stop(timer_handle, 0);
            rtos_timer_change_period(timer_handle, duration, 0);
            rtos_timer_start(timer_handle, 0);
        } else {
            rtos_timer_create(&timer_handle, "tone_timer", NULL, duration, false, tone_timer_handler);
            rtos_timer_start(timer_handle, 0);
        }
    }
}

void noTone(uint8_t _pin) {
    if (timer_handle != NULL) {
        rtos_timer_stop(timer_handle, 0);
        rtos_timer_delete(timer_handle, 0);
        timer_handle = NULL;
    }
    pinRemoveMode(_pin);
    tone_pin = TOTAL_GPIO_PIN_NUM;
}