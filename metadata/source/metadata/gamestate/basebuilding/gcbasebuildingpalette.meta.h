#pragma once
#include <metadata/metadata_common.h>
enum eSwatchPrimaryColour
{
    ESwatchPrimaryColour_Primary = 0,
    ESwatchPrimaryColour_Secondary = 1,
    ESwatchPrimaryColour_Ternary = 2,
    ESwatchPrimaryColour_Quaternary = 3,
}
enum eSwatchSecondaryColour
{
    ESwatchSecondaryColour_Primary = 0,
    ESwatchSecondaryColour_Secondary = 1,
    ESwatchSecondaryColour_Ternary = 2,
    ESwatchSecondaryColour_Quaternary = 3,
}

class cGcBaseBuildingPalette
{
    static unsigned long long muNameHash = 0xB499CC97C0515963;
    static unsigned long long muTemplateHash = 0xCC9B662A4D061ACE;

    cTkColour mPrimaryColour;
    cTkColour mSecondaryColour;
    cTkColour mTernaryColour;
    cTkColour mQuaternaryColour;
    TkID<256> mName;
    TkID<256> mId;
    eSwatchPrimaryColour SwatchPrimaryColour;
    eSwatchSecondaryColour SwatchSecondaryColour;
}
