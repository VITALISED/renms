#pragma once
#include <metadata/metadata_common.h>

class cGcSavedInteractionRaceData
{
    static unsigned long long muNameHash = 0x9B192CD525C0A892;
    static unsigned long long muTemplateHash = 0x41001B1CCB31C2FF;

    cTkFixedArray<int> maSavedRaceIndicies;
    cTkFixedArray<bool> maHasLoopedIndicies;
}
