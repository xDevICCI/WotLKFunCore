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

#ifndef _AUTHCODES_H
#define _AUTHCODES_H

enum AuthResult
{
    WOW_SUCCESS                                  = 0x00,
    WOW_FAIL_BANNED                              = 0x03,
    WOW_FAIL_UNKNOWN_ACCOUNT                     = 0x04,
    WOW_FAIL_INCORRECT_PASSWORD                  = 0x05,
    WOW_FAIL_ALREADY_ONLINE                      = 0x06,
    WOW_FAIL_NO_TIME                             = 0x07,
    WOW_FAIL_DB_BUSY                             = 0x08,
    WOW_FAIL_VERSION_INVALID                     = 0x09,
    WOW_FAIL_VERSION_UPDATE                      = 0x0A,
    WOW_FAIL_SUSPENDED                           = 0x0C,
    WOW_SUCCESS_SURVEY                           = 0x0E,
    WOW_FAIL_PARENTCONTROL                       = 0x0F,
    WOW_FAIL_LOCKED_ENFORCED                     = 0x10,
    WOW_FAIL_TRIAL_ENDED                         = 0x11,
    WOW_FAIL_USE_BATTLENET                       = 0x12,
    WOW_FAIL_TOO_FAST                            = 0x16,
    WOW_FAIL_CHARGEBACK                          = 0x17,
    WOW_FAIL_GAME_ACCOUNT_LOCKED                 = 0x18,
    WOW_FAIL_INTERNET_GAME_ROOM_WITHOUT_BNET     = 0x19,
    WOW_FAIL_UNLOCKABLE_LOCK                     = 0x20,
    WOW_FAIL_DISCONNECTED                        = 0xFF,
};

enum LoginResult
{
    LOGIN_OK                                     = 0x00,
    LOGIN_FAILED                                 = 0x01,
    LOGIN_FAILED2                                = 0x02,
    LOGIN_BANNED                                 = 0x03,
    LOGIN_UNKNOWN_ACCOUNT                        = 0x04,
    LOGIN_UNKNOWN_ACCOUNT3                       = 0x05,
    LOGIN_ALREADYONLINE                          = 0x06,
    LOGIN_NOTIME                                 = 0x07,
    LOGIN_DBBUSY                                 = 0x08,
    LOGIN_BADVERSION                             = 0x09,
    LOGIN_DOWNLOAD_FILE                          = 0x0A,
    LOGIN_FAILED3                                = 0x0B,
    LOGIN_SUSPENDED                              = 0x0C,
    LOGIN_FAILED4                                = 0x0D,
    LOGIN_CONNECTED                              = 0x0E,
    LOGIN_PARENTALCONTROL                        = 0x0F,
    LOGIN_LOCKED_ENFORCED                        = 0x10,
};

enum ExpansionFlags
{
    POST_BC_EXP_FLAG                            = 0x2,
    PRE_BC_EXP_FLAG                             = 0x1,
    NO_VALID_EXP_FLAG                           = 0x0
};

struct RealmBuildInfo
{
    int Build;
    int MajorVersion;
    int MinorVersion;
    int BugfixVersion;
    int HotfixVersion;
};

namespace AuthHelper
{
    RealmBuildInfo const* GetBuildInfo(int build);
    bool IsAcceptedClientBuild(int build);
    bool IsPostBCAcceptedClientBuild(int build);
    bool IsPreBCAcceptedClientBuild(int build);
};

#endif