#pragma once
#include <metadata/metadata_common.h>
#include <metadata/reality/stats/gcstatstypes.meta.h>
#include <metadata/simulation/weapons/gcremoteweapons.meta.h>

class cGcShipWeaponData
{
    static unsigned long long muNameHash = 0x73BA1311CF8E1962;
    static unsigned long long muTemplateHash = 0x22F67703D63F082D;

    TkID<128> mProjectile;
    cGcStatsTypes Stat;
    bool mbIsProjectile;
    TkID<128> mReticle;
    float mfAutoAimAngle;
    float mfAutoAimExtraAngle;
    bool mbShowOverheatSwitch;
    float mfOverheatCoolTime;
    float mfCoolRate;
    cGcRemoteWeapons RemoteType;
}
