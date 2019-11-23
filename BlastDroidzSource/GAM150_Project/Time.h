﻿/******************************************************************************/
/*!
	\file   Time.h
	\author Evan Kau
	\date   2/8/2017
	\par    Project: BlastDroids
	\par    Copyright © 2017 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#pragma once

/*------------------------------------------------------------------------------
// Public Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Structures:
//----------------------------------------------------------------------------*/

typedef struct Time
{
  float dtCur;
  float dtPrev;
  float timeScale;
  float sinceGameStart;
  float sinceStateStart;
} Time;

/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

void Time_Update(float dt);

void Time_ResetStateTime();

void Time_SetTimeScale(float timeScale);

Time *Time_Get();