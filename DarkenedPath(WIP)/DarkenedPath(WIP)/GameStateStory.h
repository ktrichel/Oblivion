/******************************************************************************/
/*!
\file   GameStateStory.h
\author Kyle Trichel and Drake Mathis
\par    Course: GAM100F17
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/
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

  void Mini1();
  
	void Chapter2();

  void Mini2();

  void Chapter3();

  void Mini3();

  void Chapter4();

  void Mini4();

  void Father();

  void Epilogue();

#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif
