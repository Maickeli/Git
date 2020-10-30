#include "IO.h"
#include "Typedefs.h"
#include "PrintText.h"
#include "IDT.h"
#include "MemoryMap.h"

extern "C" void _start()
{
    InitializeIDT();
    SetCursorPosition(0);

    //PrintAllMemMaps(); 
    PrintUsableMemMaps(GetUsableMemoryRegions());
    return;
}