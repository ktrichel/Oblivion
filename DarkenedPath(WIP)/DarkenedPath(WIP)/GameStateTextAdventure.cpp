/******************************************************************************/
/*!
	\file   GameStateTextAdventure.c
	\author Doug Schilling
	\par    Course: GAM100
	\par    Copyright � 2016 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#include "stdafx.h"
#include "GameStateTextAdventure.h"
#include "GameStateManager.h"
#include "Utils.h"

#include "InputProvider.h" /* GetDefaultInputFunc, ParseCommand */
#include "CommandData.h" /* struct CommandData */
#include "CommandListFactory.h" /* CreateCommandList */
#include "CommandList.h" /* CommandList_Free */
#include "CommandHandler.h" /* HandleCommand */
#include "GameStateFactory.h" /* CreateInitialGameState */
#include "GameState.h" /* struct GameState */
#include "WorldDataFactory.h" /* CreateTestWorldData */
#include "WorldData.h" /* WorldData_PrintIntroduction, WorldData_Free */

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

/* TODO REQUIRED: Declare the GameState, WorldData, CommandList & CommandData variables. */

/* ------------------------------------------------------------------------ */
/* Initilization and Setup */
/* ------------------------------------------------------------------------ */
GameState* gameState; /* The game state, reflecting the user's progress */
WorldData* worldData; /* The world data */
CommandList* commandList; /* The set of supported commands */
CommandData command; /* The command entered by the user */

/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

void GameStateTextAdventureInit()
{
	/* TODO REQUIRED: Create the initial game objects. */

	/* create the initial game objects */
	gameState = CreateInitialGameState();
	worldData = CreateInitialWorldData();
	commandList = CreateCommandList();

	/* TODO REQUIRED: Initialize the commands. */

	/* initialize the command CommandData values */
	command.commandList = commandList;
	command.context = CommandContext_User;

	/* TODO REQUIRED: Print the world introduction. */

	/* print the world introduction*/
	WorldData_PrintIntroduction(worldData, gameState->currentRoomIndex);

}

void GameStateTextAdventureUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	/* TODO BASIC: Print the command prompt "\nWhat is your command?\n>> " to the screen. */

	/* print command prompt */
	printf("\nWhat is your command?\n>> ");

	/* TODO REQUIRED: Accept user input and handle the command. */

	/* accept user input */
	ParseCommand(GetDefaultInputFunc(), &command);

	/* include an empty line before printing the result of a command */
	printf("\n");

	/* handle the command */
	HandleCommand(&command, gameState, worldData);

}

void GameStateTextAdventureExit()
{
	/* TODO REQUIRED: Cleanup and exit the WorldData, GameState and CommandList modules. */

	/* ------------------------------------------------------------------------ */
	/* Cleanup and Exit */
	/* ------------------------------------------------------------------------ */
	WorldData_Free(&worldData);
	GameState_Free(&gameState);
	CommandList_Free(&commandList);

	/* wait for input before closing the command window */
	getchar();


	/* NOTE: Do NOT clear the screen.  The game results text is currently displayed
		 on the screen and the user will be given time to read this text within the
		 GameOver game state. */
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

