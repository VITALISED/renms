#pragma once
#include <metadata/metadata_common.h>

class cGcQuestItemPlacementRule
{
    static unsigned long long muNameHash = 0xBA1C4B136F163FC8;
    static unsigned long long muTemplateHash = 0x753A9EED32FC4309;

    TkID<128> mQuestItemID;
    int miMinRoomIndex;
    int miMaxRoomIndex;
    TkID<128> mMustBeBeforeQuestItem;
    TkID<128> mMustBeAfterQuestItem;
    cTkDynamicArray<TkID<128>> maValidRoomIDs;
}
