#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkVertexLayout
{
    static unsigned long long muNameHash = 0xDD31F212063601F7;
    static unsigned long long muTemplateHash = 0x74A979AD2A0CECB6;

    int miElementCount;
    int miStride;
    long long mi64PlatformData;
    cTkDynamicArray<cTkVertexElement> maVertexElements;
}
