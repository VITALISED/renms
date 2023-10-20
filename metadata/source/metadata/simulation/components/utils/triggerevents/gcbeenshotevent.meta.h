#pragma once
#include <metadata/metadata_common.h>
enum eShotBy
{
    EShotBy_Player = 0,
    EShotBy_Anything = 1,
    EShotBy_PlayerOrRemotePlayer = 2,
}

class cGcBeenShotEvent
{
    static unsigned long long muNameHash = 0xF554DC208673EE3D;
    static unsigned long long muTemplateHash = 0xC7EECD09781E1870;

    eShotBy ShotBy;
    int miDamageThreshold;
    float mfHealthThreshold;
}
