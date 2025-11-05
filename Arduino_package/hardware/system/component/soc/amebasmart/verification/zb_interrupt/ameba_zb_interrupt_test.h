#ifndef _AMEBA_ZB_INT_TEST_H_
#define _AMEBA_ZB_INT_TEST_H_

#define ZIGBEE_REG_BASE			0x400F3C00
#define ZIGBEE_PURE_REG			(ZIGBEE_REG_BASE/*+0x1800*/)
#define ZIGBEE_ISR 				0xC
#define ZIGBEE_IMR 				0x10

#define CFG_KM4_RCV_WLAN_INT	0
#define CFG_KM4_RCV_SCB_INT		0
#define CFG_KM4_RCV_MAIL_INT	0

#undef	SYSTEM_CTRL_BASE
#define SYSTEM_CTRL_BASE		0x42008000

extern u32 CoexHwTest(IN u16 argc, IN u8  *argv[]);
extern void Wifi2ZigbeeIntTest(void);
extern void Wifi2ZigbeePTAIntHandler(void);
extern void Zigbee2WifiMailboxTest(u16 argc, u8 *argv[]);
#if CFG_KM4_RCV_WLAN_INT
extern void Zigbee2WifiMailboxIntTest(void);
extern void Zigbee2WifiMailboxIntTestHandler(void);
#endif
extern void BTuseWLAFE_PowerSeq(void);
extern void BT_pinmux(void);
extern void BTuseEXT_Uart(void);
#if CFG_KM4_RCV_MAIL_INT
extern void Wifi2BtMailboxTest(u16 argc, u8 *argv[]);
extern void FillBTMailbox(u8 cmd, u8 length, u8 *pparm);
extern void Bt2WifiMailboxTest(void);
extern void Bt2WifiMailboxTestHandler(void);
#endif
extern void Wifi2BtScoreboardTest(u16 argc, u8 *argv[]);
#if CFG_KM4_RCV_SCB_INT
extern void Bt2WifiScoreboardTest(void);
extern void Bt2WifiScoreboardTestHandler(void);
#endif
extern void Bt2WifiSCBDedicatedTest(void);
extern void Bt2WifiSCBDedicatedTestHandler(void);
extern void ClrAllFWUsedIMR(void);
extern void ClrAllFWUsedISR(void);

#endif
