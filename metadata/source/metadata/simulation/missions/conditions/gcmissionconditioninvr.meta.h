#pragma once
#include <metadata/metadata_common.h>

class cGcMissionConditionInVR
{
    static unsigned long long muNameHash = 0xC52227A9653C40A8;
    static unsigned long long muTemplateHash = 0x761B5B086FB9A7E8;

    bool mbNeedsHandControllers;
    bool mbNeedsSnapTurnOn;
    bool mbNeedsNoHandControllers;
    bool mbNeedsTeleportOn;
    bool mbNeedsSmoothMoveOn;
}
