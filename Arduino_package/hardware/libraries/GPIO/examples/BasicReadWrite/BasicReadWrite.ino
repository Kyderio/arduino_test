/*
 This example shows how to use GPIO for basic read and write
 */

#include <Arduino.h>

int ledPin = 2;   // LED connected to digital pin 2
int inPin = 3;    // pushbutton connected to digital pin 3
int val = 0;      // variable to store the read value

void setup() {
    pinMode(ledPin, OUTPUT);  // sets the digital pin 2 as output
    pinMode(inPin, INPUT);    // sets the digital pin 3 as input
}

void loop() {    
    val = digitalRead(inPin);   // read the input pin
    digitalWrite(ledPin, val);  // sets the LED to the button's value

	delay(1000);
}