/******************************************************************************/
/*!
	\file   Utils.c
	\author Doug Schilling
	\par    Course: GAM100
	\par    Copyright © 2016 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#include "stdafx.h" /* NULL, malloc/free, printf, strcmp, */

#pragma warning(push)
#pragma warning(disable: 4001)
#include <time.h>
#pragma warning(pop)

#include "Utils.h"

/*------------------------------------------------------------------------------
// Private Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Structures:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

/* Perform a screen transition effect. */
void ScreenTransition(int length)
{
	ClearScreen();
	for (int j = 0; j < length; j++)
	{
		ClearScreen();
		printf("Loading");
		for (int i = 0; i < 3; ++i)
		{
			Wait(100);
			printf(".");
			Wait(50);
		}
	}

}

/* Clear the screen. */
void ClearScreen()
{
	/* This calls the system command, "cls", which clears the screen. */
	system("cls");
}

/* Wait for a specified number of milliseconds. */
void Wait(long waitTime)
{
	clock_t wakeTime;
	wakeTime = waitTime + clock();
	while (wakeTime > clock())
	{
		/* Do nothing while waiting. */
	}
}

/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/

