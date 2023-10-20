#pragma once
#include <metadata/metadata_common.h>

class cGcDroneWeaponData
{
    static unsigned long long muNameHash = 0x7652773CA720B160;
    static unsigned long long muTemplateHash = 0x16F8728F6FC68AAF;

    TkID<128> mId;
    TkID<128> mProjectile;
    int miNumProjectiles;
    float mfProjectileSpread;
    float mfFireRate;
    bool mbChangeBarrelEachShot;
    float mfTimeout;
    int miNumShotsMin;
    int miNumShotsMax;
    float mfFireTimeMin;
    float mfFireTimeMax;
    float mfRange;
    float mfExplosionRadius;
    float mfInheritInitialVelocity;
    float mfMoveDistanceMin;
    float mfMoveDistanceMax;
}
