/*
 * This example describes how to use watchdog api.
 * In this example, watchdog is setup to 5s timeout.
 * Watchdog won't bark if we refresh it before timeout in smallTask.
 * The timer is also reloaded after refresh.
 * Otherwise, while running bigTask, watchdog will restart system in default or call callback function if registered.

 * Example guide:
 * https://www.amebaiot.com/en/amebad-arduino-watchdog/
 */

#include "WDT.h"

#define RUN_CALLBACK_IF_WATCHDOG_BARKS (0)
WDT wdt;

static uint32_t my_watchdog_irq_handler(void *data) {
    (void)data;

    Serial.println("watchdog barks!!!");
    wdt.RefreshWatchdog();

    return 0;
}

static void Small_Task(void) {
    Serial.println("......doing small task......");
    delay(1000);
    Serial.println("Small_Task finished refresh watchdog.");
    wdt.RefreshWatchdog();
}

/* If Big_Task unable to reach #10, watchdog barks. */
static void Big_Task(void) {
    Serial.println("......doing big task, up to 10......");
    for (int i = 1; i <= 10; i++) {
        Serial.print("doing dummy task #");
        Serial.println(i, DEC);

        delay(1000);
    }
    Serial.println("Big_Task finished refresh watchdog.");
    wdt.RefreshWatchdog();
}

void setup() {
    Serial.begin(115200);
    wdt.InitWatchdog(5000);  // setup 5s watchdog

#if RUN_CALLBACK_IF_WATCHDOG_BARKS
    wdt.InitWatchdogIRQ(my_watchdog_irq_handler, NULL);
#else
    // system would restart in default when watchdog barks
#endif

    wdt.StartWatchdog();  // enable watchdog timer
    Small_Task();
    Big_Task();
    while(1);
}

void loop() {
    delay(1000);
}
