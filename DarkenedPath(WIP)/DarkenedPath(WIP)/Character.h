#pragma once
#include "stdafx.h"
#ifdef __cplusplus
extern "C" {	/* Assume C declarations for C++ */
#endif

	struct CHARACTER
	{
		char (*name)[20];
		int gender;
		int health;
		int defense;
		int attack;
	};
	struct CHARACTER player = { "Xander", 1, 10, 3, 4 };
	struct CHARACTER enemy1 = { "Grunt", 1, 5, 2, 3 };
#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif
