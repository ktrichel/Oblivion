//sudo apt - get install libncurses5 - dev
//#include<curses.h>
#include "stdafx.h"
#include "GameStatePlay.h"

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
	int choice;
	while (gameState != GsQuit)
	{
		player_input = getchar();
		if (player_input == 'q' || player_input == 'Q')
		{
			GameStatePause();
			printf("Would you like to quit?\n");
			printf("(Y)es\n(N)o\n");
			choice = getchar();
			if (choice == 'y' || choice == 'Y')
			{
				GameStateManagerSetNextState(GsQuit);
			}
			else if (choice == 'n' || choice == 'N')
			{
				GameStateResume();
			}
			else
			{
				getchar();
			}
		}
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
}

void GameStateResume()
{
	printf("resumed");
}
void GameStatePlayUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);

	GetInput();
}