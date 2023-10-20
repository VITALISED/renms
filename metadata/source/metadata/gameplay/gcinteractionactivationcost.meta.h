#pragma once
#include <metadata/metadata_common.h>

class cGcInteractionActivationCost
{
    static unsigned long long muNameHash = 0xDF5512FA05691ED2;
    static unsigned long long muTemplateHash = 0xF786CC820054DF74;

    TkID<128> mSubstanceId;
    cTkDynamicArray<TkID<128>> maAltIds;
    int miCost;
    bool mbRepeat;
    TkID<128> mRequiredTech;
    cTkDynamicArray<int> maOnlyChargeDuringSeasons;
}
