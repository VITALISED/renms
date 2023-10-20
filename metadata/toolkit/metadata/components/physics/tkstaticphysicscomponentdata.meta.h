#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cTkStaticPhysicsComponentData
{
    static unsigned long long muNameHash = 0x4955878C6E8051DB;
    static unsigned long long muTemplateHash = 0x99BA278E9CAE3BE9;

    cTkPhysicsData Data;
    bool mbAddToWorldOnPrepare;
    bool mbAddToWorldImmediately;
    cTkVolumeTriggerType TriggerVolumeType;
    bool mbTriggerVolume;
    bool mbClimbable;
    bool mbNoVehicleCollide;
    bool mbNoPlayerCollide;
    bool mbCameraInvisible;
}
