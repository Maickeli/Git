#include "MemoryMap.h"

extern const uint_8 MemoryRegionCount;
static uint_8 UsableMemoryRegionCount = 0;
static struct MemoryMapEntry *UsableMemoryRegions[10];

void PrintMemoryMap(MemoryMapEntry* memoryMap, uint_16 position)
{
    if(memoryMap == 0)
    {
        SetCursorPosition(position);
        PrintString("MemoryMap is null");
        return;
    }
    SetCursorPosition(position);
    PrintString("Memory Base: "); PrintString(IntegerToString(memoryMap->BaseAddress));
    SetCursorPosition(position + 80);
    PrintString("Region Length: "); PrintString(IntegerToString(memoryMap->RegionLength));
    SetCursorPosition(position + 160);
    PrintString("Memory Type: "); PrintString(IntegerToString(memoryMap->RegionType));
    SetCursorPosition(position + 240);
    PrintString("Memory Attributes: "); PrintString(HexToString(memoryMap->ExtendedAttributes));
    SetCursorPosition(position + 400);
}

void PrintAllMemMaps()
{
    for(uint_8 i = 0; i < MemoryRegionCount; i++)
    {
        MemoryMapEntry* memMap = (MemoryMapEntry*)0x5000;
        memMap += i;
        PrintMemoryMap(memMap, CursorPos);
    }
}

bool MemoryRegionsGot = false;

MemoryMapEntry** GetUsableMemoryRegions()
{
    if(MemoryRegionsGot)
    {
        return UsableMemoryRegions;
    }

    uint_8 UsableRegionIndex;
    for(uint_8 i = 0; i < MemoryRegionCount; i++)
    {
        MemoryMapEntry* memMap = (MemoryMapEntry*)0x5000;
        memMap += i;
        if(memMap->RegionType == 1)
        {
            UsableMemoryRegions[UsableRegionIndex] = memMap;
            UsableRegionIndex++;
        }
    }
    UsableMemoryRegionCount = UsableRegionIndex;

    MemoryRegionsGot = true;
    return UsableMemoryRegions;
}

void PrintUsableMemMaps(MemoryMapEntry** usableMemoryMaps)
{    
    //PrintString(IntegerToString(UsableMemoryRegionCount));

    for(uint_64 i = 0; i < UsableMemoryRegionCount; i++)
    {
        MemoryMapEntry* memMap = usableMemoryMaps[0];
        PrintMemoryMap(memMap, CursorPos);                    // Trying to access memMap->"Anything" Crashes Virtualbox | Virtualbox usable memoryregioncount = 144 bochs = 2
    }
}