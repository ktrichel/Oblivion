/******************************************************************************/
/*!
\file   Character.h
\author Kyle Trichel and Drake Mathis
\par    Course: GAM100F17
\par    Copyright © 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/
#pragma once
#include "stdafx.h"
#include "GameStateStory.h"
#ifdef __cplusplus
extern "c" {	/* assume c declarations for c++ */
#endif

	struct CHARACTER
	{
		char name[21];
		int health;
    int maxhealth;
		int defense;
		int attack;
    int level;
    int experience;
    char drop1[20];
    char drop2[20];
    char drop3[20];
	} typedef CHARACTER;


#ifdef __cplusplus
}                      /*  End of extern "C" { */
#endif
