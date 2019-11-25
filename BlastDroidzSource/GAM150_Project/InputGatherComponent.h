﻿/******************************************************************************/
/*!
	\file   InputGatherComponent.h
	\author Evan Kau
	\date   3/11/2017
	\par    Project: BlastDroids
	\par    Copyright © 2017 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#pragma once
#include "Component.h"
#include "InputEvent.h"

/*------------------------------------------------------------------------------
// Public Consts:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Structures:
//----------------------------------------------------------------------------*/

typedef struct InputGatherData InputGatherData;

/*------------------------------------------------------------------------------
// Public Variables:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

Component* InputGatherComponent_Create();

InputEvent* InputGatherComponent_GetInput(InputGatherData *data, INPUT_TYPE type);