#pragma once
#include <metadata/metadata_common.h>
#include <?>
#include <?>

class cGcSeasonStateData
{
    static unsigned long long muNameHash = 0x4BC716CF849F5A74;
    static unsigned long long muTemplateHash = 0xF922077B7CBF3B33;

    cTkDynamicArray<float> maMilestoneValues;
    cTkDynamicArray<short> maRewardCollected;
    int miPinnedStage;
    int miPinnedMilestone;
    cTkDynamicArray<unsigned long long> maRendezvousUAs;
    bool mbHasCollectedFinalReward;
    cTkDynamicArray<cGcUAProtectedLocations> maProtectedEvents;
    cGcSeasonSaveStateOnDeath StateOnDeath;
}
