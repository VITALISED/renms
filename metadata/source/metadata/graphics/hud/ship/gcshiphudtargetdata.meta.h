#pragma once
#include <metadata/metadata_common.h>
#include <metadata/graphics/hud/ship/gcshiphudtargeticondata.meta.h>

class cGcShipHUDTargetData
{
    static unsigned long long muNameHash = 0x24B6E7D6F92704D5;
    static unsigned long long muTemplateHash = 0x1EF6B898301EEBD5;

    cGcShipHUDTargetIconData IconData;
    cTkFixedString<128,char> macArrow;
    float mfIconSizeIn;
    float mfIconMinSize;
    float mfIconMaxSize;
    float mfIconSizeScale;
    float mfArrowScale;
    float mfArrowOffset;
    float mfArrowMinFadeDist;
    float mfArrowFadeRange;
    float mfArrowMinSize;
    float mfArrowMaxSize;
    cTkColour mBaseColour;
    float mfActiveDistance;
    float mfActivateTime;
    float mfGlowAlpha;
    float mfHighlightTime;
    float mfHitPulse;
    float mfHitPulseTime;
    float mfHitWhiteOut;
    cTkColour mLockColour;
    float mfPoliceColourFreq;
    cTkColour mPoliceColour1;
    cTkColour mPoliceColour2;
    cTkColour mThreatColour;
}
