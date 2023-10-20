#pragma once
#include <metadata/metadata_common.h>

class cGcSpaceMapObjectData
{
    static unsigned long long muNameHash = 0x47334DD09E6C3FE9;
    static unsigned long long muTemplateHash = 0x465E44C5E61B503;

    cTkColour mColour;
    bool mbTintModel;
    float mfRadius;
    float mfDistanceMin;
    float mfDistanceRange;
    float mfScaleRange;
    float mfScaleMagnitude;
    float mfScaleMin;
    bool mbOrient;
}
