/* WotLKFunCore is a custom fun server built for
* World of Warcarft game build 3.3.5b. (12345)
*
* Copyright (C) 2008-2016 JustACore.
* Copyright (C) 2008-2016 TrinityCore.
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

#include "ScriptPCH.h"
#include "halls_of_reflection.h"

enum Yells
{
    SAY_AGGRO                                     = -1668060,
    SAY_SLAY_1                                    = -1668061,
    SAY_SLAY_2                                    = -1668062,
    SAY_DEATH                                     = -1668063,
    SAY_CORRUPTED_FLESH_1                         = -1668064,
    SAY_CORRUPTED_FLESH_2                         = -1668065,
};

enum Spells
{
    SPELL_OBLITERATE                              = 72360,
    SPELL_WELL_OF_CORRUPTION                      = 72362,
    SPELL_CORRUPTED_FLESH                         = 72363,
    SPELL_SHARED_SUFFERING                        = 72368,
};

enum Events
{
    EVENT_NONE,
    EVENT_OBLITERATE,
    EVENT_WELL_OF_CORRUPTION,
    EVENT_CORRUPTED_FLESH,
    EVENT_SHARED_SUFFERING,
};

class boss_marwyn : public CreatureScript
{
public:
    boss_marwyn() : CreatureScript("boss_marwyn") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_marwynAI(creature);
    }

    struct boss_marwynAI : public boss_horAI
    {
        boss_marwynAI(Creature* creature) : boss_horAI(creature) {}

        void Reset()
        {
            boss_horAI::Reset();

            if (instance)
                instance->SetData(DATA_MARWYN_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            if (instance)
                instance->SetData(DATA_MARWYN_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_OBLITERATE, 30000);          // TODO Check timer
            events.ScheduleEvent(EVENT_WELL_OF_CORRUPTION, 13000);
            events.ScheduleEvent(EVENT_CORRUPTED_FLESH, 20000);
            events.ScheduleEvent(EVENT_SHARED_SUFFERING, 20000);    // TODO Check timer
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (instance)
                instance->SetData(DATA_MARWYN_EVENT, DONE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void UpdateAI(const uint32 diff)
        {
            // Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_OBLITERATE:
                    DoCast(SPELL_OBLITERATE);
                    events.ScheduleEvent(EVENT_OBLITERATE, 30000);
                    break;
                case EVENT_WELL_OF_CORRUPTION:
                    DoCast(SPELL_WELL_OF_CORRUPTION);
                    events.ScheduleEvent(EVENT_WELL_OF_CORRUPTION, 13000);
                    break;
                case EVENT_CORRUPTED_FLESH:
                    DoScriptText(RAND(SAY_CORRUPTED_FLESH_1, SAY_CORRUPTED_FLESH_2), me);
                    DoCast(SPELL_CORRUPTED_FLESH);
                    events.ScheduleEvent(EVENT_CORRUPTED_FLESH, 20000);
                    break;
                case EVENT_SHARED_SUFFERING:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_SHARED_SUFFERING);
                    events.ScheduleEvent(EVENT_SHARED_SUFFERING, 20000);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_marwyn()
{
    new boss_marwyn();
}
