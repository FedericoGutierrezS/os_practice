#define FB_GREEN 2
#define FB_DARK_GREY 8

#include "frameb_driver.h"

int kmain(){
	char hello_world[] = "Opalo!";
	unsigned int len = 6;
	write(hello_world, len, 8, 2);
	return 0;
}

