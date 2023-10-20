#pragma once
#include <metadata/metadata_common.h>
#include <metadata/gamestate/gcgamemode.meta.h>

class cGcCostGameMode
{
    static unsigned long long muNameHash = 0x5BD84E5380495165;
    static unsigned long long muTemplateHash = 0x95757206A198C;

    bool mbInvertMode;
    cGcGameMode Mode;
    TkID<256> mCostStringCantAfford;
}
