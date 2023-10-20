#pragma once
#include <metadata/metadata_common.h>
enum eHotActionMenuTypes
{
    EHotActionMenuTypes_OnFoot = 0,
    EHotActionMenuTypes_InShip = 1,
    EHotActionMenuTypes_InExocraft = 2,
}

class cGcHotActionMenuTypes
{
    static unsigned long long muNameHash = 0xF0C0C2FEA5315F36;
    static unsigned long long muTemplateHash = 0x631C63205D55D63D;

    eHotActionMenuTypes HotActionMenuTypes;
}
