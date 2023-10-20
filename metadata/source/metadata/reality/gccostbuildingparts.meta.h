#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcbuildingcostpartcount.meta.h>

class cGcCostBuildingParts
{
    static unsigned long long muNameHash = 0x61447A1079C43833;
    static unsigned long long muTemplateHash = 0x96F0AF27135C9BEA;

    TkID<256> mDescription;
    cTkDynamicArray<cGcBuildingCostPartCount> maRequiredParts;
}
