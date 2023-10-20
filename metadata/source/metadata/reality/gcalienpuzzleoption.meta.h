#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcalienmood.meta.h>
#include <metadata/simulation/ecosystem/npcs/gcnpcproptype.meta.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>
#include <metadata/simulation/missions/types/gcmissionconditiontest.meta.h>
#include <metadata/reality/tables/gcwordcategorytableenum.meta.h>

class cGcAlienPuzzleOption
{
    static unsigned long long muNameHash = 0x3FE862FE8570BE69;
    static unsigned long long muTemplateHash = 0xE619E6DFA20C25A2;

    TkID<256> mName;
    TkID<256> mText;
    bool mbIsAlien;
    TkID<128> mCost;
    cTkDynamicArray<TkID<128>> maRewards;
    cGcAlienMood Mood;
    cGcNPCPropType Prop;
    bool mbOverrideWithAlienWord;
    bool mbReseedInteractionOnUse;
    bool mbKeepOpen;
    bool mbDisplayCost;
    bool mbTruncateCost;
    bool mbMarkInteractionComplete;
    TkID<256> mNextInteraction;
    bool mbSelectedOnBackOut;
    cGcAudioWwiseEvents AudioEvent;
    TkID<256> mTitleOverride;
    cGcMissionConditionTest EnablingConditionTest;
    cTkDynamicArray<cTkClassPointer> maEnablingConditions;
    TkID<256> mEnablingConditionId;
    cgcwordcategorytableEnum WordCategory;
}
