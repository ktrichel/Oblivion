#pragma once
#include "stdafx.h"
#include "GameStateTable.h" /* struct GameState */
#include "GameStateManager.h" 
#ifdef __cplusplus
extern "C" {	/* Assume C declarations for C++ */
#endif

	void GameStateStoryInit();

	void GameStateStoryExit();

	void GameStateStoryUpdate(float dt);

#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif
