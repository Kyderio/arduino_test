#ifndef _AMEBA_PINMUX_TEST_H_
#define _AMEBA_PINMUX_TEST_H_

#define PMUX_PINNAME(PORT, PIN)			(((PORT) << 5) | ((PIN) & 0x1F))

#endif
