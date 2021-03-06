#pragma once
#include <stdint.h>
#include "../PrintText.h"

struct MemoryMapEntry {
    uint_64 BaseAddress;
    uint_64 RegionLength;
    uint_32 RegionType;
    uint_32 ExtendedAttributes;
};


//extern uint_8 UsableMemoryRegionCount;

void PrintAllMemMaps();

void PrintMemoryMap(MemoryMapEntry* memoryMap, uint_16 position);
MemoryMapEntry** GetUsableMemoryRegions();

void PrintUsableMemMaps(MemoryMapEntry** usableMemoryMaps);