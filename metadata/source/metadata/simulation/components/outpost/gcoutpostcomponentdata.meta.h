#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcOutpostComponentData
{
    static unsigned long long muNameHash = 0x184558FBF0A370E2;
    static unsigned long long muTemplateHash = 0xEB9332FF5C26A774;

    bool mbAnomaly;
    bool mbFrigate;
    bool mbSpaceStation;
    bool mbNexusExterior;
    bool mbNexusInterior;
    bool mbAIDestination;
    bool mbHasDoors;
    bool mbHasOwnGravity;
    TkID<128> mDoor;
    bool mbCheckLandingAreaClear;
    float mfCircleRadius;
    float mfApproachRange;
    float mfApproachAngle;
    float mfApproachSpeed;
    float mfPlayerAutoLandRange;
    float mfLandingSpeed;
    float mfLandingHeight;
    bool mbRotateToDock;
    float mfTakeOffHeight;
    float mfTakeOffFwdDist;
    float mfTakeOffTime;
    float mfTakeOffAlignTime;
    float mfTakeOffSpeed;
    float mfTakeOffBoost;
    float mfTakeOffExtraAIHeight;
    float mfPostTakeOffExtraPlayerHeight;
    float mfPostTakeOffExtraPlayerSpeed;
    float mfTakeOffProgressForExtraHeight;
    cTkDynamicArray<cGcOutpostLSystemPair> maLSystems;
}
