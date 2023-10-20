#pragma once
#include <metadata/metadata_common.h>

class cGcBuildingDistribution
{
    static unsigned long long muNameHash = 0xF28B5D3A889453A9;
    static unsigned long long muTemplateHash = 0x99D79E3090915908;

    TkID<128> mName;
    int miMinDistance;
    int miMaxDistance;
}
