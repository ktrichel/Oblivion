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

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1000, 500, TRUE); // 800 width, 100 height

	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, 350, 250, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

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

