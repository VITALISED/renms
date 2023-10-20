#pragma once
#include <metadata/metadata_common.h>

class cGcCameraAmbientBuildingData
{
    static unsigned long long muNameHash = 0xDF9F37F8504FFE4D;
    static unsigned long long muTemplateHash = 0x120CDC0D966EB569;

    TkID<128> mAnimation;
    TkID<128> mDroneAnimation;
    float mfOffset;
    bool mbUseLookAt;
    bool mbAvoidTerrain;
    cTkFixedArray<bool> maAvailableBuildings;
    cTkFixedArray<bool> maAvailableRaces;
}
