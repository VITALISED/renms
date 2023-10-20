#pragma once
#include <metadata/metadata_common.h>
enum eShape
{
    EShape_Rectangle = 0,
    EShape_Ellipse = 1,
    EShape_Line = 2,
    EShape_LineInverted = 3,
    EShape_Bezier = 4,
    EShape_BezierInverted = 5,
    EShape_BezierWide = 6,
    EShape_BezierWideInverted = 7,
}

class cTkNGuiGraphicStyleData
{
    static unsigned long long muNameHash = 0x250B60FD6373D170;
    static unsigned long long muTemplateHash = 0xD456283B718F9F11;

    cTkColour mColour;
    cTkColour mIconColour;
    cTkColour mStrokeColour;
    cTkColour mGradientColour;
    cTkColour mStrokeGradientColour;
    float mfPaddingX;
    float mfPaddingY;
    float mfMarginX;
    float mfMarginY;
    float mfGradientStartOffset;
    float mfGradientEndOffset;
    float mfCornerRadius;
    float mfStrokeSize;
    int miImage;
    int miIcon;
    float mfDesaturation;
    float mfStrokeGradientOffset;
    float mfStrokeGradientFeather;
    eShape Shape;
    eGradient Gradient;
    bool mbSolidColour;
    bool mbHasDropShadow;
    bool mbHasOuterGradient;
    bool mbHasInnerGradient;
    bool mbGradientOffsetPercent;
    bool mbStrokeGradient;
}
