/* WotLKFunCore is a custom fun server built for
* World of Warcarft game build 3.3.5b. (12345)
*
* Copyright (C) 2008-2016 JustACore.
* Copyright (C) 2008-2016 TrinityCore.
* Copyright (C) 2006-2016 ScriptDev2.
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

/* ScriptData
SDName: Boss_Lord_Alexei_Barov
SD%Complete: 100
SDComment: aura applied/defined in database
SDCategory: Scholomance
EndScriptData */

#include "ScriptPCH.h"
#include "scholomance.h"

#define SPELL_IMMOLATE             20294                    // Old ID  was 15570
#define SPELL_VEILOFSHADOW         17820

class boss_lord_alexei_barov : public CreatureScript
{
public:
    boss_lord_alexei_barov() : CreatureScript("boss_lord_alexei_barov") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lordalexeibarovAI (creature);
    }

    struct boss_lordalexeibarovAI : public ScriptedAI
    {
        boss_lordalexeibarovAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 Immolate_Timer;
        uint32 VeilofShadow_Timer;

        void Reset()
        {
            Immolate_Timer = 7000;
            VeilofShadow_Timer = 15000;

            me->LoadCreaturesAddon();
        }

        void JustDied(Unit* /*killer*/)
        {
            InstanceScript* instance = me->GetInstanceScript();
            if (instance)
            {
                instance->SetData(DATA_LORDALEXEIBAROV_DEATH, 0);

                if (instance->GetData(TYPE_GANDLING) == IN_PROGRESS)
                    me->SummonCreature(1853, 180.73f, -9.43856f, 75.507f, 1.61399f, TEMPSUMMON_DEAD_DESPAWN, 0);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //Immolate_Timer
            if (Immolate_Timer <= diff)
            {
                Unit* target = NULL;
                target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if (target) DoCast(target, SPELL_IMMOLATE);

                Immolate_Timer = 12000;
            } else Immolate_Timer -= diff;

            //VeilofShadow_Timer
            if (VeilofShadow_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_VEILOFSHADOW);
                VeilofShadow_Timer = 20000;
            } else VeilofShadow_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_lordalexeibarov()
{
    new boss_lord_alexei_barov();
}
