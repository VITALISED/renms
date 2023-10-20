#pragma once
#include <metadata/metadata_common.h>
enum eHotspotType
{
    EHotspotType_Power = 1,
    EHotspotType_Mineral1 = 2,
    EHotspotType_Mineral2 = 4,
    EHotspotType_Mineral3 = 8,
    EHotspotType_Gas1 = 16,
    EHotspotType_Gas2 = 32,
}

class cGcRegionHotspotTypes
{
    static unsigned long long muNameHash = 0x1B2443FC607CC2A;
    static unsigned long long muTemplateHash = 0x2D148480DFB092DA;

    eHotspotType HotspotType;
}
