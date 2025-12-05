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

#include "SPI.h"
#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "spi_api.h"
#include "spi_ex_api.h"
#include "PinNames.h"

#ifdef __cplusplus
}
#endif

spi_t spi_obj0;
spi_t spi_obj1;
bool usingIrq[TOTAL_GPIO_PIN_NUM] = {false};

volatile int spiRxDone;
volatile int spiTxDone;
static void spi_tr_done_callback(uint32_t pdata, SpiIrq event)
{
    (void)pdata;

    switch (event) {
        case SpiRxIrq:
            spiRxDone = 1;
            break;
        case SpiTxIrq:
            spiTxDone = 1;
            break;
        default:
            printf("unknown interrput event!\n");
            break;
    }
}

SPIClassAmeba::SPIClassAmeba(void *pSpi, pin_size_t copi, pin_size_t cipo, pin_size_t sck, pin_size_t cs) {
    pSpiObj = pSpi;

    pinCOPI = copi;
    pinCIPO = cipo;
    pinSCK = sck;
    pinCS = cs;

    initStatus = false;
    dataBits = 8;           // default dataBits is 8 bits
    dataMode = SPI_MODE0;   // default dataMode is mode 0
    bitOrder = MSBFIRST;    // default bitOrder is MSB first

// #if defined(BOARD_SPARKFUN_AWCU488)
//     clockFreq = 2000000;
// #else
    clockFreq = 10000000;
// #endif

    busMode = SPI_CONTROLLER;
}

void SPIClassAmeba::beginTransaction(SPISettings settings) {
    bitOrder = settings.getBitOrder();
    dataMode = settings.getDataMode();
    busMode = settings.getBusMode();
    clockFreq = settings.getClockFreq();
    spi_format((spi_t *)pSpiObj, dataBits, dataMode, busMode);
    if (busMode == SPI_CONTROLLER) {
        spi_frequency((spi_t *)pSpiObj, clockFreq);
    }

    // disable using interrupt
    for (pin_size_t i = 0; i < TOTAL_GPIO_PIN_NUM; ++i)
    {
        if (usingIrq[i] == true) {
            disAttachedInterrupt(i);
        }
    }
}

void SPIClassAmeba::endTransaction(void) {
    // enable using interrupt
    for (pin_size_t i = 0; i < TOTAL_GPIO_PIN_NUM; ++i)
    {
        if (usingIrq[i] == true) {
            enAttachedInterrupt(i);
        }
    }
}

void SPIClassAmeba::begin(void) {
    amb_ard_pin_check_fun(pinCOPI, PIO_SPI);
    amb_ard_pin_check_fun(pinCIPO, PIO_SPI);
    amb_ard_pin_check_fun(pinSCK, PIO_SPI);
    amb_ard_pin_check_fun(pinCS, PIO_SPI);

    pinCOPI = g_APinDescription[pinCOPI].pinname;
    pinCIPO = g_APinDescription[pinCIPO].pinname;
    pinSCK = g_APinDescription[pinSCK].pinname;
    pinCS = g_APinDescription[pinCS].pinname;

    if (pinCOPI == PA_15) {
        ((spi_t *)pSpiObj)->spi_idx = MBED_SPI0;
    } else if (pinCOPI == PB_14) {
        ((spi_t *)pSpiObj)->spi_idx = MBED_SPI1;
    } else {
        printf("SPI begin: error. wrong spi_idx \r\n");
        return;
    }

    spi_init(
        (spi_t *)pSpiObj, 
        (PinName)pinCOPI, 
        (PinName)pinCIPO, 
        (PinName)pinSCK, 
        (PinName)pinCS
    );

    // Mark SPI init status
    initStatus = true;
}

void SPIClassAmeba::end(void) {
    spi_free((spi_t *)pSpiObj);

    // Mark SPI init status
    initStatus = false;
}

uint8_t SPIClassAmeba::transfer(uint8_t data) {
    uint8_t d;

    if (busMode == SPI_CONTROLLER) {
        d = (uint8_t)spi_master_write((spi_t *)pSpiObj, data);
    } else {
        spi_slave_write((spi_t *)pSpiObj, data);
        d = spi_slave_read((spi_t *)pSpiObj);
    }

    return d;
}

void SPIClassAmeba::transfer(void *buf, size_t count) {
    // uint8_t *buffer = reinterpret_cast<uint8_t *>(buf);
    // for (size_t i=0; i<count; i++) {
    //     *buffer = transfer(*buffer);
    //     buffer++;
    // }
    int i = 0;
    spiRxDone = 0;
    spi_irq_hook((spi_t *)pSpiObj, (spi_irq_handler)spi_tr_done_callback, (uint32_t)pSpiObj);

    if (busMode == SPI_CONTROLLER) {
        //spi_master_write_read_stream((spi_t *)pSpiObj, (char *)buf, (char *)buf, (uint32_t)count);
        spi_master_write_read_stream_dma((spi_t *)pSpiObj, (char *)buf, (char *)buf, (uint32_t)count);
    } else {
        //spi_slave_read_stream((spi_t *)pSpiObj, (char *)buf, (uint32_t)count);
        //spi_slave_write_stream((spi_t *)pSpiObj, (char *)buf, (uint32_t)count);
        spi_slave_read_stream_dma((spi_t *)pSpiObj, (char *)buf, (uint32_t)count);
        spi_slave_write_stream_dma((spi_t *)pSpiObj, (char *)buf, (uint32_t)count);
    }

    while (spiRxDone == 0) {
        delay(100);
        i++;
        if (i > 150) {
            printf("SPI Wait Timeout\r\n");
            break;
        }
    }
}

uint16_t SPIClassAmeba::transfer16(uint16_t data) {
    union {
        uint16_t val;
        struct {
            uint8_t lsb;
            uint8_t msb;
        };
    } t;
    t.val = data;

    if (bitOrder == LSBFIRST) {
        t.lsb = transfer(t.lsb);
        t.msb = transfer(t.msb);
    } else {
        t.msb = transfer(t.msb);
        t.lsb = transfer(t.lsb);
    }
    data = t.val;
    return data;
}

void SPIClassAmeba::usingInterrupt(int interruptNumber) {
    pin_size_t pinNumber = interruptToDigitalPin(interruptNumber);
    if (isInterruptAttached(pinNumber)) {
        usingIrq[pinNumber] = true;
    }
}

void SPIClassAmeba::notUsingInterrupt(int interruptNumber) {
    pin_size_t pinNumber = interruptToDigitalPin(interruptNumber);
    if (isInterruptAttached(pinNumber)) {
        usingIrq[pinNumber] = false;
    }
}

void SPIClassAmeba::SPIClassAmeba::attachInterrupt(void) {

}

void SPIClassAmeba::detachInterrupt(void) {

}

SPIClassAmeba SPI((void *)(&spi_obj0), SPI_COPI, SPI_CIPO, SPI_SCK, SPI_CS);        // 11, 12, 14, 15
SPIClassAmeba SPI1((void *)(&spi_obj1), SPI1_COPI, SPI1_CIPO, SPI1_SCK, SPI1_CS);   // 24, 29, 30, 32