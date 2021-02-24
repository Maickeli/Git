#include "RTC.h"


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



const char* dateTime()
{
    uint_8 second = readRegister(0x00);
    uint_8 minute = readRegister(0x02);
    uint_8 hour = readRegister(0x04);
    uint_8 day = readRegister(0x07);
    uint_8 month = readRegister(0x08);
    uint_8 year = readRegister(0x09);

    const char* date = combineStr(HexToString(hour), ":");
    date = combineStr(date, HexToString(minute));
    date = combineStr(date, " ");
    date = combineStr(date, HexToString(day));
    date = combineStr(date, ".");
    date = combineStr(date, HexToString(month));
    date = combineStr(date, ".");
    date = combineStr(date, "20");  
    date = combineStr(date, HexToString(year));  
    return date; 
}
