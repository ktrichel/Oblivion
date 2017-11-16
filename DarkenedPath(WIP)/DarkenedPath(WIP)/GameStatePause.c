#include "stdafx.h"
#include "GameStatePause.h"

struct MyStruct
{
	int word;
};

void GameStatePauseInit()
{
}

void GameStatePauseExit()
{
	ScreenTransition(2);

	ClearScreen();
}

void GameStatePauseUpdate(float dt)
{
	//printf("DEBUG: PAUSED\n");
	//Wait(500);


	printf("Would you like to return to the Main Menu?\n");
	printf("(Y)es\n(N)o\n>> ");

	char choice = getchar();

	if (choice == 'y' || choice == 'Y')
	{
		//printf("DEBUG: QUITTING");
		//Wait(500);
		GameStateManagerSetNextState(GsMainMenu);
	}
	else if (choice == 'n' || choice == 'N')
	{
		ClearScreen();
		GameStateManagerSetNextState(GsPlay);
	}
	else
	{
		ClearScreen();
		printf("Please input y or n\n");
	}

	// flush the buffer
	while (getchar() != '\n')
	{
		// intentionally left blank
	}
}
