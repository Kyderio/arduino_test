#ifndef __RTC_H__
#define __RTC_H__

#include <Arduino.h>

typedef struct alarm_s {
    uint32_t yday;  //which day of the year
    uint32_t hour;
    uint32_t min;
    uint32_t sec;
} alarm_t;

typedef void (*alarm_irq_handler)(void);

class RTC {
    public:
        RTC(void) {}
        ~RTC(void) {}
        void Init(void);
        void DeInit(void);
        void Write(time_t t);
        time_t Read(void);
        void Wait(float s);
        int SetEpoch(int year, int month, int day, int hour, int min, int sec);
        int SetAlarm(alarm_t *alrm, alarm_irq_handler alarmHandler);
        bool IsEnabled(void);

    private:
        bool rtc_en;
};
#endif
