#define FB_GREEN 2
#define FB_DARK_GREY 8

#include "frameb_driver.h"
#include "serial_driver.h"

int kmain(){
	char hello_world[] = "Hello World!";
	unsigned int len = 12;
	fb_write(hello_world, len, 8, 2);	
	serial_configure_line(0x3F8);
	serial_write(0x3F8, hello_world, len);
	return 0;
}

