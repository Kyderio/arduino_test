#ifndef __WIFIFW_SERIAL_IO_H__
#define __WIFIFW_SERIAL_IO_H__

#define TXBUF_SIZE  256      /* DO NOT CHANGE */
#define RXBUF_SIZE  15      /* DO NOT CHANGE */

#define UART_LOG_HISTORY_ENTRY  8

typedef struct {
	u8  BufCount;                           //record the input cmd char number.
	u8  UARTLogBuf[UART_LOG_CMD_BUFLEN];   //record the input command.
} FW_UART_LOG_BUF, *PFW_UART_LOG_BUF;

typedef struct {
	u8 historyNum;
	u8 wrPtr;
	u8 rdPtr;
	u8 historyBuf[UART_LOG_HISTORY_ENTRY][UART_LOG_CMD_BUFLEN + 1];
} FW_HISTORY_BUF, *PFW_HISTORY_BUF;

typedef struct _FW_COMMAND_TABLE_ {
	const    u8 *cmd;
	u8       ArgvCnt;
	void (*func)(u16 argc, const char *argv[]);
	const    u8 *msg;
} FW_COMMAND_TABLE, *PFW_COMMAND_TABLE;

typedef struct {
	u8  NewIdx;
	u8  SeeIdx;
	u8  RevdNo;
	u8  EscSTS;
	u8  ExecuteCmd;
	u8  ExecuteEsc;
	u8  Resvd;
	PFW_UART_LOG_BUF   pTmpLogBuf;
	PFW_HISTORY_BUF    pTmpHistoryBuf;
	PFW_COMMAND_TABLE  pCmdTbl;
	u32 CmdTblSz;
} FW_UART_LOG_CTL, *PFW_UART_LOG_CTL;

extern int _strcmp(const char *cs, const char *ct);
extern void FwRtlConsolInit(u16 TBLSz, void *pTBL);

#endif /* __WIFIFW_SERIAL_IO_H__ */
