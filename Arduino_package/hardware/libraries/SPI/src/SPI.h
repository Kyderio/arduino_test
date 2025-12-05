/*
 * Copyright (c) 2015 Arduino LLC
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

#ifndef _SPI_H_
#define _SPI_H_

#include <Arduino.h>
#include <api/HardwareSPI.h>

// SPI_HAS_TRANSACTION means SPI has
//   - beginTransaction()
//   - endTransaction()
//   - usingInterrupt()
//   - SPISetting(clock, bitOrder, dataMode)
// #define SPI_HAS_TRANSACTION 1
// Every core implementing arduino API has SPI transaction

// SPI_HAS_EXTENDED_CS_PIN_HANDLING means SPI has automatic 
// CS pin handling and provides the following methods:
//   - begin(pin)
//   - end(pin)
//   - setBitOrder(pin, bitorder)
//   - setDataMode(pin, datamode)
//   - setClockDivider(pin, clockdiv)
//   - transfer(pin, data, SPI_LAST/SPI_CONTINUE)
//   - beginTransaction(pin, SPISettings settings) (if transactions are available)
// #define SPI_HAS_EXTENDED_CS_PIN_HANDLING 1

// Platforms should define SPI_HAS_PERIPHERAL_MODE if SPI peripheral
// mode is supported, to allow applications to check whether peripheral
// mode is available or not
#define SPI_HAS_PERIPHERAL_MODE

class SPIClassAmeba : public arduino::HardwareSPI {
    public:
        SPIClassAmeba(void *pSpiObj, pin_size_t copi, pin_size_t cipo, pin_size_t sck, pin_size_t cs);

        uint8_t transfer(uint8_t data/*, SPITransferMode _mode = SPI_LAST*/);

        void transfer(void *_buf, size_t count/*, SPITransferMode _mode = SPI_LAST*/);

        uint16_t transfer16(uint16_t data/*, SPITransferMode _mode = SPI_LAST*/);

        // Transaction Functions
        void usingInterrupt(int interruptNumber);
        void notUsingInterrupt(int interruptNumber);
        void beginTransaction(SPISettings settings);
        void endTransaction(void);

        // SPI Configuration methods
        void attachInterrupt(void);
        void detachInterrupt(void);

        void begin(void);
        void end(void);

    private:
        void *pSpiObj;
        int pinCOPI;
        int pinCIPO;
        int pinSCK;
        int pinCS;
        bool initStatus;   // flag to mark SPI init status
        u8 dataBits;
        uint32_t clockFreq;
        SPIMode dataMode;
        BitOrder bitOrder;
        SPIBusMode busMode;
};

extern SPIClassAmeba SPI;
extern SPIClassAmeba SPI1;

#endif
