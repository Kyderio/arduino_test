/*
 This example shows how to use GPIO interrupt
 */

#include <Arduino.h>

const byte outputPin = 2;
const byte interruptPin = 3;  // input pin that the interruption will be attached to
volatile byte state = LOW;  // variable that will be updated in the ISR

void gpio_irq_handler(void)
{
    if (state) {
        Serial.println("Detect RISING edge");
    }
    else {
        Serial.println("Detect FALLING edge");
    }
}

void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }

    pinMode(outputPin, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), gpio_irq_handler, CHANGE);
}

void loop() {    
    digitalWrite(outputPin, state);
    state = !state;

    delay(1000);
}
