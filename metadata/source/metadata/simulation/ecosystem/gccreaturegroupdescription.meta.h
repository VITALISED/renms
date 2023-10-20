#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureGroupDescription
{
    static unsigned long long muNameHash = 0x3F92E065272FE2A9;
    static unsigned long long muTemplateHash = 0xB8ABC40066F421C3;

    TkID<128> mGroup;
    int miMinGroupSize;
    int miMaxGroupSize;
    float mfGroupsPerSquareKm;
}
