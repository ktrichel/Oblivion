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
	/* NOTE: There is nothing to be done here.  The game results text was
		 printed to the screen before this game state was initiated. */
}

void GameStateGameOverUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	/* Print the message "Press ENTER to continue..." to the screen. */

	/* Wait for the user to press ENTER. */
	getchar();

	/* Tell the game state manager to switch to the Main Menu state. */
}

void GameStateGameOverExit()
{
	/* Implement an interesting screen transition effect. See function definition in Utils.c. */
	/*ScreenTransition();*/

	/* Call the utility function to clear the screen (See Utils.h). */
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

