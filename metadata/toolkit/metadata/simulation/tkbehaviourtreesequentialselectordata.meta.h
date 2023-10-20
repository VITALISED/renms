#pragma once
#include <metadata/metadata_common.h>

class cTkBehaviourTreeSequentialSelectorData
{
    static unsigned long long muNameHash = 0xF3C0FF9D1D7101FA;
    static unsigned long long muTemplateHash = 0xE2BFCCE9861E998E;

    TkID<128> mName;
    bool mbLooping;
    bool mbFailWhenAnyChildFails;
    cTkDynamicArray<cTkClassPointer> maChildren;
}
