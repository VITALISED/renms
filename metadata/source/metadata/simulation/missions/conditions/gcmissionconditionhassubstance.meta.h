#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/defaultmissionitems/gcdefaultmissionsubstanceenum.meta.h>
#include <metadata/reality/gcitemneedpurpose.meta.h>

class cGcMissionConditionHasSubstance
{
    static unsigned long long muNameHash = 0x9D5EE4FB6274CF9E;
    static unsigned long long muTemplateHash = 0x1397D03F597B56A3;

    cGcDefaultMissionSubstanceEnum Default;
    TkID<128> mSubstance;
    int miAmount;
    bool mbTakeAmountFromSeasonData;
    cGcItemNeedPurpose Purpose;
}
