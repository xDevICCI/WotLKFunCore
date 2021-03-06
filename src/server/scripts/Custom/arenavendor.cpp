/* WotLKFunCore is a custom fun server built for
* World of Warcarft game build 3.3.5b. (12345)
*
* Copyright (C) 2008-2016 JustACore.
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
#include <cstring>
#include "CharacterDatabaseCleaner.h"
#include "DatabaseEnv.h"
#include "ObjectMgr.h"


class arenavendor : public CreatureScript
{
    public:

        arenavendor()
            : CreatureScript("arenavendor")
        {
        }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
	     if(pPlayer->HasItemCount(50111, 1))
	     {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Buy some items!", GOSSIP_SENDER_MAIN, 1000);
            pPlayer->PlayerTalkClass->SendGossipMenu(907, pCreature->GetGUID());
	     } else {
	     char str[200];
 	     sprintf(str,"You must complete Vault of Achavon to buy Arena Rewards!");
            pPlayer->MonsterWhisper(str,pPlayer->GetGUID(),true);
            pPlayer->PlayerTalkClass->SendCloseGossip();
	     }

            return true;
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
        {
            pPlayer->PlayerTalkClass->ClearMenus();

            switch (uiAction)
            {
            case 1000:
                pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());
                break;
            }


            return true;
        }

};

void AddSC_arenavendor()
{
    new arenavendor();
}