#pragma once
#include "IO.h"
#include "Typedefs.h"

#define VGA_MEMORY (uint_8*)0xb8000

extern uint_16 CursorPos;

void CursorDisable();
void CursorEnable();
uint_16 PosFromCoords(uint_8 x, uint_8 y);
void ClearScreen(uint_64 ClearColor = 0x00 | 0x0F, uint_16 pos = 0);
void SetCursorPosition(uint_16 pos);
void PrintChar(char chr);
void PrintString(const char* string);

const char* FloatToString(float value, uint_8 decimalPlaces);

const char* HexToString(uint_8 value);
const char* HexToString(uint_16 value);
const char* HexToString(uint_32 value);
const char* HexToString(uint_64 value);
const char* HexToString(char value);
const char* HexToString(short value);
const char* HexToString(int value);
const char* HexToString(long long value);

const char* IntegerToString(uint_8 value);
const char* IntegerToString(uint_16 value);
const char* IntegerToString(uint_32 value);
const char* IntegerToString(uint_64 value);
const char* IntegerToString(char value);
const char* IntegerToString(short value);
const char* IntegerToString(int value);
const char* IntegerToString(long long value);