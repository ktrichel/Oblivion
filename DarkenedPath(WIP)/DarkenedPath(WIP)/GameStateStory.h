#pragma once
#include "stdafx.h"
#include "GameStateTable.h" /* struct GameState */
#include "GameStateManager.h" 
#include "Character.h"
#ifdef __cplusplus
extern "C" {	/* Assume C declarations for C++ */
#endif
/*
	struct NARRATIVE
	{
		/* struct of statements 
		char stm1[150];
		char stm2[150];
		char stm3[150];
		char stm4[150];
		char stm5[150];
		char stm6[150];
		char stm7[150];
		char stm8[150];
	};
	struct NARRATIVE chp1 = { /*1 "Are you lost? Do you remember if you with your mom, or your dad?\n>> ",/*2 "Try to find a torch to look around this dark place. Maybe we can find them together!",
							/*3 "*You pick up a torch*",/*4"Oh hey I forgot to ask, what would you like me to call you?\n>> ", /*5 "right?\n(Y)es\n(N)o\n>> ", /*6 "is such a beatiful name!", /*7"is such a cool name!"
							/*8 "I think I hear someone. I hope  you're ready to get us out of here!\n\n\n\n\n\n\n\n\n\n" };*/

	void GameStateStoryInit();

	void GameStateStoryExit();

	void GameStateStoryUpdate(float dt); 

#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif
