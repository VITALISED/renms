#pragma once
#include <metadata/metadata_common.h>

class cTkMagicModelData
{
    static unsigned long long muNameHash = 0x1A5D6B5DC6FCD174;
    static unsigned long long muTemplateHash = 0xF5809AA74DC5AE51;

    cTkDynamicArray<cTkVector3> maVertices;
    cTkVector3 mCentre;
    float mfRadius;
}
