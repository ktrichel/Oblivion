/******************************************************************************/
/*!
\file   GameStateDigiPenLogo.c
\author Kyle Trichel and Drake Mathis
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
	"/########### /###      _ ___ ___   ___ __  _  __ ___ __ __       _     _  _    ",
	"//########## /### ||\\||_  | | | | | | |__ | ||__  | |__|  |_||\\|| ||  | || _|_|",
	" //######### /### || | _| | | | |_| | |__ |_||    | |__|__| || ||_||__|_||_| | ",
	"  ///####### /###                                                              ",
	"    ///////  ///                                                               ",
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
	int k = 4;
	int j;
	int w;
	w = 15;


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
	return 0;
}

void GameStateDigiPenLogoUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

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