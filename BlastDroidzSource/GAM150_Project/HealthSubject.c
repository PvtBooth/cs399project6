﻿/******************************************************************************/
/*!
	\file   HealthSubject.c
	\author Henry Brobeck
	\date   2/8/2017
	\par    Project: BlastDroids
	\par    Copyright © 2017 DigiPen (USA) Corporation.
	\brief
 */
/******************************************************************************/

#include "HealthSubject.h"

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


/**
 * \brief Send a damage event to an entity
 * \param attacker The entity sending this damage
 * \param defender The entity recieving this damage
 * \param damage The ammount of damage to send
 */
void HealthSubject_DamageNotify(Entity* attacker, Entity* defender, float damage)
{
  DamageData data;
  data.attacker = attacker;
  data.damage = damage;
  Entity_LocalEvent(defender, EVENT_DAMAGE, &data);

}


/*------------------------------------------------------------------------------
// Private Functions:
//----------------------------------------------------------------------------*/
