#pragma once
#include <metadata/metadata_common.h>
enum eAuthoring
{
    EAuthoring_FixedValue = 0,
    EAuthoring_RandomRangeFloat = 1,
    EAuthoring_Curves = 2,
}
#include <metadata/animation/tkcurvetype.meta.h>

class cTkEmitterFloatProperty
{
    static unsigned long long muNameHash = 0x6ECA0FF0AE9F9E21;
    static unsigned long long muTemplateHash = 0x6E3C701067AF1AF0;

    eAuthoring Authoring;
    float mfFixedValue;
    float mfMinRandomValue;
    float mfMaxRandomValue;
    float mfCurveVariation;
    float mfCurveStartValue;
    float mfCurveMidValue;
    float mfCurveEndValue;
    float mfCurveBlendMidpoint;
    cTkCurveType Curve1Shape;
    cTkCurveType Curve2Shape;
    cTkClassPointer mNextStage;
}
