#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcTerrainEditsBuffer
{
    static unsigned long long muNameHash = 0x28A143D89E217108;
    static unsigned long long muTemplateHash = 0xFC8CD57827D81843;

    cTkFixedArray<unsigned long long> maGalacticAddresses;
    cTkFixedArray<int> maBufferSizes;
    cTkFixedArray<unsigned char> maBufferAges;
    cTkFixedArray<cTkVector3> maBufferAnchors;
    cTkFixedArray<bool> maBufferProtected;
    cTkFixedArray<cGcTerrainEdit> maEdits;
}
