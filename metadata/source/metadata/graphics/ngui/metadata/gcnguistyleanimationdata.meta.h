#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcNGuiStyleAnimationData
{
    static unsigned long long muNameHash = 0x7CC4297B73C8CB65;
    static unsigned long long muTemplateHash = 0x6A052BCED9D7FE6B;

    float mfLength;
    bool mbLoop;
    bool mbAnimateByDefault;
    cTkDynamicArray<cGcNGuiStyleAnimationKeyframeData> maKeyFrames;
}
