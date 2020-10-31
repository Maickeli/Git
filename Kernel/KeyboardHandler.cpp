#include "KeyboardHandler.h"

bool LShiftOn;
bool CapsLockOn;
bool EnterPressed;

uint_8 lastPress;

void MainKeyboardHandler(uint_8 scanCode, uint_8 chr)
{   
    if(chr != 0)
    {
        PrintChar(chr); 
        return;
    }

    if(lastPress == 0xE0)
    {
        Keyboard0xE0Handler(scanCode);
    }
 
    switch(scanCode)
    {     
        case 0x0E:      // Backspace
            SetCursorPosition(CursorPos - 1);
            PrintChar(0);
            break;
                      
        case 0x2A:      // Left shift
            LShiftOn = true;
            break;
  
        case 0xAA:      // Left shift release
            LShiftOn = false;
            break;

        case 0x0F:      // Tab
            PrintString("   ");
            break;

        case 0x3A:
            CapsLockOn = !CapsLockOn;
            break;

        case 0x1C:      // Enter released
            EnterPressed = true;
            //PrintString("\n\r");
            break;
    }
    lastPress = scanCode;
}

void Keyboard0xE0Handler(uint_8 scanCode)
{
    switch(scanCode)
    {
        case 0x48:
            SetCursorPosition(CursorPos - 80);
            break;  
        
        case 0x50:
            SetCursorPosition(CursorPos + 80);
            break; 

        case 0x4B:
            SetCursorPosition(CursorPos - 1);
            break; 

        case 0x4D:
            SetCursorPosition(CursorPos + 1);
            break; 
    }
}