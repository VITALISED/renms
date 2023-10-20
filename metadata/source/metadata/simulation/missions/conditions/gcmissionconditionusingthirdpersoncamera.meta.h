#pragma once
#include <metadata/metadata_common.h>
enum eUsingCameraMode
{
    EUsingCameraMode_OnFoot = 0,
    EUsingCameraMode_Ship = 1,
    EUsingCameraMode_Vehicle = 2,
}

class cGcMissionConditionUsingThirdPersonCamera
{
    static unsigned long long muNameHash = 0x1966AFFB10CA6C7C;
    static unsigned long long muTemplateHash = 0xB9D1A5B382D201F1;

    eUsingCameraMode UsingCameraMode;
}
