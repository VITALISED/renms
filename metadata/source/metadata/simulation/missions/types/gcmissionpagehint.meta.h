#pragma once
#include <metadata/metadata_common.h>
enum eMissionPageHint
{
    EMissionPageHint_None = 0,
    EMissionPageHint_Suit = 1,
    EMissionPageHint_Ship = 2,
    EMissionPageHint_Weapon = 3,
    EMissionPageHint_Vehicle = 4,
    EMissionPageHint_Freighter = 5,
    EMissionPageHint_Wiki = 6,
    EMissionPageHint_Catalogue = 7,
    EMissionPageHint_MissionLog = 8,
    EMissionPageHint_Discovery = 9,
    EMissionPageHint_Journey = 10,
    EMissionPageHint_Expedition = 11,
}

class cGcMissionPageHint
{
    static unsigned long long muNameHash = 0xBC45706D394C0853;
    static unsigned long long muTemplateHash = 0xC0BFCC224C77B187;

    eMissionPageHint MissionPageHint;
}
