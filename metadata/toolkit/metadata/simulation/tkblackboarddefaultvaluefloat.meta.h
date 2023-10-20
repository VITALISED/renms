#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboardcategory.meta.h>

class cTkBlackboardDefaultValueFloat
{
    static unsigned long long muNameHash = 0x45A1CDC5CD2FB6DC;
    static unsigned long long muTemplateHash = 0x9F06630E398C2F3A;

    cTkBlackboardCategory BlackboardCategory;
    TkID<128> mBlackboardKey;
    float mfDefaultValue;
}
