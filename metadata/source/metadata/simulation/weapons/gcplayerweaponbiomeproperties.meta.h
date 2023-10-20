#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcPlayerWeaponBiomeProperties
{
    static unsigned long long muNameHash = 0x7F61AD955291D8A9;
    static unsigned long long muTemplateHash = 0x7B5757AA4A71E8A4;

    cGcBiomeType Biome;
    TkID<128> mMuzzleIdleAnimId;
    TkID<128> mMuzzleFireAnimId;
    TkID<128> mMuzzleChargedAnimId;
    TkID<128> mMuzzleIdleParticlesId;
    TkID<128> mMuzzleFireParticlesId;
    TkID<128> mMuzzleChargedParticlesId;
    TkID<128> mWeaponIdleAnimId;
    TkID<128> mWeaponFireAnimId;
    TkID<128> mWeaponChargedAnimId;
    TkID<128> mWeaponFireParticlesId;
    TkID<128> mProjectile;
    cTkColour mUpgradeColourOverride;
    cTkDynamicArray<cGcStatsBonus> maStatBonusesOverride;
}
