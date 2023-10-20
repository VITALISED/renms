#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcHUDManagerData
{
    static unsigned long long muNameHash = 0x756972574B9CCB08;
    static unsigned long long muTemplateHash = 0x205BFEB3B8061079;

    cGcTextPreset TitleFont;
    cGcTextPreset SubtitleFont;
    cGcTextPreset SubtitleFontSmall;
    float mfOSDCoreSize;
    float mfOSDFullSize;
    float mfOSDCoreAlpha;
    float mfOSDBaseTextY;
    float mfOSDBaseBandY;
    float mfOSDBorderY;
    float mfOSDUnderlineWidth;
    float mfPopUpCoreSize;
    float mfPopUpFullSize;
    float mfPopUpCoreAlpha;
    float mfPopUpY;
    float mfPopUpYMidLock;
    float mfOSDFadeSpeed;
    float mfOSDEdgeMergeAlpha;
    float mfOSDTextAppearRate;
    float mfOSDTextFadeRate;
    float mfOSDTextWaitOnAlpha;
    float mfPopUpFadeRate;
    float mfPopUpBGFadeInRate;
    float mfPopUpBGFadeOutRate;
    float mfPopUpBGTriggerFG;
    float mfPromptLine1Y;
    float mfPromptLine2Y;
    int miModelRenderTextureSize;
    int miModelRenderDisplaySize;
    int miModelRenderDisplayBorder;
    float mfModelRenderDisplayOffset;
    float mfModelRenderDisplayMove;
    cTkCurveType ModelRenderDisplayAlphaCurve;
    cTkCurveType ModelRenderDisplayMoveCurve;
}
