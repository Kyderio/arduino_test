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

#ifndef AmebaCAN_h
#define AmebaCAN_h

#include "api/HardwareCAN.h"

/* CAN sync segment is always one time quantum */
#define CAN_SYNC_SEG 1
/* Maximum acceptable deviation in sample point location (permille) */
#define CAN_SAMPLE_POINT_MARGIN 50

#define CAN_MIN_BITRATE 0
#define CAN_MAX_BITRATE 1000000
#define CAN_MAX_FILTER  1

/* Filter matches frames with extended (29-bit) CAN IDs */
#define CAN_FILTER_IDE BIT(0)

/* Filter matches frames with Remote Transmission Request (RTR) */
#define CAN_FILTER_RTR BIT(1)

/*
 * @brief Bit mask for a standard (11-bit) CAN identifier.
 */
#define CAN_STD_ID_MASK 0x7FFU

/*
 * @brief Bit mask for an extended (29-bit) CAN identifier.
 */
#define CAN_EXT_ID_MASK 0x1FFFFFFFU

#define EIO 5           /*< I/O error */
#define EBUSY 16        /*< Mount device busy */
#define EINVAL 22       /*< Invalid argument */
#define ENOSPC 28       /*< No space left on device */
#define ERANGE 34       /*< Result too large */
#define ENOTSUP 134     /*< Unsupported value */

#ifndef CLAMP
/*
 * @brief Clamp a value to a given range.
 *
 * @note Arguments are evaluated multiple times. Use Z_CLAMP for a GCC-only,
 * single evaluation version.
 *
 * @param val Value to be clamped.
 * @param low Lowest allowed value (inclusive).
 * @param high Highest allowed value (inclusive).
 *
 * @returns Clamped value.
 */
#define CLAMP(val, low, high) (((val) <= (low)) ? (low) : MIN(val, high))
#endif

/*
 * @brief Checks if a value is within range.
 *
 * @note @p val is evaluated twice.
 *
 * @param val Value to be checked.
 * @param min Lower bound (inclusive).
 * @param max Upper bound (inclusive).
 *
 * @retval true If value is within range
 * @retval false If the value is not within range
 */
#define IN_RANGE(val, min, max) ((val) >= (min) && (val) <= (max))

struct can_timing {
    /* Synchronisation jump width. */
    uint16_t sjw;
    /* Propagation segment. */
    uint16_t prop_seg;
    /* Phase segment 1. */
    uint16_t phase_seg1;
    /* Phase segment 2. */
    uint16_t phase_seg2;
    /* Prescaler value. */
    uint16_t prescaler;
};

namespace arduino {

class AmebaCanFilter
{
    public:
        AmebaCanFilter(uint32_t const can_id, uint32_t const id_mask, uint8_t const msg_flags)
            :id{can_id}
            ,mask{id_mask}
            ,flags{msg_flags} {}
        AmebaCanFilter():id{0},mask{0},flags{0} {}
        virtual ~AmebaCanFilter() {}
        /* CAN identifier to match. */
        uint32_t id;
        /* CAN identifier matching mask. If a bit in this mask is 0, the value
         * of the corresponding bit in the ``id`` field is ignored by the filter.
         */
        uint32_t mask;
        /* Msg flags. */
        uint8_t flags;
};

class AmebaCAN : public HardwareCAN
{
    public:
        AmebaCAN(uint32_t pinTx, uint32_t pinRx);
        virtual ~AmebaCAN() { }
        bool begin(CanBitRate const can_bitrate) override;
        bool begin(uint32_t const can_bitrate);
        void end(void) override;
        int write(CanMsg const &msg) override;
        size_t available(void) override;
        CanMsg read(void) override;
        void *getDev(void) {
            return A2Cx;
        }
        AmebaCanFilter getFilter(void) {
            return filter;
        }
        CanMsgRingbuffer *getMsgRingbuffer(void) {
            return &rxMsgBuf;
        }

        /**
         * @brief Set Rx filter
         *
         * @param filter AmebaCanFilter includes id, mask and flags.
         *               id: CAN identifier to match, 11-bit standard id or 29-bit extended id
         *               mask: CAN identifier matching mask. If a bit in this mask is 0, the value of the corresponding bit in the ``id`` field is ignored by the filter
         *               flags: Msg flags
         *                      0: all messages meet mask id received
         *                      CAN_FILTER_IDE: only extended messages meet mask id received
         *                      CAN_FILTER_RTR: only remote messages meet mask id received
         *                      CAN_FILTER_IDE | CAN_FILTER_RTR: only extended remote messages meet mask id received
         * @retval none.
         */
        void setRxFilter(AmebaCanFilter filter);

        /**
         * @brief Remove Rx filter
         *
         * @param none.
         *
         * @retval none.
         */
        void removeRxFilter(void);
        bool hasFilter(void) {
            return bFilter;
        }
    private:
        CanMsgRingbuffer rxMsgBuf;
        uint32_t pinTx;
        uint32_t pinRx;
        AmebaCanFilter filter;
        bool bFilter; /* whether has filter */
        void *A2Cx;
};

}

extern arduino::AmebaCAN CAN0;
extern arduino::AmebaCAN CAN1;

#endif
