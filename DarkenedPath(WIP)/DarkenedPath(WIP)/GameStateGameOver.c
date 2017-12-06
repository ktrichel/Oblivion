/******************************************************************************/
/*!
	\file   GameStateGameOver.c
	\author Doug Schilling
	\par    Course: GAM100
	\par    Copyright © 2016 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#include "stdafx.h"
#include "GameStateGameOver.h"
#include "GameStateManager.h"
#include "Utils.h"
#include <Windows.h>

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

void GameStateGameOverInit()
{
  HWND console = GetConsoleWindow();

  system("mode 123,34");   //Set mode to ensure window does not exceed buffer size
  SMALL_RECT WinRect = { 0, 0, 123, 34 };   //New dimensions for window in 8x12 pixel chars
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

  HWND consoleWindow = GetConsoleWindow();

  SetWindowPos(consoleWindow, 0, 460, 120, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void GameStateGameOverUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

  FILE *gameOver;
  char *s[162];
  gameOver = fopen("gameover.txt", "rt");
  if (gameOver == NULL)
  {
    printf("Cannot open file for reading.\n");
    exit(0);
  }
  while (fgets(s, 162, gameOver))
  {
    printf("%s", s);
  }
  fclose(gameOver);

	getch();

  GameStateManagerSetNextState(GsMainMenu);
}

void GameStateGameOverExit()
{
	ScreenTransition(2);
  ClearScreen();
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

