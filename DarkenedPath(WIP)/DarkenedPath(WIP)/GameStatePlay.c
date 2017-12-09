/******************************************************************************/
/*!
\file   GameStatePlay.c
\author Kyle Trichel and Drake Mathis
\par    Course: GAM100F17
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/
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
CHARACTER cEnemy;
CHARACTER player;
CHARACTER drops;

/*************************************************************************
*                        Prototype Declarations                          *
**************************************************************************/
void BattleUI();

/*************************************************************************
*                          Global Variables                              *
**************************************************************************/
char *battleUI[] =
{
  " _ ______ ______ ______ ______ ______ ______ ______ ______ ______ ______ _ ______ ______ ______ ______ ______ ______ ______ _ \n",
  "|_|______|______|______|______|______|______|______|______|______|______|_|______|______|______|______|______|______|______|_|\n",
  "| |                                                                     | |                                                | |\n",
  "| |   %-20s %2i                                           | |   %-20s %2i                      | |\n",
  "| |                                                                     | |                                                | |\n",
  "| |    HP: %2i/%2i                                                        | |    HP: %2i/%2i                                   | |\n",
  "| |                                                                     | |                                                | |\n",
  "| |   ATK: %2i                                                           | |   ATK:  %2i                                     | |\n",
  "| |                                                                     | |                                                | |\n",
  "| |   DEF: %2i                                                           | |   DEF:  %2i                                     | |\n",
  "| |                                                                     | |                                                | |\n",
  "| |______ ______ ______ ______ ______ ______ ______ ______ ______ ______| |______ ______ ______ ______ ______ ______ ______| |\n",
  "|_|______|______|______|______|______|______|______|______|______|______|_|______|______|______|______|______|______|______|_|\n",
};
bool cleared = false;
bool dead = false;

void GameStatePlayInit()
{
  enemy = 0;
  dead = false;
  int i = 0;
  char *end;

  FILE *playerStats = fopen("Player.txt", "r");
  char *ps[20] = { "" };
  if (playerStats == NULL)
  {
    printf("Cannot open file for reading.\n");
    exit(0);
  }

  while (fgets(ps, 20, playerStats))
  {
    if (i == 0)
    {
      strcpy(player.name, ps);
      RemoveNewLine(player.name);
    }
    else if (i == 1)
    {
      player.maxhealth = strtol(ps, &end, 10);
    }
    else if (i == 2)
    {
      player.health = strtol(ps, &end, 10);
    }
    else if (i == 3)
    {
      player.defense = strtol(ps, &end, 10);
    }
    else if (i == 4)
    {
      player.attack = strtol(ps, &end, 10);
    }
    else if (i == 5)
    {
      player.experience = strtol(ps, &end, 10);
    }
    else if (i == 6)
    {
      player.level = strtol(ps, &end, 10);
    }
    i++;
  }
  fclose(playerStats);

  FILE *fT = fopen("FirstTime.txt", "r");
  if (fT == NULL)
  {
    printf("Cannot open file for reading.\n");
    exit(0);
  }

  char first = 0;

  first = fgetc(fT);

  if (first == '0')
  {
    strcpy(player.name, name);
    player.maxhealth = 10;
    player.health = 10;
    player.defense = 1;
    player.attack = 3;
    player.experience = 0;
    player.level = 1;

    printf("HINT: Press 'a' to begin the fight, or press 'q' to go to the pause menu.\n");
    printf("Press 'h' at anytime to be reminded of the controls.\n");
  }
  fclose(fT);

  fT = fopen("FirstTime.txt", "w");
  if (fT == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(fT, "%c", '1');
  fclose(fT);
  
  cleared = false;
}

int getEnemyType(char name[20])
{
  if (strcmp(name, "Grunt") == 0)
  {
    strcpy(drops.drop1, "Rusty Sword");
    strcpy(drops.drop2, "Broken Chainmail");
    strcpy(drops.drop3, "Burnt Helmet");
    return 1;
  }
  if (strcmp(name, "Captain") == 0)
  {
    strcpy(drops.drop1, "Basic Sword");
    strcpy(drops.drop2, "Worn Chainmail");
    strcpy(drops.drop3, "Scratched Helmet");
    return 1;
  }
  if (strcmp(name, "Witch") == 0)
  {
    return 1;
  }
  /*if (strcmp(name, "Treant") == 0)
  {
  return 1;
  }*/
  /*if (strcmp(name, "Golem") == 0)
  {
  return 1;
  }*/
  if (strcmp(name, "Baby Dragon") == 0)
  {
    return 1;
  }
  /*if (strcmp(name, "Knights") == 0)
  {
  return 1;
  }*/
  if (strcmp(name, "Lieutenant") == 0)
  {
    return 1;
  }

  return 0;
}

void EnemyInit(int enemy)
{
  if (enemy == 0)
  {
    strcpy(cEnemy.name, enemy1.name);
    cEnemy.level = enemy1.level;
    cEnemy.health = 3 * enemy1.level + enemy1.level;
    cEnemy.maxhealth = cEnemy.health;
    cEnemy.defense = 1 * enemy1.level + enemy1.level;
    cEnemy.attack = 2 * enemy1.level + enemy1.level;
    cEnemy.experience = enemy1.level * 10;
    return;
  }
  if (enemy == 1)
  {
    strcpy(cEnemy.name, enemy2.name);
    cEnemy.level = enemy2.level;
    cEnemy.health = 3 * enemy2.level + enemy2.level;
    cEnemy.maxhealth = cEnemy.health;
    cEnemy.defense = 1 * enemy2.level + enemy2.level;
    cEnemy.attack = 2 * enemy2.level + enemy2.level;
    cEnemy.experience = enemy2.level * 10;
    return;
  }
  if (enemy == 2)
  {
    strcpy(cEnemy.name, enemy3.name);
    cEnemy.level = enemy3.level;
    cEnemy.health = 3 * enemy3.level + enemy3.level;
    cEnemy.maxhealth = cEnemy.health;
    cEnemy.defense = 1 * enemy3.level + enemy3.level;
    cEnemy.attack = 2 * enemy3.level + enemy3.level;
    cEnemy.experience = enemy3.level * 10;
    return;
  }
  if (enemy == 3)
  {
    strcpy(cEnemy.name, miniBoss.name);
    cEnemy.level = miniBoss.level;
    cEnemy.health = 3 * miniBoss.level + miniBoss.level;
    cEnemy.maxhealth = cEnemy.health;
    cEnemy.defense = 1 * miniBoss.level + miniBoss.level;
    cEnemy.attack = 2 * miniBoss.level + miniBoss.level;
    cEnemy.experience = miniBoss.level * 10;
    return;
  }
}

void EnemyListInit()
{
  FILE *chp;
  chp = fopen("chp.txt", "r");
  char c = 0;

  if (chp == NULL)
  {
    printf("Cannot open file for reading.\n");
    exit(0);
  }
  c = fgetc(chp);
  fclose(chp);

  if (c == '0')
  {
    if (enemy == 0)
    {
      strcpy(enemy1.name, "Grunt");
      enemy1.level = 1;
      EnemyInit(enemy);
    }
    else if (enemy == 1)
    {
      strcpy(enemy2.name, "Alert Grunt");
      enemy2.level = 1;
      EnemyInit(enemy);
    }
    else if (enemy == 2)
    {
      strcpy(enemy3.name, "Grunt Guard");
      enemy3.level = 2;
      EnemyInit(enemy);
    }
    else if (enemy == 3)
    {
      strcpy(miniBoss.name, "Captain");
      miniBoss.level = player.level;
      EnemyInit(enemy);
    }
    else if (enemy > 3)
    {
      cleared = true;
    }
  }
  else if (c == '1')
    {
      if (enemy == 0)
      {
        strcpy(enemy1.name, "Treant");
        enemy1.level = 1;
        EnemyInit(enemy);
      }
      else if (enemy == 1)
      {
        strcpy(enemy2.name, "Alert Grunt");
        enemy2.level = 1;
        EnemyInit(enemy);
      }
      else if (enemy == 2)
      {
        strcpy(enemy3.name, "Grunt Guard");
        enemy3.level = 2;
        EnemyInit(enemy);
      }
      else if (enemy == 3)
      {
        strcpy(miniBoss.name, "Witch");
        miniBoss.level = player.level;
        EnemyInit(enemy);
      }
      else if (enemy > 3)
      {
        cleared = true;
      }
    }
  else if (c == '2')
      {
        if (enemy == 0)
        {
          strcpy(enemy1.name, "Golem");
          enemy1.level = 1;
          EnemyInit(enemy);
        }
        else if (enemy == 1)
        {
          strcpy(enemy2.name, "Alert Grunt");
          enemy2.level = 1;
          EnemyInit(enemy);
        }
        else if (enemy == 2)
        {
          strcpy(enemy3.name, "Grunt Guard");
          enemy3.level = 2;
          EnemyInit(enemy);
        }
        else if (enemy == 3)
        {
          strcpy(miniBoss.name, "Baby Dragon");
          miniBoss.level = player.level;
          EnemyInit(enemy);
        }
        else if (enemy > 3)
        {
          cleared = true;
        }
      }
  else if (c == '3')
  {
    if (enemy == 0)
      {
        strcpy(enemy1.name, "Knights");
        enemy1.level = 1;
        EnemyInit(enemy);
      }
    else if (enemy == 1)
      {
        strcpy(enemy2.name, "Alert Grunt");
        enemy2.level = 1;
        EnemyInit(enemy);
      }
    else if (enemy == 2)
      {
        strcpy(enemy3.name, "Grunt Guard");
        enemy3.level = 2;
        EnemyInit(enemy);
      }
    else if (enemy == 3)
      {
        strcpy(miniBoss.name, "Lieutenant");
        miniBoss.level = player.level;
        EnemyInit(enemy);
      }
    else if (enemy > 3)
      {
        cleared = true;
      }
  }
  else if (c == '4')
  {
    if (enemy == 0)
    {
      strcpy(enemy1.name, "Erysichthon");
      enemy1.level = 10;
      EnemyInit(enemy);
    }
    else if (enemy > 1)
    {
      cleared = true;
    }
  }
        
}

void LvlUp()
{
  int expCap = player.level * 10;

  if (player.experience >= expCap)
  {
    ClearScreen();

    for (int i = 0; i < _countof(battleUI); i++)
    {
      switch (i)
      {
      case 3:
        player.level += 1;
        printf(battleUI[i], player.name, player.level, cEnemy.name, cEnemy.level);
        break;
      case 5:
        player.maxhealth += 2;
        player.health = player.maxhealth;
        printf(battleUI[i], player.health, player.maxhealth, cEnemy.health, cEnemy.maxhealth);
        break;
      case 7:
        player.attack += 2;
        printf(battleUI[i], player.attack, cEnemy.attack);
        break;
      case 9:
        player.defense += 2;
        printf(battleUI[i], player.defense, cEnemy.defense);
        break;
      default:
        printf(battleUI[i]);
        break;
      }
    }

    player.experience = 0;
    printf("You have gained 2 Max HP, 2 ATK, and 2 DEF!\nYour health has been fully restored\n");
    printf("Your power level is ever reaching near 9000!\n");
    getch();
    ClearScreen();
  }
  else
  {
    ClearScreen();

    player.health += player.maxhealth / 2;
    if (player.health > player.maxhealth)
    {
      player.health = player.maxhealth;
    }

    for (int i = 0; i < _countof(battleUI); i++)
    {
      switch (i)
      {
      case 3:
        printf(battleUI[i], player.name, player.level, cEnemy.name, cEnemy.level);
        break;
      case 5:
        printf(battleUI[i], player.health, player.maxhealth, cEnemy.health, cEnemy.maxhealth);
        break;
      case 7:
        printf(battleUI[i], player.attack, cEnemy.attack);
        break;
      case 9:
        printf(battleUI[i], player.defense, cEnemy.defense);
        break;
      default:
        printf(battleUI[i]);
        break;
      }
    }

    printf("You healed for %i damage", player.maxhealth / 2);
    getch();
    ClearScreen();
  }

  if (getEnemyType(cEnemy.name))
  {
    for (int i = 0; i < _countof(battleUI); i++)
    {
      switch (i)
      {
      case 3:
        printf(battleUI[i], player.name, player.level, cEnemy.name, cEnemy.level);
        break;
      case 5:
        printf(battleUI[i], player.health, player.maxhealth, cEnemy.health, cEnemy.maxhealth);
        break;
      case 7:
        player.attack += 1;
        printf(battleUI[i], player.attack, cEnemy.attack);
        break;
      case 9:
        player.defense += 2;
        printf(battleUI[i], player.defense, cEnemy.defense);
        break;
      default:
        printf(battleUI[i]);
        break;
      }
    }
    printf("You take the %s's %s, %s and %s for your own and prepare to continue onward\n", cEnemy.name, drops.drop1, drops.drop2, drops.drop3);
    printf("+1 ATK and +2 DEF");

    getch();
    ClearScreen();
  }
}

void calcDmg()
{
  char choice;
  int r;
  srand(time(NULL));

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
    if (c == '0')
    {
      if (strcmp(cEnemy.name, enemy1.name) == 0)
      {
        printf("You ready the torch you picked up to fight.\n");
        printf("The grunt is wearing a black tabard with an indistinguishable red insignia and has a rusty sword at the ready.\nIt's clear that he was unprepared for you to be here.\n");
      }
      else if (strcmp(cEnemy.name, miniBoss.name) == 0)
      {
        printf("As you reach near the end of the tunnel, a man as large as an ogre emerges from his chair to face you.\nHis body blocks the light coming in from the outside, and there is no way to escape without defeating him first.\n");
      }
      else
      {
        printf("You ready your rusty sword to fight.\n");
        printf("Your enemy clearly heard the alarm and seems more prepared than whom you just faced.\n");
      }
    }
    if (c == '1')
    {
      if (strcmp(cEnemy.name, enemy1.name) == 0)
      {
        printf("You ready the torch you picked up to fight.\n");
        printf("The grunt is wearing a black tabard with an indistinguishable red insignia and has a rusty sword at the ready.\nIt's clear that he was unprepared for you to be here.\n");
      }
      else if (strcmp(cEnemy.name, miniBoss.name) == 0)
      {
        printf("A figure walks out from behind a tree to stop you in your path.\n Its hair is made out of leaves , its face is covered by some sort of earthen mask, "
          "\nand its body is covered with branches and a tattered robe. \"Fu herner da jat!\" says the witchly figure.\nYou have a feeling it will not allow you to pass easily."); /*Witch states you shall not pass in jibberish*/
      }
      else
      {
        printf("You ready your rusty sword to fight.\n");
        printf("Your enemy clearly heard the alarm and seems more prepared than whom you just faced.");
      }
    }
    if (c == '2')
    {
      if (strcmp(cEnemy.name, enemy1.name) == 0)
      {
        printf("You ready the torch you picked up to fight.\n");
        printf("The grunt is wearing a black tabard with an indistinguishable red insignia and has a rusty sword at the ready.\nIt's clear that he was unprepared for you to be here.\n");
      }
      else if (strcmp(cEnemy.name, miniBoss.name) == 0)
      {
        printf("You reach just short of the mountain top and are led instead inside the mountain. You wonder inside the cavern and begin hearing \nsomething similar to heavy breathing. You decide it was just the wind in the high mountains; however,"
          "\nyou stumble into a pile coins and create a large crashing and clanging sound! \nA dragon, whom is not fully grown, is awoken and ready to defend its treasure!");
      }
      else
      {
        printf("You ready your rusty sword to fight.\n");
        printf("Your enemy clearly heard the alarm and seems more prepared than whom you just faced.");
      }
    }
    if (c == '3')
    {
      if (strcmp(cEnemy.name, enemy1.name) == 0)
      {
        printf("You ready the torch you picked up to fight.\n");
        printf("The grunt is wearing a black tabard with an indistinguishable red insignia and has a rusty sword at the ready.\nIt's clear that he was unprepared for you to be here.\n");
      }
      else if (strcmp(cEnemy.name, miniBoss.name) == 0)
      {
        printf("As you approach the top floor, you see a center door with a grand entrace. You assume this is where your father is. \n"
               "When you start to head towards the door, a pale, toned, red-eyed man, who looks quite young, blocks your path.");
      }
      else
      {
        printf("You ready your rusty sword to fight.\n");
        printf("Your enemy clearly heard the alarm and seems more prepared than whom you just faced.");
      }
      if (c == '4')
      {
        if (strcmp(cEnemy.name, enemy1.name) == 0)
        {
          printf("You ready Sildrasla you picked up to fight.\n");
          printf("The grunt is wearing a black tabard with an indistinguishable red insignia and has a rusty sword at the ready.\nIt's clear that he was unprepared for you to be here.\n");
        }
        else if (strcmp(cEnemy.name, miniBoss.name) == 0)
        {
          printf("A figure walks out from behind a tree to stop you in your path.\n Its hair is made out of leaves , its face is covered by some sort of earthen mask, "
            "\nand its body is covered with branches and a tattered robe. \"Fu herner da jat!\" says the witchly figure.\nYou have a feeling it will not allow you to pass easily."); /*Witch states you shall not pass in jibberish*/
        }
        else
        {
          printf("You ready your rusty sword to fight.\n");
          printf("Your enemy clearly heard the alarm and seems more prepared than whom you just faced.");
        }
      }
    }
  } while (c != EOF);
  fclose(chp);

  if (player.health > 0)
  {
    if (cEnemy.health <= 0)
    {
      goto DEAD;
    }

    printf("You have three options:\n1: Normal Strike\n2. Heavy Strike (Strong hit, minus health)\n3. Dodge (Heal)\n>>");

    //player choice
    choice = getch();
    while (choice != '1' && choice != '2' && choice != '3')
    {
      ClearScreen();
      printf("Press 1 2 or 3\n>>");
      choice = getch();
    }

    switch (choice)
    {
    case '1':
      printf("\nYou strike the %s\n", cEnemy.name);
      cEnemy.health = cEnemy.health - (player.attack - cEnemy.defense);
      break;
    case '2':
      printf("\nYou swing at %s with all your might\n", cEnemy.name);
      cEnemy.health = cEnemy.health - ((player.attack + 1) - cEnemy.defense);
      player.health -= ceil((double)player.maxhealth / 5);
      break;
    case '3':
      printf("\nYou attempt to dodge the next attack\n");
      player.health += ceil((double)player.defense / 2);
      break;
    }

    if (player.health > player.maxhealth)
    {
      player.health = player.maxhealth;
    }
  }

  else if (player.health <= 0)
  {
    player.health = 0;

    ClearScreen();

    for (int i = 0; i < _countof(battleUI); i++)
    {
      switch (i)
      {
      case 3:
        printf(battleUI[i], player.name, player.level, cEnemy.name, cEnemy.level);
        break;
      case 5:
        printf(battleUI[i], player.health, player.maxhealth, cEnemy.health, cEnemy.maxhealth);
        break;
      case 7:
        printf(battleUI[i], player.attack, cEnemy.attack);
        break;
      case 9:
        printf(battleUI[i], player.defense, cEnemy.defense);
        break;
      default:
        printf(battleUI[i]);
        break;
      }
    }
    printf("You have been defeated by %s\n", cEnemy.name);
    getch();

    dead = true;
    return;
  }

  Wait(500);

  DEAD:if (cEnemy.health <= 0)
  {
    cEnemy.health = 0;

    ClearScreen();

    for (int i = 0; i < _countof(battleUI); i++)
    {
      switch (i)
      {
      case 3:
        printf(battleUI[i], player.name, player.level, cEnemy.name, cEnemy.level);
        break;
      case 5:
        printf(battleUI[i], player.health, player.maxhealth, cEnemy.health, cEnemy.maxhealth);
        break;
      case 7:
        printf(battleUI[i], player.attack, cEnemy.attack);
        break;
      case 9:
        printf(battleUI[i], player.defense, cEnemy.defense);
        break;
      default:
        printf(battleUI[i]);
        break;
      }
    }
    printf("You have defeated the %s", cEnemy.name);
    getch();

    player.experience = player.experience + cEnemy.experience;
    /* printf("%i", player.experience); */

    enemy++;

    LvlUp();
  }

  if (cEnemy.health > 0)
  {

    /*enemy choice */
    r = (rand() % 3) + 1;
    switch (r)
    {
    case 1:
      printf("The %s slashes at you\n", cEnemy.name);
      player.health = player.health - (cEnemy.attack - player.defense);
      break;
    case 2:
      printf("The %s swings a heavy blow at you\n", cEnemy.name);
      player.health = player.health - ((cEnemy.attack + 1) - player.defense);
      cEnemy.health -= ceil((double)cEnemy.maxhealth / 5);
      break;
    case 3:
      printf("The %s tries to dodge your attack\n", cEnemy.name);
      cEnemy.health += ceil((double)cEnemy.defense / 2);
      break;
    }

    if (cEnemy.health > cEnemy.maxhealth)
    {
      cEnemy.health = cEnemy.maxhealth;
    }

    getch();
    BattleUI();

    return;
  }

}

void BattleUI()
{
  system("mode 133,25");   //Set mode to ensure window does not exceed buffer size
  SMALL_RECT WinRect = { 0, 0, 133, 25 };   //New dimensions for window in 8x12 pixel chars
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

  HWND consoleWindow = GetConsoleWindow();

  SetWindowPos(consoleWindow, 0, 350, 250, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

  ClearScreen();

  for (int i = 0; i < _countof(battleUI); i++)
  {
    switch (i)
    {
    case 3:
      printf(battleUI[i], player.name, player.level, cEnemy.name, cEnemy.level);
      break;
    case 5:
      printf(battleUI[i], player.health, player.maxhealth, cEnemy.health, cEnemy.maxhealth);
      break;
    case 7:
      printf(battleUI[i], player.attack, cEnemy.attack);
      break;
    case 9:
      printf(battleUI[i], player.defense, cEnemy.defense);
      break;
    default:
      printf(battleUI[i]);
      break;
    }
  }

  calcDmg();
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
    if (c == '0')
      printf("A grunt appears and won't let you leave the dungeon.\n");
  } while (c != EOF);
  fclose(chp);

  EnemyListInit();

  if (cleared)
  {
    ClearScreen();
    GameStateManagerSetNextState(GsStory);
    return;
  }
  if (dead)
  {
    ClearScreen();
    GameStateManagerSetNextState(GsGameOver);
    return;
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
    BattleUI();
  }
  else if (toupper(player_input) == 'H')
  {
    ClearScreen();
    printf("HELP: Press 'a' to begin the fight, or press 'q' to go to the pause menu.\n");
  }

  if (IsDebuggerPresent())
  {
    if (toupper(player_input) == 'B')
    {
      GameStateManagerSetNextState(GsGameOver);
    }

    if (toupper(player_input) == 'L')
    {
      ClearScreen();
      BattleUI();
    }
  }
}

void GameStatePlayExit()
{
  FILE *chp;
  chp = fopen("chp.txt", "r");
  char c = '0';
  if (chp == NULL)
  {
    printf("Cannot open file for reading.\n");
    exit(0);
  }
  c = fgetc(chp);
  switch (c)
  {
  case '0':
    c++;
    break;
  case '1':
    c++;
    break;
  case '2':
    c++;
    break;
  case '3':
    c++;
    break;
  case '4':
    c++;
    break;
  default:
    printf("End of game or out of scope");
    exit(0);
  }
  fclose(chp);


  chp = fopen("chp.txt", "w");
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }
  fprintf(chp, "%c", c);
  fclose(chp);

  FILE *playerStats = fopen("Player.txt", "w");
  char *ps[20] = { "" };
  int i = 0;
  if (playerStats == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(playerStats, "%s\n%i\n%i\n%i\n%i\n%i\n%i", player.name, player.maxhealth, player.health, player.defense, player.attack, player.experience, player.level);
  fclose(playerStats);

  ScreenTransition(2);

  ClearScreen();
}