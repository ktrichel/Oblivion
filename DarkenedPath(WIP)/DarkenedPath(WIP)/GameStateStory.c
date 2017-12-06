#include "stdafx.h"
#include "GameStateStory.h"
#include "Character.h"

CHARACTER c;

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
  getch();
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
      choice = getch();
    }
    else if (strcmp(parent, "DAD") == 0)
    {
      printf("\"So you were with your dad?\"\n(Y)es\n(N)o\n>>");
      choice = getch();
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
      choice = getch();
    }

  } while (toupper(choice) != 'Y');

  ClearScreen();
  printf("\"Well, lets try to find a torch to look around this dark place. Maybe we can find them together!\"\n");
  getch();
  ClearScreen();

  printf("*You pick up the torch*\n");
  getch();
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
    choice2 = getch();

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
  printf("\"That's a nice name, I'm happy to meet you %s!\"\n", name);
  getch();
  ClearScreen();

  printf("\"I think I hear someone. I hope you're ready to get us out of here!\"\n\n\n\n\n\n\n\n\n\n");
  printf("\nPress any button to continue...");

  getch();

  GameStateManagerSetNextState(GsPlay);
}

void Mini1()
{
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '2');

  fclose(chp);

	printf("As you reach near the end of the tunnel, a man as large as an ogre emerges from his chair to face you. \n His body blocks the light coming in from the outside, and there is no one to escape without defeating him first.");
	getch();
	GameStateManagerSetNextState(GsPlay);
}

void Chapter2()
{  
{
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '3');

  fclose(chp);
  
	printf("\"I'm glad we finally made it out of that dark place!\"\n\"I hope you're ready for your new adventure out in the real world.\"");
  getch();
  ClearScreen();
	printf("The sun seems to be overly bright, but you can see a long and windy path that goes through a large thicket.\nYou can also see the path exit the forest up a mountain with a large castle on top.");
  getchar();
  ClearScreen();
	printf("\"We have a long way to go until we make it to our father's castle. \nThey weren't as kind to me and Mom as they were to you %s.\"", name);
  getchar();
  ClearScreen();
	printf("You start to head down the darkened path into the forest which contains nothing but mysteries.");
  getch();
  ClearScreen();
	printf("A treant emerges from the crowd of trees and starts to engage you, \nas it seems you have intruded in his territory"); //158 46

  GameStateManagerSetNextState(GsPlay);
}

void Mini2()
{
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '4');

  fclose(chp);

	printf("A figure walks out from behind a tree to stop you in your path.\n Its hair is made out of leaves , its face is covered by some sort of earthen mask, "
			   "\nand its body is covered with branches and a tattered robe. \"Fu herner da jat!\" says the witchly figure.\nYou have a feeling it will not allow you to pass easily."); /*Witch states you shall not pass in jibberish*/
  getch();
  ClearScreen();

  GameStateManagerSetNextState(GsPlay);
}

void Chapter3()
{
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '5');

  fclose(chp);

  printf("\"That banshee sure was mad about something. I hope we are able to survive through these mountains up ahead.\"");
  getch();
  ClearScreen();
  printf("\"I heard our father joined the bats. The bats are going to destory anyone that doesn't follow their ideals. \n That's why me and mom...\"");
  getch();
  ClearScreen();
  printf("You start ascending the mountain... Suddenly a rock golem unravels himself and nearly crushes you! \nYou wonder why the golem is so aggressive when you have done nothing. \n You then wonder if the banshee attacking you wasn't a mistake...");
  getch();
  ClearScreen();

  GameStateManagerSetNextState(GsPlay);
}

void Mini3()
{
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '6');

  fclose(chp);

  printf("You reach just short of the mountain top and are led instead inside the mountain. You wonder inside the cavern and begin hearing \nsomething similar to heavy breathing. You decide it was just the wind in the high mountains; however,"
         "\nyou stumble into a pile coins and create a large crashing and clanging sound! \nA dragon, whom is not fully grown, is awoken and ready to defend its treasure!");

  GameStateManagerSetNextState(GsPlay);
}

void Chapter4()
{
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '7');

  fclose(chp);

  printf("\"I can't believe you found so much treasure! I would try to hurry out of here \n there may be another dragon, since that dragon didn't look too old.\"");
  getchar();
  ClearScreen();
  printf("You rummage through the coins, gathering whatever treasure you can carry, and exit through the cave on the other side of the mountain.\n You then reach the top of the mountain, which is a large plateu that has a castle on its surface.");
  getch();
  ClearScreen();
  printf("\"Hey %s, I think that is our father's castle. You should go in and meet him, \nyou may be able to learn more about what happened.\"", name);
  getchar();
  ClearScreen();
  printf("You approach the large doors that reach the clouds, and the doors start to slowly creak open. \nA group of knights pour through the door and are ready to defend their castle.");
  getchar();
  ClearScreen();

  GameStateManagerSetNextState(GsPlay);
}

void Mini4()
{
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '8');

  fclose(chp);

  printf("As you approach the top floor, you see a center door with a grand entrace. You assume this is where your father is. \nAs you approach the door a pale, toned, red-eyed man, who looks quite young, blocks your path.");

  GameStateManagerSetNextState(GsPlay);
}

void Parent()
{
  FILE *chp;
  chp = fopen("chp.txt", "w");
  char ch;
  if (chp == NULL)
  {
    printf("Cannot open file for writing.\n");
    exit(0);
  }

  fprintf(chp, "%c", '9');

  fclose(chp);

  printf("You enter the room and see your father, he is also pale, toned, and has red-eyes; however, \nit looks as if he hasn't aged past 20 and he looks more elegant than who you just faced.");
  getchar();
  ClearScreen();
  printf("Erysichthon(your father): \"It looks as if you have slain my lieutenant; I am very proud of you my son. \nI'm glad that you came to pay me visit, for now you are finally strong enough for me to test my strength upon!\"");
  getchar();
  ClearScreen();
  printf("Mysterious Girl: \"Do not be frightened %s, his strength may be overwhelming, but it is nothing to what you have faced before.\"", name);
  getchar();
  ClearScreen();
  printf("Pebbles begin to fall from the ceiling and the ground begins to quake as a large dragon lands on top of the castle. \n");
  getchar();
  ClearScreen();
  printf("Erysichthon: \"It seems as though you have upset my beauty. I hope you're prepared to feel our wrath\"");

}

void Epilogue()
{
  printf("You deal the finishing blow to the dragon as it collapses on the ground. \nYou're father falls off, and kneels in front of you.");
  getchar();
  ClearScreen();
  printf("\"I'm sorry for having you be alone. I was not able to turn your sister and mother like I was for you. \nI had your older brother be my lieutenant while I waited for you to mature because I knew you had it in you.\n"
         "Finish me and show me you have what it takes to dominate the kingdom that wants nothing but chaos in the world!\"\n(Show) him there's another way of doing this.\n(Finish) your father and give him what he wants");
  char choice[6] = gets

}