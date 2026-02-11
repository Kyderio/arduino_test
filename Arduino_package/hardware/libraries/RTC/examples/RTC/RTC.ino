/*
 * This function describes how to use the RTC API.
 * The RTC function is implemented by an independent BCD timer/counter.
 * This example will print out the time information every second.

 * Example guide:
 * https://www.amebaiot.com/en/amebad-arduino-rtc/
 */

#include "rtc.h"

/* Change these values to set the current initial date */
#define YEAR 2026
#define MONTH 1
#define DAY 1
/* Change these values to set the current initial time */
#define HOUR 13
#define MINUTE 14
#define SECOND 15

/* Create an rtc object */
RTC rtc;
time_t seconds;
struct tm *timeinfo;

void printEpochTime(void) {
    Serial.print("Epoch Time(in s) since January, 1, 1970:");
    Serial.print(seconds);
    Serial.print("s");
}

void printBasicString(void) {
    Serial.println();
    Serial.print("Time as a basic string:                  ");
    Serial.print(ctime(&seconds));
}

void printStringTime(void) {
    timeinfo = localtime(&seconds);
    Serial.print("Time as a custom formatted string:       ");
    Serial.print(timeinfo->tm_year + 1900);
    Serial.print("-");
    Serial.print(timeinfo->tm_mon + 1);
    Serial.print("-");
    Serial.print(timeinfo->tm_mday);
    Serial.print(" ");
    Serial.print(timeinfo->tm_hour);
    Serial.print(":");
    Serial.print(timeinfo->tm_min);
    Serial.print(":");
    Serial.println(timeinfo->tm_sec);
}

void setup() {
    Serial.begin(115200);
    rtc.Init(); 
    int epochTime = rtc.SetEpoch(YEAR, MONTH, DAY, HOUR, MINUTE, SECOND);
    rtc.Write(epochTime);
}

void loop() {
    seconds = rtc.Read();
    printEpochTime();
    printBasicString();
    printStringTime();
    Serial.println("----------------------------------------------------------------------");
    rtc.Wait(1);
}
