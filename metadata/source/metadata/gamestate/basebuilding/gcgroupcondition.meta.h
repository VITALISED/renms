#pragma once
#include <metadata/metadata_common.h>

class cGcGroupCondition
{
    static unsigned long long muNameHash = 0x342750A176F374A4;
    static unsigned long long muTemplateHash = 0x502E9F43682A9C6;

    cTkDynamicArray<cTkClassPointer> maConditions;
    bool mbORConditions;
}
