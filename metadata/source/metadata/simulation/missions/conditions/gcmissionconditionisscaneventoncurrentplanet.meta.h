#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionIsScanEventOnCurrentPlanet
{
    static unsigned long long muNameHash = 0xEB5EF017837D2565;
    static unsigned long long muTemplateHash = 0xB6A0C3109DCEDE9E;

    TkID<256> mEvent;
    bool mbAllowInShip;
}
