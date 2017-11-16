#include <stdio.h>
#include <windows.h>   /* WinApi header */

int main()
{
	HANDLE  hConsole;
	int k;
	int j;
	int w;
	w = 15;


	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	static const char * DigiPenLogo[] =
	{
		"                                _______                  ________              ",
		"             /### /#######     |       \\                |        \\             ",
		"             /### /#########   |        \\  _          _ |   ___   |            ",
		"             /### /##########  |    |    ||_|        |_||         |            ",
		"             /### /########### |    |    | _   ____   _ |    ____/____   _____ ",
		"             /### /########### |    |    || | /    \\ | ||   |    /    \\ |     \\",
		"             /### /##########  |    |    || ||  __  || ||   |   |  --  ||     |",
		"             /### /#########   |        / | ||      || ||   |   |  ____||  |  |",
		"             /### /#######/    |_______/  |_| \\___  ||_||___|    \\____\\ |__|__|",
		"    /####### /### ///////                     /     |                          ",
		"  /######### /###                             \\____/                           ",
		" /########## /###                                                              ",
		"/########### /###                                                              ",
		"/########### /###      _____ ___   ___ __  _  __ ___ __ __       _     _  _    ",
		"//########## /### ||\\||_  | | | | | | |__ | ||__  | |__|  |_||\\|| ||  | || _|_|",
		" //######### /### || |__| | | | |_| | |__ |_||    | |__|__| || ||_||__|_||_| | ",
		"  ///####### /###                                                              ",
		"    ///////  ///                                                               ",
	};

	/* you can loop k higher to see more color choices */
	/* if echo does not work delete for look and set k = a value i.e k=4 */
	for (k = 1; k < 16; k++)
	{
		for (j = 0; j < _countof(DigiPenLogo); j++)
		{
			SetConsoleTextAttribute(hConsole, k);

			printf("%s\n", DigiPenLogo[j]);
		}
	}
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, w);
	getchar();  /* wait */
	return 0;
}
