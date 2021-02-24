#include "IO.h"

void outb(uint_16 port, uint_8 val)
{
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

uint_16 inb(uint_16 port)
{
    uint_8 ret;
    asm volatile ( "inb %1, %0" : "=a"(ret) : "Nd"(port) );
    return ret;
}

void EnableIRQ()
{
	asm volatile("sti");
}

void PIC_remap()
{
	/*uint_8 a1, a2;
 
	a1 = inb(PIC1_DATA);                        // save masks
	a2 = inb(PIC2_DATA);
 
	outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);  // starts the initialization sequence (in cascade mode)
	outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
	outb(PIC1_DATA, 0);                 // ICW2: Master PIC vector offset
	outb(PIC2_DATA, 8);                 // ICW2: Slave PIC vector offset
	outb(PIC1_DATA, 4);                       // ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
	outb(PIC2_DATA, 2);                       // ICW3: tell Slave PIC its cascade identity (0000 0010)
	outb(PIC1_DATA, ICW4_8086);
	outb(PIC2_DATA, ICW4_8086);
 
	outb(PIC1_DATA, a1);   // restore saved masks.
	outb(PIC2_DATA, a2);*/

	    //Tell PIC's to start the initialization sequence
    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

    //Tell each PIC there offset
    outb(PIC1_DATA, 0x20);
    outb(PIC2_DATA, 0x28);

    //
    outb(PIC1_DATA, 4);
    outb(PIC2_DATA, 2);

    outb(PIC1_DATA, ICW4_8086);
    outb(PIC2_DATA, ICW4_8086);

    //Unmask all interrupts because there is common stub to catch all of them
    outb(PIC1_DATA, 0x0);
    outb(PIC2_DATA, 0x0);
}