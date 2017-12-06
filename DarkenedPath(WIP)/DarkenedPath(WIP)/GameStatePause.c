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

	choice = getch();
  
  ClearScreen();

	if (choice == 'y' || choice == 'Y')
	{
		//printf("DEBUG: QUITTING");
		//Wait(500);

		GameStateManagerSetNextState(GsMainMenu);
	}
	else if (choice == 'n' || choice == 'N')
	{
		GameStateManagerSetNextState(GsPlay);
    ClearScreen();
	}
	else
	{
		printf("Please input y or n\n");

    getch();

    ClearScreen();
	}
}
