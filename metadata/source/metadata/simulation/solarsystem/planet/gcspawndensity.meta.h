#pragma once
#include <metadata/metadata_common.h>
enum eCoverageType
{
    ECoverageType_Total = 0,
    ECoverageType_SmoothPatch = 1,
    ECoverageType_GridPatch = 2,
}

class cGcSpawnDensity
{
    static unsigned long long muNameHash = 0x36320600C6ADE7CA;
    static unsigned long long muTemplateHash = 0x792F15FD68FA96F3;

    TkID<128> mName;
    bool mbActive;
    eCoverageType CoverageType;
    float mfPatchSize;
    float mfRegionScale;
}
