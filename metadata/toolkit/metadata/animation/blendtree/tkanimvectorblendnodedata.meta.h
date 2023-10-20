#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkcurvetype.meta.h>

class cTkAnimVectorBlendNodeData
{
    static unsigned long long muNameHash = 0x541BE758514502E3;
    static unsigned long long muTemplateHash = 0x9113B80EAEF3248A;

    TkID<128> mNodeId;
    cTkFixedString<64,char> macWeightIn;
    float mfWeightRangeBegin;
    float mfWeightRangeEnd;
    float mfWeightSpringTime;
    cTkCurveType WeightCurve;
    float mfInitialWeight;
    cTkClassPointer mBlendChild;
}
