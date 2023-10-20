#pragma once
#include <metadata/metadata_common.h>
#include <?>

class cGcMissionConditionWaitForPirates
{
    static unsigned long long muNameHash = 0x978040CE6A2C247B;
    static unsigned long long muTemplateHash = 0x358310F2D3B8F7E8;

    int miLivingPirates;
    bool mbCountHostileTraders;
    bool mbCompleteOnlyInSpace;
    bool mbCareAboutAttackingPlayer;
    bool mbCheckAllFireteamMembers;
    cTkEqualityEnum Test;
}
