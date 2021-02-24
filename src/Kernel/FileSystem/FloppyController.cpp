#include "FloppyController.h"

/*unsigned char floppy_read_data(int base) 
{
    int i;
    for (i = 0; i < 600; i++)
    {
        timer_sleep(1);
        if(0x80 & inb(base+4))
        {
            return inb(base+5);
        }
    }
    panic("floppy_read_data: timeout");
    return 0;
}*/