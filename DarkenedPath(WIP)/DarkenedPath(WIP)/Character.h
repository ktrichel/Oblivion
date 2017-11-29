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
		int defense;
		int attack;
	} typedef CHARACTER;

#ifdef __cplusplus
}                      /*  End of extern "C" { */
#endif
