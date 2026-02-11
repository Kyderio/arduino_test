#include "rtc.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "ameba_soc.h"

#ifdef __cplusplus
}
#endif

static alarm_irq_handler rtc_alarm_handler;

static const u8 dim[12] = {
    31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

/**
  * @brief  Judge whether a year is a leap year or not.
  * @param  year: Actual year - 1900.
  * @return Result.
  * @retval 1: This year is a leap year.
  * @retval 0: This year is not a leap year.
  */
static inline bool is_leap_year(unsigned int year)
{
    u32 full_year = year + 1900;
    return (!(full_year % 4) && (full_year % 100)) || !(full_year % 400);
}

/**
  * @brief  Calculate total days in a specified month of a specified year.
  * @param  year: Actual year - 1900.
  * @param  month: Specified the number of months from  a specified year.
  * @note 0 represents January.
  * @return Number of days in the month of the year.
  */
static u8 days_in_month(u8 month, u8 year)
{
    u8 ret = dim[month % 12];
    if (ret == 0) {
        ret = is_leap_year(year + month / 12) ? 29 : 28;
    }
    return ret;
}

/**
  * @brief  Calculate month and day of the month according to year and day of the year.
  * @param  year: Actual year - 1900.
  * @param  yday: Day of the year.
  * @param  mon: Pointer to the variable that stores month, which can be 0~11.
  * @note 0 represents January.
  * @param  mday: Pointer to the variable that stores day of month, which can be 1~31.
  * @retval none
  */
static void calculate_mday(int year, int yday, int *mon, int *mday)
{
    int t_mon = -1, t_yday = yday + 1;

    while (t_yday > 0) {
        t_mon ++;
        t_yday -= days_in_month(t_mon, year);
    }

    *mon = t_mon;
    *mday = t_yday + days_in_month(t_mon, year);
}

/**
  * @brief  Disable RTC Alarm.
  * @param  none
  * @retval   none
  */
static void disable_alarm(void)
{
    InterruptDis(RTC_IRQ);
    InterruptUnRegister(RTC_IRQ);
    RTC_AlarmCmd(DISABLE);

    rtc_alarm_handler = NULL;
}

/**
  * @brief  Register RTC alarm interrupt handler.
  * @param  data: RTC IRQ callback data.
  * @retval 0
  */
static uint32_t alarm_intr_handler(void *data)
{
    /* To avoid gcc warnings */
    (void) data;

    alarm_irq_handler hdl;

    /*clear alarm flag*/
    RTC_AlarmClear();

    /* execute user handler*/
    if (rtc_alarm_handler != NULL) {
        hdl = rtc_alarm_handler;
        hdl();
    }

    /*disable alarm*/
    disable_alarm();

    return 0;
}

/**
  * @brief  Initializes the RTC device, include clock, RTC registers and function.
  * @param  none
  * @retval  none
  */
void RTC::Init(void) {
    RTC_InitTypeDef RTC_InitStruct;

    RCC_PeriphClockCmd(NULL, APBPeriph_RTC_CLOCK, ENABLE);
    RTC_Enable(ENABLE);

    RTC_StructInit(&RTC_InitStruct);
    RTC_InitStruct.RTC_HourFormat = RTC_HourFormat_24;
    RTC_Init(&RTC_InitStruct);

    rtc_en = true;
}

/**
  * @brief  Deinitializes the RTC device.
  * @param  none
  * @retval  none
  */
void RTC::DeInit(void) {
    RTC_Enable(DISABLE);
    RCC_PeriphClockCmd(NULL, APBPeriph_RTC_CLOCK, DISABLE);
    rtc_en = false;
    rtc_alarm_handler = NULL;
}

/**
  * @brief  Set the specified timestamp in seconds to RTC.
  * @param  t: Seconds from 1970.1.1 00:00:00 to specified data and time
  *              which is to be set.
  * @retval  none
  */
void RTC::Write(time_t t) {
    struct tm *timeinfo = localtime(&t);
    RTC_TimeTypeDef RTC_TimeStruct;

    /*set time in RTC */
    RTC_TimeStructInit(&RTC_TimeStruct);
    RTC_TimeStruct.RTC_H12_PMAM = RTC_H12_AM;
    RTC_TimeStruct.RTC_Year = timeinfo->tm_year + 1900;
    RTC_TimeStruct.RTC_Days = timeinfo->tm_yday;
    RTC_TimeStruct.RTC_Hours = timeinfo->tm_hour;
    RTC_TimeStruct.RTC_Minutes = timeinfo->tm_min;
    RTC_TimeStruct.RTC_Seconds = timeinfo->tm_sec;
    RTC_SetTime(RTC_Format_BIN, &RTC_TimeStruct);
}

/**
  * @brief  Get current timestamp in seconds from RTC.
  * @param  none
  * @retval value: The current timestamp in seconds which is calculated from 
  *              1970.1.1 00:00:00.
  */
time_t RTC::Read(void) {
    time_t t;
    struct tm tm_temp;
    RTC_TimeTypeDef RTC_TimeStruct;
    u32 ydays_thr = 0;

    memset(&tm_temp, 0x00, sizeof(struct tm));

    RTC_GetTime(RTC_Format_BIN, &RTC_TimeStruct);
    /*hour, min, sec get from RTC*/
    tm_temp.tm_sec = RTC_TimeStruct.RTC_Seconds;
    tm_temp.tm_min = RTC_TimeStruct.RTC_Minutes;
    tm_temp.tm_hour = RTC_TimeStruct.RTC_Hours;

    tm_temp.tm_yday = RTC_TimeStruct.RTC_Days;
    tm_temp.tm_year = RTC_TimeStruct.RTC_Year - RTC_BASE_YEAR; //struct tm start from 1900

    calculate_mday(tm_temp.tm_year, tm_temp.tm_yday, &tm_temp.tm_mon, &tm_temp.tm_mday);

    /* Convert to timestamp(seconds from 1970.1.1 00:00:00)*/
    t = mktime(&tm_temp);

    ydays_thr = (is_leap_year(RTC_TimeStruct.RTC_Year)) ? 366 : 365;
    //    printf("@@@%d calc%d thr%d reg%d\n", __LINE__, tm_temp.tm_year, ydays_thr, RTC_TimeStruct.RTC_Days);

    if (RTC_TimeStruct.RTC_Days > (ydays_thr - 1)) {
        RTC_TimeStruct.RTC_Days -= ydays_thr;
        RTC_TimeStruct.RTC_Year++;

        RTC_SetTime(RTC_Format_BIN, &RTC_TimeStruct);
    }

    return t;
}

/**
  * @brief  Wait for 1000000 us / 1s.
  */
void RTC::Wait(float s) {
    DelayUs((int)(s * 1000000.0f));
}

/**
 * @brief: convert human readable time to epoch time
*/
int RTC::SetEpoch(int year, int month, int day, int hour, int min, int sec) {
    struct tm t;
    time_t t_of_day;

    t.tm_year = year - 1900;  // Year - 1970
    t.tm_mon = month - 1;     // Month, where 0 = jan
    t.tm_mday = day;          // Day of the month
    t.tm_hour = hour;
    t.tm_min = min;
    t.tm_sec = sec;
    t.tm_isdst = -1;  // Is DST on? 1 = yes, 0 = no, -1 = unknown
    t_of_day = mktime(&t);

    // printf("seconds since the Epoch: %d\n", (long)t_of_day);
    return t_of_day;
}

/**
  * @brief  Set the specified RTC Alarm and interrupt.
  * @param  alarm: Alarm object defined in application software.
  * @param  alarmHandler:  Alarm interrupt callback function.
  * @return Status. It can be one of the following values:
  * @retval 0: Success.
  * @retval Others: Error.
  */
int RTC::SetAlarm(alarm_t *alrm, alarm_irq_handler alarmHandler) {
    RTC_AlarmTypeDef RTC_AlarmStruct_temp;

    rtc_alarm_handler = alarmHandler;

    /* set alarm */
    RTC_AlarmStructInit(&RTC_AlarmStruct_temp);
    RTC_AlarmStruct_temp.RTC_AlarmTime.RTC_H12_PMAM = RTC_H12_AM;
    RTC_AlarmStruct_temp.RTC_AlarmTime.RTC_Days = alrm->yday;
    RTC_AlarmStruct_temp.RTC_AlarmTime.RTC_Hours = alrm->hour;
    RTC_AlarmStruct_temp.RTC_AlarmTime.RTC_Minutes = alrm->min;
    RTC_AlarmStruct_temp.RTC_AlarmTime.RTC_Seconds = alrm->sec;

    /* if specific Alarm interrupt is needed, the other matched time can be masked */
    RTC_AlarmStruct_temp.RTC_AlarmMask = RTC_AlarmMask_None;
    RTC_AlarmStruct_temp.RTC_Alarm2Mask = RTC_Alarm2Mask_None;

    RTC_SetAlarm(RTC_Format_BIN, &RTC_AlarmStruct_temp);

    RTC_AlarmCmd(ENABLE);
    InterruptRegister((IRQ_FUN)alarm_intr_handler, RTC_IRQ, NULL, 5);
    InterruptEn(RTC_IRQ, 5);

    return 0;
}

/**
  * @brief  Judge whether RTC is enabled or not.
  * @param  none
  * @return RTC status. It can be one of the following values:
  * @retval true: RTC has been enabled.
  * @retval false: RTC has not been enabled.
  */
bool RTC::IsEnabled(void)
{
	return rtc_en;
}
