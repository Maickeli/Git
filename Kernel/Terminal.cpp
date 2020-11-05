#include "Terminal.h"

extern const char memoryInfo[70] = "MemoryInfo";
extern const char home[70] = "Home";
extern const char floppies[70] = "FloppyDrives";
extern const char help[70] = "Help";

void PrintTerminal()
{
    SetCursorPosition(PosFromCoords(0, 24));
    PrintString("Terminal >");
}

void PrintHelp()
{
    SetCursorPosition(PosFromCoords(10, 23));
    PrintString("Commands: Memory Info; Home; Floppy Drives;");
    PrintTerminal();
}

bool CompareStrings(char inputLine[], const char word[])
{
    for(uint_8 i = 0; i < 70; i++)
    {
        if(inputLine[i] != word[i])
        {
            if(inputLine[i] >= 65 && inputLine[i] <= 90 && inputLine[i] + 32 == word[i]) { continue; }
            else if(inputLine[i] >= 97 && inputLine[i] <= 122 && inputLine[i] - 32 == word[i]) { continue; }
            else { return false; }
        } 
    }
    return true;
}

void ScrollTerminal()
{
    for(uint_8 j = 1; j < 25; j++)
    {
        for(uint_16 i = PosFromCoords(0, j); i < PosFromCoords(80, j); i++)
        {
            *(VGA_MEMORY + (i - 80)  * 2) = *(VGA_MEMORY + i  * 2);
            *(VGA_MEMORY + i  * 2) = 0;
            PrintTerminal();
        }
    }
    ReadInput();
}

void ReadInput()
{
    char inputLine[70] = "";

    uint_8 indexOffset = 0;
    for(uint_8 i = 0; i < 70; i++)
    {
        if(*(VGA_MEMORY + PosFromCoords(10 + i, 23) * 2) == 0 || *(VGA_MEMORY + PosFromCoords(10 + i, 23) * 2) == ' ')
        {           
            indexOffset++;
            continue;
        }
        inputLine[i-indexOffset] = *(VGA_MEMORY + PosFromCoords(10 + i, 23) * 2);

    }

    if (CompareStrings(inputLine, memoryInfo))
    {
        ClearScreen();
        PrintUsableMemMaps(GetUsableMemoryRegions());
        PrintTerminal();
        return;
    }
    else if (CompareStrings(inputLine, home))
    {
        ClearScreen();
        PrintString(MiOSLogo);
        PrintTerminal();
    }
    else if (CompareStrings(inputLine, floppies))
    {
        DetectFloppyDrives();
        PrintTerminal();
    }
    else if (CompareStrings(inputLine, help))
    {
        PrintHelp();
    }
}