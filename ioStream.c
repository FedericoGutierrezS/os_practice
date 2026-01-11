#include "consoleConstants.h"
#include "frameb_driver.h"
#include "serial_driver.h"
#include "ioStream.h"

void print_fb(char* str) {
    unsigned int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    fb_write(str, len, CONSOLE_BG, CONSOLE_FG);
}

void print_serial(char* str, unsigned short com) {
    unsigned int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    serial_configure_line(com);
	serial_write(com, str, len);
}