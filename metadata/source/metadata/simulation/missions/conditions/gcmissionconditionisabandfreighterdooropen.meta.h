#pragma once
#include <metadata/metadata_common.h>
enum eAbandonedFreighterDoorStatus
{
    EAbandonedFreighterDoorStatus_DungeonNotReady = 0,
    EAbandonedFreighterDoorStatus_Locked = 1,
    EAbandonedFreighterDoorStatus_Opening = 2,
    EAbandonedFreighterDoorStatus_Open = 3,
}

class cGcMissionConditionIsAbandFreighterDoorOpen
{
    static unsigned long long muNameHash = 0x337390D414A23798;
    static unsigned long long muTemplateHash = 0x2CE170CA39CB196F;

    eAbandonedFreighterDoorStatus AbandonedFreighterDoorStatus;
}
