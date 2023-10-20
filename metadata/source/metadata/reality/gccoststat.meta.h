#pragma once
#include <metadata/metadata_common.h>

class cGcCostStat
{
    static unsigned long long muNameHash = 0x1C22335EC8C3634C;
    static unsigned long long muTemplateHash = 0x7857405C8A2A70F3;

    TkID<128> mStat;
    TkID<128> mStatGroup;
    int miValue;
    TkID<256> mCostAsString;
}
