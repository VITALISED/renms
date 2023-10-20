#pragma once
#include <metadata/metadata_common.h>
#include <?>
enum eOutOfBoundsBehaviour
{
    EOutOfBoundsBehaviour_NoCost = 0,
    EOutOfBoundsBehaviour_UseFirst = 1,
    EOutOfBoundsBehaviour_UseLast = 2,
}
enum eIndexProvider
{
    EIndexProvider_None = 0,
    EIndexProvider_ShipSlot = 1,
    EIndexProvider_ShipClass = 2,
    EIndexProvider_DailyFreighters = 3,
    EIndexProvider_WeaponClass = 4,
    EIndexProvider_WeaponSlot = 5,
    EIndexProvider_PetSlot = 6,
    EIndexProvider_PilotSlot = 7,
    EIndexProvider_PilotRank = 8,
}

class cGcCostMoneyList
{
    static unsigned long long muNameHash = 0x22A3BF55F268EEBE;
    static unsigned long long muTemplateHash = 0x58EF17D19A623F12;

    cTkDynamicArray<int> maCosts;
    cGcCurrency CostCurrency;
    bool mbAssertIfOutOfBounds;
    eOutOfBoundsBehaviour OutOfBoundsBehaviour;
    eIndexProvider IndexProvider;
}
