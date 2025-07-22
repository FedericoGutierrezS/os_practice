#include "serial_driver.h"
#include "io.h"


#define SERIAL_COM1_BASE 0x3F8

#define SERIAL_DATA_PORT(base) (base)
#define SERIAL_FIFO_COMMAND_PORT(base) (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base) (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base) (base + 5)


#define SERIAL_LINE_ENABLE_DLAB 0x80


void serial_configure_baud_rate(unsigned short com, unsigned short divisor) {
	outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
	outb(SERIAL_DATA_PORT(com), (divisor>>8) & 0x00FF);
	outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

void serial_configure_line(unsigned short com) {
	outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
	outb(SERIAL_FIFO_COMMAND_PORT(com), 0xC7);
	outb(SERIAL_MODEM_COMMAND_PORT(com), 0x03);	
}

unsigned char serial_is_transmit_fifo_empty(unsigned short com) {
	return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void serial_write(unsigned short com, char* message, unsigned int len) {
	unsigned int i = 0;
	for(i = 0; i < len; i++) {
		while(!serial_is_transmit_fifo_empty(com));
		outb(SERIAL_DATA_PORT(com), message[i]);
	}
}
