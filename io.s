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

