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
SDName: Uldaman
SD%Complete: 100
SDComment: Quest support: 2240, 2278 + 1 trash mob.
SDCategory: Uldaman
EndScriptData */

/* ContentData
mob_jadespine_basilisk
npc_lore_keeper_of_norgannon
go_keystone_chamber
at_map_chamber
EndContentData */

#include "ScriptPCH.h"
#include "uldaman.h"

/*######
## mob_jadespine_basilisk
######*/

enum eSpells
{
    SPELL_CRYSTALLINE_SLUMBER   = 3636,
};

class mob_jadespine_basilisk : public CreatureScript
{
    public:

        mob_jadespine_basilisk()
            : CreatureScript("mob_jadespine_basilisk")
        {
        }

        struct mob_jadespine_basiliskAI : public ScriptedAI
        {
            mob_jadespine_basiliskAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 uiCslumberTimer;

            void Reset()
            {
                uiCslumberTimer = 2000;
            }

            void EnterCombat(Unit* /*who*/)
            {
            }

            void UpdateAI(const uint32 uiDiff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //uiCslumberTimer
                if (uiCslumberTimer <= uiDiff)
                {
                    //Cast
                    DoCastVictim(SPELL_CRYSTALLINE_SLUMBER, true);

                    //Stop attacking target thast asleep and pick new target
                    uiCslumberTimer = 28000;

                    Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0);

                    if (!target || target == me->getVictim())
                        target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);

                    if (target)
                        me->TauntApply(target);

                } else uiCslumberTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_jadespine_basiliskAI(creature);
        }
};

/*######
## go_keystone_chamber
######*/

class go_keystone_chamber : public GameObjectScript
{
public:
    go_keystone_chamber() : GameObjectScript("go_keystone_chamber") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        if (InstanceScript* instance = go->GetInstanceScript())
            instance->SetData(DATA_IRONAYA_SEAL, IN_PROGRESS); //door animation and save state.

        return false;
    }
};

/*######
## at_map_chamber
######*/

#define QUEST_HIDDEN_CHAMBER    2240

class AreaTrigger_at_map_chamber : public AreaTriggerScript
{
    public:

        AreaTrigger_at_map_chamber()
            : AreaTriggerScript("at_map_chamber")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
        {
            if (player->GetQuestStatus(QUEST_HIDDEN_CHAMBER) == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(QUEST_HIDDEN_CHAMBER);

            return true;
        }
};

void AddSC_uldaman()
{
    new mob_jadespine_basilisk();
    new go_keystone_chamber();
    new AreaTrigger_at_map_chamber();
}

