/******************************************************************************/
/*!
\file   ShipSelectStackState.h
\author Ryan Booth
\date   3/9/2017
\par    Project: BlastDroids
\par    Copyright � 2017 DigiPen (USA) Corporation.
\brief
*/
/******************************************************************************/

#pragma once
#include "StackState.h"


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

StackState *ShipSelectStackState_Create();

int ShipSelectStackState_GetPlayerShip(int id);

/*----------------------------------------------------------------------------*/
