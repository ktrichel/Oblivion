#pragma once
#include "stdafx.h"
#include "GameStateStory.h"
#ifdef __cplusplus
extern "c" {	/* assume c declarations for c++ */
#endif

	struct CHARACTER
	{
		char name[20];
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
