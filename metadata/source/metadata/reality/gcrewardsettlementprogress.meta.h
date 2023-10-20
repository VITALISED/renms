#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/environment/gcbuildingclassification.meta.h>

class cGcRewardSettlementProgress
{
    static unsigned long long muNameHash = 0x87616D37E129954C;
    static unsigned long long muTemplateHash = 0x4C3A69C951601A0;

    bool mbUseInteractionBuildingType;
    cGcBuildingClassification BuildingType;
}
