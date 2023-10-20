#pragma once
#include <metadata/metadata_common.h>
enum eRestriction
{
    ERestriction_NoMoreThan = 0,
    ERestriction_AtLeast = 1,
    ERestriction_AtLeastIfICan = 2,
}

class cTkLSystemRestrictionData
{
    static unsigned long long muNameHash = 0x2CE937F1C349DD12;
    static unsigned long long muTemplateHash = 0xF3991C126F82FBD;

    int miAmount;
    eRestriction Restriction;
}
