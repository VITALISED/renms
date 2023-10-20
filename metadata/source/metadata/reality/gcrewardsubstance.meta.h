#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcRewardSubstance
{
    static unsigned long long muNameHash = 0x3DDFD92393C0D347;
    static unsigned long long muTemplateHash = 0x14FFC7609444086C;

    cGcRealitySubstanceCategory ItemCatagory;
    cGcRarity ItemRarity;
    int miItemLevel;
    int miAmountMin;
    int miAmountMax;
    bool mbDisableMultiplier;
    bool mbRewardAsBlobs;
    bool mbUseFuelMultiplier;
}
