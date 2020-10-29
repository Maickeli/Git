#include "IO.h"
#include "Typedefs.h"
#include "PrintText.h"
#include "IDT.h"
#include "MemoryMap.h"

extern "C" void _start()
{
    InitializeIDT();
    SetCursorPosition(0);

    MemoryMapEntry** usableMemoryMaps = GetUsableMemoryRegions();

    for(uint_8 i = 0; i < UsableMemoryRegionCount; i++)
    {
        MemoryMapEntry* memMap = usableMemoryMaps[i];
        memMap += i;
        PrintMemoryMap(memMap, CursorPos);
    }
    return;
}