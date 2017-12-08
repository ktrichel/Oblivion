/******************************************************************************/
/*!
\file   GameStateMiku.c
\author Kyle Trichel and David Rodriguez
\par    Course: GAM100F17
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/
#include "stdafx.h"
#include "GameStateMiku.h"
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

/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

void GameStateMikuInit()
{
	/*------------------------------------------------------------------------------
	// Setting Windows Console Size
	//----------------------------------------------------------------------------*/
	HWND console = GetConsoleWindow();

  system("mode 160,63");   //Set mode to ensure window does not exceed buffer size
  SMALL_RECT WinRect = { 0, 0, 160, 63 };   //New dimensions for window in 8x12 pixel chars
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, 300, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	/*------------------------------------------------------------------------------
	// Setting Windows Console Text Color
	//----------------------------------------------------------------------------*/
	HANDLE  hConsole;
	int k = 11;
	int w;
	w = 15;


	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	/* you can loop k higher to see more color choices */
	/* if echo does not work delete for look and set k = a value i.e k=4 */


    FILE *pfile = fopen("miku.txt", "r");
    char *s[162];
    if (pfile == NULL)
    {
      printf("Cannot open file for reading.\n");
      exit(0);
    }
    while (fgets(s, 162, pfile))
    {
      SetConsoleTextAttribute(hConsole, k);
      printf("%s", s);
    }

    fclose(pfile);

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, w);
	Wait(500);
}

void GameStateMikuUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	/* Wait for the user to press ENTER. */
	Wait(2000);

	/* Tell the game state manager to switch to the Main Menu state. */
	GameStateManagerSetNextState(GsQuit);
}

void GameStateMikuExit()
{
	/* Implement an interesting screen transition effect. See function definition in Utils.c. */
	ScreenTransition(3);

	/* Call the utility function to clear the screen (See Utils.h). */
	ClearScreen();
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/