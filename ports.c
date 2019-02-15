typedef unsigned char byte;

byte inb(unsigned short);
void outb(unsigned short, byte);
unsigned short bios_call(int);

void delay(int secs) 
{
	int x;
	while (secs--) 
	{
		x = bios_call(0);
		while (bios_call(0) == x);
	}
	return;
}

unsigned short bios_call(int data_a)
{
	byte data_b;
	outb(0x70, data_a);
	data_b = inb(0x71);
	return data_b;
}

void outb(unsigned short port, byte value)
{
	asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
}

byte inb(unsigned short port)
{
	byte ret;
	asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
	return ret;
}