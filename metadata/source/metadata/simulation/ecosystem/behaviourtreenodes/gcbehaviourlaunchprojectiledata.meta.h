#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/tkblackboarddefaultvalueid.meta.h>

class cGcBehaviourLaunchProjectileData
{
    static unsigned long long muNameHash = 0x4442EB7E64C68AC9;
    static unsigned long long muTemplateHash = 0x1F1BB35707F734B;

    cTkBlackboardDefaultValueId Projectile;
    cTkFixedString<64,char> macLaunchJoint;
    int miAmount;
    float mfHorizontalDispersion;
    float mfVerticalDispersion;
}
