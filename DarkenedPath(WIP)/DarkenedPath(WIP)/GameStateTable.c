/******************************************************************************/
/*!
\file   GameStateTable.c
\author Kyle Trichel and Drake Mathis
\par    Course: GAM100F17
\par    Copyright � 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/

#include "stdafx.h"
#include "GameStateManager.h"
#include "GameStateTable.h"

/* Include all game state headers here. */
#include "GameStateDigiPenLogo.h"
#include "GameStateMiku.h"
#include "GameStateMainMenu.h"
#include "GameStateGameOver.h"
#include "GameStatePlay.h"
#include "GameStatePause.h"
#include "GameStateStory.h"

/*------------------------------------------------------------------------------
// Private Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Structures:
//----------------------------------------------------------------------------*/

typedef void(*GameStateVoidFunctionPtr)();
typedef void(*GameStateDtFunctionPtr)(float dt);

typedef struct
{
	GameStateVoidFunctionPtr	gameStateInit;		/* Pointer to a game state initialization function. */
	GameStateDtFunctionPtr		gameStateUpdate;	/* Pointer to a game state update function. */
	GameStateVoidFunctionPtr	gameStateExit;		/* Pointer to a game state exit function. */

} GameStateTableEntry;

/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Variables:
//----------------------------------------------------------------------------*/

static const GameStateTableEntry GameStateTab[GsMax] =
{
	/* DigiPen Logo */
	{ GameStateDigiPenLogoInit, GameStateDigiPenLogoUpdate, GameStateDigiPenLogoExit },
	/* Main Menu */
	{ GameStateMainMenuInit, GameStateMainMenuUpdate, GameStateMainMenuExit },
	/* Story Transition Screen */
	{ GameStateStoryInit, GameStateStoryUpdate, GameStateStoryExit },
	/* Text Adventure */
	{ GameStatePlayInit, GameStatePlayUpdate, GameStatePlayExit },
	/* Pause */
	{ GameStatePauseInit, GameStatePauseUpdate, GameStatePauseExit },
	/* Miku */
	{ GameStateMikuInit, GameStateMikuUpdate, GameStateMikuExit },
	/* Game Over */
	{ GameStateGameOverInit, GameStateGameOverUpdate, GameStateGameOverExit },
};

/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Determine if the game state is valid. */
bool GameStateIsValid(GAMESTATE gameState)
{
	return ((0 <= gameState) && (gameState < GsMax));
}

/*----------------------------------------------------------------------------*/
/* Determine if the game state is a "special" game state. */
bool GameStateIsSpecial(GAMESTATE gameState)
{
	return ((gameState == GsRestart) || (gameState == GsQuit));
}

/*----------------------------------------------------------------------------*/
/* Execute the Init function for the current game state. */
void GameStateExecuteInit(GAMESTATE gameState)
{
	/* First validate the game state and the function pointer. */
	if (GameStateIsValid(gameState) &&
		((*GameStateTab[gameState].gameStateInit) != NULL))
	{
		/* Execute the Init function. */
		(*GameStateTab[gameState].gameStateInit)();
	}
}

/*----------------------------------------------------------------------------*/
/* Execute the Update function for the current game state. */
void GameStateExecuteUpdate(GAMESTATE gameState, float dt)
{
	/* First validate the game state and the function pointer. */
	if (GameStateIsValid(gameState) &&
		((*GameStateTab[gameState].gameStateUpdate) != NULL))
	{
		/* Execute the Update function. */
		(*GameStateTab[gameState].gameStateUpdate)(dt);
	}
}

/*----------------------------------------------------------------------------*/
/* Execute the Exit function for the current game state. */
void GameStateExecuteExit(GAMESTATE gameState)
{
	/* First validate the game state and the function pointer. */
	if (GameStateIsValid(gameState) &&
		((*GameStateTab[gameState].gameStateExit) != NULL))
	{
		/* Execute the Exit function. */
		(*GameStateTab[gameState].gameStateExit)();
	}
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

