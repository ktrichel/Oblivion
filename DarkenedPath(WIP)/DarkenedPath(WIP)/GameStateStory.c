#include "stdafx.h"
#include "GameStateStory.h"

struct NARRATIVE
{
	/* struct of statements */
	char stm1[150];
	char stm2[150];
	char stm3[150];
	char stm4[150];
	char stm5[150];
	char stm6[150];
	char stm7[150];
	char stm8[150];
};

void GameStateStoryInit()
{
	struct NARRATIVE pg1 = {"Are you lost? Do you remember if you with your mom, or your dad?","Try to find a torch to look around this dark place. Maybe we can find them together!", 
							"*You pick up a torch*", "Oh hey I forgot to ask, what would you like me to call you?", "%s right?", "%s is such a beatiful name!", "%s is such a cool name!"
							"I think I hear someone. I hope  you're ready to get us out of here!"};
}
void GameStateStoryExit()
{
	ScreenTransition(2);

	ClearScreen();
}
void GameStateStoryUpdate(float dt)
{
	UNREFERENCED_PARAMETER(dt);

	printf("\nPress Enter to continue...");
	
	getchar();

	GameStateManagerSetNextState(GsPlay);
}