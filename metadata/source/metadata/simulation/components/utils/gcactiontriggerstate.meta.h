#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/components/utils/gcactiontrigger.meta.h>

class cGcActionTriggerState
{
    static unsigned long long muNameHash = 0x51A3F598097EC1ED;
    static unsigned long long muTemplateHash = 0x80C2AECAA8F3D80A;

    TkID<128> mStateID;
    cTkDynamicArray<cGcActionTrigger> maTriggers;
}
