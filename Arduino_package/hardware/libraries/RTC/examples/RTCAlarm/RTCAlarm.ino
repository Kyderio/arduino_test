/*
 * This example demonstrate how to use the RTC library methods
 * in order to do something when an alarm is matched.
 * In particular in this example, the RTC time is set at 16:00:00 and an alarm at 16:00:10.
 * When the time match using the match type MATCH_HHMMSS is reached,
 * the attached interrupt function will print on the serial monitor Alarm Match!

 * Example guide:
 * https://www.amebaiot.com/en/amebad-arduino-rtc-alarm/
 */

#include "rtc.h"

/* Change these values to set the current initial date */
#define YEAR 2026
#define MONTH 1
#define DAY 1
/* Change these values to set the current initial time */
#define HOUR 16
#define MINUTE 0
#define SECOND 0
/* Change these values to set the alarm time */
#define ALARM_HOUR 16
#define ALARM_MIN 0
#define ALARM_SEC 10  // set alarm as 10 seconds

/* Create an rtc object */
RTC rtc;
alarm_t alarm;
time_t seconds;
struct tm *timeinfo;

void rtc_handler(void) {
    Serial.println("====   Alarm Matched   ====");
    rtc.DeInit();
}

void printStringTime(void) {
    timeinfo = localtime(&seconds);
    Serial.print("Time:       ");
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
    int initTime = rtc.SetEpoch(YEAR, MONTH, DAY, HOUR, MINUTE, SECOND);  // convert user time to seconds from 1970.1.1 00:00:00
    rtc.Write(initTime);

    // EnableAlarm(ALARM_HOUR, ALARM_MIN, ALARM_SEC);
    alarm.yday = 0;  //  default alarmDay to be zero
    alarm.hour = ALARM_HOUR;
    alarm.min = ALARM_MIN;
    alarm.sec = ALARM_SEC;
    rtc.SetAlarm(&alarm, rtc_handler);
}

void loop() {
    if (rtc.IsEnabled()) {
        seconds = rtc.Read();
        printStringTime();
        rtc.Wait(1);
    }
}
