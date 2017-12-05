/******************************************************************************
filename    main.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 

Brief Description:
This file implements the main function and game loop.

******************************************************************************/
#include "stdafx.h" /* NULL, bool */
#include "GameStateManager.h"

/* The main program loop */
int main()
{
	/* ------------------------------------------------------------------------ */
	/* Initilization and Setup */
	/* ------------------------------------------------------------------------ */
  system("mode 120,27");   //Set mode to ensure window does not exceed buffer size
  SMALL_RECT WinRect = { 0, 0, 120, 27 };   //New dimensions for window in 8x12 pixel chars
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

  HWND consoleWindow = GetConsoleWindow();

  SetWindowPos(consoleWindow, 0, 405, 225, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
  


	/* Initialize the game state manager. */
	GameStateManagerInit();

	/* ------------------------------------------------------------------------ */
	/* GAME LOOP */
	/* ------------------------------------------------------------------------ */

	/* Loop until the game is no longer running. */
	while (GameStateManagerIsRunning())
	{
		/* Update the game state manager. */
		GameStateManagerUpdate(0.0f);
	}

	/* ------------------------------------------------------------------------ */
	/* Cleanup and Exit */
	/* ------------------------------------------------------------------------ */

	/* Exit the game state manager. */
	GameStateManagerExit();

	/* cleanly exit */
	return 0;
}