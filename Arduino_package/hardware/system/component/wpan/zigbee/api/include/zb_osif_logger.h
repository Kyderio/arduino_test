#ifndef ZB_OSIF_LOGGER_H
#define ZB_OSIF_LOGGER_H

void zb_osif_serial_init(void);
void zb_osif_serial_flush(void);
#ifdef ZB_HAVE_SERIAL_SINGLE
void zb_osif_serial_put_bytes(const zb_uint8_t *bytes, zb_short_t len);
#endif

#endif /*ZB_OSIF_LOGGER_H*/
