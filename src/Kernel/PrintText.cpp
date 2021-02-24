#include "PrintText.h"

uint_16 CursorPos;

void CursorDisable()
{
    outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void CursorEnable()
{
    outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0));
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0));
}

uint_16 PosFromCoords(uint_8 x, uint_8 y)
{
    return 80 * y + x;
}

uint_16 LastCursorPos;
void SetCursorPosition(uint_16 pos)
{
    outb(0x3D4, 0x0F);
    outb(0x3D5, (uint_8)(pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint_8)((pos >> 8) & 0xFF));

    CursorPos = pos;
    if(CursorPos >= 2000)
    {
        if(LastCursorPos > 80)
        {
            SetCursorPosition(CursorPos - 2000);
        }
        else
        {
            SetCursorPosition(CursorPos + 2000);
        }
    }
    LastCursorPos = CursorPos;
}

void ClearScreen(uint_64 ClearColor, uint_16 pos)
{
    uint_64 value = 0;
    value += ClearColor << 8;
    value += ClearColor << 24;
    value += ClearColor << 40;
    value += ClearColor << 56;
    for(uint_64* i = (uint_64*)VGA_MEMORY; i < ((uint_64*)VGA_MEMORY + 4000); i++)
    {
        *i = value;
    }
    SetCursorPosition(pos);
}

char combineStrOutput[128];
const char* combineStr(const char* str1, const char* str2)
{
    uint_16 i = 0;    
    uint_8* chrPtr1 = (uint_8*)str1;
    while (*chrPtr1 != 0)
    {
        combineStrOutput[i] = *chrPtr1;
        chrPtr1++;
        i++;
    }
    
    uint_8* chrPtr2 = (uint_8*)str2;
    while (*chrPtr2 != 0)
    {
        combineStrOutput[i] = *chrPtr2;
        chrPtr2++;
        i++;
    }
    for (i; i < 128; i++)
    {
        combineStrOutput[i] = '\0';
    }
    return combineStrOutput;
}

void PrintChar(char chr, uint_8 color)
{
    *(VGA_MEMORY + CursorPos * 2) = chr;
    *(VGA_MEMORY + CursorPos * 2 + 1) = color;

    if(chr != 0)
    {
        SetCursorPosition(CursorPos + 1);
    }
}

void PrintString(const char* string, uint_8 color)
{
    uint_8* chrPtr = (uint_8*)string;
    uint_16 index = CursorPos;
    while(*chrPtr != 0)
    {
        switch (*chrPtr)
        {
            case 10: 
                //index = (index / 80) * 80;
                if(terminalOpen)
                {
                    ScrollTerminal(false);
                }
                else 
                {
                    index += 80;  
                }
                break;
            case 13:
                if(terminalOpen)
                {
                    index -= (index % 80) - 10;
                }
                else 
                {
                    index -= index % 80;
                }    
                break;

            default:
                *(VGA_MEMORY + index * 2) = *chrPtr;
                *(VGA_MEMORY + index * 2 + 1) = color;
                index++;
        }
        chrPtr++;
    }
    SetCursorPosition(index);
}

char hexToStringOutput[128];
template<typename T>
const char* HexToString(T value){
    T* valPtr = &value;
    uint_8* ptr;
    uint_8 temp;
    uint_8 size = (sizeof(T)) * 2 - 1;
    uint_8 i;
    for (i = 0; i < size; i++)
    {
        ptr = ((uint_8*)valPtr + i);
        temp = ((*ptr & 0xF0) >> 4);
        hexToStringOutput[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : 48);
        temp = ((*ptr & 0x0F));
        hexToStringOutput[size - (i * 2 + 0)] = temp + (temp > 9 ? 55 : 48);
    }
    hexToStringOutput[size + 1] = 0;

    return hexToStringOutput;
}

const char* HexToString(uint_8 value) { return HexToString<uint_8>(value); }
const char* HexToString(uint_16 value) { return HexToString<uint_16>(value); }
const char* HexToString(uint_32 value) { return HexToString<uint_32>(value); }
const char* HexToString(uint_64 value) { return HexToString<uint_64>(value); }
const char* HexToString(char value) { return HexToString<char>(value); }
const char* HexToString(short value) { return HexToString<short>(value); }
const char* HexToString(int value) { return HexToString<int>(value); }
const char* HexToString(long long value) { return HexToString<long long>(value); }

char integerToStringOutput[128];
template<typename T>
const char* IntToString(T value)
{

    uint_8 isNegative = 0;
    if(value < 0)
    {
        isNegative = 1;
        value *= -1;
        integerToStringOutput[0] = '-';
    }

    uint_8 size = 0;
    uint_64 sizeTester = (uint_64)value;
    while (sizeTester / 10 > 0)
    {
        sizeTester /= 10;
        size++;
    }

    uint_8 index = 0;
    uint_64 newValue = (uint_64)value;
    while(newValue / 10 > 0)
    {
        uint_8 remainder = newValue % 10;
        newValue /= 10;
        integerToStringOutput[isNegative + size - index] = remainder + 48;
        index++;
    }
    uint_8 remainder = newValue % 10;
    integerToStringOutput[isNegative + size - index] = remainder + 48;
    integerToStringOutput[isNegative + size + 1] = 0;
    return integerToStringOutput;
}

const char* IntToString(uint_8 value) { return IntToString<uint_8>(value); }
const char* IntToString(uint_16 value) { return IntToString<uint_16>(value); }
const char* IntToString(uint_32 value) { return IntToString<uint_32>(value); }
const char* IntToString(uint_64 value) { return IntToString<uint_64>(value); }
const char* IntToString(char value) { return IntToString<char>(value); }
const char* IntToString(short value) { return IntToString<short>(value); }
const char* IntToString(int value) { return IntToString<int>(value); }
const char* IntToString(long long value) { return IntToString<long long>(value); }


char floatToStringOutput[128];
const char* FloatToString(float value, uint_8 decimalPlaces)
{
    char* intPtr = (char*)IntToString((int)value);
    char* floatPtr = floatToStringOutput;

    if(value < 0)
    {
        value *= -1;
    }

    while(*intPtr != 0)
    {
        *floatPtr = *intPtr;
        intPtr++;
        floatPtr++;
    }
    *floatPtr = '.';
    floatPtr++;
    
    float newValue = value - (int)value;

    for (uint_8 i = 0; i < decimalPlaces + 1; i++)
    {
        if(i < decimalPlaces)
        {
            newValue *= 10;
            *floatPtr = (int)newValue + 48;
            newValue -= (int)newValue;
            floatPtr++;  
        }
        if(i == decimalPlaces)
        {
            newValue *= 10;
            if((int)newValue >= 5)
            {
                floatPtr -= 1;
                *floatPtr += 1;
                floatPtr += 1; 
            }
        }
    }

    *floatPtr = 0;

    return floatToStringOutput;
}

char IntToBinaryOutput[128];
//template<typename T>
const char* IntToBin(uint_64 value){
    char* intPtr = (char*)IntToString((int)value);
    char* binPtr = IntToBinaryOutput;

    uint_8 size = 0;
    uint_64 sizeTester = (uint_64)value;
    while (sizeTester / 2 > 0)
    {
        sizeTester /= 2;
        size++;
    }

    uint_8 index = 0;
    uint_64 newValue = (uint_64)value;
    while(newValue / 2 > 0)
    {
        uint_8 remainder = newValue % 2;
        newValue /= 2;
        integerToStringOutput[size - index] = remainder + 48;
        index++;
    }
    uint_8 remainder = newValue % 2;
    integerToStringOutput[size - index] = remainder + 48;
    integerToStringOutput[size + 1] = 0;
    return integerToStringOutput;
}

//const char* IntToBin(uint_16 value) { return IntToBin<uint_16>(value); }