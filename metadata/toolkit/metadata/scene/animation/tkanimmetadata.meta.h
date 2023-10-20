#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cTkAnimMetadata
{
    static unsigned long long muNameHash = 0x64CA3907BFF31DA;
    static unsigned long long muTemplateHash = 0x8FCA4C586CEF8D34;

    cTkDynamicArray<cTkAnimNodeData> maNodeData;
    cTkDynamicArray<cTkAnimNodeFrameData> maAnimFrameData;
    cTkAnimNodeFrameData StillFrameData;
    int miFrameCount;
    int miNodeCount;
    bool mbHas30HzFrames;
}
