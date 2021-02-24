#pragma once
#include <stdint.h>
#include "../PrintText.h"

extern bool canMoveCurX;
extern bool canMoveCurY;

extern bool LShiftOn;
extern bool CapsLockOn;
extern bool EnterPressed;
extern bool UpPressed;

void MainKeyboardHandler(uint_8 scanCode, uint_8 chr);
void Keyboard0xE0Handler(uint_8 scanCode);