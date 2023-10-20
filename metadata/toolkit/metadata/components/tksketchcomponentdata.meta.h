#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkSketchComponentData
{
    static unsigned long long muNameHash = 0xBE4097172440769E;
    static unsigned long long muTemplateHash = 0xE91336066F8AE79A;

    float mfGraphPosX;
    float mfGraphPosY;
    float mfGraphZoom;
    float mfUpdateRateMultiplier;
    cTkDynamicArray<cTkSketchNodeData> maNodes;
}
