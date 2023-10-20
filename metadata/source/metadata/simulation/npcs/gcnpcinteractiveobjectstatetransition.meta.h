#pragma once
#include <metadata/metadata_common.h>
enum eRequireMode
{
    ERequireMode_Seated = 0,
    ERequireMode_Standing = 1,
    ERequireMode_None = 2,
}

class cGcNPCInteractiveObjectStateTransition
{
    static unsigned long long muNameHash = 0x5CE318610D9BD8D9;
    static unsigned long long muTemplateHash = 0x6C36D5CDE1F2A7AA;

    TkID<128> mNewState;
    float mfProbability;
    TkID<128> mRequireEvent;
    TkID<128> mRequireLocator;
    eRequireMode RequireMode;
    cTkDynamicArray<TkID<128>> maExcludeTags;
}
