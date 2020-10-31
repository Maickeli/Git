#pragma once
#include "Typedefs.h"
#include "IO.h"

typedef struct time_t
{
    uint_8 second;
    uint_8 minute;
    uint_8 hour;
    uint_8 weekDay;
    uint_8 monthDay;
    uint_8 month;
    uint_8 year;
};
