/******************************************************************************/
/*!
\file   GameStateStory.c
\author Kyle Trichel and Drake Mathis
\par    Course: GAM100F17
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/
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
    else if (c == '2')
    {
      i = 2;
    }
    else if (c == '3')
    {
      i = 3;
    }
    else if (c == '4')
    {
      i = 4;
    }
    else if (c == '5')
    {
      i = 5;
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
  case 2:
    Chapter3();
    break;
  case 3:
    Chapter4();
    break;
  case 4:
    Father();
    break;
  case 5:
    Epilogue();
    break;
  default:
    break;
  }
}

void Chapter1()
{
  CHARACTER c;

  char parent[4] = "";
  char choice;
  char choice2;
  printf("You awaken in a dark dungeon to a voice calling out to you with a single torch as your sole light source.\nMysterious Girl: \"...llo? Hey!\"\n");
  getch();
  ClearScreen();

  printf("Mysterious Girl: \"Are you lost? Do remember who you were last with?\"\n");
  getch();
  ClearScreen();
  printf("\"...\"");
  ClearScreen();
  printf("Mysterious Girl: \"Well... lets try to find a way to look around this dark place. Maybe we can find one of your parents together!\"\n");
  getch();
  ClearScreen();

  printf("You pick up the torch\n");
  getch();
  ClearScreen();

  printf("Mysterious Girl: \"Oh hey I forgot to ask, what would you like me to call you?\"\n>> ");
  scanf("%20s", name);
  while (getchar() != '\n');
  *name = toupper(*name);
  strcpy(c.name, name);
  ClearScreen();

  do
  {
    printf("Mysterious Girl: \"%s right?\"\n(Y)es\n(N)o\n>> ", name);
    choice2 = getch();

    if (toupper(choice2) == 'N')
    {
      ClearScreen();
      printf("Mysterious Girl: \"Then what would you like to be called?\"\n>>");
      scanf("%20s", name);
      while (getchar() != '\n');
      *name = toupper(*name);
      strcpy(c.name, name);
      ClearScreen();
    }
  } while (toupper(choice2) != 'Y');

  ClearScreen();
  printf("Mysterious Girl: \"That's a nice name, I'm happy to meet you %s!\"\n", name);
  getch();
  ClearScreen();

  printf("Mysterious Girl: \"I think I hear someone. I hope you're ready to get us out of here!\"\n\n\n\n\n\n\n\n\n\n");
  printf("\nPress any button to continue...");

  getch();

  GameStateManagerSetNextState(GsPlay);
}

void Mini1()
{
	printf("As you reach near the end of the tunnel, a man as large as an ogre emerges from his chair to face you. \nHis body blocks the light coming in from the outside, and there is no way to escape without defeating him first.");
	getch();
	GameStateManagerSetNextState(GsPlay);
}

void Chapter2() 
{
	printf("Mysterious Girl: \"I'm glad we finally made it out of that dark place!\"\n\"I hope you're ready for your new adventure out in the real world.\"");
  getch();
  ClearScreen();
	printf("The sun seems to be overly bright, but you can see a long and windy path that goes through a large thicket.\nYou can also see the path exit the forest up a mountain with a large castle on top.");
  getch();
  ClearScreen();
	printf("Mysterious Girl: \"We have a long way to go until we make it to your father's castle. \nThey weren't as kind to me and Mom as they were to you %s.\"", name);
  getch();
  ClearScreen();
	printf("You start to head down the darkened path into the forest which contains nothing but mysteries.");
  getch();
  ClearScreen();
	printf("A treant emerges from the crowd of trees and starts to engage you, \nas it seems you have intruded in his territory"); //158 46

  GameStateManagerSetNextState(GsPlay);
}

void Mini2()
{
	printf("A figure walks out from behind a tree to stop you in your path.\nIts hair is made out of leaves , its face is covered by some sort of earthen mask, "
			   "\nand its body is covered with branches and a tattered robe. \"Fu herner da jat!\" says the witchly figure.\nYou have a feeling it will not allow you to pass easily."); /*Witch states you shall not pass in jibberish*/
  getch();
  ClearScreen();

  GameStateManagerSetNextState(GsPlay);
}

void Chapter3()
{
  printf("Mysterious Girl: \"That banshee sure was mad about something. I hope we are able to survive \nthrough these mountains up ahead.\"");
  getch();
  ClearScreen();
  printf("Mysterious Girl: \"I heard your father joined the bats. The bats are going to destory anyone that doesn't \nfollow their ideals. That's why me and Mom...\"");
  getch();
  ClearScreen();
  printf("You start ascending the mountain... Suddenly a rock golem unravels himself and nearly crushes you! \nYou wonder why the golem is so aggressive when you have done nothing. \nYou then wonder if the banshee attacking you wasn't a mistake...");
  getch();
  ClearScreen();

  GameStateManagerSetNextState(GsPlay);
}

void Mini3()
{
  printf("You reach just short of the mountain top and are led instead inside the mountain. You wonder inside the cavern and begin hearing \nsomething similar to heavy breathing. You decide it was just the wind in the high mountains; however,"
         "\nyou stumble into a pile coins and create a large crashing and clanging sound! \nA dragon, whom is not fully grown, is awoken and ready to defend its treasure!");

  GameStateManagerSetNextState(GsPlay);
}

void Chapter4()
{
  printf("Mysterious Girl: \"I can't believe you found so much treasure! I would try to hurry out of here \nthere may be another dragon, since that dragon didn't look too old.\"");
  getch();
  ClearScreen();
  printf("You rummage through the coins, gathering whatever treasure you can carry, and exit through the cave on the other side\nof the mountain. You then reach the top of the mountain, which is a large plateu that has a castle on its surface.");
  getch();
  ClearScreen();
  printf("Mysterious Girl: \"Hey %s, I think that is our father's castle. You should go in and meet him, \nyou may be able to learn more about what happened.\"", name);
  getch();
  ClearScreen();
  printf("You approach the large doors that reach the clouds, and the doors start to slowly creak open. \nA group of knights pour through the door and are ready to defend their castle.");
  getch();
  ClearScreen();

  GameStateManagerSetNextState(GsPlay);
}

void Mini4()
{
  printf("As you approach the top floor, you see a center door with a grand entrace. You assume this is where your father is. "
         "\nAs you approach the door a pale, toned, red-eyed man, who looks quite young, blocks your path.");

  GameStateManagerSetNextState(GsPlay);
}

void Father()
{
  ClearScreen();
  printf("You enter the room and see your father, he is also pale, toned, and has red-eyes; however, \nit looks as if he hasn't aged past 20 and he looks more elegant than who you just faced.");
  getch();
  ClearScreen();
  printf("Erysichthon(your father): \"It looks as if you have slain my lieutenant; I am very proud of you my son. \nI'm glad that you came to pay me visit, for now you are finally strong enough for me to test my strength upon!\"");
  getch();
  ClearScreen();
  printf("Mysterious Girl: \"Do not be frightened %s, his strength may be overwhelming, but it is nothing \nto what you have faced before.\"", name);
  getch();
  ClearScreen();
  printf("Pebbles begin to fall from the ceiling and the ground begins to quake as a large dragon lands on top of the castle. \n");
  getch();
  ClearScreen();
  printf("Erysichthon: \"It seems as though you have upset my beauty. I hope you're prepared to feel our wrath\"");

  GameStateManagerSetNextState(GsPlay);
}

void Epilogue()
{
  printf("You walk up to your father, ready for what he has to say for his redemption.");
  getch();
  ClearScreen();
  printf("\"I'm sorry for having you be alone. I was not able to turn your sister and mother like I was for you. \nI had your older brother be my lieutenant while I waited for you to mature because I knew you had it in you.\n"
         "Finish me and show me you have what it takes to dominate the kingdom that wants nothing but chaos in the world!\"\n(Finish) your father and give him the rest he deserves.\n(Show) him there's another way of doing this.\n>>"); 
  
  while (0 == 0)
  {
    char choice[6] = { "" };
    gets(choice);
    RemoveNewLine(choice);
    strcpy(choice, strupr(choice));
    if (strcmp(choice, "FINISH") == 0)
    {
      ClearScreen();
      printf("You deicide to bring your father peace from his darkened path.");
      getch();
      ClearScreen();
      printf("You leave your father's castle lost and confused on what to do next.");
      getch();
      ClearScreen();
      printf("Sister: \"Hey, why do you look so lost and lonely? Never forget that we are always here for you.\"");
      getch();
      ClearScreen();
      printf("You turn to see your sister's face, longing for your father's words not to be true.");
      getch();
      ClearScreen();
      printf("You see nothing but your father's castle partially destroyed. However, when you look around you can see the edges of the kingdom and distant lands.");
      getch();
      ClearScreen();
      printf("Your curiosity of the world draws you towards the nearest castle you can see, in order to study the people\nand prove to yourself that your father was wrong about the kingdom.");
      getch();
      ClearScreen();
      GameStateManagerSetNextState(GsCredits);
    }
    else if (strcmp(choice, "SHOW") == 0)
    {
      ClearScreen();
      printf("You grab your father's hand and bring him to his feet. You embrace your father with a hug that would last for an eternity.");
      getch();
      ClearScreen();
      printf("Sister: \"I knew you could bring him away from his darkened path. Thank you...\"");
      getch();
      ClearScreen();
	    printf("You turn to see your sister's face, longing for your father's words not to be true.");
	    getch();
	    ClearScreen();
	    printf("To your despair, you see nothing but your father's partially destroyed castle.");
	    getch();
	    ClearScreen();
	    printf("Father: \"I tried to make us all immortal; however, your sister was too young and your mother was to frail after birthing you.\n I'm sorry %s, I hope you'll forgive me\"", c.name);
	    getch();
	    ClearScreen();
	    printf("You nod your head, letting your father know he is forgiven. You then walk with your father to the edge of the mountain.\n");
	    getch();
  	  ClearScreen();
	    printf("Father: \"Where do you think we should go now %s?\"\n(C)amelot\n(D)istant Lands");
	    char choice2 = getch();
	    strcpy(choice2, toupper(choice2));
	    int chosen = 0;
	    while (chosen == 0)
	    {
		    if (choice2 == 'C')
		    {
			    ClearScreen();
			    printf("You and your father head towards Camelot to right the wrongs he has committed.");
			    chosen = 1;
		    }
		    else if (choice2 == 'D')
		    {
			    ClearScreen();
			    printf("You and your father head towards the distant lands to hide away and explore the world together for an eternity.");
			    chosen = 1;
		    }
		    else
		    {
			    ClearScreen();
          printf("Please type \"C\" if you would like to go to Camelot with your father \nor press \"D\" to go to distant lands with your father.");
		    }
	    }
      getch();
	    ClearScreen();
	    GameStateManagerSetNextState(GsCredits);
    }
    else if (strcmp(choice, "REPLAY") == 0)
    {
      ClearScreen(); 
      Epilogue();
    }
    else
    {
      ClearScreen();
      printf("Please type \"finish\" or \"show\" to decide your ending.\nIf you'd like to listen to the situation again type \"replay\".\n>>");
    }
  }
}