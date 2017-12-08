/******************************************************************************/
/*!
\file   GameStateDigiPenLogo.c
\author Kyle Trichel and David Rodriguez
\par    Course: GAM100F17
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/
#include "stdafx.h"
#include "GameStateDigiPenLogo.h"
#include "GameStateManager.h"

/*------------------------------------------------------------------------------
// Private Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Structures:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Variables:
//----------------------------------------------------------------------------*/
static const char * DigiPenLogo[] =
{
" ,gggggggggggg,                           ,gggggggggggg,                                ,a8a,                                                                                ",
"dP\"\"\"88\"\"\"\"\"\"Y8b,                        dP\"\"\"88\"\"\"\"\"\"Y8,                              ,8\" \"8,                           I8            I8                  I8                ",
"Yb,  88       `8b,                       Yb,  88      `8b                              d8   8b                           I8            I8                  I8                ",
" `\"  88        `8b  gg                gg  `\"  88      ,8P                              88   88                        88888888  gg  88888888            88888888             ",
"     88         Y8  \"\"                \"\"      88aaaad8P\"                               88   88                           I8     \"\"     I8                  I8                ",
"     88         d8  gg     ,gggg,gg   gg      88\"\"\"\"\"    ,ggg,    ,ggg,,ggg,           Y8   8P  ,ggg,,ggg,     ,g,       I8     gg     I8    gg      gg    I8     ,ggg,      ",
"     88        ,8P  88    dP\"  \"Y8I   88      88        i8\" \"8i  ,8\" \"8P\" \"8,          `8, ,8' ,8\" \"8P\" \"8,   ,8'8,      I8     88     I8    I8      8I    I8    i8\" \"8i     ",
"     88       ,8P'  88   i8'    ,8I   88      88        I8, ,8I  I8   8I   8I     8888  \"8,8\"  I8   8I   8I  ,8'  Yb    ,I8,    88    ,I8,   I8,    ,8I   ,I8,   I8, ,8I     ",
"     88______,dP' _,88,_,d8,   ,d8I _,88,_    88        `YbadP' ,dP   8I   Yb,    `8b,  ,d8b, ,dP   8I   Yb,,8'_   8)  ,d88b, _,88,_ ,d88b, ,d8b,  ,d8b, ,d88b,  `YbadP'     ",
"    888888888P\"   8P\"\"Y8P\"Y8888P\"8888P\"\"Y8    88       888P\"Y8888P'   8I   `Y8      \"Y88P\" \"Y88P'   8I   `Y8P' \"YY8P8P88P\"\"Y888P\"\"Y888P\"\"Y888P'\"Y88P\"`Y888P\"\"Y88888P\"Y888    ",
"                               ,d8I'                                                                                                                                         ",
"                             ,dP'8I                                                                                                                                          ",
"                            ,8\"  8I                                                                                                                                          ",
"                            I8   8I                                                                                                                                          ",
"                            `8, ,8I                                                                                                                                          ",
"                             `Y8P\"                                                                                                                                           ",
"                                              ,ggggggggggggggg                                                                                                               ",
"                                  ,dPYb,     dP\"\"\"\"\"\"88\"\"\"\"\"\"\"              ,dPYb,                                ,dPYb,                                                     ",
"                                  IP'`Yb     Yb,_    88                     IP'`Yb                                IP'`Yb                                                     ",
"                                  I8  8I      `\"\"    88                     I8  8I                                I8  8I                                                     ",
"                                  I8  8'             88                     I8  8'                                I8  8'                                                     ",
"                       ,ggggg,    I8 dP              88   ,ggg,     ,gggg,  I8 dPgg,    ,ggg,,ggg,     ,ggggg,    I8 dP    ,ggggg,      ,gggg,gg  gg     gg                  ",
"                      dP\"  \"Y8ggg I8dP               88  i8\" \"8i   dP\"  \"Yb I8dP\" \"8I  ,8\" \"8P\" \"8,   dP\"  \"Y8ggg I8dP    dP\"  \"Y8ggg  dP\"  \"Y8I  I8     8I                  ",
"                     i8'    ,8I   I8P          gg,   88  I8, ,8I  i8'       I8P    I8  I8   8I   8I  i8'    ,8I   I8P    i8'    ,8I   i8'    ,8I  I8,   ,8I                  ",
"                    ,d8,   ,d8'  ,d8b,_         \"Yb,,8P  `YbadP' ,d8,_    _,d8     I8,,dP   8I   Yb,,d8,   ,d8'  ,d8b,_ ,d8,   ,d8'  ,d8,   ,d8I ,d8b, ,d8I                  ",
"                    P\"Y8888P\"    PI8\"8888         \"Y8P' 888P\"Y888P\"\"Y8888PP88P     `Y88P'   8I   `Y8P\"Y8888P\"    8P'\"Y88P\"Y8888P\"    P\"Y8888P\"888P\"\"Y88P\"888                 ",
"                                  I8 `8,                                                                                                    ,d8I'      ,d8I'                 ",
"                                  I8  `8,                                                                                                 ,dP'8I     ,dP'8I                  ",
"                                  I8   8I                                                                                                ,8\"  8I    ,8\"  8I                  ",
"                                  I8   8I                                                                                                I8   8I    I8   8I                  ",
"                                  I8, ,8'                                                                                                `8, ,8I    `8, ,8I                  ",
"                                   \"Y8P'                                                                                                  `Y8P\"      `Y8P\"                   ",
};












/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/


void GameStateDigiPenLogoInit()
{
	HANDLE  hConsole;
	int k = 5;
	int j;
	int w;
	w = 15;


	HWND console = GetConsoleWindow();

	system("mode 175,35");   //Set mode to ensure window does not exceed buffer size
	SMALL_RECT WinRect = { 0, 0, 175, 35 };   //New dimensions for window in 8x12 pixel chars
	SMALL_RECT* WinSize = &WinRect;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

	HWND consoleWindow = GetConsoleWindow();


	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	/* you can loop k higher to see more color choices */
	/* if echo does not work delete for look and set k = a value i.e k=4 */

	for (j = 0; j < _countof(DigiPenLogo); j++)
	{
		SetConsoleTextAttribute(hConsole, k);

		printf("%s\n", DigiPenLogo[j]);
	}
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, w);
	Wait(500);
	return;
}

void GameStateDigiPenLogoUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	/* Print the message "copyright..." to the screen. */
	printf("Copyright 2017 Digipen (USA) Corporation \n");
	
	/* Print the message "Press ENTER to continue..." to the screen. */
	printf("Press any button to continue...");

	/* Wait for the user to press ENTER. */
	getch();

	/* Tell the game state manager to switch to the Main Menu state. */
	GameStateManagerSetNextState(GsMainMenu);
}

void GameStateDigiPenLogoExit()
{
	/* Implement an interesting screen transition effect. See function definition in Utils.c. */
	ScreenTransition(3);

	/* Call the utility function to clear the screen (See Utils.h). */
	ClearScreen();
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/