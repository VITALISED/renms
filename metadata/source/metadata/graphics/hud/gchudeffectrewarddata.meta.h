#pragma once
#include <metadata/metadata_common.h>
#include <metadata/animation/tkcurvetype.meta.h>

class cGcHUDEffectRewardData
{
    static unsigned long long muNameHash = 0x4453C3D28B780FD8;
    static unsigned long long muTemplateHash = 0xA1292A1ED2EC32C9;

    int miNumBoxes;
    float mfBoxAnimTime;
    float mfBoxRotate;
    float mfBoxAnimTimeBetweenBoxes;
    cTkCurveType BoxAnimTimeCurve;
    cTkVector2 mBoxSizeStart;
    float mfBoxThicknessStart;
    cTkColour mBoxColourStart;
    cTkVector2 mBoxSizeEnd;
    cTkColour mBoxColourEnd;
    float mfBoxThicknessEnd;
}
