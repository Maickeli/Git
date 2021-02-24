#include "Timer.h"

uint_64 ticks;

void Sleep(uint_16 ms)
{
    ticks = 0;
    uint_32 timer_ticks;
    timer_ticks = ticks + ms;

    while(ticks < timer_ticks);
}