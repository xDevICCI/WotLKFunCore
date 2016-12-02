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
SDName: Boss_Lorekeeper_Polkelt
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptPCH.h"
#include "scholomance.h"

#define SPELL_VOLATILEINFECTION      24928
#define SPELL_DARKPLAGUE             18270
#define SPELL_CORROSIVEACID          23313
#define SPELL_NOXIOUSCATALYST        18151

class boss_lorekeeper_polkelt : public CreatureScript
{
public:
    boss_lorekeeper_polkelt() : CreatureScript("boss_lorekeeper_polkelt") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lorekeeperpolkeltAI (creature);
    }

    struct boss_lorekeeperpolkeltAI : public ScriptedAI
    {
        boss_lorekeeperpolkeltAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 VolatileInfection_Timer;
        uint32 Darkplague_Timer;
        uint32 CorrosiveAcid_Timer;
        uint32 NoxiousCatalyst_Timer;

        void Reset()
        {
            VolatileInfection_Timer = 38000;
            Darkplague_Timer = 8000;
            CorrosiveAcid_Timer = 45000;
            NoxiousCatalyst_Timer = 35000;
        }

        void JustDied(Unit* /*killer*/)
        {
            InstanceScript* instance = me->GetInstanceScript();
            if (instance)
            {
                instance->SetData(DATA_LOREKEEPERPOLKELT_DEATH, 0);

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

            //VolatileInfection_Timer
            if (VolatileInfection_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_VOLATILEINFECTION);
                VolatileInfection_Timer = 32000;
            } else VolatileInfection_Timer -= diff;

            //Darkplague_Timer
            if (Darkplague_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_DARKPLAGUE);
                Darkplague_Timer = 8000;
            } else Darkplague_Timer -= diff;

            //CorrosiveAcid_Timer
            if (CorrosiveAcid_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CORROSIVEACID);
                CorrosiveAcid_Timer = 25000;
            } else CorrosiveAcid_Timer -= diff;

            //NoxiousCatalyst_Timer
            if (NoxiousCatalyst_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_NOXIOUSCATALYST);
                NoxiousCatalyst_Timer = 38000;
            } else NoxiousCatalyst_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_lorekeeperpolkelt()
{
    new boss_lorekeeper_polkelt();
}
