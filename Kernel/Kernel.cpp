#include "IO.h"
#include "Typedefs.h"
#include "PrintText.h"
#include "IDT.h"
#include "MemoryMap.h"
#include "Terminal.h"
#include "KeyboardHandler.h"

extern "C" void _start()
{
    InitializeIDT();
    SetCursorPosition(0);

    //PrintAllMemMaps(); 

    PrintUsableMemMaps(GetUsableMemoryRegions());

    /*
    PrintTerminal();
    while (true)
    {
        if(EnterPressed == true)
        {
            EnterPressed = false;
            ScrollTerminal();
        }
    }*/





    return;
}