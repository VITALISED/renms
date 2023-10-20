#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cTkAnimCompactMetadata
{
    static unsigned long long muNameHash = 0x8D1F8DB67274D95A;
    static unsigned long long muTemplateHash = 0x4BFF64F3341B71C2;

    cTkDynamicArray<cTkAnimNodeData> maNodeData;
    cTkDynamicArray<cTkAnimNodeFrameHalfData> maAnimFrameData;
    cTkAnimNodeFrameHalfData StillFrameData;
    int miFrameCount;
    int miNodeCount;
    bool mbHas30HzFrames;
}
