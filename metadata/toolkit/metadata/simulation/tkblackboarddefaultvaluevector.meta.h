#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboardcategory.meta.h>

class cTkBlackboardDefaultValueVector
{
    static unsigned long long muNameHash = 0x8E91F497B8C8D2F3;
    static unsigned long long muTemplateHash = 0x5AC84CD0356FFBAD;

    cTkBlackboardCategory BlackboardCategory;
    TkID<128> mBlackboardKey;
    cTkVector3 mDefaultValue;
}
