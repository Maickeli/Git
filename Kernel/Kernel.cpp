#include "IO.h"
#include "Typedefs.h"
#include "PrintText.h"
#include "IDT.h"
#include "Memory/MemoryMap.h"
#include "Terminal.h"
#include "Devices/KeyboardHandler.h"
#include "Memory/Heap.h"

extern "C" void _start()
{
    InitializeIDT();
    SetCursorPosition(0);
    ClearScreen();
    /*
    PrintString(" ______          ______      ____     _________________    _______________\n\r/____ /\\        /____ /|    /___/|   /_______________ /|  /_____________/ |\n\r
    |     \\ \\      /     | |    |___|/   |   _________   | |  |             | |\n\r|  |\\  \\ \\    /  /|  | |     ____    |  | |       |  | |  |    _________|/\n\r
    |  | \\  \\ \\  /  / |  | |    /__ /|   |  | |       |  | |  |   |__________/|\n\r|  | |\\  \\ \\/  / /|  | |    |  | |   |  | |       |  | |  |             | |\n\r
    |  | | \\  \\/  / / |  | |    |  | |   |  | |       |  | |  |_________    | |\n\r|  | |  \\____/_/  |  | |    |  | |   |  | |_______|  | |  /_________|   | |\n\r
    |  | |            |  | |    |  | |   |  |/________|  | |  |             | |\n\r|__|/             |__|/     |__|/    |_______________|/   |_____________|/");
    */
    PrintString(MiOSLogo);
    PrintTerminal();
    
    /*
    SetCursorPosition(PosFromCoords(0, 12));
    
    InitializeHeap(0x100000, 0x100000);
    void* TestMemoryAddress = malloc(0x10);
    void* TestMemoryAddress2 = malloc(0x10);
    void* TestMemoryAddress3 = malloc(0x10);

    PrintString(HexToString((uint_64)TestMemoryAddress));
    PrintString("    ");
    PrintString(HexToString((uint_64)TestMemoryAddress2));
    PrintString("    ");
    PrintString(HexToString((uint_64)TestMemoryAddress3));
    PrintString("    ");

    free(TestMemoryAddress);
    free(TestMemoryAddress2);
    free(TestMemoryAddress3);

    void* Test4 = malloc(0x60);
    PrintString(HexToString((uint_64)Test4));
    PrintString("    \n\n\r");
    */
    /*uint_8 c = inb(0x64);
    uint_8 a = c & 0xF;
    PrintString(IntegerToString(a));*/

    while (true)
    {
        if(EnterPressed == true)
        {
            EnterPressed = false;
                /*
                outb(0x64, 0xD4);
                outb(0x60, 0xF2);
                uint_8 c = inb(0x64);
                uint_8 a = c & 0xF;
                PrintString(HexToString(c));*/

            ScrollTerminal();
        }
    }

    return;
}