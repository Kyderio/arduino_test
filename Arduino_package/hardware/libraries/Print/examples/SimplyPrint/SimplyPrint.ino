/*
 This example only print Hello Arduino every 1s.
 */

#include <Arduino.h>

void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
}

void loop() {
    Serial.println("Hello Arduino!!");
    delay(1000);
}
