#pragma once
#include <metadata/metadata_common.h>
#include <metadata/ngui/tknguigraphicstyledata.meta.h>
#include <metadata/animation/tkcurvetype.meta.h>
enum eAnimate
{
    EAnimate_None = 0,
    EAnimate_WipeRightToLeft = 1,
    EAnimate_SimpleWipe = 2,
    EAnimate_SimpleWipeDown = 3,
    EAnimate_CustomWipe = 4,
    EAnimate_CustomWipeAlpha = 5,
}

class cTkNGuiGraphicStyle
{
    static unsigned long long muNameHash = 0xB70875CDF93EECEC;
    static unsigned long long muTemplateHash = 0x14961F4B4436B554;

    cTkNGuiGraphicStyleData Default;
    cTkNGuiGraphicStyleData Highlight;
    cTkNGuiGraphicStyleData Active;
    cTkVector2 mCustomMinStart;
    cTkVector2 mCustomMaxStart;
    float mfHighlightTime;
    float mfHighlightScale;
    float mfGlobalFade;
    float mfAnimTime;
    float mfAnimSplit;
    cTkCurveType AnimCurve1;
    cTkCurveType AnimCurve2;
    eAnimate Animate;
    bool mbInheritStyleFromParentLayer;
}
