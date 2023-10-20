#pragma once
#include <metadata/metadata_common.h>
enum eForHotspotType
{
    EForHotspotType_Any = 0,
    EForHotspotType_Power = 1,
    EForHotspotType_Gas = 2,
    EForHotspotType_Minerals = 3,
}

class cGcMissionConditionIsSurveying
{
    static unsigned long long muNameHash = 0xD3E5CFFA024865D7;
    static unsigned long long muTemplateHash = 0x3F14B5FCAAEFF5F;

    eForHotspotType ForHotspotType;
    bool mbRequireAlreadyAnalysed;
}
