/* WotLKFunCore is a custom fun server built for
* World of Warcarft game build 3.3.5b. (12345)
*
* Copyright (C) 2008-2016 JustACore.
* Copyright (C) 2008-2016 TrinityCore.
* Copyright (C) 2005-2016 MaNGOS.
*
* ==== Start of GNU GPL ====
*
* This file is free software; as a special exception the author gives
* unlimited permission to copy and/or distribute it, with or without
* modifications, as long as this notice is preserved.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
* implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* ==== End of GNU GPL ====
*/

#include "HomeMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "WorldPacket.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"

void HomeMovementGenerator<Creature>::Initialize(Creature & owner)
{
    _setTargetLocation(owner);
}

void HomeMovementGenerator<Creature>::Reset(Creature &)
{
}

void HomeMovementGenerator<Creature>::_setTargetLocation(Creature & owner)
{
    if (owner.HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED | UNIT_STATE_DISTRACTED))
        return;

    Movement::MoveSplineInit init(owner);
    float x, y, z, o;
    // at apply we can select more nice return points base at current movegen
    //if (owner.GetMotionMaster()->empty() || !owner.GetMotionMaster()->top()->GetResetPosition(owner,x,y,z))
    //{
    owner.GetHomePosition(x, y, z, o);
    init.SetFacing(o);
    //}
    init.MoveTo(x,y,z);
    init.SetWalk(false);
    init.Launch();

    arrived = false;
    owner.ClearUnitState(UNIT_STATE_ALL_STATE & ~UNIT_STATE_EVADE);
}

bool HomeMovementGenerator<Creature>::Update(Creature &owner, const uint32 /*time_diff*/)
{
    arrived = owner.movespline->Finalized();
    return !arrived;
}

void HomeMovementGenerator<Creature>::Finalize(Creature& owner)
{
    if (arrived)
    {
        owner.ClearUnitState(UNIT_STATE_EVADE);
        owner.SetWalk(true);
        owner.LoadCreaturesAddon(true);
        owner.AI()->JustReachedHome();
    }
}
