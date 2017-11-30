#include "stdafx.h"
#include "GameStateStory.h"
#include "Character.h"

void WriteToFile(char c)
{
  FILE *chp;
  chp = fopen("chp.txt", "w");
  c = '0';
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", c);

  fclose(chp);
}

void GameStateStoryInit()
{
  FILE *chp;
  chp = fopen("chp.txt", "r");
  char c;
  if (chp == NULL)
  {
    printf("Cannot open file for reading.\n");
    exit(0);
  }

  do
  {
    c = fgetc(chp);
    if (c < '0')
    {
      WriteToFile(c);
    }
    else
    {
      break;
    }
  } while (c != EOF);
  
  fclose(chp);
}

void GameStateStoryExit()
{
	ScreenTransition(2);

	ClearScreen();
}

void GameStateStoryUpdate(float dt)
{
	UNREFERENCED_PARAMETER(dt);
  int i = 0;

  FILE *chp;
  chp = fopen("chp.txt", "r");
  char c;
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
      i = 0;
    }
    else if (c == '1')
    {
      i = 1;
    }
  } while (c != EOF);
  fclose(chp);

  switch (i)
  {
  case 0:
    Chapter1();
    break;
  case 1:
    Chapter2();
    break;
  default:
    break;
  }
}

void Chapter1()
{
  CHARACTER c;
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }
  
  fprintf(chp, "%c", '1');
  
  fclose(chp);

  char parent[4] = "";
  char choice;
  char choice2;
  printf("You awaken in a dark dungeon to a voice calling out to you with a single torch as your sole light source.\n\"...llo? Hey!\"\n");
  getchar();
  ClearScreen();

  printf("\"Are you lost? Do remember who you were last with?\"\n");
  printf("Mom?\nDad?\n>>");

  do
  {
    scanf("%3s", parent);
    while (getchar() != '\n');
    strupr(parent);
    ClearScreen();

    if (strcmp(parent, "MOM") == 0)
    {
      printf("\"So you were with your mom?\"\n(Y)es\n(N)o\n>>");
      choice = getchar();
      while (getchar() != '\n');
    }
    else if (strcmp(parent, "DAD") == 0)
    {
      printf("\"So you were with your dad?\"\n(Y)es\n(N)o\n>>");
      choice = getchar();
      while (getchar() != '\n');
    }
    else
    {
      printf("\"Were you with your mom or your dad?\"\n>>");
      continue;
    }

    if (toupper(choice) == 'N')
    {
      ClearScreen();
      printf("\"Oh? Then who were you with?\"\n>>");
    }
    else if (toupper(choice) != 'Y')
    {
      ClearScreen();
      printf("Please type Y or N\n>>");
      choice = getchar();
      while (getchar() != '\n');
    }

  } while (toupper(choice) != 'Y');

  ClearScreen();
  printf("\"Well, lets try to find a torch to look around this dark place. Maybe we can find them together!\"\n");
  getchar();
  ClearScreen();

  printf("*You pick up the torch*\n");
  getchar();
  ClearScreen();

  printf("\"Oh hey I forgot to ask, what would you like me to call you?\"\n>> ");
  scanf("%s", name);
  while (getchar() != '\n');
  *name = toupper(*name);
  strcpy(c.name, name);
  ClearScreen();

  do
  {
    printf("\"%s right?\"\n(Y)es\n(N)o\n>> ", name);
    choice2 = getchar();
    while (getchar() != '\n');

    if (toupper(choice2) == 'N')
    {
      ClearScreen();
      printf("\"Then what would you like to be called?\"\n>>");
      scanf("%s", name);
      while (getchar() != '\n');
      *name = toupper(*name);
      strcpy(c.name, name);
      ClearScreen();
    }
  } while (toupper(choice2) != 'Y');

  ClearScreen();
  printf("\"That's a nice name, happy to meet you %s!\"\n", name);
  getchar();
  ClearScreen();

  printf("\"I think I hear someone. I hope you're ready to get us out of here!\"\n\n\n\n\n\n\n\n\n\n");
  printf("\nPress Enter to continue...");

  getchar();

  GameStateManagerSetNextState(GsPlay);
}

void Chapter2()
{
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '/');

  fclose(chp);

	printf("\"I'm glad we finally made it out of that dark place!\"\n\"I hope you're ready for your new adventure out in the real world.\"");
  getchar();
  ClearScreen();
	printf("There is a long and windy path that goes through a large thicket.\nYou can also see the path exit the forest up a mountain with a large castle on top.");
  getchar();
  ClearScreen();
	printf("\"We have a long way to go until we make it to our father's castle. They weren't as kind to me and Mom as they were to you.\"");
  getchar();

  GameStateManagerSetNextState(GsPause);
}