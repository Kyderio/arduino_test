/*
 This sketch shows how to use several hardware timers in invoke handler only once for each timer.

 Example guide:
 https://www.amebaiot.com/en/amebad-arduino-singleuse-timer/
 */

#include <GTimer.h>

int id0, id1;

void myhandler(uint32_t data) {
    Serial.print("I am timer!");
    Serial.println(data);
}

void setup() {
    // Open serial communications and wait for port to open:
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    // timerid 0, period 1s, invoke myhandler, invoke only once, user data is 0
    id0 = GTimer.begin(1 * 1000 * 1000, myhandler, false, 0);
    if (id0 < 0) {
        Serial.println("No free resource!");
    }

    // timerid 1, period 2s, invoke myhandler, invoke only once, user data is 1
    id1 = GTimer.begin(2 * 1000 * 1000, myhandler, false, 1);
    if (id1 < 0) {
        Serial.println("No free resource!");
    }
}

void loop() {
    delay(1000);
}
