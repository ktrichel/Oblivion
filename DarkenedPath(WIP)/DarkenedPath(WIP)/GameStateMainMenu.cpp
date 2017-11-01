/******************************************************************************/
/*!
	\file   GameStateMainMenu.c
	\author Doug Schilling
	\par    Course: GAM100
	\par    Copyright © 2016 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#include "stdafx.h"
#include "GameStateMainMenu.h"
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

/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

void GameStateMainMenuInit()
{
	/* TODO BASIC: Display the name of your text adventure as simple text or ASCII graphics. */
	printf("GAM100 TEXT ADVENTURE!!!\n");

		/* TODO REQUIRED: Display the following main menu options: */
		/*   Select an option: */
		/*     (P)lay */
		/*     (Q)uit */
		printf("Select an option:\n(P)lay\n(Q)uit\n");

	/* TODO ADVANCED: Implement one or more functions, such as PrintIndent() or PrintCentered(),
		 that procedurally determine where to display strings of text on the screen.
		 For example: PrintIndent(20, "(P)lay"); will display "(P)lay" starting at the 20th column.
		 Use these functions to display the menu text in a nicely presented fashion. */
}

void GameStateMainMenuUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	/* TODO BASIC: Print the message "Enter command: " to the screen. */
	printf("Enter command: ");

	/* TODO: Read the user input. */

		int option = getchar();

		/* TODO REQUIRED: Check for 'p' or 'P' to be entered. */
		if (option == 'p' || option == 'P')
		{
			/* TODO REQUIRED: Tell the game state manager to switch to the GsTextAdventure state. */
			GameStateManagerSetNextState(GsTextAdventure);
		}
		/* TODO REQUIRED: Check for 'q' or 'Q' to be entered. */
		else if (option == 'q' || option == 'Q')
		{
			/* TODO REQUIRED: Tell the game state manager to quit the game (GsQuit). */
			GameStateManagerSetNextState(GsQuit);
		}
		else
		{
			/* TODO ADVANCED: Display an error message if an invalid command is entered. */
			printf("Invalid Command! Press P or Q\n");
		}

		// flush the buffer
		while (getchar() != '\n')
		{
			// intentionally left blank
		}

}

void GameStateMainMenuExit()
{
	/* TODO ADVANCED: Implement an interesting screen transition effect. See function definition in Utils.c. */
	ScreenTransition();

	/* TODO BASIC: Call the utility function to clear the screen (See Utils.h). */
	ClearScreen();
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

