#pragma once
#include <metadata/metadata_common.h>

class cGcCreatureDiscoveryThumbnailOverride
{
    static unsigned long long muNameHash = 0xF81E00514EB73ED9;
    static unsigned long long muTemplateHash = 0xD6147A31EF214E7B;

    TkID<256> mContainsDescriptor;
    float mfDiscoveryUIScaler;
    cTkVector3 mDiscoveryUIOffset;
}
