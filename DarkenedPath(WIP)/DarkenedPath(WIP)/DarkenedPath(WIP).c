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