nasm Bootloader/Sector1/bootloader.asm -f bin -o bootloader.bin

nasm Bootloader/Sector2/ExtendedProgram.asm -f elf64 -o ExtendedProgram.o

x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Kernel/Kernel.cpp" -o "Kernel.o"

x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Kernel/IO.cpp" -o "IO.o"

x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Kernel/PrintText.cpp" -o "PrintText.o"

x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Kernel/IDT.cpp" -o "IDT.o"

x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Kernel/KeyboardHandler.cpp" -o "KeyboardHandler.o"

x86_64-elf-gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Kernel/MemoryMap.cpp" -o "MemoryMap.o"


custom-ld -T"link.ld"

copy /b bootloader.bin+kernel.bin boot.flp

DEL Kernel.o
DEL ExtendedProgram.o
DEL IO.o
DEL PrintText.o
DEL bootloader.bin
DEL Kernel.bin
DEL IDT.o
DEL MemoryMap.o
DEL KeyboardHandler.o


pause