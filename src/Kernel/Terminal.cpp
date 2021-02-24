#include "Terminal.h"

bool terminalOpen;
const char* prevCommands[25] = {"\0"};

extern const char rtcClock[70] = "time";
extern const char memoryInfo[70] = "meminfo";
extern const char home[70] = "home";
extern const char clear[70] = "clear";
extern const char floppies[70] = "floppies";
extern const char help[70] = "help";
extern const char intToBin[70] = "inttobin";
extern const char homer[70] = "homer";
extern const char twinkle[70] = "twinkle";



void TerminalMain()
{
    terminalOpen = true;
    PrintTerminal();
    while (terminalOpen)
    {
        if(EnterPressed == true)
        {
            EnterPressed = false;
            ScrollTerminal();
        }

        if(UpPressed)
        {
            UpPressed = false;
            //PrintString(prevCommands[0]);
            PrintString(*prevCommands);
        }

        if(CursorPos < 1930)
        {
            PrintTerminal();
        }
    }
}

void PrintTerminal()
{
    terminalOpen = true;
    canMoveCurY = false; canMoveCurX = true; 
    SetCursorPosition(PosFromCoords(0, 24));
    PrintString("Terminal >");
}

void PrintHelp()
{
    PrintString("Commands: \r\nmeminfo: - print info about memory\n\rhome: - back to home screen \n\rfloppies: - info about current fitted floppies\n\rtime: - display current date and time", BACKGROUND_BLACK | FOREGROUND_LIGHTGREEN);
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

void ScrollTerminal(bool read)
{
    for(uint_8 j = 1; j < 25; j++)
    {
        for(uint_16 i = PosFromCoords(0, j); i < PosFromCoords(80, j); i++)
        {
            *(VGA_MEMORY + (i - 80)  * 2) = *(VGA_MEMORY + i  * 2);
            *(VGA_MEMORY + (i - 80)  * 2 + 1) = *(VGA_MEMORY + i  * 2 + 1);
            *(VGA_MEMORY + i  * 2) = 0;
            *(VGA_MEMORY + i  * 2 + 1) = 0x00 | 0x0F;
            if(read) PrintTerminal();
        }
    }
    if(read) ReadInput();
    else SetCursorPosition(CursorPos - 80);
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

    prevCommands[0] = inputLine;

    if (CompareStrings(inputLine, memoryInfo))
    {
        for(uint_8 i = 0; i < 8; i++)
        {
            ScrollTerminal(false);
        }
        PrintUsableMemMaps(GetUsableMemoryRegions());
    }
    else if (CompareStrings(inputLine, home))
    {
        ClearScreen();
        terminalOpen = false;
        PrintString(MiOSLogo);
        PrintTerminal();
        return;
    }
    else if (CompareStrings(inputLine, clear))
    {
        ClearScreen();
        PrintTerminal();
        return;
    }
    else if (CompareStrings(inputLine, floppies))
    {
        DetectFloppyDrives();
    }
    else if (CompareStrings(inputLine, help))
    {
        PrintHelp();
    }
    else if (CompareStrings(inputLine, rtcClock))
    {
        PrintString(dateTime());
    }
    else if (CompareStrings(inputLine, intToBin))
    {
        IntToBinMain();
        terminalOpen = false;
        return;
    }
    else if (CompareStrings(inputLine, homer))
    {
        ClearScreen();
        terminalOpen = false;
        PrintString(Homer);
        PrintTerminal();
        playSong(2);
        return;
    }
    else if (CompareStrings(inputLine, twinkle))
    {
        playSong(1);
    }
    else
    {
        PrintString("No such command", BACKGROUND_BLACK | FOREGROUND_LIGHTRED);
    }
    

    ScrollTerminal(false);
    PrintTerminal();
}

const char* lastCommand()
{
    return "asd";
}