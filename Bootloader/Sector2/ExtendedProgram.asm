jmp EnterProtectedMode

%include "Bootloader/Sector2/gdt.asm"
%include "Bootloader/Sector1/print.asm"
%include "Bootloader/Sector2/DetectMemory.asm"

EnterProtectedMode:
    call DetectMemory
    call EnableA20
    cli                             ; Disable interrupts
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp codeseg:StartProtectedMode

EnableA20:
    in al, 0x92
    or al, 2
    out 0x92, al
    ret

[bits 32]

%include "Bootloader/Sector2/CPUID.asm"
%include "Bootloader/Sector2/Paging.asm"

StartProtectedMode:
    mov ax, dataseg
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
                                                ;mov ebp, 0x900000
                                                ;mov esp, ebp

    mov [0xb8000], byte 'P'
    mov [0xb8002], byte 'r'
    mov [0xb8004], byte 'o'
    mov [0xb8006], byte 't'
    mov [0xb8008], byte 'e'
    mov [0xb800A], byte 'c'
    mov [0xb800C], byte 't'
    mov [0xb800E], byte 'e'
    mov [0xb8010], byte 'd'
    mov [0xb8012], byte 'M'
    mov [0xb8014], byte 'o'
    mov [0xb8016], byte 'd'
    mov [0xb8018], byte 'e'

    call DetectCPUID
    call DetectLongMode
    call SetUpIdentityPaging
    call EditGDT

    jmp codeseg:Start64Bit

[bits 64]
[extern _start]

%include "Bootloader/Sector2/IDT.asm"

Start64Bit:
    mov edi, 0xb8000
    mov rax, 0x0f200f200f200f20
    mov ecx, 500
    rep stosq
    call ActivateSSE
    call _start
    jmp $

ActivateSSE:
    mov rax, cr0
    and ax, 0b11111101
    or ax, 0b00000001
    mov cr0, rax

    mov rax, cr4
    or ax, 0b1100000000
    mov cr4, rax
    ret

times 2048-($-$$) db 0