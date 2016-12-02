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

#ifndef DEF_HALLS_OF_STONE_H
#define DEF_HALLS_OF_STONE_H
enum Data
{
    DATA_KRYSTALLUS_EVENT,
    DATA_MAIDEN_OF_GRIEF_EVENT,
    DATA_SJONNIR_EVENT,
    DATA_BRANN_EVENT
};
enum Data64
{
    DATA_KRYSTALLUS,
    DATA_MAIDEN_OF_GRIEF,
    DATA_SJONNIR,
    DATA_KADDRAK,
    DATA_MARNAK,
    DATA_ABEDNEUM,
    DATA_GO_TRIBUNAL_CONSOLE,
    DATA_GO_KADDRAK,
    DATA_GO_MARNAK,
    DATA_GO_ABEDNEUM,
    DATA_GO_SKY_FLOOR,
    DATA_SJONNIR_DOOR,
    DATA_MAIDEN_DOOR
};
enum Creatures
{
    CREATURE_MAIDEN                                        = 27975,
    CREATURE_KRYSTALLUS                                    = 27977,
    CREATURE_SJONNIR                                       = 27978,
    CREATURE_MARNAK                                        = 30897,
    CREATURE_KADDRAK                                       = 30898,
    CREATURE_ABEDNEUM                                      = 30899,
    CREATURE_BRANN                                         = 28070
};
enum GameObjects
{
    GO_ABEDNEUM                                            = 191669,
    GO_MARNAK                                              = 192170,
    GO_KADDRAK                                             = 192171,
    GO_MAIDEN_DOOR                                         = 191292,
    GO_BRANN_DOOR                                          = 191295,
    GO_SJONNIR_DOOR                                        = 191296,
    GO_TRIBUNAL_CONSOLE                                    = 193907,
    GO_TRIBUNAL_CHEST                                      = 190586,
    GO_TRIBUNAL_CHEST_HERO                                 = 193996
};
#endif
