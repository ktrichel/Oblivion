//sudo apt - get install libncurses5 - dev
//#include<curses.h>
#include "stdafx.h"
#include "Character.h"
#include "GameStatePlay.h"

/*************************************************************************
*                        Struct Declarations                             *
**************************************************************************/
CHARACTER enemy1;
CHARACTER enemy2;
CHARACTER enemy3;
CHARACTER miniBoss;
CHARACTER player;
char drop1[];
char drop2[];
char drop3[];

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
  player.experience = 0;

  if (firstTime != 0)
  {
    firstTime = 1;
  }
  else
  {
    firstTime = 0;
  }
}
void getEnemyType(char name[20])
{
  if (name == "Grunt")
  {
    strcpy(drop1, "Rusty Sword");
    strcpy(drop2, "Broken Chainmail");
    strcpy(drop3, "Burnt Helmet");
  }
}
void EnemyInit(int enemy)
{
  if (enemy = 1)
  {
    enemy1.health = 3 * enemy1.level + enemy1.level;
    enemy1.defense = 1 * enemy1.level + enemy1.level;
    enemy1.attack = 2 * enemy1.level + enemy1.level;
    enemy1.experience = enemy1.level * 10;
  }
  if (enemy = 2)
  {
    enemy2.health = 3 * enemy2.level + enemy2.level;
    enemy2.defense = 1 * enemy2.level + enemy2.level;
    enemy2.attack = 2 * enemy2.level + enemy2.level;
    enemy2.experience = enemy2.level * 10;
  }
  if (enemy = 3)
  {
    enemy3.health = 3 * enemy3.level + enemy3.level;
    enemy3.defense = 1 * enemy3.level + enemy3.level;
    enemy3.attack = 2 * enemy3.level + enemy3.level;
    enemy3.experience = enemy3.level * 10;
  }
  if (enemy = 4)
  {
    miniBoss.health = 3 * miniBoss.level + miniBoss.level;
    miniBoss.defense = 1 * miniBoss.level + miniBoss.level;
    miniBoss.attack = 2 * miniBoss.level + miniBoss.level;
    miniBoss.experience = miniBoss.level * 10;
  }
}
void EnemyListInit()
{
  int enemy;
  if (chp.txt == 1) 
  {
    strcpy(enemy1.name, "Grunt");
    enemy = 1;
    enemy1.level = 1;
    EnemyInit(enemy);
    getEnemyType(enemy1.name);
    strcpy(enemy1.drop1, drop1);
    strcpy(enemy1.drop2, drop2);
    strcpy(enemy1.drop3, drop3);
  }
}

void calcDmg()
{
  int r;
  srand(time(NULL));
  r = (rand() % 3) + 1;
  if (chp.txt == 1)
  {
	  printf("You ready the torch you picked up to fight.\n");
	  printf("The grunt is wearing a black tabard with an indistinguishable red insignia and has a rusty sword at the ready; it's clear that he was unprepared for you to be here.\n");
  }
  printf("You have three options:\n1: normal strike\n2. heavy strike\n3. dodge");

	player.health -= (enemy1.attack - player.defense);
	enemy1.health -= (player.attack - enemy1.defense);
  if (enemy1.health <= 0)
  {
    player.experience += enemy1.experience;
  }
}


void GameStatePlayUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);
  if (chp.txt == 1)
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