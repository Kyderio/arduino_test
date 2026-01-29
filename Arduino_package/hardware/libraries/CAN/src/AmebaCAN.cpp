/*
 * Copyright (c) 2015 Arduino LLC. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "Arduino.h"
#include "AmebaCAN.h"

using namespace arduino;

#ifdef __cplusplus
extern "C" {
#endif

#include "ameba_soc.h"

#ifdef __cplusplus
}
#endif

static uint32_t ram_buffer_map[] = {
    0x0, 0x6, 0xc, 0x12, 0x18, 0x1e, 0x24, 0x2a, 0x30,
    0x36, 0x3c, 0x42, 0x48, 0x4e, 0x54, 0x5a, 0x60
};

struct can_timing g_timing_min = 
    {
        .sjw = 1,
        .prop_seg = 2,
        .phase_seg1 = 2,
        .phase_seg2 = 2,
        .prescaler = 1,
    };

struct can_timing g_timing_max = 
    {
        .sjw = 4,
        .prop_seg = 6,
        .phase_seg1 = 8,
        .phase_seg2 = 8,
        .prescaler = 32,
    };

/**
 * @brief Check if a CAN msg matches a CAN filter
 *
 * @param frame CAN message.
 * @param filter CAN filter.
 * @return true if the CAN frame matches the CAN filter, false otherwise
 */
static bool msgMatchesFilter(const A2C_RxMsgTypeDef *msg, const AmebaCanFilter *filter)
{
    if ((msg->IDE == A2C_EXTEND_FRAME) && ((filter->flags & CAN_FILTER_IDE) == 0)) {
        /* Extended (29-bit) ID frame, standard (11-bit) filter */
        return false;
    }

    if ((msg->IDE == A2C_STANDARD_FRAME) && ((filter->flags & CAN_FILTER_IDE) != 0)) {
        /* Standard (11-bit) ID frame, extended (29-bit) filter */
        return false;
    }

    if ((msg->IDE == A2C_EXTEND_FRAME) && ((msg->ExtId ^ filter->id) & filter->mask)) {
        /* Masked ID mismatch */
        return false;
    }

    if ((msg->IDE == A2C_STANDARD_FRAME) && ((msg->StdId ^ filter->id) & filter->mask)) {
        /* Masked ID mismatch */
        return false;
    }

    return true;
}

static void handleRxMessage(AmebaCAN *obj) {
    A2C_TypeDef *A2Cx = (A2C_TypeDef *)obj->getDev();
    int i, bufIdx;
    A2C_RxMsgTypeDef RxMsg;

    memset(&RxMsg, 0, sizeof(A2C_RxMsgTypeDef));

    for (bufIdx = A2C_MESSAGE_BUFFER_SIZE; bufIdx > 0; bufIdx--) {
        RxMsg.MsgBufferIdx = bufIdx - 1;
        if (A2C_MsgBufRxDoneStatusGet(A2Cx, RxMsg.MsgBufferIdx)) {
            A2C_MsgBufRxDoneStatusClear(A2Cx, RxMsg.MsgBufferIdx);
            A2C_ReadMsg(A2Cx, &RxMsg);

            if (obj->hasFilter() == false) { // None filter
                CanMsg const msg(
                                (RxMsg.IDE == A2C_STANDARD_FRAME) ? CanStandardId(RxMsg.StdId) : CanExtendedId(RxMsg.ExtId),
                                RxMsg.DLC,
                                RxMsg.Data);
                obj->getMsgRingbuffer()->enqueue(msg);
            } else { // Has filter
                AmebaCanFilter filter = obj->getFilter();
                if (msgMatchesFilter(&RxMsg, &filter) == true) {
                    CanMsg const msg(
                                    (RxMsg.IDE == A2C_STANDARD_FRAME) ? CanStandardId(RxMsg.StdId) : CanExtendedId(RxMsg.ExtId),
                                    RxMsg.DLC,
                                    RxMsg.Data);
                    obj->getMsgRingbuffer()->enqueue(msg);
                }
            }
        }
    }
}

static uint32_t interruptHandler(void *data)
{
    AmebaCAN *obj = (AmebaCAN *)data;
    A2C_TypeDef *A2Cx = (A2C_TypeDef *)obj->getDev();
    uint32_t IntStatus, ErrStatus, TxErCnt, RxErCnt, ErrPassive, ErrBusoff, ErrWarning;

    IntStatus = A2C_GetINTStatus(A2Cx);

    /*ram move done interrupt */
    if (IntStatus & A2C_RAM_MOVE_DONE_INT) {
        A2C_ClearINT(A2Cx, A2C_BIT_RAM_MOVE_DONE_INT_FLAG);
    }

    /*tx interrupt*/
    if (IntStatus & A2C_TX_INT) {
        A2C_ClearINT(A2Cx, A2C_BIT_TX_INT_FLAG);
    }

    /*rx interrupt*/
    if (IntStatus & A2C_RX_INT) {
        A2C_ClearINT(A2Cx, A2C_BIT_RX_INT_FLAG);
        // printf("Clear Interrupt Status = %lx\n", A2C_GetINTStatus(A2Cx));

        /* get current error status */
        TxErCnt = A2C_TXErrCntGet(A2Cx);
        RxErCnt = A2C_RXErrCntGet(A2Cx);
        ErrPassive = (A2Cx->A2C_ERR_CNT_STS & A2C_BIT_ERROR_PASSIVE) >> 28;
        ErrBusoff = (A2Cx->A2C_ERR_CNT_STS & A2C_BIT_ERROR_BUSOFF) >> 29;
        ErrWarning = (A2Cx->A2C_ERR_CNT_STS & A2C_BIT_ERROR_WARNING) >> 30;
        // printf("****TEC = %ld, REC = %ld, ErrPassive = %ld, ErrBusoff = %ld, ErrWarning = %ld\n", TxErCnt, RxErCnt, ErrPassive, ErrBusoff, ErrWarning);

        handleRxMessage(obj);
    }

    /* bus off interrupt */
    if (IntStatus & A2C_BUSOFF_INT) {
        A2C_ClearINT(A2Cx, A2C_BIT_BUSOFF_INT_FLAG);
        // printf("A2C0: bus off\n");
    }

    /* wakeup interrupt */
    if (IntStatus & A2C_WKUP_INT) {
        A2C_ClearINT(A2Cx, A2C_BIT_WAKEUP_INT_FLAG);
        // printf("A2C0: wake up\n");
    }

    /* error interrupt */
    if (IntStatus & A2C_ERR_INT) {
        A2C_ClearINT(A2Cx, A2C_BIT_ERROR_INT_FLAG);
        // printf("A2C0: Clear Interrupt Status = %lx\n", A2C_GetINTStatus(A2Cx));

        ErrStatus = A2C_GetErrStatus(A2Cx);
        TxErCnt = A2C_TXErrCntGet(A2Cx);
        RxErCnt = A2C_RXErrCntGet(A2Cx);
        ErrPassive = (A2Cx->A2C_ERR_CNT_STS & A2C_BIT_ERROR_PASSIVE) >> 28;
        ErrBusoff = (A2Cx->A2C_ERR_CNT_STS & A2C_BIT_ERROR_BUSOFF) >> 29;
        ErrWarning = (A2Cx->A2C_ERR_CNT_STS & A2C_BIT_ERROR_WARNING) >> 30;

        if (ErrStatus & A2C_BIT_ERROR_BIT0) {
            A2C_ClearErrStatus(A2Cx, A2C_BIT_ERROR_BIT0);
            // printf("bit 0 error: tx = 0, but rx = 1\n");
        }
        if (ErrStatus & A2C_BIT_ERROR_BIT1) {
            A2C_ClearErrStatus(A2Cx, A2C_BIT_ERROR_BIT1);
            // printf("bit 1 error: tx = 1, but rx = 0\n");
        }
        if (ErrStatus & A2C_BIT_ERROR_FORM) {
            A2C_ClearErrStatus(A2Cx, A2C_BIT_ERROR_FORM);
            // printf("form error\n");
        }
        if (ErrStatus & A2C_BIT_ERROR_CRC) {
            A2C_ClearErrStatus(A2Cx, A2C_BIT_ERROR_CRC);
            // printf("CRC error\n");
        }
        if (ErrStatus & A2C_BIT_ERROR_STUFF) {
            A2C_ClearErrStatus(A2Cx, A2C_BIT_ERROR_STUFF);
            // printf("stuff error\n");
        }
        if (ErrStatus & A2C_BIT_ERROR_ACK) {
            A2C_ClearErrStatus(A2Cx, A2C_BIT_ERROR_ACK);
            // printf("ACK error\n");
        }
        if (ErrStatus & A2C_BIT_ERROR_TX) {
            A2C_ClearErrStatus(A2Cx, A2C_BIT_ERROR_TX);
            // printf("tx error\n");
        }
        if (ErrStatus & A2C_BIT_ERROR_RX) {
            A2C_ClearErrStatus(A2Cx, A2C_BIT_ERROR_RX);
            // printf("rx error\n");
        }
        // printf("TEC = %ld, REC = %ld\n", TxErCnt, RxErCnt);
    }
    return 0;
}

static int checkTimingInRange(const struct can_timing *timing,
                 const struct can_timing *min,
                 const struct can_timing *max)
{
    if (!IN_RANGE(timing->sjw, min->sjw, max->sjw) ||
        !IN_RANGE(timing->prop_seg, min->prop_seg, max->prop_seg) ||
        !IN_RANGE(timing->phase_seg1, min->phase_seg1, max->phase_seg1) ||
        !IN_RANGE(timing->phase_seg2, min->phase_seg2, max->phase_seg2) ||
        !IN_RANGE(timing->prescaler, min->prescaler, max->prescaler)) {
        return -ENOTSUP;
    }

    if ((timing->sjw > timing->phase_seg1) || (timing->sjw > timing->phase_seg2)) {
        return -ENOTSUP;
    }

    return 0;
}

static int setTiming(A2C_TypeDef *A2Cx, const struct can_timing *timing)
{
    const struct can_timing *min = &g_timing_min;
    const struct can_timing *max = &g_timing_max;
    uint32_t a2c_bit_timing;
    int err;

    err = checkTimingInRange(timing, min, max);
    if (err != 0) {
        return err;
    }

    a2c_bit_timing = A2Cx->A2C_BIT_TIMING;
    a2c_bit_timing &= ~(A2C_MASK_BRP | A2C_MASK_SJW | A2C_MASK_TSEG2 | A2C_MASK_TSEG1);
    a2c_bit_timing |= A2C_BRP(timing->prescaler - 1) | A2C_SJW(timing->sjw) |
                   A2C_TSEG1(timing->prop_seg + timing->phase_seg1 - 1) |
                   A2C_TSEG2(timing->phase_seg2 - 1);
    A2Cx->A2C_BIT_TIMING = a2c_bit_timing;

    return 0;
}

/**
 * @brief Get the sample point location for a given bitrate
 *
 * @param  bitrate The bitrate in bits/second.
 * @return The sample point in permille.
 */
static uint16_t samplePointForBitrate(uint32_t bitrate)
{
    uint16_t sample_pnt;

    if (bitrate > 800000) {
        /* 75.0% */
        sample_pnt = 750;
    } else if (bitrate > 500000) {
        /* 80.0% */
        sample_pnt = 800;
    } else {
        /* 87.5% */
        sample_pnt = 875;
    }

    return sample_pnt;
}

/**
 * @brief Update the timing given a total number of time quanta and a sample point.
 *
 * @code{.text}
 *
 * +---------------------------------------------------+
 * |     Nominal bit time in time quanta (total_tq)    |
 * +--------------+----------+------------+------------+
 * |   sync_seg   | prop_seg | phase_seg1 | phase_seg2 |
 * +--------------+----------+------------+------------+
 * | CAN_SYNG_SEG |        tseg1          |   tseg2    |
 * +--------------+-----------------------+------------+
 *                                        ^
 *                                   sample_pnt
 * @endcode
 *
 * @see @a can_timing
 *
 * @param total_tq   Total number of time quanta.
 * @param sample_pnt Sample point in permille of the entire bit time.
 * @param[out] res   Result is written into the @a can_timing struct provided.
 * @param min        Pointer to the minimum supported timing parameter values.
 * @param max        Pointer to the maximum supported timing parameter values.
 * @retval           0 or positive sample point error on success.
 * @retval           -ENOTSUP if the requested sample point cannot be met.
 */
static int updateSamplePoint(uint32_t total_tq, uint32_t sample_pnt, struct can_timing *res,
                 const struct can_timing *min, const struct can_timing *max)
{
    uint16_t tseg1_max = max->phase_seg1 + max->prop_seg;
    uint16_t tseg1_min = min->phase_seg1 + min->prop_seg;
    uint32_t sample_pnt_res;
    uint16_t tseg1;
    uint16_t tseg2;

    /* Calculate number of time quanta in tseg2 for given sample point */
    tseg2 = total_tq - (total_tq * sample_pnt) / 1000;
    tseg2 = CLAMP(tseg2, min->phase_seg2, max->phase_seg2);

    /* Calculate number of time quanta in tseg1 */
    tseg1 = total_tq - CAN_SYNC_SEG - tseg2;
    if (tseg1 > tseg1_max) {
        /* Sample point location must be decreased */
        tseg1 = tseg1_max;
        tseg2 = total_tq - CAN_SYNC_SEG - tseg1;

        if (tseg2 > max->phase_seg2) {
            return -ENOTSUP;
        }
    } else if (tseg1 < tseg1_min) {
        /* Sample point location must be increased */
        tseg1 = tseg1_min;
        tseg2 = total_tq - CAN_SYNC_SEG - tseg1;

        if (tseg2 < min->phase_seg2) {
            return -ENOTSUP;
        }
    } else {
        /* Sample point location within range */
    }

    res->phase_seg2 = tseg2;

    /* Attempt to distribute tseg1 evenly between prop_seq and phase_seg1 */
    res->prop_seg = CLAMP(tseg1 / 2, min->prop_seg, max->prop_seg);
    res->phase_seg1 = tseg1 - res->prop_seg;

    if (res->phase_seg1 > max->phase_seg1) {
        /* Even tseg1 distribution not possible, decrease phase_seg1 */
        res->phase_seg1 = max->phase_seg1;
        res->prop_seg = tseg1 - res->phase_seg1;
    } else if (res->phase_seg1 < min->phase_seg1) {
        /* Even tseg1 distribution not possible, increase phase_seg1 */
        res->phase_seg1 = min->phase_seg1;
        res->prop_seg = tseg1 - res->phase_seg1;
    } else {
        /* No redistribution necessary */
    }

    /* Calculate the resulting sample point */
    sample_pnt_res = (CAN_SYNC_SEG + tseg1) * 1000 / total_tq;

    /* Return the absolute sample point error */
    return sample_pnt_res > sample_pnt ?
        sample_pnt_res - sample_pnt :
        sample_pnt - sample_pnt_res;
}

/**
 * @brief Internal function for calculating CAN timing parameters.
 *
 * @param[out] res   Result is written into the @a can_timing struct provided.
 * @param min        Pointer to the minimum supported timing parameter values.
 * @param max        Pointer to the maximum supported timing parameter values.
 * @param bitrate    Target bitrate in bits/s.
 * @param sample_pnt Sample point in permille of the entire bit time.
 *
 * @retval 0 or positive sample point error on success.
 * @retval -EINVAL if the requested bitrate or sample point is out of range.
 * @retval -ENOTSUP if the requested bitrate is not supported.
 * @retval -EIO if @a can_get_core_clock() is not available.
 */
static int calcTiming(struct can_timing *res,
                    const struct can_timing *min, const struct can_timing *max,
                    uint32_t bitrate, uint16_t sample_pnt)
{
    uint32_t total_tq = CAN_SYNC_SEG + max->prop_seg + max->phase_seg1 + max->phase_seg2;
    struct can_timing tmp_res = {0,0,0,0,0};
    int err_min = INT_MAX;
    uint32_t core_clock = XTAL_ClkGet();
    int err;

    if (bitrate == 0 || sample_pnt >= 1000) {
        return -EINVAL;
    }

    if (sample_pnt == 0U) {
        sample_pnt = samplePointForBitrate(bitrate);
    }

    for (int prescaler = MAX(core_clock / (total_tq * bitrate), min->prescaler);
         prescaler <= max->prescaler;
         prescaler++) {

        if (core_clock % (prescaler * bitrate)) {
            /* No integer total_tq for this prescaler setting */
            continue;
        }

        total_tq = core_clock / (prescaler * bitrate);

        err = updateSamplePoint(total_tq, sample_pnt, &tmp_res, min, max);
        if (err < 0) {
            /* Sample point cannot be met for this prescaler setting */
            continue;
        }

        if (err < err_min) {
            /* Improved sample point match */
            err_min = err;
            res->prop_seg = tmp_res.prop_seg;
            res->phase_seg1 = tmp_res.phase_seg1;
            res->phase_seg2 = tmp_res.phase_seg2;
            res->prescaler = (uint16_t)prescaler;

            if (err == 0) {
                /* Perfect sample point match */
                break;
            }
        }
    }

    if (err_min != 0U) {
        printf("Sample point error: %d 1/1000\r\n", err_min);
    }

    /* Calculate default sjw as phase_seg2 / 2 and clamp the result */
    res->sjw = MIN(res->phase_seg1, res->phase_seg2 / 2);
    res->sjw = CLAMP(res->sjw, min->sjw, max->sjw);

    return err_min == INT_MAX ? -ENOTSUP : err_min;
}

/**
 * @brief Set the bitrate of the CAN controller
 *
 * CAN in Automation (CiA) 301 v4.2.0 recommends a sample point location of
 * 87.5% percent for all bitrates. However, some CAN controllers have
 * difficulties meeting this for higher bitrates.
 *
 * This function defaults to using a sample point of 75.0% for bitrates over 800
 * kbit/s, 80.0% for bitrates over 500 kbit/s, and 87.5% for all other
 * bitrates. This is in line with the sample point locations used by the Linux
 * kernel.
 *
 * @param A2Cx         where A2Cx can be A2C.
 * @param can_bitrate  Desired arbitration phase bitrate.
 *
 * @retval 0 If successful.
 * @retval -EBUSY if the CAN controller is not in stopped state.
 * @retval -EINVAL if the requested bitrate is out of range.
 * @retval -ENOTSUP if the requested bitrate not supported by the CAN controller/transceiver
 *                  combination.
 * @retval -ERANGE if the resulting sample point is off by more than +/- 5%.
 * @retval -EIO General input/output error, failed to set bitrate.
 */
static int setBitrate(A2C_TypeDef *A2Cx, uint32_t const can_bitrate) {
    struct can_timing timing = { 0 };
    const struct can_timing *min = &g_timing_min;
    const struct can_timing *max = &g_timing_max;
    uint16_t sample_pnt;
    int ret;

    if ((can_bitrate < CAN_MIN_BITRATE) || (can_bitrate > CAN_MAX_BITRATE)) {
        return -ENOTSUP;
    }

    sample_pnt = samplePointForBitrate(can_bitrate);
    ret = calcTiming(&timing, min, max, can_bitrate, sample_pnt);
    if (ret < 0) {
        return ret;
    }

    if (ret > CAN_SAMPLE_POINT_MARGIN) {
        return -ERANGE;
    }

    return setTiming(A2Cx, &timing);
}

static void configRxMsgBuf(A2C_TypeDef *A2Cx) {
    A2C_RxMsgTypeDef RxMsg;
    // cocnfig a2c rx, check rx data in interrupt_handler
    memset(&RxMsg, 0, sizeof(A2C_RxMsgTypeDef));
    RxMsg.RTR = A2C_DATA_FRAME;
    RxMsg.IDE = A2C_STANDARD_FRAME;
    RxMsg.MsgBufferIdx = A2C_MESSAGE_BUFFER_SIZE - 1;
    RxMsg.ExtId = 0x0;
    RxMsg.StdId = 0x0;
    RxMsg.ID_MASK = 0x0;
    RxMsg.RTR_Mask = 0x0;
    RxMsg.IDE_Mask = 0x0;
    A2C_SetRxMsgBuf(A2Cx, &RxMsg);
}

AmebaCAN::AmebaCAN(uint32_t pinTx, uint32_t pinRx) {
    amb_ard_pin_check_fun(pinTx, PIO_CAN);
    amb_ard_pin_check_fun(pinRx, PIO_CAN);

    this->pinTx = g_APinDescription[pinTx].pinname;
    this->pinRx = g_APinDescription[pinRx].pinname;

    bFilter = false;
}

bool AmebaCAN::begin(CanBitRate const can_bitrate) {
    return begin(static_cast<uint32_t>(can_bitrate));
}

bool AmebaCAN::begin(uint32_t const can_bitrate) {
    A2C_TypeDef *A2Cx = NULL;
    IRQn_Type  A2C_IRQ;
    A2C_InitTypeDef  A2C_InitStruct;
    int i;

    // init a2c
    if (((pinTx == PA_25) && (pinRx == PA_26)) 
        || ((pinTx == PA_6) && (pinRx == PA_7))) {
        A2Cx = A2C_DEV_TABLE[0].A2Cx;
        A2C_IRQ = A2C_DEV_TABLE[0].IrqNum;
        RCC_PeriphClockCmd(APBPeriph_A2C0, APBPeriph_A2C0_CLOCK, ENABLE);
        Pinmux_Config(pinTx, PINMUX_FUNCTION_A2C0_TX);
        Pinmux_Config(pinRx, PINMUX_FUNCTION_A2C0_RX);
        /*Pull the STB pin low to put the CAN transceiver into normal mode.*/
        PAD_PullCtrl(g_APinDescription[CAN_STB0].pinname, GPIO_PuPd_DOWN);
    } else if (((pinTx == PB_17) && (pinRx == PB_18)) 
                || ((pinTx == PA_15) && (pinRx == PA_14))) {
        A2Cx = A2C_DEV_TABLE[1].A2Cx;
        A2C_IRQ = A2C_DEV_TABLE[1].IrqNum;
        RCC_PeriphClockCmd(APBPeriph_A2C1, APBPeriph_A2C1_CLOCK, ENABLE);
        Pinmux_Config(pinTx, PINMUX_FUNCTION_A2C1_TX);
        Pinmux_Config(pinRx, PINMUX_FUNCTION_A2C1_RX);
        /*Pull the STB pin low to put the CAN transceiver into normal mode.*/
        PAD_PullCtrl(g_APinDescription[CAN_STB1].pinname, GPIO_PuPd_DOWN);
    } else {
        printf("Invalid CAN pin\r\n");
    }

    this->A2Cx = (void *)A2Cx;

    RCC_PeriphClockDividerFENSet(USB_PLL_A2C, DISABLE);
    RCC_PeriphClockDividerFENSet(SYS_PLL_A2C, DISABLE);
    RCC_PeriphClockSourceSet(A2C, XTAL);

    A2C_BusCmd(A2Cx, DISABLE);
    A2C_StructInit(&A2C_InitStruct);
    if (can_bitrate <= static_cast<uint32_t>(CanBitRate::BR_125k)) {
        A2C_InitStruct.A2C_TriSampleEn = ENABLE;
    }
    A2C_Init(A2Cx, &A2C_InitStruct);

    setBitrate(A2Cx, can_bitrate);

    A2C_RamBufferMapConfig(A2Cx, ram_buffer_map);

    InterruptDis(A2C_IRQ);
    InterruptUnRegister(A2C_IRQ);
    InterruptRegister((IRQ_FUN)interruptHandler, A2C_IRQ, (uint32_t)this, INT_PRI_MIDDLE);
    InterruptEn(A2C_IRQ, INT_PRI_MIDDLE);
    A2C_INTConfig(A2Cx, (A2C_TX_INT | A2C_RX_INT | A2C_RAM_MOVE_DONE_INT | A2C_ERR_INT | A2C_BUSOFF_INT | A2C_WKUP_INT), ENABLE);
    A2C_TxMsgBufINTConfig(A2Cx, A2C_MB_TXINT_EN(0xFFFF), ENABLE);
    A2C_RxMsgBufINTConfig(A2Cx, A2C_MB_RXINT_EN(0xFFFF), ENABLE);

    A2C_Cmd(A2Cx, ENABLE);
    A2C_BusCmd(A2Cx, ENABLE);

    while (!A2C_BusStatusGet(A2Cx));

    /* If no filter, config default rx msg buffer */
    if (hasFilter() == false) {
        configRxMsgBuf(A2Cx);
    } else {
        uint32_t a2c_ram_cmd, a2c_ram_arb, a2c_ram_mask;

        /* Enable Msg Buffer access*/
        a2c_ram_cmd = (A2C_BIT_RAM_BUFFER_EN | A2C_BIT_RAM_ACC_ARB | A2C_BIT_RAM_ACC_CS |
                A2C_BIT_RAM_ACC_MASK | A2C_BIT_RAM_ACC_DATA_MASK | A2C_BIT_RAM_DIR);
        a2c_ram_cmd &= ~A2C_MASK_RAM_ACC_NUM;
        a2c_ram_cmd |= A2C_RAM_ACC_NUM(A2C_MESSAGE_BUFFER_SIZE - i - 1);

        /*Config frame header*/
        if (filter.flags & CAN_FILTER_IDE) {
            a2c_ram_arb = A2C_RAM_ID(filter.id) | A2C_BIT_RAM_IDE;
        } else {
            a2c_ram_arb = A2C_RAM_ID((filter.id & 0x7FF) << 18);
        }

        if (filter.flags & CAN_FILTER_RTR) {
            a2c_ram_arb |= A2C_BIT_RAM_RTR;
        }

        A2Cx->A2C_RAM_ARB = a2c_ram_arb;

        /* Enable the current buffer to receive data */
        A2Cx->A2C_RAM_CS &= ~A2C_BIT_RAM_RXTX;

        /* Set the mask ID to block unwanted data frames */
        if (filter.flags & CAN_FILTER_IDE) {
            A2Cx->A2C_RAM_MASK = A2C_BIT_RAM_IDE_MASK | A2C_RAM_ID_MASK(filter.mask);
        } else {
            A2Cx->A2C_RAM_MASK = A2C_RAM_ID_MASK(filter.mask << 18);
        }
        if (filter.flags & CAN_FILTER_RTR) {
            A2Cx->A2C_RAM_MASK |= A2C_BIT_RAM_RTR_MASK;
        }

        /* Write RX setting into the ram message buffer */
        a2c_ram_cmd |= A2C_BIT_RAM_START;
        A2Cx->A2C_RAM_CMD = a2c_ram_cmd;

        while (A2Cx->A2C_RAM_CMD & A2C_BIT_RAM_START) {
        }
    }

    return true;
}

void AmebaCAN::end() {
    A2C_TypeDef *A2Cx = (A2C_TypeDef *)this->A2Cx;
    int i;

    /* Dequeue all buffered msg */
    while (available()) {
        read();
    }

    /* Remove filter */
    removeRxFilter();

    /* Clear irq flags/Tec&Rec count/error status/msg buffer status */
    A2C_ClearAllINT(A2Cx);

    /* Close bus */
    A2C_BusCmd(A2Cx, DISABLE);
}

int AmebaCAN::write(CanMsg const &msg) {
    A2C_TxMsgTypeDef TxMsg;
    A2C_TypeDef *A2Cx = (A2C_TypeDef *)this->A2Cx;

    memset(&TxMsg, 0, sizeof(A2C_TxMsgTypeDef));

    TxMsg.RTR = A2C_DATA_FRAME;
    TxMsg.IDE = (msg.isStandardId())?A2C_STANDARD_FRAME:A2C_EXTEND_FRAME;
    TxMsg.MsgBufferIdx = 0x0;
    TxMsg.StdId = (msg.isStandardId())?msg.getStandardId():0;
    TxMsg.ExtId = (msg.isExtendedId())?msg.getExtendedId():0;
    TxMsg.DLC = msg.data_length;
    memcpy(TxMsg.Data, msg.data, msg.data_length);

    A2C_WriteMsg(A2Cx, &TxMsg);

    return 1;
}

size_t AmebaCAN::available(void) {
    return rxMsgBuf.available();
}

CanMsg AmebaCAN::read(void) {
    return rxMsgBuf.dequeue();
}

void AmebaCAN::setRxFilter(AmebaCanFilter filter) {
    if (bFilter == false) {
        this->filter = filter;
        bFilter = true;
    }
}

void AmebaCAN::removeRxFilter(void) {
    A2C_TypeDef *A2Cx = (A2C_TypeDef *)this->A2Cx;

    if (hasFilter() == false) {
        return;
    }

    filter.id = 0;
    filter.mask = 0;
    filter.flags = 0;

    A2Cx->A2C_RAM_CS = 0;


    bFilter = false;

    configRxMsgBuf(A2Cx);
}

AmebaCAN CAN0 = AmebaCAN(CAN_TX0, CAN_RX0);
AmebaCAN CAN1 = AmebaCAN(CAN_TX1, CAN_RX1);
