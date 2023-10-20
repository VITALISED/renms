#pragma once
#include <metadata/metadata_common.h>

class cTkAnimPoseCorrelationData
{
    static unsigned long long muNameHash = 0x36EF2564DBF81DFA;
    static unsigned long long muTemplateHash = 0x40DCE6DF94C5699B;

    TkID<128> mItemA;
    TkID<128> mItemB;
    float mfCorrelation;
}
