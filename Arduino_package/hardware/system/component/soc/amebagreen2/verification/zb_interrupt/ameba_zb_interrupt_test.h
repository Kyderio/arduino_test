#ifndef _AMEBA_ZB_INT_TEST_H_
#define _AMEBA_ZB_INT_TEST_H_

extern u32 CoexHwTest(IN u16 argc, IN u8  *argv[]);
extern void Wifi2BtScoreboardTest(u16 argc, u8 *argv[]);
extern void Bt2WifiSBCDedicatedTest(void);
extern void Bt2WifiSBCDedicatedTestHandler(void);
extern void BtWakeHostTestHandler(void);

#endif