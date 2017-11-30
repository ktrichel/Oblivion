#pragma once
//#pragma warning(disable : 4996)

#include "stdafx.h"
#include "GameStateTable.h" /* struct GameState */
#include "GameStateManager.h" 
#include "Character.h"

#ifdef __cplusplus
extern "C" {	/* Assume C declarations for C++ */
#endif

	char name[20];

	void GameStateStoryInit();

	void GameStateStoryExit();

	void GameStateStoryUpdate(float dt); 

  void Chapter1();

#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif
