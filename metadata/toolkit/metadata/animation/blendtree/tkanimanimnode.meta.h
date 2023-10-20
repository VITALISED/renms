#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkcurvetype.meta.h>

class cTkAnimAnimNode
{
    static unsigned long long muNameHash = 0xEC73620F98D708BF;
    static unsigned long long muTemplateHash = 0xB444741FDF06771E;

    TkID<128> mNodeId;
    TkID<128> mAnimId;
    cTkFixedString<64,char> macPhaseIn;
    cTkCurveType PhaseCurve;
    float mfPhaseRangeBegin;
    float mfPhaseRangeEnd;
}
