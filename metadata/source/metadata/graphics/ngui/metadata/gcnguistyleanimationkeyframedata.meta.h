#pragma once
#include <metadata/metadata_common.h>

class cGcNGuiStyleAnimationKeyframeData
{
    static unsigned long long muNameHash = 0x9A051A6D204FA9F2;
    static unsigned long long muTemplateHash = 0x1B8AD43A964FB688;

    float mfPosition;
    cTkDynamicArray<cTkClassPointer> maStyleProperties;
}
