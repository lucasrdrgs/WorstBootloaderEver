typedef unsigned char byte;
byte* vram = (byte*) 0xB8000;

const unsigned int SCREEN_WIDTH = 80;
const unsigned int SCREEN_HEIGHT = 25;

unsigned int ROW;
unsigned int COLUMN;

int strlen(const char* str) 
{
	int len = 0;
	while (str[len]) // while the char at the current index is not zero
		len++;
	return len;
}

void resetVram()
{
	ROW = 0;
	COLUMN = 0;
	vram = (byte*) 0xB8000;
}

void clrscr(unsigned short att)
{
	resetVram();
	const long size = SCREEN_WIDTH * SCREEN_HEIGHT;
	for(int i = 0; i < size; i++)
	{
		*vram++ = ' ';
		*vram++ = att;
	}
	resetVram();
}

void gotoxy(int x, int y)
{
	resetVram();
	int coord = x + (80 * y);
	if(coord < 0) coord = 0;
	if(coord > 80*25) coord = 80*25;
	for(int i = 0; i < 80 * 25; i++)
	{
		if(i == coord)
			break;
		else vram += 2;
	}
}

int printchar(char c, int att)
{
	*vram++ = c;
	*vram++ = att;
	if(++COLUMN == SCREEN_WIDTH)
	{
		COLUMN = 0;
		if(++ROW == SCREEN_HEIGHT)
			ROW = 0;
	}
	return 1;
}

int print(const char* msg, int att)
{
	int i = 0;
	for(i = 0; i < strlen(msg); i++)
		printchar(msg[i], att);
	return i;
}

int pad(int amt, int att)
{
	for(int i = 0; i < 80 - amt; i++)
		printchar(' ', att);
	return 80 - amt;
}

int center(char * msg, int att)
{
	int x = 40 - (strlen(msg) / 2);
	return pad(fill(x, att) + print(msg, att), att);
}

int fill(int amt, int att)
{
	return pad(80 - amt, att);
}