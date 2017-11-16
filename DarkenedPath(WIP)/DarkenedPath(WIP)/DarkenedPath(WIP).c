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
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1000, 500, TRUE); // 800 width, 100 height

	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, 350, 250, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

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