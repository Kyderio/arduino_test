

#ifndef EXAMPLE_CONFIG_H
#define EXAMPLE_CONFIG_H

// <h> None

//==========================================================
// <h> zigbee_osif - Osif layer for ZBOSS stack

//==========================================================
// <o> ZIGBEE_CHANNEL - 802.15.4 channel used by Zigbee  <11-26>


// <i> 802.15.4 channel used by Zigbee. Defaults to 16.

#ifndef ZIGBEE_CHANNEL
#define ZIGBEE_CHANNEL 16
#endif

// <o> ZIGBEE_TRACE_LEVEL - Trace level of Zigbee stack logs.  <0-4>


// <i> Trace level of Zigbee stack binary logs. Possible values: 0 - disable, 1 - error, 2 - warning, 3 - info, 4 - debug. Disabled by default.

#ifndef ZIGBEE_TRACE_LEVEL
#define ZIGBEE_TRACE_LEVEL 4
#endif

// <o> ZIGBEE_TRACE_MASK - Trace mask of Zigbee stack logs.  <0-2376>


// <i> Selectively enable Zigbee binary trace logs. Possible values (logical or): TRACE_SUBSYSTEM_ZCL, TRACE_SUBSYSTEM_ZDO, TRACE_SUBSYSTEM_NWK. Defaults to 0x0000.

#ifndef ZIGBEE_TRACE_MASK
#define ZIGBEE_TRACE_MASK 0x40
#endif



// </h>
//==========================================================

// </h>
//==========================================================

// <h> Zigbee

//==========================================================
// <q> ZB_ERROR_PRINT_TO_LOG  - zb_error - ZBOSS error handling helpers


#ifndef ZB_ERROR_PRINT_TO_LOG
#define ZB_ERROR_PRINT_TO_LOG 1
#endif

// <h> zigbee_assert - Default behavior for ZBOSS stack internal assert handler

//==========================================================
// <o> CONFIG_ZBOSS_RESET_ON_ASSERT - Reset device when a ZBOSS assert occurs  <0-1>


#ifndef CONFIG_ZBOSS_RESET_ON_ASSERT
#define CONFIG_ZBOSS_RESET_ON_ASSERT 1
#endif

// <o> CONFIG_ZBOSS_HALT_ON_ASSERT - Halt device when a ZBOSS assert occurs. Use only for testing and debugging.  <0-1>


#ifndef CONFIG_ZBOSS_HALT_ON_ASSERT
#define CONFIG_ZBOSS_HALT_ON_ASSERT 0
#endif


// </h>
//==========================================================

// </h>
//==========================================================


// <<< end of configuration section >>>
#endif //EXAMPLE_CONFIG_H

