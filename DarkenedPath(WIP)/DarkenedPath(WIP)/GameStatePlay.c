//sudo apt - get install libncurses5 - dev
//#include<curses.h>
#include "stdafx.h"
#include "Character.h"
#include "GameStatePlay.h"

/*************************************************************************
*                        Struct Declarations                             *
**************************************************************************/
CHARACTER enemy1 = { "Grunt", 5, 1, 3 };
CHARACTER player;

/*************************************************************************
*                          Global Variables                              *
**************************************************************************/
int *firstTime;

void GameStatePlayInit()
{
  strcpy(player.name, name);
  player.health = 10;
  player.defense = 0;
  player.attack = 2;

  if (firstTime != 0)
  {
    firstTime = 1;
  }
  else
  {
    firstTime = 0;
  }
}



void calcDmg()
{
  int r;
  srand(time(NULL));
  r = (rand() % 3) + 1;

  printf("You ready the torch you picked up to fight.\n");
  printf("The grunt is wearing mismatched pieces of armor and a rusty sword, it's clear that they were unprepared for you to be here.\n");
  printf("You have three options:\n1: normal strike\n2. heavy strike\n3. dodge");

	player.health -= (enemy1.attack - player.defense);
	enemy1.health -= (player.attack - enemy1.defense);
}


void GameStatePlayUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);
  printf("A grunt appears and won't let you leave the dungeon.\n");
  if (firstTime)
  {
    printf("HINT: Press 'a' to begin the fight, or press 'q' to go to the pause menu.\n");
    printf("Press 'h' at anytime to be reminded of the controls.\n");
    firstTime = 0;
  }
	printf("Enter Command\n>> ");
	char player_input = getch();

	if (toupper(player_input) == 'Q')
	{
    ClearScreen();
		GameStateManagerSetNextState(GsPause);
	}
	else if (toupper(player_input) == 'A')
	{
    ClearScreen();
    calcDmg();
	}
  else if (toupper(player_input) == 'H')
  {
    ClearScreen();
    printf("HELP: Press 'a' to begin the fight, or press 'q' to go to the pause menu.\n");
  }
}

void GameStatePlayExit()
{
	ScreenTransition(2);

	ClearScreen();
}