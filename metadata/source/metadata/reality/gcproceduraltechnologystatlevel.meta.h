#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/stats/gcstatstypes.meta.h>
#include <metadata/reality/gcweightingcurve.meta.h>

class cGcProceduralTechnologyStatLevel
{
    static unsigned long long muNameHash = 0xF41CD566C844982A;
    static unsigned long long muTemplateHash = 0xDD37A59489020326;

    cGcStatsTypes Stat;
    float mfValueMin;
    float mfValueMax;
    cGcWeightingCurve WeightingCurve;
    bool mbAlwaysChoose;
}
