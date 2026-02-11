/*
 This sketch shows how to use hardware timer and invoke interrupt handler periodically

 Example guide:
 https://www.amebaiot.com/en/amebad-arduino-periodic-timer/
 */

#include <GTimer.h>

int counter = 0;
int id;

void myhandler(uint32_t data) {
    counter++;
    Serial.print("counter: ");
    Serial.println(counter);
    if (counter >= 10) {
        Serial.println("stop timer");
        GTimer.stop(id);
    }
}

void setup() {
    // Open serial communications and wait for port to open:
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    // period 1s, invoke myhander
    id = GTimer.begin(1 * 1000 * 1000, myhandler);
    if (id < 0) {
        Serial.println("No free resource!");
    }
}

void loop() {
    delay(1000);
}
