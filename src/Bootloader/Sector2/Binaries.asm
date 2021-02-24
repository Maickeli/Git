%macro IncBin 2
    SECTION .rodata
    GLOBAL %1
%1:
    incbin %2
    db 0
    %1_size dq %1_size - %1
%endmacro

IncBin Test321, "Binaries/test.txt"

IncBin MiOSLogo, "Binaries/MiOS_logo.txt"

IncBin Homer, "Binaries/homer.txt"