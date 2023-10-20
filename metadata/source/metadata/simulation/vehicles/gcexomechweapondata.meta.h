#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcExoMechWeaponData
{
    static unsigned long long muNameHash = 0xAB111A88D43A92B4;
    static unsigned long long muTemplateHash = 0x34E79E36B5462BA;

    cTkDynamicArray<cGcMechWeaponLocation> maLocationPriority;
    float mfMaintainFireLocationMinTime;
    cTkFixedArray<TkID<128>> maMuzzleFlashDataID;
    float mfAngleToleranceForArmAiming;
    float mfCooldownTimeMin;
    float mfCooldownTimeMax;
    float mfSelectionWeight;
    float mfMinRange;
    float mfMaxRange;
    float mfAttackAngle;
}
