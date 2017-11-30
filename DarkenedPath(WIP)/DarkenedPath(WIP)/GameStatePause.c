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
  char choice;

	printf("Would you like to return to the Main Menu?\n");
	printf("(Y)es\n(N)o\n>> ");

	choice = getchar();
  
  ClearScreen();

	if (choice == 'y' || choice == 'Y')
	{
		//printf("DEBUG: QUITTING");
		//Wait(500);

    //flush the buffer
    while (getchar() != '\n');

		GameStateManagerSetNextState(GsMainMenu);
	}
	else if (choice == 'n' || choice == 'N')
	{
    //flush the buffer
    while (getchar() != '\n');

		GameStateManagerSetNextState(GsPlay);
    ClearScreen();
	}
	else
	{
		printf("Please input y or n\n");

    getchar();

    ClearScreen();
	}
}
