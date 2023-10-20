#pragma once
#include <metadata/metadata_common.h>
enum eRequirePlayerAction
{
    ERequirePlayerAction_None = 0,
    ERequirePlayerAction_Fire = 1,
    ERequirePlayerAction_InShip = 2,
    ERequirePlayerAction_OnFoot = 3,
    ERequirePlayerAction_OnFootOutside = 4,
    ERequirePlayerAction_Upload = 5,
}
enum eDistanceCheckType
{
    EDistanceCheckType_Radius = 0,
    EDistanceCheckType_BoundingBox = 1,
}

class cGcPlayerNearbyEvent
{
    static unsigned long long muNameHash = 0x8A8D7D07807BE9DC;
    static unsigned long long muTemplateHash = 0x3AA04401A1C10893;

    eRequirePlayerAction RequirePlayerAction;
    float mfDistance;
    float mfAngle;
    bool mbAnglePlayerRelative;
    float mfAngleOffset;
    bool mbAngleReflected;
    float mfAngleMinDistance;
    eDistanceCheckType DistanceCheckType;
    bool mbInverse;
    bool mbOnlyForLocalPlayer;
    bool mbIncludeAllPhysics;
    bool mbIncludeMobileNPCs;
    bool mbTeleporterCountsAsPlayer;
}
