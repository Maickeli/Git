#pragma once
#include "Typedefs.h"
#include "PrintText.h"

extern bool LShiftOn;
extern bool CapsLockOn;

void MainKeyboardHandler(uint_8 scanCode, uint_8 chr);
void Keyboard0xE0Handler(uint_8 scanCode);