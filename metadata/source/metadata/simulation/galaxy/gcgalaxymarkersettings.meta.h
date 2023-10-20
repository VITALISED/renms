#pragma once
#include <metadata/metadata_common.h>

class cGcGalaxyMarkerSettings
{
    static unsigned long long muNameHash = 0xB24FD22ADB1D885D;
    static unsigned long long muTemplateHash = 0x9D337FA7A210A1B8;

    cTkFixedArray<cTkColour> maColours;
    cTkColour mOutlineColour;
    float mfOutlineWidth;
    int miEdgeCount;
    float mfRotationBase;
    float mfLineWidth;
    float mfLineWidthFade;
    float mfSizeScale;
    float mfRadiusFixed;
    float mfRadiusMinimum;
    float mfRadiusBaseOffset;
    float mfRadiusEdge;
    cTkFixedString<128,char> macIcon;
    cTkVector2 mIconSize;
    cTkFixedString<32,char> macMarkerLabel;
    cTkVector2 mTimeScaleRange;
}
