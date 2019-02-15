void main()
{
	clrscr(0xac);
	print("GILL BATES, GOD OF COMPUTAR SAYS YOU CANT HAVE THE NEWEST VERSION OF MICHAELSOFT", 0xac);
	print("WINBLOWS USE WINDOW 1.0 INSTEAD!!!1!!1!!!!1", 0xac);
	//print("Booting up Michaelsoft Winblows 420.69... Please wait.", 0x07);
	delay(5);
	clrscr(0xF0);
	for(int i = 0; i < 5; i++)
		pad(0, 0x1F);
	center(" __  __ ___ ___ _  _   _   ___ _    ___  ___  ___ _____  ", 0x1F);
	center("|  \\/  |_ _/ __| || | /_\\ | __| |  / __|/ _ \\| __|_   _| ", 0x1F);
	center("| |\\/| || | (__| __ |/ _ \\| _|| |__\\__ \\ (_) | _|  | |   ", 0x1F);
	center("|_|  |_|___\\___|_||_/_/ \\_\\___|____|___/\\___/|_|   |_|(R)", 0x1F);
	for(int i = 0; i < 5; i++)
		pad(0, 0x1F);
	center("Michaelsoft Winblows", 0x1F);
	center("Version 420.69", 0x1F);
	for(int i = 0; i < 7; i++)
		pad(0, 0x1F);
	center("Copyright (c) Michaelsoft Corporation, 2069. All Rights Reserved.", 0x1F);
	center("Michaelsoft is a registered trademark of Michaelsoft Corp.", 0x1F);

	delay(3);
	clrscr(0xF0);
	pad(printchar((char)240, 0xF0) + fill(31, 0x90) + print("MS-DOS Executive", 0x0F) + fill(31, 0x90) + printchar((char)191, 0xF0), 0xF0);
	pad(print(" File View Special", 0xE0), 0xE0);
	pad(print(" A [-=-] B [-=-] ", 0xF0) + print("C [-=-]", 0x0F) + print(" D [-=-] C: \\GILLBATES", 0xF0), 0xF0);
	
	// tab of 16
	pad(printchar(' ', 0xF0) + print("GILLBATES.PNG  ", 0x0F) + print(" ROMAN.FON", 0xF0), 0xF0);
	pad(print(" COURA.FON      ", 0xF0) + print(" WIN.COM", 0xF0), 0xF0);
	pad(print(" COURAB.FON     ", 0xF0) + print(" WIN.INI", 0xF0), 0xF0);
	pad(print(" WIN100.BIN     ", 0xF0) + print(" WINOLDAP.MOD", 0xF0), 0xF0);
	pad(print(" WIN100.OVL     ", 0xF0) + print(" WINOLDAP.GRB", 0xF0), 0xF0);
	pad(print(" CLOCK.EXE      ", 0xF0) + print(" MSDOS.EXE", 0xF0), 0xF0);
	pad(print(" PAINT.EXE      ", 0xF0) + print(" NOTEPAD.EXE", 0xF0), 0xF0);
	pad(print(" WRITE.EXE      ", 0xF0) + print(" SCRIPT.FON", 0xF0), 0xF0);
	pad(print(" CALENDAR.EXE   ", 0xF0) + print(" CALC.EXE", 0xF0), 0xF0);
	pad(print(" README.TXT     ", 0xF0) + print(" OIETIF.EXE", 0xF0), 0xF0);
	pad(print(" TMSRA.FON", 0xF0), 0xF0);
	pad(print(" SPOOLER.EXE", 0xF0), 0xF0);
	pad(print(" TERMINAL.EXE", 0xF0), 0xF0);
	pad(0, 0xF0);
	pad(0, 0xF0);
	pad(0, 0xF0);
	pad(0, 0xF0);
	pad(0, 0xF0);
	pad(0, 0xF0);
	pad(print("<  ", 0xF0) + fill(75, 0xC0) + print(" >", 0xF0), 0xF0);
	pad(0, 0xA0);
	pad(0, 0xA0);
	for(;;) {}
}
