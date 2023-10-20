#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/defaultmissionitems/gcdefaultmissionsubstanceenum.meta.h>

class cGcCostSubstance
{
    static unsigned long long muNameHash = 0xDDDD3B456E0993D3;
    static unsigned long long muTemplateHash = 0x8E0BBA2A23E0B886;

    cGcDefaultMissionSubstanceEnum Default;
    TkID<128> mId;
    int miAmount;
}
