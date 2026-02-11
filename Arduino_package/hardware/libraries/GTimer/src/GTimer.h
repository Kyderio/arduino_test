#ifndef _GTIMER_H_
#define _GTIMER_H_

#include <Arduino.h>

#define GTIMER_NUM  2

typedef void (*GTimerHandler)(uint32_t);

typedef struct {
    GTimerHandler timeout_handler;
    uint32_t user_data;
    uint8_t tid;
    bool is_periodic;
    bool is_alloc;
} gtimer_resource;

/**
 * @class GTimerClass GTimer.h
 * @brief GTimer is a hardware timer and this class is to operate it
 *
 * @note The Gtimer occupy same resource as PWM. Please make sure the timer is not conflict with you pwm index.
 */
class GTimerClass {
public:
    GTimerClass(void) {};
    ~GTimerClass(void) {};
    /**
     * @brief Initialize a gtimer and start it immediately
     *
     * @param[in] duration_us The duration of timer. The time unit is microsecond and the precision is 32768Hz
     * @param[in] handler As timer timeout, it would invoke this handler.
     * @param[in] periodical By default the timer would keep periodicall countdown and reload which meas the handler would periodicall invoked.
     * @param[in] userdata The user data brings to the handler
     * 
     * @return >=0, The gtimer resource id
     *          -1, No free resource
     */
    int begin(uint32_t duration_us, void (*handler)(uint32_t), bool periodic = true, uint32_t userdata = 0);

    /**
     * @brief Stop and delete a specific gtimer
     *
     * @param[in] id Stop and delete the gtimer with this gtimer resource id
     */
    void end(uint32_t id);

    /**
     * @brief Stop a specific gtimer
     *
     * @param[in] id Stop the gtimer with this gtimer resource id
     */
    void stop(uint32_t id);

    /**
     * @brief Restart a specific gtimer
     *
     * @param[in] id Restart the gtimer with this gtimer resource id
     */
    void restart(uint32_t id);

    /**
     * @brief Reload a specific gtimer
     *
     * The GTimer is a countdown timer. Reload it would make it discard the current countdown value and restart countdown based on the duration.
     *
     * @param[in] id The gtimer resource to be modified
     * @param[in] duration_us The updated duration in unit of microseconds.
     */
    void reload(uint32_t id, uint32_t duration_us);

    /**
     * @brief Read current countdown time
     *
     * @param[in] id The gtimer resource to be read
     * @return The current countdown time in second
     */
    float read(uint32_t id);

    /**
     * @brief Read current countdown time
     *
     * @param[in] id The gtimer resource to be read
     * @return The current countdown time in millisecond
     */
    uint64_t readMs(uint32_t id);

    /**
     * @brief Read current countdown time
     *
     * @param[in] id The gtimer resource to be read
     * @return The current countdown time in microsecond
     */
    uint64_t readUs(uint32_t id);
};

extern GTimerClass GTimer;

#endif
