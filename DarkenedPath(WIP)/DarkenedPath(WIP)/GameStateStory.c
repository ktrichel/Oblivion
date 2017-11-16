#include "stdafx.h"
#include "GameStateStory.h"


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
	int gender;
	char name[20] = "";
	char choice;
	char choice2;
	printf("%s", chp1.stm1);
	//printf("Are you lost? Do you remember if you with your (m)om, or your (d)ad?\n>> ");
	choice = getchar();
	while (getchar() != '\n')
	{

	}
	/*do {
		if (toupper(choice )== 'M')
		{
			gender = 0;
			ClearScreen();
		}
		else if (toupper(choice )== 'D')
		{
			gender = 1;
			ClearScreen();
		}
		else
		{
			ClearScreen();
			printf("Please tell me if you have Mommy or Daddy issues. I need to know!\n");
			choice = getchar();
			while (getchar() != '\n')
			{

			}
		}
	} while (toupper(choice) != 'M' && toupper(choice) != 'D'); */

	printf("%s", chp1.stm2);
	//printf("Try to find a torch to look around this dark place. Maybe we can find them together!\n");
	getchar();
	ClearScreen();

	printf("%s", chp1.stm3);
	//printf("*You pick up a torch*\n");
	getchar();
	ClearScreen();

	printf("%s", chp1.stm4);
	//printf("Oh hey I forgot to ask, what would you like me to call you?\n>> ");
	scanf("%s", name);
	while (getchar() != '\n')
	{

	}
	ClearScreen();

	do
	{
		printf("%s %s", name, chp1.stm5);
		//printf("%s right?\n(Y)es\n(N)o\n>> ", name);
		choice2 = getchar();
		while (getchar() != '\n')
		{

		}
		if (toupper(choice2) == 'N')
		{
			ClearScreen();
			printf("Then what would you like to be called?\n");
			scanf("%s", name);
			while (getchar() != '\n')
			{

			}
			ClearScreen();
		}
	} while (toupper(choice2) != 'Y');


	if (gender == 1)
	{
		ClearScreen();
		printf("%s %s", name, chp1.stm7);
		//printf("%s is such a cool name!\n", name);
		getchar();
	}
	else if (gender == 0)
	{
		ClearScreen();
		printf("%s %s", name, chp1.stm6);
		//printf("%s is such a beautiful name!\n", name);
		getchar();
	}

	ClearScreen();
	printf("%s", chp1.stm8);
	//printf("I think I hear someone. I hope  you're ready to get us out of here!\n\n\n\n\n\n\n\n\n\n");
	printf("\nPress Enter to continue...");
	
	getchar();

	GameStateManagerSetNextState(GsPlay);
}