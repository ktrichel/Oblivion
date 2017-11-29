#include "stdafx.h"
#include "GameStateStory.h"
#include "Character.h"

static int chp;

void GameStateStoryInit()
{

}

void GameStateStoryExit()
{
	ScreenTransition(2);

	ClearScreen();
}

void GameStateStoryUpdate(float dt)
{
	UNREFERENCED_PARAMETER(dt);
  switch (chp)
  {
  case 1:
    printf("works");
    break;
  default:
    Chapter1();
  }
}

void Chapter1()
{
  CHARACTER c;
  char name[20] = "";
  char parent[4] = "";
  char choice;
  char choice2;
  printf("Are you lost? Do remember who you were last with?\n");
  printf("Mom?\nDad?\n>>");

  do
  {
    scanf("%3s", parent);
    while (getchar() != '\n');
    strupr(parent);

    if (strcmp(parent, "MOM") == 0)
    {
      printf("So you were with your mom?\n(Y)es\n(N)o\n>>");
      choice = getchar();
      while (getchar() != '\n');
    }
    else if (strcmp(parent, "DAD") == 0)
    {
      printf("So you were with your dad?\n(Y)es\n(N)o\n>>");
      choice = getchar();
      while (getchar() != '\n');
    }
    else
    {
      printf("Were you with your mom or your dad?\n>>");
      continue;
    }

    if (toupper(choice) == 'N')
    {
      printf("Oh? Then who were you with?\n>>");
    }
    else if (toupper(choice) != 'Y')
    {
      printf("Please type Y or N\n>>");
      choice = getchar();
      while (getchar() != '\n');
    }

  } while (toupper(choice) != 'Y');

  ClearScreen();
  printf("Well, lets try to find a torch to look around this dark place. Maybe we can find them together!\n");
  getchar();
  ClearScreen();

  printf("*You pick up a torch*\n");
  getchar();
  ClearScreen();

  printf("Oh hey I forgot to ask, what would you like me to call you?\n>> ");
  scanf("%s", name);
  while (getchar() != '\n');
  *name = toupper(*name);
  strcpy(c.name, name);
  printf("DEBUG: %s", c.name);
  getchar();
  ClearScreen();

  do
  {
    printf("%s right?\n(Y)es\n(N)o\n>> ", name);
    choice2 = getchar();
    while (getchar() != '\n');

    if (toupper(choice2) == 'N')
    {
      ClearScreen();
      printf("Then what would you like to be called?\n");
      scanf("%s", name);
      while (getchar() != '\n');

      ClearScreen();
    }
  } while (toupper(choice2) != 'Y');

  ClearScreen();
  printf("That's a nice name, happy to meet you %s!\n", name);
  getchar();
  ClearScreen();

  printf("I think I hear someone. I hope  you're ready to get us out of here!\n\n\n\n\n\n\n\n\n\n");
  printf("\nPress Enter to continue...");

  getchar();

  chp = 1;
  GameStateManagerSetNextState(GsPlay);
}