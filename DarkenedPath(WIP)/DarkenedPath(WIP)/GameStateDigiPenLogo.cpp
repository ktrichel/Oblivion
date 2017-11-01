/******************************************************************************/
/*!
	\file   GameStateDigiPenLogo.c
	\author Doug Schilling
	\par    Course: GAM100
	\par    Copyright © 2016 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#include "stdafx.h"
#include "GameStateDigiPenLogo.h"
#include "GameStateManager.h"
#include "Utils.h"

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
"/########### /###      _____ ___   ___ __  _  __ ___ __ __       _     _  _    ",
"//########## /### ||\\||_  | | | | | | |__ | ||__  | |__|  |_||\\|| ||  | || _|_|",
" //######### /### || |__| | | | |_| | |__ |_||    | |__|__| || ||_||__|_||_| | ",
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
	/* TODO BASIC: Print the DigiPen Logo to the screen. */

	/* First, determine the number of lines in the logo.  Hint "_countof(DigiPenLogo)" */
	_countof(DigiPenLogo);

	/* Second, print each line in the DigiPenLogo[] array. */
	for (size_t i = 0; i < _countof(DigiPenLogo); i++)
	{
		printf("%s", DigiPenLogo[i]);
	}

	/* Third, print a couple extra blank lines. */
	printf("\n\n");
}

void GameStateDigiPenLogoUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	/* TODO BASIC: Print the message "Press ENTER to continue..." to the screen. */
	printf("Press ENTER to continue...");

	/* TODO : Wait for the user to press ENTER. */
	getchar();

	/* TODO REQUIRED: Tell the game state manager to switch to the Main Menu state. */
	GameStateManagerSetNextState(GsMainMenu);
}

void GameStateDigiPenLogoExit()
{
	/* TODO ADVANCED: Implement an interesting screen transition effect. See function definition in Utils.c. */
	ScreenTransition();

	/* TODO BASIC: Call the utility function to clear the screen (See Utils.h). */
	ClearScreen();
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

