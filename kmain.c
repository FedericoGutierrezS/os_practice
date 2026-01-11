#define FB_GREEN 2
#define FB_DARK_GREY 8

#include "ioStream.h"
#include "consoleConstants.h"
#include "gdt.h"

int kmain(){
	char text[] = "What's up, Kernel World!";
	print_fb(text);
	print_serial(text, SERIAL_COM1);
	unsigned long long int __attribute__((aligned(8))) GDT[3];
	GDT[0] = 0x0000000000000000;                // Null Segment
	GDT[1] = 0x00CF9A000000FFFF;  // Code Segment: Base=0x0, Limit=0xFFFFF
	GDT[2] = 0x00CF92000000FFFF;  // Data Segment: Base=0x0, Limit=0xFFFFF
	gdt_desc gdt_descriptor;
	gdt_descriptor.address = (unsigned int)&GDT;
	gdt_descriptor.size = sizeof(GDT) - 1;
	lgdtb(&gdt_descriptor);
	return 0;
}

