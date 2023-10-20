#pragma once
#include <metadata/metadata_common.h>
enum eQuality
{
    EQuality_Normal = 0,
    EQuality_Rare = 1,
    EQuality_Epic = 2,
    EQuality_Legendary = 3,
    EQuality_Illegal = 4,
    EQuality_Sentinel = 5,
}
#include <metadata/reality/gcproceduraltechnologycategory.meta.h>
#include <metadata/reality/gcweightingcurve.meta.h>
#include <metadata/reality/gcproceduraltechnologystatlevel.meta.h>

class cGcProceduralTechnologyData
{
    static unsigned long long muNameHash = 0x6B8472FADE3C492C;
    static unsigned long long muTemplateHash = 0x771B3CF67E3FD8A8;

    TkID<128> mID;
    TkID<128> mTemplate;
    TkID<256> mGroup;
    cTkFixedString<128,char> macName;
    cTkFixedString<128,char> macNameLower;
    cTkFixedString<128,char> macSubtitle;
    cTkFixedString<128,char> macDescription;
    cTkColour mColour;
    eQuality Quality;
    cGcProceduralTechnologyCategory Category;
    int miNumStatsMin;
    int miNumStatsMax;
    cGcWeightingCurve WeightingCurve;
    cTkColour mUpgradeColour;
    cTkDynamicArray<cGcProceduralTechnologyStatLevel> maStatLevels;
}
