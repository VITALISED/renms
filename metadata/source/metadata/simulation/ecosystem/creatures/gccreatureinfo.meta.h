#pragma once
#include <metadata/metadata_common.h>
enum eAge
{
    EAge_Regular = 0,
    EAge_Weird = 1,
}
#include <?>

class cGcCreatureInfo
{
    static unsigned long long muNameHash = 0xE85F02E30BDAB35D;
    static unsigned long long muTemplateHash = 0x9B6B93F108A31AE;

    eAge Age;
    cTkFixedString<128,char> macGender1;
    cTkFixedString<128,char> macGender2;
    cTkFixedString<128,char> macTemperament;
    cTkFixedString<128,char> macDiet;
    cTkFixedString<128,char> macWeight1;
    cTkFixedString<128,char> macHeight1;
    cTkFixedString<128,char> macWeight2;
    cTkFixedString<128,char> macHeight2;
    float mfWeight1;
    float mfHeight1;
    float mfWeight2;
    float mfHeight2;
    cTkFixedString<128,char> macNotes;
    cGcRarity Rarity;
    TkID<256> mBiomeDesc;
    TkID<256> mTempermentDesc;
    TkID<256> mDietDesc;
    TkID<256> mNotesDesc;
}
