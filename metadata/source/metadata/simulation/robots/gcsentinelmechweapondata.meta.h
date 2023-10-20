#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/vehicles/gcmechweaponlocation.meta.h>
#include <metadata/simulation/vehicles/gcvehicleweaponmuzzledata.meta.h>
#include <metadata/audio/gcaudiowwiseevents.meta.h>

class cGcSentinelMechWeaponData
{
    static unsigned long long muNameHash = 0x4484F9F6C0F33596;
    static unsigned long long muTemplateHash = 0x750D6BFFAD20F7C5;

    TkID<128> mId;
    TkID<128> mProjectile;
    int miProjectilesPerShot;
    float mfProjectileSpread;
    float mfFireInterval;
    int miNumShotsMin;
    int miNumShotsMax;
    float mfCooldownTimeMin;
    float mfCooldownTimeMax;
    float mfIdealRange;
    float mfMinRange;
    float mfMaxRange;
    float mfAttackAngle;
    float mfExplosionRadius;
    float mfInheritInitialVelocity;
    cGcMechWeaponLocation ShootLocation;
    cGcVehicleWeaponMuzzleData MuzzleData;
    cGcAudioWwiseEvents StartFireAudioEvent;
    cGcAudioWwiseEvents StopFireAudioEvent;
}
