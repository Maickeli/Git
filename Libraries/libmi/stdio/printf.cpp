#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

static char *hexToStr(uint_64);
static char *intToStr(int_64);
static char *floatToStr(double, uint_8);

/*int printf(const char *restrict format, ...)
{
    va_list args;
    return 0;
}*/