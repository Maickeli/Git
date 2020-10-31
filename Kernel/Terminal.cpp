#include "Terminal.h"

void PrintTerminal()
{
    SetCursorPosition(PosFromCoords(0, 24));
    PrintString("Terminal >");
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
}