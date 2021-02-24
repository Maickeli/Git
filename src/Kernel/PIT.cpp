#include "PIT.h"

void activateChannel(uint_8 channel, uint_8 mode, uint_64 frequency)
{
	uint_64 f = IRQ_stash_and_disable();
    uint_64 divider = 1193180 / frequency;

    outb(0x43, ((channel & 0x40) ? 0x00 : 0xC0) | 0x30 | mode);
    outb(channel, divider & 0xFF);
    outb(channel, divider >> 8);

	IRQ_restore(f);
}


void play_sound(uint_32 nFrequence) {
 	uint_32 Div;
 	uint_8 tmp;
 
        //Set the PIT to the desired frequency
 	Div = 1193180 / nFrequence;
 	outb(0x43, 0xb6);
 	outb(0x42, (uint_8) (Div) );
 	outb(0x42, (uint_8) (Div >> 8));
 
        //And play the sound using the PC speaker
 	tmp = inb(0x61);
  	if (tmp != (tmp | 3)) {
 		outb(0x61, tmp | 3);
 	}
 }

void nosound() {
    uint_8 tmp = inb(0x61) & 0xFC;

    outb(0x61, tmp);
}