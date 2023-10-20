#pragma once
#include <metadata/metadata_common.h>
#include <metadata/ngui/tknguialignment.meta.h>

class cTkNGuiTextStyleData
{
    static unsigned long long muNameHash = 0x91FBF976CBE15B5F;
    static unsigned long long muTemplateHash = 0x22A52D3E97156EEF;

    cTkColour mColour;
    cTkColour mShadowColour;
    cTkColour mOutlineColour;
    float mfFontHeight;
    float mfFontSpacing;
    float mfDropShadowAngle;
    float mfDropShadowOffset;
    float mfOutlineSize;
    int miFontIndex;
    cTkNGuiAlignment Align;
    bool mbIsIndented;
    bool mbHasDropShadow;
    bool mbHasOutline;
    bool mbIsParagraph;
    bool mbAllowScroll;
    bool mbForceUpperCase;
    bool mbAutoAdjustHeight;
    bool mbAutoAdjustFontHeight;
    bool mbBlockAudio;
}
