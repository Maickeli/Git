#pragma once
#include "PrintText.h"
#include <stdint.h>
#include "Memory/MemoryMap.h"
#include "FileSystem/DetectStorage.h"
#include "Devices/KeyboardHandler.h"
#include "RTC.h"
#include "IntToBinConverter.h"
#include "Song.h"

extern bool terminalOpen;

extern const char MiOSLogo[];
extern const char Homer[];
extern const char Test321[];

void TerminalMain();
void PrintTerminal();
void ScrollTerminal(bool read = true);
void ReadInput();