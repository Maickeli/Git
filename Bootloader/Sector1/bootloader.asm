[ORG 0x7c00]      ; go to location 0x7c00

mov [BOOT_DISK], dl

mov bp, 0x7c00
mov sp, bp

call ReadDisk

jmp PROGRAM_SPACE

%include "Bootloader/Sector1/print.asm"
%include "Bootloader/Sector1/DiskRead.asm"

   times 510-($-$$) db 0
   db 0x55
   db 0xAA