#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcPersistentTerrainEdits
{
    static unsigned long long muNameHash = 0xC6506D02A6391EEB;
    static unsigned long long muTemplateHash = 0xC359CE7CE22DC772;

    unsigned long long mui64GalacticAddress;
    cTkDynamicArray<int> maBufferSizes;
    cTkDynamicArray<cTkVector3> maBufferAnchors;
    cTkDynamicArray<cGcTerrainEdit> maEdits;
}
