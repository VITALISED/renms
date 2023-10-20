#pragma once
#include <metadata/metadata_common.h>
enum ePetAction
{
    EPetAction_Tickle = 0,
    EPetAction_Treat = 1,
    EPetAction_Ride = 2,
    EPetAction_Customise = 3,
    EPetAction_Abandon = 4,
    EPetAction_LayEgg = 5,
    EPetAction_Adopt = 6,
    EPetAction_Milk = 7,
    EPetAction_HarvestSpecial = 8,
}

class cGcCreaturePetRewardActions
{
    static unsigned long long muNameHash = 0xA78B3BB0870D4585;
    static unsigned long long muTemplateHash = 0xA7BB173D3DEC06E0;

    ePetAction PetAction;
}
