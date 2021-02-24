#pragma once
#include "IO.h"
#include <stdint.h>
#include "TextModeColorCodes.h"
#include "Terminal.h"

#define VGA_MEMORY (uint_8*)0xb8000

extern uint_16 CursorPos;

void CursorDisable();
void CursorEnable();
uint_16 PosFromCoords(uint_8 x, uint_8 y);
void ClearScreen(uint_64 ClearColor = 0x00 | 0x0F, uint_16 pos = 0);
void SetCursorPosition(uint_16 pos);
void PrintChar(char chr, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE);
void PrintString(const char* string, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE);
const char* combineStr(const char* str1, const char* str2);

const char* FloatToString(float value, uint_8 decimalPlaces);

const char* IntToBin(uint_64 value);

const char* HexToString(uint_8 value);
const char* HexToString(uint_16 value);
const char* HexToString(uint_32 value);
const char* HexToString(uint_64 value);
const char* HexToString(char value);
const char* HexToString(short value);
const char* HexToString(int value);
const char* HexToString(long long value);

const char* IntToString(uint_8 value);
const char* IntToString(uint_16 value);
const char* IntToString(uint_32 value);
const char* IntToString(uint_64 value);
const char* IntToString(char value);
const char* IntToString(short value);
const char* IntToString(int value);
const char* IntToString(long long value);