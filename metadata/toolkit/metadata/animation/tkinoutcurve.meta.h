#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkcurvetype.meta.h>

class cTkInOutCurve
{
    static unsigned long long muNameHash = 0x37F732EF5C0B44F6;
    static unsigned long long muTemplateHash = 0x323106FDDDE6667;

    float mfMidpoint;
    cTkCurveType InCurve;
    cTkCurveType OutCurve;
}
