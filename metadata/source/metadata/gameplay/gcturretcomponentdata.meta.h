#pragma once
#include <metadata/metadata_common.h>
enum eGunType
{
    EGunType_Laser = 0,
    EGunType_Projectile = 1,
    EGunType_Missile = 2,
}

class cGcTurretComponentData
{
    static unsigned long long muNameHash = 0x88530A815E5B1B46;
    static unsigned long long muTemplateHash = 0x88883A0B94FB8352;

    eGunType GunType;
    TkID<128> mLaserEffectId;
    TkID<128> mLaserMuzzleFlashId;
    TkID<128> mProjectileId;
    TkID<128> mProjectileMuzzleFlashId;
    TkID<128> mMissileId;
    bool mbHasFreighterAlertLight;
    float mfTurretRange;
    float mfTurretLaserShootTime;
    float mfTurretLaserLength;
    float mfTurretLaserMoveSpeed;
    float mfTurretLaserActiveTime;
    float mfTurretLaserAbortDistance;
    float mfTurretShootPauseTime;
    int miTurretBurstCount;
    float mfTurretBurstTime;
    float mfTurretMissileLaunchTime;
    float mfTurretMissileLaunchSpeed;
    float mfTurretMaxDownAngle;
    float mfTurretSlerpFactor;
    float mfTurretAngle;
    float mfTurretProjectileRange;
    float mfTurretMissileRange;
    float mfTurretDispersionAngle;
    bool mbRemotePlayersCanDamage;
    bool mbCanMoveDuringBurst;
    bool mbFireInTurretFacing;
    float mfTurretAimOffset;
}
