#include "IO.h"
#include <stdint.h>
#include "PrintText.h"
#include "IDT.h"
#include "Memory/MemoryMap.h"
#include "Terminal.h"
#include "Devices/KeyboardHandler.h"
#include "Memory/Heap.h"
#include "PIT.h"
#include "RTC.h"
#include "Timer.h"
#include "Song.h"


extern "C" void _start()
{
    InitializeIDT();
    ClearScreen();
    //PrintString(" ______          ______      ____     _________________    _______________\n\r/____ /\\        /____ /|    /___/|   /_______________ /|  /_____________/ |\n\r|     \\ \\      /     | |    |___|/   |   _________   | |  |             | |\n\r|  |\\  \\ \\    /  /|  | |     ____    |  | |       |  | |  |    _________|/\n\r|  | \\  \\ \\  /  / |  | |    /__ /|   |  | |       |  | |  |   |__________/|\n\r|  | |\\  \\ \\/  / /|  | |    |  | |   |  | |       |  | |  |             | |\n\r|  | | \\  \\/  / / |  | |    |  | |   |  | |       |  | |  |_________    | |\n\r|  | |  \\____/_/  |  | |    |  | |   |  | |_______|  | |  /_________|   | |\n\r|  | |            |  | |    |  | |   |  |/________|  | |  |             | |\n\r|__|/             |__|/     |__|/    |_______________|/   |_____________|/", );
    
    PrintString(MiOSLogo);
    PrintTerminal();
    InitializeHeap(0x100000, 0x100000);
    activateChannel(0x40, 0x04, 1000);


    /*while (true)
    {
        if(EnterPressed == true)
        {
            playSong();
            EnterPressed = false;
            //PrintString(HexToString(inb(0x40)));
            //PrintString("\n");
        }
        /*if(inb(0x40) != lastNum)
        {
            if(i >= 10000)
            {
                PrintString(HexToString(inb(0x40)));
                PrintString("\n");
                i = 0;
            }
            i++;
        }
        lastNum = readRegister(0x00);
    }*/


    TerminalMain();
    /*uint_8 c = inb(0x64);
    uint_8 a = c & 0xF;
    PrintString(IntegerToString(a));*/

    return;
}