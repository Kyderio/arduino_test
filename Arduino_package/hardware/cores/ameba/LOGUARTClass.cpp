/*
  Copyright (c) 2011 Arduino.  All right reserved.

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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LOGUARTClass.h"

//#define LOG_UART_MODIFIABLE_BAUD_RATE 1

#ifdef __cplusplus
extern "C" {
#endif

#include "ameba_loguart.h"

#ifdef __cplusplus
}
#endif

using namespace arduino;

RingBuffer rx_buffer0;

// void arduino_loguart_irq_handler(uint32_t id, SerialIrq event) {
void arduino_loguart_irq_handler(void *arg) {
    // uint8_t c;
    RingBuffer *pRxBuffer = (RingBuffer *)arg;

    // if (event == RxIrq) {
    //     // c = char(serial_getc(&log_uart_obj));
    //     c = LOGUART_GetChar(FALSE );
    //     pRxBuffer->store_char(c);
    // }
    uint8_t data = 0;
    // uint32_t rxerror_en;

    uint32_t IrqEn = LOGUART_GetIMR();
    uint32_t reg_lsr = LOGUART_GetStatus(LOGUART_DEV);

    LOGUART_INTConfig(LOGUART_DEV, LOGUART_BIT_ERBI | LOGUART_BIT_ETOI, DISABLE);

    /* Rx data ready interrupt */
    if (reg_lsr & LOGUART_BIT_RXFIFO_INT) {
        while (1) {
            if (LOGUART_Readable()) {
                data = LOGUART_GetChar(FALSE);
                // RTK_LOGS(NOTAG, RTK_LOG_INFO, "%x\n", data);
                pRxBuffer->store_char(data);
            } else {
                break;
            }
        }
    }

    /* Rx timeout interrupt */
    if (reg_lsr & LOGUART_BIT_TIMEOUT_INT) {
        LOGUART_INTClear(LOGUART_DEV, LOGUART_BIT_TOICF);

        while (1) {
            if (LOGUART_Readable()) {
                data = LOGUART_GetChar(FALSE);
                // RTK_LOGS(NOTAG, RTK_LOG_INFO, "%x\n", data);
                pRxBuffer->store_char(data);
            } else {
                break;
            }
        }
    }

    // /* Rx error interrupt */
    // rxerror_en = IrqEn & LOGUART_BIT_ELSI;
    // if (rxerror_en) {
    //     DelayMs(5000); //for tester to switch format setting to print log

    //     if (reg_lsr & LOGUART_BIT_OVR_ERR) {
    //         RTK_LOGS(NOTAG, RTK_LOG_INFO, "LSR over run interrupt\n");
    //     }

    //     if (reg_lsr & LOGUART_BIT_PAR_ERR) {
    //         RTK_LOGS(NOTAG, RTK_LOG_INFO, "LSR parity error interrupt\n");
    //     }

    //     if (reg_lsr & LOGUART_BIT_FRM_ERR) {
    //         RTK_LOGS(NOTAG, RTK_LOG_INFO, "LSR frame error(stop bit error) interrupt\n");
    //     }

    //     if (reg_lsr & LOGUART_BIT_BREAK_INT) {
    //         RTK_LOGS(NOTAG, RTK_LOG_INFO, "LSR break error interrupt\n");
    //     }

    //     if (reg_lsr & LOGUART_BIT_RXFIFO_ERR) {
    //         LOGUART_INTConfig(LOGUART_DEV, LOGUART_BIT_ELSI, DISABLE);
    //         LOGUART_INTClear(LOGUART_DEV, LOGUART_BIT_RLSICF);
    //         RTK_LOGS(NOTAG, RTK_LOG_INFO, "LSR rx error interrupt\n");
    //     }
    // }

    LOGUART_INTConfig(LOGUART_DEV, LOGUART_BIT_ERBI | LOGUART_BIT_ETOI, ENABLE);
}

LOGUARTClass::LOGUARTClass(int dwIrq, RingBuffer* pRx_buffer) {
    _rx_buffer = pRx_buffer;
    _dwIrq = dwIrq;
}

// Protected Methods //////////////////////////////////////////////////////////////

// Public Methods /////////////////////////////////////////////////////////////////
// void LOGUARTClass::IrqHandler(void) {
//     uint8_t data = 0;
//     // uint32_t rxerror_en;

//     uint32_t IrqEn = LOGUART_GetIMR();
//     uint32_t reg_lsr = LOGUART_GetStatus(LOGUART_DEV);

//     LOGUART_INTConfig(LOGUART_DEV, LOGUART_BIT_ERBI | LOGUART_BIT_ETOI, ENABLE);

//     /* Rx data ready interrupt */
//     if (reg_lsr & LOGUART_BIT_RXFIFO_INT) {
//         while (1) {
//             if (LOGUART_Readable()) {
//                 data = LOGUART_GetChar(FALSE);
//                 // RTK_LOGS(NOTAG, RTK_LOG_INFO, "%x\n", data);
//                 _rx_buffer->store_char(data);
//             } else {
//                 break;
//             }
//         }
//     }

//     /* Rx timeout interrupt */
//     if (reg_lsr & LOGUART_BIT_TIMEOUT_INT) {
//         LOGUART_INTClear(LOGUART_DEV, LOGUART_BIT_TOICF);

//         while (1) {
//             if (LOGUART_Readable()) {
//                 data = LOGUART_GetChar(FALSE);
//                 // RTK_LOGS(NOTAG, RTK_LOG_INFO, "%x\n", data);
//                 _rx_buffer->store_char(data);
//             } else {
//                 break;
//             }
//         }
//     }

//     // /* Rx error interrupt */
//     // rxerror_en = IrqEn & LOGUART_BIT_ELSI;
//     // if (rxerror_en) {
//     //     DelayMs(5000); //for tester to switch format setting to print log

//     //     if (reg_lsr & LOGUART_BIT_OVR_ERR) {
//     //         RTK_LOGS(NOTAG, RTK_LOG_INFO, "LSR over run interrupt\n");
//     //     }

//     //     if (reg_lsr & LOGUART_BIT_PAR_ERR) {
//     //         RTK_LOGS(NOTAG, RTK_LOG_INFO, "LSR parity error interrupt\n");
//     //     }

//     //     if (reg_lsr & LOGUART_BIT_FRM_ERR) {
//     //         RTK_LOGS(NOTAG, RTK_LOG_INFO, "LSR frame error(stop bit error) interrupt\n");
//     //     }

//     //     if (reg_lsr & LOGUART_BIT_BREAK_INT) {
//     //         RTK_LOGS(NOTAG, RTK_LOG_INFO, "LSR break error interrupt\n");
//     //     }

//     //     if (reg_lsr & LOGUART_BIT_RXFIFO_ERR) {
//     //         LOGUART_INTConfig(LOGUART_DEV, LOGUART_BIT_ELSI, DISABLE);
//     //         LOGUART_INTClear(LOGUART_DEV, LOGUART_BIT_RLSICF);
//     //         RTK_LOGS(NOTAG, RTK_LOG_INFO, "LSR rx error interrupt\n");
//     //     }
//     // }

//     LOGUART_INTConfig(LOGUART_DEV, LOGUART_BIT_ERBI | LOGUART_BIT_ETOI, ENABLE);
// }

void LOGUARTClass::begin(const uint32_t dwBaudRate, uint16_t serial_config_value) {
    //amb_ard_pin_check_fun(LOG_TX, PIO_UART);
    //amb_ard_pin_check_fun(LOG_RX, PIO_UART);
    LOGUART_InitTypeDef LOGUART_InitStruct;

    // Log, UART_LOG
    //serial_init(&log_uart_obj, PA_7, PA_8);
    //serial_init(&log_uart_obj, (PinName)g_APinDescription[LOG_TX].pinname, (PinName)g_APinDescription[LOG_RX].pinname);
    LOGUART_DiagInit(FALSE);

    // serial1, HS_UART0
    //serial_init(&uart_obj, PB_19, PB_18);
    //serial_init(&uart_obj, PA_21, PA_22);
    //serial_init(&uart_obj, PA_18, PA_19);
    //serial_init(&uart_obj, PinName(g_APinDescription[SERIAL1_TX].pinname), PinName(g_APinDescription[SERIAL1_RX].pinname));

    // serial2, LP_UART
    //serial_init(&uart_obj, PB_1, PB_2);
    //serial_init(&uart_obj, PA_26, PA_25);
    //serial_init(&uart_obj, PA_12, PA_13);
    //serial_init(&uart_obj, PinName(g_APinDescription[SERIAL2_TX].pinname), PinName(g_APinDescription[SERIAL2_RX].pinname));

    /*configure LOGUART according to the parameters*/
    LOGUART_StructInit(&LOGUART_InitStruct);
    switch (serial_config_value) {
//      case SERIAL_5N1:
//          break;
//      case SERIAL_6N1:
//          break;
        case SERIAL_7N1:
            LOGUART_InitStruct.WordLen = RUART_WLS_7BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_1;
            LOGUART_InitStruct.Parity = RUART_PARITY_DISABLE;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
        case SERIAL_8N1:
            LOGUART_InitStruct.WordLen = RUART_WLS_8BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_1;
            LOGUART_InitStruct.Parity = RUART_PARITY_DISABLE;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
//      case SERIAL_5N2:
//          break;
//      case SERIAL_6N2:
//          break;
        case SERIAL_7N2:
            LOGUART_InitStruct.WordLen = RUART_WLS_7BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_2;
            LOGUART_InitStruct.Parity = RUART_PARITY_DISABLE;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
        case SERIAL_8N2:
            LOGUART_InitStruct.WordLen = RUART_WLS_8BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_2;
            LOGUART_InitStruct.Parity = RUART_PARITY_DISABLE;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
//      case SERIAL_5E1:
//          break;
//      case SERIAL_6E1:
//          break;
        case SERIAL_7E1:
            LOGUART_InitStruct.WordLen = RUART_WLS_7BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_1;
            LOGUART_InitStruct.Parity = RUART_PARITY_ENABLE;
            LOGUART_InitStruct.ParityType = RUART_EVEN_PARITY;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
        case SERIAL_8E1:
            LOGUART_InitStruct.WordLen = RUART_WLS_8BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_1;
            LOGUART_InitStruct.Parity = RUART_PARITY_ENABLE;
            LOGUART_InitStruct.ParityType = RUART_EVEN_PARITY;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
//      case SERIAL_5E2:
//          break;
//      case SERIAL_6E2:
//          break;
        case SERIAL_7E2:
            LOGUART_InitStruct.WordLen = RUART_WLS_7BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_2;
            LOGUART_InitStruct.Parity = RUART_PARITY_ENABLE;
            LOGUART_InitStruct.ParityType = RUART_EVEN_PARITY;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
        case SERIAL_8E2:
            LOGUART_InitStruct.WordLen = RUART_WLS_8BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_2;
            LOGUART_InitStruct.Parity = RUART_PARITY_ENABLE;
            LOGUART_InitStruct.ParityType = RUART_EVEN_PARITY;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
//      case SERIAL_5O1:
//          break;
//      case SERIAL_6O1:
//          break;
        case SERIAL_7O1:
            LOGUART_InitStruct.WordLen = RUART_WLS_7BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_1;
            LOGUART_InitStruct.Parity = RUART_PARITY_ENABLE;
            LOGUART_InitStruct.ParityType = RUART_ODD_PARITY;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
        case SERIAL_8O1:
            LOGUART_InitStruct.WordLen = RUART_WLS_8BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_1;
            LOGUART_InitStruct.Parity = RUART_PARITY_ENABLE;
            LOGUART_InitStruct.ParityType = RUART_ODD_PARITY;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
//      case SERIAL_5O2:
//          break;
//      case SERIAL_6O2:
//          break;
        case SERIAL_7O2:
            LOGUART_InitStruct.WordLen = RUART_WLS_7BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_2;
            LOGUART_InitStruct.Parity = RUART_PARITY_ENABLE;
            LOGUART_InitStruct.ParityType = RUART_ODD_PARITY;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
        case SERIAL_8O2:
            LOGUART_InitStruct.WordLen = RUART_WLS_8BITS;
            LOGUART_InitStruct.StopBit = RUART_STOP_BIT_2;
            LOGUART_InitStruct.Parity = RUART_PARITY_ENABLE;
            LOGUART_InitStruct.ParityType = RUART_ODD_PARITY;
            LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
            break;
//      case SERIAL_511:
//          break;
//      case SERIAL_611:
//          break;
        // case SERIAL_711:
        //     serial_format(&log_uart_obj, 7, ParityForced1, 1);
        //     break;
        // case SERIAL_811:
        //     serial_format(&log_uart_obj, 8, ParityForced1, 1);
        //     break;
//      case SERIAL_512:
//          break;
//      case SERIAL_612:
//          break;
        // case SERIAL_712:
        //     serial_format(&log_uart_obj, 7, ParityForced1, 2);
        //     break;
        // case SERIAL_812:
        //     serial_format(&log_uart_obj, 8, ParityForced1, 2);
        //     break;
//      case SERIAL_501:
//          break;
//      case SERIAL_601:
//          break;
        // case SERIAL_701:
        //     serial_format(&log_uart_obj, 7, ParityForced0, 1);
        //     break;
        // case SERIAL_801:
        //     serial_format(&log_uart_obj, 8, ParityForced0, 1);
        //     break;
//      case SERIAL_502:
//          break;
//      case SERIAL_602:
//          break;
        // case SERIAL_702:
        //     serial_format(&log_uart_obj, 7, ParityForced0, 2);
        //     break;
        // case SERIAL_802:
        //     serial_format(&log_uart_obj, 8, ParityForced0, 2);
        //     break;
      default:
        LOGUART_InitStruct.WordLen = RUART_WLS_8BITS;
        LOGUART_InitStruct.StopBit = RUART_STOP_BIT_1;
        LOGUART_InitStruct.Parity = RUART_PARITY_DISABLE;
        LOGUART_InitStruct.StickParity = RUART_STICK_PARITY_DISABLE;
        break;
    }

//     uint32_t LOGUART_BaudRate = dwBaudRate;

// #if LOG_UART_MODIFIABLE_BAUD_RATE
//     /* log uart initialize in 115200 baud rate.
//      * If we change baud rate here, Serail Monitor would not detect this change and show nothing on screen.
//      */
//     //serial_baud(&log_uart_obj, dwBaudRate);
//     serial_baud(&log_uart_obj, LOGUART_BaudRate);
// #else
//     LOGUART_BaudRate = 115200;
//     serial_baud(&log_uart_obj, LOGUART_BaudRate);
// #endif

    LOGUART_WaitTxComplete();

    /* configure word length, stop bit, parity, parity type, stickparity */
    LOGUART_DEV->LOGUART_UART_LCR = ((LOGUART_InitStruct.WordLen) |
                                     (LOGUART_STB(LOGUART_InitStruct.StopBit)) |
                                     (LOGUART_PEN(LOGUART_InitStruct.Parity)) |
                                     (LOGUART_EPS(LOGUART_InitStruct.ParityType)) |
                                     (LOGUART_STKP(LOGUART_InitStruct.StickParity)));

    /* reconfigure LOGUART baudrate according to the parameters */
    LOGUART_SetBaud(LOGUART_DEV, dwBaudRate);

    /* interrupt in AP can't be enabled when NP interrupt is still enable */
	LOGUART_INT_NP2AP();
    /* arrange Uart IRQ Number and handler */
    InterruptDis(UART_LOG_IRQ);
    InterruptUnRegister(UART_LOG_IRQ);
    InterruptRegister((IRQ_FUN)arduino_loguart_irq_handler, UART_LOG_IRQ, (uint32_t)_rx_buffer, INT_PRI_MIDDLE);
    InterruptEn(UART_LOG_IRQ, INT_PRI_MIDDLE);
    LOGUART_INTConfig(LOGUART_DEV, LOGUART_BIT_ERBI | LOGUART_BIT_ETOI, ENABLE);
}

void LOGUARTClass::end(void) {
    // clear any received data
    _rx_buffer->_iHead = _rx_buffer->_iTail;

    // serial_free(&log_uart_obj);
}

int LOGUARTClass::available(void) {
  return (uint32_t)(SERIAL_BUFFER_SIZE + _rx_buffer->_iHead - _rx_buffer->_iTail) % SERIAL_BUFFER_SIZE;
}

int LOGUARTClass::peek(void) {
    if (_rx_buffer->_iHead == _rx_buffer->_iTail)
        return -1;

    return _rx_buffer->_aucBuffer[_rx_buffer->_iTail];
}

int LOGUARTClass::read(void) {
    // if the head isn't ahead of the tail, we don't have any characters
    if (_rx_buffer->_iHead == _rx_buffer->_iTail) {
        return -1;
    }

    uint8_t uc = _rx_buffer->_aucBuffer[_rx_buffer->_iTail];
    _rx_buffer->_iTail = (unsigned int)(_rx_buffer->_iTail + 1) % SERIAL_BUFFER_SIZE;
    return uc;
}

void LOGUARTClass::flush(void) {
    LOGUART_WaitTxComplete();
}

size_t LOGUARTClass::write(const uint8_t uc_data) {
    LOGUART_PutChar(uc_data);
    return 1;
}

LOGUARTClass Serial(UART_LOG_IRQ, &rx_buffer0);

bool Serial_available() {
    return Serial.available() > 0;
}
