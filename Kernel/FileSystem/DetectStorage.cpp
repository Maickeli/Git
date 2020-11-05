#include "DetectStorage.h"

void DetectFloppyDrives()
{
    outb(0x70, 0x10);
    uint_8 data = inb(0x71);
    uint_8 high = data >> 4;
    uint_8 low = data & 0xF;
    const char* floppyType[5] = { "No floppy drive. ", "5.25\" 360 KB. ", "5.25\" 1.2 MB. ", "3.5\" 720 KB. ", "3.5\" 2.88 MB. "};
    SetCursorPosition(PosFromCoords(10, 23));
    PrintString("Floppy 1: "); PrintString(floppyType[high]); PrintString("Floppy 2: "); PrintString(floppyType[low]);
    /*PrintString("Floppy 1: ");
    switch (high)
    {
    case 0:
        PrintString("No floppy drive. ");
        break;
    case 1:
        PrintString("5.25\" 360 KB. ");
        break;  
    case 2:
        PrintString("5.25\" 1.2 MB. ");
        break;
    case 3:
        PrintString("3.5\" 720 KB. ");
        break;
    case 4:
        PrintString("3.5\" 1.44 MB. ");
        break;
    case 5:
        PrintString("3.5\" 2.88 MB. ");
        break;

    default:
        break;
    }

    PrintString("Floppy 2: ");
    switch (low)
    {
    case 0:
        PrintString("No floppy drive. ");
        break;
    case 1:
        PrintString("5.25\" 360 KB. ");
        break;  
    case 2:
        PrintString("5.25\" 1.2 MB. ");
        break;
    case 3:
        PrintString("3.5\" 720 KB. ");
        break;
    case 4:
        PrintString("3.5\" 1.44 MB. ");
        break;
    case 5:
        PrintString("3.5\" 2.88 MB. ");
        break;

    default:
        break;
    }*/
}