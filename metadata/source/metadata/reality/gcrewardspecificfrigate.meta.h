#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcRewardSpecificFrigate
{
    static unsigned long long muNameHash = 0xB9F3B9FAC994498B;
    static unsigned long long muTemplateHash = 0x1643846F26B79DF3;

    cGcFrigateClass FrigateClass;
    unsigned long long mui64FrigateSeed;
    unsigned long long mui64SystemSeed;
    cGcAlienRace AlienRace;
    TkID<256> mNameOverride;
    bool mbIsGift;
    bool mbIsRewardFrigate;
    bool mbFormatAsSeasonal;
    bool mbUseSeedFromCommunicator;
    TkID<128> mPrimaryTrait;
}
