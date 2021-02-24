#!/bin/bash
nasm src/Bootloader/Sector1/bootloader.asm -f bin -i src -o bootloader.bin
nasm src/Bootloader/Sector2/ExtendedProgram.asm -f elf64 -i src -o ExtendedProgram.o
nasm src/Bootloader/Sector2/Binaries.asm -f elf64 -i src -o Binaries.o
cmake CMakeLists.txt -G "Unix Makefiles"
make -f "Makefile" --always-make
cat bootloader.bin Kernel.bin > boot.flp