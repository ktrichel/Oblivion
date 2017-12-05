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

  system("mode 120,27");   //Set mode to ensure window does not exceed buffer size
  SMALL_RECT WinRect = { 0, 0, 120, 27 };   //New dimensions for window in 8x12 pixel chars
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

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

