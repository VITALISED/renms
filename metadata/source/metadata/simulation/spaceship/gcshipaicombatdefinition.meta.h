#pragma once
#include <metadata/metadata_common.h>
#include <metadata/tktextureresource.meta.h>

class cGcShipAICombatDefinition
{
    static unsigned long long muNameHash = 0x27F13746A084A731;
    static unsigned long long muTemplateHash = 0x16D91B292333F7C3;

    TkID<128> mId;
    TkID<128> mBehaviour;
    TkID<128> mPlanetBehaviour;
    TkID<128> mEngine;
    TkID<128> mPlanetEngine;
    TkID<128> mReward;
    int miRewardCount;
    int miHealth;
    int miLevelledExtraHealth;
    TkID<128> mShield;
    TkID<128> mGun;
    int miLaserDamageLevel;
    cTkTextureResource Icon;
}
