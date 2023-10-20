#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionConditionBaseQuery
{
    static unsigned long long muNameHash = 0xDAD32FDD35922F28;
    static unsigned long long muTemplateHash = 0x9F2B92D1DDCF62D3;

    cGcBaseSearchFilter BaseSearchFilter;
    int miMinBasesFound;
    int miMaxBasesFound;
    float mfSearchDistanceLimit;
    bool mbTakeSpecificPartIdFromSeasonData;
}
