#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionNearScanEvent
{
    static unsigned long long muNameHash = 0x8F7E57B730A9C7F8;
    static unsigned long long muTemplateHash = 0xC3315643C1652E07;

    TkID<256> mEvent;
    float mfDistance;
    bool mbAllowInShip;
    bool mbRequiresFullFireteam;
    bool mbReturnTrueIfMarkerGone;
}
