#pragma once
#include <metadata/metadata_common.h>
enum eCameraOrigin
{
    ECameraOrigin_ExternalBase = 0,
}

class cGcCameraAmbientSpecialData
{
    static unsigned long long muNameHash = 0xC266DA7C9BDD51E7;
    static unsigned long long muTemplateHash = 0x54091498A2F3C101;

    TkID<128> mAnimation;
    TkID<128> mDroneAnimation;
    eCameraOrigin CameraOrigin;
    bool mbUseLookAt;
    bool mbAvoidTerrain;
}
