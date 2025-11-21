
#ifndef EXAMPLE_CONFIG_H
#define EXAMPLE_CONFIG_H 1

// 802.15.4 channel used by Zigbee  <11-26> Defaults to 16.
#define ZIGBEE_CHANNEL 16

// Trace level of Zigbee stack logs.  <0-4> Possible values: 0 - disable, 1 - error, 2 - warning, 3 - info, 4 - debug. Disabled by default.
#define ZIGBEE_TRACE_LEVEL 3

// Trace mask of Zigbee stack logs.  <0-2376>
// Selectively enable Zigbee binary trace logs.
// Possible values (logical or): TRACE_SUBSYSTEM_ZCL, TRACE_SUBSYSTEM_ZDO, TRACE_SUBSYSTEM_NWK. Defaults to 0x0000.
#define ZIGBEE_TRACE_MASK 0x900

// Decide if erase persistent storage at start
#define ERASE_PERSISTENT_CONFIG ZB_TRUE

// Channel mask
#define ZIGBEE_CHANNEL_MASK (1<<ZIGBEE_CHANNEL)

// Endpoint id
#define ZIGBEE_ENDPOINT_ID  5


/* Finding and Binding time interval, in seconds */
#define ZB_FINDING_BINDING_TIMEOUT_S 240

// ZB_ERROR_PRINT_TO_LOG  - zb_error - ZBOSS error handling helpers
#ifndef ZB_ERROR_PRINT_TO_LOG
#define ZB_ERROR_PRINT_TO_LOG 1
#endif

// CONFIG_ZBOSS_RESET_ON_ASSERT - Reset device when a ZBOSS assert occurs  <0-1>
#ifndef CONFIG_ZBOSS_RESET_ON_ASSERT
#define CONFIG_ZBOSS_RESET_ON_ASSERT 1
#endif

// CONFIG_ZBOSS_HALT_ON_ASSERT - Halt device when a ZBOSS assert occurs. Use only for testing and debugging.  <0-1>
#ifndef CONFIG_ZBOSS_HALT_ON_ASSERT
#define CONFIG_ZBOSS_HALT_ON_ASSERT 0
#endif


#endif /* #define CUSTOM_CLUSTER_ZR_H */
