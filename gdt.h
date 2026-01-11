#ifndef GDT_H
#define GDT_H

typedef struct __attribute__((packed)){
        unsigned short size;
        unsigned int address;
} gdt_desc;

void lgdtb(void* addr);

#endif // GDT_H