#pragma once
#include "stdafx.h"
#include "GameStateTable.h" /* struct GameState */
#include "GameStateManager.h" 

#ifdef __cplusplus
extern "C" {	/* Assume C declarations for C++ */
#endif

void GameStatePlayInit();

void GameStatePlayExit();

void GameStatePlayUpdate(float dt);

int enemy;


#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif
