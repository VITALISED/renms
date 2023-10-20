#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkLODComponentData
{
    static unsigned long long muNameHash = 0x7F33053EA7D28399;
    static unsigned long long muTemplateHash = 0x112CF83927113B95;

    cTkDynamicArray<cTkLODModelResource> maLODModels;
    float mfCrossFadeTime;
    float mfCrossFadeOverlap;
}
