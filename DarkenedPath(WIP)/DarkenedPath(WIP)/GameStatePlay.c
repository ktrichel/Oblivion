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
char drop1[20];
char drop2[20];
char drop3[20];

/*************************************************************************
*                          Global Variables                              *
**************************************************************************/
int *firstTime;

void GameStatePlayInit()
{
  strcpy(player.name, name);
  player.health = 10;
  player.defense = 1;
  player.attack = 3;
  player.experience = 0;
  player.level = 1;

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
  FILE *chp;
  chp = fopen("chp.txt", "r");
  char c = '0';
  if (chp == NULL)
  {
    printf("Cannot open file for reading.\n");
    exit(0);
  }

  do
  {
    c = fgetc(chp);
    if (c == '1')
    {
      strcpy(enemy1.name, "Grunt");
      enemy = 1;
      enemy1.level = 1;
      EnemyInit(enemy);
      getEnemyType(enemy1.name);
      strcpy(enemy1.drop1, drop1);
      printf("%s", enemy1.drop1);
      strcpy(enemy1.drop2, drop2);
      printf("%s", enemy1.drop2);
      strcpy(enemy1.drop3, drop3);
      printf("%s", enemy1.drop3);
      strcpy(enemy2.name, "Grunt");
     /* enemy = 2;
      enemy1.level = 1;
      EnemyInit(enemy);
      getEnemyType(enemy1.name);
      strcpy(enemy1.drop1, drop1);
      printf("%s", enemy1.drop1);
      strcpy(enemy1.drop2, drop2);
      printf("%s", enemy1.drop2);
      strcpy(enemy1.drop3, drop3);
      printf("%s", enemy1.drop3);
      strcpy(enemy3.name, "Grunt");
      enemy = 3;
      enemy1.level = 2;
      EnemyInit(enemy);
      getEnemyType(enemy1.name);
      strcpy(enemy1.drop1, drop1);
      printf("%s", enemy1.drop1);
      strcpy(enemy1.drop2, drop2);
      printf("%s", enemy1.drop2);
      strcpy(enemy1.drop3, drop3);
      printf("%s", enemy1.drop3);*/
    }
  } while (c != EOF);
  fclose(chp);

}
void LvlUp()
{
  int expCap = player.level * 10;
  if (player.experience == expCap)
  {
    player.health = player.health + 1;
    printf("%i\n", player.health);
    player.attack = player.attack + 1;
    printf("%i\n", player.attack);
    player.defense = player.defense + 1;
    printf("%i\n", player.defense);
    player.level += 1;
    player.experience = 0;
  }
  printf("Your power level is ever reaching near 9000!\n");
}
void calcDmg()
{
  char choice;
  int r;
  srand(time(NULL));
  r = (rand() % 3) + 1;
  char loot[20];
  switch (r)
  {
  case 1:
    strcpy(loot, enemy1.drop1);
    break;
  case 2:
    strcpy(loot, enemy1.drop2);
    break;
  case 3:
    strcpy(loot, enemy1.drop3);
    break;
  }
  FILE *chp;
  chp = fopen("chp.txt", "r");
  char c = '0';
  if (chp == NULL)
  {
    printf("Cannot open file for reading.\n");
    exit(0);
  }

  do
  {
    c = fgetc(chp);
    if (c == '1')
    {
      printf("You ready the torch you picked up to fight.\n");
      printf("The grunt is wearing a black tabard with an indistinguishable red insignia and has a rusty sword at the ready; it's clear that he was unprepared for you to be here.\n");
    }
  } while (c != EOF);
  fclose(chp);

  do {
    printf("You have three options:\n1: normal strike\n2. heavy strike\n3. dodge\n");
    //player choice
    choice = getchar();
    switch (choice)
    {
      case '1':
        enemy1.health = enemy1.health - (player.attack - enemy1.defense);
        break;
      case '2':
        enemy1.health = enemy1.health - (player.attack - enemy1.defense);
        player.health -= 1;
        break;
      case '3':
        player.health += 1;
        break;
      default:
        printf("press 1 2 or 3");
        choice = getchar();
        break;
    }
    /*enemy choice */
    r = (rand() % 3) + 1;
    switch (r)
    {
    case 1:
      player.health = player.health - (enemy1.attack - player.defense);
      break;
    case 2:
      player.health = player.health - (enemy1.attack - player.defense);
      enemy1.health -= 1;
      break;
    case 3:
      enemy1.health += 1;
      break;
    }
    printf("ph: %i\n", player.health);
    printf("pa: %i\n", player.attack); 
    printf("pd: %i\n", player.defense);
    printf("eh: %i\n", enemy1.health);
    printf("ea: %i\n", enemy1.attack);
    printf("ed: %i\n", enemy1.defense);
    printf("loot: %s\n", loot);
    if (enemy1.health <= 0)
    {
      player.experience = player.experience + enemy1.experience;
     /* printf("%i", player.experience); */
    }
    getchar();
  } while (enemy1.health > 0); 
  LvlUp();
}


void GameStatePlayUpdate(float dt)
{
	/* Tell the compiler that the 'dt' variable is unused. */
	UNREFERENCED_PARAMETER(dt);
  FILE *chp;
  chp = fopen("chp.txt", "r");
  char c = '0';
  if (chp == NULL)
  {
    printf("Cannot open file for reading.\n");
    exit(0);
  }

  do
  {
    c = fgetc(chp);
    if (c == '1')
      printf("A grunt appears and won't let you leave the dungeon.\n");
  } while (c != EOF);
  fclose(chp);
  EnemyListInit();
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
  else if (toupper(player_input) == 'B')
  {
    GameStateManagerSetNextState(GsStory);
  }
}

void GameStatePlayExit()
{
	ScreenTransition(2);

	ClearScreen();
}