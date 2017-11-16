//sudo apt - get install libncurses5 - dev
//#include<curses.h>
#include "stdafx.h"
#include "GameStatePlay.h"

/* GameState* gameState; The game state, reflecting the user's progress */
/* WorldData* worldData; The world data */ 
/* CommandList* commandList;  The set of supported commands */
/* CommandData* command; The command entered by the user */



void GameStatePlayExit()
{
	ScreenTransition(2);

	ClearScreen();
}

void GameStatePlayInit()
{
	/* Create the initial game objects. */
	/*gameState = CreateInitialGameState(); */
	/*worldData = CreateInitialWorldData(); */
	//commandList = CreateCommandList();

	/* Initialize the commands. */
	//command.commandList = commandList;
	//command.context = CommandContext_User;

	/* Print the world introduction. */
	//WorldData_PrintIntroduction(worldData, gameState->currentRoomIndex);

}


void GameStatePlayUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);


	printf("Enter Command: ");

	char player_input = getchar();

	if (player_input == 'q' || player_input == 'Q')
	{
		GameStateManagerSetNextState(GsPause);
	}

	// flush the buffer
	while (getchar() != '\n')
	{
		// intentionally left blank
	}
}