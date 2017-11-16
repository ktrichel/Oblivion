//sudo apt - get install libncurses5 - dev
//#include<curses.h>
#include "stdafx.h"
#include "Character.h"
#include "GameStatePlay.h"
/* GameState* gameState; The game state, reflecting the user's progress */
/* WorldData* worldData; The world data */ 
/* CommandList* commandList;  The set of supported commands */
/* CommandData* command; The command entered by the user */

int player;
int enemy;

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
	player = 0;
	enemy = 0;
}
/*
void calcDmg()
{
	player.health = player.health - (player.defense - enemy1.attack);
	enemy1.health = enemy1.health - (enemy1.defense - player.attack);
}
*/

void GameStatePlayUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);
	int r;
/*	printf("%s:\nHealth - %d\nDefense - %d\nStrength - %d\n\n", player.name, player.health, player.defense, player.attack);
	printf("%s:\nHealth - %d\nDefense - %d\nStrength - %d\n\n", enemy1.name, enemy1.health, enemy1.defense, enemy1.attack); */
	printf("Enter Command\n>> ");
	char player_input = getch();

	if (toupper(player_input) == 'Q')
	{
		GameStateManagerSetNextState(GsPause);
	}
	else if (toupper(player_input) == 'A')
	{
		srand(time(NULL));
		r = (rand() % 5) + 1;
		printf("\nPlayer attacks for %i damage\n", r);
		player += r;
		Wait(500);
		r = (rand() % 5) + 1;
		printf("Enemy retaliates with %i damage\n", r);
		enemy += r;


		if (player >= 20)
		{
			printf("Congratulations you killed the enemy!\n");
			Wait(500);
			do
			{
				printf("(R)estart?\n");
				player_input = getch();
			} while (toupper(player_input) != 'R');
			GameStatePlayInit();
			ClearScreen();
		}
		else if (enemy >= 20)
		{
			printf("Oh no, the enemy killed you!\n");
			Wait(1000);
			GameStateManagerSetNextState(GsMainMenu);
		}
	}
	/*else if (player_input == 'a' || player_input == 'A')
	{ 
		calcDmg();
	}*/
	// flush the buffer
	//while (getch() != '\n')
	//{
		// intentionally left blank
	//}
}