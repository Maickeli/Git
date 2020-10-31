#include "RTC.h"

time_t globalTime;
bool bcd;

uint_8 readRegister(uint_8 reg)
{
    outb(0x70, reg);
    return inb(0x71);
}

void write_register(uint_8 reg, uint_8 value)
{
    outb(0x70, reg);
    outb(0x71, value);
}

uint_8 bcd2bin(uint_8 bcd)
{
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

void getTime(time_t *time)
{
    //memcpy(time, &globalTime, sizeof(time_t)); 

     
}
