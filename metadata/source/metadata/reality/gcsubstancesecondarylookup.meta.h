#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/gcsubstancesecondary.meta.h>

class cGcSubstanceSecondaryLookup
{
    static unsigned long long muNameHash = 0x5AF4540465F27753;
    static unsigned long long muTemplateHash = 0xF6D1A7B47F42D3C7;

    TkID<128> mPrimaryID;
    cTkDynamicArray<cGcSubstanceSecondary> maSecondaryChances;
}
