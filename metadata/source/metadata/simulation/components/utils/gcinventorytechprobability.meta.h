#pragma once
#include <metadata/metadata_common.h>
enum eDesiredTechProbability
{
    EDesiredTechProbability_Never = 0,
    EDesiredTechProbability_Rare = 1,
    EDesiredTechProbability_Common = 2,
    EDesiredTechProbability_Always = 3,
}

class cGcInventoryTechProbability
{
    static unsigned long long muNameHash = 0x71B8CFD20DB7A5E5;
    static unsigned long long muTemplateHash = 0x112E6E11E83935D1;

    TkID<128> mTech;
    eDesiredTechProbability DesiredTechProbability;
}
