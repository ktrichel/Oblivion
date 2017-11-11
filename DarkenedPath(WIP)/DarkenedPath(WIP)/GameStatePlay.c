//sudo apt - get install libncurses5 - dev
//#include<curses.h>
#include "stdafx.h"
#include "GameStateTable.h" /* struct GameState */
#include "GameStateManager.h" 

typedef struct
{
	GAMESTATE	current;	/* Index of the current game state. */
	GAMESTATE	previous;	/* Index of the previous game state. */
	GAMESTATE	next;		/* Index of the next game state. */

} GameState;

GameState* gameState; /* The game state, reflecting the user's progress */
/* WorldData* worldData; The world data */ 
/* CommandList* commandList;  The set of supported commands */
/* CommandData* command; The command entered by the user */

char player_input;
void GetInput()
{
	while (gameState != GsQuit)
	{
		player_input = getchar();
	}
}

void GameStatePlayInit()
{
	/* Create the initial game objects. */
	gameState = CreateInitialGameState();
	//worldData = CreateInitialWorldData();
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

	GetInput();
	if (player_input == 'q' || player_input == 'Q')
	{
		GameStatePause();
		printf("Would you like to quit?");
		int choice = getchar();
		if (choice == 'yes' || choice == 'y' || choice == 'Y')
		{
			gameState = GsMainMenu;
		}
		else if (choice == 'no' || choice == 'n' || choice == 'No' || choice == 'N')
		{
			GameStateResume();
		}
		else
		{
			;
		}
	}
}