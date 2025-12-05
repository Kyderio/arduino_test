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

#ifndef TwoWire_h
#define TwoWire_h

#include "api/HardwareI2C.h"

#define BUFFER_LENGTH 128

namespace arduino {

class TwoWire : public HardwareI2C
{
  public:
    public:
        TwoWire(uint32_t pinSDA, uint32_t pinSCL);
        void begin();
        void begin(uint8_t);
        void begin(int);
        void end();
        void setClock(uint32_t);
        void beginTransmission(uint8_t);
        void beginTransmission(int);
        uint8_t endTransmission(void);
        uint8_t endTransmission(bool);
        size_t requestFrom(uint8_t, size_t);
        size_t requestFrom(uint8_t, size_t, bool);
        size_t requestFrom(int, size_t);
        size_t requestFrom(int, size_t, bool);
        virtual size_t write(uint8_t);
        virtual size_t write(const uint8_t *, size_t);
        virtual int available(void);
        virtual int read(void);
        virtual int peek(void);
        virtual void flush(void);
        void onReceive(void(*)(int));
        void onRequest(void(*)(void));

        inline size_t write(unsigned long n) { return write((uint8_t)n); }
        inline size_t write(long n) { return write((uint8_t)n); }
        inline size_t write(unsigned int n) { return write((uint8_t)n); }
        inline size_t write(int n) { return write((uint8_t)n); }
        using Print::write;
        size_t slaveWrite(int);
        size_t slaveWrite(char *);
        size_t slaveWrite(uint8_t *, size_t);

    private:
        bool is_slave;

        // RX Buffer
        uint8_t rxBuffer[BUFFER_LENGTH];
        uint8_t rxBufferIndex;
        uint8_t rxBufferLength;

        // TX Buffer
        uint8_t txAddress;
        uint8_t txBuffer[BUFFER_LENGTH];
        uint8_t txBufferLength;

        // Callback user functions
        void (*onRequestCallback)(void);
        void (*onReceiveCallback)(int);
        static void onRequestService(void *);
        static void onReceiveService(uint8_t *, size_t, /*bool, */void *);

        uint32_t pinSDA;
        uint32_t pinSCL;

        void *pI2C;

        // TWI clock frequency
        static const uint32_t TWI_CLOCK = 100000;
        uint32_t twiClock;

        // Timeouts
        static const uint32_t RECV_TIMEOUT = 50;
        static const uint32_t XMIT_TIMEOUT = 100000;
};

}

extern arduino::TwoWire Wire;

#endif
