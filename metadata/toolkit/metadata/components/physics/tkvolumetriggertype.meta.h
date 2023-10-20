#pragma once
#include <metadata/metadata_common.h>
enum eVolumeTriggerType
{
    EVolumeTriggerType_Open = 0,
    EVolumeTriggerType_GenericInterior = 1,
    EVolumeTriggerType_GenericGlassInterior = 2,
    EVolumeTriggerType_Corridor = 3,
    EVolumeTriggerType_SmallRoom = 4,
    EVolumeTriggerType_LargeRoom = 5,
    EVolumeTriggerType_OpenCovered = 6,
    EVolumeTriggerType_HazardProtection = 7,
    EVolumeTriggerType_FieldBoundary = 8,
    EVolumeTriggerType_Custom_Biodome = 9,
    EVolumeTriggerType_Portal = 10,
    EVolumeTriggerType_VehicleBoost = 11,
    EVolumeTriggerType_NexusPlaza = 12,
    EVolumeTriggerType_NexusCommunityHub = 13,
    EVolumeTriggerType_NexusHangar = 14,
    EVolumeTriggerType_RaceObstacle = 15,
    EVolumeTriggerType_HazardProtectionCold = 16,
    EVolumeTriggerType_SpaceStorm = 17,
}

class cTkVolumeTriggerType
{
    static unsigned long long muNameHash = 0xA4F2D5595864317D;
    static unsigned long long muTemplateHash = 0x8AEBEF11092A0AA6;

    eVolumeTriggerType VolumeTriggerType;
}
