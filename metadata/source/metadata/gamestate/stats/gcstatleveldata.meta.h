#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcStatLevelData
{
    static unsigned long long muNameHash = 0xECC1CDECFE5FC437;
    static unsigned long long muTemplateHash = 0xFFEFF310D0058C71;

    TkID<256> mLevelName;
    TkID<256> mLevelNameUpper;
    TkID<256> mOSDLevelName;
    cGcStatValueData Value;
    TkID<128> mTrophyToUnlock;
}
