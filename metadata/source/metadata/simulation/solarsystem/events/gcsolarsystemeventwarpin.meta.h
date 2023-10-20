#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>

class cGcSolarSystemEventWarpIn
{
    static unsigned long long muNameHash = 0x71B66F631708B3B1;
    static unsigned long long muTemplateHash = 0x64B0FDB2C959986B;

    cGcSolarSystemLocatorChoice Locator;
    float mfTime;
    int miRepeat;
    cTkVector2 mRepeatIntervalRange;
    bool mbInvertDirection;
    bool mbInstantWarpIn;
    cTkFixedString<32,char> macSquadName;
    cTkSeed mSeed;
    cGcRealityCommonFactions Faction;
    cGcAISpaceshipRoles ShipRole;
    cTkDynamicArray<int> maShipChoiceSequence;
    cTkVector2 mShipCountRange;
    cTkVector2 mWarpIntervalRange;
    cTkVector2 mSpeedRange;
}
