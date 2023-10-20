#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcRewardProceduralProduct
{
    static unsigned long long muNameHash = 0x28EDE156F726CF4C;
    static unsigned long long muTemplateHash = 0xB83297F73B33E488;

    cGcProceduralProductCategory Type;
    TkID<256> mOSDMessage;
    bool mbSubIfPlayerAlreadyHasOne;
    bool mbOverrideRarity;
    cGcRarity Rarity;
}
