#pragma once
#include <metadata/metadata_common.h>

class cGcFreighterRoomNPCData
{
    static unsigned long long muNameHash = 0xBCA190142B227B20;
    static unsigned long long muTemplateHash = 0x5E786BA034E9F7BC;

    TkID<128> mRoomID;
    cTkFixedArray<float> maSpawnCapacity;
    cTkFixedArray<float> maPOISelectionWeight;
}
