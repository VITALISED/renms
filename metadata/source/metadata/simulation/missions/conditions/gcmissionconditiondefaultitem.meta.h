#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/missions/defaultmissionitems/gcdefaultmissionproductenum.meta.h>
#include <metadata/simulation/missions/defaultmissionitems/gcdefaultmissionsubstanceenum.meta.h>

class cGcMissionConditionDefaultItem
{
    static unsigned long long muNameHash = 0x6F38B975D5E86126;
    static unsigned long long muTemplateHash = 0x638524CFD3C9B5F8;

    cGcDefaultMissionProductEnum ProductType;
    cGcDefaultMissionSubstanceEnum SubstanceType;
    TkID<128> mID;
}
