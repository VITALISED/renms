#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcStatsEntry
{
    static unsigned long long muNameHash = 0x4309D65C13EEC689;
    static unsigned long long muTemplateHash = 0x54FBF7B560FB6EC0;

    cGcStatsTypes Type;
    cTkColour mColour;
    float mfRangeMin;
    float mfRangeMax;
    bool mbLessIsBetter;
    TkID<128> mBaseTechID;
}
