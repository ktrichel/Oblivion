/******************************************************************************/
/*!
\file   GameStateMainMenu.c
\author Kyle Trichel and Drake Mathis
\par    Course: GAM100F17
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
#include "Character.h"

/*------------------------------------------------------------------------------
// Private Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Structures:
//----------------------------------------------------------------------------*/
struct CHARACTER player;
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
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '/');

  fclose(chp);

  FILE *fT = fopen("FirstTime.txt", "w");
  if (fT == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(fT, "%c", '0');

  fclose(fT);

	/* Display the name of your text adventure as simple text or ASCII graphics. */
	printf("Darkened Path\n");

		/* Display the following main menu options: */
		/*   Select an option: */
		/*     (P)lay */
		/*     (Q)uit */
		printf("Select an option:\n(P)lay\n(C)redits\n(Q)uit\n");

}

void GameStateMainMenuUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	/* Print the message "Enter command: " to the screen. */
	printf("Enter command: ");

	/* Read the user input. */

		int option = getch();

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
    else if (toupper(option) == 'Q')
    {
      GameStateManagerSetNextState(GsCredits);
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
        FILE *chp;
        chp = fopen("chp.txt", "w");
        char ch;
        if (chp == NULL)
        {
          printf("Cannot open file for writing.\n");
          exit(0);
        }

        fprintf(chp, "%c", '0');

        fclose(chp);

        strcpy(name, "Bob");

        GameStateManagerSetNextState(GsPlay);
      }
    }
}

void GameStateMainMenuExit()
{

  strcpy(player.name, name);
  player.maxhealth = 10;
  player.health = 10;
  player.defense = 1;
  player.attack = 3;
  player.experience = 0;
  player.level = 1;

  FILE *playerStats = fopen("Player.txt", "w");
  char *ps[20] = { "" };
  int i = 0;
  if (playerStats == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(playerStats, "%s\n%i\n%i\n%i\n%i\n%i\n%i", player.name, player.maxhealth, player.health, player.defense, player.attack, player.experience, player.level);
  fclose(playerStats);

	/* Implement an interesting screen transition effect. See function definition in Utils.c. */
	ScreenTransition(3);

	/* Call the utility function to clear the screen (See Utils.h). */
	ClearScreen();
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

