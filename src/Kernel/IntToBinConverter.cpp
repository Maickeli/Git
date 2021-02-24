#include "IntToBinConverter.h"

void IntToBinMain()
{
    PrintIntToBin();
    while (true)
    {
        if(EnterPressed == true)
        {
            EnterPressed = false;
            ScrollTerminal(false);
            SetCursorPosition(PosFromCoords(10, 24));
            PrintString(IntToBin(ReadToInt()));
            ScrollTerminal(false);
            PrintIntToBin();
        }
    }
}

void PrintIntToBin()
{
    SetCursorPosition(PosFromCoords(0, 24));
    PrintString("IntToBin >");
}

uint_16 ReadToInt()
{
    char inputLine[70] = "";
    uint_16 inputValue = 0;
    uint_8 indexOffset = 0;
    for(uint_8 i = 0; i < 70; i++)
    {
        if(*(VGA_MEMORY + PosFromCoords(10 + i, 23) * 2) == 0 || *(VGA_MEMORY + PosFromCoords(10 + i, 23) * 2) == ' ')
        {           
            indexOffset++;
            continue;
        }
        inputLine[i-indexOffset] = *(VGA_MEMORY + PosFromCoords(10 + i, 23) * 2);

        uint_8 newVal = inputLine[i-indexOffset] - 48;
        if(i != 0)
        {
            inputValue *= i * 10;
        }
        inputValue += newVal;
    }
    if(inputValue == 35298)
    {
        TerminalMain();
    }
    return inputValue;
}