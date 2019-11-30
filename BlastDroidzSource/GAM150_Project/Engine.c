﻿/******************************************************************************/
/*!
	\file   Engine.c
	\author Henry Brobeck
	\date   1/18/2017
	\par    Project: BlastDroids
	\par    Copyright © 2017 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/
#pragma warning(disable: 4996)

#include "Engine.h"
#include "Sound.h"
#include "Entity.h"
#include <AEMath.h>
#include "Graphics.h"
#include "PhysicsManager.h"
#include "Input.h"
#include "Time.h"
#include "AIManager.h"
#include "Log.h"
#include "Player.h"
#include "Physics_BroadPhase.h"
#include "Camera.h"
#include "Text.h"


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

static f64 last;
static int debugCounter = 0;

/*------------------------------------------------------------------------------
// Private Function Declarations:
//----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
// Public Functions:
//----------------------------------------------------------------------------*/

/*!
 \brief Initialize all base engine modules
 */
void Engine_Init(HINSTANCE instanceH, HINSTANCE prevInstanceH, LPSTR command_line, int show)
{
  AllocConsole();
  *freopen("CONOUT$", "w", stdout);

 
  Graphics_Init(instanceH, prevInstanceH, command_line, show);
  Text_Init();
  InputEvent_Init();
  Entity_Init();
  Sound_Init();
  PhysicsManager_Init();
  AIManager_Init();
  AEGetTime(&last);

  
}

/*!
 \brief update all engine modules
 \return Change in time (in seconds) since last game loop.
 */
float Engine_UpdateStart(void)
{
  AESysFrameStart();

  AEInputUpdate();
  

  f64 current;
  AEGetTime(&current);
  float delta = (float)(current - last); //TODO: Cap frame rate?
  //delta = 1.0f/60.0f  ;
  Time_Update(delta);
  LogDataTime timeData;
  timeData.time = Time_Get();
  Log_LogData(LOG_TYPE_TIME, ((LogDataGeneric){"Engine.c"}), &timeData);
  last = current;
  delta = 1.0f / 60.0f; //Keep this here. It will fix the dt, which makes it so that the game will slow down, but we want that to keep the physics working well.

  debugCounter++;
  if (debugCounter >= 5)
  {
    LogDataGeneric genericData = { "Engine.c" };
    for (int i = 0; i < 4; i++)
    {
      Player *p = Player_GetPlayer(i);
      if (p->playerEntity)
      {
        LogDataTransform transformData;
        transformData.entity = p->playerEntity;
        transformData.transform = p->transformComponent;
        Log_LogData(LOG_TYPE_TRANSFORM, genericData, &transformData);
      }
    }
    debugCounter = 0;
  }

  AIManager_Update(delta);
  InputEvent_Update(delta);
  Entity_Update(delta);
  Sound_Update(delta);
  Graphics_Update(delta);
  //AIManager_Debug();
  //Physics_BroadPhase_Debug();

  return delta;
  
}

/**
 * \brief Finish update loop
 */
void Engine_UpdateEnd()
{
  LogDataTime timeData;
  timeData.time = Time_Get();
  Log_LogData(LOG_TYPE_TIME, ((LogDataGeneric){"Engine.c"}), &timeData);
  AESysFrameEnd();
}

/*!
 \brief Shut down all engine modules
 */
void Engine_Exit(void)
{
  Camera_Exit();
  AIManager_Exit();
  PhysicsManager_Exit();
  Entity_Exit();
  Text_Exit();
  Graphics_Exit();
  InputEvent_Exit();
  Sound_Exit();
}



/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/
