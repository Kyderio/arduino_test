#ifndef _WDT_H_
#define _WDT_H_

#include <Arduino.h>

typedef uint32_t (*WDTIrqHandler)(void *data);

class WDT {
    public:
        WDT(void) {}
        ~WDT(void) {}

        void InitWatchdog(uint32_t timeout_ms);
        void StartWatchdog(void);
        void StopWatchdog(void);
        void RefreshWatchdog(void);
        void InitWatchdogIRQ(WDTIrqHandler handler, void *data);
};
#endif
