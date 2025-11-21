/*
 This example prints MAC address, and
 scans for available Wifi networks.
 Every ten seconds, it scans again. It doesn't actually
 connect to any network, so no encryption scheme is specified.

 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 21 Junn 2012
 by Tom Igoe and Jaymes Dec

 modified 08 May 2023
 by Realtek SG

 Example guide:
 https://www.amebaiot.com/en/amebad-arduino-scan-wifi/
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
