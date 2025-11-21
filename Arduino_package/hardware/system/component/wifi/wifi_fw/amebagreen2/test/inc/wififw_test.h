#ifndef __TEST_H__
#define __TEST_H__

#define CONFIG_LPS_PG_HIOE 1

#ifdef CONFIG_LPS_PG_TEST
#if CONFIG_LPS_PG_TEST
#define LPSPG_En  1
#else
#define LPSPG_En  0
#endif
#endif

#define memory_pwr_mode_nml	0
#define memory_pwr_mode_nap	1
#define memory_pwr_mode_ret	2
#define memory_pwr_mode_slp	3

#define TSFIS32K                        1
#define TSFIS40M                        0
#define WAIT_TSF_STABLE_BREAK_CNT       (5000)
#define WAIT_TSF_STABLE_CNT             (50)
#define WAIT_TSF_STABLE_ONCE_TIME       (20)
#define GET_TSF_STATE() ((HAL_READ16(WIFI_REG_BASE, REG_TSF_CLK_STATE) & BIT_CLK_TSF_IS32K) ? TSFIS32K : TSFIS40M)

extern void FwCmdRomHelp(u16 argc, const char  *argv[]);
extern void FwCmdBufTest(u16 argc, const char  *argv[]);
extern void FwCmdRegTest(u16 argc, const char  *argv[]);
extern void FwCmdIntTest(u16 argc, const char  *argv[]);
extern void FwCmdIOPATH(u16   argc, const char  *argv[]);
extern void CmdFwLbkTest(u16 argc, const char *argv[]);
extern void FwCmdCoexTest(u16 argc, const char *argv[]);
extern void GTimer1WKTest(void);
extern void BcnelyWKTest(void);
extern void LPSPGOperation(void);
extern void LPSPG_In(void);
extern void LPSPG_Out(void);
extern void Fw_test_main(void);

#endif      /* #ifndef __TEST_H__ */
