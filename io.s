global outb

;send byte to IO port
;stack: +8 data
;	+4 port
;	+0 return
outb:
	mov al, [esp + 8]
	mov dx, [esp + 4]
	out dx, al
	ret

global inb

;returns a byte from the given IO port
;stack: +4 IO port address
;       return address
inb:
	mov dx, [esp + 4]
	in al, dx
	ret
