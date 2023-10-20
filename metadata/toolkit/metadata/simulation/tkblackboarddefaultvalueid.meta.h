#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboardcategory.meta.h>

class cTkBlackboardDefaultValueId
{
    static unsigned long long muNameHash = 0x51BC6BBE6D56FC99;
    static unsigned long long muTemplateHash = 0x8120304A040520DE;

    cTkBlackboardCategory BlackboardCategory;
    TkID<128> mBlackboardKey;
    TkID<128> mDefaultValue;
}
