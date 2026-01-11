global lgdtb

;loads the GDT to the cpu
;stack: +4 descriptor struct address
lgdtb:
	mov eax, [esp + 4]
	lgdt [eax]
	mov eax, 0x10
	mov ds, eax
    mov ss, eax
	mov es, eax
	mov gs, eax
	mov fs, eax
	; code here uses the previous cs
    jmp 0x08:flush_cs   ; specify cs when jumping to flush_cs

    flush_cs:
    	; now we've changed cs to 0x08
	ret
