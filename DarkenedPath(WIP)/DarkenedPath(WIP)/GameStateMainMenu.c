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
#include "windows.h"
#include "GameStateMainMenu.h"
#include "GameStateManager.h"
#include "Utils.h"
#include "GameStateStory.h"

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
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '/');

  fclose(chp);

	/* Display the name of your text adventure as simple text or ASCII graphics. */
	printf("GAM100 Game\n");

		/* Display the following main menu options: */
		/*   Select an option: */
		/*     (P)lay */
		/*     (Q)uit */
		printf("Select an option:\n(P)lay\n(Q)uit\n");

}

void GameStateMainMenuUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	/* Print the message "Enter command: " to the screen. */
	printf("Enter command: ");

	/* Read the user input. */

		int option = getchar();

		/* Check for 'p' or 'P' to be entered. */
		if (toupper(option) == 'P')
		{
			/* Tell the game state manager to switch to the GsTextAdventure state. */
			GameStateManagerSetNextState(GsStory);
		}
		/* Check for 'q' or 'Q' to be entered. */
		else if (toupper(option) == 'Q')
		{
			/* Tell the game state manager to quit the game (GsQuit). */
			GameStateManagerSetNextState(GsMiku);
		}
		else
		{
			/* Display an error message if an invalid command is entered. */
			printf("Invalid Command! Press P or Q\n");
		}

    if (IsDebuggerPresent())
    {
      if (toupper(option) == 'S')
      {
        strcpy(name, "Bob");

        GameStateManagerSetNextState(GsPlay);
      }
    }

		// flush the buffer
		while (getchar() != '\n')
		{
			// intentionally left blank
		}

}

void GameStateMainMenuExit()
{
	/* Implement an interesting screen transition effect. See function definition in Utils.c. */
	ScreenTransition(3);

	/* Call the utility function to clear the screen (See Utils.h). */
	ClearScreen();
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

