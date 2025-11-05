#ifndef _AMEBA_MIPI_TEST_H_
#define _AMEBA_MIPI_TEST_H_

#define MIPI_PROTOCOL_TEST					DISABLE

#define REGFLAG_DELAY						0xFC
#define REGFLAG_END_OF_TABLE				0xFD	// END OF REGISTERS MARKER

#define Mhz									1000000UL
#define T_LPX		5
#define T_HS_PREP	6
#define T_HS_TRAIL	8
#define T_HS_EXIT	7
#define T_HS_ZERO	10

#if MIPI_PROTOCOL_TEST
#define MIPI_FRAME_RATE		50000

#define MIPI_DSI_RTNI		2//4
#define MIPI_DSI_HSA		4
#define MIPI_DSI_HBP		10
#define MIPI_DSI_HFP		30

#define MIPI_DSI_VSA		1
#define MIPI_DSI_VBP		2
#define MIPI_DSI_VFP		2
#else
#define MIPI_FRAME_RATE		60

#define MIPI_DSI_RTNI		2//4
#define MIPI_DSI_HSA		4
#define MIPI_DSI_HBP		30
#define MIPI_DSI_HFP		30

#define MIPI_DSI_VSA		5
#define MIPI_DSI_VBP		20
#define MIPI_DSI_VFP		15
#endif
/*=========MIPI IRQ Info=========*/
typedef struct MIPI_Irq {
	u32 IrqNum;
	u32 IrqData;
	u32 IrqPriority;
} MIPI_IRQInfo;

typedef struct {
	u8 dataid;
	u8 byte0;
	u8 byte1;
} cmd_header_t;

typedef struct LCM_setting_table {
	u8 cmd;
	u8 count;
	u8 para_list[128];
} LCM_setting_table_t;

extern MIPI_InitTypeDef MIPI_InitStruct_g;


#endif
