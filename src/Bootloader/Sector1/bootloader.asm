[ORG 0x7c00]      ; go to location 0x7c00

; Added this
jmp 0x0000:main       ; Far jump right away

main:                 ; Added this too, Set segment registers to known values

    xor ax, ax 
    mov ds, ax 
    mov es, ax
    mov ss, ax

    mov [BOOT_DISK], dl

    mov bp, 0x7c00
    mov sp, bp

    call ReadDisk

    ; Print a test string
    mov bx, EXTENDED_STRING
    call PrintString

    jmp PROGRAM_SPACE

%include "Bootloader/Sector1/print.asm"
%include "Bootloader/Sector1/DiskRead.asm"

EXTENDED_STRING: db "Jumping to extended program",0xA, 0xD,0

times 446-($-$$) db 0 
db 0x80

times 510-($-$$) db 0
db 0x55
db 0xAA