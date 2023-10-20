#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/components/utils/gcactiontriggerstate.meta.h>

class cGcTriggerActionComponentData
{
    static unsigned long long muNameHash = 0x7F5DF5820C8BDB22;
    static unsigned long long muTemplateHash = 0x298A43DD86113262;

    bool mbHideModel;
    bool mbStartInactive;
    cTkDynamicArray<cGcActionTriggerState> maStates;
    bool mbPersistent;
    TkID<128> mPersistentState;
    bool mbResetShotTimeOnStateChange;
    bool mbLinkStateToBaseGrid;
}
