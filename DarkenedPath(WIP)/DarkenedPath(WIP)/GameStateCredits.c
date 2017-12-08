/******************************************************************************/
/*!
\file   GameStateCredits.c
\author Kyle Trichel
\par    Course: GAM100F17
\par    Copyright � 2016 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/
#include "GameStateCredits.h"
#include "GameStateTable.h"


void GameStateCreditsInit()
{
  /*------------------------------------------------------------------------------
	// Setting Windows Console Size
	//----------------------------------------------------------------------------*/
	HWND console = GetConsoleWindow();

  system("mode 160,63");   //Set mode to ensure window does not exceed buffer size
  SMALL_RECT WinRect = { 0, 0, 160, 63 };   //New dimensions for window in 8x12 pixel chars
  SMALL_RECT* WinSize = &WinRect;
  SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

	HWND consoleWindow = GetConsoleWindow();

	SetWindowPos(consoleWindow, 0, 300, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	/*------------------------------------------------------------------------------
	// Setting Windows Console Text Color
	//----------------------------------------------------------------------------*/
	//HANDLE  hConsole;
	//int k = 11;
	//int w;
	//w = 15;
  //
  //
	//hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  //
  //
	///* you can loop k higher to see more color choices */
	///* if echo does not work delete for look and set k = a value i.e k=4 */
  //
 //     SetConsoleTextAttribute(hConsole, k);
 //
 //hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 //
 //SetConsoleTextAttribute(hConsole, w);
 //Wait(500);
}

void GameStateCreditsUpdate(float dt)
{
  /* Tell the compiler that the 'dt' variable is unused. */
  UNREFERENCED_PARAMETER(dt);

  /* Print the message "Press ENTER to continue..." to the screen. */
  printf("Press any button to continue...");

  /* Wait for the user to press ENTER. */
  getch();

  /* Tell the game state manager to switch to the Main Menu state. */
  GameStateManagerSetNextState(GsMainMenu);
}

void GameStateCreditsExit() 
{
  ScreenTransition(3);

  ClearScreen();
}