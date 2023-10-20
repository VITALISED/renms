#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>
#include <?>
#include <?>

class cGcPlayerWeaponPropertiesData
{
    static unsigned long long muNameHash = 0xD0F82AE353636444;
    static unsigned long long muTemplateHash = 0x2F1095FDA8B8012A;

    cGcPlayerWeaponClass WeaponClass;
    cGcStatsTypes Stat;
    cGcRemoteWeapons RemoteType;
    cTkFixedString<128,char> macMuzzleLaserResource;
    cTkFixedString<128,char> macMuzzleGunResource;
    TkID<128> mDefaultProjectile;
    TkID<128> mDefaultMuzzleIdleAnimId;
    TkID<128> mDefaultMuzzleFireAnimId;
    TkID<128> mDefaultMuzzleChargedAnimId;
    TkID<128> mDefaultMuzzleIdleParticlesId;
    TkID<128> mDefaultMuzzleFireParticlesId;
    TkID<128> mDefaultMuzzleChargedParticlesId;
    TkID<128> mDefaultWeaponIdleAnimId;
    TkID<128> mDefaultWeaponFireAnimId;
    TkID<128> mDefaultWeaponChargedAnimId;
    TkID<128> mDefaultWeaponFireParticlesId;
    float mfMuzzleFlashScale;
    float mfChargingMuzzleFlashMinScale;
    float mfChargingMuzzleFlashMaxScale;
    float mfVibrationScale;
    float mfRumbleScale;
    float mfParticlesOffsetMultiplier;
    TkID<128> mVibartionId;
    TkID<128> mShakeId;
    bool mbUseMuzzleLight;
    bool mbMuzzleLightUsesLaserColour;
    bool mbMuzzleLightUsesMuzzleColour;
    cTkColour mDefaultMuzzleLightColour;
    float mfMuzzleLightIntensity;
    bool mbFlashMuzzleOnProjectileFire;
    bool mbUsesCustomBiomeAnims;
    bool mbUsesCustomBiomeMuzzleParticles;
    bool mbUsesCustomBiomeProjectile;
    bool mbUsesCustomBiomeColour;
    bool mbUsesCustomBiomeFireAnims;
    bool mbUsesCustomBiomeFireParticles;
    bool mbUsesCustomBiomeStats;
    cTkDynamicArray<cGcPlayerWeaponBiomeProperties> maBiomeProperties;
}
