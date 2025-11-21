

#ifndef _SCCB_TEST_H
#define _SCCB_TEST_H

void sccb_init(void);
void sccb_write_reg8(int slave_addr, u8 reg, u8 data);
void sccb_write_reg16(int slave_addr, u16 reg, u8 data);
u8 sccb_read_reg8(u8 slave_addr, u8 reg);
u8 sccb_read_reg16(u8 slave_addr, u16 reg);

#endif

