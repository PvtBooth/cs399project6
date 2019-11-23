﻿/******************************************************************************/
/*!
	\file   Game.h
	\author HeneryBrobeck
	\date   1/18/2017
	\par    Project: BlastDroids
	\par    Copyright © 2017 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#pragma once
#include <stdbool.h>


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

void Game_Init(void);

void Game_Update(float dt);

void Game_Exit(void);

int Game_IsRunning(void);

void Game_SetRunning(int running);

/*----------------------------------------------------------------------------*/

