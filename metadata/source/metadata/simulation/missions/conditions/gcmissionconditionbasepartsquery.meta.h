#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/basebuilding/gcbasepartsearchfilter.meta.h>
#include <metadata/gamestate/basebuilding/gcbasesearchfilter.meta.h>

class cGcMissionConditionBasePartsQuery
{
    static unsigned long long muNameHash = 0xDC4640E07A221674;
    static unsigned long long muTemplateHash = 0x4FA6B511C814BF6D;

    cGcBasePartSearchFilter PartsSearchFilter;
    int miMinPartsFound;
    int miMaxPartsFound;
    cGcBaseSearchFilter ExcludeBasesFilter;
    bool mbExcludeGlobalBuffer;
    float mfSearchDistanceLimit;
}
