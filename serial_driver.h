#ifndef INCL_SERIAL_DRV
#define INCL_SERIAL_DRV

void serial_configure_baud_rate(unsigned short com, unsigned short divisor);

void serial_configure_line(unsigned short com);

unsigned char serial_is_transmit_fifo_empty(unsigned short com);

void serial_write(unsigned short com, char* message, unsigned int len);

#endif
