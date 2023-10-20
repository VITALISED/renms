#pragma once
#include <metadata/metadata_common.h>
#include <metadata/physics/tkphysicsdata.meta.h>
#include <metadata/components/physics/tkvolumetriggertype.meta.h>
enum eSurfaceProperties
{
    ESurfaceProperties_None = 0,
    ESurfaceProperties_Glass = 1,
}

class cTkPhysicsComponentData
{
    static unsigned long long muNameHash = 0xC58660803669C46F;
    static unsigned long long muTemplateHash = 0x25CD3FFA8E448F4E;

    cTkPhysicsData Data;
    cTkClassPointer mRagdollData;
    cTkVolumeTriggerType TriggerVolumeType;
    eSurfaceProperties SurfaceProperties;
    bool mbTriggerVolume;
    bool mbClimbable;
    bool mbFloor;
    bool mbIgnoreModelOwner;
    bool mbNoVehicleCollide;
    bool mbNoPlayerCollide;
    bool mbCameraInvisible;
    bool mbInvisibleForInteraction;
    bool mbAllowTeleporter;
    bool mbBlockTeleporter;
    bool mbDisableGravity;
    float mfSpinOnCreate;
    bool mbUseBasePartOptimisation;
    bool mbIsTransporter;
}
