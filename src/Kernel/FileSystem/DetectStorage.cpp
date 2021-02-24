#include "DetectStorage.h"

void DetectFloppyDrives()
{
    outb(0x70, 0x10);
    uint_8 data = inb(0x71);
    uint_8 high = data >> 4;
    uint_8 low = data & 0xF;
    const char* floppyType[5] = { "No floppy drive. ", "5.25\" 360 KB. ", "5.25\" 1.2 MB. ", "3.5\" 720 KB. ", "3.5\" 2.88 MB. "};
    PrintString("Floppy 1: ", BACKGROUND_BLACK | FOREGROUND_LIGHTGREEN); PrintString(floppyType[high]); PrintString("Floppy 2: ", BACKGROUND_BLACK | FOREGROUND_LIGHTGREEN); PrintString(floppyType[low]);
    //outb(0x3F2, 0x80);
}