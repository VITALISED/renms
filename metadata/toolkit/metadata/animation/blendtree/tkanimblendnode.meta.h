#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cTkAnimBlendNode
{
    static unsigned long long muNameHash = 0xA394D25E5A975DA5;
    static unsigned long long muTemplateHash = 0x25E024F7E9E3C213;

    TkID<128> mNodeId;
    cTkFixedString<64,char> macWeightIn;
    float mfWeightRangeBegin;
    float mfWeightRangeEnd;
    float mfWeightSpringTime;
    cTkCurveType WeightCurve;
    float mfInitialWeight;
    cTkClassPointer mBlendLeft;
    cTkClassPointer mBlendRight;
}
