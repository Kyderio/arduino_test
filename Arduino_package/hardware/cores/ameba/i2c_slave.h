#include "i2c_api.h"
#include "os_wrapper.h"

void I2CISRHandle(void *Data);


typedef void (*i2c_slave_request_cb_t) (void * arg);
typedef void (*i2c_slave_receive_cb_t) (uint8_t * data, size_t len, /*bool stop, */void * arg);


typedef struct i2c_slave_struct_t {
    i2c_t *i2c_slave_dev;
    void *arg;
	uint32_t tx_datalength;
    uint32_t rx_datalength;
	// uint32_t event_status;
    i2c_slave_request_cb_t rqst_callback;
    i2c_slave_receive_cb_t recv_callback;
    rtos_task_t task_handle;
    rtos_queue_t event_queue;
    uint8_t *rx_buffer;
    // rtos_queue_t rx_queue;
    // rtos_queue_t tx_queue;
	// SemaphoreHandle_t event_sema;
} i2c_slave_struct_t;


typedef enum {
	I2C_SLAVE_NO_EVENT = 0,
	I2C_SLAVE_RX_EVENT, 
	I2C_SLAVE_TX_EVENT
} i2c_slave_event_enum_t;


typedef struct {
    i2c_slave_event_enum_t event;
    uint32_t param;
	// bool stop;
} i2c_slave_queue_event_t;


bool i2c_slave_init(i2c_t *obj, PinName SDA, PinName SCL, uint8_t addr, int hz, uint8_t *rxBuffer);
void i2c_slave_attach_callbacks(i2c_slave_request_cb_t onRequestService, i2c_slave_receive_cb_t onReceiveService, void * arg);
bool i2cSlaveWrite(const uint8_t *buffer, size_t len, uint32_t timeout);

