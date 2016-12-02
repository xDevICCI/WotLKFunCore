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

#include "ScriptMgr.h"
#include "Chat.h"

class enables_commandscript : public CommandScript
{
public:
    enables_commandscript() : CommandScript("enables_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand toggleCommandTable[] =
        {
            { "summon",         SEC_PLAYER,      false, &HandleToggleSummonCommand,         "", NULL },
            { "appear",         SEC_PLAYER,      false, &HandleToggleAppearCommand,         "", NULL },
            { "status",         SEC_PLAYER,      false, &HandleToggleStatusCommand,         "", NULL },
            { NULL,             0,               false, NULL,                               "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "toggle",         SEC_PLAYER,     false, NULL,                  "", toggleCommandTable },
            { NULL,             0,              false, NULL,                               "", NULL }
        };
        return commandTable;
    }

    static bool HandleToggleAppearCommand(ChatHandler* handler, const char* args)
    {
	    if (!handler->GetSession() && !handler->GetSession()->GetPlayer())
		    return false;

	    std::string argstr = (char*)args;

	    if (!*args)
	    {
		    if (handler->GetSession()->GetPlayer()->GetCommandStatus(TOGGLE_APPEAR))
			    argstr = "off";	
		    else
			    argstr = "on";
	    }

	    if (argstr == "on")
	    {
		    handler->GetSession()->GetPlayer()->m_toggleAppear = true;
		    handler->PSendSysMessage(LANG_YOU_CAN_BE_APPEARED);
		    return true;
	    }
	    else if (argstr == "off")
	    {
		    handler->GetSession()->GetPlayer()->m_toggleAppear = false;
		    handler->PSendSysMessage(LANG_YOU_CANT_BE_APPEARED);
		    return true;
	    }

        return false;
    }

    static bool HandleToggleSummonCommand(ChatHandler* handler, const char* args)
    {
	    if (!handler->GetSession() && !handler->GetSession()->GetPlayer())
		    return false;

	    std::string argstr = (char*)args;

	    if (!*args)
	    {
		    if (handler->GetSession()->GetPlayer()->GetCommandStatus(TOGGLE_SUMMON))
			    argstr = "off";	
		    else
			    argstr = "on";
	    }

	    if (argstr == "on")
	    {
		    handler->GetSession()->GetPlayer()->m_toggleSummon = true;
		    handler->PSendSysMessage(LANG_YOU_CAN_BE_SUMMONED);
		    return true;
	    }
	    else if (argstr == "off")
	    {
		    handler->GetSession()->GetPlayer()->m_toggleSummon = false;
		    handler->PSendSysMessage(LANG_YOU_CANT_BE_SUMMONED);
		    return true;
	    }

        return false;
    }

    static bool HandleToggleStatusCommand(ChatHandler* handler, char const* /*args*/)
    {
	    if (!handler->GetSession() && !handler->GetSession()->GetPlayer())
		    return false;

	    Player* player = handler->GetSession()->GetPlayer();

	    if(player->GetCommandStatus(TOGGLE_APPEAR))
	       handler->PSendSysMessage(LANG_STATUS_APPEAR_ACTIVE);
	    if(player->GetCommandStatus(TOGGLE_SUMMON))
	       handler->PSendSysMessage(LANG_STATUS_SUMMON_ACTIVE);

	    if(!player->GetCommandStatus(TOGGLE_APPEAR))
	       handler->PSendSysMessage(LANG_STATUS_APPEAR_DISABLED);
	    if(!player->GetCommandStatus(TOGGLE_SUMMON))
	       handler->PSendSysMessage(LANG_STATUS_SUMMON_DISABLED);

        return true;
    }
};

void AddSC_enables_commandscript()
{
    new enables_commandscript();
}
