#pragma once
#include <metadata/metadata_common.h>
enum eOrigin
{
    EOrigin_SpaceStationInternals = 0,
    EOrigin_SpaceStationBack = 1,
    EOrigin_FreighterBattle = 2,
    EOrigin_Freighter = 3,
    EOrigin_FreighterHangar = 4,
    EOrigin_AtlasStation = 5,
    EOrigin_BlackHole = 6,
    EOrigin_Anomaly = 7,
}

class cGcCameraAmbientSpaceData
{
    static unsigned long long muNameHash = 0x3B1EFAD66E07132E;
    static unsigned long long muTemplateHash = 0xA4725CF1C9F5609E;

    TkID<128> mAnimation;
    TkID<128> mDroneAnimation;
    eOrigin Origin;
}
