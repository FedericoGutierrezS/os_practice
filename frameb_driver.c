#include "io.h"
#include "frameb_driver.h"

/*IO ports*/
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

/*IO port commands*/
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND 15

/*FB_defs*/
#define FB_MEM_START 0x000B8000

void fb_move_cursor(unsigned short pos){
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

void fb_write_cell(unsigned short pos, char c, unsigned char bg, unsigned char fg) {
	char *fb = (char *)FB_MEM_START;
	fb[pos*2] = c;
	fb[pos*2 + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

int fb_write(char *buf, unsigned int len, unsigned char bg, unsigned char fg){
	unsigned short i = 0;
	for(i = 0; i < len; i++){
		fb_move_cursor(i);
		fb_write_cell(i, buf[i], fg, bg);
	}
	return 1;
}
