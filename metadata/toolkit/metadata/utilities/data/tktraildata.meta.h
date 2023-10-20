#pragma once
#include <metadata/metadata_common.h>

class cTkTrailData
{
    static unsigned long long muNameHash = 0xE0F2CCB358CDA3EE;
    static unsigned long long muTemplateHash = 0xB28F8694B7AEA50;

    float mfWidth;
    int miPoints;
    int miMaxPointsPerFrame;
    float mfDistanceThreshold;
    float mfPointLife;
    int miFrontPoints;
    float mfFrontUvEnd;
}
