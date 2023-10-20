#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/components/gameplay/gcinteractiontype.meta.h>
#include <metadata/reality/gcalienrace.meta.h>

class cGcPlayerTitle
{
    static unsigned long long muNameHash = 0x864FCB26DF972FCF;
    static unsigned long long muTemplateHash = 0x5D71BDFA93D8D2C7;

    TkID<128> mID;
    TkID<256> mTitle;
    TkID<256> mUnlockDescription;
    TkID<256> mAlreadyUnlockedDescription;
    TkID<128> mRevealedBy;
    TkID<128> mUnlockedByProductRecipe;
    TkID<128> mUnlockedByMission;
    TkID<128> mUnlockedByTrophy;
    TkID<128> mUnlockedByStat;
    float mfUnlockedByStatValue;
    int miUnlockedByLeveledStatRank;
    cGcInteractionType UnlockedByInteraction;
    int miUnlockedByInteractionIndex;
    cGcAlienRace UnlockedByInteractionRace;
    bool mbUnlockedByInteractionOnlyTestMainRaces;
}
