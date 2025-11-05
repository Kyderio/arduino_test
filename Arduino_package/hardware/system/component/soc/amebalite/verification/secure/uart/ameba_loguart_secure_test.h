#ifndef _RTL8721D_UART_TEST_H_
#define _RTL8721D_UART_TEST_H_

u8 LOGUART_GetChar_s(LOGUART_TypeDef *UARTLOG_DEV, bool PullMode);
void LOGUART_PutChar_s(LOGUART_TypeDef *UARTLOG_DEV, u8 c);
_LONG_CALL_ u32 printf_p(IN  const char *fmt, ...);

#define DBG_AMEBA_SEC(...)     do {\
		if (unlikely(ConfigDebug[LEVEL_ERROR] & BIT(MODULE_MISC))) \
			printf_p("[amebaLite]#\r" __VA_ARGS__);\
	}while(0)

#define printf DBG_AMEBA_SEC

#endif
