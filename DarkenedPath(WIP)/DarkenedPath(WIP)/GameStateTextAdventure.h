/******************************************************************************/
/*!
	\file   GameStateTextAdventure.h
	\author Doug Schilling
	\par    Course: GAM100
	\par    Copyright � 2016 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#pragma once

#ifdef __cplusplus
extern "C" {
	/* Assume C declarations for C++ */
#endif

/*------------------------------------------------------------------------------
// Public Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Structures:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

/*!
 \brief
 */
extern void GameStateTextAdventureInit();

/*!
 \param	dt Change in time (in seconds) since last game loop.
 */
extern void GameStateTextAdventureUpdate(float dt);

/*!
 \brief
 */
extern void GameStateTextAdventureExit();

/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif

