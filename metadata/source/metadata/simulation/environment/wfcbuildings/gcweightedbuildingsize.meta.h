#pragma once
#include <metadata/metadata_common.h>

class cGcWeightedBuildingSize
{
    static unsigned long long muNameHash = 0x90DB43477E714E6D;
    static unsigned long long muTemplateHash = 0xDC7CD8229B1A09FC;

    float mfRelativeProbability;
    int miSizeX;
    int miSizeY;
    int miSizeZ;
    bool mbCreateSymmetricBuilding;
}
