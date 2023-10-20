#pragma once
#include <metadata/metadata_common.h>
#include <metadata/simulation/ecosystem/creatures/data/gccreaturepetrewardactions.meta.h>

class cGcRewardPetAction
{
    static unsigned long long muNameHash = 0x76B0722D154CFD89;
    static unsigned long long muTemplateHash = 0x2452EC99FC0C771B;

    cGcCreaturePetRewardActions PetAction;
    TkID<128> mPlayerEmoteID;
    TkID<128> mEffectID;
    TkID<128> mSpecialHarvestID;
    int miSpecialHarvestMul;
}
