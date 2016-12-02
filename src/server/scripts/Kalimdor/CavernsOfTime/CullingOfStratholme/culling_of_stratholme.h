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

#ifndef DEF_CULLING_OF_STRATHOLME_H
#define DEF_CULLING_OF_STRATHOLME_H

enum Data
{
    DATA_MEATHOOK_EVENT,
    DATA_SALRAMM_EVENT,
    DATA_EPOCH_EVENT,
    DATA_MAL_GANIS_EVENT,
    DATA_INFINITE_EVENT,
    DATA_ARTHAS_EVENT,
    DATA_CRATE_COUNT,
};

enum Data64
{
    DATA_ARTHAS,
    DATA_MEATHOOK,
    DATA_SALRAMM,
    DATA_EPOCH,
    DATA_MAL_GANIS,
    DATA_INFINITE,
    DATA_SHKAF_GATE,
    DATA_MAL_GANIS_GATE_1,
    DATA_MAL_GANIS_GATE_2,
    DATA_EXIT_GATE,
    DATA_MAL_GANIS_CHEST
};

enum Creatures
{
    NPC_MEATHOOK        = 26529,
    NPC_SALRAMM         = 26530,
    NPC_EPOCH           = 26532,
    NPC_MAL_GANIS       = 26533,
    NPC_INFINITE        = 32273,
    NPC_ARTHAS          = 26499,
    NPC_JAINA           = 26497,
    NPC_UTHER           = 26528,
    NPC_CHROMIE_2       = 27915,
    NPC_GENERIC_BUNNY   = 28960,
};

enum GameObjects
{
    GO_SHKAF_GATE       = 188686,
    GO_MALGANIS_GATE_1  = 187711,
    GO_MALGANIS_GATE_2  = 187723,
    GO_EXIT_GATE        = 191788,
    GO_MALGANIS_CHEST_N = 190663,
    GO_MALGANIS_CHEST_H = 193597,
    GO_SUSPICIOUS_CRATE = 190094,
    GO_PLAGUED_CRATE    = 190095,
};

enum WorldStatesCoT
{
    WORLDSTATE_SHOW_CRATES          = 3479,
    WORLDSTATE_CRATES_REVEALED      = 3480,
    WORLDSTATE_WAVE_COUNT           = 3504,
    WORLDSTATE_TIME_GUARDIAN        = 3931,
    WORLDSTATE_TIME_GUARDIAN_SHOW   = 3932,
};

enum CrateSpells
{
    SPELL_CRATES_CREDIT     = 58109,
};

#endif
