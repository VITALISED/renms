#pragma once
#include <metadata/metadata_common.h>

class cGcExpeditionEventSaveData
{
    static unsigned long long muNameHash = 0xA95CE4EF897F62B2;
    static unsigned long long muTemplateHash = 0xF229AC5E7FE69A17;

    cTkSeed mSeed;
    unsigned long long mui64UA;
    cTkDynamicArray<int> maAffectedFrigateIndices;
    cTkDynamicArray<int> maRepairingFrigateIndices;
    cTkDynamicArray<int> maAffectedFrigateResponses;
    TkID<256> mEventID;
    TkID<256> mInterventionEventID;
    cTkFixedString<64,char> macOverriddenDescription;
    bool mbWhaleEvent;
    TkID<128> mOverriddenReward;
    bool mbSuccess;
    bool mbIsInterventionEvent;
    bool mbAvoidedIntervention;
}
