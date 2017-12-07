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
//char drop1[20];
//char drop2[20];
//char drop3[20];

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

void RemoveNewLine(char *string)
{
  int length = strlen(string);
  
  for (int i = 0; i < length; i++)
  {
    if (*(string + i) == '\n')
    {
      *(string + i) = 0;
    }
  }
}

void GameStatePlayInit()
{
  enemy = 0;
  int i = 0;
  char *end;

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
  printf("%s\n%i\n%i\n%i\n%i\n%i\n%i", player.name, player.maxhealth, player.health, player.defense, player.attack, player.experience, player.level);
  getch();
}

void getEnemyType(char name[20])
{
  if (name == "Grunt")
  {
    //strcpy(drop1, "Rusty Sword");
    //strcpy(drop2, "Broken Chainmail");
    //strcpy(drop3, "Burnt Helmet");
  }
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
    else if (enemy >= 4)
    {
      cleared = true;
    }
    /*getEnemyType(enemy1.name);
    strcpy(enemy1.drop1, drop1);
    printf("%s", enemy1.drop1);
    strcpy(enemy1.drop2, drop2);
    printf("%s", enemy1.drop2);
    strcpy(enemy1.drop3, drop3);
    printf("%s", enemy1.drop3);*/

    /*
    getEnemyType(enemy1.name);
    strcpy(enemy1.drop1, drop1);
    printf("%s", enemy1.drop1);
    strcpy(enemy1.drop2, drop2);
    printf("%s", enemy1.drop2);
    strcpy(enemy1.drop3, drop3);
    printf("%s", enemy1.drop3);
    strcpy(enemy3.name, "Grunt");

    getEnemyType(enemy1.name);
    strcpy(enemy1.drop1, drop1);
    printf("%s", enemy1.drop1);
    strcpy(enemy1.drop2, drop2);
    printf("%s", enemy1.drop2);
    strcpy(enemy1.drop3, drop3);
    printf("%s", enemy1.drop3);*/
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
  }

  getch();
  ClearScreen();
}

void calcDmg()
{
  char choice;
  int r;
  srand(time(NULL));
  /*r = (rand() % 3) + 1;
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
  }*/

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
        printf("As you reach near the end of the tunnel, a man as large as an ogre emerges from his chair to face you. \n His body blocks the light coming in from the outside, and there is no way to escape without defeating him first.");
      }
      else
      {
        printf("You ready your rusty sword to fight.\n");
        printf("Your enemy clearly heard the alarm and seems more prepared than whom you just faced.");
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
        printf("A figure walks out from behind a tree to stop you in your path.\n Its hair is made out of leaves , its face is covered by some sort of earthen mask, "
          "\nand its body is covered with branches and a tattered robe. \"Fu herner da jat!\" says the witchly figure.\nYou have a feeling it will not allow you to pass easily."); /*Witch states you shall not pass in jibberish*/
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
        printf("A figure walks out from behind a tree to stop you in your path.\n Its hair is made out of leaves , its face is covered by some sort of earthen mask, "
          "\nand its body is covered with branches and a tattered robe. \"Fu herner da jat!\" says the witchly figure.\nYou have a feeling it will not allow you to pass easily."); /*Witch states you shall not pass in jibberish*/
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
    }
  } while (c != EOF);
  fclose(chp);

  if (cEnemy.health > 0)
  {
    printf("You have three options:\n1: normal strike\n2. heavy strike\n3. dodge\n>>");

    //player choice
    choice = getch();
    switch (choice)
    {
    case '1':
      printf("\nYou strike the %s\n", cEnemy.name);
      cEnemy.health = cEnemy.health - (player.attack - cEnemy.defense);
      break;
    case '2':
      printf("\nYou swing at %s with all your might\n", cEnemy.name);
      cEnemy.health = cEnemy.health - ((player.attack + 1) - cEnemy.defense);
      player.health -= 1;
      break;
    case '3':
      printf("\nYou attempt to dodge the next attack\n");
      player.health += 1;
      break;
    default:
      printf("press 1 2 or 3\n");
      choice = getch();
      break;
    }
  }

  Wait(500);

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
      cEnemy.health -= 1;
      break;
    case 3:
      printf("The %s tries to dodge your attack\n", cEnemy.name);
      cEnemy.health += 1;
      break;
    }

    getch();
    BattleUI();
    return;
  }

  if (cEnemy.health <= 0)
  {
    {
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

  EnemyListInit();

  if (cleared)
  {
    ClearScreen();
    GameStateManagerSetNextState(GsStory);
  }

  do
  {
    c = fgetc(chp);
    if (c == '0')
      printf("A grunt appears and won't let you leave the dungeon.\n");
  } while (c != EOF);
  fclose(chp);


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