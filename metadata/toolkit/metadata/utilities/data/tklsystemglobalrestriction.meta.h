#pragma once
#include <metadata/metadata_common.h>
#include <metadata/utilities/data/tklsystemrestrictiondata.meta.h>

class cTkLSystemGlobalRestriction
{
    static unsigned long long muNameHash = 0x26AACC9ACEE360C5;
    static unsigned long long muTemplateHash = 0xA11CB8562D934F93;

    cTkFixedString<32,char> macName;
    cTkFixedString<128,char> macModel;
    cTkDynamicArray<cTkLSystemRestrictionData> maRestrictions;
}
