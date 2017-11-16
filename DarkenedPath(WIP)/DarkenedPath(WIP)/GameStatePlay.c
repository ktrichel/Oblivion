//sudo apt - get install libncurses5 - dev
//#include<curses.h>
#include "stdafx.h"
#include "GameStatePlay.h"

/* GameState* gameState; The game state, reflecting the user's progress */
/* WorldData* worldData; The world data */ 
/* CommandList* commandList;  The set of supported commands */
/* CommandData* command; The command entered by the user */

char player_input;

void GetInput()
{
	ClearScreen();
	printf("Press q to quit: ");
	player_input = getchar();

	if (player_input == 'q' || player_input == 'Q')
	{
		GameStatePause();
	}

	// flush the buffer
	while (getchar() != '\n')
	{
		// intentionally left blank
	}
}

void GameStatePlayExit()
{
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
void GameStatePause() 
{
	ClearScreen();
	printf("DEBUG: PAUSED\n");
	Wait(500);

	char choice;

	printf("Would you like to quit?\n");
	printf("(Y)es\n(N)o\n");
	choice = getchar();
	if (choice == 'y' || choice == 'Y')
	{
		printf("DEBUG: QUITTING");
		Wait(500);
		GameStateManagerSetNextState(GsQuit);
	}
	else if (choice == 'n' || choice == 'N')
	{
		GameStateResume();
	}
}

void GameStateResume()
{
	printf("DEBUG: RESUMED\n");
}

void GameStatePlayUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	GetInput();
}